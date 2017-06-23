#!bin/sh

uncertainty="zPtUp"
sed -e 's/ZPtReweighting = 0/ZPtReweighting = 1/g' analysisMacro_ztt_DY_ZTT.conf > analysisMacro_ztt_DY_ZTT_${uncertainty}.conf
sed -e 's/ZPtReweighting = 0/ZPtReweighting = 1/g' analysisMacro_ztt_DY_ZLL.conf > analysisMacro_ztt_DY_ZLL_${uncertainty}.conf
cp DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZTT DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZTT_${uncertainty}
cp DYJetsToLL_M-50_13TeV-madgraphMLM_ZTT DYJetsToLL_M-50_13TeV-madgraphMLM_ZTT_${uncertainty}
cp DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZTT DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZLL_${uncertainty}
cp DYJetsToLL_M-50_13TeV-madgraphMLM_ZTT DYJetsToLL_M-50_13TeV-madgraphMLM_ZLL_${uncertainty}
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZTT_${uncertainty}.conf DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZTT_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZTT_${uncertainty}.conf DYJetsToLL_M-50_13TeV-madgraphMLM_ZTT_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZLL_${uncertainty}.conf DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZLL_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZLL_${uncertainty}.conf DYJetsToLL_M-50_13TeV-madgraphMLM_ZLL_${uncertainty} 20 &

uncertainty="zPtDown"
sed -e 's/ZPtReweighting = 0/ZPtReweighting = -1/g' analysisMacro_ztt_DY_ZTT.conf > analysisMacro_ztt_DY_ZTT_${uncertainty}.conf
sed -e 's/ZPtReweighting = 0/ZPtReweighting = -1/g' analysisMacro_ztt_DY_ZLL.conf > analysisMacro_ztt_DY_ZLL_${uncertainty}.conf
cp DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZTT DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZTT_${uncertainty}
cp DYJetsToLL_M-50_13TeV-madgraphMLM_ZTT DYJetsToLL_M-50_13TeV-madgraphMLM_ZTT_${uncertainty}
cp DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZTT DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZLL_${uncertainty}
cp DYJetsToLL_M-50_13TeV-madgraphMLM_ZTT DYJetsToLL_M-50_13TeV-madgraphMLM_ZLL_${uncertainty}
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZTT_${uncertainty}.conf DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZTT_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZTT_${uncertainty}.conf DYJetsToLL_M-50_13TeV-madgraphMLM_ZTT_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZLL_${uncertainty}.conf DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZLL_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZLL_${uncertainty}.conf DYJetsToLL_M-50_13TeV-madgraphMLM_ZLL_${uncertainty} 20 &


