#include "DoubleHiggs/Selection/interface/output.hh"

void output::init() {

  clearVars();

  fTree->Branch("nTagJets",&nTagJets,"nTagJets/F");
  fTree->Branch("allFullyResolved_AK4JetsSum_pt",&allFullyResolved_AK4JetsSum_pt,"allFullyResolved_AK4JetsSum_pt/F");
  fTree->Branch("allOneJet_AK8JetsSum_pt",&allOneJet_AK8JetsSum_pt,"allOneJet_AK8JetsSum_pt/F");
  fTree->Branch("allThreeJet_AK4JetsSum_pt",&allThreeJet_AK4JetsSum_pt,"allThreeJet_AK4JetsSum_pt/F");
  fTree->Branch("nOneJet_GoodFatJet",&nOneJet_GoodFatJet,"nOneJet_GoodFatJet/I");
  fTree->Branch("nGoodThreeJet_FatJet",&nGoodThreeJet_FatJet,"nGoodThreeJet_FatJet/I");
  fTree->Branch("nGoodThreeJet_Ak4Jet",&nGoodThreeJet_Ak4Jet,"nGoodThreeJet_Ak4Jet/I");
/* -------------------------------------------------------------------------- */
/*                                   One Jet                                  */
/* -------------------------------------------------------------------------- */
fTree->Branch("	OneJet_FatJet_area",&OneJet_FatJet_area,"OneJet_FatJet_area/F");
fTree->Branch("OneJet_FatJet_btagCMVA",&OneJet_FatJet_btagCMVA,"OneJet_FatJet_btagCMVA/F");
fTree->Branch("OneJet_FatJet_btagCSVV2",&OneJet_FatJet_btagCSVV2,"OneJet_FatJet_btagCSVV2/F");
fTree->Branch("OneJet_FatJet_btagDDBvL",&OneJet_FatJet_btagDDBvL,"OneJet_FatJet_btagDDBvL/F");
fTree->Branch("OneJet_FatJet_btagDDBvL_noMD",&OneJet_FatJet_btagDDBvL_noMD,"OneJet_FatJet_btagDDBvL_noMD/F");
fTree->Branch("OneJet_FatJet_btagDDCvB",&OneJet_FatJet_btagDDCvB,"OneJet_FatJet_btagDDCvB/F");
fTree->Branch("OneJet_FatJet_btagDDCvB_noMD",&OneJet_FatJet_btagDDCvB_noMD,"OneJet_FatJet_btagDDCvB_noMD/F");
fTree->Branch("OneJet_FatJet_btagDDCvL",&OneJet_FatJet_btagDDCvL,"OneJet_FatJet_btagDDCvL/F");
fTree->Branch("OneJet_FatJet_btagDDCvL_noMD",&OneJet_FatJet_btagDDCvL_noMD,"OneJet_FatJet_btagDDCvL_noMD/F");
fTree->Branch("OneJet_FatJet_btagDeepB",&OneJet_FatJet_btagDeepB,"OneJet_FatJet_btagDeepB/F");
fTree->Branch("OneJet_FatJet_btagHbb",&OneJet_FatJet_btagHbb,"OneJet_FatJet_btagHbb/F");
fTree->Branch("OneJet_FatJet_deepTagMD_H4qvsQCD",&OneJet_FatJet_deepTagMD_H4qvsQCD,"OneJet_FatJet_deepTagMD_H4qvsQCD/F");
fTree->Branch("OneJet_FatJet_deepTagMD_HbbvsQCD",&OneJet_FatJet_deepTagMD_HbbvsQCD,"OneJet_FatJet_deepTagMD_HbbvsQCD/F");
fTree->Branch("OneJet_FatJet_deepTagMD_TvsQCD",&OneJet_FatJet_deepTagMD_TvsQCD,"OneJet_FatJet_deepTagMD_TvsQCD/F");
fTree->Branch("OneJet_FatJet_deepTagMD_WvsQCD",&OneJet_FatJet_deepTagMD_WvsQCD,"OneJet_FatJet_deepTagMD_WvsQCD/F");
fTree->Branch("OneJet_FatJet_deepTagMD_ZHbbvsQCD",&OneJet_FatJet_deepTagMD_ZHbbvsQCD,"OneJet_FatJet_deepTagMD_ZHbbvsQCD/F");
fTree->Branch("OneJet_FatJet_deepTagMD_ZHccvsQCD",&OneJet_FatJet_deepTagMD_ZHccvsQCD,"OneJet_FatJet_deepTagMD_ZHccvsQCD/F");
fTree->Branch("OneJet_FatJet_deepTagMD_ZbbvsQCD",&OneJet_FatJet_deepTagMD_ZbbvsQCD,"OneJet_FatJet_deepTagMD_ZbbvsQCD/F");
fTree->Branch("OneJet_FatJet_deepTagMD_ZvsQCD",&OneJet_FatJet_deepTagMD_ZvsQCD,"OneJet_FatJet_deepTagMD_ZvsQCD/F");
fTree->Branch("OneJet_FatJet_deepTagMD_bbvsLight",&OneJet_FatJet_deepTagMD_bbvsLight,"OneJet_FatJet_deepTagMD_bbvsLight/F");
fTree->Branch("OneJet_FatJet_deepTagMD_ccvsLight",&OneJet_FatJet_deepTagMD_ccvsLight,"OneJet_FatJet_deepTagMD_ccvsLight/F");
fTree->Branch("OneJet_FatJet_deepTag_H",&OneJet_FatJet_deepTag_H,"OneJet_FatJet_deepTag_H/F");
fTree->Branch("OneJet_FatJet_deepTag_QCD",&OneJet_FatJet_deepTag_QCD,"OneJet_FatJet_deepTag_QCD/F");
fTree->Branch("OneJet_FatJet_deepTag_QCDothers",&OneJet_FatJet_deepTag_QCDothers,"OneJet_FatJet_deepTag_QCDothers/F");
fTree->Branch("OneJet_FatJet_deepTag_TvsQCD",&OneJet_FatJet_deepTag_TvsQCD,"OneJet_FatJet_deepTag_TvsQCD/F");
fTree->Branch("OneJet_FatJet_deepTag_WvsQCD",&OneJet_FatJet_deepTag_WvsQCD,"OneJet_FatJet_deepTag_WvsQCD/F");
fTree->Branch("OneJet_FatJet_deepTag_ZvsQCD",&OneJet_FatJet_deepTag_ZvsQCD,"OneJet_FatJet_deepTag_ZvsQCD/F");
fTree->Branch("OneJet_FatJet_electronIdx3SJ",&OneJet_FatJet_electronIdx3SJ,"OneJet_FatJet_electronIdx3SJ/F");
fTree->Branch("OneJet_FatJet_eta",&OneJet_FatJet_eta,"OneJet_FatJet_eta/F");
fTree->Branch("OneJet_FatJet_genJetAK8Idx",&OneJet_FatJet_genJetAK8Idx,"OneJet_FatJet_genJetAK8Idx/F");
fTree->Branch("OneJet_FatJet_hadronFlavour",&OneJet_FatJet_hadronFlavour,"OneJet_FatJet_hadronFlavour/F");
fTree->Branch("OneJet_FatJet_jetId",&OneJet_FatJet_jetId,"OneJet_FatJet_jetId/F");
fTree->Branch("OneJet_FatJet_lsf3",&OneJet_FatJet_lsf3,"OneJet_FatJet_lsf3/F");
fTree->Branch("OneJet_FatJet_mass",&OneJet_FatJet_mass,"OneJet_FatJet_mass/F");
fTree->Branch("OneJet_FatJet_msoftdrop",&OneJet_FatJet_msoftdrop,"OneJet_FatJet_msoftdrop/F");
fTree->Branch("OneJet_FatJet_muonIdx3SJ",&OneJet_FatJet_muonIdx3SJ,"OneJet_FatJet_muonIdx3SJ/F");
fTree->Branch("OneJet_FatJet_n2b1",&OneJet_FatJet_n2b1,"OneJet_FatJet_n2b1/F");
fTree->Branch("OneJet_FatJet_n3b1",&OneJet_FatJet_n3b1,"OneJet_FatJet_n3b1/F");
// fTree->Branch("OneJet_FatJet_particleNetMD_QCD",&OneJet_FatJet_particleNetMD_QCD,"OneJet_FatJet_particleNetMD_QCD/F");
// fTree->Branch("OneJet_FatJet_particleNetMD_Xbb",&OneJet_FatJet_particleNetMD_Xbb,"OneJet_FatJet_particleNetMD_Xbb/F");
// fTree->Branch("OneJet_FatJet_particleNetMD_Xcc",&OneJet_FatJet_particleNetMD_Xcc,"OneJet_FatJet_particleNetMD_Xcc/F");
// fTree->Branch("OneJet_FatJet_particleNetMD_Xqq",&OneJet_FatJet_particleNetMD_Xqq,"OneJet_FatJet_particleNetMD_Xqq/F");
// fTree->Branch("OneJet_FatJet_particleNet_H4qvsQCD",&OneJet_FatJet_particleNet_H4qvsQCD,"OneJet_FatJet_particleNet_H4qvsQCD/F");
// fTree->Branch("OneJet_FatJet_particleNet_HbbvsQCD",&OneJet_FatJet_particleNet_HbbvsQCD,"OneJet_FatJet_particleNet_HbbvsQCD/F");
// fTree->Branch("OneJet_FatJet_particleNet_HccvsQCD",&OneJet_FatJet_particleNet_HccvsQCD,"OneJet_FatJet_particleNet_HccvsQCD/F");
// fTree->Branch("OneJet_FatJet_particleNet_QCD",&OneJet_FatJet_particleNet_QCD,"OneJet_FatJet_particleNet_QCD/F");
// fTree->Branch("OneJet_FatJet_particleNet_TvsQCD",&OneJet_FatJet_particleNet_TvsQCD,"OneJet_FatJet_particleNet_TvsQCD/F");
// fTree->Branch("OneJet_FatJet_particleNet_WvsQCD",&OneJet_FatJet_particleNet_WvsQCD,"OneJet_FatJet_particleNet_WvsQCD/F");
// fTree->Branch("OneJet_FatJet_particleNet_ZvsQCD",&OneJet_FatJet_particleNet_ZvsQCD,"OneJet_FatJet_particleNet_ZvsQCD/F");
fTree->Branch("OneJet_FatJet_phi",&OneJet_FatJet_phi,"OneJet_FatJet_phi/F");
fTree->Branch("OneJet_FatJet_pt",&OneJet_FatJet_pt,"OneJet_FatJet_pt/F");
fTree->Branch("OneJet_FatJet_rawFactor",&OneJet_FatJet_rawFactor,"OneJet_FatJet_rawFactor/F");
fTree->Branch("OneJet_FatJet_subJetIdx1",&OneJet_FatJet_subJetIdx1,"OneJet_FatJet_subJetIdx1/F");
fTree->Branch("OneJet_FatJet_subJetIdx2",&OneJet_FatJet_subJetIdx2,"OneJet_FatJet_subJetIdx2/F");
fTree->Branch("OneJet_FatJet_tau1",&OneJet_FatJet_tau1,"OneJet_FatJet_tau1/F");
fTree->Branch("OneJet_FatJet_tau2",&OneJet_FatJet_tau2,"OneJet_FatJet_tau2/F");
fTree->Branch("OneJet_FatJet_tau3",&OneJet_FatJet_tau3,"OneJet_FatJet_tau3/F");
fTree->Branch("OneJet_FatJet_tau4",&OneJet_FatJet_tau4,"OneJet_FatJet_tau4/F");
fTree->Branch("OneJet_nFatJet",&OneJet_nFatJet,"OneJet_nFatJet/F");

/* -------------------------------------------------------------------------- */
/*                                 Three Jets                                 */
/* -------------------------------------------------------------------------- */
fTree->Branch("ThreeJet_FatJet_area",&ThreeJet_FatJet_area,"ThreeJet_FatJet_area/F");
fTree->Branch("ThreeJet_FatJet_btagCMVA",&ThreeJet_FatJet_btagCMVA,"ThreeJet_FatJet_btagCMVA/F");
fTree->Branch("ThreeJet_FatJet_btagCSVV2",&ThreeJet_FatJet_btagCSVV2,"ThreeJet_FatJet_btagCSVV2/F");
fTree->Branch("ThreeJet_FatJet_btagDDBvL",&ThreeJet_FatJet_btagDDBvL,"ThreeJet_FatJet_btagDDBvL/F");
fTree->Branch("ThreeJet_FatJet_btagDDBvL_noMD",&ThreeJet_FatJet_btagDDBvL_noMD,"ThreeJet_FatJet_btagDDBvL_noMD/F");
fTree->Branch("ThreeJet_FatJet_btagDDCvB",&ThreeJet_FatJet_btagDDCvB,"ThreeJet_FatJet_btagDDCvB/F");
fTree->Branch("ThreeJet_FatJet_btagDDCvB_noMD",&ThreeJet_FatJet_btagDDCvB_noMD,"ThreeJet_FatJet_btagDDCvB_noMD/F");
fTree->Branch("ThreeJet_FatJet_btagDDCvL",&ThreeJet_FatJet_btagDDCvL,"ThreeJet_FatJet_btagDDCvL/F");
fTree->Branch("ThreeJet_FatJet_btagDDCvL_noMD",&ThreeJet_FatJet_btagDDCvL_noMD,"ThreeJet_FatJet_btagDDCvL_noMD/F");
fTree->Branch("ThreeJet_FatJet_btagDeepB",&ThreeJet_FatJet_btagDeepB,"ThreeJet_FatJet_btagDeepB/F");
fTree->Branch("ThreeJet_FatJet_btagHbb",&ThreeJet_FatJet_btagHbb,"ThreeJet_FatJet_btagHbb/F");
fTree->Branch("ThreeJet_FatJet_deepTagMD_H4qvsQCD",&ThreeJet_FatJet_deepTagMD_H4qvsQCD,"ThreeJet_FatJet_deepTagMD_H4qvsQCD/F");
fTree->Branch("ThreeJet_FatJet_deepTagMD_HbbvsQCD",&ThreeJet_FatJet_deepTagMD_HbbvsQCD,"ThreeJet_FatJet_deepTagMD_HbbvsQCD/F");
fTree->Branch("ThreeJet_FatJet_deepTagMD_TvsQCD",&ThreeJet_FatJet_deepTagMD_TvsQCD,"ThreeJet_FatJet_deepTagMD_TvsQCD/F");
fTree->Branch("ThreeJet_FatJet_deepTagMD_WvsQCD",&ThreeJet_FatJet_deepTagMD_WvsQCD,"ThreeJet_FatJet_deepTagMD_WvsQCD/F");
fTree->Branch("ThreeJet_FatJet_deepTagMD_ZHbbvsQCD",&ThreeJet_FatJet_deepTagMD_ZHbbvsQCD,"ThreeJet_FatJet_deepTagMD_ZHbbvsQCD/F");
fTree->Branch("ThreeJet_FatJet_deepTagMD_ZHccvsQCD",&ThreeJet_FatJet_deepTagMD_ZHccvsQCD,"ThreeJet_FatJet_deepTagMD_ZHccvsQCD/F");
fTree->Branch("ThreeJet_FatJet_deepTagMD_ZbbvsQCD",&ThreeJet_FatJet_deepTagMD_ZbbvsQCD,"ThreeJet_FatJet_deepTagMD_ZbbvsQCD/F");
fTree->Branch("ThreeJet_FatJet_deepTagMD_ZvsQCD",&ThreeJet_FatJet_deepTagMD_ZvsQCD,"ThreeJet_FatJet_deepTagMD_ZvsQCD/F");
fTree->Branch("ThreeJet_FatJet_deepTagMD_bbvsLight",&ThreeJet_FatJet_deepTagMD_bbvsLight,"ThreeJet_FatJet_deepTagMD_bbvsLight/F");
fTree->Branch("ThreeJet_FatJet_deepTagMD_ccvsLight",&ThreeJet_FatJet_deepTagMD_ccvsLight,"ThreeJet_FatJet_deepTagMD_ccvsLight/F");
fTree->Branch("ThreeJet_FatJet_deepTag_H",&ThreeJet_FatJet_deepTag_H,"ThreeJet_FatJet_deepTag_H/F");
fTree->Branch("ThreeJet_FatJet_deepTag_QCD",&ThreeJet_FatJet_deepTag_QCD,"ThreeJet_FatJet_deepTag_QCD/F");
fTree->Branch("ThreeJet_FatJet_deepTag_QCDothers",&ThreeJet_FatJet_deepTag_QCDothers,"ThreeJet_FatJet_deepTag_QCDothers/F");
fTree->Branch("ThreeJet_FatJet_deepTag_TvsQCD",&ThreeJet_FatJet_deepTag_TvsQCD,"ThreeJet_FatJet_deepTag_TvsQCD/F");
fTree->Branch("ThreeJet_FatJet_deepTag_WvsQCD",&ThreeJet_FatJet_deepTag_WvsQCD,"ThreeJet_FatJet_deepTag_WvsQCD/F");
fTree->Branch("ThreeJet_FatJet_deepTag_ZvsQCD",&ThreeJet_FatJet_deepTag_ZvsQCD,"ThreeJet_FatJet_deepTag_ZvsQCD/F");
fTree->Branch("ThreeJet_FatJet_electronIdx3SJ",&ThreeJet_FatJet_electronIdx3SJ,"ThreeJet_FatJet_electronIdx3SJ/F");
fTree->Branch("ThreeJet_FatJet_eta",&ThreeJet_FatJet_eta,"ThreeJet_FatJet_eta/F");
fTree->Branch("ThreeJet_FatJet_genJetAK8Idx",&ThreeJet_FatJet_genJetAK8Idx,"ThreeJet_FatJet_genJetAK8Idx/F");
fTree->Branch("ThreeJet_FatJet_hadronFlavour",&ThreeJet_FatJet_hadronFlavour,"ThreeJet_FatJet_hadronFlavour/F");
fTree->Branch("ThreeJet_FatJet_jetId",&ThreeJet_FatJet_jetId,"ThreeJet_FatJet_jetId/F");
fTree->Branch("ThreeJet_FatJet_lsf3",&ThreeJet_FatJet_lsf3,"ThreeJet_FatJet_lsf3/F");
fTree->Branch("ThreeJet_FatJet_mass",&ThreeJet_FatJet_mass,"ThreeJet_FatJet_mass/F");
fTree->Branch("ThreeJet_FatJet_msoftdrop",&ThreeJet_FatJet_msoftdrop,"ThreeJet_FatJet_msoftdrop/F");
fTree->Branch("ThreeJet_FatJet_muonIdx3SJ",&ThreeJet_FatJet_muonIdx3SJ,"ThreeJet_FatJet_muonIdx3SJ/F");
fTree->Branch("ThreeJet_FatJet_n2b1",&ThreeJet_FatJet_n2b1,"ThreeJet_FatJet_n2b1/F");
fTree->Branch("ThreeJet_FatJet_n3b1",&ThreeJet_FatJet_n3b1,"ThreeJet_FatJet_n3b1/F");
fTree->Branch("ThreeJet_FatJet_nCHadrons",&ThreeJet_FatJet_nCHadrons,"ThreeJet_FatJet_nCHadrons/F");
// fTree->Branch("ThreeJet_FatJet_particleNetMD_QCD",&ThreeJet_FatJet_particleNetMD_QCD,"ThreeJet_FatJet_particleNetMD_QCD/F");
// fTree->Branch("ThreeJet_FatJet_particleNetMD_Xbb",&ThreeJet_FatJet_particleNetMD_Xbb,"ThreeJet_FatJet_particleNetMD_Xbb/F");
// fTree->Branch("ThreeJet_FatJet_particleNetMD_Xcc",&ThreeJet_FatJet_particleNetMD_Xcc,"ThreeJet_FatJet_particleNetMD_Xcc/F");
// fTree->Branch("ThreeJet_FatJet_particleNetMD_Xqq",&ThreeJet_FatJet_particleNetMD_Xqq,"ThreeJet_FatJet_particleNetMD_Xqq/F");
// fTree->Branch("ThreeJet_FatJet_particleNet_H4qvsQCD",&ThreeJet_FatJet_particleNet_H4qvsQCD,"ThreeJet_FatJet_particleNet_H4qvsQCD/F");
// fTree->Branch("ThreeJet_FatJet_particleNet_HbbvsQCD",&ThreeJet_FatJet_particleNet_HbbvsQCD,"ThreeJet_FatJet_particleNet_HbbvsQCD/F");
// fTree->Branch("ThreeJet_FatJet_particleNet_HccvsQCD",&ThreeJet_FatJet_particleNet_HccvsQCD,"ThreeJet_FatJet_particleNet_HccvsQCD/F");
// fTree->Branch("ThreeJet_FatJet_particleNet_QCD",&ThreeJet_FatJet_particleNet_QCD,"ThreeJet_FatJet_particleNet_QCD/F");
// fTree->Branch("ThreeJet_FatJet_particleNet_TvsQCD",&ThreeJet_FatJet_particleNet_TvsQCD,"ThreeJet_FatJet_particleNet_TvsQCD/F");
// fTree->Branch("ThreeJet_FatJet_particleNet_WvsQCD",&ThreeJet_FatJet_particleNet_WvsQCD,"ThreeJet_FatJet_particleNet_WvsQCD/F");
// fTree->Branch("ThreeJet_FatJet_particleNet_ZvsQCD",&ThreeJet_FatJet_particleNet_ZvsQCD,"ThreeJet_FatJet_particleNet_ZvsQCD/F");
fTree->Branch("ThreeJet_FatJet_phi",&ThreeJet_FatJet_phi,"ThreeJet_FatJet_phi/F");
fTree->Branch("ThreeJet_FatJet_pt",&ThreeJet_FatJet_pt,"ThreeJet_FatJet_pt/F");
fTree->Branch("ThreeJet_FatJet_rawFactor",&ThreeJet_FatJet_rawFactor,"ThreeJet_FatJet_rawFactor/F");
fTree->Branch("ThreeJet_FatJet_subJetIdx1",&ThreeJet_FatJet_subJetIdx1,"ThreeJet_FatJet_subJetIdx1/F");
fTree->Branch("ThreeJet_FatJet_subJetIdx2",&ThreeJet_FatJet_subJetIdx2,"ThreeJet_FatJet_subJetIdx2/F");
fTree->Branch("ThreeJet_FatJet_tau1",&ThreeJet_FatJet_tau1,"ThreeJet_FatJet_tau1/F");
fTree->Branch("ThreeJet_FatJet_tau2",&ThreeJet_FatJet_tau2,"ThreeJet_FatJet_tau2/F");
fTree->Branch("ThreeJet_FatJet_tau3",&ThreeJet_FatJet_tau3,"ThreeJet_FatJet_tau3/F");
fTree->Branch("ThreeJet_FatJet_tau4",&ThreeJet_FatJet_tau4,"ThreeJet_FatJet_tau4/F");
fTree->Branch("ThreeJet_nFatJet",&ThreeJet_nFatJet,"ThreeJet_nFatJet/F");
fTree->Branch("ThreeJetAk4_jet2_pt",&ThreeJetAk4_jet2_pt,"ThreeJetAk4_jet2_pt/F");
fTree->Branch("ThreeJetAk4_jet1_eta",&ThreeJetAk4_jet1_eta,"ThreeJetAk4_jet1_eta/F");
fTree->Branch("ThreeJetAk4_jet2_eta",&ThreeJetAk4_jet2_eta,"ThreeJetAk4_jet2_eta/F");
fTree->Branch("ThreeJetAk4_jet1_phi",&ThreeJetAk4_jet1_phi,"ThreeJetAk4_jet1_phi/F");
fTree->Branch("ThreeJetAk4_jet2_phi",&ThreeJetAk4_jet2_phi,"ThreeJetAk4_jet2_phi/F");
fTree->Branch("ThreeJetAk4_jet1_M",&ThreeJetAk4_jet1_M,"ThreeJetAk4_jet1_M/F");
fTree->Branch("ThreeJetAk4_jet2_M",&ThreeJetAk4_jet2_M,"ThreeJetAk4_jet2_M/F");


  fTree->Branch("FullyResolved_jet1_pt",&FullyResolved_jet1_pt,"FullyResolved_jet1_pt/F");
  fTree->Branch("FullyResolved_jet2_pt",&FullyResolved_jet2_pt,"FullyResolved_jet2_pt/F");
  fTree->Branch("FullyResolved_jet3_pt",&FullyResolved_jet3_pt,"FullyResolved_jet3_pt/F");
  fTree->Branch("FullyResolved_jet4_pt",&FullyResolved_jet4_pt,"FullyResolved_jet4_pt/F");

  fTree->Branch("FullyResolved_jet1_eta",&FullyResolved_jet1_eta,"FullyResolved_jet1_eta/F");
  fTree->Branch("FullyResolved_jet2_eta",&FullyResolved_jet2_eta,"FullyResolved_jet2_eta/F");
  fTree->Branch("FullyResolved_jet3_eta",&FullyResolved_jet3_eta,"FullyResolved_jet3_eta/F");
  fTree->Branch("FullyResolved_jet4_eta",&FullyResolved_jet4_eta,"FullyResolved_jet4_eta/F");

  fTree->Branch("FullyResolved_jet1_phi",&FullyResolved_jet1_phi,"FullyResolved_jet1_phi/F");
  fTree->Branch("FullyResolved_jet2_phi",&FullyResolved_jet2_phi,"FullyResolved_jet2_phi/F");
  fTree->Branch("FullyResolved_jet3_phi",&FullyResolved_jet3_phi,"FullyResolved_jet3_phi/F");
  fTree->Branch("FullyResolved_jet4_phi",&FullyResolved_jet4_phi,"FullyResolved_jet4_phi/F");

  fTree->Branch("FullyResolved_jet1_E",&FullyResolved_jet1_E,"FullyResolved_jet1_E/F");
  fTree->Branch("FullyResolved_jet2_E",&FullyResolved_jet2_E,"FullyResolved_jet2_E/F");
  fTree->Branch("FullyResolved_jet3_E",&FullyResolved_jet3_E,"FullyResolved_jet3_E/F");
  fTree->Branch("FullyResolved_jet4_E",&FullyResolved_jet4_E,"FullyResolved_jet4_E/F");
  
  fTree->Branch("FullyResolved_jet1_M",&FullyResolved_jet1_M,"FullyResolved_jet1_M/F");
  fTree->Branch("FullyResolved_jet2_M",&FullyResolved_jet2_M,"FullyResolved_jet2_M/F");
  fTree->Branch("FullyResolved_jet3_M",&FullyResolved_jet3_M,"FullyResolved_jet3_M/F");
  fTree->Branch("FullyResolved_jet4_M",&FullyResolved_jet4_M,"FullyResolved_jet4_M/F");
  
  fTree->Branch("FullyResolvedTwoLeadingJets_pt",&FullyResolvedTwoLeadingJets_pt,"FullyResolvedTwoLeadingJets_pt/F");
  fTree->Branch("FullyResolvedTwoLeadingJets_eta",&FullyResolvedTwoLeadingJets_eta,"FullyResolvedTwoLeadingJets_eta/F");
  fTree->Branch("FullyResolvedTwoLeadingJets_phi",&FullyResolvedTwoLeadingJets_phi,"FullyResolvedTwoLeadingJets_phi/F");
  fTree->Branch("FullyResolvedTwoLeadingJets_m",&FullyResolvedTwoLeadingJets_m,"FullyResolvedTwoLeadingJets_m/F");
  fTree->Branch("FullyResolvedTwoLeadingJets_E",&FullyResolvedTwoLeadingJets_E,"FullyResolvedTwoLeadingJets_E/F");
  
  fTree->Branch("FullyResolvedThirdFourthJets_pt",&FullyResolvedThirdFourthJets_pt,"FullyResolvedThirdFourthJets_pt/F");
  fTree->Branch("FullyResolvedThirdFourthJets_eta",&FullyResolvedThirdFourthJets_eta,"FullyResolvedThirdFourthJets_eta/F");
  fTree->Branch("FullyResolvedThirdFourthJets_phi",&FullyResolvedThirdFourthJets_phi,"FullyResolvedThirdFourthJets_phi/F");
  fTree->Branch("FullyResolvedThirdFourthJets_m",&FullyResolvedThirdFourthJets_m,"FullyResolvedThirdFourthJets_m/F");
  fTree->Branch("FullyResolvedThirdFourthJets_E",&FullyResolvedThirdFourthJets_E,"FullyResolvedThirdFourthJets_E/F");
  
  fTree->Branch("FullyResolvedFourJets_pt",&FullyResolvedFourJets_pt,"FullyResolvedFourJets_pt/F");
  fTree->Branch("FullyResolvedFourJets_eta",&FullyResolvedFourJets_eta,"FullyResolvedFourJets_eta/F");
  fTree->Branch("FullyResolvedFourJets_phi",&FullyResolvedFourJets_phi,"FullyResolvedFourJets_phi/F");
  fTree->Branch("FullyResolvedFourJets_m",&FullyResolvedFourJets_m,"FullyResolvedFourJets_m/F");
  fTree->Branch("FullyResolvedFourJets_E",&FullyResolvedFourJets_E,"FullyResolvedFourJets_E/F");

  fTree->Branch("ThreeJetTwoLeadingJets_pt",&ThreeJetTwoLeadingJets_pt,"ThreeJetTwoLeadingJets_pt/F");
  fTree->Branch("ThreeJetTwoLeadingJets_eta",&ThreeJetTwoLeadingJets_eta,"ThreeJetTwoLeadingJets_eta/F");
  fTree->Branch("ThreeJetTwoLeadingJets_phi",&ThreeJetTwoLeadingJets_phi,"ThreeJetTwoLeadingJets_phi/F");
  fTree->Branch("ThreeJetTwoLeadingJets_m",&ThreeJetTwoLeadingJets_m,"ThreeJetTwoLeadingJets_m/F");
  fTree->Branch("ThreeJetTwoLeadingJets_E",&ThreeJetTwoLeadingJets_E,"ThreeJetTwoLeadingJets_E/F");
  //metadata and weights
  fTree->Branch("run",&run,"run/I");
  fTree->Branch("ls",&ls,"ls/I");
  fTree->Branch("evt",&evt,"evt/I");
  // fTree->Branch("nPV",&nPV,"nPV/F");
  fTree->Branch("nPU_mean",&nPU_mean,"nPU_mean/F");
  fTree->Branch("genWeight",&genWeight,"genWeight/F");
  fTree->Branch("puWeight",&puWeight,"puWeight/F");
  fTree->Branch("puWeight_Up",&puWeight_Up,"puWeight_Up/F");
  fTree->Branch("puWeight_Dn",&puWeight_Dn,"puWeight_Dn/F");
  fTree->Branch("L1PFWeight",&L1PFWeight,"L1PFWeight/F");
  fTree->Branch("LHEWeight",&LHEWeight[0],"LHEWeight[1164]/F");
  fTree->Branch("nScaleWeight",&nScaleWeight,"nScaleWeight/I");
  fTree->Branch("nPdfWeight",&nPdfWeight,"nPdfWeight/I");
  fTree->Branch("scaleWeight",&scaleWeight[0],"scaleWeight[200]/F");
  fTree->Branch("pdfWeight",&pdfWeight[0],"pdfWeight[200]/F");
  //btag counters
  fTree->Branch("nBtag_loose",&nBtag_loose,"nBtag_loose/I");
  fTree->Branch("nBtag_medium",&nBtag_medium,"nBtag_medium/I");
  fTree->Branch("nBtag_tight",&nBtag_tight,"nBtag_tight/I");
  fTree->Branch("btagWeight",&btagWeight,"btagWeight/F");
  //trigger
  fTree->Branch("trigger_1Pho",&trigger_1Pho,"trigger_1Pho/O");
  fTree->Branch("trigger_2Pho",&trigger_2Pho,"trigger_2Pho/O");

  fTree->Branch("isAntiIso",&isAntiIso,"isAntiIso/O");
  //photon 1
  fTree->Branch("pho1_pt",&pho1_pt,"pho1_pt/F");
  fTree->Branch("pho1_eta",&pho1_eta,"pho1_eta/F");
  fTree->Branch("pho1_phi",&pho1_phi,"pho1_phi/F");
  fTree->Branch("pho1_m",&pho1_m,"pho1_m/F");
  fTree->Branch("pho1_q",&pho1_q,"pho1_q/F");
  fTree->Branch("pho1_iso",&pho1_iso,"pho1_iso/F");
  fTree->Branch("pho1_dxy",&pho1_dxy,"pho1_dxy/F");
  fTree->Branch("pho1_dz",&pho1_dz,"pho1_dz/F");
  fTree->Branch("pho1_E",&pho1_E,"pho1_E/F");
  fTree->Branch("pho1_pt_byMgg",&pho1_pt_byMgg,"pho1_pt_byMgg/F");
  fTree->Branch("pho1_E_byMgg",&pho1_E_byMgg,"pho1_E_byMgg/F");
  fTree->Branch("pho1_idEffWeight",&pho1_idEffWeight,"pho1_idEffWeight/F");
  //photon 1 scale variations
  fTree->Branch("pho1_pt_scaleUp",&pho1_pt_scaleUp,"pho1_pt_scaleUp/F");
  fTree->Branch("pho1_pt_scaleDn",&pho1_pt_scaleDn,"pho1_pt_scaleDn/F");
  //photon 2
  fTree->Branch("pho2_pt",&pho2_pt,"pho2_pt/F");
  fTree->Branch("pho2_eta",&pho2_eta,"pho2_eta/F");
  fTree->Branch("pho2_phi",&pho2_phi,"pho2_phi/F");
  fTree->Branch("pho2_m",&pho2_m,"pho2_m/F");
  fTree->Branch("pho2_q",&pho2_q,"pho2_q/F");
  fTree->Branch("pho2_iso",&pho2_iso,"pho2_iso/F");
  fTree->Branch("pho2_dxy",&pho2_dxy,"pho2_dxy/F");
  fTree->Branch("pho2_dz",&pho2_dz,"pho2_dz/F");
  fTree->Branch("pho2_E",&pho2_E,"pho2_E/F");
  fTree->Branch("pho2_pt_byMgg",&pho2_pt_byMgg,"pho2_pt_byMgg/F");
  fTree->Branch("pho2_E_byMgg",&pho2_E_byMgg,"pho2_E_byMgg/F");
  fTree->Branch("pho2_idEffWeight",&pho2_idEffWeight,"pho2_idEffWeight/F");
  //photon 2 scale variations
  fTree->Branch("pho2_pt_scaleUp",&pho2_pt_scaleUp,"pho2_pt_scaleUp/F");
  fTree->Branch("pho2_pt_scaleDn",&pho2_pt_scaleDn,"pho2_pt_scaleDn/F");
  //diphoton final state
  fTree->Branch("diphoton_m",&diphoton_m,"diphoton_m/F");
  fTree->Branch("diphoton_pt",&diphoton_pt,"diphoton_pt/F");
  fTree->Branch("diphoton_eta",&diphoton_eta,"diphoton_eta/F");
  fTree->Branch("diphoton_phi",&diphoton_phi,"diphoton_phi/F");
  fTree->Branch("diphoton_E",&diphoton_E,"diphoton_E/F");
  //diphoton scale variations
  fTree->Branch("diphoton_m_scaleUp",&diphoton_m_scaleUp,"diphoton_m_scaleUp/F");
  fTree->Branch("diphoton_m_scaleDn",&diphoton_m_scaleDn,"diphoton_m_scaleDn/F");
  fTree->Branch("diphoton_pt_scaleUp",&diphoton_pt_scaleUp,"diphoton_pt_scaleUp/F");
  fTree->Branch("diphoton_pt_scaleDn",&diphoton_pt_scaleDn,"diphoton_pt_scaleDn/F");
  fTree->Branch("pho1_mvaID_WP80",&pho1_mvaID_WP80,"pho1_mvaID_WP80/F");
  fTree->Branch("pho2_mvaID_WP80",&pho2_mvaID_WP80,"pho2_mvaID_WP80/F");
  fTree->Branch("pho1_mvaID_Fall17V1p1",&pho1_mvaID_Fall17V1p1,"pho1_mvaID_Fall17V1p1/F");
  fTree->Branch("pho2_mvaID_Fall17V1p1",&pho2_mvaID_Fall17V1p1,"pho2_mvaID_Fall17V1p1/F");
  fTree->Branch("pho1_mvaID_WP90",&pho1_mvaID_WP90,"pho1_mvaID_WP90/F");
  fTree->Branch("pho2_mvaID_WP90",&pho2_mvaID_WP90,"pho2_mvaID_WP90/F");



};

void output::clearVars() {

   nTagJets = -999.0;
   allFullyResolved_AK4JetsSum_pt = -999.0;
   allOneJet_AK8JetsSum_pt = -999.0;
   nOneJet_GoodFatJet = -999.0;
   nGoodThreeJet_FatJet = -999.0;
   nGoodThreeJet_Ak4Jet = -999.0;



    OneJet_FatJet_area = -999.0;
  	OneJet_FatJet_btagCMVA = -999.0;
  	OneJet_FatJet_btagCSVV2 = -999.0;
  	OneJet_FatJet_btagDDBvL = -999.0;
  	OneJet_FatJet_btagDDBvL_noMD = -999.0;
  	OneJet_FatJet_btagDDCvB = -999.0;
  	OneJet_FatJet_btagDDCvB_noMD = -999.0;
  	OneJet_FatJet_btagDDCvL = -999.0;
  	OneJet_FatJet_btagDDCvL_noMD = -999.0;
  	OneJet_FatJet_btagDeepB = -999.0;
  	OneJet_FatJet_btagHbb = -999.0;
  	OneJet_FatJet_deepTagMD_H4qvsQCD = -999.0;
  	OneJet_FatJet_deepTagMD_HbbvsQCD = -999.0;
  	OneJet_FatJet_deepTagMD_TvsQCD = -999.0;
  	OneJet_FatJet_deepTagMD_WvsQCD = -999.0;
  	OneJet_FatJet_deepTagMD_ZHbbvsQCD = -999.0;
  	OneJet_FatJet_deepTagMD_ZHccvsQCD = -999.0;
  	OneJet_FatJet_deepTagMD_ZbbvsQCD = -999.0;
  	OneJet_FatJet_deepTagMD_ZvsQCD = -999.0;
  	OneJet_FatJet_deepTagMD_bbvsLight = -999.0;
  	OneJet_FatJet_deepTagMD_ccvsLight = -999.0;
  	OneJet_FatJet_deepTag_H = -999.0;
  	OneJet_FatJet_deepTag_QCD = -999.0;
  	OneJet_FatJet_deepTag_QCDothers = -999.0;
  	OneJet_FatJet_deepTag_TvsQCD = -999.0;
  	OneJet_FatJet_deepTag_WvsQCD = -999.0;
  	OneJet_FatJet_deepTag_ZvsQCD = -999.0;
  	OneJet_FatJet_electronIdx3SJ = -999;
  	OneJet_FatJet_eta = -999.0;
    OneJet_FatJet_genJetAK8Idx = -999;
  	OneJet_FatJet_hadronFlavour = -999;
  	OneJet_FatJet_jetId = -999;
  	OneJet_FatJet_lsf3 = -999.0;
  	OneJet_FatJet_mass = -999.0;
  	OneJet_FatJet_msoftdrop = -999.0;
  	OneJet_FatJet_muonIdx3SJ = -999;
  	OneJet_FatJet_n2b1 = -999.0;
  	OneJet_FatJet_n3b1 = -999.0;
  	OneJet_FatJet_particleNetMD_QCD = -999.0;
  	OneJet_FatJet_particleNetMD_Xbb = -999.0;
  	OneJet_FatJet_particleNetMD_Xcc = -999.0;
  	OneJet_FatJet_particleNetMD_Xqq = -999.0;
  	OneJet_FatJet_particleNet_H4qvsQCD = -999.0;
  	OneJet_FatJet_particleNet_HbbvsQCD = -999.0;
  	OneJet_FatJet_particleNet_HccvsQCD = -999.0;
  	OneJet_FatJet_particleNet_QCD = -999.0;
  	OneJet_FatJet_particleNet_TvsQCD = -999.0;
  	OneJet_FatJet_particleNet_WvsQCD = -999.0;
  	OneJet_FatJet_particleNet_ZvsQCD = -999.0;
  	OneJet_FatJet_phi = -999.0;
  	OneJet_FatJet_pt = -999.0;
  	OneJet_FatJet_rawFactor = -999.0;
    OneJet_FatJet_subJetIdx1 = -999;
  	OneJet_FatJet_subJetIdx2 = -999;
  	OneJet_FatJet_tau1 = -999.0;
  	OneJet_FatJet_tau2 = -999.0;
  	OneJet_FatJet_tau3 = -999.0;
  	OneJet_FatJet_tau4 = -999.0;
  	OneJet_nFatJet = -999; 
   ThreeJet_FatJet_btagCMVA = -999.0;
   ThreeJet_FatJet_btagCSVV2 = -999.0;
   ThreeJet_FatJet_btagDDBvL = -999.0;
   ThreeJet_FatJet_btagDDBvL_noMD = -999.0;
   ThreeJet_FatJet_btagDDCvB = -999.0;
   ThreeJet_FatJet_btagDDCvB_noMD = -999.0;
   ThreeJet_FatJet_btagDDCvL     = -999.0;
   ThreeJet_FatJet_btagDDCvL_noMD = -999.0;
   ThreeJet_FatJet_btagDeepB      = -999.0;
   ThreeJet_FatJet_btagHbb = -999.0;
   ThreeJet_FatJet_deepTagMD_H4qvsQCD = -999.0;
   ThreeJet_FatJet_deepTagMD_HbbvsQCD = -999.0;
   ThreeJet_FatJet_deepTagMD_TvsQCD = -999.0;
   ThreeJet_FatJet_deepTagMD_WvsQCD = -999.0;
   ThreeJet_FatJet_deepTagMD_ZHbbvsQCD = -999.0;
   ThreeJet_FatJet_deepTagMD_ZHccvsQCD = -999.0;
   ThreeJet_FatJet_deepTagMD_ZbbvsQCD  = -999.0;
   ThreeJet_FatJet_deepTagMD_ZvsQCD = -999.0;
   ThreeJet_FatJet_deepTagMD_bbvsLight = -999.0;
   ThreeJet_FatJet_deepTagMD_ccvsLight = -999.0;
   ThreeJet_FatJet_deepTag_H = -999.0;
   ThreeJet_FatJet_deepTag_QCD = -999.0;
   ThreeJet_FatJet_deepTag_QCDothers = -999.0;
   ThreeJet_FatJet_deepTag_TvsQCD = -999.0;
   ThreeJet_FatJet_deepTag_WvsQCD = -999.0;
   ThreeJet_FatJet_deepTag_ZvsQCD = -999.0;
   ThreeJet_FatJet_electronIdx3SJ = -999.0;
   ThreeJet_FatJet_eta = -999.0;
   ThreeJet_FatJet_genJetAK8Idx = -999.0;
   ThreeJet_FatJet_hadronFlavour = -999.0;
   ThreeJet_FatJet_jetId = -999.0;
   ThreeJet_FatJet_lsf3 = -999.0;
   ThreeJet_FatJet_mass = -999.0;
   ThreeJet_FatJet_msoftdrop = -999.0;
   ThreeJet_FatJet_muonIdx3SJ = -999.0;
   ThreeJet_FatJet_n2b1 = -999.0;
   ThreeJet_FatJet_n3b1 = -999.0;
   ThreeJet_FatJet_nBHadrons = -999.0;
   ThreeJet_FatJet_nCHadrons = -999.0;
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
  ThreeJet_FatJet_phi=-999.0;
  ThreeJet_FatJet_pt=-999.0;
  ThreeJet_FatJet_rawFactor=-999.0;
  ThreeJet_FatJet_subJetIdx1=-999.0;
  ThreeJet_FatJet_subJetIdx2=-999.0;
  ThreeJet_FatJet_tau1=-999.0;
  ThreeJet_FatJet_tau2=-999.0;
  ThreeJet_FatJet_tau3=-999.0;
  ThreeJet_FatJet_tau4=-999.0;
  ThreeJet_nFatJet=-999.0;
  ThreeJetAk4_jet1_pt = -999.0;
  ThreeJetAk4_jet2_pt = -999.0;
  ThreeJetAk4_jet1_eta = -999.0;
  ThreeJetAk4_jet2_eta = -999.0;
  ThreeJetAk4_jet1_phi = -999.0;
  ThreeJetAk4_jet2_phi = -999.0;
  ThreeJetAk4_jet1_M = -999.0;
  ThreeJetAk4_jet2_M = -999.0;
  ThreeJet_FatJet_nCHadrons = -999.0;








   FullyResolved_jet1_E = -999.0;
   FullyResolved_jet2_E = -999.0;
   FullyResolved_jet3_E = -999.0;
   FullyResolved_jet4_E = -999.0;

   FullyResolved_jet1_M = -999.0;
   FullyResolved_jet2_M = -999.0;
   FullyResolved_jet3_M = -999.0;
   FullyResolved_jet4_M = -999.0;

   FullyResolvedTwoLeadingJets_pt = -999.0;
   FullyResolvedTwoLeadingJets_eta = -999.0;
   FullyResolvedTwoLeadingJets_phi = -999.0;
   FullyResolvedTwoLeadingJets_m = -999.0;
   FullyResolvedTwoLeadingJets_E = -999.0;

   FullyResolvedThirdFourthJets_pt = -999.0;
   FullyResolvedThirdFourthJets_eta = -999.0;
   FullyResolvedThirdFourthJets_phi = -999.0;
   FullyResolvedThirdFourthJets_m = -999.0;
   FullyResolvedThirdFourthJets_E = -999.0;

   FullyResolvedFourJets_pt = -999.0;
   FullyResolvedFourJets_eta = -999.0;
   FullyResolvedFourJets_phi = -999.0;
   FullyResolvedFourJets_m = -999.0;
   FullyResolvedFourJets_E = -999.0;

   ThreeJetTwoLeadingJets_pt = -999.0;
   ThreeJetTwoLeadingJets_eta = -999.0;
   ThreeJetTwoLeadingJets_phi = -999.0;
   ThreeJetTwoLeadingJets_m = -999.0;
   ThreeJetTwoLeadingJets_E = -999.0;
  //  AK8_Jet1_pt = -999.0;
  //  AK8_Jet2_pt = -999.0;
  //  AK8_Jet3_pt = -999.0;
  //  AK8_Jet4_pt = -999.0;

  //  AK8_Jet1_eta = -999.0;
  //  AK8_Jet2_eta = -999.0;
  //  AK8_Jet3_eta = -999.0;
  //  AK8_Jet4_eta = -999.0;

  //  AK8_Jet1_phi = -999.0;
  //  AK8_Jet2_phi = -999.0;
  //  AK8_Jet3_phi = -999.0;
  //  AK8_Jet4_phi = -999.0;


  //------------------------------------//
  //       METADATA AND EVENT WEIGHTS   //
  //------------------------------------//



  //------------------------------------//
  //       photonS                      //
  //------------------------------------//




  //------------------------------------//
  //       METADATA AND EVENT WEIGHTS   //
  //------------------------------------//

  run = 0;
  ls = 0;
  evt = 0;
  FullyResolved_jet1_pt = -999.0;
  FullyResolved_jet2_pt = -999.0;
  FullyResolved_jet3_pt = -999.0;
  FullyResolved_jet4_pt = -999.0;
  
  FullyResolved_jet1_eta = -999.0;
  FullyResolved_jet2_eta = -999.0;
  FullyResolved_jet3_eta = -999.0;
  FullyResolved_jet4_eta = -999.0;
  
  FullyResolved_jet1_phi = -999.0;
  FullyResolved_jet2_phi = -999.0;
  FullyResolved_jet3_phi = -999.0;
  FullyResolved_jet4_phi = -999.0;

  // AK8_Jet1_pt = -999.0;
  // AK8_Jet2_pt = -999.0;
  // AK8_Jet3_pt = -999.0;
  // AK8_Jet4_pt = -999.0;

  // AK8_Jet1_eta = -999.0;
  // AK8_Jet2_eta = -999.0;
  // AK8_Jet3_eta = -999.0;
  // AK8_Jet4_eta = -999.0;

  // AK8_Jet1_phi = -999.0;
  // AK8_Jet2_phi = -999.0;
  // AK8_Jet3_phi = -999.0;
  // AK8_Jet4_phi = -999.0;


  // nPV = 0;
  nPU_mean = 0;

  genWeight = 1.0;
  puWeight = 1.0;
  puWeight_Up = 1.0;
  puWeight_Dn = 1.0;

  L1PFWeight = 1.0;

  std::fill_n(LHEWeight,1164,0);

  nScaleWeight = 0;
  nPdfWeight = 0;
  std::fill_n(scaleWeight,200,0);
  std::fill_n(pdfWeight,200,0);

  nBtag_loose = 0;
  nBtag_medium = 0;
  nBtag_tight = 0;

  btagWeight = 1.0;

  trigger_1Pho = false;
  trigger_2Pho = false;

  isAntiIso = false;

  //------------------------------------//
  //       photonS                      //
  //------------------------------------//

  //photon 1
  pho1_pt = -999.0;
  pho1_eta = -999.0;
  pho1_phi = -999.0;
  pho1_m = -999.0;
  pho1_q = -999.0;
  pho1_dxy = -999.0;
  pho1_dz = -999.0;
  pho1_iso = -999.0;
  pho1_idEffWeight = 1.0;
  pho1_E = -999.0;
  pho2_E = -999.0;
  diphoton_E = -999.0;

  //photon 1 scale variations
  pho1_pt_scaleUp = -999.0;
  pho1_pt_scaleDn = -999.0;

  //photon 2
  pho2_pt = -999.0;
  pho2_eta = -999.0;
  pho2_phi = -999.0;
  pho2_m = -999.0;
  pho2_q = -999.0;
  pho2_dxy = -999.0;
  pho2_dz = -999.0;
  pho2_iso = -999.0;
  pho2_idEffWeight = 1.0;

  //photon 2 scale variations
  pho2_pt_scaleUp = -999.0;
  pho2_pt_scaleDn = -999.0;

  //diphoton final state
  diphoton_m = -999.0;
  diphoton_pt = -999.0;
  diphoton_eta = -999.0;
  diphoton_phi = -999.0;

  //diphoton scale variations
  diphoton_m_scaleUp = -999.0;
  diphoton_m_scaleDn = -999.0;
  diphoton_pt_scaleUp = -999.0;
  diphoton_pt_scaleDn = -999.0;
  pho1_mvaID_Fall17V1p1 = -999.0;
  pho2_mvaID_Fall17V1p1 = -999.0;
  pho1_mvaID_WP80 = -999.0;
  pho2_mvaID_WP80 = -999.0;
  pho1_mvaID_WP90 = -999.0;
  pho2_mvaID_WP90 = -999.0;
  pho1_mvaIDFall17V1 = -999.0;
  pho1_mvaIDFall17V2 = -999.0;
  pho2_mvaIDFall17V1 = -999.0;
  pho2_mvaIDFall17V2 = -999.0;


  

};

