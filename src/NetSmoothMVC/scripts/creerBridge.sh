#!/bin/bash

#	permet de créer un bridge dont 
#	le nom est le premier argument
brctl addbr $1

ifconfig $1 up 2> /dev/null

echo "bridge created : '$1'"
