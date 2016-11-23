#include "Entitee.h"

using namespace std;

Entitee::Entitee(int numType, int type)
{
	char nomBridge[10];
	char caratype='\0';
	if(type==TYPE_MACHINE)
		m_bridgeInit="\0";
	else
	{
		if(type==TYPE_PASSERELLE)
			caratype='P';
		if(type==TYPE_HUB)
			caratype='H';
		sprintf(nomBridge, "br%c%d", caratype, numType);
		m_bridgeInit=nomBridge;
	}
	m_type=type;
	m_bridgeActuel=m_bridgeInit;
	m_running=false;
	m_estConnecteAuBridge=false;
}

string Entitee::getBridgeInit(void) const
{
	return m_bridgeInit;
}

string Entitee::getBridgeActuel(void) const
{
	return m_bridgeActuel;
}

void Entitee::setBridgeActuel(string bridge)
{
	m_bridgeActuel=bridge;
}

void Entitee::setEtatMachine(bool etat)
{
	m_running=etat;
}

bool Entitee::getEtatMachine()
{
	return m_running;
}

int Entitee::getType()
{
	return m_type;
}

void Entitee::addCable(Cable *cable)
{
	m_cableList.push_back(cable);
}

vector<Cable*> Entitee::getCables(void)
{
	return m_cableList;
}

void Entitee::setConnexion(bool con)
{
	m_estConnecteAuBridge=con;
}

bool Entitee::getConnexion(void) const
{
	return m_estConnecteAuBridge;
}
