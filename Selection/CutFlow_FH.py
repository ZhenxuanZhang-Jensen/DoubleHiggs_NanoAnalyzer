import pandas as pd
import ROOT
import os

ROOT.gROOT.SetBatch(True)

plotDir = "CutFlowTables_FH"
if not os.path.isdir(plotDir):
    os.makedirs(plotDir)

Hist = [
        "/eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G4Q_M300.root",
        "/eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G4Q_M1000.root",
        "/eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G4Q_M3000.root",

        # "GluGluToRadionToHHTo2G4Q_M250.root",
        # "GluGluToRadionToHHTo2G4Q_M260.root",
        # "GluGluToRadionToHHTo2G4Q_M270.root",
        # "GluGluToRadionToHHTo2G4Q_M280.root",
        # "GluGluToRadionToHHTo2G4Q_M300.root",
        # "GluGluToRadionToHHTo2G4Q_M320.root",
        # "GluGluToRadionToHHTo2G4Q_M350.root",
        # "GluGluToRadionToHHTo2G4Q_M400.root",
        # "GluGluToRadionToHHTo2G4Q_M450.root",
        # "GluGluToRadionToHHTo2G4Q_M500.root",
        # "GluGluToRadionToHHTo2G4Q_M550.root",
        # "GluGluToRadionToHHTo2G4Q_M600.root",
        # "GluGluToRadionToHHTo2G4Q_M650.root",
        # "GluGluToRadionToHHTo2G4Q_M700.root",
        # "GluGluToRadionToHHTo2G4Q_M750.root",
        # "GluGluToRadionToHHTo2G4Q_M800.root",
        # "GluGluToRadionToHHTo2G4Q_M850.root",
        # "GluGluToRadionToHHTo2G4Q_M900.root",
        # "GluGluToRadionToHHTo2G4Q_M1000.root",
        # "GluGluToRadionToHHTo2G4Q_M1250.root",
        # "GluGluToRadionToHHTo2G4Q_M1500.root",
        # "GluGluToRadionToHHTo2G4Q_M1750.root",
        # "GluGluToRadionToHHTo2G4Q_M2000.root",
        # "GluGluToRadionToHHTo2G4Q_M2500.root",
        # "GluGluToRadionToHHTo2G4Q_M3000.root",
        # "GluGluToHHTo2G4Q_node-cHHH0.root",
        # "GluGluToHHTo2G4Q_node-cHHH1.root",
        # "GluGluToHHTo2G4Q_node-cHHH2p45.root",
        # "GluGluToHHTo2G4Q_node-cHHH5.root"

        ]

info = {"SampleName": [],
        "MC Gen": [],
        "Trigger": [],
        "Photon Selection": [],
        "Lepton Selection": [],
        "nAK8_Higgs >= 1": [],
        "nAK8H=0 & nAK8_W >= 2": [],
        "nAK8H=0 & nAK8_W>=1 & nAK4>=2": [],
        "nAK8H=0 & nAK8_W=1 & nAK4>=2": [],
        "nAK8H=0 & nAK8W=0 & nAK4>=4": [],
        "1Jet2Jet3Jet4Jet": [],
        "pT/mgg cut": [],
        "pT(#gamma #gamma)>100": [],
        "DiPhoton (%)": [],
        "1Jet Category(%)": [],
        "2Jet Category(%)": [],
        "3Jet Category(in)(%)": [],
        "3Jet Category(%)": [],
        "4Jet Category(%)": [],
        "All cat jets(%)": [],
        "Pt/mgg && Photon pT > 100 (%)": []
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

    h1 = inFile.Get("totalCutFlow_FH")
    h1.SetTitle(Title)
    h1.GetYaxis().SetTitle("Number of events")

    c1 = ROOT.TCanvas()
    h1.Draw("TEXT")
    c1.SaveAs(plotDir+"/"+inFileName.replace(".root", ".pdf"))

    print("Number of bins: {}".format(h1.GetNbinsX()))
    for x in range(h1.GetNbinsX()):
        # print("x: {}".format(x+1))
        # print('Bin content of bin {} is {} and the label is "{}"'.format(x+1,h1.GetBinContent(x+1),h1.GetXaxis().GetBinLabel(x+1)))
        if h1.GetXaxis().GetBinLabel(x + 1) not in info:
            continue
        info[h1.GetXaxis().GetBinLabel(x + 1)].append(int(h1.GetBinContent(x + 1)))
 
    info["DiPhoton (%)"].append(round((float(info["Photon Selection"][count]) / info["MC Gen"][count]) * 100.0,2))
    # print("test: ",info["nAK8H=0 & nAK8W=0 & nAK4>=4"][count])
    # print("test: ",info["MC Gen"][count])
    info["1Jet Category(%)"].append(round((float(info["nAK8_Higgs >= 1"][count]) / info["MC Gen"][count]) * 100.0,2))
    info["2Jet Category(%)"].append(round((float(info["nAK8H=0 & nAK8_W >= 2"][count]) / info["MC Gen"][count]) * 100.0,2))
    info["3Jet Category(in)(%)"].append(round((float(info["nAK8H=0 & nAK8_W>=1 & nAK4>=2"][count]) / info["MC Gen"][count]) * 100.0,2))
    info["3Jet Category(%)"].append(round((float(info["nAK8H=0 & nAK8_W=1 & nAK4>=2"][count]) / info["MC Gen"][count]) * 100.0,2))
    info["4Jet Category(%)"].append(round((float(info["nAK8H=0 & nAK8W=0 & nAK4>=4"][count]) / info["MC Gen"][count]) * 100.0,2))
    info["All cat jets(%)"].append(round((float(info["1Jet2Jet3Jet4Jet"][count]) / info["MC Gen"][count]) * 100.0,2))
    info["Pt/mgg && Photon pT > 100 (%)"].append(round((float(info["pT(#gamma #gamma)>100"][count]) / info["MC Gen"][count]) * 100.0,2))

    count += 1

print("\n\n\n")
# print "| SampleName |",'|'.join(str(e) for e in info["SampleName"])
# for x in range(len(info["SampleName"])+1):
#     # print "x: ",x
#     print "|--- ",
# print "\nMC Gen |",'|'.join(str(e) for e in info["MC Gen"])
# print "Trigger |",'|'.join(str(e) for e in info["Trigger"])
# print "Photon Selection |",'|'.join(str(e) for e in info["Photon Selection"])
# print "Lepton Selection |",'|'.join(str(e) for e in info["Lepton Selection"])
# print "nAK8H=0 & nAK8W=0 & nAK4>=4",'|'.join(str(e) for e in info["nAK8H=0 & nAK8W=0 & nAK4>=4"])
# print "pT/mgg cut |",'|'.join(str(e) for e in info["pT/mgg cut"])
# print "pT(#gamma #gamma)>100 |",'|'.join(str(e) for e in info["pT(#gamma #gamma)>100"])
# print "DiPhoton (%) |",'|'.join(str(float("{:.2f}".format(e))) for e in info["DiPhoton (%)"])
# print "1Jet Category |",'|'.join(str(float("{:.2f}".format(e))) for e in info["1Jet Category"])
# print "Pt/mgg && Photon pT > 100 (%) |",'|'.join(str(float("{:.2f}".format(e))) for e in info["Pt/mgg && Photon pT > 100 (%)"])


# creating a Dataframe object
df = pd.DataFrame(info)

# print(df)

print("\n\n\n")

df = df.T
# print(df)

print("\n\n\n")
# df = df.reindex([5, 8, 6, 3, 2, 7, 0, 1, 4, 9])
# print(df)

# df = df.reindex(["SampleName", "MC Gen", "Trigger", "Photon Selection", "Lepton Selection", "nAK8H=0 & nAK8W=0 & nAK4>=4", "1Jet2Jet3Jet4Jet", "pT/mgg cut", "pT(#gamma #gamma)>100", "DiPhoton (%)", "1Jet Category", "All cat jets(%)", "Pt/mgg && Photon pT > 100 (%)"])
# df = df.reindex(["SampleName", "MC Gen", "Trigger", "Photon Selection", "Lepton Selection", "nAK8H=0 & nAK8W=0 & nAK4>=4", "1Jet2Jet3Jet4Jet", "DiPhoton (%)", "1Jet Category", "All cat jets(%)"])
df = df.reindex(["SampleName", "MC Gen", "Trigger", "Photon Selection", "Lepton Selection", "nAK8_Higgs >= 1", "nAK8H=0 & nAK8_W >= 2", "nAK8H=0 & nAK8_W>=1 & nAK4>=2", "nAK8H=0 & nAK8_W=1 & nAK4>=2", "nAK8H=0 & nAK8W=0 & nAK4>=4", "1Jet2Jet3Jet4Jet", "DiPhoton (%)", "1Jet Category(%)", "2Jet Category(%)", "3Jet Category(in)(%)", "3Jet Category(%)", "4Jet Category(%)", "All cat jets(%)"])
# df = df.reindex(["SampleName", "MC Gen", "Trigger", "Photon Selection", "Lepton Selection", "DiPhoton (%)", "1Jet Category(%)", "2Jet Category(%)", "3Jet Category(in)(%)", "3Jet Category(%)", "4Jet Category(%)", "All cat jets(%)"])

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
# df.loc[7] = info["1Jet Category"]
# df.loc[8] = info["Pt/mgg && Photon pT > 100 (%)"]
# df.loc[0] = info["MC Gen"]
# print(df)
