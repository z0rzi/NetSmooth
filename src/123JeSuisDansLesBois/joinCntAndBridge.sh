#!/bin/bash

#	permet de relier un container a un
#	bridge

if [ $# -ne 2 ] ; then
	echo "USAGE = $0 <container name> <bridge name>"
	echo "you wrote $0 $1 $2 $3"
	exit
fi

a=$(lxc-info -n $1 | grep Link)

for result in $a ; do
	if [ "$result" != "Link:" ]; then
		brctl addif $2 $result
	fi
done
