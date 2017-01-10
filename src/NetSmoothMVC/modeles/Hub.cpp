#include "Hub.h"

using namespace std;


Hub::Hub(int id)
	:Entitee(id, TYPE_HUB)
{
}

int Hub::lancerContainer(){return 0;}
std::vector<struct paramIp*> Hub::getIpConfig(){}
void Hub::appliquerParamIp(){}
void Hub::appliquerParamRoutage4(){}
void Hub::appliquerParamRoutage6(){}
void Hub::stopperContainer(){}
void Hub::lierABridge(){}
void Hub::separerDeBridge(){}
