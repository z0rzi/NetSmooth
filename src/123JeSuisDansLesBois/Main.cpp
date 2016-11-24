#include <iostream>
#include <string>
#include <cstdlib>
#include <signal.h>
#include <lxc/lxccontainer.h>
#include <unistd.h>
#include <strings.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "Constantes.h"
#include "Ordinateur.h"
#include "Passerelle.h"
#include "Cable.h"
#include "Hub.h"

using namespace std;

void creerBridge(const char* nomPont)
{
	int x=fork();

	if(x==-1)
	{
		perror("fork");
		exit(1);
	}
	if(x==0)
	{
		execl("./creerBridge.sh", "createBridge", nomPont, NULL);
		exit(0);
	}
	int useless;
	while(waitpid(0, &useless, WUNTRACED)<0);
}

void detruireBridge(const char* nomPont)
{
	int x=fork();

	if(x==-1)
	{
		perror("fork");
		exit(1);
	}
	if(x==0)
	{
		execl("./detruireBridge.sh", "destroyBridge", nomPont, NULL);
		exit(0);
	}
	int useless;
	while(waitpid(0, &useless, WUNTRACED)<0);
}









int main(void)
{
	struct lxc_container* cnt1=lxc_container_new("machine0", NULL);
	struct lxc_container* cnt2=lxc_container_new("machine1", NULL);
	struct lxc_container* cnt3=lxc_container_new("gateway0", NULL);

	Ordinateur m0(cnt1), m1(cnt2);
	Passerelle p(cnt3);

	struct paramIp ip={"eth0", "192.168.0.10", "255.255.255.0", "", ""};
	m0.addIpConfig(ip);

	ip.ipv4="172.16.0.10";
	m1.addIpConfig(ip);

	ip.ipv4="172.16.0.1";
	p.addIpConfig(ip);
	ip.interface="eth1";
	ip.ipv4="192.168.0.1";
	p.addIpConfig(ip);


	struct paramRoutage route={"eth0", "172.16.0.0/24", "192.168.0.1"};
	m0.addRouteConfig(route);

	route.destination="192.168.0.0/24";
	route.passerelle="172.16.0.1";
	m1.addRouteConfig(route);
	
	Hub h0, h1;

	Cable c0(&m0, &h0);
	m0.addCable(&c0);
	h0.addCable(&c0);

	Cable c1(&m1, &h1);
	m1.addCable(&c1);
	h1.addCable(&c1);

	Cable c2(&p, &h0);
	p.addCable(&c2);
	h0.addCable(&c2);

	Cable c3(&p, &h1);
	p.addCable(&c3);
	h1.addCable(&c3);

	launchEntitee(&m0);
	launchEntitee(&m1);
	launchEntitee(&h0);
	launchEntitee(&h1);
	launchEntitee(&p);

	lancerXterm(&m0);
	lancerXterm(&m1);
	lancerXterm(&p);

	cout << "entrez quelque chose pour finir" << endl;
	int bobo;
	cin >> bobo;

	stoperContainer(cnt1);
	stoperContainer(cnt2);
	stoperContainer(cnt3);


	return 0;
}
