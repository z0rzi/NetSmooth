#include "Passerelle.h"
#include "Cable.h"
#include "Entitee.h"

using namespace std;

int Passerelle::numPass=0;

Passerelle::Passerelle(struct lxc_container *container)
		:Entitee(numPass, 'P'), m_container(container)
{
	numPass++;
}

struct lxc_container* Passerelle::getContainer(void) const
{
	return m_container;
}
