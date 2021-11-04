import pandas as pd
import ROOT
import os

ROOT.gROOT.SetBatch(True)

plotDir = "CutFlowTables_SL"
if not os.path.isdir(plotDir):
    os.makedirs(plotDir)

Hist = [
        "/eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G2Qlnu_M250.root",
        "/eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G2Qlnu_M1000.root",
        "/eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G2Qlnu_M3000.root",
        # "GluGluToRadionToHHTo2G2Qlnu_M500.root",
        # "GluGluToRadionToHHTo2G2Qlnu_M800.root",
        # "GluGluToRadionToHHTo2G2Qlnu_M1500.root",
        # "GluGluToRadionToHHTo2G2Qlnu_M2000.root",
        # "GluGluToRadionToHHTo2G2Qlnu_M2500.root"
        ]

info = {"SampleName": [],
        "MC Gen": [],
        "Trigger": [],
        "Photon Selection": [],
        "Lepton Selection": [],
        "Ele before cut": [],
        "Mu before cut": [],
        "Mu after cut": [],
        "Ele after cut": [],
        "nAK8_W >= 1": [],
        "nAK4 >= 2": [],
        "1Jet+2Jet": [],
        "pT/mgg cut": [],
        "pT(#gamma #gamma)>100": [],
        "DiPhoton (%)": [],
        "Exactly 1 lepton(%)": [],
        "1Jet Category(%)": [],
        "2Jet Category(%)": [],
        "All cat jets(%)": [],
        "Pt/mgg && Photon pT > 100 (%)": [],
        "All Leptons": []
        }

count = 0
for files_ in Hist:
    inFileName = files_
    print "Reading from", inFileName

    inFileNameSplit = inFileName.split("_")
    if len(inFileNameSplit) == 1:
        Title = inFileName.replace(".root", "")
    else:
        Title = inFileName.split("_")[-1].replace(".root", "")
    info["SampleName"].append(Title)
    inFile = ROOT.TFile.Open(inFileName, "READ")

    # print("Number of bins: {}".format(inFile.GetXaxis().GetNbinsX()))

    h1 = inFile.Get("totalCutFlow_SL")
    h1.SetTitle(Title)
    h1.GetYaxis().SetTitle("Number of events")

    c1 = ROOT.TCanvas()
    h1.Draw("TEXT")
    # c1.SaveAs(inFileName.replace(".root", ".pdf"))
    c1.SaveAs(plotDir+"/"+inFileName.replace(".root", ".pdf"))

    print("Number of bins: {}".format(h1.GetNbinsX()))
    for x in range(h1.GetNbinsX()):
        if h1.GetXaxis().GetBinLabel(x + 1) not in info:
            continue
        info[h1.GetXaxis().GetBinLabel(x + 1)].append(int(h1.GetBinContent(x + 1)))

    info["DiPhoton (%)"].append(round((float(info["Photon Selection"][count]) / info["MC Gen"][count]) * 100.0,2))
    info["Exactly 1 lepton(%)"].append(round((float(info["Lepton Selection"][count]) / info["MC Gen"][count]) * 100.0,2))
    info["1Jet Category(%)"].append(round((float(info["nAK8_W >= 1"][count]) / info["MC Gen"][count]) * 100.0,2))
    info["2Jet Category(%)"].append(round((float(info["nAK4 >= 2"][count]) / info["MC Gen"][count]) * 100.0,2))
    info["All cat jets(%)"].append(round((float(info["1Jet+2Jet"][count]) / info["MC Gen"][count]) * 100.0,2))
    info["Pt/mgg && Photon pT > 100 (%)"].append(round((float(info["pT(#gamma #gamma)>100"][count]) / info["MC Gen"][count]) * 100.0,2))    
    
    # info["GEN_Match_photon(%) before"].append(round((float(info["GEN_Match photon before"][count]) / info["MC Gen"][count]) * 100.0,2))
    # info["GEN_Match_photon(%) after"].append(round((float(info["GEN_Match photon after"][count]) / info["MC Gen"][count]) * 100.0,2))


    count += 1

print("\n\n\n")

# creating a Dataframe object
df = pd.DataFrame(info)

# print(df)

print("\n\n\n")

df = df.T
# print(df)

print("\n\n\n")
# df = df.reindex([5, 8, 6, 3, 2, 7, 0, 1, 4, 9])
# print(df)

# df = df.reindex(["SampleName", "MC Gen", "Trigger", "Photon Selection", "Lepton Selection", "nAK8H=0 & nAK8W=0 & nAK4>=4", "1Jet+2Jet", "pT/mgg cut", "pT(#gamma #gamma)>100", "DiPhoton (%)", "1Jet Category(%)", "All cat jets(%)", "Pt/mgg && Photon pT > 100 (%)"])
# df = df.reindex(["SampleName", "MC Gen", "Trigger", "Photon Selection", "Lepton Selection", "nAK8H=0 & nAK8W=0 & nAK4>=4", "1Jet+2Jet", "DiPhoton (%)", "1Jet Category(%)", "All cat jets(%)"])
df = df.reindex(["SampleName", "MC Gen", "Trigger", "Photon Selection", 
"All Leptons",
"Mu before cut","Mu after cut","Ele before cut","Ele after cut","Lepton Selection", 
"nAK8_W >= 1", "nAK4 >= 2", "1Jet+2Jet", "DiPhoton (%)", "Exactly 1 lepton(%)", "1Jet Category(%)", 
"2Jet Category(%)", "All cat jets(%)"
])

print(df)

df.to_csv(plotDir + "/test.csv")

os.system('cat '+ plotDir+ '/test.csv')

# df = pd.DataFrame(columns=info["SampleName"],dtype="string")
# df.loc[0] = info["MC Gen"]
# df.loc[1] = info["Trigger"]
# df.loc[2] = info["Photon Selection"]
# df.loc[3] = info["Lepton Selection"]
# df.loc[4] = info["nAK8H=0 & nAK8W=0 & nAK4>=4"]
# df.loc[5] = info["pT(#gamma #gamma)>100"]
# df.loc[6] = info["DiPhoton (%)"]
# df.loc[7] = info["1Jet Category(%)"]
# df.loc[8] = info["Pt/mgg && Photon pT > 100 (%)"]
# df.loc[0] = info["MC Gen"]
# print(df)

