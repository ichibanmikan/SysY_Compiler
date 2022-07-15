#!/bin/bash

var=0

function getdir(){
    echo $1
    for file in $1/*
    do
    if test -f $file
    then
      continue
    else
        echo $file
        arr=${file##*/}
        echo $arr
        let var++
        python3 test.py -s ./test/$arr -l
        getdir $file
    fi
    done
}

getdir .
echo "$var dirs have been tested"
