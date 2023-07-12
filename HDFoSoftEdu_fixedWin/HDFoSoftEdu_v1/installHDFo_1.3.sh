#! /bin/bash

#This script install HDFoSoftEdu software

sep="/"
sus="_"
sdot="."
deskEXT="desktop"
cont=0

cd
homeDIR=$(pwd)
echo "Home folder: $homeDIR/"
echo " "

_ROOT="root.exe"
#_ROOT="rooot.exe"

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

echo "Verifying dependencies ..."
odeintDIR="/usr/include/boost/numeric/odeint"

#if /sbin/ldconfig -p | grep libboost > /dev/null ;
if [ -d $odeintDIR ];
then
    if [ $(ls -1 $odeintDIR | wc -l) -gt 0 ];
    then
	echo -e "Odeint Boost library found !!  ${Green}\u2714 \u2714 ${Color_Off} "
	echo "Number of file in $odeintDIR : $(ls -1 $odeintDIR | wc -l)"
	echo "Note: It will be necessary for g++ compilation"
	echo "      #include <boost/numeric/odeint.hpp> // odeint function definitions"
    else
	echo -e "\u274c Please install boost library:"
	echo "sudo apt-get install libboost-all-dev"
	echo "Visit: https://www.boost.org/"
	warnInfoLIB1=$(echo " "
		      echo -e "\u274c libboost NOT found"
		      echo "sudo apt-get install libboost-all-dev"
		      echo "Visit: https://www.boost.org/"
		      echo " ")
	zenity --info --text="$warnInfoLIB1" --ok-label="Exit install"
	echo "bye"
	sleep 1
	exit 1
    fi
else
    echo -e "\u274c libboost NOT found"
    echo "Please install boost library:"
    echo "sudo apt-get install libboost-all-dev"
    echo "Visit: https://www.boost.org/"
    warnInfoLIB2=$(echo " "
		   echo -e "\u274c libboost NOT found"
		   echo "sudo apt-get install libboost-all-dev"
		   echo "Visit: https://www.boost.org/"
		   echo " ")
    zenity --info --text="$warnInfoLIB2" --ok-label="Exit install"
    echo "bye"
    sleep 1
    exit 1
fi

    
if command -v $_ROOT > /dev/null ;
then
    echo -e "ROOT System-wide install found it! ${Green}\u2714 \u2714 ${Color_Off}"
    $_ROOT --version
    let "cont = 1"
    pathROOTEXE="$_ROOT"
    pathROOTCLING="rootcling"
    pathROOTCONFIG="root-config"
else
    echo "NO ROOT system-wide install found."
    echo "---> Looking for user's ROOT install at $homeDIR..."
    check=$(find $homeDIR/ -iname $_ROOT | cat | wc -l)
    if [ $check -ne 0 ];
    then
	echo " "
	echo -e "User's ROOT install found it!!${Green}\u2714 \u2714 ${Color_Off} $_ROOT at:"
	find $homeDIR/ -iname $_ROOT
	echo " "
	pathROOTEXE=$(find $homeDIR/ -iname $_ROOT)
	pathROOTCLING=$(find $homeDIR/ -iname rootcling)
	pathROOTCONFIG=$(find $homeDIR/ -iname root-config)
	let "cont = 2"
    else
	echo " "
	echo -e "${Red} \u274c ${Color_Off} ${Blue}$_ROOT${Color_Off} command ${Bg_red}NOT${Color_Off} found"
	echo " Please install ROOT-CERN "
	echo " https://root.cern/install/"
	echo " We recommend install precompiled version. Go to 'Download a pre-compiled binary distribution' section for further info."
	echo " "
	warnInfo=$(echo " "
		   echo -e "\u274c $_ROOT$ NOT$ found"
		   echo " Please install ROOT-CERN "
		   echo " https://root.cern/install/"
		   echo " We recommend install precompiled version. Go to 'Download a pre-compiled binary distribution' section for further info."
		   echo " ")
	zenity --info --text="$warnInfo" --ok-label="Exit install"
	echo "bye"
	sleep 1
	exit 1
    fi
fi

if [ $cont -eq 1 ]; then
    infoINS1=$(
	echo "ROOT System install found it!"
	echo "Please click CONTINUE to select HDFoSoftEdu Installation Folder"
	echo " "
	command -v $_ROOT
	$pathROOTEXE -q
	echo "Executables found: "
	echo "rootcling, root-config:"
	echo "$pathROOTCLING"
	echo "$pathROOTCONFIG"
	echo " ")
    echo "$infoINS1" | (zenity --text-info --title="HDFo SoftEdu install" --width=800 --height=400 --ok-label='CONTINUE' --cancel-label='Exit install')
    if [ $? -eq 1 ]; then
	echo "Exit"
	exit 2
    fi   
else
    infoINS2=$(echo "Please click CONTINUE to select installation folder"
	       echo " "
	       echo "Info $_ROOT:"
	       echo "NO ROOT system-wide install found."
	       echo "---> Looking for user's ROOT install at $homeDIR..."
	       echo "User's ROOT install found it!!. $_ROOT at:"
	       echo "$pathROOTEXE"
	       $pathROOTEXE -q
	       echo "rootcling, root-config:"
	       echo "$pathROOTCLING"
	       echo "$pathROOTCONFIG"
	       echo "Please click CONTINUE to select installation folder"
	    )
    echo "$infoINS2" | (zenity --text-info --title="HDFo SoftEdu install" --width=800 --height=400 --ok-label='CONTINUE' --cancel-label='Exit install')
    if [ $? -eq 1 ]; then
	echo "Exit"
	exit 2
    fi   

fi

dirPATH=$(zenity --file-selection   --directory --title="HDFo SoftEdu install Choose a Installation Folder" --width=800 --height=400 )

(zenity --info --text="Please click CONTINUE to select Desktop Folder" --title="HDFo SoftEdu install choose Desktop Folder" --ok-label='CONTINUE' --width=800 --height=400 )

dirDESK=$(zenity --file-selection   --directory --title="HDFo SoftEdu install choose a Desktop Folder" --width=800 --height=400)

tarFILE="HDFoSoftEdu_v1.tar"
pwd
echo "Installation folder: $dirPATH"
echo "Path to Desktop folder: $dirDESK"
echo "Downloading HDFo source files: ... "
echo "wget https://raw.githubusercontent.com/fisinforgh/hdfo/main/HDFoSoftEdu_fixedWin/$tarFILE -P $dirPATH"
echo "Wait..."
(wget -O $dirPATH/$tarFILE https://raw.githubusercontent.com/fisinforgh/hdfo/main/HDFoSoftEdu_fixedWin/$tarFILE) | zenity --progress --width=800 --height=400 --auto-close \
										     --title="HDFoEdu_1.0 Install" \
										     --text="Downloading HDFoSofEdu... Please wait ..." \
										     --percentage=10
echo " "

if [ -f $dirPATH/$tarFILE ];
then
    (echo "Please click CONTINUE to install HDFoSoftEdu"
    echo "$tarFILE successfully downloaded!!") | (zenity --text-info --width=800 --height=400  --title="HDFo SoftEdu install" \
						       --ok-label='CONTINUE' --cancel-label='Exit install')
    if [ $? -eq 1 ]; then
	echo "Exit"
	exit 2
    fi    
else
    (echo "wget FAILED. It may possible web page not available"
     echo "Please check your internet connection and try it again"
    ) | (zenity --info --text="$warnInfo" --ok-label="Exit install")
    if [ $? -eq 1 ]; then
	echo "Exit"
	exit 2
    fi
fi


nameDIR="HDFoSoftEdu_v1"
FILE="SEHDFo_v1"

cd $dirPATH
tar xfv $tarFILE
cd $nameDIR

if [ -f "$FILE" ]; then
    rm $FILE
    ($pathROOTCLING -f SEHDFoDict_v1.cxx -c SEHDFo_v1.h SEHDFoLinkDef_v1.h
     g++ -o SEHDFo_v1 SEHDFo_v1.cxx  SEHDFoDict_v1.cxx `$pathROOTCONFIG --cflags --glibs`) | zenity --progress --width=800 --height=400 --auto-close \
												    --title="HDFoEdu_1.0 Install" \
												    --text="Compiling HDFoEdu_1.0 software" \
												    --percentage=10
else
    ($pathROOTCLING -f SEHDFoDict_v1.cxx -c SEHDFo_v1.h SEHDFoLinkDef_v1.h
     g++ -o SEHDFo_v1 SEHDFo_v1.cxx  SEHDFoDict_v1.cxx `$pathROOTCONFIG --cflags --glibs`) | zenity --progress --width=800 --height=400 --auto-close \
												    --title="HDFoEdu_1.0 Install" \
												    --text="Compiling HDFoEdu_1.0 software" \
												    --percentage=10
fi


if [ -f "$FILE" ]; then
    echo "Executable compilation complete"
    (zenity --info --text="HDFoEdu_1.0 executable compilation complete $FILE. \nPlease click CONTINUE to setup HDFo executable globally and  desktop icon "\
	    --title="HDFo SoftEdu install" --ok-label='CONTINUE' --width=800 --height=400 )
else 
    echo "Something went WRONG. Please check requirements"
    echo "and try again"
    (zenity --info --text="Please check g++ compiler and try it again "\
	    --title="HDFo SoftEdu install ERROR" --ok-label='Exit install' --width=800 --height=400 )
    if [ $? -eq 0 ]; then
	echo "Exit"
	exit 2
    fi
fi

# Creating hidden path file..."
echo " "
echo "$dirPATH/$nameDIR" > ~/.pathDIR_HDFo.txt

if [ -f $homeDIR/.bash_aliases ]; then
    sed -i '/HDFo/d' $homeDIR/.bash_aliases
    echo "# HDFoSoftEdu globally available executable " >> $homeDIR/.bash_aliases
    echo "export PATH=\"$dirPATH/$nameDIR:\$PATH\"" >> $homeDIR/.bash_aliases
else
    echo "# HDFoSoftEdu globally available executable " > $homeDIR/.bash_aliases
    echo "export PATH=\"$dirPATH/$nameDIR:\$PATH\"" >> $homeDIR/.bash_aliases
fi

vHDFo="HDFoSoftEdu1.0"
deskFILE=$dirPATH/$nameDIR/$vHDFo$sdot$deskEXT

echo "Configuring desktop file..."

echo "$deskFILE"

echo "[Desktop Entry]" > "$deskFILE"
echo "Version=1.0" >> "$deskFILE"
echo "Type=Application" >> "$deskFILE"
echo "Exec=$dirPATH/$nameDIR/$FILE" >> "$deskFILE"
echo "Icon=$dirPATH/$nameDIR/icons/logoHDFo.png" >> "$deskFILE"
echo "Terminal=false" >> "$deskFILE"
echo "Name=$vHDFo" >> "$deskFILE"
echo "Comment=An object-oriented data analysis framework">> "$deskFILE"
echo "MimeType=application/x-root;text/x-c++src;">> "$deskFILE"
echo "Categories=Science;">> "$deskFILE"

echo "Desktop file: ... "
cat $deskFILE
dirSRCDESK="desktop_file"
infoDESK_FILE=$(echo "Globally executable completed, hidden bash file:"
		echo "$homeDIR/.bash_aliases"
		echo "# HDFoSoftEdu globally available executable "
		echo "export PATH=\"$dirPATH/$nameDIR:\$PATH\""
		echo "\n Desktop file configuration success: \n"; cat $deskFILE ; echo "\n HDFoSofEdu Installation COMPLETED!! \n Please close and enjoy!!")

cp $deskFILE $dirDESK
mv $deskFILE $dirPATH/$nameDIR/$dirSRCDESK

(zenity --info --text="$infoDESK_FILE" --width=800 --height=400  --ok-label='Close' )
echo "Installation COMPLETED!!!"
#(zenity --info --text="INSTALL COMPLETED !!! Please close window "\
#	    --title="HDFo SoftEdu install" --ok-label='Close' --width=800 --height=400  )
exit 0



