#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <iomanip>
#include <ctime>
#include <map>
#include <math.h>

#include "TROOT.h"
#include "TFile.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TChain.h"
#include "TProfile.h"
#include "TMath.h"
#include "TString.h"
#include "TClass.h"
#include "TApplication.h"
#include "TLorentzVector.h"
#include "TF1.h"
#include "TH2.h"
#include <TClonesArray.h>

#include "DoubleHiggs/Selection/interface/NanoAOD_MC.hh"
#include "DoubleHiggs/Selection/interface/NanoAOD_Weights.hh"
#include "DoubleHiggs/Selection/interface/Utils.hh"

int main(int argc, char const *argv[])
{
    std::cout << "[INFO]: Program name is : " << argv[0] << std::endl;

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    int isMC = atoi(argv[3]);
    int era = atoi(argv[4]);
    bool DEBUG = atoi(argv[5]);

    /**
     * If the inputFile ends with ".root", then add it into the text file.
     */
    if (ends_with(inputFile,"root"))
    {
        std::string str = "echo ";
        str = str + inputFile + " > InputRootFileList.txt";
        const char *command = str.c_str();
        system(command);
        inputFile = "InputRootFileList.txt";
    }

    if(DEBUG) std::cout << "[INFO]: inputFile: " << inputFile << std::endl;
    if(DEBUG) std::cout << "[INFO]: outputFile: " << outputFile << std::endl;

    const float H_MASS = 125.10;
    const float W_MASS = 80.379;

    //lepton cuts
    const float EL_PT_CUT = 10;
    const float MU_PT_CUT = 10;

    const float PHO_ETA_CUT = 2.5;
    const float PHO_PT_VETO_CUT = 10.0;
    const float PHO_PT_CUT = 25.0;
    const float PHO_R9_CUT = 0.8;
    const float PHOTON_PFRELISO03_CHG_CUT = 20;
    const float HOVERE_CUT = 0.08;
    const float PHO1_PT_CUT = 35;
    const float PHO2_PT_CUT = 25;


/* --------------------------- all the efficiency --------------------------- */
    float passAllPhotonEff = 0;
    float passAllOneJetEff = 0;
    float passAllThreeJetEff = 0;
    float passAllFourJetEff = 0;




    const float OneJet_AK8_LEP_DR_CUT = 0.8;
    const float TlreeJet_AK8_LEP_DR_CUT = 1.2;
    const float AK4_LEP_DR_CUT = 0.4;

    //ak8 jet cuts
    const float ONEJET_AK8JET_PT_MIN_CUT = 400;
    const float THREEJET_AK8JET_PT_MIN_CUT = 200;
    const float THREEJET_AK8JET_PT_MAX_CUT = 400;

    const float AK8_MAX_ETA = 2.4;
    const float AK8_MIN_SDM = 40;
    const float AK8_MAX_SDM = 160;

    //ak4 jet cuts
    //const float AK4_PT_VETO_CUT = 20;
    const float AK4_ETA_CUT = 2.4;
    const float AK4_PT_CUT = 30;
    const float AK4_JJ_MIN_M = 40.0;
    const float AK4_JJ_MAX_M = 150.0;

    std::vector<TLorentzVector> TightPhoton;
    std::vector<TLorentzVector> Ak4Jets;
    std::vector<TLorentzVector> ThreeJetAk4Jets;
    std::vector<TLorentzVector> Ak4JetsTem;
    std::vector<TLorentzVector> Ak8Jets;
    std::vector<TLorentzVector> ThreeJet_FatJet;
    std::vector<TLorentzVector> OneJet_FatJet;
    std::vector<int> goodAK4JetIndex;
    std::vector<int> goodOneJetFatJetIndex;
    std::vector<int> goodThreeJetAK4JetIndex;
    std::vector<int> goodThreeJetFatJetIndex;
    std::vector<int> goodAK4JetTem;

    //
    //   INPUT/OUTPUT
    //

    TFile *of = new TFile(outputFile.c_str(),"RECREATE");
    TTree *ot = new TTree("Events","Events");
    TH1F *totalEvents = new TH1F("TotalEvents","TotalEvents",2,-1,1);

    TFile *f=0;
    TTree *t=0, *r=0;

    std::ifstream ifs;
    ifs.open(inputFile.data());
    assert(ifs.is_open());
    output* OutputTree = new output(ot); //!"ot" is a output tree
    std::string line;
    float PassEvents = 0.;
    uint allEntries;
    while (getline(ifs,line)) {
        std::stringstream ss(line);
        std::string filetoopen;
        ss >> filetoopen;
        std::cout << "File: " << TString(filetoopen) << std::endl;

        //f = TFile::Open(TString("root://cmseos.fnal.gov/")+TString(filetoopen),"read");
        //f = TFile::Open(TString("root://xrootd-cms.infn.it/")+TString(filetoopen),"read");
        f = TFile::Open(TString(filetoopen),"read");
        t = (TTree *)f->Get("Events");
        r = (TTree *)f->Get("Runs");
        if (t==NULL) continue;

        //std::cout << filetoopen << std::endl;
        //!NanoReader is the tree Events T
        NanoAOD_MC NanoReader = NanoAOD_MC(t);
        NanoAOD_Weights NanoWeightReader = NanoAOD_Weights(r);
        //! MC so getEntry(0) 
        if (isMC==1) {
            NanoWeightReader.GetEntry(0);
            totalEvents->SetBinContent(2,totalEvents->GetBinContent(2)+NanoWeightReader.genEventSumw);
        }
        allEntries += t->GetEntries(); 
        for (uint i=0; i < t->GetEntries(); i++) {
            //for (uint i=0; i < 1000000; i++) {
            OutputTree->clearVars();
            NanoReader.GetEntry(i);
            if (i > 10001) break;
            if (i%1000==0) std::cout <<"event " << i << std::endl;
            // if (i>50000) exit(0);

            if (isMC==1) {
                OutputTree->genWeight=NanoReader.Generator_weight;
            }

            if (era==2017) {
                if ( NanoReader.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 || NanoReader.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 || NanoReader.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 ) OutputTree->trigger_1Pho = true;
            }
            // else if (era==2017) {
            //     if ( NanoReader.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 || NanoReader.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 || NanoReader.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 ) OutputTree->trigger_1Pho = true;
            //     if ( NanoReader.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 || NanoReader.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 || NanoReader.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 ) OutputTree->trigger_2Pho = true;
            // }
            // else if (era==2018) {
            //     if ( NanoReader.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 || NanoReader.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 || NanoReader.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 ) OutputTree->trigger_1Pho = true;
            // }

            // if (!(OutputTree->trigger_1Pho)) continue;

            TightPhoton.clear();
            Ak4Jets.clear();
            Ak8Jets.clear();

            OutputTree->run = NanoReader.run;
            OutputTree->evt = NanoReader.event;
            OutputTree->ls = NanoReader.luminosityBlock;

            // OutputTree->nPV = NanoReader.PV_npvsGood;
            OutputTree->nPU_mean = NanoReader.Pileup_nPU;

            OutputTree->puWeight = 1.0;//scaleFactor.GetPUWeight(info->nPUmean, 0);
            /* -------------------------------------------------------------------------- */
            /*                      ele and muon Selection 
                    no electron and muon in fullyHadronic                         */
            /* -------------------------------------------------------------------------- */
            int nTightEle=0;
            int nTightMu=0;

            for (uint j=0; j < NanoReader.nMuon; j++) {
                if (!NanoReader.Muon_tightId[j]) continue;
                if ( NanoReader.Muon_pt[j] < MU_PT_CUT ) continue;
                nTightMu++;
            }
            for (uint j=0; j < NanoReader.nElectron; j++) {
                //cut-based ID Fall17 V2 (0:fail, 1:veto, 2:loose, 3:medium, 4:tight)
                if ( NanoReader.Electron_cutBased[j]<3 ) continue;
                if ( NanoReader.Electron_pt[j] < EL_PT_CUT ) continue;
                nTightEle++;
            }

            if (nTightEle+nTightMu>0) continue;

            /* -------------------------------------------------------------------------- */
            /*                              PHOTON SELECTION                              */
            /* -------------------------------------------------------------------------- */
            int nTightPhoton = 0;
            int nVetoPhoton = 0;

            for (UInt_t PhotonCount = 0; PhotonCount < NanoReader.nPhoton; ++PhotonCount)
            {
                if (!(NanoReader.Photon_r9[PhotonCount] > PHO_R9_CUT)) continue;
                if (!(NanoReader.Photon_pfRelIso03_chg[PhotonCount] < PHOTON_PFRELISO03_CHG_CUT)) continue;
                if (!(NanoReader.Photon_hoe[PhotonCount] < HOVERE_CUT)) continue;

                if ( !(abs(NanoReader.Photon_eta[PhotonCount]) < PHO_ETA_CUT )) continue;
                if (!(NanoReader.Photon_isScEtaEB[PhotonCount] || NanoReader.Photon_isScEtaEE[PhotonCount])) continue;
                //using conservative uncertainty value of 3%
                if ( 1.03*NanoReader.Photon_pt[PhotonCount] < PHO_PT_VETO_CUT ) continue;

                if (!NanoReader.Photon_cutBased[PhotonCount]) continue;
                if (NanoReader.Photon_pfRelIso03_all[PhotonCount]>0.25) continue;
                nVetoPhoton++;

                //using conservative uncertainty value of 3%
                if ( 1.03*NanoReader.Photon_pt[PhotonCount] < PHO_PT_CUT ) continue;
                if (!NanoReader.Photon_cutBased[PhotonCount]) continue;
                if (NanoReader.Photon_pfRelIso03_all[PhotonCount]>0.15) continue;

                nTightPhoton++;


                /* ----------- push pt,eta,phi,ecorr in the TightPhoton last index ---------- */
                TightPhoton.push_back(TLorentzVector(0,0,0,0));
                TightPhoton.back().SetPtEtaPhiE( NanoReader.Photon_pt[PhotonCount],
                                                NanoReader.Photon_eta[PhotonCount],
                                                NanoReader.Photon_phi[PhotonCount],
                                                NanoReader.Photon_eCorr[PhotonCount]
                                                );
                /* ------- sort and Leading_photon -> pho1  SubLeading_photon -> pho2  ------- */
                if ( NanoReader.Photon_pt[PhotonCount] > OutputTree->pho1_pt ) {
                    OutputTree->pho2_pt = OutputTree->pho1_pt;
                    OutputTree->pho2_eta = OutputTree->pho1_eta;
                    OutputTree->pho2_phi = OutputTree->pho1_phi;
                    OutputTree->pho2_m = OutputTree->pho1_m;
                    OutputTree->pho2_iso = OutputTree->pho1_iso;
                    OutputTree->pho2_q = OutputTree->pho1_q; 
                    OutputTree->pho2_mvaIDFall17V2 = OutputTree->pho1_mvaIDFall17V2;
                    OutputTree->pho2_mvaIDFall17V1 = OutputTree->pho1_mvaIDFall17V1;
                    OutputTree->pho2_mvaID_WP80 = OutputTree->pho1_mvaID_WP80;
                    OutputTree->pho2_mvaID_WP90 = OutputTree->pho1_mvaID_WP90;


                    OutputTree->pho1_pt = NanoReader.Photon_pt[PhotonCount];
                    OutputTree->pho1_eta = NanoReader.Photon_eta[PhotonCount];
                    OutputTree->pho1_phi = NanoReader.Photon_phi[PhotonCount];
                    OutputTree->pho1_m = NanoReader.Photon_mass[PhotonCount];
                    OutputTree->pho1_iso = NanoReader.Photon_pfRelIso03_all[PhotonCount];
                    OutputTree->pho1_q = NanoReader.Photon_charge[PhotonCount];
                    OutputTree->pho1_mvaIDFall17V2 = NanoReader.Photon_mvaID[PhotonCount];
                    OutputTree->pho1_mvaIDFall17V1 = NanoReader.Photon_mvaID_Fall17V1p1[PhotonCount];
                    OutputTree->pho1_mvaID_WP80 = NanoReader.Photon_mvaID_WP80[PhotonCount];
                    OutputTree->pho1_mvaID_WP90 = NanoReader.Photon_mvaID_WP90[PhotonCount];
                }
                else if ( NanoReader.Photon_pt[PhotonCount] > OutputTree->pho2_pt ) {
                    OutputTree->pho2_pt = NanoReader.Photon_pt[PhotonCount];
                    OutputTree->pho2_eta = NanoReader.Photon_eta[PhotonCount];
                    OutputTree->pho2_phi = NanoReader.Photon_phi[PhotonCount];
                    OutputTree->pho2_m = NanoReader.Photon_mass[PhotonCount];
                    OutputTree->pho2_iso = NanoReader.Photon_pfRelIso03_all[PhotonCount];
                    OutputTree->pho2_q = NanoReader.Photon_charge[PhotonCount];
                    OutputTree->pho2_mvaIDFall17V2 = NanoReader.Photon_mvaID[PhotonCount];
                    OutputTree->pho2_mvaIDFall17V1 = NanoReader.Photon_mvaID_Fall17V1p1[PhotonCount];
                    OutputTree->pho2_mvaID_WP80 = NanoReader.Photon_mvaID_WP80[PhotonCount];
                    OutputTree->pho2_mvaID_WP90 = NanoReader.Photon_mvaID_WP90[PhotonCount];
                }
            }
            /* ----------------- Leading and SubLeading photon selection ---------------- */
            if(!(OutputTree->pho1_pt > 35)) continue;
            if(!(OutputTree->pho2_pt > 25)) continue;

            if (!(nTightPhoton==2)) continue;
            
            /* -------------------------------------------------------------------------- */
            /*                             photon m,pt,eta,phi                            */
            /* -------------------------------------------------------------------------- */
            TLorentzVector LV_pho1(0,0,0,0);
            LV_pho1.SetPtEtaPhiM( OutputTree->pho1_pt, OutputTree->pho1_eta, OutputTree->pho1_phi, OutputTree->pho1_m );

            TLorentzVector LV_pho2(0,0,0,0);
            LV_pho2.SetPtEtaPhiM( OutputTree->pho2_pt, OutputTree->pho2_eta, OutputTree->pho2_phi, OutputTree->pho2_m );

            TLorentzVector diphoton = LV_pho1+LV_pho2;

            OutputTree->diphoton_m = diphoton.M();
            OutputTree->diphoton_pt = diphoton.Pt();
            OutputTree->diphoton_eta = diphoton.Eta();
            OutputTree->diphoton_phi = diphoton.Phi();
            OutputTree->diphoton_E = diphoton.E();
            OutputTree->pho1_E = LV_pho1.E();
            OutputTree->pho2_E = LV_pho2.E();
            OutputTree->pho1_pt_byMgg = LV_pho1.Pt()/diphoton.M();
            OutputTree->pho2_pt_byMgg = LV_pho1.Pt()/diphoton.M();
            OutputTree->pho1_E_byMgg = LV_pho2.E()/diphoton.M();
            OutputTree->pho2_E_byMgg = LV_pho2.E()/diphoton.M();
            if(!(OutputTree->pho1_pt_byMgg > 0.35)) continue;
            if(!(OutputTree->pho2_pt_byMgg > 0.25)) continue;


            float dmW = 3000.0;  
            float allOneJet_AK4JetsSum_pt = 0;
            float allOneJet_AK8JetsSum_pt = 0;
            int nGoodOneJet_FatJet = 0;
            goodOneJetFatJetIndex.clear();

            passAllPhotonEff++;
            /* -------------------------------------------------------------------------- */
            /*                              ONEJET SELECTION                              */
            /* -------------------------------------------------------------------------- */
            for (UInt_t OneJetAk8JetCount = 0; OneJetAk8JetCount < NanoReader.nFatJet; ++OneJetAk8JetCount)
            {
                if ( ! (NanoReader.FatJet_pt[OneJetAk8JetCount]>ONEJET_AK8JET_PT_MIN_CUT ||
                        NanoReader.FatJet_pt_jesTotalUp[OneJetAk8JetCount]>200 ||
                        NanoReader.FatJet_pt_jesTotalDown[OneJetAk8JetCount]>200)
                    ) continue;
                if ( ! (fabs(NanoReader.FatJet_eta[OneJetAk8JetCount]) < AK8_MAX_ETA)
                    ) continue;

                if ( ! (NanoReader.FatJet_msoftdrop[OneJetAk8JetCount]>AK8_MIN_SDM ||
                        NanoReader.FatJet_msoftdrop_jesTotalUp[OneJetAk8JetCount]>AK8_MIN_SDM ||
                        NanoReader.FatJet_msoftdrop_jesTotalDown[OneJetAk8JetCount]>AK8_MIN_SDM)
                    ) continue;

                if ( ! (NanoReader.FatJet_msoftdrop[OneJetAk8JetCount]<AK8_MAX_SDM ||
                        NanoReader.FatJet_msoftdrop_jesTotalUp[OneJetAk8JetCount]<AK8_MAX_SDM ||
                        NanoReader.FatJet_msoftdrop_jesTotalDown[OneJetAk8JetCount]<AK8_MAX_SDM)
                    ) continue;

                bool isClean=true;
                /* -------------------------------------------------------------------------- */
                /*                               lepton cleaning                              */
                /* -------------------------------------------------------------------------- */
                for ( std::size_t k=0; k<TightPhoton.size(); k++) {
                    if (deltaR( TightPhoton.at(k).Eta(), TightPhoton.at(k).Phi(),
                            NanoReader.FatJet_eta[OneJetAk8JetCount], NanoReader.FatJet_phi[OneJetAk8JetCount])
                            < OneJet_AK8_LEP_DR_CUT)
                    isClean = false;
                }
                if ( isClean == false ) continue;
                /* -------------------------------------------------------------------------- */
                // resonnance FatJet - H_mass > 3000
                if ( fabs(NanoReader.FatJet_msoftdrop[OneJetAk8JetCount] - H_MASS) > dmW ) continue;
                goodOneJetFatJetIndex.push_back(OneJetAk8JetCount);
            }
                OutputTree->OneJet_FatJet_area = NanoReader.FatJet_area[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_btagCMVA = NanoReader.FatJet_btagCMVA[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_btagCSVV2 = NanoReader.FatJet_btagCSVV2[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_btagDDBvL = NanoReader.FatJet_btagDDBvL[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_btagDDBvL_noMD = NanoReader.FatJet_btagDDBvL_noMD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_btagDDCvB = NanoReader.FatJet_btagDDCvB[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_btagDDCvB_noMD = NanoReader.FatJet_btagDDCvB_noMD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_btagDDCvL = NanoReader.FatJet_btagDDCvB_noMD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_btagDDCvL_noMD = NanoReader.FatJet_btagDDCvB_noMD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_btagDeepB = NanoReader.FatJet_btagDDCvB_noMD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_btagHbb = NanoReader.FatJet_btagHbb[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_deepTagMD_H4qvsQCD = NanoReader.FatJet_deepTagMD_H4qvsQCD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_deepTagMD_HbbvsQCD = NanoReader.FatJet_deepTagMD_HbbvsQCD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_deepTagMD_TvsQCD = NanoReader.FatJet_deepTagMD_TvsQCD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_deepTagMD_WvsQCD = NanoReader.FatJet_deepTagMD_WvsQCD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_deepTagMD_ZHbbvsQCD = NanoReader.FatJet_deepTagMD_ZHbbvsQCD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_deepTagMD_ZHccvsQCD = NanoReader.FatJet_deepTagMD_ZHccvsQCD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_deepTagMD_ZbbvsQCD = NanoReader.FatJet_deepTagMD_ZbbvsQCD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_deepTagMD_ZvsQCD = NanoReader.FatJet_deepTagMD_ZvsQCD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_deepTagMD_bbvsLight = NanoReader.FatJet_deepTagMD_bbvsLight[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_deepTagMD_ccvsLight = NanoReader.FatJet_deepTagMD_ccvsLight[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_deepTag_H = NanoReader.FatJet_deepTag_H[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_deepTag_QCD = NanoReader.FatJet_deepTag_QCD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_deepTag_QCDothers = NanoReader.FatJet_deepTag_QCDothers[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_deepTag_TvsQCD = NanoReader.FatJet_deepTag_TvsQCD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_deepTag_WvsQCD = NanoReader.FatJet_deepTag_WvsQCD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_deepTag_ZvsQCD = NanoReader.FatJet_deepTag_ZvsQCD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_electronIdx3SJ = NanoReader.FatJet_electronIdx3SJ[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_eta = NanoReader.FatJet_eta[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_genJetAK8Idx = NanoReader.FatJet_genJetAK8Idx[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_hadronFlavour = NanoReader.FatJet_hadronFlavour[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_jetId=NanoReader.FatJet_jetId[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_lsf3=NanoReader.FatJet_lsf3[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_mass=NanoReader.FatJet_mass[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_msoftdrop=NanoReader.FatJet_msoftdrop[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_muonIdx3SJ=NanoReader.FatJet_muonIdx3SJ[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_n2b1=NanoReader.FatJet_n2b1[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_n3b1=NanoReader.FatJet_n3b1[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_nBHadrons=NanoReader.FatJet_nBHadrons[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_nCHadrons=NanoReader.FatJet_nCHadrons[goodOneJetFatJetIndex[0]];
                //! todo: add this variable but not find in root file
                // OutputTree->FatJet_particleNetMD_QCD=NanoReader.FatJet_particleNetMD_QCD[goodOneJetFatJetIndex[0]];
                // OutputTree->FatJet_particleNetMD_Xbb=NanoReader.FatJet_particleNetMD_Xbb[goodOneJetFatJetIndex[0]];
                // OutputTree->FatJet_particleNetMD_Xcc=NanoReader.FatJet_particleNetMD_Xcc[goodOneJetFatJetIndex[0]];
                // OutputTree->FatJet_particleNetMD_Xqq=NanoReader.FatJet_particleNetMD_Xqq[goodOneJetFatJetIndex[0]];
                // OutputTree->FatJet_particleNet_H4qvsQCD=NanoReader.FatJet_particleNet_H4qvsQCD[goodOneJetFatJetIndex[0]];
                // OutputTree->FatJet_particleNet_HbbvsQCD=NanoReader.FatJet_particleNet_HbbvsQCD[goodOneJetFatJetIndex[0]];
                // OutputTree->FatJet_particleNet_HccvsQCD=NanoReader.FatJet_particleNet_HccvsQCD[goodOneJetFatJetIndex[0]];
                // OutputTree->FatJet_particleNet_QCD=NanoReader.FatJet_particleNet_QCD[goodOneJetFatJetIndex[0]];
                // OutputTree->FatJet_particleNet_TvsQCD=NanoReader.FatJet_particleNet_TvsQCD[goodOneJetFatJetIndex[0]];
                // OutputTree->FatJet_particleNet_WvsQCD=NanoReader.FatJet_particleNet_WvsQCD[goodOneJetFatJetIndex[0]];
                // OutputTree->FatJet_particleNet_ZvsQCD=NanoReader.FatJet_particleNet_ZvsQCD[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_phi=NanoReader.FatJet_phi[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_pt=NanoReader.FatJet_pt[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_rawFactor=NanoReader.FatJet_rawFactor[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_subJetIdx1=NanoReader.FatJet_subJetIdx1[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_subJetIdx2=NanoReader.FatJet_subJetIdx2[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_tau1=NanoReader.FatJet_tau1[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_tau2=NanoReader.FatJet_tau2[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_tau3=NanoReader.FatJet_tau3[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_FatJet_tau4=NanoReader.FatJet_tau4[goodOneJetFatJetIndex[0]];
                OutputTree->OneJet_nFatJet=NanoReader.nFatJet;

                dmW = fabs(NanoReader.FatJet_msoftdrop[goodOneJetFatJetIndex[0]] - H_MASS);
                allOneJet_AK8JetsSum_pt += NanoReader.FatJet_pt[goodOneJetFatJetIndex[0]];
                nGoodOneJet_FatJet = goodOneJetFatJetIndex.size();
                OutputTree->allOneJet_AK8JetsSum_pt = allOneJet_AK8JetsSum_pt;
                OutputTree->nGoodOneJet_FatJet = nGoodOneJet_FatJet;
                float passAllPhotonEff = 0;

            /* -------------------------------------------------------------------------- */
            /*                              ONEJET SELECTION                              */
            /* -------------------------------------------------------------------------- */

            /* -------------------------------------------------------------------------- */
            /*                            THREE JETS SELECTION                            */
            /* -------------------------------------------------------------------------- */
            float allThreeJet_AK4JetsSum_pt = 0;
            float allThreeJet_AK8JetsSum_pt = 0;
            int nGoodThreeJet_FatJet = 0;
            int nGoodThreeJet_Ak4Jet = 0;
            goodThreeJetAK4JetIndex.clear();
            goodThreeJetFatJetIndex.clear();
            ThreeJetAk4Jets.clear();
            for (UInt_t ThreeJetAk8JetCount = 0; ThreeJetAk8JetCount < NanoReader.nFatJet; ++ThreeJetAk8JetCount)
            {
                if ( ! (THREEJET_AK8JET_PT_MAX_CUT>NanoReader.FatJet_pt[ThreeJetAk8JetCount]>THREEJET_AK8JET_PT_MIN_CUT ||
                        NanoReader.FatJet_pt_jesTotalUp[ThreeJetAk8JetCount]>THREEJET_AK8JET_PT_MIN_CUT ||
                        NanoReader.FatJet_pt_jesTotalDown[ThreeJetAk8JetCount]>THREEJET_AK8JET_PT_MIN_CUT)
                    ) continue;
                if ( ! (fabs(NanoReader.FatJet_eta[ThreeJetAk8JetCount]) < AK8_MAX_ETA)
                    ) continue;

                if ( ! (NanoReader.FatJet_msoftdrop[ThreeJetAk8JetCount]>AK8_MIN_SDM ||
                        NanoReader.FatJet_msoftdrop_jesTotalUp[ThreeJetAk8JetCount]>AK8_MIN_SDM ||
                        NanoReader.FatJet_msoftdrop_jesTotalDown[ThreeJetAk8JetCount]>AK8_MIN_SDM)
                    ) continue;

                if ( ! (NanoReader.FatJet_msoftdrop[ThreeJetAk8JetCount]<AK8_MAX_SDM ||
                        NanoReader.FatJet_msoftdrop_jesTotalUp[ThreeJetAk8JetCount]<AK8_MAX_SDM ||
                        NanoReader.FatJet_msoftdrop_jesTotalDown[ThreeJetAk8JetCount]<AK8_MAX_SDM)
                    ) continue;

                bool isClean=true;
                /* -------------------------------------------------------------------------- */
                /*                               lepton cleaning                              */
                /* -------------------------------------------------------------------------- */
                for ( std::size_t k=0; k<TightPhoton.size(); k++) {
                    if (deltaR( TightPhoton.at(k).Eta(), TightPhoton.at(k).Phi(),
                            NanoReader.FatJet_eta[ThreeJetAk8JetCount], NanoReader.FatJet_phi[ThreeJetAk8JetCount])
                            < 0.8)
                    isClean = false;
                }
                if ( isClean == false ) continue;
                /* -------------------------------------------------------------------------- */
                // resonnance FatJet - H_mass > 3000
                if ( fabs(NanoReader.FatJet_msoftdrop[ThreeJetAk8JetCount] - H_MASS) > dmW ) continue;
                for (UInt_t ThreeJet_Ak4JetCount = 0; ThreeJet_Ak4JetCount < NanoReader.nJet; ++ThreeJet_Ak4JetCount)
                {
                    //jet energy scale variations
                    if ( NanoReader.Jet_pt[ThreeJet_Ak4JetCount] < AK4_PT_CUT) continue;
                    if (fabs(NanoReader.Jet_eta[ThreeJet_Ak4JetCount]) > AK8_MAX_ETA) continue;
                    if (!(NanoReader.Jet_jetId[ThreeJet_Ak4JetCount] >= 2)) continue;
                    if (!(NanoReader.Jet_puId[ThreeJet_Ak4JetCount] >= 3)) continue;
                    
                    bool isClean=true;

                    //lepton cleaning
                    for ( std::size_t k=0; k<TightPhoton.size(); k++) {
                        if (!(deltaR( TightPhoton.at(k).Eta(), TightPhoton.at(k).Phi(),
                                    NanoReader.Jet_eta[ThreeJet_Ak4JetCount], NanoReader.Jet_phi[ThreeJet_Ak4JetCount])
                            > 0.4))
                            isClean = false;
                    }
                    if ( isClean == false ) continue;
                    // Ak8 and Ak4 jet DR
                    if (!(deltaR( NanoReader.FatJet_eta[ThreeJetAk8JetCount], NanoReader.FatJet_phi[ThreeJetAk8JetCount],
                                NanoReader.Jet_eta[ThreeJet_Ak4JetCount], NanoReader.Jet_phi[ThreeJet_Ak4JetCount])
                        > 1.2)) continue;
                    //https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation102X
                    if (NanoReader.Jet_eta[ThreeJet_Ak4JetCount]<2.4) {
                    if (NanoReader.Jet_btagDeepB[ThreeJet_Ak4JetCount] > 0.1241) OutputTree->nBtag_loose++;
                    if (NanoReader.Jet_btagDeepB[ThreeJet_Ak4JetCount] > 0.4184) OutputTree->nBtag_medium++;
                    if (NanoReader.Jet_btagDeepB[ThreeJet_Ak4JetCount] > 0.7527) OutputTree->nBtag_tight++;
                    }
                    ThreeJetAk4Jets.push_back(TLorentzVector(0,0,0,0));
                    ThreeJetAk4Jets.back().SetPtEtaPhiM( NanoReader.Jet_pt[ThreeJet_Ak4JetCount],
                                            NanoReader.Jet_eta[ThreeJet_Ak4JetCount],
                                            NanoReader.Jet_phi[ThreeJet_Ak4JetCount],
                                            NanoReader.Jet_mass[ThreeJet_Ak4JetCount]
                                            );
                    goodThreeJetAK4JetIndex.push_back(ThreeJet_Ak4JetCount);
                }

                goodThreeJetFatJetIndex.push_back(ThreeJetAk8JetCount);
            }
            nGoodThreeJet_FatJet = goodThreeJetFatJetIndex.size();
            nGoodThreeJet_Ak4Jet = goodThreeJetAK4JetIndex.size();
            if (!(nGoodThreeJet_FatJet>=1 && nGoodThreeJet_Ak4Jet>=2)) continue;    

            OutputTree-> nGoodThreeJet_FatJet = nGoodThreeJet_FatJet;
            OutputTree -> nGoodThreeJet_Ak4Jet = nGoodThreeJet_Ak4Jet;
            OutputTree->ThreeJet_FatJet_area = NanoReader.FatJet_area[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_btagCMVA = NanoReader.FatJet_btagCMVA[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_btagCSVV2 = NanoReader.FatJet_btagCSVV2[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_btagDDBvL = NanoReader.FatJet_btagDDBvL[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_btagDDBvL_noMD = NanoReader.FatJet_btagDDBvL_noMD[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_btagDDCvB = NanoReader.FatJet_btagDDCvB[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_btagDDCvB_noMD = NanoReader.FatJet_btagDDCvB_noMD[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_btagDDCvL = NanoReader.FatJet_btagDDCvB_noMD[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_btagDDCvL_noMD = NanoReader.FatJet_btagDDCvB_noMD[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_btagDeepB = NanoReader.FatJet_btagDDCvB_noMD[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_btagHbb = NanoReader.FatJet_btagHbb[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_deepTagMD_H4qvsQCD = NanoReader.FatJet_deepTagMD_H4qvsQCD[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_deepTagMD_HbbvsQCD = NanoReader.FatJet_deepTagMD_HbbvsQCD[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_deepTagMD_TvsQCD = NanoReader.FatJet_deepTagMD_TvsQCD[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_deepTagMD_WvsQCD = NanoReader.FatJet_deepTagMD_WvsQCD[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_deepTagMD_ZHbbvsQCD = NanoReader.FatJet_deepTagMD_ZHbbvsQCD[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_deepTagMD_ZHccvsQCD = NanoReader.FatJet_deepTagMD_ZHccvsQCD[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_deepTagMD_ZbbvsQCD = NanoReader.FatJet_deepTagMD_ZbbvsQCD[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_deepTagMD_ZvsQCD = NanoReader.FatJet_deepTagMD_ZvsQCD[goodThreeJetFatJetIndex[0]]; 
            OutputTree->ThreeJet_FatJet_deepTagMD_bbvsLight = NanoReader.FatJet_deepTagMD_bbvsLight[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_deepTagMD_ccvsLight = NanoReader.FatJet_deepTagMD_ccvsLight[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_deepTag_H = NanoReader.FatJet_deepTag_H[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_deepTag_QCD = NanoReader.FatJet_deepTag_QCD[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_deepTag_QCDothers = NanoReader.FatJet_deepTag_QCDothers[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_deepTag_TvsQCD = NanoReader.FatJet_deepTag_TvsQCD[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_deepTag_WvsQCD = NanoReader.FatJet_deepTag_WvsQCD[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_deepTag_ZvsQCD = NanoReader.FatJet_deepTag_ZvsQCD[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_electronIdx3SJ = NanoReader.FatJet_electronIdx3SJ[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_eta = NanoReader.FatJet_eta[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_genJetAK8Idx = NanoReader.FatJet_genJetAK8Idx[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_hadronFlavour = NanoReader.FatJet_hadronFlavour[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_jetId=NanoReader.FatJet_jetId[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_lsf3=NanoReader.FatJet_lsf3[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_mass=NanoReader.FatJet_mass[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_msoftdrop=NanoReader.FatJet_msoftdrop[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_muonIdx3SJ=NanoReader.FatJet_muonIdx3SJ[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_n2b1=NanoReader.FatJet_n2b1[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_n3b1=NanoReader.FatJet_n3b1[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_nBHadrons=NanoReader.FatJet_nBHadrons[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_nCHadrons=NanoReader.FatJet_nCHadrons[goodThreeJetFatJetIndex[0]];
            //! todo: add this variable but not find in root file
            // OutputTree->FatJet_particleNetMD_QCD=NanoReader.FatJet_particleNetMD_QCD[goodThreeJetFatJetIndex[0]];
            // OutputTree->FatJet_particleNetMD_Xbb=NanoReader.FatJet_particleNetMD_Xbb[goodThreeJetFatJetIndex[0]];
            // OutputTree->FatJet_particleNetMD_Xcc=NanoReader.FatJet_particleNetMD_Xcc[goodThreeJetFatJetIndex[0]];
            // OutputTree->FatJet_particleNetMD_Xqq=NanoReader.FatJet_particleNetMD_Xqq[goodThreeJetFatJetIndex[0]];
            // OutputTree->FatJet_particleNet_H4qvsQCD=NanoReader.FatJet_particleNet_H4qvsQCD[goodThreeJetFatJetIndex[0]];
            // OutputTree->FatJet_particleNet_HbbvsQCD=NanoReader.FatJet_particleNet_HbbvsQCD[goodThreeJetFatJetIndex[0]];
            // OutputTree->FatJet_particleNet_HccvsQCD=NanoReader.FatJet_particleNet_HccvsQCD[goodThreeJetFatJetIndex[0]];
            // OutputTree->FatJet_particleNet_QCD=NanoReader.FatJet_particleNet_QCD[goodThreeJetFatJetIndex[0]];
            // OutputTree->FatJet_particleNet_TvsQCD=NanoReader.FatJet_particleNet_TvsQCD[goodThreeJetFatJetIndex[0]];
            // OutputTree->FatJet_particleNet_WvsQCD=NanoReader.FatJet_particleNet_WvsQCD[goodThreeJetFatJetIndex[0]];
            // OutputTree->FatJet_particleNet_ZvsQCD=NanoReader.FatJet_particleNet_ZvsQCD[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_phi=NanoReader.FatJet_phi[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_pt=NanoReader.FatJet_pt[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_rawFactor=NanoReader.FatJet_rawFactor[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_subJetIdx1=NanoReader.FatJet_subJetIdx1[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_subJetIdx2=NanoReader.FatJet_subJetIdx2[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_tau1=NanoReader.FatJet_tau1[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_tau2=NanoReader.FatJet_tau2[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_tau3=NanoReader.FatJet_tau3[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_FatJet_tau4=NanoReader.FatJet_tau4[goodThreeJetFatJetIndex[0]];
            OutputTree->ThreeJet_nFatJet=NanoReader.nFatJet;
            for (int i =0;i<2;i++)
            {allThreeJet_AK4JetsSum_pt += NanoReader.Jet_pt[goodThreeJetFatJetIndex[i]];
            }
            OutputTree->allThreeJet_AK4JetsSum_pt = allThreeJet_AK4JetsSum_pt;

            OutputTree->ThreeJetAk4_jet1_pt = ThreeJetAk4Jets.at(0).Pt();
            OutputTree->ThreeJetAk4_jet2_pt = ThreeJetAk4Jets.at(1).Pt();

            OutputTree->ThreeJetAk4_jet1_eta = ThreeJetAk4Jets.at(0).Eta();
            OutputTree->ThreeJetAk4_jet2_eta = ThreeJetAk4Jets.at(1).Eta();

            OutputTree->ThreeJetAk4_jet1_phi = ThreeJetAk4Jets.at(0).Phi();
            OutputTree->ThreeJetAk4_jet2_phi = ThreeJetAk4Jets.at(1).Phi();

            OutputTree->ThreeJetAk4_jet1_M = ThreeJetAk4Jets.at(0).M();
            OutputTree->ThreeJetAk4_jet2_M = ThreeJetAk4Jets.at(1).M();

            TLorentzVector ThreeJetTwoLeadingJets = ThreeJetAk4Jets.at(0) + ThreeJetAk4Jets.at(1);
            OutputTree -> ThreeJetTwoLeadingJets_pt = ThreeJetTwoLeadingJets.Pt();
            OutputTree -> ThreeJetTwoLeadingJets_eta = ThreeJetTwoLeadingJets.Eta();
            OutputTree -> ThreeJetTwoLeadingJets_phi = ThreeJetTwoLeadingJets.Phi();
            OutputTree -> ThreeJetTwoLeadingJets_m = ThreeJetTwoLeadingJets.M();
            OutputTree -> ThreeJetTwoLeadingJets_E = ThreeJetTwoLeadingJets.E();


                /* -------------------------------------------------------------------------- */
                /*                            THREE JETS SELECTION                            */
                /* -------------------------------------------------------------------------- */

                goodAK4JetIndex.clear();
                goodAK4JetTem.clear();
                Ak4JetsTem.clear();
                Ak4Jets.clear();
            /* -------------------------------------------------------------------------- */

            /* -------------------------------------------------------------------------- */
            /*                                   FOUR JETS SELECTION                                   */
            /* -------------------------------------------------------------------------- */
            float allFullyResolved_AK4JetsSum_pt = 0.0;
            for (UInt_t Ak4JetCount = 0; Ak4JetCount < NanoReader.nJet; ++Ak4JetCount)
            {
                //jet energy scale variations
                if ( NanoReader.Jet_pt[Ak4JetCount] < AK4_PT_CUT) continue;
                if (fabs(NanoReader.Jet_eta[Ak4JetCount]) > AK8_MAX_ETA) continue;
                if (!(NanoReader.Jet_jetId[Ak4JetCount] >= 2)) continue;
                if (!(NanoReader.Jet_puId[Ak4JetCount] >= 3)) continue;
                
                bool isClean=true;

                //lepton cleaning
                for ( std::size_t k=0; k<TightPhoton.size(); k++) {
                    if (!(deltaR( TightPhoton.at(k).Eta(), TightPhoton.at(k).Phi(),
                            NanoReader.Jet_eta[Ak4JetCount], NanoReader.Jet_phi[Ak4JetCount])
                        > AK4_LEP_DR_CUT))
                        isClean = false;
                }
                if ( isClean == false ) continue;

                //https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation102X
                if (NanoReader.Jet_eta[Ak4JetCount]<2.4) {
                if (NanoReader.Jet_btagDeepB[Ak4JetCount] > 0.1241) OutputTree->nBtag_loose++;
                if (NanoReader.Jet_btagDeepB[Ak4JetCount] > 0.4184) OutputTree->nBtag_medium++;
                if (NanoReader.Jet_btagDeepB[Ak4JetCount] > 0.7527) OutputTree->nBtag_tight++;
                }

                Ak4Jets.push_back(TLorentzVector(0,0,0,0));
                Ak4Jets.back().SetPtEtaPhiM( NanoReader.Jet_pt[Ak4JetCount],
                                            NanoReader.Jet_eta[Ak4JetCount],
                                            NanoReader.Jet_phi[Ak4JetCount],
                                            NanoReader.Jet_mass[Ak4JetCount]
                                            );

                goodAK4JetIndex.push_back(Ak4JetCount);
                allFullyResolved_AK4JetsSum_pt += NanoReader.Jet_pt[Ak4JetCount];
            


                // for (std::vector<int>::iterator It_JetIndex = goodAK4JetIndex.begin(); It_JetIndex != goodAK4JetIndex.end(); ++It_JetIndex)
                // {
                    // std::cout << "DEBUG: " << *It_JetIndex << std::endl;
                // }
                //
                //
                // get 4 jets for FH final state with minWH vals
            }
            int nTagJets = goodAK4JetIndex.size();
            if (nTagJets<4) continue;
            // We need to save pt, eta, phi, energy for first 4 AK4 jets
            // output->FullyResolved_jet1_pt = goodAK4JetIndex[0].pT
            
            /* ----------------------- output the AK4 and AK8 jet ----------------------- */
            
            /* ------------------- cout four pt to make sure in order ------------------- */
            if(!(NanoReader.Jet_pt[goodAK4JetIndex[0]]>NanoReader.Jet_pt[goodAK4JetIndex[1]]>NanoReader.Jet_pt[goodAK4JetIndex[2]])>NanoReader.Jet_pt[goodAK4JetIndex[3]])
            {
                std::cout << "4 jets is not in order please check" << std::endl;
            }

            OutputTree->nTagJets = nTagJets;
            OutputTree->allFullyResolved_AK4JetsSum_pt = allFullyResolved_AK4JetsSum_pt;

            OutputTree->FullyResolved_jet1_pt = NanoReader.Jet_pt[goodAK4JetIndex[0]];
            OutputTree->FullyResolved_jet2_pt = NanoReader.Jet_pt[goodAK4JetIndex[1]];
            OutputTree->FullyResolved_jet3_pt = NanoReader.Jet_pt[goodAK4JetIndex[2]];
            OutputTree->FullyResolved_jet4_pt = NanoReader.Jet_pt[goodAK4JetIndex[3]];


            OutputTree->FullyResolved_jet1_eta = NanoReader.Jet_eta[goodAK4JetIndex[0]];
            OutputTree->FullyResolved_jet2_eta = NanoReader.Jet_eta[goodAK4JetIndex[1]];
            OutputTree->FullyResolved_jet3_eta = NanoReader.Jet_eta[goodAK4JetIndex[2]];
            OutputTree->FullyResolved_jet4_eta = NanoReader.Jet_eta[goodAK4JetIndex[3]];

            OutputTree->FullyResolved_jet1_phi = NanoReader.Jet_phi[goodAK4JetIndex[0]];
            OutputTree->FullyResolved_jet2_phi = NanoReader.Jet_phi[goodAK4JetIndex[1]];
            OutputTree->FullyResolved_jet3_phi = NanoReader.Jet_phi[goodAK4JetIndex[2]];
            OutputTree->FullyResolved_jet4_phi = NanoReader.Jet_phi[goodAK4JetIndex[3]];

            OutputTree->FullyResolved_jet1_M = NanoReader.Jet_mass[goodAK4JetIndex[0]];
            OutputTree->FullyResolved_jet2_M = NanoReader.Jet_mass[goodAK4JetIndex[1]];
            OutputTree->FullyResolved_jet3_M = NanoReader.Jet_mass[goodAK4JetIndex[2]];
            OutputTree->FullyResolved_jet4_M = NanoReader.Jet_mass[goodAK4JetIndex[3]];


            OutputTree->FullyResolved_jet1_E = Ak4Jets.at(0).E();
            OutputTree->FullyResolved_jet2_E = Ak4Jets.at(1).E();
            OutputTree->FullyResolved_jet3_E = Ak4Jets.at(2).E();
            OutputTree->FullyResolved_jet4_E = Ak4Jets.at(3).E();

            /* -------------------------- Sum of 2 leading jets ------------------------- */
            TLorentzVector FullyResolvedTwoLeadingJets = Ak4Jets.at(0) + Ak4Jets.at(1);
            OutputTree -> FullyResolvedTwoLeadingJets_pt = FullyResolvedTwoLeadingJets.Pt();
            OutputTree -> FullyResolvedTwoLeadingJets_eta = FullyResolvedTwoLeadingJets.Eta();
            OutputTree -> FullyResolvedTwoLeadingJets_phi = FullyResolvedTwoLeadingJets.Phi();
            OutputTree -> FullyResolvedTwoLeadingJets_m = FullyResolvedTwoLeadingJets.M();
            OutputTree -> FullyResolvedTwoLeadingJets_E = FullyResolvedTwoLeadingJets.E();

            /* -------------------------- Sum of 3rd 4th  jets -------------------------- */
            TLorentzVector FullyResolvedThirdFourthJets = Ak4Jets.at(2) + Ak4Jets.at(3);
            OutputTree -> FullyResolvedThirdFourthJets_pt = FullyResolvedThirdFourthJets.Pt();
            OutputTree -> FullyResolvedThirdFourthJets_eta = FullyResolvedThirdFourthJets.Eta();
            OutputTree -> FullyResolvedThirdFourthJets_phi = FullyResolvedThirdFourthJets.Phi();
            OutputTree -> FullyResolvedThirdFourthJets_m = FullyResolvedThirdFourthJets.M();
            OutputTree -> FullyResolvedThirdFourthJets_E = FullyResolvedThirdFourthJets.E();

            /* ------------------------------ Sum of 4 jets ----------------------------- */
            TLorentzVector FullyResolvedFourJets = Ak4Jets.at(0) + Ak4Jets.at(1)+ Ak4Jets.at(2) + Ak4Jets.at(3);
            OutputTree -> FullyResolvedFourJets_pt = FullyResolvedFourJets.Pt();
            OutputTree -> FullyResolvedFourJets_eta = FullyResolvedFourJets.Eta();
            OutputTree -> FullyResolvedFourJets_phi = FullyResolvedFourJets.Phi();
            OutputTree -> FullyResolvedFourJets_m = FullyResolvedFourJets.M();
            OutputTree -> FullyResolvedFourJets_E = FullyResolvedFourJets.E();
            // OutputTree->AK8_Jet1_pt = NanoReader.Jet_pt[goodAK8JetIndex[0]];
            // OutputTree->AK8_Jet2_pt = NanoReader.Jet_pt[goodAK8JetIndex[1]];
            // OutputTree->AK8_Jet3_pt = NanoReader.Jet_pt[goodAK8JetIndex[2]];
            // OutputTree->AK8_Jet4_pt = NanoReader.Jet_pt[goodAK8JetIndex[3]];

            // OutputTree->AK8_Jet1_eta = NanoReader.Jet_eta[goodAK8JetIndex[0]];
            // OutputTree->AK8_Jet2_eta = NanoReader.Jet_eta[goodAK8JetIndex[1]];
            // OutputTree->AK8_Jet3_eta = NanoReader.Jet_eta[goodAK8JetIndex[2]];
            // OutputTree->AK8_Jet4_eta = NanoReader.Jet_eta[goodAK8JetIndex[3]];

            // OutputTree->AK8_Jet1_phi = NanoReader.Jet_phi[goodAK8JetIndex[0]];
            // OutputTree->AK8_Jet2_phi = NanoReader.Jet_phi[goodAK8JetIndex[1]];
            // OutputTree->AK8_Jet3_phi = NanoReader.Jet_phi[goodAK8JetIndex[2]];
            // OutputTree->AK8_Jet4_phi = NanoReader.Jet_phi[goodAK8JetIndex[3]];



            if (isMC==1) {

                OutputTree->nScaleWeight = NanoReader.nLHEScaleWeight;
                OutputTree->nPdfWeight = NanoReader.nLHEPdfWeight;

                for (uint j=0; j<OutputTree->nScaleWeight; j++) {
                    //LHE scale variation weights (w_var / w_nominal); [0] is MUR="0.5" MUF="0.5";
                    //[1] is MUR="0.5" MUF="1.0"; [2] is MUR="0.5" MUF="2.0"; [3] is MUR="1.0" MUF="0.5";
                    //[4] is MUR="1.0" MUF="2.0"; [5] is MUR="2.0" MUF="0.5"; [6] is MUR="2.0" MUF="1.0";
                    //[7] is MUR="2.0" MUF="2.0"
                    OutputTree->scaleWeight[j]=NanoReader.LHEScaleWeight[j];
                }
                for (uint j=0; j<OutputTree->nPdfWeight; j++) {
                    //LHE pdf variation weights (w_var / w_nominal) for LHA IDs 91400 - 91432
                    OutputTree->pdfWeight[j]=NanoReader.LHEPdfWeight[j];
                }

            }

            OutputTree->btagWeight = NanoReader.btagWeight_CSVV2;
            OutputTree->L1PFWeight = NanoReader.L1PreFiringWeight_Nom;
            ot->Fill();
        }
    }
    // float eff = PassEvents / (float)allEntries;
    // cout
    // std::cout << "efficiency is :" << eff << std::endl; 
    of->Write();
    of->Close();
    return 0;
}








