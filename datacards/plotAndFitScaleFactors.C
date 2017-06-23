#include <iostream>
#include "../plotting/HttStylesNew.cc"
#include "TGraphErrors.h"
#include "TF1.h"

void plotAndFitScaleFactors(){

  SetStyle();

  const int ptBins = 5;
  float x[ptBins +1]    = {6.25  , 8.75  , 12.5  , 17.5  , 30   };
  float xErr[ptBins +1] = {1.25  , 1.25  , 2.5   , 2.5   , 10   };
  float y[ptBins +1]    = {0.650 , 0.643 , 0.785 , 0.698 , 0.804};
  float yErr[ptBins +1] = {0.069 , 0.038 , 0.035 , 0.034 , 0.042};

  TGraphErrors *g =  new TGraphErrors(ptBins,x,y,xErr,yErr);
  g->SetMarkerStyle(20);
  g->GetXaxis()->SetTitle("track pt");
  g->GetYaxis()->SetTitle("trk iso scale factor");
  g->SetTitle("");
  g->GetYaxis()->SetRangeUser(0.5,1.0);

  // Make Fit
  TF1* f1 = new TF1("f1","[0]");
  f1->SetLineColor(kOrange);
  g->Fit("f1");
  /*
  TF1* f2 = new TF1("f2","[0]*x+[1]");
  f2->SetLineColor(kBlue);
  g->Fit("f2");
  */

  TCanvas * canv1 = MakeCanvas("canv1", "", 700, 800);
  canv1 -> cd();

  g->Draw("AP");

  

  canv1->SaveAs("figures/TauIsolation_ScaleFactors.pdf");

}
