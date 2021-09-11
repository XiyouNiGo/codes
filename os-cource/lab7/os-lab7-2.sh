#!/bin/bash
for ((i = 0; i < 5; i++));do
{
    sleep 1;
    echo 1 >> aa && echo "done!"
} &
done
wait
cat aa | wc -l
rm aa
