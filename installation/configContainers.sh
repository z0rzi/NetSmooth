#!/bin/bash

list=$(ls /var/lib/lxc/)
if [ "$1" = "clean" ]; then
	for i in $list; do
		path="/var/lib/lxc/$i/rootfs"
		rm -rf $path/.scr
		rm -rf $path/.networkInfo
		cp $path/etc/.bash.bashrc $path/etc/bash.bashrc
	done
else
	for i in $list; do
		path="/var/lib/lxc/$i/rootfs"
		if ! [ -e $path/etc/.bash.bashrc ]; then
			cp $path/etc/bash.bashrc $path/etc/.bash.bashrc
		fi
		mkdir $path/.networkInfo
		echo "alias route='/.scr/aliasRoute.sh'" >> $path/etc/bash.bashrc
		echo "alias ifconfig='/.scr/aliasIfconfig.sh'" >> $path/etc/bash.bashrc
		echo "alias ip='/.scr/aliasIp.sh'" >> $path/etc/bash.bashrc
		echo "/.scr/majIpconfig.sh" >> $path/etc/bash.bashrc
		echo "/.scr/majRouteconfig.sh" >> $path/etc/bash.bashrc
		mkdir $path/.scr
		path="$path/.scr"

		echo "#!/bin/bash" > $path/aliasIp.sh
		echo "ip \$@" >> $path/aliasIp.sh
		echo "/.scr/majIpconfig.sh" >> $path/aliasIp.sh

		echo "#!/bin/bash" > $path/aliasIfconfig.sh
		echo "ifconfig \$@" >> $path/aliasIfconfig.sh
		echo "/.scr/majIpconfig.sh" >> $path/aliasIfconfig.sh

		echo "#!/bin/bash" > $path/aliasRoute.sh
		echo "route \$@" >> $path/aliasRoute.sh
		echo "/.scr/majRouteconfig.sh" >> $path/aliasRoute.sh

		echo "#!/bin/bash" > $path/majRouteconfig.sh
		echo "echo -n > /.networkInfo/routeConfig.info" >> $path/majRouteconfig.sh
		echo "a=\$(route | grep [.] | sed ':a;N;\$!ba;s/\n/ = /g')" >> $path/majRouteconfig.sh
		echo "i=\$(route | grep [.] | wc -l)" >> $path/majRouteconfig.sh
		echo "while [ \$i -gt 0 ]; do" >> $path/majRouteconfig.sh
		echo "	echo \"\$a\" | awk {'print \$8'} >> /.networkInfo/routeConfig.info	# interface" >> $path/majRouteconfig.sh
		echo "	echo \"\$a\" | awk {'print \$1'} >> /.networkInfo/routeConfig.info	# dest" >> $path/majRouteconfig.sh
		echo "	echo \"\$a\" | awk {'print \$2'} >> /.networkInfo/routeConfig.info	# pass" >> $path/majRouteconfig.sh
		echo "	echo \"\$a\" | awk {'print \$3'} >> /.networkInfo/routeConfig.info	# mask" >> $path/majRouteconfig.sh
		echo "	dist=\$(expr index \"\$a\" \"=\")" >> $path/majRouteconfig.sh
		echo "	a=\${a:\$dist:\${#a}}" >> $path/majRouteconfig.sh
		echo "	i=\$((i-1))" >> $path/majRouteconfig.sh
		echo "done" >> $path/majRouteconfig.sh


		echo "#!/bin/bash" > $path/majIpconfig.sh
		echo "echo -n > /.networkInfo/ipConfig.info" >> $path/majIpconfig.sh
		echo "listIfaces=\$(ls /sys/class/net)" >> $path/majIpconfig.sh
		echo "for iface in \$listIfaces; do" >> $path/majIpconfig.sh
		echo "	echo \$iface >> /.networkInfo/ipConfig.info	#interface" >> $path/majIpconfig.sh
		echo "	echo \$(ifconfig \$iface | grep -w inet | tr \":\" \" \" | awk {'print \$3'}) >> /.networkInfo/ipConfig.info	#ipv4" >> $path/majIpconfig.sh
		echo "	echo \$(ifconfig \$iface | grep -w inet | tr \":\" \" \" | awk {'print \$7'}) >> /.networkInfo/ipConfig.info	#mask" >> $path/majIpconfig.sh
		echo "	echo \$(ifconfig \$iface | grep -w inet6 | awk {'print \$3'}) >> /.networkInfo/ipConfig.info	#ipv6" >> $path/majIpconfig.sh
		echo "done" >> $path/majIpconfig.sh

		chmod 775 $path/*.sh
	done
fi
