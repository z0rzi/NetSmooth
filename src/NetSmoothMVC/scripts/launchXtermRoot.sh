#!/bin/bash

xterm -hold -T "$2" -e "lxc-attach -n $1; kill \$PPID"
