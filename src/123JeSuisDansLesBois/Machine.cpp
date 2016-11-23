#include "Machine.h"

using namespace std;

Machine::Machine(int num, int type, struct lxc_container* c)
	:Entitee(num, type), m_container(c)
{
}

void Machine::addIpConfig(struct paramIp ip)
{
	m_paramIp.push_back(ip);
}

vector<struct paramIp> Machine::getIpConfig() const
{
	return m_paramIp;
}

void Machine::addRouteConfig(struct paramRoutage route)
{
	m_paramRoutage.push_back(route);
}

vector<struct paramRoutage> Machine::getRouteConfig() const
{
	return m_paramRoutage;
}


struct lxc_container* Machine::getContainer(void) const
{
	return m_container;
}
