// example.C

#ifndef ROOT_TGDockableFrame
#include "TGDockableFrame.h"
#endif
#ifndef ROOT_TGMdiDecorFrame
#include "TGMdiDecorFrame.h"
#endif
#ifndef ROOT_TG3DLine
#include "TG3DLine.h"
#endif
#ifndef ROOT_TGMdiFrame
#include "TGMdiFrame.h"
#endif
#ifndef ROOT_TGMdiMainFrame
#include "TGMdiMainFrame.h"
#endif
#ifndef ROOT_TGMdiMenu
#include "TGMdiMenu.h"
#endif
#ifndef ROOT_TGListBox
#include "TGListBox.h"
#endif
#ifndef ROOT_TGNumberEntry
#include "TGNumberEntry.h"
#endif
#ifndef ROOT_TGScrollBar
#include "TGScrollBar.h"
#endif
#ifndef ROOT_TGComboBox
#include "TGComboBox.h"
#endif
#ifndef ROOT_TGuiBldHintsEditor
#include "TGuiBldHintsEditor.h"
#endif
#ifndef ROOT_TRootBrowser
#include "TRootBrowser.h"
#endif
#ifndef ROOT_TGuiBldNameFrame
#include "TGuiBldNameFrame.h"
#endif
#ifndef ROOT_TGFrame
#include "TGFrame.h"
#endif
#ifndef ROOT_TGMenu
#include "TGMenu.h"
#endif
#ifndef ROOT_TGFileDialog
#include "TGFileDialog.h"
#endif
#ifndef ROOT_TGShutter
#include "TGShutter.h"
#endif
#ifndef ROOT_TGButtonGroup
#include "TGButtonGroup.h"
#endif
#ifndef ROOT_TGCommandPlugin
#include "TGCommandPlugin.h"
#endif
#ifndef ROOT_TGCanvas
#include "TGCanvas.h"
#endif
#ifndef ROOT_TGFSContainer
#include "TGFSContainer.h"
#endif
#ifndef ROOT_TGuiBldEditor
#include "TGuiBldEditor.h"
#endif
#ifndef ROOT_TGColorSelect
#include "TGColorSelect.h"
#endif
#ifndef ROOT_TGTextEdit
#include "TGTextEdit.h"
#endif
#ifndef ROOT_TGButton
#include "TGButton.h"
#endif
#ifndef ROOT_TRootContextMenu
#include "TRootContextMenu.h"
#endif
#ifndef ROOT_TGFSComboBox
#include "TGFSComboBox.h"
#endif
#ifndef ROOT_TGLabel
#include "TGLabel.h"
#endif
#ifndef ROOT_TGView
#include "TGView.h"
#endif
#ifndef ROOT_TGMsgBox
#include "TGMsgBox.h"
#endif
#ifndef ROOT_TRootGuiBuilder
#include "TRootGuiBuilder.h"
#endif
#ifndef ROOT_TGFileBrowser
#include "TGFileBrowser.h"
#endif
#ifndef ROOT_TGTab
#include "TGTab.h"
#endif
#ifndef ROOT_TGListView
#include "TGListView.h"
#endif
#ifndef ROOT_TGSplitter
#include "TGSplitter.h"
#endif
#ifndef ROOT_TGTextEditor
#include "TGTextEditor.h"
#endif
#ifndef ROOT_TRootCanvas
#include "TRootCanvas.h"
#endif
#ifndef ROOT_TGStatusBar
#include "TGStatusBar.h"
#endif
#ifndef ROOT_TGListTree
#include "TGListTree.h"
#endif
#ifndef ROOT_TGuiBldGeometryFrame
#include "TGuiBldGeometryFrame.h"
#endif
#ifndef ROOT_TGToolTip
#include "TGToolTip.h"
#endif
#ifndef ROOT_TGToolBar
#include "TGToolBar.h"
#endif
#ifndef ROOT_TRootEmbeddedCanvas
#include "TRootEmbeddedCanvas.h"
#endif
#ifndef ROOT_TCanvas
#include "TCanvas.h"
#endif
#ifndef ROOT_TGuiBldDragManager
#include "TGuiBldDragManager.h"
#endif
#ifndef ROOT_TGHtmlBrowser
#include "TGHtmlBrowser.h"
#endif

#include <TApplication.h>
#include <TGClient.h>
#include <TF1.h>
#include <TImage.h>
#include <TLatex.h>
#include <TPaveText.h>
#include <TCurlyLine.h>
#include <TEllipse.h>
#include <TGraph.h>
#include <TLine.h>
#include <TAxis.h>
#include <TMarker.h>
#include <TLegend.h>
#include <TSystem.h>
#include <TStyle.h>
#include <TArrow.h>
#include <TString.h>
#include <TSystem.h>
#include <TBox.h>
#include "Riostream.h"

#include <GuiTypes.h>
#include <algorithm>

#include "SEHDFo_v1.h"
#include "include/masPlot.h"
#include "include/forcedPlot.h"

MyMainFrame::MyMainFrame(const TGWindow *p,UInt_t w,UInt_t h) {

  
  TString spathHIDEN_FILE(gSystem->HomeDirectory());
  //cout << "spathHIDEN_FILE: " << spathHIDEN_FILE << endl;
  spathHIDEN_FILE.Append("/.pathDIR_HDFoSoftEdu_v1.txt");
  //cout << "spathHIDEN_FILE: " << spathHIDEN_FILE << endl;

  ifstream inHidenFile;
  inHidenFile.open(spathHIDEN_FILE);
  
  string spathICONS;
  getline(inHidenFile,spathICONS);
  pathDIR_ICONS.Append(spathICONS);
  pathDIR_ICONS.Append("/icons/");
  //cout << pathDIR_ICONS  << endl;
  
  // main frame
  fMainFrameHDFOSC = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);
  //fMainFrameHDFOSC = new TGMainFrame(gClient->GetRoot(),10,10, kVerticalFrame);
  //fMainFrameHDFOSC->SetName("fMainFrame");
  //fMainFrameHDFOSC->SetLayoutBroken(kTRUE);
  
  //Create a main frame
  //fMainFrameHDFOSC = new TGMainFrame(p,w,h);
  
  fMainFrameHDFOSC->SetName("fMainFrameHDFOSC");
  fMainFrameHDFOSC->SetLayoutBroken(kTRUE);

   
  // vertical frame
  TGVerticalFrame *fVerticalFrameV = new TGVerticalFrame(fMainFrameHDFOSC,25,500,kVerticalFrame);
  fVerticalFrameV->SetName("fVerticalFrameV");
  //fVerticalFrameV->SetLayoutBroken(kTRUE);
  
  ULong_t ucolor;        // will reflect user color changes
  gClient->GetColorByName("#cccc99",ucolor);
  
  // "Timing and Forced oscillations" group frame
  TGGroupFrame *fGroupFrameFO = new TGGroupFrame(fVerticalFrameV,"Timing and Forced oscillations",kVerticalFrame,TGGroupFrame::GetDefaultGC()(),TGGroupFrame::GetDefaultFontStruct(),ucolor);
  fGroupFrameFO->SetLayoutBroken(kTRUE);

  fCheckButtonFORCED = new TGCheckButton(fGroupFrameFO,"Run forced oscillations");
  fCheckButtonFORCED->ChangeBackground(ucolor);
  fCheckButtonFORCED->SetTextJustify(36);
  fCheckButtonFORCED->SetMargins(0,0,0,0);
  fCheckButtonFORCED->SetWrapLength(-1);
  fGroupFrameFO->AddFrame(fCheckButtonFORCED, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fCheckButtonFORCED->MoveResize(16,67,160,17);

  
  fNumberEntryDT = new TGNumberEntry(fGroupFrameFO, (Double_t) 0,9,-1,(TGNumberFormat::EStyle) 5);
  fGroupFrameFO->AddFrame(fNumberEntryDT, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fNumberEntryDT->MoveResize(20,35,80,20);
  fNumberEntryDT->SetNumber(0.1);
  //fNumberEntryDT->SetNumAttr(TGNumberFormat::kNEAPositive);
  fNumberEntryDT->SetLimits(TGNumberFormat::kNELLimitMin, 0.05);


  fNumberEntryRT = new TGNumberEntry(fGroupFrameFO, (Double_t) 0,9,-1,(TGNumberFormat::EStyle) 5);
  fGroupFrameFO->AddFrame(fNumberEntryRT, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fNumberEntryRT->MoveResize(140,35,80,20);
  fNumberEntryRT->SetNumber(10.0);
  fNumberEntryRT->SetLimits(TGNumberFormat::kNELLimitMin, 0.1);

  fNumberEntryFO = new TGNumberEntry(fGroupFrameFO, (Double_t) 0,9,-1,(TGNumberFormat::EStyle) 5);
  fGroupFrameFO->AddFrame(fNumberEntryFO, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fNumberEntryFO->MoveResize(150,90,70,20);
  fNumberEntryFO->SetNumber(1.0);
  fNumberEntryFO->SetLimits(TGNumberFormat::kNELLimitMin, 0.0);

  fNumberEntryWF = new TGNumberEntry(fGroupFrameFO, (Double_t) 0,9,-1,(TGNumberFormat::EStyle) 5);
  fGroupFrameFO->AddFrame(fNumberEntryWF, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fNumberEntryWF->MoveResize(150,130,70,20);
  fNumberEntryWF->SetNumber(1.0);
  fNumberEntryWF->SetLimits(TGNumberFormat::kNELLimitMin, 0.01);

  
  TGLabel *fLabelDT = new TGLabel(fGroupFrameFO,"Time step dt [ s ]",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
  fLabelDT->SetTextJustify(36);
  fLabelDT->SetMargins(0,0,0,0);
  fLabelDT->SetWrapLength(-1);
  fGroupFrameFO->AddFrame(fLabelDT, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fLabelDT->MoveResize(10,20,100,16);

  TGLabel *fLabelRT = new TGLabel(fGroupFrameFO,"Run time t_f [ s ]",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
  fLabelRT->SetTextJustify(36);
  fLabelRT->SetMargins(0,0,0,0);
  fLabelRT->SetWrapLength(-1);
  fGroupFrameFO->AddFrame(fLabelRT, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fLabelRT->MoveResize(130,20,100,16);

  TGLabel *fLabelFO = new TGLabel(fGroupFrameFO,"(FoSin(wt)) Fo [ N ]",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
  fLabelFO->SetTextJustify(36);
  fLabelFO->SetMargins(0,0,0,0);
  fLabelFO->SetWrapLength(-1);
  fGroupFrameFO->AddFrame(fLabelFO, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fLabelFO->MoveResize(40,92,100,16);

  TGLabel *fLabelWF = new TGLabel(fGroupFrameFO,"Forced frequency [ rad/s ]",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
  fLabelWF->SetTextJustify(36);
  fLabelWF->SetMargins(0,0,0,0);
  fLabelWF->SetWrapLength(-1);
  fGroupFrameFO->AddFrame(fLabelWF, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fLabelWF->MoveResize(5,130,140,16);

  
  fGroupFrameFO->SetLayoutManager(new TGVerticalLayout(fGroupFrameFO));
  fGroupFrameFO->Resize(232,120);
  fVerticalFrameV->AddFrame(fGroupFrameFO, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fGroupFrameFO->MoveResize(8,500,232,170);
  
  TGFont *ufont;         // will reflect user font changes
  ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");
  
  TGGC   *uGC;           // will reflect user GC changes
  // graphics context changes
  GCValues_t valpFrameHD;
  valpFrameHD.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
  gClient->GetColorByName("#000000",valpFrameHD.fForeground);
  gClient->GetColorByName("#e8e8e8",valpFrameHD.fBackground);
  valpFrameHD.fFillStyle = kFillSolid;
  valpFrameHD.fFont = ufont->GetFontHandle();
  valpFrameHD.fGraphicsExposures = kFALSE;
  uGC = gClient->GetGC(&valpFrameHD, kTRUE);
  
  gClient->GetColorByName("#99cccc",ucolor);
  
  // "Harmonic Damped Oscillations" group frame
  TGGroupFrame *fGroupFrameHD = new TGGroupFrame(fVerticalFrameV,"Harmonic Damped Oscillations",kVerticalFrame,uGC->GetGC(),ufont->GetFontStruct(),ucolor);
  fGroupFrameHD->SetLayoutBroken(kTRUE);

  fNumberEntryK = new TGNumberEntry(fGroupFrameHD, (Double_t) 0,15,-1,(TGNumberFormat::EStyle) 5);
  fGroupFrameHD->AddFrame(fNumberEntryK, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fNumberEntryK->MoveResize(24,48,120,20);

  fNumberEntryB = new TGNumberEntry(fGroupFrameHD, (Double_t) 0,14,-1,(TGNumberFormat::EStyle) 5);
  fGroupFrameHD->AddFrame(fNumberEntryB, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fNumberEntryB->MoveResize(80,112,112,20);

  fNumberEntryM = new TGNumberEntry(fGroupFrameHD, (Double_t) 0,15,-1,(TGNumberFormat::EStyle) 5);
  fGroupFrameHD->AddFrame(fNumberEntryM, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fNumberEntryM->MoveResize(32,168,120,20);

  fNumberEntryA0 = new TGNumberEntry(fGroupFrameHD, (Double_t) 0,7,-1,(TGNumberFormat::EStyle) 5);
  fGroupFrameHD->AddFrame(fNumberEntryA0, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fNumberEntryA0->MoveResize(32,224,64,20);

  fNumberEntryPH = new TGNumberEntry(fGroupFrameHD, (Double_t) 0,7,-1,(TGNumberFormat::EStyle) 5);
  fGroupFrameHD->AddFrame(fNumberEntryPH, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fNumberEntryPH->MoveResize(152,224,64,20);

  fNumberEntryK->SetNumber(1.0);
  fNumberEntryB->SetNumber(0.0);
  fNumberEntryM->SetNumber(1.0);
  fNumberEntryA0->SetNumber(0.2);
  fNumberEntryPH->SetNumber(0.0);

  fNumberEntryK->SetLimits(TGNumberFormat::kNELLimitMin, 0.001);
  fNumberEntryB->SetNumAttr(TGNumberFormat::kNEAPositive);
  fNumberEntryM->SetLimits(TGNumberFormat::kNELLimitMin, 0.001);
  
  TGLabel *fLabelK = new TGLabel(fGroupFrameHD,"Spring constant K [ N/m ]",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
  fLabelK->SetTextJustify(36);
  fLabelK->SetMargins(0,0,0,0);
  fLabelK->SetWrapLength(-1);
  fGroupFrameHD->AddFrame(fLabelK, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fLabelK->MoveResize(16,16,200,22);
  
  TGLabel *fLabelB = new TGLabel(fGroupFrameHD,"Damping constant b (-bv) [ kg/s ]",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
  fLabelB->SetTextJustify(36);
  fLabelB->SetMargins(0,0,0,0);
  fLabelB->SetWrapLength(-1);
  fGroupFrameHD->AddFrame(fLabelB, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fLabelB->MoveResize(8,80,200,24);
  
  TGLabel *fLabelM = new TGLabel(fGroupFrameHD,"Mass m [ kg ]",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
  fLabelM->SetTextJustify(36);
  fLabelM->SetMargins(0,0,0,0);
  fLabelM->SetWrapLength(-1);
  fGroupFrameHD->AddFrame(fLabelM, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fLabelM->MoveResize(32,144,176,16);
  
  TGLabel *fLabelA0 = new TGLabel(fGroupFrameHD,"Init Amplitude A0 [ m ]",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
  fLabelA0->SetTextJustify(36);
  fLabelA0->SetMargins(0,0,0,0);
  fLabelA0->SetWrapLength(-1);
  fGroupFrameHD->AddFrame(fLabelA0, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fLabelA0->MoveResize(8,200,120,16);

 
  TGLabel *fLabelPH = new TGLabel(fGroupFrameHD,"Fase phi (deg)",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
  fLabelPH->SetTextJustify(36);
  fLabelPH->SetMargins(0,0,0,0);
  fLabelPH->SetWrapLength(-1);
  fGroupFrameHD->AddFrame(fLabelPH, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fLabelPH->MoveResize(144,200,79,16);
  
  fGroupFrameHD->SetLayoutManager(new TGVerticalLayout(fGroupFrameHD));
  fGroupFrameHD->Resize(232,264);
  fVerticalFrameV->AddFrame(fGroupFrameHD, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fGroupFrameHD->MoveResize(8,8,232,264);
  
  gClient->GetColorByName("#ffcccc",ucolor);
  
  // "Overdamped Oscillations" group frame
  TGGroupFrame *fGroupFrameOD = new TGGroupFrame(fVerticalFrameV,"Overdamped Oscillations",kVerticalFrame,TGGroupFrame::GetDefaultGC()(),TGGroupFrame::GetDefaultFontStruct(),ucolor);
  fGroupFrameOD->SetLayoutBroken(kTRUE);
  
  fNumberEntryX0 = new TGNumberEntry(fGroupFrameOD, (Double_t) 0,9,-1,(TGNumberFormat::EStyle) 5);
  fGroupFrameOD->AddFrame(fNumberEntryX0, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fNumberEntryX0->MoveResize(10,40,80,20);

  fNumberEntryV0 = new TGNumberEntry(fGroupFrameOD, (Double_t) 0,9,-1,(TGNumberFormat::EStyle) 5);
  fGroupFrameOD->AddFrame(fNumberEntryV0, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fNumberEntryV0->MoveResize(140,40,80,20);

  fNumberEntryX0->SetNumber(0.2);
  fNumberEntryV0->SetNumber(1.0);
  
  TGLabel *fLabelX0 = new TGLabel(fGroupFrameOD,"Init Pos x(0) [ m ]",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
  fLabelX0->SetTextJustify(36);
  fLabelX0->SetMargins(0,0,0,0);
  fLabelX0->SetWrapLength(-1);
  fGroupFrameOD->AddFrame(fLabelX0, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fLabelX0->MoveResize(5,20,95,16);
  
  TGLabel *fLabelV0 = new TGLabel(fGroupFrameOD,"Init Speed v(0) [ m/s ]",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
  fLabelV0->SetTextJustify(36);
  fLabelV0->SetMargins(0,0,0,0);
  fLabelV0->SetWrapLength(-1);
  fGroupFrameOD->AddFrame(fLabelV0, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fLabelV0->MoveResize(110,20,115,16);
  
  fGroupFrameOD->SetLayoutManager(new TGVerticalLayout(fGroupFrameOD));
  fGroupFrameOD->Resize(232,152);
  fVerticalFrameV->AddFrame(fGroupFrameOD, new TGLayoutHints(kLHintsExpandX));
  fGroupFrameOD->MoveResize(8,392,232,80);

  fLabelW = new TGLabel(fVerticalFrameV,"W =sqrt[Wo^2 - (b/2m)^2]: [ rad/s ]");
  fLabelW->SetTextJustify(36);
  fLabelW->SetMargins(0,0,0,0);
  fLabelW->SetWrapLength(-2);
  fVerticalFrameV->AddFrame(fLabelW, new TGLayoutHints(kLHintsExpandX| kLHintsTop,2,2,2,2));
  fLabelW->MoveResize(1,350,224,40);

  fLabelW0 = new TGLabel(fVerticalFrameV,"Wo: gamma (b/2m): [ rad/s]");
  fLabelW0->SetTextJustify(36);
  fLabelW0->SetMargins(0,0,0,0);
  fLabelW0->SetWrapLength(-1);
  fVerticalFrameV->AddFrame(fLabelW0, new TGLayoutHints(kLHintsExpandX| kLHintsTop,2,2,2,2));
  fLabelW0->MoveResize(1,325,224,45);

  fLabelSTEP = new TGLabel(fVerticalFrameV,"Running 0 Iterations out of 0");
  fLabelSTEP->SetTextJustify(36);
  fLabelSTEP->SetMargins(0,0,0,0);
  fLabelSTEP->SetWrapLength(-1);
  fVerticalFrameV->AddFrame(fLabelSTEP, new TGLayoutHints(kLHintsRight| kLHintsExpandX | kLHintsTop,2,2,2,2));
  fLabelSTEP->MoveResize(1,336,224,40);

  fMainFrameHDFOSC->AddFrame(fVerticalFrameV, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fVerticalFrameV->MoveResize(8,16,256,696);
  
  // horizontal frame
  TGHorizontalFrame *fHorizontalFrameH = new TGHorizontalFrame(fMainFrameHDFOSC,600,30,kHorizontalFrame);
  fHorizontalFrameH->SetName("fHorizontalFrameH");
  //fHorizontalFrameH->SetLayoutBroken(kTRUE);
  
  fTextButtonDRAW = new TGTextButton(fHorizontalFrameH,"&Draw",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
  fTextButtonDRAW->SetTextJustify(36);
  fTextButtonDRAW->SetMargins(0,0,0,0);
  fTextButtonDRAW->SetWrapLength(-1);
  fTextButtonDRAW->Resize(99,24);

  fTextButtonDRAW->Connect("Clicked()","MyMainFrame",this,"DoDraw()");

  fHorizontalFrameH->AddFrame(fTextButtonDRAW, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fTextButtonDRAW->MoveResize(24,16,99,24);
  
  ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");
  
  // graphics context changes
  GCValues_t valButtonSTOP;
  valButtonSTOP.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
  gClient->GetColorByName("#ff0000",valButtonSTOP.fForeground);
  gClient->GetColorByName("#e8e8e8",valButtonSTOP.fBackground);
  valButtonSTOP.fFillStyle = kFillSolid;
  valButtonSTOP.fFont = ufont->GetFontHandle();
  valButtonSTOP.fGraphicsExposures = kFALSE;
  uGC = gClient->GetGC(&valButtonSTOP, kTRUE);
  fTextButtonSTOP = new TGTextButton(fHorizontalFrameH,"S&top",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
  fTextButtonSTOP->SetTextJustify(36);
  fTextButtonSTOP->SetMargins(0,0,0,0);
  fTextButtonSTOP->SetWrapLength(-1);
  fTextButtonSTOP->Resize(99,22);
  fHorizontalFrameH->AddFrame(fTextButtonSTOP, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fTextButtonSTOP->MoveResize(136,16,99,22);

  fTextButtonSTOP->Connect("Clicked()","MyMainFrame",this,"DoStop()");
  
  fTextButtonCONTINUE = new TGTextButton(fHorizontalFrameH,"&Continue",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
  fTextButtonCONTINUE->SetTextJustify(36);
  fTextButtonCONTINUE->SetMargins(0,0,0,0);
  fTextButtonCONTINUE->SetWrapLength(-1);
  fTextButtonCONTINUE->Resize(104,22);
  fHorizontalFrameH->AddFrame(fTextButtonCONTINUE, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fTextButtonCONTINUE->MoveResize(248,16,104,22);

  fTextButtonCONTINUE->Connect("Clicked()","MyMainFrame",this,"DoContinue()");
  
  ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");
  
  // graphics context changes
  GCValues_t valButtonCLEAR;
  valButtonCLEAR.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
  gClient->GetColorByName("#003300",valButtonCLEAR.fForeground);
  gClient->GetColorByName("#e8e8e8",valButtonCLEAR.fBackground);
  valButtonCLEAR.fFillStyle = kFillSolid;
  valButtonCLEAR.fFont = ufont->GetFontHandle();
  valButtonCLEAR.fGraphicsExposures = kFALSE;
  uGC = gClient->GetGC(&valButtonCLEAR, kTRUE);
  fTextButtonCLEAR = new TGTextButton(fHorizontalFrameH,"C&lear",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
  fTextButtonCLEAR->SetTextJustify(36);
  fTextButtonCLEAR->SetMargins(0,0,0,0);
  fTextButtonCLEAR->SetWrapLength(-1);
  fTextButtonCLEAR->Resize(99,22);
  fHorizontalFrameH->AddFrame(fTextButtonCLEAR, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fTextButtonCLEAR->MoveResize(416,16,99,22);
  
  fTextButtonEXIT = new TGTextButton(fHorizontalFrameH,"&Exit",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
  fTextButtonEXIT->SetTextJustify(36);
  fTextButtonEXIT->SetMargins(0,0,0,0);
  fTextButtonEXIT->SetWrapLength(-1);
  fTextButtonEXIT->Resize(99,22);
  fHorizontalFrameH->AddFrame(fTextButtonEXIT, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fTextButtonEXIT->MoveResize(568,16,99,22);

  fMainFrameHDFOSC->AddFrame(fHorizontalFrameH, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fHorizontalFrameH->MoveResize(400,550,500,30);

  TGIcon *fIconHDFo = new TGIcon(fMainFrameHDFOSC, pathDIR_ICONS + "logoHDFo.png");
  fIconHDFo->SetName("logoHDFo");
  fMainFrameHDFOSC->AddFrame(fIconHDFo, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fIconHDFo->MoveResize(275,530,80,60);

  //TGIcon *fIconFISINFOR = new TGIcon(fMainFrameHDFOSC, pathDIR_ICONS + "logoFISINFOR.png");
  //fIconFISINFOR->SetName("logoFisinfor");
  //fMainFrameHDFOSC->AddFrame(fIconFISINFOR, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  //fIconFISINFOR->MoveResize(755,530,200,60);

  TGIcon *UDicon = new TGIcon(fMainFrameHDFOSC, pathDIR_ICONS + "logoUD.png");
  UDicon->SetName("logoUD");
  fMainFrameHDFOSC->AddFrame(UDicon, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  UDicon->MoveResize(965,530,155,60);
  
  // embedded canvas
  fECanvas = new TRootEmbeddedCanvas(0,fMainFrameHDFOSC,900,500,kSunkenFrame);
  fECanvas->SetName("fECanvas");
  //  Int_t wfRootEmbeddedCanvasEC = fECanvas->GetCanvasWindowId();
  //  TCanvas *c123 = new TCanvas("c123", 10, 10, wfRootEmbeddedCanvasEC);
  //  fECanvas->AdoptCanvas(c123);
  fMainFrameHDFOSC->AddFrame(fECanvas, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fECanvas->MoveResize(260,16,860,510);

    
  ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");
  
  // graphics context changes
  GCValues_t valButtonHELP;
  valButtonHELP.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
  gClient->GetColorByName("#0000ff",valButtonHELP.fForeground);
  gClient->GetColorByName("#e8e8e8",valButtonHELP.fBackground);
  valButtonHELP.fFillStyle = kFillSolid;
  valButtonHELP.fFont = ufont->GetFontHandle();
  valButtonHELP.fGraphicsExposures = kFALSE;
  uGC = gClient->GetGC(&valButtonHELP, kTRUE);
  fTextButtonHELP = new TGTextButton(fMainFrameHDFOSC,"&Help",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
  fTextButtonHELP->SetTextJustify(36);
  fTextButtonHELP->SetMargins(0,0,0,0);
  fTextButtonHELP->SetWrapLength(-1);
  fTextButtonHELP->Resize(99,56);

  fTextButtonHELP->Connect("Clicked()","MyMainFrame",this,"DoHelp()");
  fMainFrameHDFOSC->AddFrame(fTextButtonHELP, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  fTextButtonHELP->MoveResize(650,550,99,24);

  double gamma_i = 2.0*fNumberEntryB->GetNumber()/fNumberEntryM->GetNumber();

  char cw0i[50];
  double w0i = sqrt(fNumberEntryK->GetNumber()/fNumberEntryK->GetNumber());
  sprintf(cw0i, "Wo: %0.3f  gamma (b/2m): %0.3f [ rad/s]" , (float)w0i, (float)gamma_i ); 
  fLabelW0->SetTitle(cw0i);
    
  char cwi[50];
  double wi = sqrt(w0i*w0i - gamma_i*gamma_i);
  sprintf(cwi, "W =sqrt[Wo^2 - (b/2m)^2]: %0.3f [ rad/s ]" , (float)wi); 
  fLabelW->SetTitle(cwi);


  DoHelp();
  

  fTextButtonEXIT->SetCommand("gApplication->Terminate(0)");
  fTextButtonSTOP->SetState(kButtonDisabled, kTRUE);
  fTextButtonCONTINUE->SetState(kButtonDisabled, kTRUE);
  fTextButtonCLEAR->SetState(kButtonDisabled, kTRUE);
  fCheckButtonFORCED->SetOn();

  
  fMainFrameHDFOSC->SetMWMHints(kMWMDecorAll,
				kMWMFuncAll,
				kMWMInputModeless);
  fMainFrameHDFOSC->MapSubwindows();
  
  fMainFrameHDFOSC->Resize(fMainFrameHDFOSC->GetDefaultSize());
  fMainFrameHDFOSC->MapWindow();
  fMainFrameHDFOSC->Resize(1150,600);
  fMainFrameHDFOSC->SetWindowName("HDFoSoftEdu_1.0");
  fMainFrameHDFOSC->MapRaised();
  
  
}

void MyMainFrame::csDraw() {
  //  fTextButtonDRAW->TGTextButton::SetText("Dr&aw again");
  fTextButtonDRAW->TGTextButton::SetState(kButtonUp, kTRUE);
  fTextButtonHELP->TGTextButton::SetState(kButtonUp, kTRUE);

  optBreak = 2;
}

void MyMainFrame::DoStop() {
  optBreak = 1;
  fTextButtonCLEAR->TGTextButton::SetState(kButtonUp, kTRUE);
  fTextButtonCONTINUE->TGTextButton::SetState(kButtonUp, kTRUE);
  fTextButtonSTOP->TGTextButton::SetState(kButtonDisabled, kTRUE);
  fTextButtonHELP->TGTextButton::SetState(kButtonDisabled, kTRUE);

}
void MyMainFrame::DoContinue() {
  fTextButtonSTOP->TGTextButton::SetState(kButtonUp, kTRUE);
  fTextButtonCLEAR->TGTextButton::SetState(kButtonDisabled, kTRUE);
  fTextButtonDRAW->TGTextButton::SetState(kButtonDisabled, kTRUE);
  fTextButtonHELP->TGTextButton::SetState(kButtonDisabled, kTRUE);

  optBreak = 0;
  fTextButtonCONTINUE->TGTextButton::SetState(kButtonDisabled, kTRUE);

}
void MyMainFrame::DoHelp() {
  
  TCanvas *c1 = fECanvas->GetCanvas();
  c1->SetFillColor(18);
  c1->Clear();
  c1->Update();

  //TImage *img2 = TImage::Open( pathDIR_ICONS + "logoFISINFOR.png");
  TImage *img2 = TImage::Open( pathDIR_ICONS + "logoFisinfor_v2.png");
  TImage *img3 = TImage::Open( pathDIR_ICONS + "logoLIFAE.png");
  //  TImage *img1 = TImage::Open( pathDIR_ICONS + "HDFo_vid.png");
  //TImage *img1 = TImage::Open( pathDIR_ICONS + "logoHDFo.png");
  
  TPad *pad1 = new TPad("pad1","This is pad1",0.01,0.8,0.99,0.97);
  TPad *pad3 = new TPad("pad3","This is pad3",0.01,0.02,0.70,0.79);
  TPad *pad4 = new TPad("pad3","This is pad3",0.71,0.31,0.99,0.79);
  TPad *pad5 = new TPad("pad3","This is pad3",0.77,0.01,0.93,0.30);
  pad5->Divide(1,2);
  
  pad1->SetFillColor(0);
  pad3->SetFillColor(0);
  pad4->SetFillColor(0);
  pad5->SetFillColor(0);

  pad1->Draw();
  pad3->Draw();
  pad4->Draw();
  pad5->Draw();

  pad5->cd(1);
  img2->Draw();
  pad5->cd(2);
  img3->Draw();
    
  pad1->cd();
  TLatex *t1 = new TLatex(0.5, 0.75,"HDFo #color[2]{Soft}#color[4]{Edu}");
  TLatex *t2 = new TLatex(0.5, 0.45,"*Harmonic Damped Forced oscillations #color[2]{Software}#color[4]{Education}");
  TLatex *t3 = new TLatex(0.5, 0.15,"Creditos: UNIVERSIDAD DISTRITAL FRANCISCO JOSE DE CALDAS");
  t1->SetTextAlign(22);
  t1->SetTextSize(0.3);
  t2->SetTextAlign(21);
  t2->SetTextSize(0.2);
  t3->SetTextAlign(22);
  t3->SetTextSize(0.2);
  t1->Draw();
  t2->Draw();
  t3->Draw();

  TPaveText *pave = new TPaveText(0.0,0.05,0.42,0.97);
  pave->SetTextAlign(10);
  pave->SetTextFont(42);
  pave->SetTextSize(0.035);
  pave->SetFillColor(kCyan-10);

  pave->AddText(" ");
  pave->AddText("#font[62]{HARMONIC Oscillations:}");
  pave->AddText("  Position x(t) = A_{o}cos(w_{o}t + #phi)");
  pave->AddText("  Linear Momentum p(t) = -Awsin(wt + #phi)");
  pave->AddText("#font[62]{DAMPED Oscillations:}");
  pave->AddText("  Position x(t) = A(t)cos(wt + #phi)");
  pave->AddText("  Linear Momentum p(t) = m#frac{dx}{dt}");
  pave->AddText("  Amplitude A(t) = A_{0}e^{-#gamma t}   (#gamma=b/2m)");
  pave->AddText("  w = #sqrt{w^{2}_{o} - #gamma^{2}}");

  pave->AddText("#font[62]{OVER-DAMPED Oscillations:}");
  pave->AddText("  w_{o} < #gamma");
  pave->AddText("#font[62]{FORCED Oscillations:}");
  pave->AddText("  It uses ODEINT C++ library to solve:");
  pave->AddText("  m#ddot{x} + #gamma #dot{x} + w^{2}_{o}x = #frac{F_{o}}{m}sin(wt)");
  
  TPaveText *pavegui = new TPaveText(0.43,0.05,0.99,0.97);
  pavegui->SetTextAlign(10);
  pavegui->SetTextFont(42);
  pavegui->SetTextColor(0);
  pavegui->SetTextSize(0.035);
  pavegui->SetFillColor(kRed-6);

  pavegui->AddText(" ");
  pavegui->AddText(" To run a simulation press #font[62]{DRAW} ");
  pavegui->AddText(" To stop a simulation press #font[62]{STOP} ");
  pavegui->AddText(" To continue a simulation press #font[62]{CONTINUE} ");
  pavegui->AddText(" To clear gui press #font[62]{CLEAR} ");
  pavegui->AddText(" To popup this gui 'help' press #font[62]{HELP} ");
  pavegui->AddText(" Note: ctrl + the underlined key to activate buttons:"); 
  pavegui->AddText("       i.e  ctrl+d to activate #font[62]{DRAW}");
  pavegui->AddText(" Please, keep in mind the HDFo software is intended");
  pavegui->AddText(" for educational porposes only. It is suggested to run");
  pavegui->AddText(" simulations by thinking of a decent dt step and ");
  pavegui->AddText(" number of steps (it would cost an slowdown in cpu");
  pavegui->AddText(" performance).");
  pavegui->AddText(" ");
  pavegui->AddText("   Without further ado, #scale[1.2]{#font[62]{lets hands ON !!}}");
  pavegui->AddText("   Check your buttons and press #font[62]{DRAW!!}");


  TPaveText *pavecred = new TPaveText(0.01,0.01,0.99,0.97);
  pavecred->SetTextAlign(10);
  pavecred->SetTextFont(42);
  pavecred->SetTextColor(0);
  pavecred->SetTextSize(0.055);
  pavecred->SetFillColor(kBlue-6);

  pavecred->AddText(" ");
  pavecred->AddText(" Autores: ");
  pavecred->AddText(" #font[62]{Julian A Salamanca B}, PHD ");
  pavecred->AddText(" GRUPO DE INVESTIGACION FISINFOR ");
  pavecred->AddText(" FACULTAD DE CIENCIAS Y EDUCACION");
  pavecred->AddText(" #font[62]{Diego J Rodriguez P, PHD}");
  pavecred->AddText(" GRUPO DE INVESTIGACION LIFAE");
  pavecred->AddText(" FACULTAD DE INGENIERIA ");
  pavecred->AddText(" Profesores #font[72]{UNIVERSIDAD DISTRITAL}");
  pavecred->AddText(" #font[72]{FRANCISCO JOSE DE CALDAS}");
  
  pad3->cd();
  pave->Draw();
  pavegui->Draw();
  
  pad4->cd();
  pavecred->Draw();
  
  
  
  c1->Update();
}

void MyMainFrame::DoDraw() {

  TCanvas *fCanvas = fECanvas->GetCanvas();
  fCanvas->Clear();
  fCanvas->Update();
  fCanvas->SetFillColor(0);
  //fCanvas->Modified();
  fCanvas->Divide(2,2);
  fCanvas->cd(2)->Divide(2,1);

  
  gStyle->SetTitleFontSize(0.08);
  //  gStyle->SetNdivisions(505);
  gStyle->SetNdivisions(505,"Y");
  gStyle->SetNdivisions(505,"X");
  gStyle->SetLabelSize(0.08,"X");
  gStyle->SetLabelSize(0.08,"Y");
  gStyle->SetTitleOffset(0.6);
  
  gStyle->SetTitleXOffset(0.70);
  gStyle->SetTitleYOffset(1.5);

  gStyle->SetLabelOffset(0.001,"X");
  gStyle->SetLabelOffset(0.001,"Y");

  gStyle->SetTitleXSize(0.1);
  gStyle->SetTitleYSize(0.08);

  gStyle->SetGridColor(4);
  gStyle->SetOptFit(1);
  gStyle->SetOptStat("e");
  
  gStyle->SetPadTopMargin(0.1); 
  gStyle->SetPadBottomMargin(0.2); 
  gStyle->SetPadLeftMargin(0.15); 
  gStyle->SetPadRightMargin(0.01); 
  //gStyle->SetTitleFontSize(0.3);
 
  optBreak = 0;
  int ms=10;
  int nIter = 0;
  fTextButtonDRAW->SetState(kButtonDisabled, kTRUE);
  fTextButtonCLEAR->SetState(kButtonDisabled, kTRUE);
  fTextButtonCONTINUE->SetState(kButtonDisabled, kTRUE);
  fTextButtonSTOP->SetState(kButtonUp, kTRUE);
  fTextButtonHELP->SetState(kButtonDisabled, kTRUE);

  double k  = fNumberEntryK->GetNumber();
  double b  = fNumberEntryB->GetNumber();
  double m  = fNumberEntryM->GetNumber();
  double A0  = fNumberEntryA0->GetNumber();
  double ph  = fNumberEntryPH->GetNumber();

  double X0  = fNumberEntryX0->GetNumber();
  double V0  = fNumberEntryV0->GetNumber();

  double dt  = fNumberEntryDT->GetNumber();
  double t_f = fNumberEntryRT->GetNumber();
  Int_t chkb = fCheckButtonFORCED->GetState();
  double Fo  = fNumberEntryFO->GetNumber();
  double wr  = fNumberEntryWF->GetNumber();
  
  double w0 = TMath::Sqrt(k/m);
  double gamma = b/(2.0*m);


  char cw0[50];
  sprintf(cw0, "Wo: %0.3f gamma (b/2m): %0.3f [ rad/s ]", (float)w0, (float)gamma); 
  fLabelW0->SetTitle(cw0);
  
  
  if(chkb==0){
    double w, w2;
    w2 = w0*w0 - gamma*gamma;
    
    if(w2 >= 0){
      w = TMath::Sqrt(w2);
    }
    else{
      w=-1;
    }

    char cw[50];
    sprintf(cw, "W =sqrt(Wo^2 - (b/2m)^2): %0.3f [ rad/s ]" , (float)w); 
    fLabelW->SetTitle(cw);
    
    TCurlyLine *curlyline; 
    TEllipse *ellipse;
    TArrow *arrowK, *arrowB;
    TLine *vline, *vline_x_0, *hline;
    TGraph *gr, *gr_x, *gr_p, *gr_A, *gr_ec, *gr_ep, *gr_em, *gr_epp;
    TBox *BBox;
   
    
    double A[5000];
    double x1[5000];
    double p1[5000];
    double t1[5000];
    double ec[5000];
    double ep[5000];
    double em[5000]; // ec + ep
    
    double t;
    int n=0;
    t=0.0;
    
    if(dt < 0.04){
      fTextButtonCLEAR->TGTextButton::SetState(kButtonUp, kTRUE);
      fTextButtonCONTINUE->SetState(kButtonUp, kTRUE);
      fTextButtonCLEAR-> Connect("Clicked()", "TCanvas", fCanvas, "Clear()");
      fTextButtonCLEAR-> Connect("Clicked()", "TCanvas", fCanvas, "Update()");
      fTextButtonCLEAR-> Connect("Clicked()", "MyMainFrame", this, "csDraw()");

      return;
    }
    
    while(t < t_f){
      
      A[n] = fA(A0,gamma,t);
      t1[n]=t;
      
      if(w2 >= 0){
	x1[n]=fx(A[n],w0,ph,t);
	p1[n]=fp(A[n],w0,ph,m,t);
      }
      else{
	x1[n]=fx_od(X0, V0, gamma, w0,t);
	p1[n]=fp_od(X0, V0, gamma, w0, m, t);
      }
      ec[n]=(p1[n])*(p1[n])/(2.0*m);
      ep[n]=0.5*k*(x1[n])*(x1[n]);
      em[n]=ec[n] + ep[n];
      
      t = t + dt;
      n++;
      
    }
    
    char cnIter[50];

    double *pX1max = max_element(x1, x1 + n);
    double *pX1min = min_element(x1, x1 + n);
    double *pP1max = max_element(p1, p1 + n);
    double *pP1min = min_element(p1, p1 + n);

    double X1max = *pX1max;
    double X1min = *pX1min;

    double P1max = *pP1max;
    double P1min = *pP1min;
    
    for(int nn=0; nn<n; nn++){
      gSystem->ProcessEvents();  // handle GUI events

      nIter = nn+1;
      sprintf(cnIter, "Running %d iterations out of %d",nIter,n); 
      fLabelSTEP->SetTitle(cnIter);

      //fButtonDraw->SetState(kButtonDisabled, kTRUE);
      
      fCanvas->cd(1);
      
      if(w2 >= 0.0){
	arrowK = new TArrow(0.5, 0.6,0.5 + -x1[nn]/TMath::Abs(A0)*0.35 ,0.6 ,0.015,"|>");
	if(b > 0.0)
	  arrowB = new TArrow(0.5, 0.35 ,0.5 - p1[nn]/TMath::Abs(P1max-P1min)*0.35 ,0.35 ,0.015,"|>");
	
	curlyline = new TCurlyLine(0.1, 0.5, 0.5 + x1[nn]/TMath::Abs(A0)*0.1, 0.5);
	ellipse = new TEllipse(0.5 + x1[nn]/TMath::Abs(A0)*0.1, 0.5 , 0.04, 0.05, 0, 360, 0);
	BBox = new TBox(0.15, 0.45, 0.5 + x1[nn]/TMath::Abs(A0)*0.1 -0.08, 0.55);
      }
      else {
	arrowK = new TArrow(0.5, 0.6, 0.5 + - x1[nn]/TMath::Abs(X1max - X1min)*0.35 ,0.6 ,0.015,"|>");
	arrowB = new TArrow(0.5, 0.35 ,0.5 - p1[nn]/TMath::Abs(P1max - P1min)*0.35 ,0.35 ,0.015,"|>");
	
	curlyline = new TCurlyLine(0.1, 0.5, 0.5 + (x1[nn])/TMath::Abs(X1max - X1min)*0.3 , 0.5);
	ellipse = new TEllipse(0.5 + (x1[nn])/TMath::Abs(X1max - X1min)*0.3 , 0.5 , 0.04, 0.05, 0, 360, 0);
	BBox = new TBox(0.15, 0.45, 0.5 + (x1[nn])/TMath::Abs(X1max - X1min)*0.3 -0.08, 0.55);

      }
      ellipse->SetFillColor(2);
      
      vline = new TLine(0.1, 0.4, 0.1, 0.65);
      vline->SetLineWidth(8);
      vline->SetLineStyle(1);
      vline->SetLineColor(1);
      
      vline_x_0 = new TLine(0.5, 0.4, 0.5, 0.7);
      vline_x_0->SetLineWidth(2);
      vline_x_0->SetLineStyle(4);
      vline_x_0->SetLineColor(1);

      arrowK->SetLineColor(kCyan+3);
      arrowK->SetLineWidth(5);
      arrowK->SetAngle(30);

      if(b>0){
	arrowB->SetLineColor(kBlue-3);
	arrowB->SetLineWidth(5);
	arrowB->SetAngle(30);
	BBox->SetFillColorAlpha(kBlue-3,0.35);
      }
      
      TLatex *   tex = new TLatex(0.45, 0.25,"x=0 [m] (damping as kinetic friction)");
      tex->SetLineWidth(2);
      tex->Draw();

      double springF = -k*x1[nn];
      double dampedF = -b*p1[nn]/m;

      char ctexSF[100];
      sprintf(ctexSF,"Spring force (-kx): %0.3F [ N ]", (float)springF);
      TLatex *texSF = new TLatex(0.53, 0.75, ctexSF);
      texSF->SetLineWidth(2);
      texSF->SetTextColor(kCyan+3);
      texSF->Draw();

      char ctexDF[100];
      sprintf(ctexDF,"Damping force (-bv): %0.3F [ N ]", (float)dampedF);
      TLatex *texDF = new TLatex(0.53, 0.65, ctexDF);
      texDF->SetLineWidth(2);
      texDF->SetTextColor(kBlue-3);
      texDF->Draw();

      
      hline = new TLine(0.1, 0.45, 0.9, 0.45);
      if(b>0){
	hline->SetLineWidth(6);
	hline->SetLineColor(2);
	hline->SetLineStyle(3);
      }
      else{
	hline->SetLineWidth(4);
	hline->SetLineColor(16);
	hline->SetLineStyle(1);
      }
      
      curlyline->Draw();
      ellipse->Draw();
      vline->Draw();
      vline_x_0->Draw();
      hline->Draw();
      arrowK->Draw();

      if(b>0){
	arrowB->Draw();
	BBox->Draw();
      }
      
      fCanvas->cd(2)->cd(1)->SetGrid();
      gr_x = new TGraph(nn+1,t1,x1);
      gr_x->SetTitle("x(t), #color[4]{A(t)} [m]              ");
      gr_x->GetXaxis()->SetTitle("t [s]");
      
      gr_A = new TGraph(nn+1,t1,A);
      gr_A->SetTitle("A(t)");
      gr_A->SetLineStyle(3);
      gr_A->SetLineWidth(3);
      gr_A->SetLineColor(4);
      gr_x->Draw("ACP");
      if(w2>0)
	gr_A->Draw("CP");
      
      fCanvas->cd(2)->cd(2)->SetGrid();
      gr_p = new TGraph(nn+1,t1,p1);
      gr_p->SetTitle("p(t) [kg m/s]                  ");
      gr_p->GetXaxis()->SetTitle("t [s]");
      gr_p->Draw("ACP");
      
      fCanvas->cd(3)->SetGrid();
      gr = new TGraph(nn+1,x1,p1);
      gr->SetTitle("p [kg m/s]           Phase Space");
      gr->GetXaxis()->SetTitle("x (m)");
      gr->Draw("ACP");
      
      fCanvas->cd(4)->SetGrid();
      gr_em = new TGraph(nn+1,x1,em);
      gr_em->SetLineColor(1);
      gr_em->SetMarkerColor(1);
      gr_em->GetYaxis()->SetTitle("#lambda");
      gr_em->SetTitle("Energy type [ J ]:  #color[1]{Mecanical} #color[2]{Kinetic} #color[3]{Potential}");
      //gr_em->GetYaxis()->SetRangeUser(0, em[0]);
      if(w2 > 0.04){
	gr_em->GetXaxis()->SetLimits(-TMath::Abs(A0)*1.1, TMath::Abs(A0)*1.1);
	gr_em->GetYaxis()->SetRangeUser(0,0.5*k*A0*A0*1.1);
      }
      
      gr_em->GetYaxis()->SetTitle("Energy (J)");
      gr_em->GetXaxis()->SetTitle("x (m)");
      
      gr_ec = new TGraph(nn+1,x1,ec);
      gr_ec->SetLineColor(2);
      gr_ec->GetYaxis()->SetTitle("#lambda");
      
      gr_ep = new TGraph(nn+1,x1,ep);
      gr_ep->SetLineColor(3);
      gr_ep->GetYaxis()->SetTitle("#lambda");
      
      auto markem = new TMarker(x1[nn], em[nn], 20);
      markem->SetMarkerColor(1);
      auto markec = new TMarker(x1[nn], ec[nn], 20);
      markec->SetMarkerColor(2);
      auto markep = new TMarker(x1[nn], ep[nn], 20);
      markep->SetMarkerColor(3);
      
      
      gr_em->Draw("ACP");
      gr_ec->Draw("CP");
      gr_ep->Draw("CP");
      markem->Draw();
      markec->Draw();
      markep->Draw();
      
      
      fCanvas->Update();
      //fButtonExit->SetState(kButtonEngaged, kTRUE);
      
      usleep(ms*500);
      //delete curlyline;
      
      if(optBreak == 1){
	while(optBreak == 1){
	  
	  gSystem->ProcessEvents();
	  fTextButtonCLEAR->TGTextButton::SetState(kButtonUp, kTRUE);
	  
	  fTextButtonCONTINUE->SetState(kButtonUp, kTRUE);
	  fTextButtonCLEAR->Connect("Clicked()", "TCanvas", fCanvas, "Clear()");
	  fTextButtonCLEAR->Connect("Clicked()", "TCanvas", fCanvas, "Update()");
	  fTextButtonCLEAR->Connect("Clicked()", "MyMainFrame", this, "csDraw()");
	  
	}
      }
      if(optBreak == 2){
	fTextButtonCONTINUE->SetState(kButtonDisabled, kTRUE);
	fTextButtonCLEAR->SetState(kButtonDisabled, kTRUE);
	
	return;
      }
      
      // it is because to show the last curlyline when play arround with "gr"
      if(nn < n-1){
	delete curlyline;
	delete ellipse;
	delete vline;
	delete vline_x_0;
	delete hline;
	delete arrowK;
	delete tex;
	delete texSF;
	delete texDF;

	if(b>0){
	  delete arrowB;
	  delete BBox;
	}

      }
    }//for
    
    
    // for reference how to clear pad by button
    // clear-> Connect("Clicked()", "TCanvas", fCanvas->cd(1), "Clear()");
    //clear-> Connect("Clicked()", "TCanvas", fCanvas, "Update()");
    fTextButtonCLEAR->TGTextButton::SetState(kButtonUp, kTRUE);
    
    fTextButtonCLEAR-> Connect("Clicked()", "TCanvas", fCanvas, "Clear()");
    fTextButtonCLEAR-> Connect("Clicked()", "TCanvas", fCanvas, "Update()");
    fTextButtonCLEAR-> Connect("Clicked()", "MyMainFrame", this, "csDraw()");
    
  }// if check button
  else{

    //gStyle->SetPadLeftMargin(0.08); 
    TCanvas *fCanvasF = fECanvas->GetCanvas();
    fCanvasF->Clear();
    fCanvasF->Update();
    fCanvasF->Divide(2,2);
    fCanvasF->cd(2)->Divide(2,1);

    optBreak = 0;
    char cw0r[50];
    sprintf(cw0r, "Wo: %0.3f gamma (b/2m): %0.3f [ rad/s ]" , (float)w0, (float)gamma); 
    fLabelW0->SetTitle(cw0r);

    double w = sqrt(w0*w0 - gamma*gamma);
    char cwr[50];
    sprintf(cwr, "W =sqrt(Wo^2 - (b/2m)^2): %0.3f [ rad/s ]" , (float)w); 
    fLabelW->SetTitle(cwr);

    TGraph *gr_xr, *gr_pr, *gr_xrpr, *grAw;
    TCurlyLine *curlyline; 
    TEllipse *ellipse;
    TLine *vline, *vline_x_0, *hline;
    TArrow *arrowK, *arrowB, *arrowF;
    TBox *BBox;

    fCanvasF->cd(4)->SetGrid();
    auto f1_Ar = new TF1("A [ m ]          Amplitude as a funtion of freq.", fA_r, 0, 5.0*w0, 4);
    f1_Ar->SetParameters(k,m,b,Fo);
    f1_Ar->GetXaxis()->SetTitle("W [rad/s]");
    
    TLine *avline = new TLine(w0, -0.02 , w0, f1_Ar->GetMaximum());
    avline->SetLineWidth(3);
    avline->SetLineStyle(4);
    avline->SetLineColor(1);
    
    TLine *avline_wr = new TLine(wr, -0.02 , wr , 1.1*f1_Ar->Eval(wr));
    avline_wr->SetLineWidth(5);
    avline_wr->SetLineStyle(6);
    avline_wr->SetLineColor(4);

    
    char c_w0[50];
    sprintf(c_w0,"Wo = %0.3f [ rad/s ]",(float)w0);
    char c_wr[50];
    sprintf(c_wr,"#color[4]{W(forced) = %0.3f [ rad/s ]}",(float)wr);
    char c_Amax[50];
    sprintf(c_Amax,"#color[2]{Amax = %0.2f [ rad/s ]}",(float)(f1_Ar->GetMaximum()));

    double x_Amax = TMath::Sqrt(w0*w0 - 0.5*b*b/(m*m));
    char c_xAmax[50];
    sprintf(c_xAmax,"#color[2]{W(forced) at Amax = %0.2f [ rad/s ]}",(float)x_Amax);

    TLine *avline_wr_max = new TLine(x_Amax, -0.02 , x_Amax , 1.01*f1_Ar->Eval(x_Amax));
    avline_wr_max->SetLineWidth(3);
    avline_wr_max->SetLineStyle(2);
    avline_wr_max->SetLineColor(2);
    
    auto legend = new TLegend(0.5,0.5,0.99,0.9);
    //legend->SetHeader("The Legend Title","R"); // option "C" allows to center the header
    legend->AddEntry(f1_Ar,c_Amax,"l");
    legend->AddEntry(avline,c_w0,"l");
    legend->AddEntry(avline_wr,c_wr,"l");
    legend->AddEntry(avline_wr_max ,c_xAmax,"l");
    legend->AddEntry((TObject*)0 ,"#color[2]{#sqrt{Wo^{2} - #frac{1}{2} b^{2}/m^{2}}}"," ");
    
    //f1_Ar->DrawF1(0, 5.0*w0);
    f1_Ar->Draw();
    avline->Draw("same");
    avline_wr->Draw("same");
    avline_wr_max->Draw("same");
    legend->Draw();
      
    fCanvasF->Update();
    fCanvasF->Modified();

    
    //runge_kutta4<state_type> rk4;
    //euler<state_type> rk4;
    //runge_kutta_fehlberg78<state_type> rk4;
    runge_kutta_dopri5<state_type> rk4;
    fforced forced( k, m, b, 1, Fo);
    //    state_type x_forced = {{ 1.0 , 0.0 }};
    state_type x_forced = {{ X0 , V0 }};
    double tr= 0.0;

    int nstep = (int)(t_f/dt);
    double tt[nstep];
    double xx[nstep];
    double pp[nstep];
    double hForce[nstep]; // harmonic Force 
    
    for( size_t i=0 ; i<nstep ; ++i ){

      rk4.do_step( forced , x_forced , tr , dt );
      tt[i] = tr;
      xx[i] = x_forced[0];
      pp[i] = m*x_forced[1];
      hForce[i] = Fo*sin(wr*tr);
      tr += dt;
    }

    double T_forced = 2*3.1416/wr;
    int dtStep = T_forced/dt;

    int opt = 0;
    int optM = 0;
    
    tr=0.0;

    double *pXmax = max_element(xx, xx + nstep);
    double *pXmin = min_element(xx, xx + nstep);
    double *pPmax = max_element(pp, pp + nstep);
    double *pPmin = min_element(pp, pp + nstep);

    double Xmax = *pXmax;
    double Xmin = *pXmin;

    double Pmax = *pPmax;
    double Pmin = *pPmin;
    

    char cnIter_r[50];
    for( size_t i=0 ; i<nstep ; ++i ){
      gSystem->ProcessEvents();  // handle GUI events

      nIter = i+1;
      sprintf(cnIter_r, "Running %d iterations out of %d",nIter,nstep); 
      fLabelSTEP->SetTitle(cnIter_r);
      
      fCanvasF->cd(1);

      arrowF = new TArrow(0.5 + xx[i]/TMath::Abs(Xmax-Xmin)*0.25 - hForce[i]/Fo*0.2 , 0.5, 0.5 + xx[i]/TMath::Abs(Xmax-Xmin)*0.25, 0.5 ,0.015,"|>");

      arrowK = new TArrow(0.5, 0.6,0.5 + -xx[i]/TMath::Abs(Xmax-Xmin)*0.4 ,0.6 ,0.015,"|>");
      if(b > 0.0)
	arrowB = new TArrow(0.5, 0.35 ,0.5 - pp[i]/TMath::Abs(Pmax-Pmin)*0.4 ,0.35 ,0.015,"|>");
      
      curlyline = new TCurlyLine(0.1, 0.5, 0.5 + xx[i]/TMath::Abs(Xmax-Xmin)*0.2, 0.5);
      BBox = new TBox(0.15, 0.45, 0.5 + xx[i]/TMath::Abs(Xmax-Xmin)*0.2 -0.08, 0.55);
      ellipse = new TEllipse(0.5 + xx[i]/TMath::Abs(Xmax-Xmin)*0.2, 0.5 , 0.04, 0.05, 0, 360, 0);
      
      ellipse->SetFillColor(2);


      
      vline = new TLine(0.1, 0.4, 0.1, 0.65);
      vline->SetLineWidth(8);
      vline->SetLineStyle(1);
      vline->SetLineColor(1);
      
      vline_x_0 = new TLine(0.5, 0.4, 0.5, 0.7);
      vline_x_0->SetLineWidth(2);
      vline_x_0->SetLineStyle(4);
      vline_x_0->SetLineColor(1);
      
      arrowK->SetLineColor(kCyan+3);
      arrowK->SetLineWidth(5);
      arrowK->SetAngle(30);

      arrowF->SetLineColor(kRed+3);
      arrowF->SetLineWidth(5);
      arrowF->SetAngle(30);

      if(b>0){
	arrowB->SetLineColor(kBlue-3);
	arrowB->SetLineWidth(5);
	arrowB->SetAngle(30);
	BBox->SetFillColorAlpha(kBlue-3,0.35);
      }

      TLatex *   tex = new TLatex(0.45, 0.25,"x=0 [m] (damping as kinetic friction)");
      tex->SetLineWidth(2);
      tex->Draw();

      double springF = -k*xx[i];
      double dampedF = -b*pp[i]/m;
      double harmonicF = hForce[i];

      char ctexSF[100];
      sprintf(ctexSF,"Spring force (-kx): %0.3F [ N ]", (float)springF);
      TLatex *texSF = new TLatex(0.53, 0.75, ctexSF);
      texSF->SetLineWidth(2);
      texSF->SetTextColor(kCyan+3);
      texSF->Draw();

      char ctexDF[100];
      sprintf(ctexDF,"Damping force (-bv): %0.3F [ N ]", (float)dampedF);
      TLatex *texDF = new TLatex(0.53, 0.65, ctexDF);
      texDF->SetLineWidth(2);
      texDF->SetTextColor(kBlue-3);
      texDF->Draw();

      char ctexHF[100];
      sprintf(ctexHF,"Harmonic force [ FoSin(w_{Forced} t) ]: %0.3F [ N ]", (float)harmonicF);
      TLatex *texHF = new TLatex(0.3, 0.85, ctexHF);
      texHF->SetLineWidth(2);
      texHF->SetTextColor(kRed+3);
      texHF->Draw();

      
      hline = new TLine(0.1, 0.45, 0.9, 0.45);
      if(b>0){
	hline->SetLineWidth(6);
	hline->SetLineColor(2);
	hline->SetLineStyle(3);
      }
      else{
	hline->SetLineWidth(4);
	hline->SetLineColor(16);
	hline->SetLineStyle(1);
      }
      
      curlyline->Draw();
      ellipse->Draw();
      vline->Draw();
      vline_x_0->Draw();
      hline->Draw();
      arrowF->Draw();
      arrowK->Draw();
      
      if(b>0){
	arrowB->Draw();
	BBox->Draw();
      }

      
      gr_xr = new TGraph(i+1, tt , xx);
      gr_pr = new TGraph(i+1, tt , pp);

      gr_xrpr = new TGraph(i+1, xx , pp);
      auto markxt = new TMarker(tt[i], xx[i], 20);
      auto markpt = new TMarker(tt[i], pp[i], 20);
      auto markxp = new TMarker(xx[i], pp[i], 20);

      /*
      // placing red spot for stationary behavior
      if(opt == 0){
	if((xx[i+1] > xx[i]) && (xx[i+1] > xx[i+2])){
	  if((xx[i+1+ dtStep] > 0.99*xx[i+1]) && (xx[i+1+ dtStep] < 1.01*xx[i+1])){
	    opt = 1;
	  }
	}
      }
      if(opt == 1){
	markxt->SetMarkerColor(2);
	markpt->SetMarkerColor(2);
	markxp->SetMarkerColor(2);
      }
      else{
	markxt->SetMarkerColor(3);
	markpt->SetMarkerColor(3);
	markxp->SetMarkerColor(3);
      }
      */

      markxt->SetMarkerColor(2);
      markpt->SetMarkerColor(2);
      markxp->SetMarkerColor(2);
            
      fCanvasF->cd(2)->cd(1)->SetGrid();
      gr_xr->SetTitle("x [ m]               x(t)");
      gr_xr->GetXaxis()->SetTitle("t [ s ]");
      gr_xr->Draw("ACP");
      markxt->Draw();

      fCanvasF->cd(2)->cd(2)->SetGrid();
      gr_pr->SetTitle("p [ kg m/s]               p(t)");
      gr_pr->GetXaxis()->SetTitle("t [ s ]");
      gr_pr->Draw("ACP");
      markpt->Draw();

      fCanvasF->cd(3)->SetGrid();
      gr_xrpr->SetTitle("p [ kg m/s]               Phase Space");
      gr_xrpr->GetXaxis()->SetTitle("x [ m ]");
      gr_xrpr->Draw("ACP");
      markxp->Draw();
          
      fCanvasF->Update();
      fCanvasF->Modified();
      
      usleep(ms*500);
      tr += dt;
      
      if(optBreak == 1){
	while(optBreak == 1){
	  
	  gSystem->ProcessEvents();
	  fTextButtonCLEAR->TGTextButton::SetState(kButtonUp, kTRUE);
	  
	  fTextButtonCONTINUE->SetState(kButtonUp, kTRUE);
	  fTextButtonCLEAR->Connect("Clicked()", "TCanvas", fCanvasF, "Clear()");
	  fTextButtonCLEAR->Connect("Clicked()", "TCanvas", fCanvasF, "Update()");
	  fTextButtonCLEAR->Connect("Clicked()", "MyMainFrame", this, "csDraw()");
	  
	}
      }
      if(optBreak == 2){
	fTextButtonCONTINUE->SetState(kButtonDisabled, kTRUE);
	fTextButtonCLEAR->SetState(kButtonDisabled, kTRUE);
	
	return;
      }
      // it is because to show the last curlyline when play arround with "gr"
      if(i < nstep-1){
	delete curlyline;
	delete ellipse;
	delete vline;
	delete vline_x_0;
	delete hline;
	delete tex;
	delete texSF;
	delete texDF;
	delete texHF;

	delete arrowF;
	delete arrowK;
	if(b>0){
	  delete arrowB;
	  delete BBox;
	}


	delete gr_xr, gr_pr, gr_xrpr, markxt, markpt, markxp;
	
      }
      
    }

   

    
    fTextButtonCLEAR->TGTextButton::SetState(kButtonUp, kTRUE);
    //fTextButtonCONTINUE->SetState(kButtonUp, kTRUE);
    fTextButtonCONTINUE->SetState(kButtonDisabled, kTRUE);
    fTextButtonCLEAR-> Connect("Clicked()", "TCanvas", fCanvasF, "Clear()");
    fTextButtonCLEAR-> Connect("Clicked()", "TCanvas", fCanvasF, "Update()");
    fTextButtonCLEAR-> Connect("Clicked()", "MyMainFrame", this, "csDraw()");
    
    
  }

}

MyMainFrame::~MyMainFrame() {
   // Clean up used widgets: frames, buttons, layout hints
   fMainFrameHDFOSC->Cleanup();
   delete fMainFrameHDFOSC;
}

void sehdfo_v1() {
  // Popup the GUI...
  gStyle->SetCanvasPreferGL(1);
  
  new MyMainFrame(gClient->GetRoot(),200,200);
}

int main(int argc, char **argv) {
  TApplication theApp("App",&argc,argv);
  sehdfo_v1();
  theApp.Run();
  return 0;
}

