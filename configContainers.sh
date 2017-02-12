#!/bin/bash

list=$(ls /var/lib/lxc/)

for i in $list; do
	path="/var/lib/lxc/$i/rootfs"
	mkdir $path/.networkInfo
	path=$path/root
	echo "alias route='~/.scr/aliasRoute.sh'" >> $path/.bashrc
	echo "alias ifconfig='~/.scr/aliasIfconfig.sh'" >> $path/.bashrc
	echo "~/.scr/aliasRoute.sh > /dev/null" >> $path/.bashrc
	echo "~/.scr/aliasIfconfig.sh > /dev/null" >> $path/.bashrc
	mkdir $path/.scr
	path="$path/.scr"

	echo "	#!/bin/bash" > $path/aliasRoute.sh
	echo "	route \$@" >> $path/aliasRoute.sh
	echo "	echo -n > /.networkInfo/routeConfig.info" >> $path/aliasRoute.sh
	echo "	a=\$(route | grep [.] | sed ':a;N;\$!ba;s/\n/ = /g')" >> $path/aliasRoute.sh
	echo "	i=\$(route | grep [.] | wc -l)" >> $path/aliasRoute.sh
	echo "	while [ \$i -gt 0 ]; do" >> $path/aliasRoute.sh
	echo "		echo \"\$a\" | awk {'print \$8'} >> /.networkInfo/routeConfig.info	# interface" >> $path/aliasRoute.sh
	echo "		echo \"\$a\" | awk {'print \$1'} >> /.networkInfo/routeConfig.info	# dest" >> $path/aliasRoute.sh
	echo "		echo \"\$a\" | awk {'print \$2'} >> /.networkInfo/routeConfig.info	# pass" >> $path/aliasRoute.sh
	echo "		echo \"\$a\" | awk {'print \$3'} >> /.networkInfo/routeConfig.info	# mask" >> $path/aliasRoute.sh
	echo "		dist=\$(expr index \"\$a\" \"=\")" >> $path/aliasRoute.sh
	echo "		a=\${a:\$dist:\${#a}}" >> $path/aliasRoute.sh
	echo "		i=\$((i-1))" >> $path/aliasRoute.sh
	echo "	done" >> $path/aliasRoute.sh


	echo "	#!/bin/bash" > $path/aliasIfconfig.sh
	echo "	ifconfig \$@" >> $path/aliasIfconfig.sh
	echo "	echo -n > /.networkInfo/ipConfig.info" >> $path/aliasIfconfig.sh
	echo "	listIfaces=\$(ls /sys/class/net)" >> $path/aliasIfconfig.sh
	echo "	for iface in \$listIfaces; do" >> $path/aliasIfconfig.sh
	echo "		echo \$iface >> /.networkInfo/ipConfig.info	#interface" >> $path/aliasIfconfig.sh
	echo "		echo \$(ifconfig \$iface | grep -w inet | tr \":\" \" \" | awk {'print \$3'}) >> /.networkInfo/ipConfig.info	#ipv4" >> $path/aliasIfconfig.sh
	echo "		echo \$(ifconfig \$iface | grep -w inet | tr \":\" \" \" | awk {'print \$7'}) >> /.networkInfo/ipConfig.info	#mask" >> $path/aliasIfconfig.sh
	echo "		echo \$(ifconfig \$iface | grep -w inet6 | awk {'print \$3'}) >> /.networkInfo/ipConfig.info	#ipv6" >> $path/aliasIfconfig.sh
	echo "	done" >> $path/aliasIfconfig.sh

	chmod 775 $path/*.sh
done
