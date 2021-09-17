#ifndef OUTPUT_HH
#define OUTPUT_HH

#include "TTree.h"

class output{

public:

  output(TTree *t) {
    fTree = t;
    init();
  };

  ~output() {
    delete fTree;
  };

  void clearVars();
  void init();

  TTree *fTree;
  float nTagJets = -999.0;
  float allFullyResolved_AK4JetsSum_pt = -999.0;
  float allOneJet_AK8JetsSum_pt = -999.0;
  float allThreeJet_AK4JetsSum_pt = -999.0;
  int nGoodOneJet_FatJet = -999;
  int nGoodThreeJet_FatJet = -999;
  int nGoodThreeJet_Ak4Jet = -999;



  Float_t	OneJet_FatJet_area = -999.0;
  Float_t	OneJet_FatJet_btagCMVA = -999.0;
  Float_t	OneJet_FatJet_btagCSVV2 = -999.0;
  Float_t	OneJet_FatJet_btagDDBvL = -999.0;
  Float_t	OneJet_FatJet_btagDDBvL_noMD = -999.0;
  Float_t	OneJet_FatJet_btagDDCvB = -999.0;
  Float_t	OneJet_FatJet_btagDDCvB_noMD = -999.0;
  Float_t	OneJet_FatJet_btagDDCvL = -999.0;
  Float_t	OneJet_FatJet_btagDDCvL_noMD = -999.0;
  Float_t	OneJet_FatJet_btagDeepB = -999.0;
  Float_t	OneJet_FatJet_btagHbb = -999.0;
  Float_t	OneJet_FatJet_deepTagMD_H4qvsQCD = -999.0;
  Float_t	OneJet_FatJet_deepTagMD_HbbvsQCD = -999.0;
  Float_t	OneJet_FatJet_deepTagMD_TvsQCD = -999.0;
  Float_t	OneJet_FatJet_deepTagMD_WvsQCD = -999.0;
  Float_t	OneJet_FatJet_deepTagMD_ZHbbvsQCD = -999.0;
  Float_t	OneJet_FatJet_deepTagMD_ZHccvsQCD = -999.0;
  Float_t	OneJet_FatJet_deepTagMD_ZbbvsQCD = -999.0;
  Float_t	OneJet_FatJet_deepTagMD_ZvsQCD = -999.0;
  Float_t	OneJet_FatJet_deepTagMD_bbvsLight = -999.0;
  Float_t	OneJet_FatJet_deepTagMD_ccvsLight = -999.0;
  Float_t	OneJet_FatJet_deepTag_H = -999.0;
  Float_t	OneJet_FatJet_deepTag_QCD = -999.0;
  Float_t	OneJet_FatJet_deepTag_QCDothers = -999.0;
  Float_t	OneJet_FatJet_deepTag_TvsQCD = -999.0;
  Float_t	OneJet_FatJet_deepTag_WvsQCD = -999.0;
  Float_t	OneJet_FatJet_deepTag_ZvsQCD = -999.0;
  Float_t	OneJet_FatJet_electronIdx3SJ = -999;
  Float_t	OneJet_FatJet_eta = -999.0;
  Float_t OneJet_FatJet_genJetAK8Idx = -999;
  Float_t	OneJet_FatJet_hadronFlavour = -999;
  Float_t	OneJet_FatJet_jetId = -999;
  Float_t	OneJet_FatJet_lsf3 = -999.0;
  Float_t	OneJet_FatJet_mass = -999.0;
  Float_t	OneJet_FatJet_msoftdrop = -999.0;
  Float_t	  OneJet_FatJet_muonIdx3SJ = -999;
  Float_t	OneJet_FatJet_n2b1 = -999.0;
  Float_t	OneJet_FatJet_n3b1 = -999.0;
  UChar_t	OneJet_FatJet_nBHadrons ;
  UChar_t	OneJet_FatJet_nCHadrons ;
  Float_t	OneJet_FatJet_particleNetMD_QCD = -999.0;
  Float_t	OneJet_FatJet_particleNetMD_Xbb = -999.0;
  Float_t	OneJet_FatJet_particleNetMD_Xcc = -999.0;
  Float_t	OneJet_FatJet_particleNetMD_Xqq = -999.0;
  Float_t	OneJet_FatJet_particleNet_H4qvsQCD = -999.0;
  Float_t	OneJet_FatJet_particleNet_HbbvsQCD = -999.0;
  Float_t	OneJet_FatJet_particleNet_HccvsQCD = -999.0;
  Float_t	OneJet_FatJet_particleNet_QCD = -999.0;
  Float_t	OneJet_FatJet_particleNet_TvsQCD = -999.0;
  Float_t	OneJet_FatJet_particleNet_WvsQCD = -999.0;
  Float_t	OneJet_FatJet_particleNet_ZvsQCD = -999.0;
  Float_t	OneJet_FatJet_phi = -999.0;
  Float_t	OneJet_FatJet_pt = -999.0;
  Float_t	OneJet_FatJet_rawFactor = -999.0;
  Float_t   OneJet_FatJet_subJetIdx1 = -999;
  Float_t	  OneJet_FatJet_subJetIdx2 = -999;
  Float_t	OneJet_FatJet_tau1 = -999.0;
  Float_t	OneJet_FatJet_tau2 = -999.0;
  Float_t	OneJet_FatJet_tau3 = -999.0;
  Float_t	OneJet_FatJet_tau4 = -999.0;
  float	OneJet_nFatJet = -999;  

  float ThreeJet_FatJet_area = -999.0;
  float ThreeJet_FatJet_btagCMVA = -999.0;
  float ThreeJet_FatJet_btagCSVV2 = -999.0;
  float ThreeJet_FatJet_btagDDBvL = -999.0;
  float ThreeJet_FatJet_btagDDBvL_noMD = -999.0;
  float ThreeJet_FatJet_btagDDCvB = -999.0;
  float ThreeJet_FatJet_btagDDCvB_noMD = -999.0;
  float ThreeJet_FatJet_btagDDCvL     = -999.0;
  float ThreeJet_FatJet_btagDDCvL_noMD = -999.0;
  float ThreeJet_FatJet_btagDeepB      = -999.0;
  float ThreeJet_FatJet_btagHbb = -999.0;
  float ThreeJet_FatJet_deepTagMD_H4qvsQCD = -999.0;
  float ThreeJet_FatJet_deepTagMD_HbbvsQCD = -999.0;
  float ThreeJet_FatJet_deepTagMD_TvsQCD = -999.0;
  float ThreeJet_FatJet_deepTagMD_WvsQCD = -999.0;
  float ThreeJet_FatJet_deepTagMD_ZHbbvsQCD = -999.0;
  float ThreeJet_FatJet_deepTagMD_ZHccvsQCD = -999.0;
  float ThreeJet_FatJet_deepTagMD_ZbbvsQCD  = -999.0;
  float ThreeJet_FatJet_deepTagMD_ZvsQCD = -999.0;
  float ThreeJet_FatJet_deepTagMD_bbvsLight = -999.0;
  float ThreeJet_FatJet_deepTagMD_ccvsLight = -999.0;
  float ThreeJet_FatJet_deepTag_H = -999.0;
  float ThreeJet_FatJet_deepTag_QCD = -999.0;
  float ThreeJet_FatJet_deepTag_QCDothers = -999.0;
  float ThreeJet_FatJet_deepTag_TvsQCD = -999.0;
  float ThreeJet_FatJet_deepTag_WvsQCD = -999.0;
  float ThreeJet_FatJet_deepTag_ZvsQCD = -999.0;
  float ThreeJet_FatJet_electronIdx3SJ = -999.0;
  float ThreeJet_FatJet_eta = -999.0;
  float ThreeJet_FatJet_genJetAK8Idx = -999.0;
  float ThreeJet_FatJet_hadronFlavour = -999.0;
  float ThreeJet_FatJet_jetId = -999.0;
  float ThreeJet_FatJet_lsf3 = -999.0;
  float ThreeJet_FatJet_mass = -999.0;
  float ThreeJet_FatJet_msoftdrop = -999.0;
  float ThreeJet_FatJet_muonIdx3SJ = -999.0;
  float ThreeJet_FatJet_n2b1 = -999.0;
  float ThreeJet_FatJet_n3b1 = -999.0;
  float ThreeJet_FatJet_nBHadrons = -999.0;
  float ThreeJetAk4_jet1_pt = -999.0;
  float ThreeJetAk4_jet2_pt = -999.0;
  float ThreeJetAk4_jet1_eta = -999.0;
  float ThreeJetAk4_jet2_eta = -999.0;
  float ThreeJetAk4_jet1_phi = -999.0;
  float ThreeJetAk4_jet2_phi = -999.0;
  float ThreeJetAk4_jet1_M = -999.0;
  float ThreeJetAk4_jet2_M = -999.0;
  float ThreeJet_FatJet_nCHadrons = -999.0;

  //! todo: add this variable but not find in root file
  // FatJet_particleNetMD_QCD=NanoReader.FatJet_particleNetMD_QCD[Ak8JetCount];
  // FatJet_particleNetMD_Xbb=NanoReader.FatJet_particleNetMD_Xbb[Ak8JetCount];
  // FatJet_particleNetMD_Xcc=NanoReader.FatJet_particleNetMD_Xcc[Ak8JetCount];
  // FatJet_particleNetMD_Xqq=NanoReader.FatJet_particleNetMD_Xqq[Ak8JetCount];
  // FatJet_particleNet_H4qvsQCD=NanoReader.FatJet_particleNet_H4qvsQCD[Ak8JetCount];
  // FatJet_particleNet_HbbvsQCD=NanoReader.FatJet_particleNet_HbbvsQCD[Ak8JetCount];
  // FatJet_particleNet_HccvsQCD=NanoReader.FatJet_particleNet_HccvsQCD[Ak8JetCount];
  // FatJet_particleNet_QCD=NanoReader.FatJet_particleNet_QCD[Ak8JetCount];
  // FatJet_particleNet_TvsQCD=NanoReader.FatJet_particleNet_TvsQCD[Ak8JetCount];
  // FatJet_particleNet_WvsQCD=NanoReader.FatJet_particleNet_WvsQCD[Ak8JetCount];
  // FatJet_particleNet_ZvsQCD=NanoReader.FatJet_particleNet_ZvsQCD[Ak8JetCount];
  float ThreeJet_FatJet_phi=-999.0;
  float ThreeJet_FatJet_pt=-999.0;
  float ThreeJet_FatJet_rawFactor=-999.0;
  float ThreeJet_FatJet_subJetIdx1=-999.0;
  float ThreeJet_FatJet_subJetIdx2=-999.0;
  float ThreeJet_FatJet_tau1=-999.0;
  float ThreeJet_FatJet_tau2=-999.0;
  float ThreeJet_FatJet_tau3=-999.0;
  float ThreeJet_FatJet_tau4=-999.0;
  float ThreeJet_nFatJet=-999.0;

 


  float FullyResolved_jet1_pt = -999.0;
  float FullyResolved_jet2_pt = -999.0;
  float FullyResolved_jet3_pt = -999.0;
  float FullyResolved_jet4_pt = -999.0;

  float FullyResolved_jet1_eta = -999.0;
  float FullyResolved_jet2_eta = -999.0;
  float FullyResolved_jet3_eta = -999.0;
  float FullyResolved_jet4_eta = -999.0;

  float FullyResolved_jet1_phi = -999.0;
  float FullyResolved_jet2_phi = -999.0;
  float FullyResolved_jet3_phi = -999.0;
  float FullyResolved_jet4_phi = -999.0;

  float FullyResolved_jet1_E = -999.0;
  float FullyResolved_jet2_E = -999.0;
  float FullyResolved_jet3_E = -999.0;
  float FullyResolved_jet4_E = -999.0;

  float FullyResolved_jet1_M = -999.0;
  float FullyResolved_jet2_M = -999.0;
  float FullyResolved_jet3_M = -999.0;
  float FullyResolved_jet4_M = -999.0;

  float FullyResolvedTwoLeadingJets_pt = -999.0;
  float FullyResolvedTwoLeadingJets_eta = -999.0;
  float FullyResolvedTwoLeadingJets_phi = -999.0;
  float FullyResolvedTwoLeadingJets_m = -999.0;
  float FullyResolvedTwoLeadingJets_E = -999.0;


  float FullyResolvedThirdFourthJets_pt = -999.0;
  float FullyResolvedThirdFourthJets_eta = -999.0;
  float FullyResolvedThirdFourthJets_phi = -999.0;
  float FullyResolvedThirdFourthJets_m = -999.0;
  float FullyResolvedThirdFourthJets_E = -999.0;

  float FullyResolvedFourJets_pt = -999.0;
  float FullyResolvedFourJets_eta = -999.0;
  float FullyResolvedFourJets_phi = -999.0;
  float FullyResolvedFourJets_m = -999.0;
  float FullyResolvedFourJets_E = -999.0;

  float ThreeJetTwoLeadingJets_pt = -999.0;
  float ThreeJetTwoLeadingJets_eta = -999.0;
  float ThreeJetTwoLeadingJets_phi = -999.0;
  float ThreeJetTwoLeadingJets_m = -999.0;
  float ThreeJetTwoLeadingJets_E = -999.0;
  // float AK8_Jet1_pt = -999.0;
  // float AK8_Jet2_pt = -999.0;
  // float AK8_Jet3_pt = -999.0;
  // float AK8_Jet4_pt = -999.0;

  // float AK8_Jet1_eta = -999.0;
  // float AK8_Jet2_eta = -999.0;
  // float AK8_Jet3_eta = -999.0;
  // float AK8_Jet4_eta = -999.0;

  // float AK8_Jet1_phi = -999.0;
  // float AK8_Jet2_phi = -999.0;
  // float AK8_Jet3_phi = -999.0;
  // float AK8_Jet4_phi = -999.0;


  //------------------------------------//
  //       METADATA AND EVENT WEIGHTS   //
  //------------------------------------//

  uint run = 0;
  uint ls = 0;
  uint evt = 0;
  // float nPV = -999.0;
  float nPU_mean = -999.0;
  float genWeight = -999.0;
  float puWeight = -999.0;
  float puWeight_Up = -999.0;
  float puWeight_Dn = -999.0;
  float L1PFWeight = -999.0;
  float LHEWeight[1164] = {};
  uint nScaleWeight;
  uint nPdfWeight;
  float scaleWeight[200] = {};
  float pdfWeight[200] = {};

  //btag counters
  uint nBtag_loose;
  uint nBtag_medium;
  uint nBtag_tight;

  float btagWeight = -999.0;

  //triggers
  bool trigger_1Pho = false;
  bool trigger_2Pho = false;

  //signal vs anti-iso
  bool isAntiIso = -999.0;

  //------------------------------------//
  //       LEPTONS                      //
  //------------------------------------//

  //photon 1
  float pho1_pt = -999.0;
  float pho1_eta = -999.0;
  float pho1_phi = -999.0;
  float pho1_m = -999.0;
  float pho1_q = -999.0;
  float pho1_iso = -999.0;
  float pho1_dxy = -999.0;
  float pho1_dz = -999.0;
  float pho1_idEffWeight = -999.0;
  float pho1_E = -999.0;
  float pho1_pt_byMgg = -999.0;
  float pho1_E_byMgg = -999.0;
  //photon 1 scale variations
  float pho1_pt_scaleUp = -999.0;
  float pho1_pt_scaleDn = -999.0;

  //photon 2
  float pho2_pt = -999.0;
  float pho2_eta = -999.0;
  float pho2_phi = -999.0;
  float pho2_m = -999.0;
  float pho2_q = -999.0;
  float pho2_iso = -999.0;
  float pho2_dxy = -999.0;
  float pho2_dz = -999.0;
  float pho2_idEffWeight = -999.0;
  float pho2_E = -999.0;
  float pho2_pt_byMgg = -999.0;
  float pho2_E_byMgg = -999.0;

  //photon 2 scale variations
  float pho2_pt_scaleUp = -999.0;
  float pho2_pt_scaleDn = -999.0;

  //diphoton final state
  float diphoton_m = -999.0;
  float diphoton_pt = -999.0;
  float diphoton_eta = -999.0;
  float diphoton_phi = -999.0;
  float diphoton_E = -999.0;
  //diphoton scale variations
  float diphoton_m_scaleUp = -999.0;
  float diphoton_m_scaleDn = -999.0;
  float diphoton_pt_scaleUp = -999.0;
  float diphoton_pt_scaleDn = -999.0;
  float pho1_mvaID_Fall17V1p1 = -999.0;
  float pho2_mvaID_Fall17V1p1 = -999.0;
  float pho1_mvaID_WP80 = -999.0;
  float pho2_mvaID_WP80 = -999.0;
  float pho1_mvaID_WP90 = -999.0;
  float pho2_mvaID_WP90 = -999.0;
  float pho1_mvaIDFall17V1 = -999.0;
  float pho1_mvaIDFall17V2 = -999.0;
  float pho2_mvaIDFall17V1 = -999.0;
  float pho2_mvaIDFall17V2 = -999.0;

};

#endif
