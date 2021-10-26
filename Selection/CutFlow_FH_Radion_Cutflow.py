import pandas as pd
import ROOT
import os

ROOT.gROOT.SetBatch(True)

plotDir = "Radion_Cutflow"
if not os.path.isdir(plotDir):
    os.makedirs(plotDir)

Hist = [
        "/eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G4Q_M250.root",
        "/eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G4Q_M500.root",
        "/eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G4Q_M1000.root",
        "/eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G4Q_M2000.root",
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
        # "GluGluToRadionToHHTo2G4Q_M2500.root",
        # "GluGluToRadionToHHTo2G4Q_M3000.root",
        # "GluGluToHHTo2G4Q_node-cHHH0.root",
        # "GluGluToHHTo2G4Q_node-cHHH1.root",
        # "GluGluToHHTo2G4Q_node-cHHH2p45.root",
        # "GluGluToHHTo2G4Q_node-cHHH5.root"

        ]

info = {"SampleName": [],
        "MC GEN": [],
        "| |eta1| - |eta2| | < 0.1":[],
        "| |eta1| - |eta2| | < 0.5":[],
        "| |eta1| - |eta2| | < 1":[],  
        "| p1 - p2 | < 10":[],        
        "| p1 - p2 | < 50":[],         
        "| p1 - p2 | < 100":[],        
        "| p1 - p2 | < 200":[] 
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

    h1 = inFile.Get("Radion_Cutflow")
    h1.SetTitle(Title)
    h1.GetYaxis().SetTitle("Number of events")

    print("Number of bins: {}".format(h1.GetNbinsX()))
    for x in range(h1.GetNbinsX()):
        # print("x: {}".format(x+1))
        # print('Bin content of bin {} is {} and the label is "{}"'.format(x+1,h1.GetBinContent(x+1),h1.GetXaxis().GetBinLabel(x+1)))
        if h1.GetXaxis().GetBinLabel(x + 1) not in info:
            continue
        info[h1.GetXaxis().GetBinLabel(x + 1)].append(int(h1.GetBinContent(x + 1)))

    

print("\n")


# creating a Dataframe object
df = pd.DataFrame(info)

# print(df)

print("\n\n\n")

df = df.T
print(df)
