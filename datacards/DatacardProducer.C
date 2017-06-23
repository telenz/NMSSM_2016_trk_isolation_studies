#include <sstream> 
#include <iostream>
#include <fstream>
#include <iomanip>
#include "TH1.h"
#include "TFile.h"

void DatacardProducer(TString ptRange = "2p5to5") {

  // ***************
  // Creating datacard inputs
  // *************** 
  TString BaseName = "datacard_"+ptRange;
  TString rootFileName =  "templates_trk_isolation_" + ptRange + ".root";

  ostringstream str;
  str << BaseName << ".txt";
  string nn = str.str();
  const char * p = nn.c_str();

  // Open histogram with all information
  TFile *inFile = new TFile(rootFileName,"UPDATE");
  TH1D* h_data = 0;
  TH1D* h_qcd  = 0;
  TH1D* h_ewk  = 0;
  TH1D* h_tt   = 0;
  TH1D* h_z    = 0;
  TH1D* h_ztt  = 0;

  if(inFile){
    inFile -> GetObject("data_obs",h_data);
    inFile -> GetObject("qcd" ,h_qcd);
    inFile -> GetObject("ewk" ,h_ewk);
    inFile -> GetObject("tt"  ,h_tt);
    inFile -> GetObject("z"   ,h_z);
    inFile -> GetObject("ztt" ,h_ztt);
  }


  // %%%%%%%%%%%%%%%%%%%%%%%%%%% SYS UNCERTAINTIES %%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // Determine jes uncertainty
  TFile * in = new TFile("templates_trk_isolation_" + ptRange + "_jesUp.root","READ");
  TH1D* h_data_jesUp = 0;
  TH1D* h_qcd_jesUp  = 0;
  TH1D* h_ewk_jesUp  = 0;
  TH1D* h_tt_jesUp   = 0;
  TH1D* h_z_jesUp    = 0;
  TH1D* h_ztt_jesUp  = 0;

  if(in){
    in -> GetObject("data_obs",h_data_jesUp);
    in -> GetObject("qcd" ,h_qcd_jesUp);
    in -> GetObject("ewk" ,h_ewk_jesUp);
    in -> GetObject("tt"  ,h_tt_jesUp);
    in -> GetObject("z"   ,h_z_jesUp);
    in -> GetObject("ztt" ,h_ztt_jesUp);
  }
  in = new TFile("templates_trk_isolation_" + ptRange + "_jesDown.root","READ");
  TH1D* h_data_jesDown = 0;
  TH1D* h_qcd_jesDown  = 0;
  TH1D* h_ewk_jesDown  = 0;
  TH1D* h_tt_jesDown   = 0;
  TH1D* h_z_jesDown    = 0;
  TH1D* h_ztt_jesDown  = 0;

  if(in){
    in -> GetObject("data_obs",h_data_jesDown);
    in -> GetObject("qcd" ,h_qcd_jesDown);
    in -> GetObject("ewk" ,h_ewk_jesDown);
    in -> GetObject("tt"  ,h_tt_jesDown);
    in -> GetObject("z"   ,h_z_jesDown);
    in -> GetObject("ztt" ,h_ztt_jesDown);
  }

  // symmetrize
  double qcd_jes = 1/2.*(fabs(h_qcd_jesUp->Integral()/h_qcd->Integral()-1.) + fabs(h_qcd_jesDown->Integral()/h_qcd->Integral()-1.)) + 1;
  double ewk_jes = 1/2.*(fabs(h_ewk_jesUp->Integral()/h_ewk->Integral()-1.) + fabs(h_ewk_jesDown->Integral()/h_ewk->Integral()-1.)) + 1;
  double tt_jes  = 1/2.*(fabs(h_tt_jesUp->Integral()/h_tt->Integral()-1.) + fabs(h_tt_jesDown->Integral()/h_tt->Integral()-1.)) + 1;
  double z_jes   = 1/2.*(fabs(h_z_jesUp->Integral()/h_z->Integral()-1.) + fabs(h_z_jesDown->Integral()/h_z->Integral()-1.)) + 1;
  double ztt_jes = 1/2.*(fabs(h_ztt_jesUp->Integral()/h_ztt->Integral()-1.) + fabs(h_ztt_jesDown->Integral()/h_ztt->Integral()-1.)) + 1;

  // ---------------------------------------------------------------------------------------------------
  // Determine ues uncertainty
  in = new TFile("templates_trk_isolation_" + ptRange + "_uesUp.root","READ");
  TH1D* h_data_uesUp = 0;
  TH1D* h_qcd_uesUp  = 0;
  TH1D* h_ewk_uesUp  = 0;
  TH1D* h_tt_uesUp   = 0;
  TH1D* h_z_uesUp    = 0;
  TH1D* h_ztt_uesUp  = 0;

  if(in){
    in -> GetObject("data_obs",h_data_uesUp);
    in -> GetObject("qcd" ,h_qcd_uesUp);
    in -> GetObject("ewk" ,h_ewk_uesUp);
    in -> GetObject("tt"  ,h_tt_uesUp);
    in -> GetObject("z"   ,h_z_uesUp);
    in -> GetObject("ztt" ,h_ztt_uesUp);
  }
  in = new TFile("templates_trk_isolation_" + ptRange + "_uesDown.root","READ");
  TH1D* h_data_uesDown = 0;
  TH1D* h_qcd_uesDown  = 0;
  TH1D* h_ewk_uesDown  = 0;
  TH1D* h_tt_uesDown   = 0;
  TH1D* h_z_uesDown    = 0;
  TH1D* h_ztt_uesDown  = 0;

  if(in){
    in -> GetObject("data_obs",h_data_uesDown);
    in -> GetObject("qcd" ,h_qcd_uesDown);
    in -> GetObject("ewk" ,h_ewk_uesDown);
    in -> GetObject("tt"  ,h_tt_uesDown);
    in -> GetObject("z"   ,h_z_uesDown);
    in -> GetObject("ztt" ,h_ztt_uesDown);
  }

  // symmetrize
  double qcd_ues = 1/2.*(fabs(h_qcd_uesUp->Integral()/h_qcd->Integral()-1.) + fabs(h_qcd_uesDown->Integral()/h_qcd->Integral()-1.)) + 1;
  double ewk_ues = 1/2.*(fabs(h_ewk_uesUp->Integral()/h_ewk->Integral()-1.) + fabs(h_ewk_uesDown->Integral()/h_ewk->Integral()-1.)) + 1;
  double tt_ues  = 1/2.*(fabs(h_tt_uesUp->Integral()/h_tt->Integral()-1.) + fabs(h_tt_uesDown->Integral()/h_tt->Integral()-1.)) + 1;
  double z_ues   = 1/2.*(fabs(h_z_uesUp->Integral()/h_z->Integral()-1.) + fabs(h_z_uesDown->Integral()/h_z->Integral()-1.)) + 1;
  double ztt_ues = 1/2.*(fabs(h_ztt_uesUp->Integral()/h_ztt->Integral()-1.) + fabs(h_ztt_uesDown->Integral()/h_ztt->Integral()-1.)) + 1;
  // ---------------------------------------------------------------------------------------------------
  // Write top pt and z pt templates 
  in = new TFile("templates_trk_isolation_" + ptRange + "_topPtUp.root","READ");
  TH1D* h_tt_topPtUp = 0;
  in -> GetObject("tt", h_tt_topPtUp);
  in = new TFile("templates_trk_isolation_" + ptRange + "_topPtDown.root","READ");
  TH1D* h_tt_topPtDown = 0;
  in -> GetObject("tt", h_tt_topPtDown);

  in = new TFile("templates_trk_isolation_" + ptRange + "_zPtUp.root","READ");
  TH1D* h_z_zPtUp = 0;
  TH1D* h_ztt_zPtUp = 0;
  in -> GetObject("z"  , h_z_zPtUp);
  in -> GetObject("ztt", h_ztt_zPtUp);
  in = new TFile("templates_trk_isolation_" + ptRange + "_zPtDown.root","READ");
  TH1D* h_z_zPtDown = 0;
  TH1D* h_ztt_zPtDown = 0;
  in -> GetObject("z"  , h_z_zPtDown);
  in -> GetObject("ztt", h_ztt_zPtDown);

  inFile->cd();
  h_tt_topPtUp   -> Write("tt_topPtUp");
  h_tt_topPtDown -> Write("tt_topPtDown");
  h_z_zPtUp      -> Write("z_zPtUp");
  h_z_zPtDown    -> Write("z_zPtDown");
  h_ztt_zPtUp    -> Write("ztt_zPtUp");
  h_ztt_zPtDown  -> Write("ztt_zPtDown");
  
  // %%%%%%%%%%%%%%%%%%%%%%%%%%% END : SYS UNCERTAINTIES %%%%%%%%%%%%%%%%%%%%%%%%%

  std::ofstream textFile(p);
  textFile << left;
  
  textFile << "imax 1   number of channels" << endl;
  textFile << "jmax *   number of backgrounds" << endl;
  textFile << "kmax *   number of nuisance parameters" << endl;
  textFile << "-----------------" << endl;
  textFile << "observation " << h_data->Integral() << endl;
  textFile << "-----------------" << endl;
  textFile << "shapes * ch1 " <<rootFileName << "  $PROCESS   $PROCESS_$SYSTEMATIC" << endl;

  textFile << "-----------------" << endl;
  textFile << setw(30) << "bin"                           << setw(20) << "ch1"  << setw(20) << "ch1"   << setw(20) << "ch1"   << setw(20) << "ch1"   << setw(20) << "ch1"   << endl;
  textFile << setw(30) << "process"                       << setw(20) << "ztt"  << setw(20) << "qcd"   << setw(20) << "ewk"   << setw(20) << "tt"    << setw(20) << "z"     << endl;
  textFile << setw(30) << "process"                       << setw(20) << "0"    << setw(20) << "1"     << setw(20) << "2"     << setw(20) << "3"     << setw(20) << "4"     << endl;
  textFile << setw(30) << "rate" << setw(20) << h_ztt->Integral() << setw(20) << h_qcd->Integral() << setw(20) << h_ewk->Integral() << setw(20) << h_tt->Integral() << setw(20) << h_z->Integral() << endl;

  textFile << "-----------------" << endl;
  textFile << setw(15) << "lumi"    << setw(15) << "lnN"   << setw(20)   << "1.027" << setw(20) << "1.027" << setw(20) << "1.027" << setw(20) << "1.027" << setw(20) << "1.027" << endl;
  textFile << setw(15) << "lepEff"  << setw(15) << "lnN"   << setw(20)   << "1.02"  << setw(20) << "1.02"  << setw(20) << "1.02"  << setw(20) << "1.02"  << setw(20) << "1.02"  << endl;
  textFile << setprecision(4) << setw(15) << "jes"     << setw(15) << "lnN"   << setw(20)   << ztt_jes << setw(20) << qcd_jes << setw(20) << ewk_jes << setw(20) << tt_jes  << setw(20) << z_jes   << endl;
  textFile << setprecision(4) << setw(15) << "ues"     << setw(15) << "lnN"   << setw(20)   << ztt_ues << setw(20) << qcd_ues << setw(20) << ewk_ues << setw(20) << tt_ues  << setw(20) << z_ues   << endl;
  textFile << setw(15) << "zPt"     << setw(15) << "shape" << setw(20)   << "1.00"  << setw(20) << "-"     << setw(20) << "-"     << setw(20) << "-"     << setw(20) << "1.00"  << endl;
  textFile << setw(15) << "topPt"   << setw(15) << "shape" << setw(20)   << "-"     << setw(20) << "-"     << setw(20) << "-"     << setw(20) << "1.00"  << setw(20) << "-"     << endl;

  textFile << "qcdScale rateParam ch1 qcd  1  [0.0,3.0]" << endl;
  textFile << "ewkScale rateParam ch1 ewk  1  [0.0,3.0]" << endl;
  textFile << "ttScale rateParam ch1 tt  1  [0.0,3.0]" << endl;
  textFile << "zScale rateParam ch1 z  1  [0.0,3.0]" << endl;

  // *******************
  // end creating datacard inputs
  // *******************
}
