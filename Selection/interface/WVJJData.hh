#ifndef WVJJ_DATA_HH
#define WVJJ_DATA_HH

#include "TTree.h"

class WVJJData {

public:

  WVJJData(TTree *t) {
    fTree = t;
    init();
  };

  ~WVJJData() {
    delete fTree;
  };

  void clearVars();
  void init();

  TTree *fTree;

  //------------------------------------//
  //       METADATA AND EVENT WEIGHTS   //
  //------------------------------------//

  float diphoton_dRgg = -999.0;
  float diphoton_dPhigg = -999.0;
  float diphoton_dEtagg = -999.0;
  float TwoJet_deltaR_jj = -999.0;
  float TwoJet_deltaPhi_jj = -999.0;
  float TwoJet_deltaEta_jj = -999.0;
  float ThreeJet_deltaR_AK8AK40 = -999.0;
  float ThreeJet_deltaR_AK8AK41 = -999.0;
  float ThreeJet_deltaR_MinAK8AK4 = -999.0;
  float FullyResolved_deltaR_MinAlljeta = -999.0;

  uint run;
  uint ls;
  uint long evt;
  float nPV = -999.0;
  float nPU_mean = -999.0;
  float genWeight = -999.0;
  float puWeight = -999.0;
  float puWeight_Up = -999.0;
  float puWeight_Down = -999.0;
  float L1PFWeight = -999.0;
  float L1PFWeight_Up = -999.0;
  float L1PFWeight_Down = -999.0;
  uint nScaleWeight;
  uint nPdfWeight;
  uint nAqgcWeight;
  float scaleWeight[200] = {};
  float pdfWeight[200] = {};
  float aqgcWeight[1000] = {};

  // tZq veto ZV
  bool is_tZq;

  float GEN_HWW_pT = -999.0;
  float GEN_HWW_eta = -999.0;
  float GEN_HWW_phi = -999.0;
  float GEN_HWW_energy = -999.0;
  float GEN_HGG_pT = -999.0;
  float GEN_HGG_eta = -999.0;
  float GEN_HGG_phi = -999.0;
  float GEN_HGG_energy = -999.0;

  float GEN_Lepton1_p = -999.0;
  float GEN_Lepton1_pt = -999.0;
  float GEN_Lepton1_pz = -999.0;
  float GEN_Lepton1_eta = -999.0;
  float GEN_Lepton1_phi = -999.0;
  float GEN_Lepton1_m = -999.0;
  float GEN_Lepton1_E = -999.0;
  float GEN_Ele_p = -999.0;
  float GEN_Ele_pt = -999.0;
  float GEN_Ele_pz = -999.0;
  float GEN_Ele_eta = -999.0;
  float GEN_Ele_phi = -999.0;
  float GEN_Ele_m = -999.0;
  float GEN_Ele_E = -999.0;
  float GEN_Muon_p = -999.0;
  float GEN_Muon_pt = -999.0;
  float GEN_Muon_pz = -999.0;
  float GEN_Muon_eta = -999.0;
  float GEN_Muon_phi = -999.0;
  float GEN_Muon_m = -999.0;
  float GEN_Muon_E = -999.0;
  float Ele_p = -999.0;
  float Ele_pt = -999.0;
  float Ele_pz = -999.0;
  float Ele_eta = -999.0;
  float Ele_phi = -999.0;
  float Ele_m = -999.0;
  float Ele_E = -999.0;
  float Muon_p = -999.0;
  float Muon_pt = -999.0;
  float Muon_pz = -999.0;
  float Muon_eta = -999.0;
  float Muon_phi = -999.0;
  float Muon_m = -999.0;
  float Muon_E = -999.0;
  float GEN_Lepton2_p = -999.0;
  float GEN_Lepton2_pt = -999.0;
  float GEN_Lepton2_pz = -999.0;
  float GEN_Lepton2_eta = -999.0;
  float GEN_Lepton2_phi = -999.0;
  float GEN_Lepton2_m = -999.0;
  float GEN_Lepton2_E = -999.0;
  float GEN_Lepton3_p = -999.0;
  float GEN_Lepton3_pt = -999.0;
  float GEN_Lepton3_pz = -999.0;
  float GEN_Lepton3_eta = -999.0;
  float GEN_Lepton3_phi = -999.0;
  float GEN_Lepton3_m = -999.0;
  float GEN_Lepton3_E = -999.0;
  float GEN_LeadingPhoton_pT = -999.0;
  float GEN_LeadingPhoton_eta = -999.0;
  float GEN_LeadingPhoton_phi = -999.0;
  float GEN_LeadingPhoton_energy = -999.0;
  float GEN_SubLeadingPhoton_pT = -999.0;
  float GEN_SubLeadingPhoton_eta = -999.0;
  float GEN_SubLeadingPhoton_phi = -999.0;
  float GEN_SubLeadingPhoton_energy = -999.0;
  float GEN_Q1_pT = -999.0;
  float GEN_Q1_eta = -999.0;
  float GEN_Q1_phi = -999.0;
  float GEN_Q1_energy = -999.0;
  float GEN_Q2_pT = -999.0;
  float GEN_Q2_eta = -999.0;
  float GEN_Q2_phi = -999.0;
  float GEN_Q2_energy = -999.0;
  float GEN_Q3_pT = -999.0;
  float GEN_Q3_eta = -999.0;
  float GEN_Q3_phi = -999.0;
  float GEN_Q3_energy = -999.0;
  float GEN_Q4_pT = -999.0;
  float GEN_Q4_eta = -999.0;
  float GEN_Q4_phi = -999.0;
  float GEN_Q4_energy = -999.0;
  float GEN_W1_pT = -999.0;
  float GEN_W1_eta = -999.0;
  float GEN_W1_phi = -999.0;
  float GEN_W1_energy = -999.0;
  float GEN_W2_pT = -999.0;
  float GEN_W2_eta = -999.0;
  float GEN_W2_phi = -999.0;
  float GEN_W2_energy = -999.0;
  float GEN_H1_pT = -999.0;
  float GEN_H1_eta = -999.0;
  float GEN_H1_phi = -999.0;
  float GEN_H1_energy = -999.0;
  float GEN_H2_pT = -999.0;
  float GEN_H2_eta = -999.0;
  float GEN_H2_phi = -999.0;
  float GEN_H2_energy = -999.0;

  float GEN_HWW_mass = -999.0;
  float GEN_HGG_mass = -999.0;
  float GEN_LeadingPhoton_mass = -999.0;
  float GEN_SubLeadingPhoton_mass = -999.0;
  float GEN_Q1_mass = -999.0;
  float GEN_Q2_mass = -999.0;
  float GEN_Q3_mass = -999.0;
  float GEN_Q4_mass = -999.0;
  float GEN_W1_mass = -999.0;
  float GEN_W2_mass = -999.0;
  float GEN_H1_mass = -999.0;
  float GEN_H2_mass = -999.0;
  // GEN level x->HH
  float GEN_Radion_HH_p = -999.0;
  float GEN_Radion_HH_pt = -999.0;
  float GEN_Radion_HH_pz = -999.0;
  float GEN_Radion_HH_eta = -999.0;
  float GEN_Radion_HH_phi = -999.0;
  float GEN_Radion_HH_m = -999.0;
  float GEN_Radion_HH_E = -999.0;
  // GEN level x->HH->WWgg
  float GEN_Radion_WWgg_p = -999.0;
  float GEN_Radion_WWgg_pt = -999.0;
  float GEN_Radion_WWgg_pz = -999.0;
  float GEN_Radion_WWgg_eta = -999.0;
  float GEN_Radion_WWgg_phi = -999.0;
  float GEN_Radion_WWgg_m = -999.0;
  float GEN_Radion_WWgg_E = -999.0;

  float LHE_deltaR_HH = -999.0;
  float LHE_deltaEta_HH = -999.0;
  float LHE_deltaPhi_HH = -999.0;
  float LHE_H1_p = -999.0;
  float LHE_H2_p = -999.0;
  float LHE_H1_pt = -999.0;
  float LHE_H2_pt = -999.0;
  float LHE_H1_pz = -999.0;
  float LHE_H2_pz = -999.0;
  float LHE_H1_eta = -999.0;
  float LHE_H2_eta = -999.0;
  float LHE_H1_phi = -999.0;
  float LHE_H2_phi = -999.0;
  // LHE level x->HH
  float LHE_Radion_HH_p = -999.0;
  float LHE_Radion_HH_pt = -999.0;
  float LHE_Radion_HH_pz = -999.0;
  float LHE_Radion_HH_eta = -999.0;
  float LHE_Radion_HH_phi = -999.0;
  float LHE_Radion_HH_m = -999.0;
  float LHE_Radion_HH_E = -999.0;


  float LHEGEN_deltaR_HToGGH = -999.0;
  float LHEGEN_deltaR_HToWWH = -999.0;
  float DiPhoton_deltaR_LHERECO_HH = -999.0;

  float GEN_deltaR_GG = -999.0;
  float GEN_deltaR_WW = -999.0;
  float GEN_deltaR_MIN4Q = -999.0;
  float DiPhoton_deltaR_GENRECO_HH = -999.0;
  float Leading_photon_deltaR_GENRECO_G = -999.0;
  float SubLeading_photon_deltaR_GENRECO_G = -999.0;
  float DiPhoton_deltaR_pho1_GENPhoton = -999.0;
  float DiPhoton_deltaR_pho2_GENPhoton = -999.0;
  float TwoJet_deltaR_GENRECO_HH = -999.0;
  float TwoJet_deltaR_LeadAK8WBoson_GENW = -999.0;
  float TwoJet_deltaR_SubLeadAK8WBoson_GENW = -999.0;
  float ThreeJet_deltaR_GENRECO_HH = -999.0;
  float ThreeJet_deltaR_AK4WBoson_GENW = -999.0;
  float ThreeJet_deltaR_AK8WBoson_GENW = -999.0;
  float ThreeJet_deltaR_AK4_1stJet_GENW = -999.0;
  float ThreeJet_deltaR_AK4_2ndJet_GENW = -999.0;
  float FullyResolved_deltaR_1stLeadingJet_GENQ = -999.0;
  float FullyResolved_deltaR_2ndLeadingJet_GENQ = -999.0;
  float FullyResolved_deltaR_3rdLeadingJet_GENQ = -999.0;
  float FullyResolved_deltaR_4thLeadingJet_GENQ = -999.0;
  float FullyResolved_deltaR_LeadingWboson_GENW = -999.0;
  float FullyResolved_deltaR_SubLeadingWboson_GENW = -999.0;
  float FullyResolved_deltaR_GENRECO_HH = -999.0;

  float OneJet_deltaR_LHERECO_HH = -999.0;
  float TwoJet_deltaR_LHERECO_HH = -999.0;
  float ThreeJet_deltaR_LHERECO_HH = -999.0;
  float FullyResolved_deltaR_LHERECO_HH = -999.0;

  //njet counters
  uint nAK4Jet30;
  uint nAK4Jet50;
  uint nJet30_noClean;
  uint nJet50_noClean;
  uint nGoodAK4jets;

  //btag counters
  uint nAK4Btag_loose;
  uint nAK4Btag_medium;
  uint nAK4Btag_tight;

  float btagWeight_loose = -999.0;
  float btagWeight_loose_Up = -999.0;
  float btagWeight_loose_Down = -999.0;
  float btagWeight_medium = -999.0;
  float btagWeight_medium_Up = -999.0;
  float btagWeight_medium_Down = -999.0;
  float btagWeight_tight = -999.0;
  float btagWeight_tight_Up = -999.0;
  float btagWeight_tight_Down = -999.0;

  //triggers
  bool trigger_1Mu;
  bool trigger_2Mu;
  bool trigger_1El;
  bool trigger_2El;
  bool trigger_2Pho;

  //signal vs anti-iso
  bool isAntiIso;
  float lepFakeRate = -999.0;

  //------------------------------------//
  //       LEPTONS                      //
  //------------------------------------//

  //lepton 1
  float lep1_pt = -999.0;
  float lep1_eta = -999.0;
  float lep1_phi = -999.0;
  float lep1_m = -999.0;
  float lep1_q = -999.0;
  float lep1_iso = -999.0;
  float lep1_dxy = -999.0;
  float lep1_dz = -999.0;
  float lep1_sip3d = -999.0;
  float lep1_idEffWeight = -999.0;
  float lep1_trigEffWeight = -999.0;

  //lepton 1 scale variations
  float lep1_pt_scaleUp = -999.0;
  float lep1_pt_scaleDown = -999.0;

  //lepton 2
  float lep2_pt = -999.0;
  float lep2_eta = -999.0;
  float lep2_phi = -999.0;
  float lep2_m = -999.0;
  float lep2_q = -999.0;
  float lep2_iso = -999.0;
  float lep2_dxy = -999.0;
  float lep2_dz = -999.0;
  float lep2_sip3d = -999.0;
  float lep2_idEffWeight = -999.0;
  float lep2_trigEffWeight = -999.0;

  //lepton 2 scale variations
  float lep2_pt_scaleUp = -999.0;
  float lep2_pt_scaleDown = -999.0;

  //dilepton final state
  float dilep_m = -999.0;
  float dilep_mt = -999.0;
  float dilep_pt = -999.0;
  float dilep_eta = -999.0;
  float dilep_phi = -999.0;

  //dilepton JES variations
  float dilep_m_jesFlavorQCDUp = -999.0;
  float dilep_m_jesFlavorQCDDown = -999.0;
  float dilep_m_jesRelativeBalUp = -999.0;
  float dilep_m_jesRelativeBalDown = -999.0;
  float dilep_m_jesHFUp = -999.0;
  float dilep_m_jesHFDown = -999.0;
  float dilep_m_jesBBEC1Up = -999.0;
  float dilep_m_jesBBEC1Down = -999.0;
  float dilep_m_jesEC2Up = -999.0;
  float dilep_m_jesEC2Down = -999.0;
  float dilep_m_jesAbsoluteUp = -999.0;
  float dilep_m_jesAbsoluteDown = -999.0;
  float dilep_m_jesBBEC1_YearUp = -999.0;
  float dilep_m_jesBBEC1_YearDown = -999.0;
  float dilep_m_jesEC2_YearUp = -999.0;
  float dilep_m_jesEC2_YearDown = -999.0;
  float dilep_m_jesAbsolute_YearUp = -999.0;
  float dilep_m_jesAbsolute_YearDown = -999.0;
  float dilep_m_jesHF_YearUp = -999.0;
  float dilep_m_jesHF_YearDown = -999.0;
  float dilep_m_jesRelativeSample_YearUp = -999.0;
  float dilep_m_jesRelativeSample_YearDown = -999.0;
  float dilep_m_jesTotalUp = -999.0;
  float dilep_m_jesTotalDown = -999.0;

  float dilep_mt_jesFlavorQCDUp = -999.0;
  float dilep_mt_jesFlavorQCDDown = -999.0;
  float dilep_mt_jesRelativeBalUp = -999.0;
  float dilep_mt_jesRelativeBalDown = -999.0;
  float dilep_mt_jesHFUp = -999.0;
  float dilep_mt_jesHFDown = -999.0;
  float dilep_mt_jesBBEC1Up = -999.0;
  float dilep_mt_jesBBEC1Down = -999.0;
  float dilep_mt_jesEC2Up = -999.0;
  float dilep_mt_jesEC2Down = -999.0;
  float dilep_mt_jesAbsoluteUp = -999.0;
  float dilep_mt_jesAbsoluteDown = -999.0;
  float dilep_mt_jesBBEC1_YearUp = -999.0;
  float dilep_mt_jesBBEC1_YearDown = -999.0;
  float dilep_mt_jesEC2_YearUp = -999.0;
  float dilep_mt_jesEC2_YearDown = -999.0;
  float dilep_mt_jesAbsolute_YearUp = -999.0;
  float dilep_mt_jesAbsolute_YearDown = -999.0;
  float dilep_mt_jesHF_YearUp = -999.0;
  float dilep_mt_jesHF_YearDown = -999.0;
  float dilep_mt_jesRelativeSample_YearUp = -999.0;
  float dilep_mt_jesRelativeSample_YearDown = -999.0;
  float dilep_mt_jesTotalUp = -999.0;
  float dilep_mt_jesTotalDown = -999.0;

  float dilep_pt_jesFlavorQCDUp = -999.0;
  float dilep_pt_jesFlavorQCDDown = -999.0;
  float dilep_pt_jesRelativeBalUp = -999.0;
  float dilep_pt_jesRelativeBalDown = -999.0;
  float dilep_pt_jesHFUp = -999.0;
  float dilep_pt_jesHFDown = -999.0;
  float dilep_pt_jesBBEC1Up = -999.0;
  float dilep_pt_jesBBEC1Down = -999.0;
  float dilep_pt_jesEC2Up = -999.0;
  float dilep_pt_jesEC2Down = -999.0;
  float dilep_pt_jesAbsoluteUp = -999.0;
  float dilep_pt_jesAbsoluteDown = -999.0;
  float dilep_pt_jesBBEC1_YearUp = -999.0;
  float dilep_pt_jesBBEC1_YearDown = -999.0;
  float dilep_pt_jesEC2_YearUp = -999.0;
  float dilep_pt_jesEC2_YearDown = -999.0;
  float dilep_pt_jesAbsolute_YearUp = -999.0;
  float dilep_pt_jesAbsolute_YearDown = -999.0;
  float dilep_pt_jesHF_YearUp = -999.0;
  float dilep_pt_jesHF_YearDown = -999.0;
  float dilep_pt_jesRelativeSample_YearUp = -999.0;
  float dilep_pt_jesRelativeSample_YearDown = -999.0;
  float dilep_pt_jesTotalUp = -999.0;
  float dilep_pt_jesTotalDown = -999.0;

  //dilepton lepton scale variations
  float dilep_m_scaleUp = -999.0;
  float dilep_m_scaleDown = -999.0;
  float dilep_mt_scaleUp = -999.0;
  float dilep_mt_scaleDown = -999.0;
  float dilep_pt_scaleUp = -999.0;
  float dilep_pt_scaleDown = -999.0;


  // Photons
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


  //------------------------------------//
  //       MET                          //
  //------------------------------------//

  float MET = -999.0;
  float MET_phi = -999.0;
  float MET_2017 = -999.0;

  float MET_jesFlavorQCDUp = -999.0;
  float MET_jesFlavorQCDDown = -999.0;
  float MET_jesRelativeBalUp = -999.0;
  float MET_jesRelativeBalDown = -999.0;
  float MET_jesHFUp = -999.0;
  float MET_jesHFDown = -999.0;
  float MET_jesBBEC1Up = -999.0;
  float MET_jesBBEC1Down = -999.0;
  float MET_jesEC2Up = -999.0;
  float MET_jesEC2Down = -999.0;
  float MET_jesAbsoluteUp = -999.0;
  float MET_jesAbsoluteDown = -999.0;
  float MET_jesBBEC1_YearUp = -999.0;
  float MET_jesBBEC1_YearDown = -999.0;
  float MET_jesEC2_YearUp = -999.0;
  float MET_jesEC2_YearDown = -999.0;
  float MET_jesAbsolute_YearUp = -999.0;
  float MET_jesAbsolute_YearDown = -999.0;
  float MET_jesHF_YearUp = -999.0;
  float MET_jesHF_YearDown = -999.0;
  float MET_jesRelativeSample_YearUp = -999.0;
  float MET_jesRelativeSample_YearDown = -999.0;
  float MET_jesTotalUp = -999.0;
  float MET_jesTotalDown = -999.0;

  float MET_phi_jesFlavorQCDUp = -999.0;
  float MET_phi_jesFlavorQCDDown = -999.0;
  float MET_phi_jesRelativeBalUp = -999.0;
  float MET_phi_jesRelativeBalDown = -999.0;
  float MET_phi_jesHFUp = -999.0;
  float MET_phi_jesHFDown = -999.0;
  float MET_phi_jesBBEC1Up = -999.0;
  float MET_phi_jesBBEC1Down = -999.0;
  float MET_phi_jesEC2Up = -999.0;
  float MET_phi_jesEC2Down = -999.0;
  float MET_phi_jesAbsoluteUp = -999.0;
  float MET_phi_jesAbsoluteDown = -999.0;
  float MET_phi_jesBBEC1_YearUp = -999.0;
  float MET_phi_jesBBEC1_YearDown = -999.0;
  float MET_phi_jesEC2_YearUp = -999.0;
  float MET_phi_jesEC2_YearDown = -999.0;
  float MET_phi_jesAbsolute_YearUp = -999.0;
  float MET_phi_jesAbsolute_YearDown = -999.0;
  float MET_phi_jesHF_YearUp = -999.0;
  float MET_phi_jesHF_YearDown = -999.0;
  float MET_phi_jesRelativeSample_YearUp = -999.0;
  float MET_phi_jesRelativeSample_YearDown = -999.0;
  float MET_phi_jesTotalUp = -999.0;
  float MET_phi_jesTotalDown = -999.0;


  float PuppiMET = -999.0;
  float PuppiMET_phi = -999.0;

  //W neutrino pZ
  float neu_pz_type0 = -999.0;
  //------------------------------------//
  //       1 Jet Case (AK8 Higgs jet)   //
  //------------------------------------//
  int nOneJet_GoodFatJet = -999;

  float OneJet_FatJet_area = -999.0;
  float OneJet_FatJet_btagCMVA = -999.0;
  float OneJet_FatJet_btagCSVV2 = -999.0;
  float OneJet_FatJet_btagDDBvL = -999.0;
  float OneJet_FatJet_btagDDBvL_noMD = -999.0;
  float OneJet_FatJet_btagDDCvB = -999.0;
  float OneJet_FatJet_btagDDCvB_noMD = -999.0;
  float OneJet_FatJet_btagDDCvL = -999.0;
  float OneJet_FatJet_btagDDCvL_noMD = -999.0;
  float OneJet_FatJet_btagDeepB = -999.0;
  float OneJet_FatJet_btagHbb = -999.0;
  float OneJet_FatJet_deepTagMD_H4qvsQCD = -999.0;
  float OneJet_FatJet_deepTagMD_HbbvsQCD = -999.0;
  float OneJet_FatJet_deepTagMD_TvsQCD = -999.0;
  float OneJet_FatJet_deepTagMD_WvsQCD = -999.0;
  float OneJet_FatJet_deepTagMD_ZHbbvsQCD = -999.0;
  float OneJet_FatJet_deepTagMD_ZHccvsQCD = -999.0;
  float OneJet_FatJet_deepTagMD_ZbbvsQCD = -999.0;
  float OneJet_FatJet_deepTagMD_ZvsQCD = -999.0;
  float OneJet_FatJet_deepTagMD_bbvsLight = -999.0;
  float OneJet_FatJet_deepTagMD_ccvsLight = -999.0;
  float OneJet_FatJet_deepTag_H = -999.0;
  float OneJet_FatJet_deepTag_QCD = -999.0;
  float OneJet_FatJet_deepTag_QCDothers = -999.0;
  float OneJet_FatJet_deepTag_TvsQCD = -999.0;
  float OneJet_FatJet_deepTag_WvsQCD = -999.0;
  float OneJet_FatJet_deepTag_ZvsQCD = -999.0;
  float OneJet_FatJet_electronIdx3SJ = -999;
  float OneJet_FatJet_eta = -999.0;
  float OneJet_FatJet_genJetAK8Idx = -999;
  float OneJet_FatJet_hadronFlavour = -999;
  float OneJet_FatJet_jetId = -999;
  float OneJet_FatJet_lsf3 = -999.0;
  float OneJet_FatJet_mass = -999.0;
  float OneJet_FatJet_msoftdrop = -999.0;
  float OneJet_FatJet_muonIdx3SJ = -999;
  float OneJet_FatJet_n2b1 = -999.0;
  float OneJet_FatJet_n3b1 = -999.0;
  UChar_t OneJet_FatJet_nBHadrons ;
  UChar_t OneJet_FatJet_nCHadrons ;
  float OneJet_FatJet_particleNetMD_QCD = -999.0;
  float OneJet_FatJet_particleNetMD_Xbb = -999.0;
  float OneJet_FatJet_particleNetMD_Xcc = -999.0;
  float OneJet_FatJet_particleNetMD_Xqq = -999.0;
  float OneJet_FatJet_particleNet_H4qvsQCD = -999.0;
  float OneJet_FatJet_particleNet_HbbvsQCD = -999.0;
  float OneJet_FatJet_particleNet_HccvsQCD = -999.0;
  float OneJet_FatJet_particleNet_QCD = -999.0;
  float OneJet_FatJet_particleNet_TvsQCD = -999.0;
  float OneJet_FatJet_particleNet_WvsQCD = -999.0;
  float OneJet_FatJet_particleNet_ZvsQCD = -999.0;
  float OneJet_FatJet_phi = -999.0;
  float OneJet_FatJet_pt = -999.0;
  float OneJet_FatJet_rawFactor = -999.0;
  float OneJet_FatJet_subJetIdx1 = -999;
  float OneJet_FatJet_subJetIdx2 = -999;
  float OneJet_FatJet_tau1 = -999.0;
  float OneJet_FatJet_tau2 = -999.0;
  float OneJet_FatJet_tau3 = -999.0;
  float OneJet_FatJet_tau4 = -999.0;
  float OneJet_nFatJet = -999;

  float OneJet_Radion_p = -999.0;
  float OneJet_Radion_pt = -999.0;
  float OneJet_Radion_pz = -999.0;
  float OneJet_Radion_eta = -999.0;
  float OneJet_Radion_phi = -999.0;
  float OneJet_Radion_m = -999.0;
  float OneJet_Radion_E = -999.0;
  // SL channel
  float OneJet_p = -999.0;
  float OneJet_pt = -999.0;
  float OneJet_pz = -999.0;
  float OneJet_eta = -999.0;
  float OneJet_phi = -999.0;
  float OneJet_M = -999.0;
  float OneJet_E = -999.0;
  float OneJet_deltaR_GENRECO_HH = -999.0;

  float TwoJet_LeadJet_p = -999.0;
  float TwoJet_LeadJet_pt = -999.0;
  float TwoJet_LeadJet_pz = -999.0;
  float TwoJet_LeadJet_eta = -999.0;
  float TwoJet_LeadJet_phi = -999.0;
  float TwoJet_LeadJet_M = -999.0;
  float TwoJet_LeadJet_E = -999.0;
  float TwoJet_SubLeadJet_p = -999.0;
  float TwoJet_SubLeadJet_pt = -999.0;
  float TwoJet_SubLeadJet_pz = -999.0;
  float TwoJet_SubLeadJet_eta = -999.0;
  float TwoJet_SubLeadJet_phi = -999.0;
  float TwoJet_SubLeadJet_M = -999.0;
  float TwoJet_SubLeadJet_E = -999.0;
  float TwoJet_deltaR_AK4WBoson_GENW = -999.0;

  //---
  float TwoJet_LeadFatJet_area = -999.0;
  float TwoJet_LeadFatJet_btagCMVA = -999.0;
  float TwoJet_LeadFatJet_btagCSVV2 = -999.0;
  float TwoJet_LeadFatJet_btagDDBvL = -999.0;
  float TwoJet_LeadFatJet_btagDDBvL_noMD = -999.0;
  float TwoJet_LeadFatJet_btagDDCvB = -999.0;
  float TwoJet_LeadFatJet_btagDDCvB_noMD = -999.0;
  float TwoJet_LeadFatJet_btagDDCvL = -999.0;
  float TwoJet_LeadFatJet_btagDDCvL_noMD = -999.0;
  float TwoJet_LeadFatJet_btagDeepB = -999.0;
  float TwoJet_LeadFatJet_btagHbb = -999.0;
  float TwoJet_LeadFatJet_deepTagMD_H4qvsQCD = -999.0;
  float TwoJet_LeadFatJet_deepTagMD_HbbvsQCD = -999.0;
  float TwoJet_LeadFatJet_deepTagMD_TvsQCD = -999.0;
  float TwoJet_LeadFatJet_deepTagMD_WvsQCD = -999.0;
  float TwoJet_LeadFatJet_deepTagMD_ZHbbvsQCD = -999.0;
  float TwoJet_LeadFatJet_deepTagMD_ZHccvsQCD = -999.0;
  float TwoJet_LeadFatJet_deepTagMD_ZbbvsQCD = -999.0;
  float TwoJet_LeadFatJet_deepTagMD_ZvsQCD = -999.0;
  float TwoJet_LeadFatJet_deepTagMD_bbvsLight = -999.0;
  float TwoJet_LeadFatJet_deepTagMD_ccvsLight = -999.0;
  float TwoJet_LeadFatJet_deepTag_H = -999.0;
  float TwoJet_LeadFatJet_deepTag_QCD = -999.0;
  float TwoJet_LeadFatJet_deepTag_QCDothers = -999.0;
  float TwoJet_LeadFatJet_deepTag_TvsQCD = -999.0;
  float TwoJet_LeadFatJet_deepTag_WvsQCD = -999.0;
  float TwoJet_LeadFatJet_deepTag_ZvsQCD = -999.0;
  float TwoJet_LeadFatJet_electronIdx3SJ = -999.0;
  float TwoJet_LeadFatJet_eta = -999.0;
  float TwoJet_LeadFatJet_genJetAK8Idx = -999.0;
  float TwoJet_LeadFatJet_hadronFlavour = -999.0;
  float TwoJet_LeadFatJet_jetId = -999.0;
  float TwoJet_LeadFatJet_lsf3 = -999.0;
  float TwoJet_LeadFatJet_mass = -999.0;
  float TwoJet_LeadFatJet_msoftdrop = -999.0;
  float TwoJet_LeadFatJet_muonIdx3SJ = -999.0;
  float TwoJet_LeadFatJet_n2b1 = -999.0;
  float TwoJet_LeadFatJet_n3b1 = -999.0;
  float TwoJet_LeadFatJet_nBHadrons = -999.0;
  float TwoJet_LeadFatJet_nCHadrons = -999.0;
  float TwoJet_FatJet_particleNetMD_QCD = -999.0;
  float TwoJet_FatJet_particleNetMD_Xbb = -999.0;
  float TwoJet_FatJet_particleNetMD_Xcc = -999.0;
  float TwoJet_FatJet_particleNetMD_Xqq = -999.0;
  float TwoJet_FatJet_particleNet_H4qvsQCD = -999.0;
  float TwoJet_FatJet_particleNet_HbbvsQCD = -999.0;
  float TwoJet_FatJet_particleNet_HccvsQCD = -999.0;
  float TwoJet_FatJet_particleNet_QCD = -999.0;
  float TwoJet_FatJet_particleNet_TvsQCD = -999.0;
  float TwoJet_FatJet_particleNet_WvsQCD = -999.0;
  float TwoJet_FatJet_particleNet_ZvsQCD = -999.0;
  float TwoJet_LeadFatJet_phi = -999.0;
  float TwoJet_LeadFatJet_pt = -999.0;
  float TwoJet_LeadFatJet_rawFactor = -999.0;
  float TwoJet_LeadFatJet_subJetIdx1 = -999.0;
  float TwoJet_LeadFatJet_subJetIdx2 = -999.0;
  float TwoJet_LeadFatJet_tau1 = -999.0;
  float TwoJet_LeadFatJet_tau2 = -999.0;
  float TwoJet_LeadFatJet_tau3 = -999.0;
  float TwoJet_LeadFatJet_tau4 = -999.0;
  float TwoJet_nFatJet = -999.0;
  float TwoJet_SubLeadFatJet_area = -999.0;
  float TwoJet_SubLeadFatJet_btagCMVA = -999.0;
  float TwoJet_SubLeadFatJet_btagCSVV2 = -999.0;
  float TwoJet_SubLeadFatJet_btagDDBvL = -999.0;
  float TwoJet_SubLeadFatJet_btagDDBvL_noMD = -999.0;
  float TwoJet_SubLeadFatJet_btagDDCvB = -999.0;
  float TwoJet_SubLeadFatJet_btagDDCvB_noMD = -999.0;
  float TwoJet_SubLeadFatJet_btagDDCvL = -999.0;
  float TwoJet_SubLeadFatJet_btagDDCvL_noMD = -999.0;
  float TwoJet_SubLeadFatJet_btagDeepB = -999.0;
  float TwoJet_SubLeadFatJet_btagHbb = -999.0;
  float TwoJet_SubLeadFatJet_deepTagMD_H4qvsQCD = -999.0;
  float TwoJet_SubLeadFatJet_deepTagMD_HbbvsQCD = -999.0;
  float TwoJet_SubLeadFatJet_deepTagMD_TvsQCD = -999.0;
  float TwoJet_SubLeadFatJet_deepTagMD_WvsQCD = -999.0;
  float TwoJet_SubLeadFatJet_deepTagMD_ZHbbvsQCD = -999.0;
  float TwoJet_SubLeadFatJet_deepTagMD_ZHccvsQCD = -999.0;
  float TwoJet_SubLeadFatJet_deepTagMD_ZbbvsQCD = -999.0;
  float TwoJet_SubLeadFatJet_deepTagMD_ZvsQCD = -999.0;
  float TwoJet_SubLeadFatJet_deepTagMD_bbvsLight = -999.0;
  float TwoJet_SubLeadFatJet_deepTagMD_ccvsLight = -999.0;
  float TwoJet_SubLeadFatJet_deepTag_H = -999.0;
  float TwoJet_SubLeadFatJet_deepTag_QCD = -999.0;
  float TwoJet_SubLeadFatJet_deepTag_QCDothers = -999.0;
  float TwoJet_SubLeadFatJet_deepTag_TvsQCD = -999.0;
  float TwoJet_SubLeadFatJet_deepTag_WvsQCD = -999.0;
  float TwoJet_SubLeadFatJet_deepTag_ZvsQCD = -999.0;
  float TwoJet_SubLeadFatJet_electronIdx3SJ = -999.0;
  float TwoJet_SubLeadFatJet_eta = -999.0;
  float TwoJet_SubLeadFatJet_genJetAK8Idx = -999.0;
  float TwoJet_SubLeadFatJet_hadronFlavour = -999.0;
  float TwoJet_SubLeadFatJet_jetId = -999.0;
  float TwoJet_SubLeadFatJet_lsf3 = -999.0;
  float TwoJet_SubLeadFatJet_mass = -999.0;
  float TwoJet_SubLeadFatJet_msoftdrop = -999.0;
  float TwoJet_SubLeadFatJet_muonIdx3SJ = -999.0;
  float TwoJet_SubLeadFatJet_n2b1 = -999.0;
  float TwoJet_SubLeadFatJet_n3b1 = -999.0;
  float TwoJet_SubLeadFatJet_nBHadrons = -999.0;
  float TwoJet_SubLeadFatJet_nCHadrons = -999.0;
  float TwoJet_SubLeadFatJet_particleNetMD_QCD = -999.0;
  float TwoJet_SubLeadFatJet_particleNetMD_Xbb = -999.0;
  float TwoJet_SubLeadFatJet_particleNetMD_Xcc = -999.0;
  float TwoJet_SubLeadFatJet_particleNetMD_Xqq = -999.0;
  float TwoJet_SubLeadFatJet_particleNet_H4qvsQCD = -999.0;
  float TwoJet_SubLeadFatJet_particleNet_HbbvsQCD = -999.0;
  float TwoJet_SubLeadFatJet_particleNet_HccvsQCD = -999.0;
  float TwoJet_SubLeadFatJet_particleNet_QCD = -999.0;
  float TwoJet_SubLeadFatJet_particleNet_TvsQCD = -999.0;
  float TwoJet_SubLeadFatJet_particleNet_WvsQCD = -999.0;
  float TwoJet_SubLeadFatJet_particleNet_ZvsQCD = -999.0;
  float TwoJet_SubLeadFatJet_phi = -999.0;
  float TwoJet_SubLeadFatJet_pt = -999.0;
  float TwoJet_SubLeadFatJet_rawFactor = -999.0;
  float TwoJet_SubLeadFatJet_subJetIdx1 = -999.0;
  float TwoJet_SubLeadFatJet_subJetIdx2 = -999.0;
  float TwoJet_SubLeadFatJet_tau1 = -999.0;
  float TwoJet_SubLeadFatJet_tau2 = -999.0;
  float TwoJet_SubLeadFatJet_tau3 = -999.0;
  float TwoJet_SubLeadFatJet_tau4 = -999.0;
  float TwoJet_HWW_pt = -999.0;
  float TwoJet_HWW_eta = -999.0;
  float TwoJet_HWW_phi = -999.0;
  float TwoJet_HWW_m = -999.0;
  float TwoJet_HWW_E = -999.0;
  float TwoJet_Radion_p = -999.0;
  float TwoJet_Radion_pt = -999.0;
  float TwoJet_Radion_pz = -999.0;
  float TwoJet_Radion_eta = -999.0;
  float TwoJet_Radion_phi = -999.0;
  float TwoJet_Radion_m = -999.0;
  float TwoJet_Radion_E = -999.0;

  float ThreeJet_FatJet_area = -999.0;
  float ThreeJet_FatJet_btagCMVA = -999.0;
  float ThreeJet_FatJet_btagCSVV2 = -999.0;
  float ThreeJet_FatJet_btagDDBvL = -999.0;
  float ThreeJet_FatJet_btagDDBvL_noMD = -999.0;
  float ThreeJet_FatJet_btagDDCvB = -999.0;
  float ThreeJet_FatJet_btagDDCvB_noMD = -999.0;
  float ThreeJet_FatJet_btagDDCvL = -999.0;
  float ThreeJet_FatJet_btagDDCvL_noMD = -999.0;
  float ThreeJet_FatJet_btagDeepB = -999.0;
  float ThreeJet_FatJet_btagHbb = -999.0;
  float ThreeJet_FatJet_deepTagMD_H4qvsQCD = -999.0;
  float ThreeJet_FatJet_deepTagMD_HbbvsQCD = -999.0;
  float ThreeJet_FatJet_deepTagMD_TvsQCD = -999.0;
  float ThreeJet_FatJet_deepTagMD_WvsQCD = -999.0;
  float ThreeJet_FatJet_deepTagMD_ZHbbvsQCD = -999.0;
  float ThreeJet_FatJet_deepTagMD_ZHccvsQCD = -999.0;
  float ThreeJet_FatJet_deepTagMD_ZbbvsQCD = -999.0;
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
  float ThreeJet_FatJet_nCHadrons = -999.0;
  float ThreeJet_FatJet_particleNetMD_QCD = -999.0;
  float ThreeJet_FatJet_particleNetMD_Xbb = -999.0;
  float ThreeJet_FatJet_particleNetMD_Xcc = -999.0;
  float ThreeJet_FatJet_particleNetMD_Xqq = -999.0;
  float ThreeJet_FatJet_particleNet_H4qvsQCD = -999.0;
  float ThreeJet_FatJet_particleNet_HbbvsQCD = -999.0;
  float ThreeJet_FatJet_particleNet_HccvsQCD = -999.0;
  float ThreeJet_FatJet_particleNet_QCD = -999.0;
  float ThreeJet_FatJet_particleNet_TvsQCD = -999.0;
  float ThreeJet_FatJet_particleNet_WvsQCD = -999.0;
  float ThreeJet_FatJet_particleNet_ZvsQCD = -999.0;
  float ThreeJet_FatJet_phi = -999.0;
  float ThreeJet_FatJet_pt = -999.0;
  float ThreeJet_FatJet_rawFactor = -999.0;
  float ThreeJet_FatJet_subJetIdx1 = -999.0;
  float ThreeJet_FatJet_subJetIdx2 = -999.0;
  float ThreeJet_FatJet_tau1 = -999.0;
  float ThreeJet_FatJet_tau2 = -999.0;
  float ThreeJet_FatJet_tau3 = -999.0;
  float ThreeJet_FatJet_tau4 = -999.0;
  float ThreeJet_nFatJet = -999.0;
  float ThreeJet_nAK4Jet = -999.0;
  float ThreeJet_LeadingAK4_pT = -999.0;
  float ThreeJet_LeadingAK4_eta = -999.0;
  float ThreeJet_LeadingAK4_phi = -999.0;
  float ThreeJet_LeadingAK4_mass = -999.0;
  float ThreeJet_SubLeadingAK4_pT = -999.0;
  float ThreeJet_SubLeadingAK4_eta = -999.0;
  float ThreeJet_SubLeadingAK4_phi = -999.0;
  float ThreeJet_SubLeadingAK4_mass = -999.0;
  float ThreeJet_AK4WBoson_pt = -999.0;
  float ThreeJet_AK4WBoson_eta = -999.0;
  float ThreeJet_AK4WBoson_phi = -999.0;
  float ThreeJet_AK4WBoson_m = -999.0;
  float ThreeJet_AK4WBoson_E = -999.0;
  float ThreeJet_Radion_p = -999.0;
  float ThreeJet_Radion_pt = -999.0;
  float ThreeJet_Radion_pz = -999.0;
  float ThreeJet_Radion_eta = -999.0;
  float ThreeJet_Radion_phi = -999.0;
  float ThreeJet_Radion_m = -999.0;
  float ThreeJet_Radion_E = -999.0;

  float ThreeJet_Higgs_pt = -999.0;
  float ThreeJet_Higgs_eta = -999.0;
  float ThreeJet_Higgs_phi = -999.0;
  float ThreeJet_Higgs_m = -999.0;
  float ThreeJet_Higgs_E = -999.0;
  //------------------------------------//
  //       AK4 Jets                     //
  //------------------------------------//

  float FullyResolved_allAK4JetsSum_pt = -999.0;
  float FullyResolved_Jet1_pt = -999.0;
  float FullyResolved_Jet2_pt = -999.0;
  float FullyResolved_Jet3_pt = -999.0;
  float FullyResolved_Jet4_pt = -999.0;

  float FullyResolved_Jet1_eta = -999.0;
  float FullyResolved_Jet2_eta = -999.0;
  float FullyResolved_Jet3_eta = -999.0;
  float FullyResolved_Jet4_eta = -999.0;

  float FullyResolved_Jet1_phi = -999.0;
  float FullyResolved_Jet2_phi = -999.0;
  float FullyResolved_Jet3_phi = -999.0;
  float FullyResolved_Jet4_phi = -999.0;

  float FullyResolved_Jet1_E = -999.0;
  float FullyResolved_Jet2_E = -999.0;
  float FullyResolved_Jet3_E = -999.0;
  float FullyResolved_Jet4_E = -999.0;

  float FullyResolved_Jet1_M = -999.0;
  float FullyResolved_Jet2_M = -999.0;
  float FullyResolved_Jet3_M = -999.0;
  float FullyResolved_Jet4_M = -999.0;

  float FullyResolved_TwoLeadingJets_pt = -999.0;
  float FullyResolved_TwoLeadingJets_eta = -999.0;
  float FullyResolved_TwoLeadingJets_phi = -999.0;
  float FullyResolved_TwoLeadingJets_m = -999.0;
  float FullyResolved_TwoLeadingJets_E = -999.0;

  float FullyResolved_ThirdFourthJets_pt = -999.0;
  float FullyResolved_ThirdFourthJets_eta = -999.0;
  float FullyResolved_ThirdFourthJets_phi = -999.0;
  float FullyResolved_ThirdFourthJets_m = -999.0;
  float FullyResolved_ThirdFourthJets_E = -999.0;

  float FullyResolved_FourJets_pt = -999.0;
  float FullyResolved_FourJets_eta = -999.0;
  float FullyResolved_FourJets_phi = -999.0;
  float FullyResolved_FourJets_m = -999.0;
  float FullyResolved_FourJets_E = -999.0;

  float FullyResolved_Radion_p = -999.0;
  float FullyResolved_Radion_pt = -999.0;
  float FullyResolved_Radion_pz = -999.0;
  float FullyResolved_Radion_eta  = -999.0;
  float FullyResolved_Radion_phi  = -999.0;
  float FullyResolved_Radion_m  = -999.0;
  float FullyResolved_Radion_E  = -999.0;

  float GEN_deltaR_HH = -999.0;
  float GEN_deltaEta_HH = -999.0;
  float GEN_deltaPhi_HH = -999.0;

  float OneJet_deltaR_HH = -999.0;
  float OneJet_deltaEta_HH = -999.0;
  float OneJet_deltaPhi_HH = -999.0;
  float TwoJet_deltaR_HH = -999.0;
  float TwoJet_deltaEta_HH = -999.0;
  float TwoJet_deltaPhi_HH = -999.0;
  float ThreeJet_deltaR_HH = -999.0;
  float ThreeJet_deltaR_WW = -999.0;
  float ThreeJet_deltaEta_HH = -999.0;
  float ThreeJet_deltaPhi_HH = -999.0;
  float FullyResolved_deltaR_HH = -999.0;
  float FullyResolved_deltaEta_HH = -999.0;
  float FullyResolved_deltaPhi_HH = -999.0;

};

#endif
