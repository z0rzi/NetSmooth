#!/bin/bash

ifconfig $1 down
brctl delbr $1

echo "bridge destroyed : '$1'"
