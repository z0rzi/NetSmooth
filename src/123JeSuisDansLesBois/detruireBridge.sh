#!/bin/bash

brctl delbr $1

echo "bridge destroyed : '$1'"
