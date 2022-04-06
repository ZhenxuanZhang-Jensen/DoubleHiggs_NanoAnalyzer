#ifndef UTILS_HH
#define UTILS_HH

#include "TMath.h"
#include "../interface/WVJJData.hh"
#include "TLorentzVector.h"

//float deltaR(float eta1, float phi1, float eta2, float phi2) {
//
//  float dPhi = fabs(phi1-phi2);
//  if (dPhi>6.283185308) dPhi -= 6.283185308;
//  if (dPhi>3.141592654) dPhi = 6.283185308 - dPhi;
//
//  float dEta = fabs(eta1-eta2);
//
//  return sqrt( dPhi*dPhi + dEta*dEta );
//
//}

float deltaR(float eta1, float phi1, float eta2, float phi2) {
  float deltaPhi = TMath::Abs(phi1-phi2);
  float deltaEta = eta1-eta2;
  if(deltaPhi > TMath::Pi()) {
    deltaPhi = TMath::TwoPi() - deltaPhi;
  }
  return TMath::Sqrt(deltaEta*deltaEta + deltaPhi*deltaPhi);
}

float deltaR(TLorentzVector vec1, TLorentzVector vec2) {
  float eta1 = vec1.Eta();
  float eta2 = vec2.Eta();
  float phi1 = vec1.Phi();
  float phi2 = vec2.Phi();
  
  return deltaR(eta1, phi1, eta2, phi2);
}

float MinDeltaRFromReferenceLV(TLorentzVector ReferenceVec, TLorentzVector Check1, TLorentzVector Check2)
{
  float deltaR1 = deltaR(ReferenceVec, Check1);
  float deltaR2 = deltaR(ReferenceVec, Check2);
  return TMath::Min(deltaR1,deltaR2);
}

float MinDeltaRFromReferenceLV(TLorentzVector ReferenceVec, TLorentzVector Check1, TLorentzVector Check2, TLorentzVector Check3, TLorentzVector Check4)
{
  float deltaR1 = deltaR(ReferenceVec, Check1);
  float deltaR2 = deltaR(ReferenceVec, Check2);
  float deltaR3 = deltaR(ReferenceVec, Check3);
  float deltaR4 = deltaR(ReferenceVec, Check4);
  float minOf12 = TMath::Min(deltaR1,deltaR2);
  float minOf34 = TMath::Min(deltaR3,deltaR4);
  return TMath::Min(minOf12,minOf34);
}


/* minimum deltaR between any 4 TLorentzVector */
float MinDeltaR(TLorentzVector Check1, TLorentzVector Check2, TLorentzVector Check3, TLorentzVector Check4)
{
  float deltaR1 = deltaR(Check1, Check2);
  float deltaR2 = deltaR(Check1, Check3);
  float deltaR3 = deltaR(Check1, Check4);
  
  float deltaR4 = deltaR(Check2, Check3);
  float deltaR5 = deltaR(Check2, Check4);

  float deltaR6 = deltaR(Check3, Check4);
  
  return TMath::Min(TMath::Min(TMath::Min(TMath::Min(TMath::Min(deltaR1,deltaR2), deltaR3), deltaR4), deltaR5), deltaR6);
}
float MinDeltaR3(TLorentzVector Check1, TLorentzVector Check2, TLorentzVector Check3)
{
  float deltaR1 = deltaR(Check1, Check2);
  float deltaR2 = deltaR(Check1, Check3);
  float deltaR3 = deltaR(Check2, Check3);
  return TMath::Min(TMath::Min(deltaR1,deltaR2), deltaR3);
}
/* maximum deltaR between any 4 TLorentzVector */
float MaxDeltaR(TLorentzVector Check1, TLorentzVector Check2, TLorentzVector Check3, TLorentzVector Check4)
{
  float deltaR1 = deltaR(Check1, Check2);
  float deltaR2 = deltaR(Check1, Check3);
  float deltaR3 = deltaR(Check1, Check4);
  
  float deltaR4 = deltaR(Check2, Check3);
  float deltaR5 = deltaR(Check2, Check4);

  float deltaR6 = deltaR(Check3, Check4);
  
  return TMath::Max(TMath::Max(TMath::Max(TMath::Max(TMath::Max(deltaR1,deltaR2), deltaR3), deltaR4), deltaR5), deltaR6);
}
float Min3Q(TLorentzVector Check1, TLorentzVector Check2, TLorentzVector Check3, TLorentzVector Check4)
{
  TLorentzVector min2Q;
  float none =-999;
  float deltaR1 = deltaR(Check1, Check2);
  float deltaR2 = deltaR(Check1, Check3);
  float deltaR3 = deltaR(Check1, Check4);
  
  float deltaR4 = deltaR(Check2, Check3);
  float deltaR5 = deltaR(Check2, Check4);

  float deltaR6 = deltaR(Check3, Check4);
  float mindeltaR = TMath::Min(TMath::Min(TMath::Min(TMath::Min(TMath::Min(deltaR1,deltaR2), deltaR3), deltaR4), deltaR5), deltaR6);
  if(mindeltaR == deltaR1){min2Q = Check1+Check2;return MinDeltaR3(min2Q,Check3,Check4);};
  if(mindeltaR == deltaR2){min2Q = Check1+Check3;return MinDeltaR3(min2Q,Check2,Check4);};
  if(mindeltaR == deltaR3){min2Q = Check1+Check4;return MinDeltaR3(min2Q,Check2,Check3);};
  if(mindeltaR == deltaR4){min2Q = Check2+Check3;return MinDeltaR3(min2Q,Check1,Check4);};
  if(mindeltaR == deltaR5){min2Q = Check2+Check4;return MinDeltaR3(min2Q,Check1,Check3);};
  if(mindeltaR == deltaR6){min2Q = Check3+Check4;return MinDeltaR3(min2Q,Check1,Check2);};
  return none;
}
float TwoJetCategory(TLorentzVector Check1, TLorentzVector Check2, TLorentzVector Check3, TLorentzVector Check4)
{
   TLorentzVector min2Q;
  float deltaR1 = deltaR(Check1, Check2);
  float deltaR2 = deltaR(Check1, Check3);
  float deltaR3 = deltaR(Check1, Check4);
  
  float deltaR4 = deltaR(Check2, Check3);
  float deltaR5 = deltaR(Check2, Check4);

  float deltaR6 = deltaR(Check3, Check4);
  float mindeltaR = TMath::Min(TMath::Min(TMath::Min(TMath::Min(TMath::Min(deltaR1,deltaR2), deltaR3), deltaR4), deltaR5), deltaR6);
  if(mindeltaR == deltaR1 && mindeltaR<0.8 && deltaR(Check3,Check4)<0.8 && MaxDeltaR(Check1,Check2,Check3,Check4)>1.6) {return 1;};
  if(mindeltaR == deltaR2 && mindeltaR<0.8 && deltaR(Check2,Check4)<0.8 && MaxDeltaR(Check1,Check2,Check3,Check4)>1.6) {return 1;};
  if(mindeltaR == deltaR3 && mindeltaR<0.8 && deltaR(Check2,Check3)<0.8 && MaxDeltaR(Check1,Check2,Check3,Check4)>1.6) {return 1;};
  if(mindeltaR == deltaR4 && mindeltaR<0.8 && deltaR(Check1,Check4)<0.8 && MaxDeltaR(Check1,Check2,Check3,Check4)>1.6) {return 1;};
  if(mindeltaR == deltaR5 && mindeltaR<0.8 && deltaR(Check1,Check3)<0.8 && MaxDeltaR(Check1,Check2,Check3,Check4)>1.6) {return 1;};
  if(mindeltaR == deltaR6 && mindeltaR<0.8 && deltaR(Check1,Check2)<0.8 && MaxDeltaR(Check1,Check2,Check3,Check4)>1.6) {return 1;};
  return 0;
}
float ThreeJetCategory(TLorentzVector Check1, TLorentzVector Check2, TLorentzVector Check3, TLorentzVector Check4)
{
   TLorentzVector Merge_2Q_1;
   TLorentzVector Merge_2Q_2;
   TLorentzVector Merge_2Q_3;
   TLorentzVector Merge_2Q_4;
   TLorentzVector Merge_2Q_5;
   TLorentzVector Merge_2Q_6;
  float deltaR1 = deltaR(Check1, Check2);
  float deltaR2 = deltaR(Check1, Check3);
  float deltaR3 = deltaR(Check1, Check4);
  float deltaR4 = deltaR(Check2, Check3);
  float deltaR5 = deltaR(Check2, Check4);
  float deltaR6 = deltaR(Check3, Check4);
  Merge_2Q_1 = Check1 + Check2;
  Merge_2Q_2 = Check1 + Check3;
  Merge_2Q_3 = Check1 + Check4;
  Merge_2Q_4 = Check2 + Check3;
  Merge_2Q_5 = Check2 + Check4;
  Merge_2Q_6 = Check3 + Check4;

  float mindeltaR = TMath::Min(TMath::Min(TMath::Min(TMath::Min(TMath::Min(deltaR1,deltaR2), deltaR3), deltaR4), deltaR5), deltaR6);
  if(mindeltaR == deltaR1 && mindeltaR<0.8 && deltaR(Check3,Check4)>0.8 && MinDeltaRFromReferenceLV(Merge_2Q_1,Check3,Check4)>1.2) {return 1;};
  if(mindeltaR == deltaR2 && mindeltaR<0.8 && deltaR(Check2,Check4)>0.8 && MinDeltaRFromReferenceLV(Merge_2Q_2,Check2,Check4)>1.2) {return 1;};
  if(mindeltaR == deltaR3 && mindeltaR<0.8 && deltaR(Check2,Check3)>0.8 && MinDeltaRFromReferenceLV(Merge_2Q_3,Check2,Check3)>1.2) {return 1;};
  if(mindeltaR == deltaR4 && mindeltaR<0.8 && deltaR(Check1,Check4)>0.8 && MinDeltaRFromReferenceLV(Merge_2Q_4,Check1,Check4)>1.2) {return 1;};
  if(mindeltaR == deltaR5 && mindeltaR<0.8 && deltaR(Check1,Check3)>0.8 && MinDeltaRFromReferenceLV(Merge_2Q_5,Check1,Check3)>1.2) {return 1;};
  if(mindeltaR == deltaR6 && mindeltaR<0.8 && deltaR(Check1,Check2)>0.8 && MinDeltaRFromReferenceLV(Merge_2Q_6,Check1,Check2)>1.2) {return 1;};
  return 0;
}

float deltaPhi(float phi1, float phi2) {
  float deltaphi_ = TMath::Abs(phi1-phi2);
  if(deltaphi_ > TMath::Pi()) {
    deltaphi_ = TMath::TwoPi() - deltaphi_;
  }
  return deltaphi_;
}

float deltaPhi(TLorentzVector vec1, TLorentzVector vec2) {
  float phi1 = vec1.Phi();
  float phi2 = vec2.Phi();
  float deltaphi_ = TMath::Abs(phi1-phi2);
  if(deltaphi_ > TMath::Pi()) {
    deltaphi_ = TMath::TwoPi() - deltaphi_;
  }
  return deltaphi_;
}

float deltaEta(TLorentzVector vec1, TLorentzVector vec2) {
  float eta1 = vec1.Eta();
  float eta2 = vec2.Eta();
  float deltaeta_ = eta1-eta2;
  return deltaeta_;
}

float GetBinTH2_value(float x, float y, TH2* h2) {
  int nbinsX = h2->GetNbinsX();
  int nbinsY = h2->GetNbinsY();
  int xbin = h2->GetXaxis()->FindBin(x);
  int ybin = h2->GetYaxis()->FindBin(y);
  xbin = (xbin > nbinsX) ? nbinsX : (xbin < 1 ? 1 : xbin);
  ybin = (ybin > nbinsY) ? nbinsY : (ybin < 1 ? 1 : ybin);
  return h2->GetBinContent(xbin, ybin);
}

float GetSFs_Lepton(double pt, double eta, TH1 *h1){
  if (pt > h1->GetYaxis()->GetXmax())
    pt = h1->GetYaxis()->GetXmax() - 1.0;
  if (pt < h1->GetYaxis()->GetXmin())
    pt = h1->GetYaxis()->GetXmin() + 1.0;

  return h1->GetBinContent(h1->GetXaxis()->FindFixBin(eta), h1->GetYaxis()->FindFixBin(pt));
}

//double GetJECunc( double pt, double eta, JetCorrectionUncertainty *fJetUnc) {
//  fJetUnc->setJetPt ( pt  );
//  fJetUnc->setJetEta( eta );
//  return fJetUnc->getUncertainty(true);
//}

/**
 * @brief      Check if the string contains suffix or not
 *
 * @param[in]  s       Input string
 * @param[in]  suffix  Suffix to check
 *
 * @return     Return true or false if input string contains suffix or not.
 */
bool ends_with(const std::string & s, const std::string & suffix) {
    return s.rfind(suffix) == s.length() - suffix.length();
}

//======================================================================
// Got this from
// http://oopweb.com/CPP/Documents/CPPHOWTO/Volume/C++Programming-HOWTO-7.html
// returns one token (the whole string) if none of the delimiters are found.
//
void Tokenize(const std::string& str,
        std::vector<std::string>& tokens,
        const std::string& delimiters = "/",
        bool include_delimiters=false)
{
  std::string src=str;
  tokens.clear();
  // std::cout << "string: " << str << std::endl;
  // std::cout << "delimiters: " << delimiters << std::endl;
  // std::cout << "string: " << str << std::endl;

  // Skip delimiters at beginning.
  std::string::size_type lastPos = src.find_first_not_of(delimiters, 0);

  if (include_delimiters && lastPos>0)
    tokens.push_back(src.substr(0,lastPos));

  // Find first delimiter.
  std::string::size_type pos = src.find_first_of(delimiters, lastPos);

  while (pos != std::string::npos || lastPos != std::string::npos) {
    // Found a token, add it to the vector.
    tokens.push_back(src.substr(lastPos, pos - lastPos));

    lastPos = src.find_first_not_of(delimiters, pos);

    if (include_delimiters && pos!=std::string::npos) {
      tokens.push_back(src.substr(pos, lastPos-pos));
    } //else skip delimiters.

    // Find next delimiter
    pos = src.find_first_of(delimiters, lastPos);

  }
  // std::cout << "tokens.size() = " << tokens.size() << std::endl;
  // std::cout << "tokens[8] = " << tokens[8] << std::endl;
  // std::cout << "tokens[8] = " << tokens[9] << std::endl;
}                                                            // Tokenize

#endif
