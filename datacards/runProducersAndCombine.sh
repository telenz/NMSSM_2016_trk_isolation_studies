#!bin/bash

iniCMSSW_7_4_7

#ptBins=("2p5to5" "5to7p5" "7p5to10" "10to15" "15to20" "20toInf")
ptBins=("5to7p5" "7p5to10" "10to15" "15to20" "20toInf")

for i in "${ptBins[@]}"
do

    root -l -b -q TemplateProducer.C"(\"invMassMuTrkH\", \"${i}\", \"\")"
    root -l -b -q TemplateProducer.C"(\"invMassMuTrkH\", \"${i}\", \"_jesUp\")"
    root -l -b -q TemplateProducer.C"(\"invMassMuTrkH\", \"${i}\", \"_jesDown\")"
    root -l -b -q TemplateProducer.C"(\"invMassMuTrkH\", \"${i}\", \"_uesUp\")"
    root -l -b -q TemplateProducer.C"(\"invMassMuTrkH\", \"${i}\", \"_uesDown\")"
    root -l -b -q TemplateProducer.C"(\"invMassMuTrkH\", \"${i}\", \"_zPtUp\")"
    root -l -b -q TemplateProducer.C"(\"invMassMuTrkH\", \"${i}\", \"_zPtDown\")"
    root -l -b -q TemplateProducer.C"(\"invMassMuTrkH\", \"${i}\", \"_topPtUp\")"
    root -l -b -q TemplateProducer.C"(\"invMassMuTrkH\", \"${i}\", \"_topPtDown\")"

    root -l -b -q DatacardProducer.C"(\"${i}\")"

    combine -M MaxLikelihoodFit --plots --saveNormalizations --saveShapes --saveWithUncertainties --saveNLL --robustFit=1 --rMin=-2 --rMax=10 -m 81 datacard_${i}.txt -v2
    mv mlfit.root  mlfit_${i}.root
    root -l -b -q MakePostFitPlots.C"(\"${i}\")" 

done


# Get the results for r and other parameters:
# fit_s->Print() with open root file mlfit...root