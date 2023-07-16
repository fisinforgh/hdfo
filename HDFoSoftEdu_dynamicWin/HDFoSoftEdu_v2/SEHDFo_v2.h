/////////////////////////////////////////////////////////////////////////////
//                                                                         //
// NOTICE OF COPYRIGHT                                                     //
//                                                                         //
// Copyright (C) 2023                                                      //
//                                                                         //
// Authors:								   //
//   [1] Julián Salamanca*						   //
//   [2] Diego Julián Rodríguez-Patarroyo**				   //
//   [3] Marco Antonio Ramírez-Ramos***                			   //
//                                                                         //
//   [1] jasalamanca@udistrital.edu.co (profesor Universidad Distrital)    //
//   [2] djrodriguezp@udistrital.edu.co (profesor Universidad Distrital)   //
//   [3] maramirezramos@utep.edu			   		   //
//									   //
//  * Grupo de Física e Informática (FISINFOR)		     		   //
//  ** Grupo de Laboratorio de Fuentes Alternas de Energía (LIFAE)	   //
//  *,** Universidad Distrital Francisco José de Caldas (Bogotá, Colombia) //	
//   *** University of Texas at El Paso (UTEP) 	  			   //
//       (USA)                                                             //
// Web page:								   //
//   https://github.com/fisinforgh/hdfo/tree/main/HDFoSoftEdu_dynamicWin   //
//                                                                         //
// This program is free software; you can redistribute it and/or modify    //
// it under the terms of the GNU General Public License as published by    //
// the Free Software Foundation; either version 2 of the License, or       //
// (at your option) any later version.                                     //
//                                                                         //
// This program is distributed in the hope that it will be useful,         //
// but WITHOUT ANY WARRANTY; without even the implied warranty of          //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           //
// GNU General Public License for more details:                            //
//                                                                         //
//               http://www.gnu.org/copyleft/gpl.html                      //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
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
