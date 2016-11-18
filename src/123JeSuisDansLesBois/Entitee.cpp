#include "Entitee.h"

#include <iostream>

using namespace std;

Entitee::Entitee(int numType, const char type)
{
	char nomBridge[10];
	sprintf(nomBridge, "br%c%d", type, numType);
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

void Entitee::machineLancee()
{
	m_running=1;
}

void Entitee::machineAretee()
{
	m_running=0;
}

int Entitee::getEtatMachine()
{
	return m_running;
}

char Entitee::getType()
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
