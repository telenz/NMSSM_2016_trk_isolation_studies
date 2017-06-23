#include <iostream>
#include "HttStylesNew.cc"
#include "TGraphErrors.h"


void plotAndFitScaleFactors(){

  const int ptBins = 5;
  float x[ptBins +1]    = {3.75 , 6.25 , 8.75 , 15 , 30};
  float xErr[ptBins +1] = {1.25 , 1.25 , 1.25 , 5 , 10};
  float y[ptBins +1]    = {7.5879 , 1.9226 , 1.0177 , 0.97227 , 0.77155 };
  float yErr[ptBins +1] = {0.198  , 0.201  , 0.0822 , 0.0366  , 0.023};

  TGraphErrors *g =  new TGraphErrors(ptBins,x,y,xErr,yErr);
  g->SetMarkerStyle(20);
  g->GetXaxis()->SetTitle("track pt");
  g->GetYaxis()->SetTitle("trk iso scale factor");
  g->SetTitle("");


  TCanvas * canv1 = MakeCanvas("canv1", "", 700, 800);
  canv1 -> cd();

  g->Draw("AP");

  canv1->SaveAs("TauIsolation_ScaleFactos.pdf");

}
