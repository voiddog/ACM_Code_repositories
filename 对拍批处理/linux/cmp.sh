#!/bin/bash
./random
./a
./b
cmp a.txt b.txt
declare -i i=$?
for (( ; i==0 ; ))
do
    echo "ok"
    ./random
    ./a
    ./b
    cmp a.txt b.txt
    i=$?;
done
