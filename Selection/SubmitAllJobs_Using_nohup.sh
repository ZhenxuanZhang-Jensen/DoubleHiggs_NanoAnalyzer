WhichSamples=${1}

# if [ $# -eq 1 ]
#   then
#     echo "One arguments supplied"
#     WhichSamples=0
# fi

if [ ${WhichSamples} -eq 0 ]
  then
    echo "Running for SL-hadronic.."
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-1000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M1000.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M1000.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-250_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M250.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M250.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-3000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M3000.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M3000.log &
    # nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-1500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M1500.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M1500.log &
    # nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-2000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M2000.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M2000.log &
    # nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M500.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M500.log &
    # nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-2500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M2500.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M2500.log &
    # nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-800_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M800.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M800.log &
    ps -f
fi

if [ ${WhichSamples} -eq 1 ]
  then
    echo "Running for fully-hadronic.."
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-250_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt /eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G4Q_M250.root 1 2017  7 0 1 >& /eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G4Q_M250.log &
    # nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt /eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G4Q_M500.root 1 2017  7 0 1 >& /eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G4Q_M500.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt /eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G4Q_M1000.root 1 2017  7 0 1 >& /eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G4Q_M1000.log &
    # nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-2000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt /eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G4Q_M2000.root 1 2017  7 0 1 >& /eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G4Q_M2000.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-3000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt /eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G4Q_M3000.root 1 2017  7 0 1 >& /eos/user/z/zhenxuan/DoubleHiggs/MC_Root/GluGluToRadionToHHTo2G4Q_M3000.log &
    # nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-800_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M800.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M800.log &
    # nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M1500.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M1500.log &
    # nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-2500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M2500.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M2500.log &
    # nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH1_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH1.root 1 2017  7 0 1 >& GluGluToHHTo2G4Q_node-cHHH1.log &
    ps -f
fi

if [ ${WhichSamples} -eq 2 ]
  then
    echo "Running for all fully-hadronic samples..."
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-250_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M250.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M250.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-260_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M260.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M260.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-270_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M270.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M270.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-280_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M280.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M280.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-300_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M300.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M300.log &
    ps -f
    echo "To prevent too many background jobs, sleeping for 2 mins"
    sleep 2m
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-320_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M320.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M320.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-350_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M350.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M350.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-400_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M400.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M400.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-450_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M450.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M450.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M500.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M500.log &
    ps -f
    echo "To prevent too many background jobs, sleeping for 2 mins"
    sleep 2m
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-550_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M550.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M550.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-600_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M600.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M600.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-650_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M650.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M650.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-700_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M700.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M700.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-750_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M750.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M750.log &
    ps -f
    echo "To prevent too many background jobs, sleeping for 2 mins"
    sleep 2m
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-800_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M800.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M800.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-850_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M850.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M850.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-900_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M900.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M900.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M1000.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M1000.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1250_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M1250.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M1250.log &
    ps -f
    echo "To prevent too many background jobs, sleeping for 2 mins"
    sleep 2m
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M1500.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M1500.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1750_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M1750.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M1750.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-2000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M2000.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M2000.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-2500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M2500.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M2500.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-3000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M3000.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M3000.log &
    ps -f
    echo "To prevent too many background jobs, sleeping for 2 mins"
    sleep 2m
    echo "Running for SM fully-hadronic samples.."
    nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH0_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH0.root 1 2017 7 0 1 &> GluGluToHHTo2G4Q_node_cHHH0.log &
    nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH2p45_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH2p45.root 1 2017 7 0 1 &> GluGluToHHTo2G4Q_node_cHHH2p45.log &
    nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH1_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH1.root 1 2017 7 0 1 &> GluGluToHHTo2G4Q_node_cHHH1.log &
    nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH5_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH5.root 1 2017 7 0 1 &> GluGluToHHTo2G4Q_node_cHHH5.log &
    ps -f
    sleep 2m
    echo "Running for Data..."
    nohup Selection InputSampleTextFiles/DoubleEG_Run2017B.txt DoubleEG_Run2017B.root 0 2017 7 0 1 &> DoubleEG_Run2017B.log &
    nohup Selection InputSampleTextFiles/DoubleEG_Run2017C.txt DoubleEG_Run2017C.root 0 2017 7 0 1 &> DoubleEG_Run2017C.log &
    nohup Selection InputSampleTextFiles/DoubleEG_Run2017D.txt DoubleEG_Run2017D.root 0 2017 7 0 1 &> DoubleEG_Run2017D.log &
    nohup Selection InputSampleTextFiles/DoubleEG_Run2017E.txt DoubleEG_Run2017E.root 0 2017 7 0 1 &> DoubleEG_Run2017E.log &
    nohup Selection InputSampleTextFiles/DoubleEG_Run2017F.txt DoubleEG_Run2017F.root 0 2017 7 0 1 &> DoubleEG_Run2017F.log &
    ps -f
    echo "To prevent too many background jobs, sleeping for 2 mins"
    sleep 2m
    ps -f
fi

if [ ${WhichSamples} -eq 3 ]
  then
    echo "Running for SM fully-hadronic samples.."
    nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH0_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH0.root 1 2017 7 0 1 &> GluGluToHHTo2G4Q_node_cHHH0.log &
    nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH2p45_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH2p45.root 1 2017 7 0 1 &> GluGluToHHTo2G4Q_node_cHHH2p45.log &
    nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH1_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH1.root 1 2017 7 0 1 &> GluGluToHHTo2G4Q_node_cHHH1.log &
    nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH5_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH5.root 1 2017 7 0 1 &> GluGluToHHTo2G4Q_node_cHHH5.log &
    ps -f
fi

if [ ${WhichSamples} -eq 4 ]
  then
    echo "Running on data."
    nohup Selection InputSampleTextFiles/DoubleEG_Run2017B.txt DoubleEG_Run2017B.root 0 2017 7 0 1 &> DoubleEG_Run2017B.log &
    nohup Selection InputSampleTextFiles/DoubleEG_Run2017C.txt DoubleEG_Run2017C.root 0 2017 7 0 1 &> DoubleEG_Run2017C.log &
    nohup Selection InputSampleTextFiles/DoubleEG_Run2017D.txt DoubleEG_Run2017D.root 0 2017 7 0 1 &> DoubleEG_Run2017D.log &
    nohup Selection InputSampleTextFiles/DoubleEG_Run2017E.txt DoubleEG_Run2017E.root 0 2017 7 0 1 &> DoubleEG_Run2017E.log &
    nohup Selection InputSampleTextFiles/DoubleEG_Run2017F.txt DoubleEG_Run2017F.root 0 2017 7 0 1 &> DoubleEG_Run2017F.log &
    ps -f
fi

if [ ${WhichSamples} -eq 5 ]
  then
    echo "Running a test job.."
    # Selection InputSampleTextFiles/inputFiles.txt test.root 1 2017 7 0 1
    # xrdcp root://cms-xrd-global.cern.ch//store/mc/RunIIFall17NanoAODv7/GluGluToRadionToHHTo2G4Q_M-3000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8/NANOAODSIM/PU2017_12Apr2018_Nano02Apr2020_102X_mc2017_realistic_v8-v1/120000/DB64186F-0685-E445-ACF2-0C039BFD6301.root .
    Selection DB64186F-0685-E445-ACF2-0C039BFD6301.root test.root 1 2017 7 0 0
fi
# python CutFlow.py
