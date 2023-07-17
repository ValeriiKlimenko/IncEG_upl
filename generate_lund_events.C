/* ---------------------------------- */
/*    Frascati, March 17th, 2016.     */
/*                                    */
/*       author: Silvia Pisano        */
/*        pisanos@jlab.org            */
/*    silvia.pisano@lnf.infn.it       */
/* ---------------------------------- */
{

  gSystem->CompileMacro("DisFunctions.C", "kf");
  gSystem->CompileMacro("GenFunctions.C", "kf");
  gSystem->CompileMacro("InclusiveRateAnalysis.C");
  t=new InclusiveRateAnalysis();

  float beamE = 10.6;
  Double_t theta_min, theta_max;
  Double_t p_min, p_max;
  Int_t start_number;
  Int_t totalEvents = 2000000000;
  Int_t eventsPerFile = 2000000;

  if (beamE > 10.5 && beamE < 10.7){
    //10.6 GeV
    t->SetKinematicLimits(7., 38., 0.04, 1.5, 10.604, 0.002, 1745089, 10.604);
    t->SetFile("cross_section_data/data_7_38_0.04_1.5_10.6_0.002_elasFixParamUPD.dat");
      
      
    // before elas peak and param upd
    //t->SetKinematicLimits(5., 40., 0.05, 1.4, 10.602, 0.002, 1631623, 10.604);
    //t->SetFile("cross_section_data/data_5_35_0.05_1.4_10.6_0.002IncParamAdj_iter2.dat");
  }

  cout << beamE <<endl;
  cout <<  Form("/w/hallb-scifs17exp/clas12/markov/LUND/lustre/expphy/%3.1fGeV/InclusiveElastic/", beamE) << endl;
  
  t->PrepareOutput("");
  t->BookHistos();
  t->SetLuminosity( pow( 10, 35 ) );
  t->ReadDataFile();
  t->PlotCrossSectionDependences();
  start_number = 0;
  theta_min = 7.;
  theta_max = 38;
  p_min = 1.5;
  p_max = 10.604;
  t->GeneratePseudoData(totalEvents, eventsPerFile, Form("l"), start_number, theta_min, theta_max, p_min, p_max);

  t->CompareGenEventsToOriginal();
  t->SaveOutput();
  delete t;
  
}
