#!/bin/bash

usage() {
  echo "The same as tee but prepend each line with the time the line is received."
  echo ""
  echo "Usage:"
  echo `basename $0` "[-h] [-a] file"
  echo "Parameters:"
  echo -e "\tfile\tname of file to write to"
  echo "Options:"
  echo -e "\t-a\tAppends to file"
  echo -e "\t-h\tShow usage and exit"
}

APPEND=

while getopts ":ah" opt; do
    case $opt in
        a) APPEND=1
            ;;
        h) usage
            exit 0
            ;;
        *) usage
            exit 1
            ;;
    esac
    shift
done

if [ ! $1 ]
then
  usage
  echo Error: not enough arguments
  exit 1
fi

echo "Redirecting to $1"

if [ ! $APPEND ] && [ -e $1 ]
then
  rm $1
fi

while read myline
do
  Line="[`date +%T`] $myline"
  echo $Line
  if [ $1 ]
  then
    echo $Line >> $1
  fi
done

