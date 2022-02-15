#!/bin/bash
#Script to create a new class in your gdextension project

read -p "Class name: " className
read -p "Extends from: " extends

dirHeader="../base/src/example.h"
dirScript="../base/src/example.cpp"
dirRegister="./src/register_types.cpp"
dirProject="./src/"

dirDoneCPP=$dirProject${className,,}.cpp
dirDoneH=$dirProject${className,,}.h
tab=$'\t'

sed -i "/ClassDB::register_class/a ClassDB::register_class<${className}>();" $dirRegister
cp $dirScript $dirDoneCPP
cp $dirHeader $dirDoneH


# This replace some strings in order to organize things

#search words
search_class=CNAME
search_class_lower=LOWERC
search_class_upper=UPPERC
search_extends=EXTENDS
search_extends_lower=LOWEXT

extendsLower=${extends,,}
classNameLower=${className,,}
classNameUpper=${className^^}


# CPP
sed -i "s/$search_class_lower/$classNameLower/g" $dirDoneCPP
sed -i "s/$search_class/$className/g" $dirDoneCPP

# H
sed -i "s/$search_class_upper/$classNameUpper/g" $dirDoneH
sed -i "s/$search_extends_lower/$extendsLower/g" $dirDoneH
sed -i "s/$search_class/$className/g" $dirDoneH
sed -i "s/$search_extends/$extends/g" $dirDoneH