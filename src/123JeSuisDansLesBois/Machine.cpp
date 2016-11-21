#include "Machine.h"
#include "Cable.h"
#include "Entitee.h"

using namespace std;

int Machine::numMachine=0;

Machine::Machine(struct lxc_container *container)
		:Entitee(numMachine, TYPE_MACHINE), m_container(container)
{
	numMachine++;
}

struct lxc_container* Machine::getContainer(void) const
{
	return m_container;
}

void Machine::setIpConfig(struct paramIp* ip)
{
	m_paramIp=ip;
}

struct paramIp* Machine::getIpConfig() const
{
	return m_paramIp;
}
