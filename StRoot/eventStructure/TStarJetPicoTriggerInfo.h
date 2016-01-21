#ifndef __TSTARJETPICOTRIGGERINFO_HH
#define __TSTARJETPICOTRIGGERINFO_HH

#include <TObject.h>
#include <TString.h>

class TStarJetPicoTriggerInfo : public TObject
{
 public:
  TStarJetPicoTriggerInfo();
  TStarJetPicoTriggerInfo(const TStarJetPicoTriggerInfo &t);
  // TStarJetPicoTriggerInfo(TString trigtype,Int_t flag,Float_t eta, Float_t phi);
  virtual ~TStarJetPicoTriggerInfo();

  void    Clear(Option_t *Option = "");

  //Setters
  // void SetTriggerType(TString trigtype){fTrigType=trigtype;}
  void SetEta(Float_t eta) {fEta=eta;}
  void SetPhi(Float_t phi) {fPhi=phi;}
  void SetTriggerFlag(Int_t flag) {fTrigFlag=flag;}
  void SetId(Int_t id) {fId=id;}
  void SetADC(Int_t ADC) {fADC=ADC;}

  //Getters
  //TString GetTriggerType() const {return fTrigType;}
  Float_t GetEta() const {return fEta;}
  Float_t GetPhi() const {return fPhi;}
  Int_t GetTriggerFlag() const {return fTrigFlag;}
  Int_t isJPL0();
  Int_t isJPL2(); 
  Int_t isJPS();
  Int_t isHTL0();
  Int_t isHTL2();
  Int_t isHTS();
  Int_t isBBC();
  void PrintInfo();
  Int_t GetId() const {return fId;}
  Int_t GetADC() const {return fADC;}


 private:
  //TString fTrigType; //JetPatchL0,JetPatchL2,HighTowerL0,HighTowerL2
  Float_t fEta; //eta of the tower/patch in the reference frame 0,0,0 
  Float_t fPhi; //phi of the tower/patch in the reference frame 0,0,0 
  Int_t fTrigFlag;//1=HTL0, 2=JPL0, 3=HTL2, 4=JPL2
  Int_t fId; // id of the tower that fired this trigger
  Int_t fADC; // its ADC value

 ClassDef(TStarJetPicoTriggerInfo, 2)
   };

#endif
