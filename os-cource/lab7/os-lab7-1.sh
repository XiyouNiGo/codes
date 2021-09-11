#!/bin/bash
for ((i = 0; i < 5; i++));do
{
    sleep 1;
    echo 1 >> aa && echo "done!"
} done
cat aa | wc -l
rm aa
