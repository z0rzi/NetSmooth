#include "Entitee.h"

#include <iostream>

using namespace std;

Entitee::Entitee(int numType, int type)
{
	char nomBridge[10];
	char caratype='\0';
	if(type==TYPE_MACHINE)
		caratype='M';
	if(type==TYPE_PASSERELLE)
		caratype='P';
	if(type==TYPE_HUB)
		caratype='H';
	sprintf(nomBridge, "br%c%d", caratype, numType);
	m_bridge_virtuel=nomBridge;
	m_type=type;
	m_bridge_reel="\0";
	m_running=0;
}

string Entitee::getBridge_vir(void) const
{
	return m_bridge_virtuel;
}

string Entitee::getBridge_reel(void) const
{
	return m_bridge_reel;
}

void Entitee::setBridge_reel(string bridge)
{
	m_bridge_reel=bridge;
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
