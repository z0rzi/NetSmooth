#include "Machine.h"
#include "Entitee.h"
#include "ElementListeChainee.h"

using namespace std;

ElementListeChainee::ElementListeChainee(Entitee* m_entitee0,ElementListeChainee* m_nextElement0)
{
	this->m_entitee = m_entitee0;
	this->m_nextElement=m_nextElement0;
}

ElementListeChainee::~ElementListeChainee()
{
	delete this->m_entitee;
}

void ElementListeChainee::setEntitee(Entitee* m_entitee0)
{
	this->m_entitee = m_entitee0;
}

void ElementListeChainee::setNextElement(ElementListeChainee* m_nextElement0)
{
	this->m_nextElement=m_nextElement0;
}

Entitee* ElementListeChainee::getEntitee(void)
{
	return this->m_entitee;
}

ElementListeChainee* ElementListeChainee::getNextElement(void)
{
	return this->m_nextElement;
}



