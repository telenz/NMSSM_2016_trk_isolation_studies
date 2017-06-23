# NMSSM_2016_trk_isolation_studies
scripts to evaluate data-mc differences of track isolation for NMSSM analysis (2016 data)

##########################################
#### To run the analysis and make the histograms for all sample you need to run
#### Before you will need to take care that all filelists are available in the histogram folder
cd histograms 
source runAnalysis 

#### To run the analysis for the several systematic unceratinies:
source runAnalysis_jesSys.sh 
source runAnalysis_uesSys.sh 
source runAnalysis_topPtSys.sh 
source runAnalysis_zPtSys.sh 

#### In order to check if jobs failed and in this case resubmit:
source resubmit 

#### To add all single root files to one together
source hadd 

##########################################
#### To make some prefit plots (ad-hoc systematic uncertainties are included)
cd plotting 
source makePlots.sh 

##########################################
#### To make templates, datacards and the final evaluation of the datacards to extract the scale factors
cd datacards 
source runProducersAndCombine.sh 

### To plot and fit all scale factors (you need to add them by hand to the script):
root -l -b -q plotAndFitScaleFactors.C 