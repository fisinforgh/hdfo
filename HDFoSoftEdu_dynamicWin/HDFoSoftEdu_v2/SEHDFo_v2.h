#include <TQObject.h>
#include <RQ_OBJECT.h>

class TGWindow;
class TGMainFrame;
class TRootEmbeddedCanvas;
class TGNumberEntry;
class TGCheckButton;
class TGTextButton;
class TGLabel;

class MyMainFrame {
  RQ_OBJECT("MyMainFrame")
  private:
  TGMainFrame         *fMainFrameHDFOSC;
  TRootEmbeddedCanvas *fECanvas;

  TGNumberEntry       *fNumberEntryK;
  TGNumberEntry       *fNumberEntryB;
  TGNumberEntry       *fNumberEntryM;
  TGNumberEntry       *fNumberEntryA0;
  TGNumberEntry       *fNumberEntryPH;

  TGNumberEntry       *fNumberEntryX0;
  TGNumberEntry       *fNumberEntryV0;


  TGNumberEntry       *fNumberEntryDT;
  TGNumberEntry       *fNumberEntryRT;
  TGCheckButton       *fCheckButtonFORCED;
  TGNumberEntry       *fNumberEntryFO;
  TGNumberEntry       *fNumberEntryWF;

  //horizontal frame buttons
  TGTextButton        *fTextButtonDRAW;
  TGTextButton        *fTextButtonSTOP;
  TGTextButton        *fTextButtonCONTINUE;  
  TGTextButton        *fTextButtonCLEAR;  
  TGTextButton        *fTextButtonEXIT;  
  TGTextButton        *fTextButtonHELP;

  // to chek frequency vales w and w0 (natural one)
  TGLabel             *fLabelW;
  TGLabel             *fLabelW0;
  TGLabel             *fLabelSTEP;

  
  // stop button behavior
  Int_t               optBreak=0;
  TString pathDIR_ICONS;
public:
  MyMainFrame(const TGWindow *p,UInt_t w,UInt_t h);
  virtual ~MyMainFrame();
  
  void DoDraw();
  void DoHelp();
  void csDraw();
  void DoStop();
  void DoContinue();

};
