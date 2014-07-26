#!/bin/bash
./random
java a
java b
./compare a.txt b.txt
declare -i i=$?
for (( ; i==1 ; ))
do
    ./random
    java a
    java b
    ./compare a.txt b.txt
    i=$?;
done
