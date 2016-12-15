# NetSmooth

## Prérequis
logiciels:
* Qt version 5.5.3
* LXC & lxc-devel

containers:
* 10 containers de type *"machine"*
* 5 containers de type *"passerelle"*


## Compilation
Executez le fichier **make.sh** dans *./src/build-NetSmoothMVC-Desktop-Debug/* afin de compiler le programme.
Puis, lancez l'executable créé (**NetSmoothMVC**)


## Note
Fichier de configuration d'un container de type *"machine"* :

	lxc.include = /usr/share/lxc/config/debian.common.conf
	lxc.arch = x86
	lxc.network.type = veth
	lxc.network.name = eth0
	lxc.network.flags = up
	lxc.rootfs = /var/lib/lxc/<nom du container>/rootfs
	lxc.utsname = <nom du container>


Fichier de configuration d'un container de type *"passerelle"* :

	lxc.include = /usr/share/lxc/config/debian.common.conf
	lxc.arch = x86
	lxc.network.type = veth
	lxc.network.name = eth0
	lxc.network.flags = up
	lxc.network.type = veth
	lxc.network.name = eth1
	lxc.network.flags = up
	lxc.rootfs = /var/lib/lxc/<nom du container>/rootfs
	lxc.utsname = <nom du container>
