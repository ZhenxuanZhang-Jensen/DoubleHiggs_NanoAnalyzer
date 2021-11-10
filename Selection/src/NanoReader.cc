#include "../interface/NanoReader.hh"
/* -------------------------------------------------------------------------- */
/*                   Utilize the invariant mass information:                  */
/* -------------------------------------------------------------------------- */
// void GetFHminWHJets(std::vector<TLorentzVector> &AllGoodJets, std::vector<Float_t> &b_dis, std::vector<TLorentzVector> &SelectedJets, std::vector<Float_t> &Selectedb_dis, bool DEBUG)
// {
//     // get 4 jets for FH final state with minWH vals
//     SelectedJets.clear();
//     Selectedb_dis.clear();
//     double TempMinWMass = 999999.0;
//     double TempMinHMass = 999999.0;

//     int OnShellW_LeadingJetIndex = -1;
//     int OnShellW_SubLeadingJetIndex = -1;
//     int OffShellW_LeadingJetIndex = -1;
//     int OffShellW_SubLeadingJetIndex = -1;

//     TLorentzVector jet11;
//     TLorentzVector jet12;
//     TLorentzVector jet1;
//     TLorentzVector jet2;
//     TLorentzVector jet3;
//     TLorentzVector jet4;
//     Float_t jet1b;
//     Float_t jet2b;
//     Float_t jet3b;
//     Float_t jet4b;

//     int nTagJets = AllGoodJets.size();

//     // Select 2 jets whose mass closest to W-boson mass
//     for (int CountJet1 = 0; CountJet1 < nTagJets-1; CountJet1++) {
//         for (int CountJet2 = CountJet1+1; CountJet2 < nTagJets; CountJet2++) {
//             if (DEBUG) std::cout << "(CountJet1,CountJet2) = (" << CountJet1 << "," << CountJet2 << ")" << std::endl;
//             jet11 = AllGoodJets[CountJet1];
//             jet12 = AllGoodJets[CountJet2];
//             // if (b_dis[CountJet1] > 0.7221) continue;
//             // if (b_dis[CountJet2] > 0.7221) continue;

//             double deltaMass =  abs((jet11 + jet12).M() - 80.0);
//             if (DEBUG) std::cout << "deltaMass = " << deltaMass << "\t TempMinWMass = " << TempMinWMass << std::endl;
//             if ( deltaMass < TempMinWMass)
//             {
//                 if  (jet11.Pt() > jet12.Pt()) {
//                     OnShellW_LeadingJetIndex = CountJet1;
//                     OnShellW_SubLeadingJetIndex = CountJet2;
//                 } else {
//                     OnShellW_LeadingJetIndex = CountJet2;
//                     OnShellW_SubLeadingJetIndex = CountJet1;
//                 }
//                 TempMinWMass = deltaMass;
//                 if (DEBUG) std::cout << "==> (CountJet1,CountJet2) = (" << CountJet1 << "," << CountJet2 << ")" << std::endl;
//             }
//         }
//     }
//     if (DEBUG) std::cout << "[INFO] Print Jet Index (After W-Selection): " << OnShellW_LeadingJetIndex << "\t" << OnShellW_SubLeadingJetIndex << "\t" << OffShellW_LeadingJetIndex << "\t" << OffShellW_SubLeadingJetIndex  << std::endl;

//     for (int CountJet1 = 0; CountJet1 < nTagJets-1; CountJet1++) {
//         if (CountJet1 == OnShellW_LeadingJetIndex || CountJet1 == OnShellW_SubLeadingJetIndex) continue;
//         for (int CountJet2 = CountJet1+1; CountJet2 < nTagJets; CountJet2++) {
//             if (CountJet2 == OnShellW_LeadingJetIndex || CountJet2 == OnShellW_SubLeadingJetIndex) continue;
//             if (DEBUG) std::cout << "(CountJet1,CountJet2) = (" << CountJet1 << "," << CountJet2 << ")" << std::endl;
//             jet11 = AllGoodJets[CountJet1];
//             jet12 = AllGoodJets[CountJet2];

//             double deltaMass =  abs((jet11 + jet12 + AllGoodJets[OnShellW_LeadingJetIndex] + AllGoodJets[OnShellW_SubLeadingJetIndex] ).M() - 125.0);
//             if (DEBUG) std::cout << "deltaMass = " << deltaMass << "\t TempMinHMass = " << TempMinHMass << std::endl;
//             if ( deltaMass < TempMinHMass)
//             {
//                 if  (jet11.Pt() > jet12.Pt()) {
//                     OffShellW_LeadingJetIndex = CountJet1;
//                     OffShellW_SubLeadingJetIndex = CountJet2;
//                 } else {
//                     OffShellW_LeadingJetIndex = CountJet2;
//                     OffShellW_SubLeadingJetIndex = CountJet1;
//                 }
//                 TempMinHMass = deltaMass;
//                 if (DEBUG) std::cout << "==> (CountJet1,CountJet2) = (" << CountJet1 << "," << CountJet2 << ")" << std::endl;
//             }
//         }
//     }
//     jet1 = AllGoodJets[OnShellW_LeadingJetIndex];
//     jet2 = AllGoodJets[OnShellW_SubLeadingJetIndex];
//     jet3 = AllGoodJets[OffShellW_LeadingJetIndex];
//     jet4 = AllGoodJets[OffShellW_SubLeadingJetIndex];
//     jet1b = b_dis[OnShellW_LeadingJetIndex];
//     jet2b = b_dis[OnShellW_SubLeadingJetIndex];
//     jet3b = b_dis[OffShellW_LeadingJetIndex];
//     jet4b = b_dis[OffShellW_SubLeadingJetIndex];

//     if (DEBUG) std::cout << "[INFO] Print pt of 4 selected jets: " << OnShellW_LeadingJetIndex << "\t" << OnShellW_SubLeadingJetIndex << "\t" << OffShellW_LeadingJetIndex << "\t" << OffShellW_SubLeadingJetIndex  << std::endl;
//     if (DEBUG) std::cout << "[INFO] jet1 pT = " << jet1.Pt() << std::endl;
//     if (DEBUG) std::cout << "[INFO] jet2 pT = " << jet2.Pt() << std::endl;
//     if (DEBUG) std::cout << "[INFO] jet3 pT = " << jet3.Pt() << std::endl;
//     if (DEBUG) std::cout << "[INFO] jet4 pT = " << jet4.Pt() << std::endl;

//     SelectedJets.push_back(jet1);
//     SelectedJets.push_back(jet2);
//     SelectedJets.push_back(jet3);
//     SelectedJets.push_back(jet4);
//     Selectedb_dis.push_back(jet1b);
//     Selectedb_dis.push_back(jet2b);
//     Selectedb_dis.push_back(jet3b);
//     Selectedb_dis.push_back(jet4b);

// }
/* -------------------------------------------------------------------------- */
/*               Choose the four jets with max (dR(H_γγ,H_jjjj))              */
/* -------------------------------------------------------------------------- */
template<typename T> std::vector<std::vector<T>> getAllCombinations(const std::vector<T>& inputVector, int k)
{
    std::vector<std::vector<T>> combinations;
    std::vector<int> selector(inputVector.size());
    std::fill(selector.begin(), selector.begin() + k, 1);

    do {
        std::vector<int> selectedIds;
        std::vector<T> selectedVectorElements;
        for (uint i = 0; i < inputVector.size(); i++) {
            if (selector[i]) {
                selectedIds.push_back(i);
            }
        }
        for (auto& id : selectedIds) {
            selectedVectorElements.push_back(inputVector[id]);
        }
        combinations.push_back(selectedVectorElements);
    } while (std::prev_permutation(selector.begin(), selector.end()));

    return combinations;
}

double DeltaPhi(double phi1,double phi2)
{
  double result = phi1 - phi2;
  if (result > TMath::Pi()) result -= 2*TMath::Pi();
  if (result <= -TMath::Pi()) result += 2*TMath::Pi();
  return result;
}
double DeltaR(double eta1,double phi1,double eta2,double phi2)
{
  double deta = eta1 - eta2;
  double dphi = DeltaPhi(phi1, phi2);
  return std::sqrt(deta*deta + dphi*dphi);
}
void GetFHJetUsingDR(TLorentzVector &Hgg, std::vector<TLorentzVector> &AllGoodJets, std::vector<Float_t> &b_dis, std::vector<TLorentzVector> &SelectedJets, std::vector<Float_t> &Selectedb_dis, bool DEBUG)
{
    // get 4 jets for FH final state with minWH vals
    SelectedJets.clear();
    Selectedb_dis.clear();
    double TempMinWMass = 999999.0;
    double TempMinHMass = 999999.0;

    int OnShellW_LeadingJetIndex = -1;
    int OnShellW_SubLeadingJetIndex = -1;
    int OffShellW_LeadingJetIndex = -1;
    int OffShellW_SubLeadingJetIndex = -1;

    TLorentzVector jet11;
    TLorentzVector jet12;
    TLorentzVector jet21;
    TLorentzVector jet22;
    TLorentzVector jet1;
    TLorentzVector jet2;
    TLorentzVector jet3;
    TLorentzVector jet4;
    Float_t jet1b;
    Float_t jet2b;
    Float_t jet3b;
    Float_t jet4b;

    int nTagJets = AllGoodJets.size();
    std::vector<int> PosOfGoodJets;

    for (int i = 0; i < nTagJets; ++i)
    {
        PosOfGoodJets.push_back(i);
    }

    std::vector<std::vector<int>> CombinationsOf4Jets = getAllCombinations(PosOfGoodJets, 4);

    if (DEBUG) std::cout << "Size of vector output: " << CombinationsOf4Jets.size() << std::endl;

    float minDR = 10.0;
    float maxDPhi = 0;

    for (uint i = 0; i < CombinationsOf4Jets.size(); ++i)
    {
        if (DEBUG) std::cout << "Combination: " << i << ": ";
        for (uint j = 0; j < CombinationsOf4Jets[i].size(); ++j)
        {
            if (DEBUG) std::cout << CombinationsOf4Jets[i][j] << "\t";
        }
        TLorentzVector HWW = AllGoodJets[CombinationsOf4Jets[i][0]] + AllGoodJets[CombinationsOf4Jets[i][1]] + AllGoodJets[CombinationsOf4Jets[i][2]] + AllGoodJets[CombinationsOf4Jets[i][3]];
        float temp_dR = DeltaR(Hgg.Eta(), Hgg.Phi(), HWW.Eta(), HWW.Phi());
        float temp_dphi = DeltaPhi(Hgg.Phi(),HWW.Phi());
        if (temp_dphi > maxDPhi)
        {
            /* code */
            // minDR = temp_dR;
            maxDPhi = temp_dphi;
            std::vector<std::vector<int>> CombinationsOf2Jets = getAllCombinations(CombinationsOf4Jets[i], 2);

            float minDMass = 100.0;

            for (uint WMassIndex = 0; WMassIndex < CombinationsOf2Jets.size(); ++WMassIndex)
            {
                TLorentzVector W1 = AllGoodJets[CombinationsOf2Jets[WMassIndex][0]] + AllGoodJets[CombinationsOf2Jets[WMassIndex][1]];
                float temp_Mass = abs(W1.M() - 80.0);
                if (temp_Mass < minDMass)
                {
                    minDMass = temp_Mass;
                    OnShellW_LeadingJetIndex = CombinationsOf2Jets[WMassIndex][0];
                    OnShellW_SubLeadingJetIndex = CombinationsOf2Jets[WMassIndex][1];
                }
            }

            int countOffShellJets = 0;
            for (uint IndexOffShellW = 0; IndexOffShellW < CombinationsOf4Jets[i].size(); ++IndexOffShellW)
            {
                if (CombinationsOf4Jets[i][IndexOffShellW] == OnShellW_LeadingJetIndex) continue;
                if (CombinationsOf4Jets[i][IndexOffShellW] == OnShellW_SubLeadingJetIndex) continue;
                countOffShellJets++;
                if (countOffShellJets==1) OffShellW_LeadingJetIndex = CombinationsOf4Jets[i][IndexOffShellW];
                if (countOffShellJets==2) OffShellW_SubLeadingJetIndex = CombinationsOf4Jets[i][IndexOffShellW];
            }
            }

        if (DEBUG) std::cout << "\n" << std::endl;
    }

    jet1 = AllGoodJets[OnShellW_LeadingJetIndex];
    jet2 = AllGoodJets[OnShellW_SubLeadingJetIndex];
    jet3 = AllGoodJets[OffShellW_LeadingJetIndex];
    jet4 = AllGoodJets[OffShellW_SubLeadingJetIndex];
    jet1b = b_dis[OnShellW_LeadingJetIndex];
    jet2b = b_dis[OnShellW_SubLeadingJetIndex];
    jet3b = b_dis[OffShellW_LeadingJetIndex];
    jet4b = b_dis[OffShellW_SubLeadingJetIndex];

    if (DEBUG) std::cout << "[INFO] Print pt of 4 selected jets: " << OnShellW_LeadingJetIndex << "\t" << OnShellW_SubLeadingJetIndex << "\t" << OffShellW_LeadingJetIndex << "\t" << OffShellW_SubLeadingJetIndex  << std::endl;
    if (DEBUG) std::cout << "[INFO] jet1 pT = " << jet1.Pt() << std::endl;
    if (DEBUG) std::cout << "[INFO] jet2 pT = " << jet2.Pt() << std::endl;
    if (DEBUG) std::cout << "[INFO] jet3 pT = " << jet3.Pt() << std::endl;
    if (DEBUG) std::cout << "[INFO] jet4 pT = " << jet4.Pt() << std::endl;

    SelectedJets.push_back(jet1);
    SelectedJets.push_back(jet2);
    SelectedJets.push_back(jet3);
    SelectedJets.push_back(jet4);
    Selectedb_dis.push_back(jet1b);
    Selectedb_dis.push_back(jet2b);
    Selectedb_dis.push_back(jet3b);
    Selectedb_dis.push_back(jet4b);
}
