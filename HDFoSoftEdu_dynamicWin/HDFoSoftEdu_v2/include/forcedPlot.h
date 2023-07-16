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
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <boost/numeric/odeint.hpp> // odeint function definitions

using namespace std;
using namespace boost::numeric::odeint;

typedef std::array<double,2> state_type;

//===============================================

//Amplitude permanent solution forced oscillation
Double_t fA_r(Double_t *x, Double_t *par){

  Double_t k, m, b, Fo, w_var;
  w_var = x[0];
  k  = par[0];
  m  = par[1];
  b  = par[2];
  Fo = par[3];

  Double_t Ar, num, den;
  Double_t w02 = k/m;

  if((Fo > 0)&&(b>0)){
  
    num = Fo;
    den = m*m*(w02 - w_var*w_var)*(w02 - w_var*w_var) + b*b*w_var*w_var;
    Ar = num/TMath::Sqrt(den);
  }
  else if((Fo > 0)&&(b<0.0001)){
    num = Fo;
    den = m*m*(w02 - w_var*w_var)*(w02 - w_var*w_var);
    Ar = num/TMath::Sqrt(den);
  }
  else if((Fo < 0.00001)&&(b < 0.00001)){
    Ar = 0;
  }
  else if((Fo < 0.00001)&&(b > 0)){
    Ar = 0;
  }
  else
    Ar=0;

  return Ar;
}
struct fforced
{
  double m_kk, m_MM, m_bb, m_FFo, m_ww;
  fforced(double kk,double MM,double bb, double FFo, double ww)
    : m_kk(kk),m_MM(MM),m_bb(bb),m_FFo(FFo),m_ww(ww) { }
  void operator()(const state_type &x_forced,
		  state_type &dxdt,double t) const
  {
    dxdt[0] = x_forced[1];
    dxdt[1] = -m_kk/m_MM*x_forced[0] - m_bb/m_MM*x_forced[1] + m_FFo/m_MM*sin(m_ww*t);
  }
};

