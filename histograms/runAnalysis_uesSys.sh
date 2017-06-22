#!bin/sh

uncertainty="uesUp"

# Make config files 
for file in $(find -maxdepth 1 -type f -name "*.conf")
do 
    if [[ $file == *"Down"* ]]; then
	continue
    fi
    if [[ $file == *"Up"* ]]; then
	continue
    fi
    filename=${file:0:${#file}-5}
    sed -e 's/UnclusteredES = 0/UnclusteredES = 1/g' ${file} > ${filename}_${uncertainty}.conf
done

# Make sample files
for file in $(find -maxdepth 1 -type f -name "*")
do 
    if [[ $file == *".conf"* ]]; then
	continue
    fi
    if [[ $file == *".root"* ]]; then
	continue
    fi
    if [[ $file == *".sh"* ]]; then
	continue
    fi
    if [[ $file == *"~"* ]]; then
	continue
    fi
    if [[ $file == *"Down"* ]]; then
	continue
    fi
    if [[ $file == *"Up"* ]]; then
	continue
    fi
    echo ${file}
    cp ${file} ${file}_${uncertainty}
done


./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_${uncertainty}.conf WW_13TeV-pythia8_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_${uncertainty}.conf WZ_13TeV-pythia8_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_W_${uncertainty}.conf WJetsToLNu_13TeV-madgraphMLM_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_${uncertainty}.conf ZZ_13TeV-pythia8_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_${uncertainty}.conf ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powheg_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_${uncertainty}.conf ST_t-channel_top_4f_inclusiveDecays_13TeV-powheg_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_${uncertainty}.conf ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_${uncertainty}.conf ST_tW_top_5f_inclusiveDecays_13TeV-powheg_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_TT_${uncertainty}.conf TT_13TeV-powheg-pythia8_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZTT_${uncertainty}.conf DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZTT_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZTT_${uncertainty}.conf DYJetsToLL_M-50_13TeV-madgraphMLM_ZTT_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZLL_${uncertainty}.conf DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZLL_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZLL_${uncertainty}.conf DYJetsToLL_M-50_13TeV-madgraphMLM_ZLL_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_${uncertainty}.conf QCD_Pt-20toInf_MuEnrichedPt20_13TeV_noTrig_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DATA_${uncertainty}.conf SingleMuon_Run2016_${uncertainty} 20 &

# Estimate same sign region for QCD background
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DATA_SS_${uncertainty}.conf SingleMuon_Run2016_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS_${uncertainty}.conf WW_13TeV-pythia8_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS_${uncertainty}.conf WZ_13TeV-pythia8_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_W_SS_${uncertainty}.conf WJetsToLNu_13TeV-madgraphMLM_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS_${uncertainty}.conf ZZ_13TeV-pythia8_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS_${uncertainty}.conf ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powheg_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS_${uncertainty}.conf ST_t-channel_top_4f_inclusiveDecays_13TeV-powheg_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS_${uncertainty}.conf ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS_${uncertainty}.conf ST_tW_top_5f_inclusiveDecays_13TeV-powheg_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_TT_SS_${uncertainty}.conf TT_13TeV-powheg-pythia8_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZTT_SS_${uncertainty}.conf DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZTT_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZTT_SS_${uncertainty}.conf DYJetsToLL_M-50_13TeV-madgraphMLM_ZTT_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZLL_SS_${uncertainty}.conf DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZLL_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZLL_SS_${uncertainty}.conf DYJetsToLL_M-50_13TeV-madgraphMLM_ZLL_SS_${uncertainty} 20 &


############################################################################################################################################################
uncertainty="uesDown"

# Make config files 
for file in $(find -maxdepth 1 -type f -name "*.conf")
do 
    if [[ $file == *"Down"* ]]; then
	continue
    fi
    if [[ $file == *"Up"* ]]; then
	continue
    fi
    filename=${file:0:${#file}-5}
    sed -e 's/UnclusteredES = 0/UnclusteredES = -1/g' ${file} > ${filename}_${uncertainty}.conf
done

# Make sample files
for file in $(find -maxdepth 1 -type f -name "*")
do 
    if [[ $file == *".conf"* ]]; then
	continue
    fi
    if [[ $file == *".root"* ]]; then
	continue
    fi
    if [[ $file == *".sh"* ]]; then
	continue
    fi
    if [[ $file == *"~"* ]]; then
	continue
    fi
    if [[ $file == *"Down"* ]]; then
	continue
    fi
    if [[ $file == *"Up"* ]]; then
	continue
    fi
    echo ${file}
    cp ${file} ${file}_${uncertainty}
done


./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_${uncertainty}.conf WW_13TeV-pythia8_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_${uncertainty}.conf WZ_13TeV-pythia8_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_W_${uncertainty}.conf WJetsToLNu_13TeV-madgraphMLM_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_${uncertainty}.conf ZZ_13TeV-pythia8_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_${uncertainty}.conf ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powheg_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_${uncertainty}.conf ST_t-channel_top_4f_inclusiveDecays_13TeV-powheg_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_${uncertainty}.conf ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_${uncertainty}.conf ST_tW_top_5f_inclusiveDecays_13TeV-powheg_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_TT_${uncertainty}.conf TT_13TeV-powheg-pythia8_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZTT_${uncertainty}.conf DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZTT_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZTT_${uncertainty}.conf DYJetsToLL_M-50_13TeV-madgraphMLM_ZTT_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZLL_${uncertainty}.conf DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZLL_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZLL_${uncertainty}.conf DYJetsToLL_M-50_13TeV-madgraphMLM_ZLL_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_${uncertainty}.conf QCD_Pt-20toInf_MuEnrichedPt20_13TeV_noTrig_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DATA_${uncertainty}.conf SingleMuon_Run2016_${uncertainty} 20 &

# Estimate same sign region for QCD background
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DATA_SS_${uncertainty}.conf SingleMuon_Run2016_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS_${uncertainty}.conf WW_13TeV-pythia8_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS_${uncertainty}.conf WZ_13TeV-pythia8_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_W_SS_${uncertainty}.conf WJetsToLNu_13TeV-madgraphMLM_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS_${uncertainty}.conf ZZ_13TeV-pythia8_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS_${uncertainty}.conf ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powheg_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS_${uncertainty}.conf ST_t-channel_top_4f_inclusiveDecays_13TeV-powheg_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS_${uncertainty}.conf ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_MC_SS_${uncertainty}.conf ST_tW_top_5f_inclusiveDecays_13TeV-powheg_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_TT_SS_${uncertainty}.conf TT_13TeV-powheg-pythia8_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZTT_SS_${uncertainty}.conf DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZTT_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZTT_SS_${uncertainty}.conf DYJetsToLL_M-50_13TeV-madgraphMLM_ZTT_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZLL_SS_${uncertainty}.conf DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZLL_SS_${uncertainty} 20 &
./qsub_seq.sh analysis_macro_ztt analysisMacro_ztt_DY_ZLL_SS_${uncertainty}.conf DYJetsToLL_M-50_13TeV-madgraphMLM_ZLL_SS_${uncertainty} 20 &


