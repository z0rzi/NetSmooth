#include "Ordinateur.h"

using namespace std;

Ordinateur::Ordinateur(int num, int type, struct lxc_container* c)
	:Entitee(num, type), m_container(c)
{
}

void Ordinateur::addIpConfig(struct paramIp ip)
{
	m_paramIp.push_back(ip);
}

vector<struct paramIp> Ordinateur::getIpConfig() const
{
	return m_paramIp;
}


struct lxc_container* Ordinateur::getContainer(void) const
{
	return m_container;
}
