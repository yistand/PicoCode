#include "TStarJetPicoPrimaryTrack.h"

ClassImp(TStarJetPicoPrimaryTrack)

TStarJetPicoPrimaryTrack::TStarJetPicoPrimaryTrack()
  : TObject()
  , fCharge(0)      
  , fNFittedHits(0) 
  , fNHitsPoss(0)   
  , fKey(0)            
  , fPx(0)             
  , fPy(0)             
  , fPz(0)                        
  , fDCA(0)            
  , fdEdx(0)           
  , fNsigmaPion(0)   
  , fNsigmaKaon(0)   
  , fNsigmaProton(0)
  , fNsigmaElectron(0)
  , fsDCAxy(0)
  , fChi2(0)
  , fChi2PV(0)
  , fFlag(0)
  , fTofTime(-9.)
  , fTofBeta(-9.)
  , fTofyLocal(-9.)
{
  ;
}

TStarJetPicoPrimaryTrack::TStarJetPicoPrimaryTrack(const TStarJetPicoPrimaryTrack &t)
  : TObject(t)
  , fCharge(t.fCharge)      
  , fNFittedHits(t.fNFittedHits) 
  , fNHitsPoss(t.fNHitsPoss)   
  , fKey(t.fKey)            
  , fPx(t.fPx)             
  , fPy(t.fPy)             
  , fPz(t.fPz)                      
  , fDCA(t.fDCA)            
  , fdEdx(t.fdEdx)           
  , fNsigmaPion(t.fNsigmaPion)   
  , fNsigmaKaon(t.fNsigmaKaon)   
  , fNsigmaProton(t.fNsigmaProton)
  , fNsigmaElectron(t.fNsigmaElectron)
  , fsDCAxy(t.fsDCAxy)
  , fChi2(t.fChi2)
  , fChi2PV(t.fChi2PV)
  , fFlag(t.fFlag)
  , fTofTime(t.fTofTime)
  , fTofBeta(t.fTofBeta)
  , fTofyLocal(t.fTofyLocal)
{
  ;
}

TStarJetPicoPrimaryTrack::~TStarJetPicoPrimaryTrack()
{
  ;
}

void TStarJetPicoPrimaryTrack::Clear(Option_t */*Option*/)
{
  fCharge = 0;      
  fNFittedHits = 0; 
  fNHitsPoss = 0;   
  fKey = 0;            
  fPx = 0;             
  fPy = 0;             
  fPz = 0;                      
  fDCA = 0;            
  fdEdx = 0;           
  fNsigmaPion = 0;   
  fNsigmaKaon = 0;   
  fNsigmaProton = 0;
  fNsigmaElectron = 0;
  fsDCAxy = 0;
  fChi2 = 0;
  fChi2PV = 0;
  fFlag = 0;
  fTofTime = -9.;
  fTofBeta = -9.;
  fTofyLocal = -9.;
}

Float_t TStarJetPicoPrimaryTrack::GetEta()
{
  double costheta = fPz/TMath::Sqrt(fPx*fPx+fPy*fPy+fPz*fPz);
  return TMath::ATanH(costheta);
}
