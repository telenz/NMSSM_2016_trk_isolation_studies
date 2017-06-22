#!bin/sh

uncertainty="topPtUp"
sed -e 's/TopPtReweightingScale = 0/TopPtReweightingScale = 1/g' analysisMacro_ztt_TT.conf > analysisMacro_ztt_TT_${uncertainty}.conf
cp TT_13TeV-powheg-pythia8 TT_13TeV-powheg-pythia8_${uncertainty}
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_TT_${uncertainty}.conf TT_13TeV-powheg-pythia8_${uncertainty} 20 &

uncertainty="topPtDown"
sed -e 's/TopPtReweightingScale = 0/TopPtReweightingScale = -1/g' analysisMacro_ztt_TT.conf > analysisMacro_ztt_TT_${uncertainty}.conf
cp TT_13TeV-powheg-pythia8 TT_13TeV-powheg-pythia8_${uncertainty}
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_TT_${uncertainty}.conf TT_13TeV-powheg-pythia8_${uncertainty} 20 &


