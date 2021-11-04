#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
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

#include "../interface/NanoReader.hh"
#include "../interface/ScaleFactors.hh"
#include "../interface/Utils.hh"
#include "../interface/METzCalculator.h"

int main (int argc, char** argv) {

    std::cout << "[INFO]: Program name is : " << argv[0] << std::endl;
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    int isMC = atoi(argv[3]);
    int era = atoi(argv[4]);
    int nanoVersion = atoi(argv[5]);
    bool DEBUG = atoi(argv[6]);
    bool DOWNLOAD_LOCAL_COPY = atoi(argv[7]);


    // const float W_MASS = 80.379;
    // const float Z_MASS = 91.1876;
    const float V_MASS = 85.7863;

    const float MUON_MASS = 0.1056583745;
    const float ELE_MASS  = 0.000511;

    //lepton cuts
    const float LEP_PT_VETO_CUT = 10;
    // const float EL_PT_CUT = 10;
    const float EL_ETA_CUT = 2.5;
    // const float MU_PT_CUT = 10;
    const float MU_ETA_CUT = 2.4;

    //photon cuts
    const float PHO_ETA_CUT = 2.5;
    const float PHO_PT_VETO_CUT = 10.0;
    // const float PHO_PT_CUT = 25.0;
    const float PHO_R9_CUT = 0.8;
    const float PHOTON_PFRELISO03_CHG_CUT = 20;
    const float HOVERE_CUT = 0.08;
    const float PHO1_PT_CUT = 35;
    const float PHO2_PT_CUT = 25;
    const float PHO_MVA_ID = -0.9;

    //ak8 jet cuts
    const float AK8_WJET_MIN_PT = 200;
    //checking eta with 2.4 to 4.7
    const float AK8_MAX_ETA = 4.7;

    // Mass window cuts
    const float AK8_WJet_MIN_SDM = 40;
    const float AK8_WJet_MAX_SDM = 130;

    //ak4 jet cuts
    //const float AK4_PT_VETO_CUT = 20;
    // const float AK4_ETA_CUT = 2.4;
    const float AK4_PT_CUT = 25;
    //checking eta with 2.4 to 4.7
    const float AK4_MAX_ETA = 4.7;
    // const float AK4_JJ_MIN_M = 40.0;
    // const float AK4_JJ_MAX_M = 250.0;

    // cleaning cuts
    // To-Do: Check the cut values of jet cleaning with other jets
    const float AK8_LEP_DR_CUT = 0.8;
    const float AK4_LEP_DR_CUT = 0.8;
    const float AK8_AK8_DR_CUT = 1.6;
    const float AK4_AK8_DR_CUT = 1.2;
    const float AK4_AK4_DR_CUT = 0.8;

    // Jet sub-structure cuts
    const float TAU21 = 0.55;

    // btag deepCSV a.k.a. DeepB working points
    //https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation102X
    //https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation94X
    //https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation2016Legacy
    // float btag_loose_wp = 0.0;
    // // float btag_tight_wp = 0.0;
    // // float btag_medium_wp = 0.0;
    // if (era==2018) {
    //   btag_loose_wp = 0.1241;
    //   // btag_medium_wp = 0.4184;
    //   // btag_tight_wp = 0.7527;
    // }
    // if (era==2017) {
    //   btag_loose_wp = 0.1522;
    //   // btag_medium_wp = 0.4941;
    //   // btag_tight_wp = 0.8001;
    // }
    // if (era==2016) {
    //   btag_loose_wp = 0.2217;
    //   // btag_medium_wp = 0.6321;
    //   // btag_tight_wp = 0.8953;
    // }

    ScaleFactors scaleFactor(era);

    std::vector<TLorentzVector> LV_LHE_Higgs;
    std::vector<TLorentzVector> LV_LHE_WBosons;
    std::vector<TLorentzVector> LV_LHE_photons;
    std::vector<TLorentzVector> LV_GEN_Higgs;
    std::vector<TLorentzVector> LV_GEN_WBosons;
    std::vector<TLorentzVector> LV_GEN_photons;
    std::vector<TLorentzVector> LV_GEN_quarks;
    std::vector<TLorentzVector> LV_GEN_leptons;
    std::vector<TLorentzVector> LV_GEN_neutrino;

    std::vector<TLorentzVector> LV_tightMuon;
    std::vector<TLorentzVector> LV_tightEle;
    std::vector<TLorentzVector> LV_tightPhoton;

    std::vector<TLorentzVector> LV_Ak4Jets;
    // std::vector<TLorentzVector> Ak4JetsTem;
    std::vector<TLorentzVector> LV_Ak8WZJets;
    std::vector<TLorentzVector> LV_Ak8HiggsJets;

    std::vector<int> goodAK4JetIndex;
    std::vector<int> goodWJetIndex;
    std::vector<int> goodWLepJetIndex;
    std::vector<int> goodHJetIndex;
    // std::vector<int> goodAK4JetTem;
    //
    //
    //   INPUT/OUTPUT
    //
    //

    TFile *of = new TFile(outputFile.c_str(),"RECREATE");
    TTree *ot = new TTree("Events","Events");
    WVJJData* WVJJTree = new WVJJData(ot);
    TH1F *totalEvents = new TH1F("TotalEvents","TotalEvents",2,-1,1);
    
    TH1F *totalCutFlow_SL = new TH1F("totalCutFlow_SL","totalCutFlow_SL",18,0,18);
    totalCutFlow_SL->GetXaxis()->SetBinLabel(1,"MC Gen");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(2,"nEvent");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(3,"Skim NanoAOD");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(4,"Trigger");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(5,"Photon Selection");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(6,"Lepton Selection");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(7,"nAK8_W >= 1");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(8,"nAK4 >= 2");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(9,"1Jet+2Jet");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(10,"pT/mgg cut");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(11,"pT(#gamma #gamma)>100");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(12,"GEN_Match photon before");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(13,"GEN_Match photon after");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(14,"Mu before cut");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(15,"Ele before cut");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(16,"Mu after cut");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(17,"Ele after cut");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(18,"All Leptons");
    
    TH1F *totalCutFlow_SL_GENMatch = new TH1F("totalCutFlow_SL_GENMatch","totalCutFlow_SL_GENMatch",13,0,13);
    totalCutFlow_SL_GENMatch->GetXaxis()->SetBinLabel(1,"MC Gen");
    totalCutFlow_SL_GENMatch->GetXaxis()->SetBinLabel(2,"nEvent");
    totalCutFlow_SL_GENMatch->GetXaxis()->SetBinLabel(3,"Skim NanoAOD");
    totalCutFlow_SL_GENMatch->GetXaxis()->SetBinLabel(4,"Trigger");
    totalCutFlow_SL_GENMatch->GetXaxis()->SetBinLabel(5,"Photon Selection");
    totalCutFlow_SL_GENMatch->GetXaxis()->SetBinLabel(6,"Lepton Selection");
    totalCutFlow_SL_GENMatch->GetXaxis()->SetBinLabel(7,"nAK8_W >= 1");
    totalCutFlow_SL_GENMatch->GetXaxis()->SetBinLabel(8,"nAK4 >= 2");
    totalCutFlow_SL_GENMatch->GetXaxis()->SetBinLabel(9,"1Jet+2Jet");
    totalCutFlow_SL_GENMatch->GetXaxis()->SetBinLabel(10,"pT/mgg cut");
    totalCutFlow_SL_GENMatch->GetXaxis()->SetBinLabel(11,"pT(#gamma #gamma)>100");
    totalCutFlow_SL_GENMatch->GetXaxis()->SetBinLabel(12,"GEN_Match photon before");
    totalCutFlow_SL_GENMatch->GetXaxis()->SetBinLabel(13,"GEN_Match photon after");

    TH1F *eventNumber = new TH1F("eventNumber","eventNumber",1,0,1);
    eventNumber->GetXaxis()->SetBinLabel(1,"LHE_Radion_HH_eta");
    

    TFile *f=0;
    TTree *t=0, *r=0;

    // Bool_t has_HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 = false;
    // Bool_t has_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 = false;
    // Bool_t has_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 = false;

    Bool_t has_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 = false;
    Bool_t has_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95 = false;
    Bool_t has_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 = false;
    Bool_t has_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 = false;
    Bool_t has_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 = false;
    Bool_t has_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 = false;
    Bool_t has_HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 = false;
    Bool_t has_HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 = false;

    // has_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ=false, has_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL=false,
    // has_HLT_DiEle27_WPTightCaloOnly_L1DoubleEG=false,
    // has_HLT_DoubleEle33_CaloIdL_MW=false, has_HLT_DoubleEle25_CaloIdL_MW=false, has_HLT_DoubleEle27_CaloIdL_MW=false;

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

    if(DEBUG) std::cout << "[INFO]: inputTextFile: " << inputFile << std::endl;
    if(DEBUG) std::cout << "[INFO]: outputFile: " << outputFile << std::endl;

    std::ifstream ifs;
    ifs.open(inputFile.data());
    assert(ifs.is_open());
    std::string line;
    int lineCount=0;

    // Create a temporary directory to download the file from EOS
    // if (DOWNLOAD_LOCAL_COPY) {
    char test[] = "/tmp/zhenxuan/tmpdir_XXXXXX";
    char *dir_name = mkdtemp(test);
    int CountEvents = 0;
    // }
    while (getline(ifs,line)) {
        std::stringstream ss(line);
        std::string filetoopen;
        ss >> filetoopen;

        lineCount+=1;

        std::cout << "[INFO]: current file: " << filetoopen << std::endl;
        // f = TFile::Open(TString("root://cmseos.fnal.gov/") + TString(filetoopen), "read");
        // f = TFile::Open(TString("root://xrootd-cms.infn.it/")+TString(filetoopen),"read");
        if (DOWNLOAD_LOCAL_COPY) {
            TString EOSFileDownloadCommand = TString("xrdcp ") + TString(filetoopen) + TString("  ") + TString(dir_name);
            if(DEBUG) std::cout << "EOS file download command: \n\t" << EOSFileDownloadCommand << std::endl;
            system((std::string(EOSFileDownloadCommand)).c_str());
            std::vector<std::string> fields;
            const std::string delimiter = "\\";
            Tokenize(filetoopen,fields); // TO-DO: Add the delimiter here.
            // f = TFile::Open(TString(fields[9]),"read"); // TO-DO: instead of 9th element it should take last element
            std::cout << "File to run: " << TString(dir_name)+"/"+TString(fields.back()) << std::endl;
            f = TFile::Open(TString(dir_name)+"/"+TString(fields.back()),"read"); // TO-DO: instead of 9th element it should take last element
        }
        else {
            f = TFile::Open(TString(filetoopen),"read");
        }

        if (f->IsZombie())
        {
            std::cout << "SKIPPING: This root file is IsZombie." << std::endl;
            continue;
        }

        if(DEBUG) std::cout << "[INFO]: current file: " << filetoopen << std::endl;

        t = (TTree *)f->Get("Events");
        r = (TTree *)f->Get("Runs");
        if (t==NULL)
        {
            std::cout << "SKIPPING: No tree named \"Events\" exits." << std::endl;
            continue;
        }

        NanoReader NanoReader_ = NanoReader(t);
        NanoReader NanoWeightReader = NanoReader(r);

        NanoWeightReader.GetEntry(0);

        float genEventSumw=0.0;
        float genEventCount=0.0;
        if (isMC && nanoVersion == 6) {
            genEventSumw = *NanoWeightReader.genEventSumw_;
            genEventCount = *NanoWeightReader.genEventCount_;
        }
        else if (isMC && nanoVersion >= 7) {
            genEventSumw = *NanoWeightReader.genEventSumw;
            genEventCount = *NanoWeightReader.genEventCount;
        }
        totalEvents->SetBinContent(2,totalEvents->GetBinContent(2)+genEventSumw);
        totalCutFlow_SL->Fill("MC Gen",genEventCount);
        totalCutFlow_SL_GENMatch->Fill("MC Gen",genEventCount);
        totalCutFlow_SL->Fill("nEvent",genEventSumw);
        totalCutFlow_SL_GENMatch->Fill("nEvent",genEventSumw);
        //check if tree has these hlt branches
        if (lineCount == 1){
            has_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 = t->GetBranchStatus("HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90");
            has_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95 = t->GetBranchStatus("HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95");
            has_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 = t->GetBranchStatus("HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55");
            has_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 = t->GetBranchStatus("HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55");
            has_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 = t->GetBranchStatus("HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55");
            has_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 = t->GetBranchStatus("HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55");
            has_HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 = t->GetBranchStatus("HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55");
            has_HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 = t->GetBranchStatus("HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55");
        }

        if(DEBUG) std::cout << "\t[INFO]: Start of event loop. " << std::endl;
        for (uint i=0; i < t->GetEntries(); i++)
        // for (uint i=0; i < 200; i++)
        {
            
            WVJJTree->clearVars();
            NanoReader_.GetEntry(i);
            totalCutFlow_SL->Fill("Skim NanoAOD",1);
            totalCutFlow_SL_GENMatch->Fill("Skim NanoAOD",1);

            if (i%10000==0) std::cout <<"\t[INFO]: file " << lineCount << ": event " << i << std::endl;
            if (DEBUG)       std::cout <<"\t[INFO]: file " << lineCount << ": event " << i << std::endl;

            if (isMC==1) {
                WVJJTree->genWeight=*NanoReader_.Generator_weight;
            }

            WVJJTree->run = *NanoReader_.run;
            WVJJTree->evt = *NanoReader_.event;
            WVJJTree->ls = *NanoReader_.luminosityBlock;

            // WVJJTree->nPV = *NanoReader_.PV_npvsGood;
            if (isMC) WVJJTree->nPU_mean = *NanoReader_.Pileup_nPU;

            WVJJTree->puWeight = scaleFactor.GetPUWeight(WVJJTree->nPU_mean, 0);
            WVJJTree->puWeight_Up = scaleFactor.GetPUWeight(WVJJTree->nPU_mean, 1);
            WVJJTree->puWeight_Down = scaleFactor.GetPUWeight(WVJJTree->nPU_mean, -1);

            // LHE information: Before partion shower
            // It contains information for pp -> Radion -> HH, only.
            if (isMC==1)
            {
                LV_LHE_Higgs.clear();
               
                for (UInt_t LHEPartCount = 0; LHEPartCount < *NanoReader_.nLHEPart; ++LHEPartCount)
                {
                    // if (NanoReader_.LHEPart_status[LHEPartCount] == 1)
                    // std::cout <<  "Event No. " << i << "/" << lineCount
                    //             << "\tLHE: pdgID = " << NanoReader_.LHEPart_pdgId[LHEPartCount]
                    //             << "\t Status = " << NanoReader_.LHEPart_status[LHEPartCount]
                    //             << "\t mass = " << NanoReader_.LHEPart_mass[LHEPartCount]
                    //             << "\t pT = " << NanoReader_.LHEPart_pt[LHEPartCount]
                    //             << std::endl;
                    if (NanoReader_.LHEPart_pdgId[LHEPartCount] == 25 && NanoReader_.LHEPart_status[LHEPartCount] == 1)
                    {
                        LV_LHE_Higgs.push_back(TLorentzVector(0,0,0,0));
                        LV_LHE_Higgs.back().SetPtEtaPhiM(NanoReader_.LHEPart_pt[LHEPartCount],
                                                         NanoReader_.LHEPart_eta[LHEPartCount],
                                                         NanoReader_.LHEPart_phi[LHEPartCount],
                                                         NanoReader_.LHEPart_mass[LHEPartCount]);
                    }
                }
            }
            WVJJTree->LHE_deltaR_HH = deltaR(LV_LHE_Higgs[0].Eta(),LV_LHE_Higgs[0].Phi(),LV_LHE_Higgs[1].Eta(),LV_LHE_Higgs[1].Phi());
            WVJJTree->LHE_deltaEta_HH = LV_LHE_Higgs[0].Eta() - LV_LHE_Higgs[1].Eta();
            WVJJTree->LHE_deltaPhi_HH = deltaPhi(LV_LHE_Higgs[0].Phi(),LV_LHE_Higgs[1].Phi());
            if(LV_LHE_Higgs[0].Pt()>=LV_LHE_Higgs[1].Pt())
            {
            // radion dynamic check LHE level                
            WVJJTree->LHE_H1_p = LV_LHE_Higgs[0].P();
            WVJJTree->LHE_H1_pt = LV_LHE_Higgs[0].Pt();
            WVJJTree->LHE_H1_pz = LV_LHE_Higgs[0].Pz();
            WVJJTree->LHE_H1_eta = LV_LHE_Higgs[0].Eta();
            WVJJTree->LHE_H1_phi = LV_LHE_Higgs[0].Phi();
            WVJJTree->LHE_H2_p = LV_LHE_Higgs[1].P();
            WVJJTree->LHE_H2_pt = LV_LHE_Higgs[1].Pt();
            WVJJTree->LHE_H2_pz = LV_LHE_Higgs[1].Pz();
            WVJJTree->LHE_H2_eta = LV_LHE_Higgs[1].Eta();
            WVJJTree->LHE_H2_phi = LV_LHE_Higgs[1].Phi();
            }
            else{
            WVJJTree->LHE_H1_p = LV_LHE_Higgs[1].P();
            WVJJTree->LHE_H1_pt = LV_LHE_Higgs[1].Pt();
            WVJJTree->LHE_H1_pz = LV_LHE_Higgs[1].Pz();
            WVJJTree->LHE_H1_eta = LV_LHE_Higgs[1].Eta();
            WVJJTree->LHE_H1_phi = LV_LHE_Higgs[1].Phi();
            WVJJTree->LHE_H2_p = LV_LHE_Higgs[0].P();
            WVJJTree->LHE_H2_pt = LV_LHE_Higgs[0].Pt();
            WVJJTree->LHE_H2_pz = LV_LHE_Higgs[0].Pz();
            WVJJTree->LHE_H2_eta = LV_LHE_Higgs[0].Eta();
            WVJJTree->LHE_H2_phi = LV_LHE_Higgs[0].Phi();

            }
            // x->HH
            TLorentzVector LV_LHE_Radion_HH(0,0,0,0);
            LV_LHE_Radion_HH = LV_LHE_Higgs[0] + LV_LHE_Higgs[1] ;
            WVJJTree->LHE_Radion_HH_p = LV_LHE_Radion_HH.P();
            WVJJTree->LHE_Radion_HH_pt = LV_LHE_Radion_HH.Pt();
            WVJJTree->LHE_Radion_HH_pz = LV_LHE_Radion_HH.Pz();
            WVJJTree->LHE_Radion_HH_eta = LV_LHE_Radion_HH.Eta();
            eventNumber->Fill("LHE_Radion_HH_eta",1);
            WVJJTree->LHE_Radion_HH_phi = LV_LHE_Radion_HH.Phi();
            WVJJTree->LHE_Radion_HH_m = LV_LHE_Radion_HH.M();
            WVJJTree->LHE_Radion_HH_E = LV_LHE_Radion_HH.E();
           
                // std::cout << "H1 eta = " << LV_LHE_Higgs[0].Eta() << std::endl;
                // std::cout << "H2 eta = " << LV_LHE_Higgs[1].Eta() << std::endl;

            

            // Below part : GEN information
            //              This contains information of the Higgs decays and after shower effects.
            //
            if (isMC==1)
            {
                LV_GEN_Higgs.clear();
                LV_GEN_WBosons.clear();
                LV_GEN_photons.clear();
                LV_GEN_quarks.clear();
                LV_GEN_leptons.clear();
                LV_GEN_neutrino.clear();
                // checking print the GENevents tree
                // for (UInt_t GENPartCount = 0; GENPartCount < *NanoReader_.nGenPart; ++GENPartCount)
                // {   
                //     std::cout
                //     << "Event:" << i <<"/idx:" << GENPartCount << "\t ID:" << NanoReader_.GenPart_pdgId[GENPartCount] 
                //     << "\t Name:";
                //     printpdgID(NanoReader_.GenPart_pdgId[GENPartCount]);
                //     std::cout <<"\t MotherID:" << NanoReader_.GenPart_genPartIdxMother[GENPartCount]
                //     << "\t Pt:" << NanoReader_.GenPart_pt[GENPartCount]
                //     << "\t Eta:" << NanoReader_.GenPart_eta[GENPartCount]
                //     << "\t Phi:" << NanoReader_.GenPart_phi[GENPartCount]
                //     << std::endl; 
                // }
                for (UInt_t GENPartCount = 0; GENPartCount < *NanoReader_.nGenPart; ++GENPartCount)
                {
                    int pdgid = NanoReader_.GenPart_pdgId[GENPartCount];
                    int status = NanoReader_.GenPart_status[GENPartCount];
                    int motherPDGid = NanoReader_.GenPart_pdgId[NanoReader_.GenPart_genPartIdxMother[GENPartCount]];

                    bool isPrompt = (NanoReader_.GenPart_statusFlags[i] >> 0  & 1 );
                    bool isHardProcess = (NanoReader_.GenPart_statusFlags[i] >> 7  & 1 );    
                    bool isFromHardProcess = (NanoReader_.GenPart_statusFlags[i] >> 8  & 1 );
                    bool isFromHardProcessBeforeFSR = (NanoReader_.GenPart_statusFlags[i] >> 11  & 1 );
                    
                    // Get Higgs bosons
                    if (pdgid == 25)
                    {
                        // std::cout << "\tEvent No. " << i << "/" << lineCount << ":\tHiggs: pdgID: " << pdgid
                                  // << "\tstatus: " << status << "\tMother pdgID: " <<  motherPDGid
                                  // << "\tpT: " << NanoReader_.GenPart_pt[GENPartCount] << std::endl;
                        LV_GEN_Higgs.push_back(TLorentzVector(0,0,0,0));
                        LV_GEN_Higgs.back().SetPtEtaPhiM(NanoReader_.GenPart_pt[GENPartCount],
                                                           NanoReader_.GenPart_eta[GENPartCount],
                                                           NanoReader_.GenPart_phi[GENPartCount],
                                                           NanoReader_.GenPart_mass[GENPartCount]);
                    }

                    // Get GEN photons
                    // status 1 and 23 => final state particles
                    // check status code here: http://th-www.if.uj.edu.pl/~erichter/TauAnalFrame/external/pythia8185/htmldoc/ParticleProperties.html
                    if (abs(pdgid) == 22 && (status==1 || status == 23) && motherPDGid==25)
                    {
                        // std::cout << "Event No. " << i << "/" << lineCount << ":\tpdgID: " << pdgid
                                  // << "\tstatus: " << status << "\tMother pdgID: " <<  motherPDGid
                                  // <<  std::endl;

                        LV_GEN_photons.push_back(TLorentzVector(0,0,0,0));
                        LV_GEN_photons.back().SetPtEtaPhiM(NanoReader_.GenPart_pt[GENPartCount],
                                                           NanoReader_.GenPart_eta[GENPartCount],
                                                           NanoReader_.GenPart_phi[GENPartCount],
                                                           NanoReader_.GenPart_mass[GENPartCount]);
                    }

                    // Get W-bosons from Higgs
                    if (abs(pdgid) == 24 && motherPDGid == 25)
                    {
                        // std::cout << "\tEvent No. " << i << "/" << lineCount << ":\tWBoson: pdgID: " << pdgid
                                  // << "\tstatus: " << status << "\tMother pdgID: " <<  motherPDGid
                                  // << "\tpT: " << NanoReader_.GenPart_pt[GENPartCount] << std::endl;
                        LV_GEN_WBosons.push_back(TLorentzVector(0,0,0,0));
                        LV_GEN_WBosons.back().SetPtEtaPhiM(NanoReader_.GenPart_pt[GENPartCount],
                                                           NanoReader_.GenPart_eta[GENPartCount],
                                                           NanoReader_.GenPart_phi[GENPartCount],
                                                           NanoReader_.GenPart_mass[GENPartCount]);
                    }

                    // Get quarks coming from W-bosons and should be final state particles
                    // status = 23 => final state particles
                    if (abs(pdgid) <= 6 && abs(motherPDGid) == 24 && status == 23 )
                    {
                        // std::cout << "\tEvent No. " << i << "/" << lineCount << ":\tQuarks: pdgID: " << pdgid
                                  // << "\tstatus: " << status << "\tMother pdgID: " <<  motherPDGid
                                  // << "\tpT: " << NanoReader_.GenPart_pt[GENPartCount] << std::endl;
                        CountEvents++;
                        LV_GEN_quarks.push_back(TLorentzVector(0,0,0,0));
                        LV_GEN_quarks.back().SetPtEtaPhiM(NanoReader_.GenPart_pt[GENPartCount],
                                                           NanoReader_.GenPart_eta[GENPartCount],
                                                           NanoReader_.GenPart_phi[GENPartCount],
                                                           NanoReader_.GenPart_mass[GENPartCount]);
                    }
                    // Important: add lepton and neutrino
                    // Add ele,mu,tao separatly then add together as leptons
                    // if (  (abs(pdgid)==11 ||abs(pdgid)==13||abs(pdgid)==15) && abs(motherPDGid) == 24 && (status == 1||status ==23) )
                    if (  ((abs(pdgid)==11&&(status==1||status==23)) || (abs(pdgid)==13&&(status==1||status==23)) || (abs(pdgid)==15&&(status==2||status==23))) && abs(motherPDGid) == 24 )
                    {
                        LV_GEN_leptons.push_back(TLorentzVector(0,0,0,0));
                        LV_GEN_leptons.back().SetPtEtaPhiM(NanoReader_.GenPart_pt[GENPartCount],
                                                           NanoReader_.GenPart_eta[GENPartCount],
                                                           NanoReader_.GenPart_phi[GENPartCount],
                                                           NanoReader_.GenPart_mass[GENPartCount]);
                        // std::cout << "\tEvent No. " << i << "/" << lineCount << ":\tQuarks: pdgID: " << pdgid
                        //           << "\tstatus: " << status << "\tMother pdgID: " <<  motherPDGid
                        //           << "\tpT: " << NanoReader_.GenPart_pt[GENPartCount]
                        //           << "\tEta: " << NanoReader_.GenPart_eta[GENPartCount] 
                        //           << "\tPhi: " << NanoReader_.GenPart_phi[GENPartCount]
                        //           << "\t isPrompt:" << isPrompt 
                        //           <<"\t isHardProcess:" << isHardProcess <<"\t isFromHardProcess:" << isFromHardProcess<< 
                        //           "\t isFromHardProcessBeforeFSR:" << isFromHardProcessBeforeFSR
                        //           << std::endl;                        
                    }
                    if (  (abs(pdgid)==12 ||abs(pdgid)==14||abs(pdgid)==16) && abs(motherPDGid) == 24 && (status == 1||status ==23))
                    {
                        
                        LV_GEN_neutrino.push_back(TLorentzVector(0,0,0,0));
                        LV_GEN_neutrino.back().SetPtEtaPhiM(NanoReader_.GenPart_pt[GENPartCount],
                                                           NanoReader_.GenPart_eta[GENPartCount],
                                                           NanoReader_.GenPart_phi[GENPartCount],
                                                           NanoReader_.GenPart_mass[GENPartCount]);
                    }
                    
                   
                }
                
                if (LV_GEN_leptons.size() != 1)
                {
                    // std::cout << "Lepton size = " << LV_GEN_leptons.size()<<std::endl;
                //     std::cout << "GEN Leptons are more than 1. Please check..." << std::endl;
                //     exit(0);
                }
                if (LV_GEN_photons.size() != 2)
                {
                    std::cout << "photons size = " << LV_GEN_photons.size() << std::endl;
                    std::cout << "GEN photons are more than 2. Please check..." << std::endl;
                    exit(0);
                }
                if (LV_GEN_Higgs.size()!=2)
                {
                    std::cout << "Higgs size = " << LV_GEN_Higgs.size() << std::endl;
                    std::cout << "GEN Higgs are more than 2. Please check..." << std::endl;
                    exit(0);
                }
                if (LV_GEN_WBosons.size()!= 2 )
                {
                    std::cout << "W-Bosons size = " << LV_GEN_WBosons.size() << std::endl;
                    std::cout << "GEN W-Bosons are more than 2. Please check..." << std::endl;
                    exit(0);
                }
                if (LV_GEN_quarks.size()!=2)
                {
                    std::cout << "Quarks size = " << LV_GEN_quarks.size() << std::endl;
                    std::cout << "GEN Quarks are more than 2. Please check..." << std::endl;
                    exit(0);
                }
            }
            TLorentzVector LV_GEN_HiggsGG(0,0,0,0);
            TLorentzVector LV_GEN_HiggsWW(0,0,0,0);
            LV_GEN_HiggsGG = LV_GEN_photons[0] + LV_GEN_photons[1];
            LV_GEN_HiggsWW = LV_GEN_WBosons[0] + LV_GEN_WBosons[1];

            WVJJTree->LHEGEN_deltaR_HToGGH = TMath::Min(deltaR(LV_LHE_Higgs[0].Eta(),LV_LHE_Higgs[0].Phi(),LV_GEN_HiggsGG.Eta(),LV_GEN_HiggsGG.Phi()),
                                                    deltaR(LV_LHE_Higgs[1].Eta(),LV_LHE_Higgs[1].Phi(),LV_GEN_HiggsGG.Eta(),LV_GEN_HiggsGG.Phi()));
            
            WVJJTree->LHEGEN_deltaR_HToWWH = TMath::Min(deltaR(LV_LHE_Higgs[0].Eta(),LV_LHE_Higgs[0].Phi(),LV_GEN_HiggsWW.Eta(),LV_GEN_HiggsWW.Phi()),
                                                    deltaR(LV_LHE_Higgs[1].Eta(),LV_LHE_Higgs[1].Phi(),LV_GEN_HiggsWW.Eta(),LV_GEN_HiggsWW.Phi()));

            // Save pT, eta, phi and mass of LV_GEN_leptons[0] in output Tree
            WVJJTree->GEN_Lepton1_p = LV_GEN_leptons[0].P();            
            WVJJTree->GEN_Lepton1_pt = LV_GEN_leptons[0].Pt();            
            WVJJTree->GEN_Lepton1_pz = LV_GEN_leptons[0].Pz();            
            WVJJTree->GEN_Lepton1_eta = LV_GEN_leptons[0].Eta();            
            WVJJTree->GEN_Lepton1_phi = LV_GEN_leptons[0].Phi();            
            WVJJTree->GEN_Lepton1_m = LV_GEN_leptons[0].M();            
            WVJJTree->GEN_Lepton1_E = LV_GEN_leptons[0].E();
            if(LV_GEN_leptons.size() == 3)
            {
                WVJJTree->GEN_Lepton1_p = LV_GEN_leptons[0].P();            
                WVJJTree->GEN_Lepton1_pt = LV_GEN_leptons[0].Pt();            
                WVJJTree->GEN_Lepton1_pz = LV_GEN_leptons[0].Pz();            
                WVJJTree->GEN_Lepton1_eta = LV_GEN_leptons[0].Eta();            
                WVJJTree->GEN_Lepton1_phi = LV_GEN_leptons[0].Phi();            
                WVJJTree->GEN_Lepton1_m = LV_GEN_leptons[0].M();            
                WVJJTree->GEN_Lepton1_E = LV_GEN_leptons[0].E();
                WVJJTree->GEN_Lepton2_p = LV_GEN_leptons[0].P();            
                WVJJTree->GEN_Lepton2_pt = LV_GEN_leptons[0].Pt();            
                WVJJTree->GEN_Lepton2_pz = LV_GEN_leptons[0].Pz();            
                WVJJTree->GEN_Lepton2_eta = LV_GEN_leptons[0].Eta();            
                WVJJTree->GEN_Lepton2_phi = LV_GEN_leptons[0].Phi();            
                WVJJTree->GEN_Lepton2_m = LV_GEN_leptons[0].M();            
                WVJJTree->GEN_Lepton2_E = LV_GEN_leptons[0].E();
                WVJJTree->GEN_Lepton3_p = LV_GEN_leptons[0].P();            
                WVJJTree->GEN_Lepton3_pt = LV_GEN_leptons[0].Pt();            
                WVJJTree->GEN_Lepton3_pz = LV_GEN_leptons[0].Pz();            
                WVJJTree->GEN_Lepton3_eta = LV_GEN_leptons[0].Eta();            
                WVJJTree->GEN_Lepton3_phi = LV_GEN_leptons[0].Phi();            
                WVJJTree->GEN_Lepton3_m = LV_GEN_leptons[0].M();            
                WVJJTree->GEN_Lepton3_E = LV_GEN_leptons[0].E();
            }

            // Save pT, eta, phi and mass of LV_GEN_photons[0] in output Tree
            // Save pT, eta, phi and mass of LV_GEN_photons[1] in output Tree
            WVJJTree->GEN_LeadingPhoton_pT = LV_GEN_photons[0].Pt();
            WVJJTree->GEN_LeadingPhoton_eta = LV_GEN_photons[0].Eta();
            WVJJTree->GEN_LeadingPhoton_phi = LV_GEN_photons[0].Phi();
            WVJJTree->GEN_LeadingPhoton_energy = LV_GEN_photons[0].E();
            WVJJTree->GEN_LeadingPhoton_mass = LV_GEN_photons[0].M();

            WVJJTree->GEN_SubLeadingPhoton_pT = LV_GEN_photons[1].Pt();
            WVJJTree->GEN_SubLeadingPhoton_eta = LV_GEN_photons[1].Eta();
            WVJJTree->GEN_SubLeadingPhoton_phi = LV_GEN_photons[1].Phi();
            WVJJTree->GEN_SubLeadingPhoton_energy = LV_GEN_photons[1].E();
            WVJJTree->GEN_SubLeadingPhoton_mass = LV_GEN_photons[1].M();

            // Save pT, eta, phi and mass of LV_GEN_quarks[0] in output Tree
            // Save pT, eta, phi and mass of LV_GEN_quarks[1] in output Tree
            // Save pT, eta, phi and mass of LV_GEN_quarks[2] in output Tree
            // Save pT, eta, phi and mass of LV_GEN_quarks[3] in output Tree

            WVJJTree->GEN_Q1_pT = LV_GEN_quarks[0].Pt();
            WVJJTree->GEN_Q1_eta = LV_GEN_quarks[0].Eta();
            WVJJTree->GEN_Q1_phi = LV_GEN_quarks[0].Phi();
            WVJJTree->GEN_Q1_energy = LV_GEN_quarks[0].E();
            WVJJTree->GEN_Q1_mass = LV_GEN_quarks[0].M();

            WVJJTree->GEN_Q2_pT = LV_GEN_quarks[1].Pt();
            WVJJTree->GEN_Q2_eta = LV_GEN_quarks[1].Eta();
            WVJJTree->GEN_Q2_phi = LV_GEN_quarks[1].Phi();
            WVJJTree->GEN_Q2_energy = LV_GEN_quarks[1].E();
            WVJJTree->GEN_Q2_mass = LV_GEN_quarks[1].M();


            // Save pT, eta, phi and mass of LV_GEN_WBosons[0] in output Tree
            // Save pT, eta, phi and mass of LV_GEN_WBosons[1] in output Tree

            WVJJTree->GEN_W1_pT = LV_GEN_WBosons[0].Pt();
            WVJJTree->GEN_W1_eta = LV_GEN_WBosons[0].Eta();
            WVJJTree->GEN_W1_phi = LV_GEN_WBosons[0].Phi();
            WVJJTree->GEN_W1_energy = LV_GEN_WBosons[0].E();
            WVJJTree->GEN_W1_mass = LV_GEN_WBosons[0].M();

            WVJJTree->GEN_W2_pT = LV_GEN_WBosons[1].Pt();
            WVJJTree->GEN_W2_eta = LV_GEN_WBosons[1].Eta();
            WVJJTree->GEN_W2_phi = LV_GEN_WBosons[1].Phi();
            WVJJTree->GEN_W2_energy = LV_GEN_WBosons[1].E();
            WVJJTree->GEN_W2_mass = LV_GEN_WBosons[1].M();

            // Save pT, eta, phi and mass of LV_GEN_Higgs[0] in output Tree
            // Save pT, eta, phi and mass of LV_GEN_Higgs[1] in output Tree
            if(LV_GEN_Higgs[0].Pt()>=LV_GEN_Higgs[1].Pt())
            {
            WVJJTree->GEN_H1_pT = LV_GEN_Higgs[0].Pt();
            WVJJTree->GEN_H1_eta = LV_GEN_Higgs[0].Eta();
            WVJJTree->GEN_H1_phi = LV_GEN_Higgs[0].Phi();
            WVJJTree->GEN_H1_energy = LV_GEN_Higgs[0].E();
            WVJJTree->GEN_H1_mass = LV_GEN_Higgs[0].M();

            WVJJTree->GEN_H2_pT = LV_GEN_Higgs[1].Pt();
            WVJJTree->GEN_H2_eta = LV_GEN_Higgs[1].Eta();
            WVJJTree->GEN_H2_phi = LV_GEN_Higgs[1].Phi();
            WVJJTree->GEN_H2_energy = LV_GEN_Higgs[1].E();
            WVJJTree->GEN_H2_mass = LV_GEN_Higgs[1].M();
            }
            else
            {
            WVJJTree->GEN_H1_pT = LV_GEN_Higgs[1].Pt();
            WVJJTree->GEN_H1_eta = LV_GEN_Higgs[1].Eta();
            WVJJTree->GEN_H1_phi = LV_GEN_Higgs[1].Phi();
            WVJJTree->GEN_H1_energy = LV_GEN_Higgs[1].E();
            WVJJTree->GEN_H1_mass = LV_GEN_Higgs[1].M();

            WVJJTree->GEN_H2_pT = LV_GEN_Higgs[0].Pt();
            WVJJTree->GEN_H2_eta = LV_GEN_Higgs[0].Eta();
            WVJJTree->GEN_H2_phi = LV_GEN_Higgs[0].Phi();
            WVJJTree->GEN_H2_energy = LV_GEN_Higgs[0].E();
            WVJJTree->GEN_H2_mass = LV_GEN_Higgs[0].M();

            }
            WVJJTree->GEN_deltaR_HH = deltaR(LV_GEN_Higgs[0],LV_GEN_Higgs[1]);
            WVJJTree->GEN_deltaEta_HH = LV_GEN_Higgs[0].Eta() - LV_GEN_Higgs[1].Eta();
            WVJJTree->GEN_deltaPhi_HH = deltaPhi(LV_GEN_Higgs[0],LV_GEN_Higgs[1]);
            WVJJTree->GEN_deltaR_GG = deltaR(LV_GEN_photons[0],LV_GEN_photons[1]);
            WVJJTree->GEN_deltaR_WW = deltaR(LV_GEN_WBosons[0],LV_GEN_WBosons[1]);
            WVJJTree->GEN_deltaR_MIN4Q = MinDeltaR(LV_GEN_quarks[0],LV_GEN_quarks[1],LV_GEN_quarks[2],LV_GEN_quarks[3]);

            WVJJTree->GEN_HWW_pT = (LV_GEN_WBosons[0]+LV_GEN_WBosons[1]).Pt();
            WVJJTree->GEN_HWW_eta = (LV_GEN_WBosons[0]+LV_GEN_WBosons[1]).Eta();
            WVJJTree->GEN_HWW_phi = (LV_GEN_WBosons[0]+LV_GEN_WBosons[1]).Phi();
            WVJJTree->GEN_HWW_energy = (LV_GEN_WBosons[0]+LV_GEN_WBosons[1]).E();
            WVJJTree->GEN_HWW_mass = (LV_GEN_WBosons[0]+LV_GEN_WBosons[1]).M();

            WVJJTree->GEN_HGG_pT = (LV_GEN_photons[1]+LV_GEN_photons[0]).Pt();
            WVJJTree->GEN_HGG_eta = (LV_GEN_photons[1]+LV_GEN_photons[0]).Eta();
            WVJJTree->GEN_HGG_phi = (LV_GEN_photons[1]+LV_GEN_photons[0]).Phi();
            WVJJTree->GEN_HGG_energy = (LV_GEN_photons[1]+LV_GEN_photons[0]).E();
            WVJJTree->GEN_HGG_mass = (LV_GEN_photons[1]+LV_GEN_photons[0]).M();
            // GEN level Radion kinematic check
            // x->HH
            TLorentzVector LV_GEN_Radion_HH(0,0,0,0);
            LV_GEN_Radion_HH = LV_GEN_Higgs[0] + LV_GEN_Higgs[1] ;
            WVJJTree->GEN_Radion_HH_p = LV_GEN_Radion_HH.P();
            WVJJTree->GEN_Radion_HH_pt = LV_GEN_Radion_HH.Pt();
            WVJJTree->GEN_Radion_HH_pz = LV_GEN_Radion_HH.Pz();
            WVJJTree->GEN_Radion_HH_eta = LV_GEN_Radion_HH.Eta();
            WVJJTree->GEN_Radion_HH_phi = LV_GEN_Radion_HH.Phi();
            WVJJTree->GEN_Radion_HH_m = LV_GEN_Radion_HH.M();
            WVJJTree->GEN_Radion_HH_E = LV_GEN_Radion_HH.E();
            // x->WWgg
            TLorentzVector LV_GEN_Radion_WWgg(0,0,0,0);
            LV_GEN_Radion_WWgg = LV_GEN_photons[0] + LV_GEN_photons[1]+ LV_GEN_WBosons[0] + LV_GEN_WBosons[1];
            WVJJTree->GEN_Radion_WWgg_p = LV_GEN_Radion_WWgg.P();
            WVJJTree->GEN_Radion_WWgg_pt = LV_GEN_Radion_WWgg.Pt();
            WVJJTree->GEN_Radion_WWgg_pz = LV_GEN_Radion_WWgg.Pz();
            WVJJTree->GEN_Radion_WWgg_eta = LV_GEN_Radion_WWgg.Eta();
            WVJJTree->GEN_Radion_WWgg_phi = LV_GEN_Radion_WWgg.Phi();
            WVJJTree->GEN_Radion_WWgg_m = LV_GEN_Radion_WWgg.M();
            WVJJTree->GEN_Radion_WWgg_E = LV_GEN_Radion_WWgg.E();
            WVJJTree->trigger_2Pho = (
                                      (has_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 ? *NanoReader_.HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 : 0) ||
                                      (has_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95 ? *NanoReader_.HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95 : 0) ||
                                      (has_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 ? *NanoReader_.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 : 0) ||
                                      (has_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 ? *NanoReader_.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 : 0) ||
                                      (has_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 ? *NanoReader_.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 : 0) ||
                                      (has_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 ? *NanoReader_.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 : 0) ||
                                      (has_HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 ? *NanoReader_.HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 : 0) ||
                                      (has_HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 ? *NanoReader_.HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 : 0)
                                      );

            //std::cout << "passed trigger: ";
            //if (WVJJTree->trigger_1Mu) std::cout << "1 muon ";
            //if (WVJJTree->trigger_2Mu) std::cout << "2 muon ";
            //if (WVJJTree->trigger_1El) std::cout << "1 ele ";
            //if (WVJJTree->trigger_2El) std::cout << "2 ele ";
            // if (DEBUG)
            // {
            //   if (WVJJTree->trigger_2Pho) std::cout << "\t[INFO] 2 photon trigger passed." << std::endl;
            //   else std::cout << "\t[INFO] 2 photon trigger not passed." << std::endl;
            // }
            //std::cout << std::endl;

            if (WVJJTree->trigger_2Pho) totalCutFlow_SL->Fill("Trigger",1);
            if (WVJJTree->trigger_2Pho) totalCutFlow_SL_GENMatch->Fill("Trigger",1);

            /* -------------------------------------------------------------------------- */
            /*                              PHOTON SELECTION                              */
            /* -------------------------------------------------------------------------- */
            LV_tightPhoton.clear();
            int nTightPhoton = 0;
            if (*NanoReader_.nPhoton < 2) continue;
            for (UInt_t PhotonCount = 0; PhotonCount < *NanoReader_.nPhoton; ++PhotonCount)
            {
                if (!(NanoReader_.Photon_r9[PhotonCount] > PHO_R9_CUT || (NanoReader_.Photon_pfRelIso03_chg[PhotonCount]*NanoReader_.Photon_pt[PhotonCount]) < PHOTON_PFRELISO03_CHG_CUT || NanoReader_.Photon_pfRelIso03_chg[PhotonCount] < 0.3)) continue;
                if (!(NanoReader_.Photon_hoe[PhotonCount] < HOVERE_CUT)) continue;
                if (!(NanoReader_.Photon_pt[PhotonCount] > PHO_PT_VETO_CUT)) continue;
                if (!(abs(NanoReader_.Photon_eta[PhotonCount]) < PHO_ETA_CUT )) continue;
                if (!(NanoReader_.Photon_isScEtaEB[PhotonCount] || NanoReader_.Photon_isScEtaEE[PhotonCount])) continue;
                if (!(NanoReader_.Photon_mvaID[PhotonCount] > PHO_MVA_ID)) continue;
                if(!(NanoReader_.Photon_pixelSeed[PhotonCount]) == 0 ) continue;
                if (!(NanoReader_.Photon_electronVeto[PhotonCount]) == 1) continue;
                nTightPhoton++;

                /* ----------- push pt,eta,phi,ecorr in the TightPhoton last index ---------- */
                LV_tightPhoton.push_back(TLorentzVector(0,0,0,0));
                LV_tightPhoton.back().SetPtEtaPhiE( NanoReader_.Photon_pt[PhotonCount],
                                                NanoReader_.Photon_eta[PhotonCount],
                                                NanoReader_.Photon_phi[PhotonCount],
                                                NanoReader_.Photon_eCorr[PhotonCount]
                                                );
                /* ------- sort and Leading_photon -> pho1  SubLeading_photon -> pho2  ------- */
                if ( NanoReader_.Photon_pt[PhotonCount] > WVJJTree->pho1_pt ) {
                    WVJJTree->pho2_pt = WVJJTree->pho1_pt;
                    WVJJTree->pho2_eta = WVJJTree->pho1_eta;
                    WVJJTree->pho2_phi = WVJJTree->pho1_phi;
                    WVJJTree->pho2_m = WVJJTree->pho1_m;
                    WVJJTree->pho2_E = WVJJTree->pho1_E;
                    WVJJTree->pho2_iso = WVJJTree->pho1_iso;
                    WVJJTree->pho2_q = WVJJTree->pho1_q;
                    WVJJTree->pho2_mvaIDFall17V2 = WVJJTree->pho1_mvaIDFall17V2;
                    WVJJTree->pho2_mvaIDFall17V1 = WVJJTree->pho1_mvaIDFall17V1;
                    WVJJTree->pho2_mvaID_WP80 = WVJJTree->pho1_mvaID_WP80;
                    WVJJTree->pho2_mvaID_WP90 = WVJJTree->pho1_mvaID_WP90;

                    WVJJTree->pho1_pt = NanoReader_.Photon_pt[PhotonCount];
                    WVJJTree->pho1_eta = NanoReader_.Photon_eta[PhotonCount];
                    WVJJTree->pho1_phi = NanoReader_.Photon_phi[PhotonCount];
                    WVJJTree->pho1_m = NanoReader_.Photon_mass[PhotonCount];
                    WVJJTree->pho1_E = NanoReader_.Photon_eCorr[PhotonCount];
                    WVJJTree->pho1_iso = NanoReader_.Photon_pfRelIso03_all[PhotonCount];
                    WVJJTree->pho1_q = NanoReader_.Photon_charge[PhotonCount];
                    WVJJTree->pho1_mvaIDFall17V2 = NanoReader_.Photon_mvaID[PhotonCount];
                    WVJJTree->pho1_mvaIDFall17V1 = NanoReader_.Photon_mvaID_Fall17V1p1[PhotonCount];
                    WVJJTree->pho1_mvaID_WP80 = NanoReader_.Photon_mvaID_WP80[PhotonCount];
                    WVJJTree->pho1_mvaID_WP90 = NanoReader_.Photon_mvaID_WP90[PhotonCount];
                }
                else if ( (NanoReader_.Photon_pt[PhotonCount] > WVJJTree->pho2_pt) && ( WVJJTree->pho1_pt >NanoReader_.Photon_pt[PhotonCount]) ) {
                    WVJJTree->pho2_pt = NanoReader_.Photon_pt[PhotonCount];
                    WVJJTree->pho2_eta = NanoReader_.Photon_eta[PhotonCount];
                    WVJJTree->pho2_phi = NanoReader_.Photon_phi[PhotonCount];
                    WVJJTree->pho2_m = NanoReader_.Photon_mass[PhotonCount];
                    WVJJTree->pho2_E = NanoReader_.Photon_eCorr[PhotonCount];
                    WVJJTree->pho2_iso = NanoReader_.Photon_pfRelIso03_all[PhotonCount];
                    WVJJTree->pho2_q = NanoReader_.Photon_charge[PhotonCount];
                    WVJJTree->pho2_mvaIDFall17V2 = NanoReader_.Photon_mvaID[PhotonCount];
                    WVJJTree->pho2_mvaIDFall17V1 = NanoReader_.Photon_mvaID_Fall17V1p1[PhotonCount];
                    WVJJTree->pho2_mvaID_WP80 = NanoReader_.Photon_mvaID_WP80[PhotonCount];
                    WVJJTree->pho2_mvaID_WP90 = NanoReader_.Photon_mvaID_WP90[PhotonCount];
                }
                // if(nTightPhoton==3)
                // {
                //     WVJJTree->pho3_pt = NanoReader_.Photon_pt[PhotonCount];
                //     WVJJTree->pho3_eta = NanoReader_.Photon_eta[PhotonCount];
                //     WVJJTree->pho3_phi = NanoReader_.Photon_phi[PhotonCount];
                //     WVJJTree->pho3_m = NanoReader_.Photon_mass[PhotonCount];
                //     WVJJTree->pho3_iso = NanoReader_.Photon_pfRelIso03_all[PhotonCount];
                //     WVJJTree->pho3_q = NanoReader_.Photon_charge[PhotonCount];                    
                // }
                // checked ntightphoton problems
                // std::cout << "ntight_photons= " << nTightPhoton << std::endl;
                // std::cout << "photon_pt= " << NanoReader_.Photon_pt[PhotonCount] << std::endl;
                // std::cout << "pho1_pt= " << WVJJTree->pho1_pt << std::endl;
                // std::cout << "pho2_pt= " << WVJJTree->pho2_pt << std::endl;
                
            }
            // LV_tightPhoton.push_back(TLorentzVector(0,0,0,0));
            // LV_tightPhoton.back().SetPtEtaPhiE(
            //                                 WVJJTree->pho1_pt,
            //                                 WVJJTree->pho1_eta,
            //                                 WVJJTree->pho1_phi,
            //                                 WVJJTree->pho1_E
            //                                 );
            // LV_tightPhoton.push_back(TLorentzVector(0,0,0,0));
            // LV_tightPhoton.back().SetPtEtaPhiE(
            //                                 WVJJTree->pho2_pt,
            //                                 WVJJTree->pho2_eta,
            //                                 WVJJTree->pho2_phi,
            //                                 WVJJTree->pho2_E
            //                                 );
            TLorentzVector LV_pho1(0,0,0,0);
            LV_pho1.SetPtEtaPhiM( WVJJTree->pho1_pt, WVJJTree->pho1_eta, WVJJTree->pho1_phi, WVJJTree->pho1_m );

            TLorentzVector LV_pho2(0,0,0,0);
            LV_pho2.SetPtEtaPhiM( WVJJTree->pho2_pt, WVJJTree->pho2_eta, WVJJTree->pho2_phi, WVJJTree->pho2_m );

            
            /* ----------------- Leading and SubLeading photon selection ---------------- */

            if(!(WVJJTree->pho1_pt > PHO1_PT_CUT)) continue;
            if(!(WVJJTree->pho2_pt > PHO2_PT_CUT)) continue;
            if (!(nTightPhoton >= 2)) continue;
            //checking lepton misidentify
            // if(nTightEle!=1) continue;
            totalCutFlow_SL->Fill("Photon Selection",1);
            totalCutFlow_SL_GENMatch->Fill("Photon Selection",1);

            // std::cout << "Exactly 2 photons found..." << std::endl;

            /* -------------------------------------------------------------------------- */
            /*                             photon m,pt,eta,phi                            */
            /* -------------------------------------------------------------------------- */
            // TLorentzVector LV_pho1(0,0,0,0);
            // LV_pho1.SetPtEtaPhiM( WVJJTree->pho1_pt, WVJJTree->pho1_eta, WVJJTree->pho1_phi, WVJJTree->pho1_m );

            // TLorentzVector LV_pho2(0,0,0,0);
            // LV_pho2.SetPtEtaPhiM( WVJJTree->pho2_pt, WVJJTree->pho2_eta, WVJJTree->pho2_phi, WVJJTree->pho2_m );

            TLorentzVector diphoton = LV_pho1+LV_pho2;

            WVJJTree->diphoton_m = diphoton.M();
            WVJJTree->diphoton_pt = diphoton.Pt();
            WVJJTree->diphoton_eta = diphoton.Eta();
            WVJJTree->diphoton_phi = diphoton.Phi();
            WVJJTree->diphoton_E = diphoton.E();
            WVJJTree->pho1_pt_byMgg = LV_pho1.Pt()/diphoton.M();
            WVJJTree->pho2_pt_byMgg = LV_pho1.Pt()/diphoton.M();
            WVJJTree->pho1_E_byMgg = LV_pho2.E()/diphoton.M();
            WVJJTree->pho2_E_byMgg = LV_pho2.E()/diphoton.M();
            //RECO level photon deltaR
            WVJJTree->diphoton_dRgg = deltaR(LV_pho1,LV_pho2);
            WVJJTree->diphoton_dPhigg = deltaPhi(LV_pho1,LV_pho2);
            WVJJTree->diphoton_dEtagg = LV_pho1.Eta() - LV_pho2.Eta();

            WVJJTree->DiPhoton_deltaR_LHERECO_HH = MinDeltaRFromReferenceLV(diphoton,LV_LHE_Higgs[0],LV_LHE_Higgs[1]);
            // WVJJTree->DiPhoton_deltaR_GENRECO_HH = MinDeltaRFromReferenceLV(diphoton,LV_GEN_Higgs[0],LV_GEN_Higgs[1]);
            WVJJTree->DiPhoton_deltaR_GENRECO_HH = deltaR(diphoton,LV_GEN_photons[1]+LV_GEN_photons[0]);
            WVJJTree->Leading_photon_deltaR_GENRECO_G = deltaR(LV_pho1,LV_GEN_photons[0]);
            WVJJTree->SubLeading_photon_deltaR_GENRECO_G = deltaR(LV_pho2,LV_GEN_photons[1]);
            WVJJTree->DiPhoton_deltaR_pho1_GENPhoton = MinDeltaRFromReferenceLV(LV_pho1,LV_GEN_photons[0],LV_GEN_photons[1]);
            WVJJTree->DiPhoton_deltaR_pho2_GENPhoton = MinDeltaRFromReferenceLV(LV_pho2,LV_GEN_photons[0],LV_GEN_photons[1]);
            if(!(WVJJTree->pho1_pt_byMgg > 0.35)) continue;
            if(!(WVJJTree->pho2_pt_byMgg > 0.25)) continue;
            totalCutFlow_SL->Fill("GEN_Match photon before",1);
            if(WVJJTree->DiPhoton_deltaR_GENRECO_HH < 0.4 ){
                totalCutFlow_SL->Fill("GEN_Match photon after",1);
            }
            // LEPTON SELECTION
            /* -------------------------------------------------------------------------- */
            /*                      ele and muon Selection                                */
            /*             no electron and muon in fullyHadronic                          */
            /* -------------------------------------------------------------------------- */
            LV_tightMuon.clear();
            LV_tightEle.clear();
            int nTightEle = 0;
            int nTightMu = 0;
            int nMu = 0;
            int nEle = 0;
            // if(DEBUG) std::cout << "[INFO]: nMuon: " << *NanoReader_.nMuon << std::endl;
            // if(DEBUG) std::cout << "[INFO]: nElectron: " << *NanoReader_.nElectron << std::endl;

            for (uint j=0; j < *NanoReader_.nMuon; j++) 
            {
                nMu++;
                if ( NanoReader_.Muon_pt[j] < LEP_PT_VETO_CUT ) continue;
                if ( abs(NanoReader_.Muon_eta[j]) > MU_ETA_CUT ) continue;

                // cut-based ID, tight WP
                // checking without selection
                // if ( ! NanoReader_.Muon_tightId[j] ) continue;

                // MiniIso ID from miniAOD selector (1=MiniIsoLoose, 2=MiniIsoMedium, 3=MiniIsoTight, 4=MiniIsoVeryTight)
                // if ( ! (NanoReader_.Muon_miniIsoId[j] > 2) ) continue;

                if (DEBUG) std::cout << "\t[INFO::Muons] [" << i <<"/" << lineCount << "] Clean Muons with photons" << std::endl;

                // bool isClean=true;
                // for ( std::size_t k=0; k<2; k++) {
                //     if (deltaR(LV_tightPhoton.at(k).Eta(), LV_tightPhoton.at(k).Phi(),
                //                NanoReader_.Muon_eta[j], NanoReader_.Muon_phi[j]) < 0.4) {
                //         isClean = false;
                //     }
                // }
                // if ( isClean == false ) continue;

                TLorentzVector Mu(0,0,0,0);
                // Mu.SetPtEtaPhiM( NanoReader_.Muon_pt[j], NanoReader_.Muon_eta[j], NanoReader_.Muon_phi[j], NanoReader_.Muon_mass[j] );
                Mu.SetPtEtaPhiM( NanoReader_.Muon_pt[j], NanoReader_.Muon_eta[j], NanoReader_.Muon_phi[j], MUON_MASS );

                // Electron and photon should not give the Z-mass
                if( fabs((Mu+LV_pho1).M() - 91.187) < 5.0) continue;
                if( fabs((Mu+LV_pho2).M() - 91.187) < 5.0) continue;

                nTightMu++;
                LV_tightMuon.push_back(Mu);
            }

            if (nMu!=0)
            {
                totalCutFlow_SL->Fill("Mu before cut",1);
            }
            if (nTightMu!=0)
            {
                totalCutFlow_SL->Fill("Mu after cut",1);
            }
           
            
            for ( uint j=0; j < *NanoReader_.nElectron; j++ )
            {
                nEle++;
                if ( NanoReader_.Electron_pt[j] < LEP_PT_VETO_CUT ) continue;
                if ( abs(NanoReader_.Electron_eta[j]) > EL_ETA_CUT ) continue;
                if ( NanoReader_.Electron_convVeto[j] == false) continue;

                // cut-based ID (0:fail, 1:veto, 2:loose, 3:medium, 4:tight)
                // Veto, 2016 -> cutbased HLT safe
                // 2017, 2018 -> cutbased loost Fall17V2
                if ( era == 2016 ) {
                    if ( NanoReader_.Electron_cutBased_HLTPreSel[j] == 0 ) continue;
                    // if ( NanoReader_.Electron_lostHits[j] >= 1 ) continue;
                }
                else {
                    if ( NanoReader_.Electron_cutBased[j] < 2 ) continue;
                    // if ( NanoReader_.Electron_convVeto[j] != 1) continue;
                    // for 2017, 2018
                    // if ( abs(NanoReader_.Electron_eta[j]) > 1.479 ) {
                    // if (abs(NanoReader_.Electron_sieie[j]) > 0.03 ) continue;
                    // if (abs(NanoReader_.Electron_eInvMinusPInv[j]) > 0.014 ) continue;
                    // }
                }
                bool isClean=true;
                for ( std::size_t k=0; k<2; k++) {
                    if (deltaR(LV_tightPhoton.at(k).Eta(), LV_tightPhoton.at(k).Phi(),
                               NanoReader_.Electron_eta[j], NanoReader_.Electron_phi[j]) < 0.4) {
                        isClean = false;
                    }
                }
                if ( isClean == false ) continue;

                TLorentzVector Ele(0,0,0,0);
                // Ele.SetPtEtaPhiM( NanoReader_.Electron_pt[j], NanoReader_.Electron_eta[j], NanoReader_.Electron_phi[j], NanoReader_.Electron_mass[j] );
                Ele.SetPtEtaPhiM( NanoReader_.Electron_pt[j], NanoReader_.Electron_eta[j], NanoReader_.Electron_phi[j], ELE_MASS );

                // Electron and photon should not give the Z-mass
                if( fabs((Ele+LV_pho1).M() - 91.187) < 5.0) continue;
                if( fabs((Ele+LV_pho2).M() - 91.187) < 5.0) continue;

                nTightEle++;
                LV_tightEle.push_back(Ele);
            }
            // std::cout << "\t[INFO] Number of Eletrons: " << nTightEle
            // <<" \t Number of Muons:" << nTightMu <<"\t Numbers of leptons:" << nTightEle + nTightMu << std::endl;
            if(nMu + nEle != 0)
            {
                totalCutFlow_SL->Fill("All Leptons",1);
            }
            if(nEle != 0)
            {
                totalCutFlow_SL->Fill("Ele before cut",1);
            }
            if(nTightEle!=0)
            {
                totalCutFlow_SL->Fill("Ele after cut",1);
            }

            if (nTightMu + nTightEle != 1) continue;
            totalCutFlow_SL->Fill("Lepton Selection",1);
            totalCutFlow_SL_GENMatch->Fill("Lepton Selection",1);
            
            /* -------------------------------------------------------------------------- */
            /*                                   AK8Jet   Higgs Jet                       */
            /* -------------------------------------------------------------------------- */
            // AK8
            LV_Ak8HiggsJets.clear();
            goodHJetIndex.clear();
            float dmV = 0.0;
            // int fj_idx = -1;

           
            if (DEBUG) std::cout << "\t[INFO::AK8jets] [" << i <<"/" << lineCount << "] After one jet if condition" << std::endl;

            /* -------------------------------------------------------------------------- */
            /*                                   AK8Jet   W Jet                       */
            /* -------------------------------------------------------------------------- */
            // AK8
            LV_Ak8WZJets.clear();
            goodWJetIndex.clear();
            dmV = 0.0;
            int nGood_W_FatJet = 0;
            // fj_idx = -1;

            for (uint j=0; j<*NanoReader_.nFatJet; j++)
            {
                if ( fabs(NanoReader_.FatJet_eta[j]) > AK8_MAX_ETA ) continue;
                if ( NanoReader_.FatJet_pt[j]<AK8_WJET_MIN_PT ) continue;

                if ( NanoReader_.FatJet_msoftdrop[j]<AK8_WJet_MIN_SDM ) continue;
                if ( NanoReader_.FatJet_msoftdrop[j]>AK8_WJet_MAX_SDM ) continue;

                bool isClean=true;

                if ( NanoReader_.FatJet_tau2[j]/NanoReader_.FatJet_tau1[j] > TAU21) isClean = false;

                // cleaning jet from electron
                for ( std::size_t k=0; k<LV_tightEle.size(); k++)
                {
                    if (deltaR(LV_tightEle.at(k).Eta(), LV_tightEle.at(k).Phi(),
                         NanoReader_.FatJet_eta[j], NanoReader_.FatJet_phi[j]) < AK8_LEP_DR_CUT)
                    isClean = false;
                }
                // cleaning jet from muons
                for ( std::size_t k=0; k<LV_tightMuon.size(); k++)
                {
                    if (deltaR(LV_tightMuon.at(k).Eta(), LV_tightMuon.at(k).Phi(),
                         NanoReader_.FatJet_eta[j], NanoReader_.FatJet_phi[j]) < AK8_LEP_DR_CUT)
                    isClean = false;
                }
                // cleaning jet from photons
                for ( std::size_t k=0; k<2; k++) {
                    if (deltaR(LV_tightPhoton.at(k).Eta(), LV_tightPhoton.at(k).Phi(),
                               NanoReader_.FatJet_eta[j], NanoReader_.FatJet_phi[j]) < AK8_LEP_DR_CUT) {
                        isClean = false;
                    }
                }
                // cleaning fat jet with all other fat jets
                for ( std::size_t k=0; k<goodWJetIndex.size(); k++) {
                  if (deltaR(NanoReader_.FatJet_eta[goodWJetIndex.at(k)], NanoReader_.FatJet_phi[goodWJetIndex.at(k)],
                             NanoReader_.FatJet_eta[j], NanoReader_.FatJet_phi[j]) < AK8_AK8_DR_CUT) {
                    isClean = false;
                  }
                }

                if ( isClean == false ) continue;

                if ( nGood_W_FatJet == 0 ) dmV = fabs(NanoReader_.FatJet_msoftdrop[j] - V_MASS);
                
                if ( fabs(NanoReader_.FatJet_msoftdrop[j] - V_MASS) > dmV ) continue;
                dmV = fabs(NanoReader_.FatJet_msoftdrop[j] - V_MASS);
                // fj_idx = j;
                nGood_W_FatJet++;
                goodWJetIndex.push_back(j);
                LV_Ak8WZJets.push_back(TLorentzVector(0,0,0,0));
                LV_Ak8WZJets.back().SetPtEtaPhiM(NanoReader_.FatJet_pt[j],
                                            NanoReader_.FatJet_eta[j],
                                            NanoReader_.FatJet_phi[j],
                                            NanoReader_.FatJet_msoftdrop[j]
                                            );
            }
            // if (nGood_WLep_FatJet>=1) to talCutFlow_SL->Fill("nAK8_W >= 1",1);

            /* -------------------------------------------------------------------------- */
            /*                                   AK4Jet                                   */
            /* -------------------------------------------------------------------------- */
            goodAK4JetIndex.clear();
            LV_Ak4Jets.clear();
            int nGood_AK4Jet = 0;

            float allAK4JetsSum_pt = 0.0;
            if (DEBUG) std::cout << "Starting AK4 jet loop" << std::endl;
            for (uint j=0; j<*NanoReader_.nJet; j++)
            {
                if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] =====> JetIndex: " << j << std::endl;
                //jet energy scale variations
                if (!( NanoReader_.Jet_pt[j] > AK4_PT_CUT )) continue;
                if (!(fabs(NanoReader_.Jet_eta[j]) < AK4_MAX_ETA)) continue;
                //jet ID
                // https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookNanoAOD#Jets
                // tight jet ID
                if (!(NanoReader_.Jet_jetId[j] >= 2)) continue;
                // PU JET ID for jets pt > AK4_PT_CUT and < 50
                if (NanoReader_.Jet_pt[j] < 50 && NanoReader_.Jet_puId[j] < 3) continue;

                bool isClean=true;

                // object cleaning
                // if (nGood_W_FatJet > 0 || nGood_Higgs_FatJet > 0)
                if (nGood_W_FatJet == 1)
                {
                    for ( std::size_t k=0; k<goodWJetIndex.size(); k++)
                    {
                        if (deltaR(NanoReader_.FatJet_eta[goodWJetIndex.at(k)], NanoReader_.FatJet_phi[goodWJetIndex.at(k)],
                             NanoReader_.Jet_eta[j], NanoReader_.Jet_phi[j]) < AK4_AK8_DR_CUT) {
                            isClean = false;
                        }
                    }
                }

                if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] Clean AK4 jet with other AK4 jets" << std::endl;
                for ( std::size_t k=0; k<goodAK4JetIndex.size(); k++) {
                  if (deltaR(NanoReader_.Jet_eta[goodAK4JetIndex.at(k)], NanoReader_.Jet_phi[goodAK4JetIndex.at(k)],
                             NanoReader_.Jet_eta[j], NanoReader_.Jet_phi[j]) < AK4_AK4_DR_CUT) {
                    isClean = false;
                  }
                }

                if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] Clean AK4 jet with photons jets" << std::endl;
                for ( std::size_t k=0; k<2; k++) {
                    if (deltaR(LV_tightPhoton.at(k).Eta(), LV_tightPhoton.at(k).Phi(),
                               NanoReader_.Jet_eta[j], NanoReader_.Jet_phi[j]) < AK4_LEP_DR_CUT) {
                        isClean = false;
                    }
                }

                for ( std::size_t k=0; k<LV_tightEle.size(); k++) {
                    if (deltaR(LV_tightEle.at(k).Eta(), LV_tightEle.at(k).Phi(),
                               NanoReader_.Jet_eta[j], NanoReader_.Jet_phi[j]) < AK4_LEP_DR_CUT) {
                        isClean = false;
                    }
                }
                for ( std::size_t k=0; k<LV_tightMuon.size(); k++) {
                    if (deltaR(LV_tightMuon.at(k).Eta(), LV_tightMuon.at(k).Phi(),
                               NanoReader_.Jet_eta[j], NanoReader_.Jet_phi[j]) < AK4_LEP_DR_CUT) {
                        isClean = false;
                    }
                }

                if ( isClean == false ) continue;


                if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] compute the btag eff." << std::endl;
                //https://twiki.cern.ch/twiki/bin/viewauth/CMS/BTagSFMethods#1a_Event_reweighting_using_scale
                float btag_eff_loose = 1.0;
                float btag_eff_medium = 1.0;
                float btag_eff_tight = 1.0;

                if (NanoReader_.Jet_pt[j]>30) WVJJTree->nAK4Jet30++;
                if (NanoReader_.Jet_pt[j]>50) WVJJTree->nAK4Jet50++;

                if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] AK4 jets Passed all pre-selections" << std::endl;
                if (fabs(NanoReader_.Jet_eta[j]) < 2.5) {

                    if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] Within |eta|<2.5" << std::endl;
                    if (isMC) {
                        btag_eff_loose = scaleFactor.GetBtagEff(NanoReader_.Jet_hadronFlavour[j], NanoReader_.Jet_pt[j], NanoReader_.Jet_eta[j], "loose");
                        btag_eff_medium = scaleFactor.GetBtagEff(NanoReader_.Jet_hadronFlavour[j], NanoReader_.Jet_pt[j], NanoReader_.Jet_eta[j], "medium");
                        btag_eff_tight = scaleFactor.GetBtagEff(NanoReader_.Jet_hadronFlavour[j], NanoReader_.Jet_pt[j], NanoReader_.Jet_eta[j], "tight");
                    }

                    if (DEBUG) std::cout << "\t[INFO::AK4Jets] [" << i <<"/" << lineCount << "] btag_eff_loose = " << btag_eff_loose << std::endl;
                    if (DEBUG) std::cout << "\t[INFO::AK4Jets] [" << i <<"/" << lineCount << "] btag_eff_medium = " << btag_eff_medium << std::endl;
                    if (DEBUG) std::cout << "\t[INFO::AK4Jets] [" << i <<"/" << lineCount << "] btag_eff_tight  = " << btag_eff_tight << std::endl;

                    if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] Got Btag SF for loose, medium and tight" << std::endl;
                  
                }
                if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] btag weight computation done" << std::endl;

                LV_Ak4Jets.push_back(TLorentzVector(0,0,0,0));
                LV_Ak4Jets.back().SetPtEtaPhiM(NanoReader_.Jet_pt[j],
                                            NanoReader_.Jet_eta[j],
                                            NanoReader_.Jet_phi[j],
                                            NanoReader_.Jet_mass[j]
                                            );
                goodAK4JetIndex.push_back(j);
                allAK4JetsSum_pt += NanoReader_.Jet_pt[j];
                nGood_AK4Jet++;
            }
            if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] Outside of AK4 jet loop." << std::endl;

            // for (std::vector<int>::iterator It_JetIndex = goodAK4JetIndex.begin(); It_JetIndex != goodAK4JetIndex.end(); ++It_JetIndex)
            // {
            // std::cout << "DEBUG: " << *It_JetIndex << std::endl;
            // }
            //
            //
            // get 4 jets for FH final state with minWH vals

            int nGoodAK4jets = goodAK4JetIndex.size();

            if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] Passed nJet>=4 conditon" << std::endl;
            //Important: 1 W fat jet
            if ((nTightMu + nTightEle == 1) && nGood_W_FatJet >= 1 )
                {totalCutFlow_SL->Fill("nAK8_W >= 1",1);
                totalCutFlow_SL_GENMatch->Fill("nAK8_W >= 1",1);}
            //Important: 2 W jets
            if ((nTightMu + nTightEle == 1) && nGood_W_FatJet == 0 &&  nGoodAK4jets >= 2)
            {
                WVJJTree->TwoJet_LeadJet_p = LV_Ak4Jets[0].P();
                WVJJTree->TwoJet_LeadJet_pt = LV_Ak4Jets[0].Pt();
                WVJJTree->TwoJet_LeadJet_pz = LV_Ak4Jets[0].Pz();
                WVJJTree->TwoJet_LeadJet_eta = LV_Ak4Jets[0].Eta();
                WVJJTree->TwoJet_LeadJet_phi = LV_Ak4Jets[0].Phi();
                WVJJTree->TwoJet_LeadJet_M = LV_Ak4Jets[0].M();
                WVJJTree->TwoJet_LeadJet_E = LV_Ak4Jets[0].E();
                
                WVJJTree->TwoJet_SubLeadJet_p = LV_Ak4Jets[1].P();
                WVJJTree->TwoJet_SubLeadJet_pt = LV_Ak4Jets[1].Pt();
                WVJJTree->TwoJet_SubLeadJet_pz = LV_Ak4Jets[1].Pz();
                WVJJTree->TwoJet_SubLeadJet_eta = LV_Ak4Jets[1].Eta();
                WVJJTree->TwoJet_SubLeadJet_phi = LV_Ak4Jets[1].Phi();
                WVJJTree->TwoJet_SubLeadJet_M = LV_Ak4Jets[1].M();
                WVJJTree->TwoJet_SubLeadJet_E = LV_Ak4Jets[1].E();
                
              
                WVJJTree->TwoJet_deltaR_GENRECO_HH = deltaR(LV_Ak4Jets[0] + LV_Ak4Jets[1], LV_GEN_WBosons[0]+LV_GEN_WBosons[1]);
                // deltaR between GEN W-bosons and Reconstructed W-bosons
                WVJJTree->TwoJet_deltaR_AK4WBoson_GENW = MinDeltaRFromReferenceLV(LV_Ak4Jets[0] +LV_Ak4Jets[1], LV_GEN_WBosons[0], LV_GEN_WBosons[1]);


                totalCutFlow_SL->Fill("nAK4 >= 2",1);
                totalCutFlow_SL_GENMatch->Fill("nAK4 >= 2",1);
            
            
            
            }
            
            // final selection
            if ((nTightMu + nTightEle == 1) && (
                (nGood_W_FatJet >= 1) ||
                (nGood_W_FatJet == 0 && nGoodAK4jets >= 2))
               )
            {
                {totalCutFlow_SL->Fill("1Jet+2Jet",1);
                totalCutFlow_SL_GENMatch->Fill("1Jet+2Jet",1);}

                if(WVJJTree->pho1_pt_byMgg > 0.35 && WVJJTree->pho2_pt_byMgg > 0.25)
                {   totalCutFlow_SL->Fill("pT/mgg cut",1);
                    totalCutFlow_SL_GENMatch->Fill("pT/mgg cut",1);}
                if(WVJJTree->pho1_pt_byMgg > 0.35 && WVJJTree->pho2_pt_byMgg > 0.25 && WVJJTree->diphoton_pt > 100.0)
                    {totalCutFlow_SL->Fill("pT(#gamma #gamma)>100",1);
                    totalCutFlow_SL_GENMatch->Fill("pT(#gamma #gamma)>100",1);}
            }

           
            if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] After four jet if condition" << std::endl;

            if (isMC==1) {
                WVJJTree->nScaleWeight = *NanoReader_.nLHEScaleWeight;
                WVJJTree->nPdfWeight = *NanoReader_.nLHEPdfWeight;

                for (uint j=0; j<WVJJTree->nScaleWeight; j++) {
                    //LHE scale variation weights (w_var / w_nominal); [0] is MUR="0.5" MUF="0.5";
                    //[1] is MUR="0.5" MUF="1.0"; [2] is MUR="0.5" MUF="2.0"; [3] is MUR="1.0" MUF="0.5";
                    //[4] is MUR="1.0" MUF="2.0"; [5] is MUR="2.0" MUF="0.5"; [6] is MUR="2.0" MUF="1.0";
                    //[7] is MUR="2.0" MUF="2.0"
                    WVJJTree->scaleWeight[j]=NanoReader_.LHEScaleWeight[j];
                }
                for (uint j=0; j<WVJJTree->nPdfWeight; j++) {
                    //LHE pdf variation weights (w_var / w_nominal) for LHA IDs 91400 - 91432
                    WVJJTree->pdfWeight[j]=NanoReader_.LHEPdfWeight[j];
                }

                // tZq events in ZV signal sample
                if ( (NanoReader_.GenPart_genPartIdxMother[2] == 0 && abs(NanoReader_.GenPart_pdgId[2]) == 6)
                    || (NanoReader_.GenPart_genPartIdxMother[3] == 0 && abs(NanoReader_.GenPart_pdgId[3]) == 6)
                    ) {
                    WVJJTree->is_tZq = true;
                }
                //std::cout<<abs(NanoReader_.GenPart_pdgId[2])<< " " << WVJJTree->is_tZq << std::endl;
            }

            if (isMC==1 && *NanoReader_.nLHEReweightingWeight!=0) {
                WVJJTree->nAqgcWeight=*NanoReader_.nLHEReweightingWeight;

                for (uint j=0; j<WVJJTree->nAqgcWeight; j++) {
                    WVJJTree->aqgcWeight[j]=NanoReader_.LHEReweightingWeight[j];
                }

            }

            if (isMC) {
                //if (era==2016) {
                //  WVJJTree->btagWeight = *NanoReader_.btagWeight_CMVA;
                //}
                //else {
                //  WVJJTree->btagWeight = *NanoReader_.btagWeight_DeepCSVB;
                //}

                if (era!=2018) {
                    WVJJTree->L1PFWeight = *NanoReader_.L1PreFiringWeight_Nom;
                    WVJJTree->L1PFWeight_Up = *NanoReader_.L1PreFiringWeight_Up;
                    WVJJTree->L1PFWeight_Down = *NanoReader_.L1PreFiringWeight_Dn;
                }
            }

            ot->Fill();
        }

        delete t;
        delete r;
        delete f;
        //t=0;
        //r=0;
        //f=0;
    }

    of->Write();
    of->Close();
    TString removeCommand = TString("rm -rf ") + TString(dir_name);
    std::cout << "Delete the temp directory: " << removeCommand << std::endl;
    system((std::string(removeCommand)).c_str());

    return 0;

}
