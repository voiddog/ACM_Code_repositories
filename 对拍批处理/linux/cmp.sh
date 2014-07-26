#!/bin/bash
./random
./a
./b
./compare a.txt b.txt
declare -i i=$?
for (( ; i==1 ; ))
do
    ./random
    ./a
    ./b
    ./compare a.txt b.txt
    i=$?;
done
