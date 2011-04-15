#!/bin/bash

usage() {
  echo "Teetime: The same as tee but prepend each line with the current time when the data is received."
  echo ""
  echo "Usage:"
  echo $(basename $0) "[-h] [-a] [-v] filename"
  echo "Parameters:"
  echo -e "\tfilename\tFile to write to"
  echo "Options:"
  echo -e "\t-a\tAppend to file"
  echo -e "\t-v\tProduce verbose output"
  echo -e "\t-h\tShow usage and exit"
}

printVerbose() {
  if [ $VERBOSE ]
  then
    echo "$1"
  fi
}

APPEND=    # Specify if content file should be appended to output file
VERBOSE=   # Specify if verbose oputput should be produced

while getopts ":ahv" opt; do
    case $opt in
        a) APPEND=1
            ;;
        v) VERBOSE=1
           printVerbose "Using Verbose output"
            ;;
        h) usage
            exit 0
            ;;
        *) usage
            echo "Option not recognized: $OPTARG"
            exit 1
            ;;
    esac
done
shift $(($OPTIND - 1))

if [ ! $1 ]
then
  usage
  echo Error: not enough arguments
  exit 1
fi

printVerbose "Redirecting to $1"

if [ ! $APPEND ]
then
  if [ -e $1 ]
  then
    rm $1
  fi
else
  printVerbose "Appending to file"
fi

while read myline
do
  Line="[$(date +%T)] $myline"
  echo $Line
  if [ $1 ]
  then
    echo $Line >> $1
  fi
done

exit 0
