#!/bin/bash

for i in "echo $PATH | tr ':' ' '"
do
	if test -e "$i/$1"
	then
		if test -f $i/$1
		then echo $i/$1
		fi
	fi
done
