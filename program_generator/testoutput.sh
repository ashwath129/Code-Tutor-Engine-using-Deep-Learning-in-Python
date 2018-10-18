#!/bin/bash

i=1
while [ $i -le 48 ]
do
	./compiled/$i
	echo "\n"
	i=$((i+1))
done


