#include "../plotting/HtoH.h"
#include "TFile.h"
#include "TColor.h"
#include "THStack.h"
#include <iostream>

using namespace std;

void TemplateProducer(TString histName = "invMassMuTrkH", TString ptRange = "2p5to5", TString sys="") {

  TString dir("../histograms/");
  TH1::SetDefaultSumw2();

  TFile * file = new TFile(dir+"SingleMuon_Run2016.root");
  
  TString samples[30] = {"WW_13TeV-pythia8", // (0)
			 "WZ_13TeV-pythia8", // (1) 
			 "ZZ_13TeV-pythia8", // (2)
			 "WJetsToLNu_13TeV-madgraphMLM", // (3)
			 "ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powheg", // (4)
			 "ST_t-channel_top_4f_inclusiveDecays_13TeV-powheg",     // (5)
			 "ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg",     // (6)
			 "ST_tW_top_5f_inclusiveDecays_13TeV-powheg",         // (7)
			 "TT_13TeV-powheg-pythia8",               // (8)
			 "DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZLL", // (9)
			 "DYJetsToLL_M-50_13TeV-madgraphMLM_ZLL",     // (10)
			 "SingleMuon_Run2016_SS",//"QCD_Pt-20toInf_MuEnrichedPt15_13TeV_noTrig",   // (11)
			 "DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZTT", // (12)
			 "DYJetsToLL_M-50_13TeV-madgraphMLM_ZTT",     // (13)
			 "WW_13TeV-pythia8_SS", // (14)
			 "WZ_13TeV-pythia8_SS", // (15) 
			 "ZZ_13TeV-pythia8_SS", // (16)
			 "WJetsToLNu_13TeV-madgraphMLM_SS", // (17)
			 "ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powheg_SS", // (18)
			 "ST_t-channel_top_4f_inclusiveDecays_13TeV-powheg_SS",     // (19)
			 "ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg_SS",     // (20)
			 "ST_tW_top_5f_inclusiveDecays_13TeV-powheg_SS",         // (21)
			 "TT_13TeV-powheg-pythia8_SS",               // (22)
			 "DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZLL_SS", // (23)
			 "DYJetsToLL_M-50_13TeV-madgraphMLM_ZLL_SS",     // (24)
			 "DYJetsToLL_M-10to50_13TeV-madgraphMLM_ZTT_SS", // (25)
			 "DYJetsToLL_M-50_13TeV-madgraphMLM_ZTT_SS"     // (26)
  };

  float xsec[30] = {115.0,   // WW (0)
		    47.13,   // WZ (1)
		    16.52,   // ZZ (2)
		    61526.7, // WJets (3)
		    80.95,   // ST_t-channel_antitop (4)
	            136.95,  // ST_t-channel_top     (5)
		    35.6,    // ST_tW_antitop        (6)
		    35.6,    // ST_tW_top            (7)
		    831.8,   // TTbar (8)
		    18610,   // DYJetsToLL_M-10to50 (9)
		    5765,    // DYJetsToLL_M-50     (10)
		    1.,//720648000 * 0.00042/2., // QCD    (11)
		    18610,   // DYJetsToLL_M-10to50 (12)
		    5765,    // DYJetsToLL_M-50     (13)
		    115.0,   // WW (14)
		    47.13,   // WZ (15)
		    16.52,   // ZZ (16)
		    61526.7, // WJets (17)
		    80.95,   // ST_t-channel_antitop (18)
	            136.95,  // ST_t-channel_top     (19)
		    35.6,    // ST_tW_antitop        (20)
		    35.6,    // ST_tW_top            (21)
		    831.8,   // TTbar (22)
		    18610,   // DYJetsToLL_M-10to50 (23)
		    5765,    // DYJetsToLL_M-50     (24)
		    18610,   // DYJetsToLL_M-10to50 (25)
		    5765    // DYJetsToLL_M-50     (26)
  };


  // Run2016 : 35890;
  float lumi = 35890;
  TH1D * histDataOld = (TH1D*)file->Get(histName + "_" + ptRange);

  int nBins  = histDataOld->GetNbinsX();
  float xMin = histDataOld->GetBinLowEdge(1);
  float xMax = histDataOld->GetBinLowEdge(nBins+1);

  const int nBinsNew = 20;
  float bins[nBinsNew+1] = {0 , 10 , 20 , 30 , 40 , 50 , 60 , 70 , 80 , 90 , 100 , 110 , 120 , 130 , 140 , 150 , 160 , 170 , 180 , 190 , 200};
  
  TH1D * dataHist = new TH1D("data_obs","",nBinsNew,bins);
  TH1D * hist = TH1DtoTH1D(histDataOld,nBinsNew,bins,true,"_new_Data");
  dataHist->Add(hist);

  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // Add backgounds to groups and scale them according lumi etc.
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  TH1D * ewkHist = new TH1D("ewk","",nBinsNew,bins);
  TH1D * ttHist  = new TH1D("tt", "",nBinsNew,bins);
  TH1D * qcdHist = new TH1D("qcd","",nBinsNew,bins);
  TH1D * zHist   = new TH1D("z",  "",nBinsNew,bins);
  TH1D * zttHist = new TH1D("ztt",  "",nBinsNew,bins);
  TH1D * ssHist  = new TH1D("ssHist",  "",nBinsNew,bins);

  int nSamples = 14;

  for (int iS=0; iS<nSamples; ++iS) {

    TFile * fileMC = 0 ;
    if(sys.Contains("_topPt") && (iS<4 || iS>8) ) continue;
    if(sys.Contains("_zPt") && iS!=9 && iS!=10&& iS!=12 && iS!=13 ) continue;
 
    if(sys.Contains("_topPt") && iS==8)      fileMC = new TFile(dir+"/"+samples[iS]+sys+".root");
    else if(sys.Contains("_topPt") && iS!=8) fileMC = new TFile(dir+"/"+samples[iS]+".root");
    else fileMC = new TFile(dir+"/"+samples[iS]+sys+".root");

    TH1D * histOld = (TH1D*)fileMC->Get(histName + "_" + ptRange);
    TH1D * hist = TH1DtoTH1D(histOld,nBinsNew,bins,true,"_new_"+samples[iS]);
    TH1D * eventCount = (TH1D*)fileMC->Get("histWeightsH");
    float nGen = eventCount->GetSumOfWeights();
    float norm = xsec[iS]*lumi/nGen;
    //std::cout << "Sample = " << iS << "  entries = " << hist->GetSumOfWeights() << std::endl;

    TH1D * tempHist = ewkHist;
    if (iS>3&&iS<9)       tempHist = ttHist;
    if (iS==9||iS==10)    tempHist = zHist;
    if (iS==11){          tempHist = qcdHist;norm=1.0;}
    if (iS==12 || iS==13) tempHist = zttHist;
    tempHist->Add(tempHist,hist,1.,norm);
  }

  // Add all SS background and subtract them from data_SS
  for (int iS=14; iS<27; ++iS) {

    if(sys.Contains("_topPt") || sys.Contains("_zPt") ) continue;

    TFile * fileMC = new TFile(dir+"/"+samples[iS]+sys+".root");
    TH1D * histOld = (TH1D*)fileMC->Get(histName + "_" + ptRange);
    TH1D * hist = TH1DtoTH1D(histOld,nBinsNew,bins,true,"_new_"+samples[iS]);
    TH1D * eventCount = (TH1D*)fileMC->Get("histWeightsH");
    float nGen = eventCount->GetSumOfWeights();
    float norm = xsec[iS]*lumi/nGen;
    //std::cout << "Sample = " << iS << "  entries = " << hist->GetSumOfWeights() << std::endl;
    ssHist->Add(ssHist,hist,1.,norm);
  }

  qcdHist->Add(ssHist,-1);  

  std::cout << "QCD   : " << qcdHist->GetSumOfWeights() << std::endl;
  std::cout << "EWK   : " << ewkHist->GetSumOfWeights() << std::endl;
  std::cout << "TTJ   : " << ttHist->GetSumOfWeights()  << std::endl;
  std::cout << "DY    : " << zHist->GetSumOfWeights()   << std::endl;
  std::cout << "ZTT   : " << zttHist->GetSumOfWeights() << std::endl << std::endl;


  TFile *outFile = new TFile("templates_trk_isolation_"+ptRange+sys+".root","RECREATE");
  outFile->cd();
  if(!sys.Contains("_topPt") && !sys.Contains("_zPt")) qcdHist->Write();
  if(!sys.Contains("_topPt") && !sys.Contains("_zPt")) ewkHist->Write();
  if(!sys.Contains("_zPt"))   ttHist->Write();
  if(!sys.Contains("_topPt")) zHist->Write();
  if(!sys.Contains("_topPt")) zttHist->Write();
  if(!sys.Contains("_topPt") && !sys.Contains("_zPt")) dataHist->Write();
  outFile->Close();
  delete outFile;

}
