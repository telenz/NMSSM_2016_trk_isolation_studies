#include "CMS_lumi.C"
#include "HttStylesNew.cc"
#include "HtoH.h"
#include "TFile.h"
#include "TColor.h"
#include "THStack.h"

using namespace std;

void PlotSamplesRatio(TString histName = "ptLeadingMuH",
		      TString xtitle = "leading muon p_{T} p[GeV]",
		      TString ytitle = "Events",
		      int nBinsNew = 10,
		      float xLower = 0,
		      float xUpper = 149,
		      float yLower = 100,
		      bool logY = true,
		      bool drawLeg = true) {

  TString dir("../histograms/");

  float qcdScale = 0.45;
  bool showAcceptance = false;
  float signalXSec = 43.92 * 0.20;

  SetStyle();
  TH1::SetDefaultSumw2();

  TString sys = "";
  //TString sys = "_jesDown";

  TFile * file = new TFile(dir+"SingleMuon_Run2016" + sys + ".root");
  
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

  xsec[11] *= qcdScale;

  // Run2016 : 35890;
  float lumi = 35890;
  TH1D * histDataOld = (TH1D*)file->Get(histName);

  int nBins  = histDataOld->GetNbinsX();
  float xMin = histDataOld->GetBinLowEdge(1);
  float xMax = histDataOld->GetBinLowEdge(nBins+1);

  std::cout << std::endl;
  std::cout << "Histogram " << histName << " : " << "nbins = " << nBins
	    << " , min = " << xMin
	    << " , max = " << xMax << std::endl;
  std::cout << std::endl;

  float bins[300];
  if (nBins%nBinsNew!=0) { 
    std::cout << "new number of bins = " << nBinsNew << "  not multiple of " << nBins << std::endl;
    return;
  }
  float binWidth = (xMax-xMin)/float(nBinsNew);
  for (int iB=0; iB<=nBinsNew; ++iB)   bins[iB] = xMin + float(iB)*binWidth;
  
  TH1D * histData = TH1DtoTH1D(histDataOld,nBinsNew,bins,true,"_Data_new");

  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // Add backgounds to groups and scale them according lumi etc.
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  TH1D * ewkHist = new TH1D("ewkHist","",nBinsNew,bins);
  TH1D * ttHist  = new TH1D("ttHist", "",nBinsNew,bins);
  TH1D * qcdHist = new TH1D("qcdHist","",nBinsNew,bins);
  TH1D * zHist   = new TH1D("zHist",  "",nBinsNew,bins);
  TH1D * zttHist = new TH1D("zttHist",  "",nBinsNew,bins);
  TH1D * ssHist  = new TH1D("ssHist",  "",nBinsNew,bins);

  int nSamples = 14;

  for (int iS=0; iS<nSamples; ++iS) {
 
    TFile * fileMC = new TFile(dir+"/"+samples[iS]+sys+".root");
    TH1D * histOld = (TH1D*)fileMC->Get(histName);
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

  // Add all SS background and subtract them from data_SS (data-driven QCD estimation)
  for (int iS=14; iS<27; ++iS) {
    TFile * fileMC = new TFile(dir+"/"+samples[iS]+sys+".root");
    TH1D * histOld = (TH1D*)fileMC->Get(histName);
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

  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // Ad-hoc systematic uncertainties
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  float lumiSys = 0.03;
  float lepSys  = 0.02;

  float ttSys   = 0.07;
  float ewkSys  = 0.15;
  float qcdSys  = 0.10;
  float zSys    = 0.03;

  double addErr = 0;

  for(int iB=1; iB<=ttHist->GetNbinsX(); iB++){

    addErr =  ttHist->GetBinContent(iB)*ttSys;
    ttHist -> SetBinError(iB, sqrt( pow(ttHist->GetBinError(iB),2) + pow(addErr,2)) );
    addErr =  ttHist->GetBinContent(iB)*lumiSys;
    ttHist -> SetBinError(iB, sqrt( pow(ttHist->GetBinError(iB),2) + pow(addErr,2)) );
    addErr =  ttHist->GetBinContent(iB)*lepSys;
    ttHist -> SetBinError(iB, sqrt( pow(ttHist->GetBinError(iB),2) + pow(addErr,2)) );

    addErr =  ewkHist->GetBinContent(iB)*ewkSys;
    ewkHist -> SetBinError(iB, sqrt( pow(ewkHist->GetBinError(iB),2) + pow(addErr,2)) );
    addErr =  ewkHist->GetBinContent(iB)*lumiSys;
    ewkHist -> SetBinError(iB, sqrt( pow(ewkHist->GetBinError(iB),2) + pow(addErr,2)) );
    addErr =  ewkHist->GetBinContent(iB)*lepSys;
    ewkHist -> SetBinError(iB, sqrt( pow(ewkHist->GetBinError(iB),2) + pow(addErr,2)) );

    addErr =  qcdHist->GetBinContent(iB)*qcdSys;
    qcdHist -> SetBinError(iB, sqrt( pow(qcdHist->GetBinError(iB),2) + pow(addErr,2)) );
    addErr =  qcdHist->GetBinContent(iB)*lumiSys;
    qcdHist -> SetBinError(iB, sqrt( pow(qcdHist->GetBinError(iB),2) + pow(addErr,2)) );
    addErr =  qcdHist->GetBinContent(iB)*lepSys;
    qcdHist -> SetBinError(iB, sqrt( pow(qcdHist->GetBinError(iB),2) + pow(addErr,2)) );

    addErr =  zHist->GetBinContent(iB)*zSys;
    zHist -> SetBinError(iB, sqrt( pow(zHist->GetBinError(iB),2) + pow(addErr,2)) );
    addErr =  zHist->GetBinContent(iB)*lumiSys;
    zHist -> SetBinError(iB, sqrt( pow(zHist->GetBinError(iB),2) + pow(addErr,2)) );
    addErr =  zHist->GetBinContent(iB)*lepSys;
    zHist -> SetBinError(iB, sqrt( pow(zHist->GetBinError(iB),2) + pow(addErr,2)) );

    addErr =  zttHist->GetBinContent(iB)*zSys;
    zttHist -> SetBinError(iB, sqrt( pow(zttHist->GetBinError(iB),2) + pow(addErr,2)) );
    addErr =  zttHist->GetBinContent(iB)*lumiSys;
    zttHist -> SetBinError(iB, sqrt( pow(zttHist->GetBinError(iB),2) + pow(addErr,2)) );
    addErr =  zttHist->GetBinContent(iB)*lepSys;
    zttHist -> SetBinError(iB, sqrt( pow(zttHist->GetBinError(iB),2) + pow(addErr,2)) );
  }

  // Add the single histograms to one total histogram
  TH1D * bkgErr = (TH1D*)ttHist->Clone("bkgErr");
  bkgErr->Add(ewkHist);
  bkgErr->Add(qcdHist);
  bkgErr->Add(zHist);
  bkgErr->Add(zttHist);
  bkgErr->SetFillStyle(3001);
  bkgErr->SetFillColor(1);
  bkgErr->SetMarkerStyle(21);
  bkgErr->SetMarkerSize(0);  

  // Make stack plot
  THStack *stack_bkg = new THStack("stack_bkg","");
  stack_bkg->Add(ttHist  ,"hist");
  stack_bkg->Add(ewkHist ,"hist");
  stack_bkg->Add(qcdHist ,"hist");
  stack_bkg->Add(zHist   ,"hist");
  stack_bkg->Add(zttHist ,"hist");

  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // PLOTTING
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  InitData(histData);
  InitHist(qcdHist ,"","",TColor::GetColor("#FFCCFF"),1001);
  InitHist(ewkHist ,"","",TColor::GetColor("#DE5A6A"),1001);
  InitHist(ttHist  ,"","",TColor::GetColor("#9999CC"),1001);
  InitHist(zHist   ,"","",TColor::GetColor("#6F2D35"),1001);
  InitHist(zttHist ,"","",TColor::GetColor("#FFCC66"),1001);
  histData->GetXaxis()->SetTitle(xtitle);
  histData->GetYaxis()->SetTitle(ytitle);
  histData->GetYaxis()->SetTitleOffset(1.3);
  histData->GetYaxis()->SetTitleSize(0.06);
  histData->GetXaxis()->SetRangeUser(xLower,xUpper);
  float yUpper = histData->GetMaximum();
  if (logY)
    histData->GetYaxis()->SetRangeUser(yLower,4*yUpper);
  else
    histData->GetYaxis()->SetRangeUser(0,1.2*yUpper);

  histData->SetMarkerSize(1.2);
  histData->GetXaxis()->SetLabelSize(0);
  histData->GetYaxis()->SetLabelSize(0.06);

  TCanvas * canv1 = MakeCanvas("canv1", "", 600, 700);
  TPad *upper = new TPad("upper", "pad",0,0.31,1,1);
  upper->Draw();
  upper->cd();

  upper->SetFillColor(0);
  upper->SetBorderMode(0);
  upper->SetBorderSize(10);
  upper->SetTickx(1);
  upper->SetTicky(1);
  upper->SetLeftMargin(0.17);
  upper->SetRightMargin(0.05);
  upper->SetBottomMargin(0.02);
  upper->SetFrameFillStyle(0);
  upper->SetFrameLineStyle(0);
  upper->SetFrameLineWidth(2);
  upper->SetFrameBorderMode(0);
  upper->SetFrameBorderSize(10);
  upper->SetFrameFillStyle(0);
  upper->SetFrameLineStyle(0);
  upper->SetFrameLineWidth(2);
  upper->SetFrameBorderMode(0);
  upper->SetFrameBorderSize(10);

  histData  -> Draw("e1");
  stack_bkg -> Draw("same");
  histData  -> Draw("e1same");
  bkgErr    -> Draw("e2same");

  TLegend * leg = new TLegend(0.6,0.45,0.84,0.78);
  SetLegendStyle(leg);
  leg->SetTextSize(0.046);
  leg->AddEntry(histData,"Data","lp");
  leg->AddEntry(zttHist,"Z#rightarrow#tau#tau","f");
  leg->AddEntry(zHist,"Drell-Yan","f");
  //leg->AddEntry(qcdHist,"QCD #mu-enriched","f");
  leg->AddEntry(qcdHist,"QCD (data driven)","f");
  leg->AddEntry(ewkHist,"electroweak","f");
  leg->AddEntry(ttHist,"t#bar{t}+single top","f");
  if (drawLeg) leg->Draw();
  writeExtraText = true;
  extraText = "Preliminary";
  CMS_lumi(upper,4,33); 
  //plotchannel("opposite-sign #mu trk");

  if (logY) upper->SetLogy(true);
    
  upper->Draw("SAME");
  upper->RedrawAxis();
  upper->Modified();
  upper->Update();
  canv1->cd();

  TH1D * ratioH = (TH1D*)histData->Clone("ratioH");
  TH1D * ratioErrH = (TH1D*)bkgErr->Clone("ratioErrH");
  ratioH->SetMarkerColor(1);
  ratioH->SetMarkerStyle(20);
  ratioH->SetMarkerSize(1.2);
  ratioH->SetLineColor(1);
  ratioH->GetYaxis()->SetRangeUser(0.5,1.5);
  ratioH->GetYaxis()->SetNdivisions(505);
  ratioH->GetXaxis()->SetLabelFont(42);
  ratioH->GetXaxis()->SetLabelOffset(0.04);
  ratioH->GetXaxis()->SetLabelSize(0.14);
  ratioH->GetXaxis()->SetTitleSize(0.13);
  ratioH->GetXaxis()->SetTitleOffset(1.2);
  ratioH->GetYaxis()->SetTitle("obs/exp");
  ratioH->GetYaxis()->SetLabelFont(42);
  ratioH->GetYaxis()->SetLabelOffset(0.015);
  ratioH->GetYaxis()->SetLabelSize(0.13);
  ratioH->GetYaxis()->SetTitleSize(0.14);
  ratioH->GetYaxis()->SetTitleOffset(0.5);
  ratioH->GetXaxis()->SetTickLength(0.07);
  ratioH->GetYaxis()->SetTickLength(0.04);
  ratioH->GetYaxis()->SetLabelOffset(0.01);

  ratioH    -> Divide(bkgErr);
  ratioErrH -> Divide(bkgErr);

  // ------------>Primitives in pad: lower
  TPad * lower = new TPad("lower", "pad",0,0,1,0.30);
  lower->Draw();
  lower->cd();

  lower->SetFillColor(0);
  lower->SetBorderMode(0);
  lower->SetBorderSize(10);
  lower->SetGridy();
  lower->SetTickx(1);
  lower->SetTicky(1);
  lower->SetLeftMargin(0.17);
  lower->SetRightMargin(0.05);
  lower->SetTopMargin(0.026);
  lower->SetBottomMargin(0.35);
  lower->SetFrameFillStyle(0);
  lower->SetFrameLineStyle(0);
  lower->SetFrameLineWidth(2);
  lower->SetFrameBorderMode(0);
  lower->SetFrameBorderSize(10);
  lower->SetFrameFillStyle(0);
  lower->SetFrameLineStyle(0);
  lower->SetFrameLineWidth(2);
  lower->SetFrameBorderMode(0);
  lower->SetFrameBorderSize(10);

  ratioH->Draw("e1");
  ratioErrH->Draw("e2same");

  lower->Modified();
  lower->RedrawAxis();
  canv1->cd();
  canv1->SetSelected(canv1);

  canv1->Print("figures/"+histName+sys+".png");

}
