#!/bin/bash

list=$(ls /var/lib/lxc/)

for c in $list; do
	lxc-destroy -n $c &
done
