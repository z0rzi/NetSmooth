#include "Hub.h"

#include "DataBase.h"

Hub::Hub(int id)
	:Entitee(id, TYPE_HUB)
{
}

Hub::~Hub()
{
 DataBase::detruireHub(this);
}

int Hub::lancerContainer(){return 0;}
std::vector<struct paramIp*> Hub::getIpConfig(){}
void Hub::appliquerParamIp(){}
void Hub::appliquerParamRoutage4(){}
void Hub::appliquerParamRoutage6(){}
void Hub::stopperContainer(){}
void Hub::lierABridge(){}
void Hub::separerDeBridge(){}
void Hub::lireModifContainer(){}
void Hub::majIpContainer(){}
void Hub::majRouteContainer(){}
