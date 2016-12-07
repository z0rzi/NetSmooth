#include "Hub.h"

using namespace std;


Hub::Hub(int id)
	:Entitee(id, TYPE_HUB)
{
}

void Hub::appliquerParamIp(){}
void Hub::appliquerParamRoutage(){}
int Hub::lancerContainer(){}
void Hub::stopperContainer(){}
void Hub::lierABridge(){}
