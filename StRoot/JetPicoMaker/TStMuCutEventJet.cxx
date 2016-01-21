//////////////////////////////////////////////////////////
//                                                      //
//              TStMuCutEventJet Class                 //
//                                                      //
//////////////////////////////////////////////////////////

#include "StEvent/StEvent.h" 
#include "StEvent/StEventTypes.h" 
#include "StEvent/StEventSummary.h" 
#include "StEvent/StEventInfo.h" 
#include "StEvent/StDetectorState.h" 
#include "StEvent/StL0Trigger.h"

#include "StEventUtilities/StuRefMult.hh"

#include "StarClassLibrary/SystemOfUnits.h"
#include "StarClassLibrary/StTimer.hh"

#include "StarClassLibrary/StThreeVectorD.hh"
#include "StarClassLibrary/StThreeVectorF.hh"

#include "StMuDSTMaker/COMMON/StMuCut.h"
#include "StMuDSTMaker/COMMON/StMuDebug.h"
 
#include "TClonesArray.h"
#include "TObject.h"
#include "TClass.h"

#include <TPaveText.h>
#include <TCutG.h>
#include <TArrayI.h>
#include <TObjArray.h>

#include "TStMuCutEventJet.h"

ClassImp(TStMuCutEventJet)

//______________________________________________________________________________
    TStMuCutEventJet::TStMuCutEventJet():TObject()
{ 
  //
  // Default constructor
  //

  Reset();

}

//______________________________________________________________________________

void TStMuCutEventJet::Reset()
{
  //
  // Resets the cut definition and the counters
  //
    fTRUE         = 1; 
    fFALSE        = 0;
    fVerbose      = fFALSE;
    
    fnumevent     = 0;     
    fnumgoodevent = 0; 

    fFlagVertexIflag = kFALSE;
    fFlagVertexX     = kFALSE;
    fFlagVertexY     = kFALSE;
    fFlagVertexZ     = kFALSE;
    fFlagEVeto       = kFALSE;
    fFlagMult        = kFALSE;
    fFlagL0TriggerWord  = kFALSE;

    fnVertexIflag = 0;
    fnVertexX     = 0;
    fnVertexY     = 0;
    fnVertexZ     = 0;
    fnEVeto       = 0;
    fnMult        = 0;
    fnL0TriggerWord = 0;

    fnallVertexX         = 0;
    fnallVertexY         = 0;
    fnallVertexZ         = 0;
    fnallMult            = 0;
    fnallL0TriggerWord   = 0;
    fAuAuRefCheck        = kFALSE;

}

//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsCuCuMinBias()
{   
  SetL0TriggerWord(66007,66203,99999,99999,99999,99999,99999,99999,99999,99999);  
}

//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsCuCuHighTwr()
{   
  SetL0TriggerWord(66007,66203,99999,99999,99999,99999,99999,99999,99999,99999);  
}

//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsCuCu62MinBias()
{   
  SetL0TriggerWord(76007,76011,99999,99999,99999,99999,99999,99999,99999,99999);  
}

//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsAuAuCentral()
{   
  SetL0TriggerWord(15105,15007,99999,99999,99999,99999,99999,99999,99999,99999);  
}
//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsAuAuMinBias()
{   
  SetL0TriggerWord(15007,99999,99999,99999,99999,99999,99999,99999,99999,99999);
}
 
//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsAuAuL2()
{   //L2 trigger and bht2-mb & mb-vpd
  fAuAuRefCheck=kTRUE;
  SetL0TriggerWord(200620,200621,200001,200003,200013,200211,200212,200220,200221,200222);
}
 
//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsAuAuY7Min()
{
  fAuAuRefCheck=kTRUE;
  SetL0TriggerWord(200620,200621,200001,200003,200013,200211,200212,200220,200221,200222);
 
}

//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsAuAu62()
{   
  SetL0TriggerWord(35001,35004,35006,35007,35008,35009,99999,99999,99999,99999);  
}

//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsAuAu19()
{   
  SetL0TriggerWord(4609,4609,99999,99999,99999,99999,99999,99999,99999,99999);
}

//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsAuAuMBHalfHL04()
{   
  SetL0TriggerWord(15006,25001,25007,25105,25203,25211,25310,99999,99999,99999);  
  
}

//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsPPMinBiasY6()
{   
  SetL0TriggerWord(117001,999999,999999,999999,999999,999999,999999,999999,99999,99999);  
  
}
//________________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsPPHTTPY6()
{   
  SetL0TriggerWord(117201,999999,999999,999999,999999,999999,999999,999999,99999,99999);  
  
}
//______________________________________________________________________________

void TStMuCutEventJet::SetStandardCutsPPHT2Y6()
{   
  SetL0TriggerWord(117211,117212,127212,127213,137213,999999,999999,999999,99999,99999);  
  
}

//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsPPJP1mbY6()
{   
  SetL0TriggerWord(117221,127221,137221,137222,999999,999999,9999999,999999,99999,99999);  
  
}
//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsPPallY6()//mb(1) + JP(4) + HT(5)
{   
  SetL0TriggerWord(117001,117221,127221,137221,137222,117211,117212,127212,127213,137213);
  
}


//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsdAuALLY8()
{   
  SetL0TriggerWord(210020,210500,210501,210510,210511,210520,210521,210541,999999,999999);  
}

//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsdAuHTY8()
{   
  SetL0TriggerWord(210500,210501,210510,210511,210520,210521,210541,999999,999999,999999);  
}

//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsMC(){
  SetL0TriggerWord(0,0,0,0,999999,999999,9999999,999999,99999,99999);  

}

//______________________________________________________________________________ 
void TStMuCutEventJet::SetStandardCutsPPy8(){
  SetL0TriggerWord(220500,220510,220520,220000,999999,999999,999999,999999,999999,999999);  
}

//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsppY12(){
  //2015.10.12 #ly SetL0TriggerWord(370341,370011,370541,370542,370351,370601,370611,370621,99999,99999);  
  SetL0TriggerWord(370341,370011,370521,370522,370531,370601,370611,370621,99999,99999);  	//  TOFMult4, VPDMB-nobsmd, BHT2*BBCMB, BHT2*BBCMB, BHT2, JP0, JP1, JP2

}

//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsppY12JP2(){
  SetL0TriggerWord(370621,99999,99999,999999,999999,999999,999999,999999,999999,999999);  	//  JP2

}

//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsppY12MB(){
  SetL0TriggerWord(370011,99999,99999,999999,999999,999999,999999,999999,999999,999999);  	//  VPDMB-nobsmd

}

//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsAuAuY11MB(){
// vpd-zdc-mb-protected	
  SetL0TriggerWord(350003,350013,350023,350033,350043,99999,99999,99999,99999,99999);  
}

//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsAuAuY11HT()
{   // Use NPE trigger. 350502, 350512 for NPE15
//	350503,350513 for NPE18
//	350504,350514 for NPE25
//  SetL0TriggerWord(350502,350512,350503,350513,350504,350514,99999,99999,99999,99999);	// NPE15, NPE18, NPE25
  SetL0TriggerWord(350503,350513,99999,99999,99999,99999,99999,99999,99999,99999);	// NPE18
//  SetL0TriggerWord(350504,350514,99999,99999,99999,99999,99999,99999,99999,99999);	// NPE25
}
 
//______________________________________________________________________________
void TStMuCutEventJet::SetStandardCutsAuAuY11L2()
{   //L2 trigger
// #ly not sure what is it, therefore commented out.   fAuAuRefCheck=kTRUE;
  SetL0TriggerWord(20,350069,99999,99999,99999,99999,99999,99999,99999,99999);
}
 

//______________________________________________________________________________
 Int_t TStMuCutEventJet::CheckEvent(StMuEvent *Event)
{

  if (fVerbose) cout<<"TStMuCutEventJet::CheckEvent"<<endl;

  //Checks whether a given event passes the defined cuts 
 
  StatisticForParticle(Event);
  
  fnumevent++;
    
  
  if(fFlagL0TriggerWord && (Event->triggerIdCollection().nominal().isTrigger(fL0TriggerWord) ==0 &&
			    Event->triggerIdCollection().nominal().isTrigger(fL0TriggerWord2) ==0 && 
			    Event->triggerIdCollection().nominal().isTrigger(fL0TriggerWord3) ==0 &&  
			    Event->triggerIdCollection().nominal().isTrigger(fL0TriggerWord4) ==0 && 
			    Event->triggerIdCollection().nominal().isTrigger(fL0TriggerWord5) ==0 && 
			    Event->triggerIdCollection().nominal().isTrigger(fL0TriggerWord6) ==0 &&
			    Event->triggerIdCollection().nominal().isTrigger(fL0TriggerWord7) ==0 && 
			    Event->triggerIdCollection().nominal().isTrigger(fL0TriggerWord8) ==0 && 
			    Event->triggerIdCollection().nominal().isTrigger(fL0TriggerWord9) ==0 && 
			    Event->triggerIdCollection().nominal().isTrigger(fL0TriggerWord10) ==0  
			    ))
    {
      if(fVerbose) printf("Event not accepted L0TriggerWord ");
      fnL0TriggerWord++;
      return kFALSE;
    }
  
 


  if(fFlagMult && (GetNumGoodTracks(Event) < fMinMult || GetNumGoodTracks(Event) > fMaxMult) )
    {
      if(fVerbose) printf("Event not accepted  Mult %d. ",GetNumGoodTracks(Event));
      fnMult++;
      return kFALSE;
    }
  
  
   if(fFlagVertexX && (GetVertexX(Event) < fMinVertexX || GetVertexX(Event) > fMaxVertexX) )
     {
       if(fVerbose) printf("Event not accepted  VertexX = %f ",GetVertexX(Event));
       fnVertexX++;
       return kFALSE;
     }
    
    if(fFlagVertexY && (GetVertexY(Event) < fMinVertexY || GetVertexY(Event) > fMaxVertexY) )
    {
      if(fVerbose) printf("Event not accepted  VertexY = %f ",GetVertexY(Event));
      fnVertexY++;
      return kFALSE;
    }
    if(fFlagVertexZ && (GetVertexZ(Event) < fMinVertexZ || GetVertexZ(Event) > fMaxVertexZ ||GetVertexZ(Event) ==0 )  )
    {
      if(fVerbose) printf("Event not accepted  VertexZ = %f ",GetVertexZ(Event));
      fnVertexZ++;
      return kFALSE;
    }
    
    fnumgoodevent++;

    return kTRUE;

}


void TStMuCutEventJet::StatisticForParticle(StMuEvent *Event)
{
  
  //Checks whether a given event passes the defined cuts  
  
    if(fFlagL0TriggerWord && (GetL0TriggerWord(Event)!= fL0TriggerWord))
    {     
      fnallL0TriggerWord++;
    }
 
   
    if(fFlagMult && (GetNumGoodTracks(Event) < fMinMult || GetNumGoodTracks(Event) > fMaxMult) )
    {    
      fnallMult++;    
    }
 
    if(fFlagVertexX && (GetVertexX(Event) < fMinVertexX || GetVertexX(Event) > fMaxVertexX) )
    {      
      fnallVertexX++;     
    }

    if(fFlagVertexY && (GetVertexY(Event) < fMinVertexY || GetVertexY(Event) > fMaxVertexY) )
    {     
      fnallVertexY++;      
    }

    if(fFlagVertexZ && (GetVertexZ(Event) < fMinVertexZ || GetVertexZ(Event) > fMaxVertexZ) )
    {      
      fnallVertexZ++;      
    }     
}

//______________________________________________________________________________
 TPaveText  *TStMuCutEventJet::GetCutList()
{
  //
  // Creates a TPaveText with the defined cuts and the cut-statistics
  //

  TPaveText *pave      = new TPaveText(0,0,1,1);
 
  Char_t         hname[10000]; 

  sprintf(hname,"total number of events : %d ",fnumevent);  
  pave->AddText(hname);

  sprintf(hname,"number of events accepted : %d ",fnumgoodevent);  
  pave->AddText(hname);
   

  if(fFlagL0TriggerWord)
    {   
      sprintf(hname,"SetL0TriggerWord(%d,%d,%d,%d,%d,%d,%d,%d,%d,%d) : %d all: %d ",fL0TriggerWord,fL0TriggerWord2,fL0TriggerWord3,fL0TriggerWord4,fL0TriggerWord5,fL0TriggerWord6,fL0TriggerWord7,fL0TriggerWord8,fL0TriggerWord9,fL0TriggerWord10,fnL0TriggerWord,fnallL0TriggerWord);
      pave->AddText(hname);
    } 

  if(fFlagMult)
    {     
      sprintf(hname,"SetMult(%d,%d) : %d all: %d ", fMinMult, fMaxMult,fnMult,fnallMult);
      pave->AddText(hname);
    } 
  if(fFlagVertexIflag)
    { 
      if(fN2VertexIflag!= 99 && fN3VertexIflag != 99)      
	sprintf(hname,"SetVertexIflag(%d,%d,%d) : %d ",fN1VertexIflag
		,fN2VertexIflag
		,fN3VertexIflag
		,fnVertexIflag);  
      if(fN2VertexIflag!= 99 && fN3VertexIflag == 99)      
	sprintf(hname,"SetVertexIflag(%d,%d) : %d ",fN1VertexIflag
		,fN2VertexIflag
		,fnVertexIflag);  
      if(fN2VertexIflag== 99 && fN3VertexIflag == 99)      
	sprintf(hname,"SetVertexIflag(%d) : %d ",fN1VertexIflag
		,fnVertexIflag);  
      
      pave->AddText(hname);
    }
  if(fFlagVertexX)
    {
      sprintf(hname,"SetVertexX(%f,%f) : %d all: %d  ", fMinVertexX, fMaxVertexX,fnVertexX,fnallVertexX);
      pave->AddText(hname);
    }
  if(fFlagVertexY)
    {
      sprintf(hname,"SetVertexY(%f,%f) : %d all: %d", fMinVertexY, fMaxVertexY,fnVertexY,fnallVertexY);
      pave->AddText(hname);
    }
  if(fFlagVertexZ)
    {
      sprintf(hname,"SetVertexZ(%f,%f) : %d all: %d", fMinVertexZ, fMaxVertexZ, fnVertexZ,fnallVertexZ);
      pave->AddText(hname);
    }
  if(fFlagEVeto)
    {
      sprintf(hname,"SetEVeto(%f,%f) : %d ", fMinEVeto, fMaxEVeto,fnEVeto);
      pave->AddText(hname);
    }
  return pave;
}

//______________________________________________________________________________
 void  TStMuCutEventJet::PrintCutList()
{
  //
  // Prints the defined cuts and the cut-statistic
  //

  GetCutList()->Print();
}



Int_t  TStMuCutEventJet::GetNumTracks(StMuEvent *Event)
{
  StEventSummary &eventsum = Event->eventSummary();
  return eventsum.numberOfTracks();
}

Int_t  TStMuCutEventJet::GetNumGoodTracks(StMuEvent *Event)
{ 

  //  Int_t referencemult = -999;
 
  //if(fAuAuRefCheck) referencemult = Event->grefmult();
  //else referencemult = Event->refMult();
 return fAuAuRefCheck ? Event->grefmult() : Event->refMult();
 //return referencemult;
  
 }


Float_t  TStMuCutEventJet::GetVertexZ(StMuEvent *Event)
{
  StEventSummary &eventsum = Event->eventSummary();
  return (eventsum.primaryVertexPosition()).z() ;   
}


Float_t  TStMuCutEventJet::GetVertexY(StMuEvent *Event)
{
  StEventSummary &eventsum = Event->eventSummary();
  return (eventsum.primaryVertexPosition()).y() ;  
}

Float_t  TStMuCutEventJet::GetVertexX(StMuEvent *Event)
{
  StEventSummary &eventsum = Event->eventSummary();
  return (eventsum.primaryVertexPosition()).x() ;    
}


UInt_t TStMuCutEventJet::GetL0TriggerWord(StMuEvent *Event)
{ 
  StL0Trigger& l0Trigger  = Event->l0Trigger();
  return l0Trigger.triggerWord();
}


Double_t  TStMuCutEventJet::GetReactionPlane(StMuEvent *Event, UShort_t s)
{
  return 0;//Event->reactionPlane(s);
}


Double_t  TStMuCutEventJet::GetReactionPlanePtWgt(StMuEvent *Event, UShort_t s)
{
  return 0;//Event->reactionPlanePtWgt(s); 
}
