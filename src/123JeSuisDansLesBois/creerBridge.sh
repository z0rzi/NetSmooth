#!/bin/bash

#	permet de créer un bridge dont 
#	le nom est le premier argument
brctl addbr $1

echo "bridge created : '$1'"
