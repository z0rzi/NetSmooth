#include "Hub.h"

using namespace std;


Hub::Hub(int id)
	:Entitee(id, TYPE_HUB)
{
}

int Hub::lancerContainer(){return 0;}
void Hub::appliquerParamIp(){}
void Hub::appliquerParamRoutage(){}
void Hub::stopperContainer(){}
void Hub::lierABridge(){}
void Hub::separerDeBridge(){}
