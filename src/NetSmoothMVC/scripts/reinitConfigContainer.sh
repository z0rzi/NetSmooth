#!/bin/bash

echo -n > /var/lib/lxc/$1/rootfs/.networkInfo/.ipConfig.info
echo -n > /var/lib/lxc/$1/rootfs/.networkInfo/.routeConfig.info
