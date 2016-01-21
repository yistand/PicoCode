#ifndef __TSTARJETPICOTOWERCUTS_HH
#define __TSTARJETPICOTOWERCUTS_HH

#include <TObject.h>

#include <set>

class TStarJetPicoEvent;
class TStarJetPicoTower;
class TStarJetPicoTrackCuts;

class TStarJetPicoTowerCuts : public TObject
{
 public:
  TStarJetPicoTowerCuts();
  TStarJetPicoTowerCuts(const TStarJetPicoTowerCuts &t);
  virtual ~TStarJetPicoTowerCuts() {;} // nothing to delete

  virtual Bool_t IsTowerOK(TStarJetPicoTower *tw, TStarJetPicoEvent *mEv);
  virtual Bool_t CheckTowerQA(TStarJetPicoTower *tw, TStarJetPicoEvent *mEv);
    
  /*   //nick elsey: allows you to set your own hot and dead towers */
  /* Bool_t CheckTowerAgainstLists(TStarJetPicoTower *tw); */
  /* Bool_t AddHotTower(Int_t Id); */
  /* Bool_t AddDeadTower(Int_t Id); */
  /* Bool_t AddHotTowers(std::vector<Int_t> Ids); */
  /* Bool_t AddDeadTowers(std::vector<Int_t> Ids); */

  // KK: Use one set to reject bad towers
  void ResetBadTowerList( );
  Bool_t AddBadTowers(TString csvfile);

    

  virtual Double_t TowerEnergyMipCorr(TStarJetPicoTower *mTower);

  virtual Double_t HadronicCorrection(TStarJetPicoTower *mTower,
			      TStarJetPicoEvent *mEvent,
			      TStarJetPicoTrackCuts *trackQA,
			      Double_t frac);

  virtual Int_t    DoPID(TStarJetPicoTower */*tw*/) {return 0;}

  void SetMaxEtCut(Double_t val) {fMaxEt = val;}
  Double_t GetMaxEtCut() {return fMaxEt;}
    
  // nick elsey: the range of phi values accepted; initially set at 0,0 - accepts everything
  // to cut out a region in [-Pi,Pi], MinPhi > MaxPhi
  // added for year 11 analysis to help deal with a bad region in the TPC
  Bool_t SetPhiCut(Double_t min, Double_t max);
    
  Double_t GetMaxPhiCut() {return fMaxPhi;}
  Double_t GetMinPhiCut() {return fMinPhi;}

  void Sety8PythiaCut(Bool_t val) {y8PythiaCut = val;}
  Bool_t Gety8PythiaCut() {return y8PythiaCut;}

 private:
  /// KK: Replacement for IsTowerOK(Int_t mTowId, Int_t mTrigId)
  Bool_t IsTowerOK( Int_t mTowId );

  /// The other method of this name has extra checks, this one shouldn't be used by itself
  virtual Bool_t IsTowerOK(Int_t mTowId, Int_t mTrigId);

  Double_t fMaxEt;
  
  Double_t fMaxPhi;
  Double_t fMinPhi;
  
  Bool_t y8PythiaCut;
    
  // KK: Just use one set of rejected towers
  std::set<Int_t> badTowers; 
  /* std::set<Int_t> hotTowers; */
  /* std::set<Int_t> deadTowers; */

  ClassDef(TStarJetPicoTowerCuts, 3)
};

#endif
