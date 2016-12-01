#include "Hub.h"

using namespace std;

int Hub::numHub=0;

Hub::Hub()
	:Entitee(numHub, TYPE_HUB)
{
	numHub++;
}

void Hub::appliquerParamIp(){}
void Hub::appliquerParamRoutage(){}
int Hub::lancerContainer(){}
int Hub::stopperContainer(){}
void Hub::lierABridge(){}
