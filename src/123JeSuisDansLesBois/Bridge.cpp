#include "Bridge.h"

using namespace std;

void Bridge::creerBridge(const char* nomPont)
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

void Bridge::detruireBridge(const char* nomPont)
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
