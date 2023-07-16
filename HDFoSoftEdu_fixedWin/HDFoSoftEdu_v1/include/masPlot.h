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
using namespace std;
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include<unistd.h>
#include <iomanip>
//===============================================

double fx( double A0, double w0, double th, double t)
{
  double xx=A0*cos(w0*t + th);        return xx;
}

double fp( double A0, double w0, double th, double m, double t)
{
  double pp=-m*A0*w0*sin(w0*t + th);        return pp;
}

double fA( double A0, double gamma, double t)
{
  // 2gamma = b/2m
  double AA = A0*exp(-gamma*t);    return AA;
}

// od: overdamped
// https://mathworld.wolfram.com/OverdampedSimpleHarmonicMotion.html
double fx_od(double x_0, double v_0, double gamma, double W0, double t){

  double a, b, D, r_minus, r_plus;
  D = sqrt(4*gamma*gamma -4*W0);
  
  r_plus = 0.5*(-2*gamma + D);
  r_minus = 0.5*(-2*gamma - D);
  
  a = x_0 - (r_minus*x_0 - v_0)/(r_minus - r_plus);
  b = (r_minus*x_0 - v_0)/(r_minus - r_plus);
  
  double xx_od = a*exp(r_minus*t) + b*exp(r_plus*t); return xx_od;
}
double fp_od(double x_0, double v_0, double gamma, double W0, double m, double t){

  double a, b, D, r_minus, r_plus;
  D = sqrt(4*gamma*gamma -4*W0);
    
  r_plus = 0.5*(-2*gamma + D);
  r_minus = 0.5*(-2*gamma - D);
  
  a = x_0 - (r_minus*x_0 - v_0)/(r_minus - r_plus);
  b = (r_minus*x_0 - v_0)/(r_minus - r_plus);
  
  double pp_od = a*r_minus*exp(r_minus*t) + b*r_plus*exp(r_plus*t);return pp_od;
}

