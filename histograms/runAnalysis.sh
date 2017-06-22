#!bin/sh

./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC.conf WW_13TeV-pythia8 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC.conf WZ_13TeV-pythia8 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_W.conf WJetsToLNu_13TeV-madgraphMLM 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC.conf ZZ_13TeV-pythia8 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC.conf ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powheg 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC.conf ST_t-channel_top_4f_inclusiveDecays_13TeV-powheg 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC.conf ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC.conf ST_tW_top_5f_inclusiveDecays_13TeV-powheg 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_TT.conf TT_13TeV-powheg-pythia8 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZTT.conf DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZTT 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZTT.conf DYJetsToLL_M-50_13TeV-madgraphMLM_ZTT 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZLL.conf DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZLL 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZLL.conf DYJetsToLL_M-50_13TeV-madgraphMLM_ZLL 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC.conf QCD_Pt-20toInf_MuEnrichedPt20_13TeV_noTrig 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DATA.conf SingleMuon_Run2016 20 &

# Estimate same sign region for QCD background
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DATA_SS.conf SingleMuon_Run2016_SS 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS.conf WW_13TeV-pythia8_SS 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS.conf WZ_13TeV-pythia8_SS 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_W_SS.conf WJetsToLNu_13TeV-madgraphMLM_SS 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS.conf ZZ_13TeV-pythia8_SS 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS.conf ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powheg_SS 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS.conf ST_t-channel_top_4f_inclusiveDecays_13TeV-powheg_SS 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS.conf ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg_SS 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS.conf ST_tW_top_5f_inclusiveDecays_13TeV-powheg_SS 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_TT_SS.conf TT_13TeV-powheg-pythia8_SS 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZTT_SS.conf DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZTT_SS 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZTT_SS.conf DYJetsToLL_M-50_13TeV-madgraphMLM_ZTT_SS 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZLL_SS.conf DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZLL_SS 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZLL_SS.conf DYJetsToLL_M-50_13TeV-madgraphMLM_ZLL_SS 20 &
