#!/bin/bash

#	permet de detruire le bridge qui
#	a le meme nom que le premier 
#	argument sur la ligne de commande
brctl delbr $1

echo "bridge destroyed : '$1'"
