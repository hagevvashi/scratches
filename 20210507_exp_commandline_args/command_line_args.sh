#!/usr/bin/env bash
set -euo pipefail

remote='origin'

while getopts b: OPT
do
  case $OPT in
     b) remote=$OPTARG
        ;;
  esac
done

echo $remote
