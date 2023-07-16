auxFile="auxcop.txt"
#1: copyright file
#2: file

cp $1 $auxFile

cat $2 >> $auxFile
mv $auxFile $2
