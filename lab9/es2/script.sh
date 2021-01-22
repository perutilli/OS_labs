#!/bin/bash

while true;
do
	sleep $1
	if !(who | grep $2)
	then
		echo "$2 logged out"
	else
		echo "$2 is still logged in"
	fi
done
