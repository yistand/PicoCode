// use this macro first to create trees from MuDsts

void bemcCalibMacro(int nEvents = 1e3,
		const char* filelist = "test.list", 
		const char* nametag  = "test",
		    int nFiles = 8
		    )
{
  gROOT->Macro("LoadLogger.C");
  gROOT->Macro("loadMuDst.C");
  gSystem->Load("StarMagField.so");
  gSystem->Load("StMagF");
  gSystem->Load("StDetectorDbMaker");
  gSystem->Load("StTpcDb");
  gSystem->Load("St_db_Maker");
  gSystem->Load("StDbUtilities");
  gSystem->Load("StMcEvent");
  gSystem->Load("StMcEventMaker");
  gSystem->Load("StDaqLib");
  gSystem->Load("StEmcRawMaker");
  gSystem->Load("StEmcADCtoEMaker");
  gSystem->Load("StEpcMaker");
  gSystem->Load("StTriggerUtilities");
  gSystem->Load("StDbBroker");
  gSystem->Load("libgeometry_Tables");
  gSystem->Load("StEEmcUtil");
  gSystem->Load("StEEmcDbMaker");
  gSystem->Load("StPreEclMaker");
  gSystem->Load("StEpcMaker");
 
  gSystem->Load("libTStarJetPico.so");
  gSystem->Load("JetPicoMaker");
	
  StChain* chain = new StChain("StChain");
	
  StMuDstMaker* muDstMaker = new StMuDstMaker(0,0,"",filelist,"",nFiles);
  St_db_Maker *dbMaker = new St_db_Maker("StarDb","MySQL:StarDb");
  StEEmcDbMaker* eemcb = new StEEmcDbMaker("eemcDb");
  StEmcADCtoEMaker *adc = new StEmcADCtoEMaker();
  StPreEclMaker *pre_ecl  = new StPreEclMaker();
  StEpcMaker *epc         = new StEpcMaker();

  //get control table so we can turn off BPRS zero-suppression and save hits from "bad" caps
  controlADCtoE_st* control_table = adc->getControlTable();
  control_table->CutOff[1] = -1;
  control_table->CutOffType[1] = 0;
  control_table->DeductPedestal[1] = 2;
  adc->saveAllStEvent(kTRUE);

  StTriggerSimuMaker* trigsim = new StTriggerSimuMaker();
  trigsim->setMC(false);
  trigsim->useBemc();
  trigsim->useEemc();
  trigsim->useBbc();
  trigsim->useOnlineDB();
  trigsim->bemc->setConfig(StBemcTriggerSimu::kOffline);



  StMuJetAnalysisTreeMaker *ana = new StMuJetAnalysisTreeMaker;
  ana->SetVerbose(0);
  ana->setRootFile(Form("pp12Pico_%s.root",nametag));  
  ana->SetFlagData(8); //For PP Y12
  ana->GetV0Cuts()->SetStandardCutspp();   
  ana->SetDoV0s(kFALSE);      
  //TString outfile(name);
  //StEmcOfflineCalibrationMaker* bemcCalibMaker = new StEmcOfflineCalibrationMaker("bemcCalibMaker",outfile.Data());

  //2012 200 GeV triggers
  //high tower
  //bemcCalibMaker->addHighTowerTrigger(370501); //BHT0*VPD
  //bemcCalibMaker->addHighTowerTrigger(370511); //BHT1*VPD
  //bemcCalibMaker->addHighTowerTrigger(370531); //BHT2
  //bemcCalibMaker->addHighTowerTrigger(370521); //BHT2*BBCMB
  //bemcCalibMaker->addHighTowerTrigger(370522); //BHT2*BBCMB

  StMemStat memory;
  memory.PrintMem(NULL);
	
  chain->Init();
  cout<<"chain initialized"<<endl;
	
  TStopwatch total;
  TStopwatch timer;
	
  int i=0;
  while(i<nEvents && chain->Make()==kStOk)
    {
      if(i % 100000 == 0){
	cout<<"done with event "<<i;
	cout<<"\tcpu: "<<timer.CpuTime()<<"\treal: "<<timer.RealTime()<<"\tratio: "<<timer.CpuTime()/timer.RealTime();//<<endl;
	timer.Start();
	memory.PrintMem(NULL);
      }
      i++;
      chain->Clear();
    }
	
  chain->ls(3);
  chain->Finish();
  printf("my macro processed %i events in %s",i,nametag);
  cout<<"\tcpu: "<<total.CpuTime()<<"\treal: "<<total.RealTime()<<"\tratio: "<<total.CpuTime()/total.RealTime()<<endl;

  cout << endl;
  cout << "-------------" << endl;
  cout << "(-: Done :-) " << endl;
  cout << "-------------" << endl;
  cout << endl;
}
