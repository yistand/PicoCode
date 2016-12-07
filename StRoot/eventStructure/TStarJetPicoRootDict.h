/********************************************************************
* TStarJetPicoRootDict.h
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************************/
#ifdef __CINT__
#error TStarJetPicoRootDict.h/C is only for compilation. Abort cint.
#endif
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define G__ANSIHEADER
#define G__DICTIONARY
#define G__PRIVATE_GVALUE
#include "G__ci.h"
#include "FastAllocString.h"
extern "C" {
extern void G__cpp_setup_tagtableTStarJetPicoRootDict();
extern void G__cpp_setup_inheritanceTStarJetPicoRootDict();
extern void G__cpp_setup_typetableTStarJetPicoRootDict();
extern void G__cpp_setup_memvarTStarJetPicoRootDict();
extern void G__cpp_setup_globalTStarJetPicoRootDict();
extern void G__cpp_setup_memfuncTStarJetPicoRootDict();
extern void G__cpp_setup_funcTStarJetPicoRootDict();
extern void G__set_cpp_environmentTStarJetPicoRootDict();
}


#include "TObject.h"
#include "TMemberInspector.h"
#include "TStarJetPicoDefinitions.h"
#include "TStarJetPicoDemoClass.h"
#include "TStarJetPicoEventCuts.h"
#include "TStarJetPicoEvent.h"
#include "TStarJetPicoEventHeader.h"
#include "TStarJetPicoPrimaryTrack.h"
#include "TStarJetPicoQAHistograms.h"
#include "TStarJetPicoReaderBase.h"
#include "TStarJetPicoReader.h"
#include "TStarJetPicoTowerCuts.h"
#include "TStarJetPicoTower.h"
#include "TStarJetPicoTrackCuts.h"
#include "TStarJetPicoTriggerInfo.h"
#include "TStarJetPicoUtils.h"
#include "TStarJetPicoV0Cuts.h"
#include "TStarJetPicoV0.h"
#include "TStarJetVectorContainer.h"
#include "TStarJetVector.h"
#include "TStarJetVectorJet.h"
#include "TStarJetReaderParticleContainer.h"
#include <algorithm>
namespace std { }
using namespace std;

#ifndef G__MEMFUNCBODY
#endif

extern G__linked_taginfo G__TStarJetPicoRootDictLN_TClass;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TBuffer;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TDirectory;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMemberInspector;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TObject;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TNamed;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TString;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TList;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TClonesArray;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetPicoDefinitions;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetPicoDefinitionscLcLEVENT_FEATURES;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetPicoPrimaryTrack;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetPicoTrackCuts;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_vectorlEvectorlEdoublecOallocatorlEdoublegRsPgRcOallocatorlEvectorlEdoublecOallocatorlEdoublegRsPgRsPgRsPgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_reverse_iteratorlEvectorlEvectorlEdoublecOallocatorlEdoublegRsPgRcOallocatorlEvectorlEdoublecOallocatorlEdoublegRsPgRsPgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetPicoDemoClass;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TFile;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TBranch;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TArrayD;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TArrayI;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_maplEstringcOTObjArraymUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOTObjArraymUgRsPgRsPgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TChain;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetPicoEvent;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetPicoEventCuts;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TRef;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetPicoEventHeader;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetPicoTower;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetPicoV0;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetPicoTriggerInfo;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TH1F;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TH1D;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TH2D;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetPicoQAHistograms;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMatrixTBaselEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMatrixTBaselEdoublegR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TVectorTlEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TVectorTlEdoublegR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TElementActionTlEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TElementPosActionTlEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMatrixTlEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMatrixTRow_constlEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMatrixTRowlEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMatrixTDiag_constlEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMatrixTColumn_constlEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMatrixTFlat_constlEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMatrixTSub_constlEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMatrixTSparseRow_constlEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMatrixTSparseDiag_constlEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMatrixTColumnlEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMatrixTDiaglEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMatrixTFlatlEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMatrixTSublEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMatrixTSparseRowlEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TMatrixTSparseDiaglEfloatgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TLorentzVector;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetVector;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetVectorcLcL_FEATUREINDEX_D;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetVectorcLcL_FEATUREINDEX_I;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetVectorcLcL_CUSTOMTYPE;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetVectorcLcL_CHARGETYPE;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStopwatch;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetPicoReaderBase;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetVectorContainerlETStarJetVectorgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetPicoV0Cuts;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetPicoTowerCuts;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetPicoReader;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_vectorlEintcOallocatorlEintgRsPgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_reverse_iteratorlEvectorlEintcOallocatorlEintgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_setlEintcOlesslEintgRcOallocatorlEintgRsPgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetPicoUtils;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_valarraylEdoublegR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetVectorJet;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetVectorJetcLcLFEATURESD;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetReaderParticleContainer;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetVectorContainerlETStarJetVectorJetgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetVectorContainerlETLorentzVectorgR;
extern G__linked_taginfo G__TStarJetPicoRootDictLN_TStarJetVectorContainerlETObjectgR;

/* STUB derived class for protected member access */
typedef TStarJetVectorContainer<TStarJetVector> G__TStarJetVectorContainerlETStarJetVectorgR;
typedef TStarJetVectorContainer<TStarJetVectorJet> G__TStarJetVectorContainerlETStarJetVectorJetgR;
typedef TStarJetVectorContainer<TLorentzVector> G__TStarJetVectorContainerlETLorentzVectorgR;
typedef TStarJetVectorContainer<TObject> G__TStarJetVectorContainerlETObjectgR;
