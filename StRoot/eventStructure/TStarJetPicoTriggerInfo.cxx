#include "TStarJetPicoTriggerInfo.h"
#include "Riostream.h"
ClassImp(TStarJetPicoTriggerInfo)

//____________________________________________________
TStarJetPicoTriggerInfo::TStarJetPicoTriggerInfo()
 : TObject()
  // , fTrigType(0)
   , fEta(0)
   , fPhi(0)
 , fTrigFlag(0)
   , fId(0)
   , fADC(0)
{}
//____________________________________________________
TStarJetPicoTriggerInfo::TStarJetPicoTriggerInfo(const TStarJetPicoTriggerInfo &t)
: TObject(t)
  //, fTrigType(t.fTrigType)
  , fEta(t.fEta)
  , fPhi(t.fPhi)
  , fTrigFlag(t.fTrigFlag)
  , fId(t.fId)
  , fADC(t.fADC)
{}

//____________________________________________________
// TStarJetPicoTriggerInfo::TStarJetPicoTriggerInfo(TString trigtype,Int_t flag,Float_t eta, Float_t phi){
//   fTrigType=trigtype;
//   fEta=eta;
//   fPhi=phi;
//   fTrigFlag=flag;
// }
//____________________________________________________
TStarJetPicoTriggerInfo::~TStarJetPicoTriggerInfo(){
  //destructor
  fEta=0;
  fPhi=0;
  fTrigFlag=0;
  fId=0;
  fADC=0;
}
//____________________________________________________
Int_t TStarJetPicoTriggerInfo::isJPL0(){
  if(fTrigFlag==2)return 1;
  else return 0;
}
//____________________________________________________
Int_t TStarJetPicoTriggerInfo::isJPL2(){
  if(fTrigFlag==4)return 1;
  else return 0;
}
//____________________________________________________
Int_t TStarJetPicoTriggerInfo::isJPS(){
  if(fTrigFlag==6)return 1;
  else return 0;
}
//____________________________________________________
Int_t TStarJetPicoTriggerInfo::isHTL0(){
  if(fTrigFlag==1)return 1;
  else return 0;
}
//____________________________________________________
Int_t TStarJetPicoTriggerInfo::isHTL2(){
  if(fTrigFlag==3)return 1;
  else return 0;
}
//____________________________________________________
Int_t TStarJetPicoTriggerInfo::isHTS(){
  if(fTrigFlag==7)return 1;
  else return 0;
}

//____________________________________________________
Int_t TStarJetPicoTriggerInfo::isBBC(){
  if(fTrigFlag==5)return 1;
  else return 0;
}
//____________________________________________________
void TStarJetPicoTriggerInfo::Clear(Option_t */*Option*/){
  // fTrigType="";
  fEta=0;
  fPhi=0;
  fTrigFlag=0;
  fId=0;
  fADC=0;

}
//____________________________________________________
void TStarJetPicoTriggerInfo::PrintInfo(){
  std::cout<<"=============== Trigger Info =============="<<std::endl;
  if(fTrigFlag==1)std::cout<<"HTL0;  eta="<<fEta<<"   phi="<<fPhi<<"   id="<<fId<<"   ADC="<<fADC<<std::endl;
  if(fTrigFlag==2)std::cout<<"JPL0;  eta="<<fEta<<"   phi="<<fPhi<<"   id="<<fId<<"   ADC="<<fADC<<std::endl;
  if(fTrigFlag==3)std::cout<<"HTL2;  eta="<<fEta<<"   phi="<<fPhi<<"   id="<<fId<<"   ADC="<<fADC<<std::endl;
  if(fTrigFlag==4)std::cout<<"JPL2;  eta="<<fEta<<"   phi="<<fPhi<<"   id="<<fId<<"   ADC="<<fADC<<std::endl;
  std::cout<<"=========================================="<<std::endl;
}
