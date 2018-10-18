#!/bin/bash

i=1
while [ $i -le 48 ]
do
	gcc "programs/$i.c" -o "compiled/$i"
	i=$((i+1))
done


