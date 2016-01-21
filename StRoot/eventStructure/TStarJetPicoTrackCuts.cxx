#include "TStarJetPicoTrackCuts.h"
#include "TStarJetPicoPrimaryTrack.h"
#include "TStarJetPicoDefinitions.h"

#include <TMath.h>
#include <TString.h>

/////////////////////////////////////////////////////////////////////////
//                                                                     //
// TStarJetPicoTrackCuts                                               //
//                                                                     //
// Default cuts implemented.                                           //
// Lots of virtual functions... so overload in derived classes and     //
// pass to TStarJetPicoReader via TStarJetPicoReader::SetTrackCuts     //
// TStarJetPicoReader::LoadTracks() calls ::IsTrackOK method.          //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

ClassImp(TStarJetPicoTrackCuts)

TStarJetPicoTrackCuts::TStarJetPicoTrackCuts()
  : TObject()
  , fMaxDCA(1.0)
  , fMinNfit(20)
  , fFitOverMax(0.52)
  , fMaxPt(1000.) // by default, no cut effectively
  , fMinPhi(0.0)
  , fMaxPhi(0.0)
  , fMaxChi2(1000.) // no cut effectively
  , fPCT(kFALSE)
  , fFlagMaxChi2(kFALSE)
{
  __DEBUG(2, "Creating track cuts with default values.");  
}

TStarJetPicoTrackCuts::TStarJetPicoTrackCuts(const TStarJetPicoTrackCuts &t)
  : TObject(t)
  , fMaxDCA(t.fMaxDCA)
  , fMinNfit(t.fMinNfit)
  , fFitOverMax(t.fFitOverMax)
  , fMaxPt(t.fMaxPt)
  , fMinPhi(t.fMinPhi)
  , fMaxPhi(t.fMaxPhi)
  , fMaxChi2(t.fMaxChi2)
  , fPCT(t.fPCT)
  , fFlagMaxChi2(t.fFlagMaxChi2)
{
  __DEBUG(2, "Copy track cuts.");  
}

Bool_t TStarJetPicoTrackCuts::IsDCAOK(TStarJetPicoPrimaryTrack *tr)
{
  if (TMath::Abs(tr->GetDCA()) < fMaxDCA)
    {
      __DEBUG(9, Form("Accept. %f < %f", TMath::Abs(tr->GetDCA()), fMaxDCA));
      return kTRUE; 
    }

  __DEBUG(9, Form("Reject. ! %f < %f", TMath::Abs(tr->GetDCA()), fMaxDCA));
  return kFALSE;
}

Bool_t TStarJetPicoTrackCuts::IsMinNFitPointsOK(TStarJetPicoPrimaryTrack *tr)
{
  if (tr->GetNOfFittedHits() > fMinNfit)
    {
      __DEBUG(9, Form("Accept. %d > %d", tr->GetNOfFittedHits(), fMinNfit));
      return kTRUE;
    }

  __DEBUG(9, Form("Reject. ! %d > %d", tr->GetNOfFittedHits(), fMinNfit));
  return kFALSE;
}

Bool_t TStarJetPicoTrackCuts::IsFitOverMaxPointsOK(TStarJetPicoPrimaryTrack *tr)
{
  Double_t ratio = 1.;
  ratio = (ratio * tr->GetNOfFittedHits()) / (ratio * tr->GetNOfPossHits());

  if (ratio > fFitOverMax)
    {
      __DEBUG(9, Form("Accept. %f > %f", ratio, fFitOverMax));
      return kTRUE;
    }
  
  __DEBUG(9, Form("Reject. ! %f > %f", ratio, fFitOverMax));
  return kFALSE;
}

Bool_t TStarJetPicoTrackCuts::IsMaxPtOK(TStarJetPicoPrimaryTrack *tr)
{
  Double_t pt = TMath::Sqrt(tr->GetPx()*tr->GetPx() + tr->GetPy()*tr->GetPy());;
  if (pt < fMaxPt)
    {
      __DEBUG(9, Form("Accept. %f < %f", pt, fMaxPt));
      return kTRUE;
    }
  
  __DEBUG(9, Form("Reject. ! %f < %f", pt, fMaxPt));
  return kFALSE;
}

Bool_t  TStarJetPicoTrackCuts::IsChi2OK(TStarJetPicoPrimaryTrack *tr) {
  if (fFlagMaxChi2==kTRUE) {
    Float_t chi2 = tr->GetChi2PV();
    if (chi2<fMaxChi2) {
      __DEBUG(9, Form("Accept. %f < %f", chi2, fMaxChi2));
      return kTRUE;
    } 
    
    __DEBUG(9, Form("Reject. ! %f < %f",chi2, fMaxChi2));
    return kFALSE;
  }
  else {
    __DEBUG(9, Form("Accept. Not checking chi2 cut!"));
    return kTRUE;
  }
}


Bool_t  TStarJetPicoTrackCuts::IsPCTOK(TStarJetPicoPrimaryTrack *tr) {
  if (fPCT==kTRUE) {
    Int_t flag=tr->GetFlag();
    if (flag<1000) {
      __DEBUG(9, Form("Accept. Track flag < 1000"));
      return kTRUE;
    }

    __DEBUG(9, Form("Reject. Track flag >=1000: PCT track!"));
    return kFALSE;
  }
  else {
    __DEBUG(9, Form("Accept. Track flag not checked."));
    return kTRUE;
  }
}

Bool_t TStarJetPicoTrackCuts::IsTrackOK(TStarJetPicoPrimaryTrack *tr)
{
  return IsDCAOK(tr) && IsMinNFitPointsOK(tr) && IsFitOverMaxPointsOK(tr) && IsMaxPtOK(tr) && IsChi2OK(tr) && IsPCTOK(tr);
}

Bool_t TStarJetPicoTrackCuts::CheckTrackQA(TStarJetPicoPrimaryTrack *tr)
{
  return IsTrackOK(tr);
}

Bool_t TStarJetPicoTrackCuts::SetPhiCut(Double_t min, Double_t max)
{
    Bool_t retval = kTRUE;
    if ( min > TMath::Pi() || min < (-1.0)*TMath::Pi() ) {
        __ERROR("Phi minimum cut out of bounds [-Pi,Pi]");
        retval = kFALSE;
    }
    if ( max > TMath::Pi() || max < (-1.0)*TMath::Pi() ) {
        __ERROR("Phi maximum cut out of bounds [-Pi,Pi]");
        retval = kFALSE;
    }
    if (!retval)
        return retval;
    
    fMinPhi = min;
    fMaxPhi = max;
    return kTRUE;
}
