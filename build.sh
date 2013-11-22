#!/bin/sh
EXDIR=`cd $(dirname $0); pwd`
cd "$EXDIR/$1"

#echo please input source dir:
#read FROMDIR
#echo please input output dir:
#read TODIR

FROMDIR=""
TODIR=""

rm -rf $TODIR
cp -r $FROMDIR $TODIR

deepls(){
    for x in $1/*
    do
        y=`basename $x .lua`
        if [ -f $x ]
        then
            $EXDIR/file_encrypto "$EXDIR/$1/$y.lua" "$EXDIR/$2/$y.so"
        fi
        if [ -d $x ]
        then
            deepls "$1/$y" "$2/$y"
        fi
    done
}

deepls $FROMDIR $TODIR

find $TODIR -name '*.lua' -exec rm {} \;
