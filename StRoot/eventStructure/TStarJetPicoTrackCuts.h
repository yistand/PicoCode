#ifndef __TSTARJETPICOTRACKCUTS_HH
#define __TSTARJETPICOTRACKCUTS_HH

#include <TObject.h>

class TStarJetPicoPrimaryTrack;

class TStarJetPicoTrackCuts : public TObject
{
 public:
  TStarJetPicoTrackCuts();
  TStarJetPicoTrackCuts(const TStarJetPicoTrackCuts &t);
  virtual ~TStarJetPicoTrackCuts() {;} // nothing to delete

  virtual Bool_t   IsDCAOK(TStarJetPicoPrimaryTrack *tr);
  virtual Bool_t   IsMinNFitPointsOK(TStarJetPicoPrimaryTrack *tr);
  virtual Bool_t   IsFitOverMaxPointsOK(TStarJetPicoPrimaryTrack *tr);
  virtual Bool_t   IsMaxPtOK(TStarJetPicoPrimaryTrack *tr);
  virtual Bool_t   IsChi2OK(TStarJetPicoPrimaryTrack *tr);
  virtual Bool_t   IsPCTOK(TStarJetPicoPrimaryTrack *tr);

  virtual Bool_t   IsTrackOK(TStarJetPicoPrimaryTrack *tr);
  virtual Bool_t   CheckTrackQA(TStarJetPicoPrimaryTrack *tr);

  virtual Int_t    DoPID(TStarJetPicoPrimaryTrack */*tr*/) {return 0;}

  void SetDCACut(Double_t val) {fMaxDCA = val;}
  void SetMinNFitPointsCut(Int_t val) {fMinNfit = val;}
  void SetFitOverMaxPointsCut(Double_t val) {fFitOverMax = val;}
  void SetMaxPtCut(Double_t val) {fMaxPt = val;}

  void SetMaxChi2Cut(Double_t val) {fFlagMaxChi2=kTRUE; fMaxChi2 = val;}
  void SetMaxChi2CutOff() {fFlagMaxChi2=kFALSE;}
  void SetPCTCut(Bool_t val) {fPCT = val;}

  Double_t GetDCACut() {return fMaxDCA;}
  Int_t    GetMinNFitPointsCut() {return fMinNfit;}
  Double_t GetFitOverMaxPointsCut() {return fFitOverMax;}
  Double_t GetMaxPtCut() {return fMaxPt;}
    
    // nick elsey: the range of phi values accepted; initially set at 0,0 - accepts everything
    // to cut out a region, in [-Pi,Pi] MinPhi > MaxPhi
    // added for year 11 analysis to help deal with a bad region in the TPC
  Bool_t SetPhiCut(Double_t min, Double_t max);
    
  Double_t GetMinPhiCut() {return fMinPhi;}
  Double_t GetMaxPhiCut() {return fMaxPhi;}
  

 private:

  Double_t fMaxDCA;
  Int_t    fMinNfit;
  Double_t fFitOverMax;
  Double_t fMaxPt;
    
  Double_t fMinPhi;
  Double_t fMaxPhi;

  Double_t fMaxChi2;
  Bool_t   fPCT;
  Bool_t   fFlagMaxChi2;

  ClassDef(TStarJetPicoTrackCuts, 2)
};

#endif
