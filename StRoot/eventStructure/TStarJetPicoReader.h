#ifndef __TSTARJETPICOREADER_HH
#define __TSTARJETPICOREADER_HH

#include <TObject.h>
#include <TH1.h>
#include <TString.h>
#include "TStarJetVectorContainer.h"

class TStarJetPicoEventCuts;
class TStarJetPicoPrimaryTrack;
class TStarJetPicoTower;
class TStarJetPicoV0;
class TStarJetPicoV0Cuts;
class TStarJetPicoTriggerInfo;
class TStarJetPicoTrackCuts;
class TStarJetPicoTowerCuts;

class TChain;
class TBranch;
class TArrayI;
class TList;
class TStopwatch;

#include "TStarJetPicoReaderBase.h"

class TStarJetPicoReader : public TStarJetPicoReaderBase
{
 public:

  TStarJetPicoReader();
  virtual ~TStarJetPicoReader();

  TStarJetPicoEventCuts* GetEventCuts() {return fEventCuts;}
  TStarJetPicoTrackCuts* GetTrackCuts() {return fTrackCuts;}
  TStarJetPicoTowerCuts* GetTowerCuts() {return fTowerCuts;}
  TStarJetPicoV0Cuts*    GetV0Cuts()    {return fV0Cuts;}

  void SetRejectTowerElectrons(Bool_t val) {fRejectTowerElectrons = val;}
  void SetApplyMIPCorrection(Bool_t val);
  void SetApplyFractionHadronicCorrection(Bool_t val);
  void SetFractionHadronicCorrection(Double_t val);
  void SetTrackPileUpCut(int val);

  virtual void SetEventCuts(TStarJetPicoEventCuts* evCuts);
  virtual void SetTrackCuts(TStarJetPicoTrackCuts* trCuts);
  virtual void SetTowerCuts(TStarJetPicoTowerCuts* twCuts);
  virtual void SetV0Cuts(TStarJetPicoV0Cuts* v0Cuts);
    
    //nick elsey: added to allow for run ID rejection
  void AddMaskedRun(Int_t Id);
  void AddMaskedRuns(std::vector<Int_t> Ids);

  TH1D* GetHadronicResult() { return HadronicResult; }; // note that you may have to clone this guy cause it'll be deleted.

 protected:
  
  virtual Bool_t LoadEvent();
  virtual Bool_t LoadV0s(TArrayI *trackIdsToRemove);
  virtual Bool_t LoadTracks(TArrayI *trackIdsToRemove);
  virtual Bool_t LoadTowers();

 private:

  TStarJetPicoEventCuts* fEventCuts; //! cuts for event selection
  TStarJetPicoTrackCuts* fTrackCuts;//! cuts tracks
  TStarJetPicoTowerCuts* fTowerCuts;//! cuts tower
  TStarJetPicoV0Cuts*    fV0Cuts;//! cuts for V0s
  std::vector<Int_t>     fMaskedRuns;// nick elsey: added to reject specific run numbers

  Bool_t   fRejectTowerElectrons; // Make sure we do not double count the electrons.
  Bool_t   fApplyMIPCorrection; // Apply MIP or not? Exclusive with fApplyFractionHadronicCorrection
  Bool_t   fApplyFractionHadronicCorrection; // Another type of charge particles energy depostion in EMC.
  Double_t fFractionHadronicCorrection; // Fraction of momentum of the TPC track to be subtracted from EMC tower.
 
  Int_t   fTrackPileUpCut;	// #ly Li Yi 2015.10.19		whether apply pile up cut, currently matching TPC tracks to bemc or tof
				// #ly Li Yi 2016.01.22		0: no pile up cut. 1: match to bemc or tof. 2: match to tof
  
  // DEBUG
  /// To count the number of rejected towers
  TH1D* HadronicResult;
  

  ClassDef(TStarJetPicoReader, 1)
};

#endif
