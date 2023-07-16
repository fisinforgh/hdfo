###########################################################################
#                                                                         #
# NOTICE OF COPYRIGHT                                                     #
#                                                                         #
# Copyright (C) 2023                                                      #
#                                                                         #
# Authors:								  #
#   [1] Julián Salamanca*						  #
#   [2] Diego Julián Rodríguez-Patarroyo**				  #
#   [3] Marco Antonio Ramírez-Ramos***                			  #
#                                                                         #
#   [1] jasalamanca@udistrital.edu.co (profesor Universidad Distrital)    #
#   [2] djrodriguezp@udistrital.edu.co (profesor Universidad Distrital)   #
#   [3] maramirezramos@utep.edu	       			   		  #
#									  #
#  * Grupo de Física e Informática (FISINFOR)		     		  #
#  ** Grupo de Laboratorio de Fuentes Alternas de Energía (LIFAE)	  #
#  *,** Universidad Distrital Francisco José de Caldas (Bogotá, Colombia) #	
#   *** University of Texas at El Paso (UTEP) 	  			  #
#       (USA)                                                             #
# Web page:								  #
#   https:#github.com/fisinforgh/hdfo/tree/main/HDFoSoftEdu_dynamicWin    #
#                                                                         #
# This program is free software; you can redistribute it and/or modify    #
# it under the terms of the GNU General Public License as published by    #
# the Free Software Foundation; either version 2 of the License, or       #
# (at your option) any later version.                                     #
#                                                                         #
# This program is distributed in the hope that it will be useful,         #
# but WITHOUT ANY WARRANTY; without even the implied warranty of          #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           #
# GNU General Public License for more details:                            #
#                                                                         #
#               http:#www.gnu.org/copyleft/gpl.html                       #
#                                                                         #
###########################################################################
#! /bin/bash

#This script UNINSTALL HDFoSoftEdu software

sep="/"
sus="_"
sdot="."
deskEXT="desktop"
cont=0


Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White
Color_Off='\033[0m'       # Text Reset
Bg_red='\033[0;41m'

messageUNIS=$(echo "Welcome to the HDFo SoftEdu UNINSTALL wizard"
	      echo "You are about to uninstall  HDFo SoftEdu software"
	      echo "If you are completely sure, please clik on UNINSTALL"
	      )

echo "$messageUNIS" | (zenity --text-info --title="HDFo SoftEdu uninstall" --width=800 --height=400 --ok-label='UNINSTALL' --cancel-label='Exit')
if [ $? -eq 1 ]; then
    echo "Exit"
    exit 2
fi

(zenity --info --text="Please click CONTINUE to select \"Desktop\" Folder to UNISTALL HDFo SoftEdu desktop's icon" --title="HDFo SoftEdu UNINSTALL desktop icon" --ok-label='CONTINUE' --width=800 --height=400 )

dirDESK=$(zenity --file-selection   --directory --title="HDFo SoftEdu UNINSTALL choose a Desktop Folder" --width=800 --height=400)

manUNIS=$( echo "Remove HDFo SoftEdu software manually:"
	   echo "Find installation folder and remove:"
	   echo "  $dirNAME and $tarFILE"
	   echo "Go to the desktop folder and remove:"
	   echo "  $dirNAME.desktop"
	   echo "Go to hidden file \".bash_aliases\" and remove this two lines:"
	   echo "# HDFoSoftEdu_v2 globally available executable "
	   echo "export PATH=\"/home/fisinfor/test_v2/HDFoSoftEdu_v2:\$PATH")


cd
homeDIR=$(pwd)
echo "Home folder: $homeDIR/"
echo " "

hiddenFILE=".pathDIR_HDFoSoftEdu_v2.txt"
dirNAME="HDFoSoftEdu_v2"
tarFILE="HDFoSoftEdu_v2.tar"
pathINSTALL=$(echo "$homeDIR$sep$hiddenFILE")

echo $pathINSTALL

if [ -f $pathINSTALL ]; then
    read -r line < $pathINSTALL
    rm $pathINSTALL
else
    (zenity --info --text="$manUNIS" --width=800 --height=400  --ok-label='Close' )
    exit 2
fi
  
echo "0. $line"

cd $line

cd ..

installDIR=$(pwd)

echo "$installDIR"

if [ -d $installDIR/$dirNAME ]; then
    echo "1 rm $installDIR/$dirNAME"
    rm -r $installDIR/$dirNAME
else
    (zenity --info --text="$manUNIS" --width=800 --height=400  --ok-label='Close' )
    exit 2
fi


if [ -f $installDIR/$tarFILE ]; then
    echo "2 rm $installDIR/$tarFILE"
    rm $installDIR/$tarFILE
else
    (zenity --info --text="$manUNIS" --width=800 --height=400  --ok-label='Close' )
    exit 2
fi

echo "$dirDESK"
if [ -f $dirDESK/$dirNAME.desktop ]; then
    echo "3 rm $dirDESK/$dirNAME.desktop"
    rm $dirDESK/$dirNAME.desktop
else
    (zenity --info --text="$manUNIS" --width=800 --height=400  --ok-label='Close' )
    exit 2
fi

if [ -f $homeDIR/.bash_aliases ]; then
    sed -i "/$dirNAME/d" $homeDIR/.bash_aliases
    (zenity --info --text="UNINSTALL successesfully completed" --width=800 --height=400  --ok-label='Close' )
    exit 0
else
    (zenity --info --text="$manUNIS" --width=800 --height=400  --ok-label='Close' )
    exit 2
fi
