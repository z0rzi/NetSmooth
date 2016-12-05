#include "Machine.h"
#include "Entitee.h"
#include "ElementListeChainee.h"

using namespace std;

ElementListeChainee::ElementListeChainee(Machine* m_machine0)
{
	this->m_machine = m_machine0;
  this->m_nextElement=NULL;
}

ElementListeChainee::~ElementListeChainee()
{
  delete this->m_machine;
}

void ElementListeChainee::setMachine(Machine* m_machine0)
{
  this->m_machine = m_machine0;
}

void ElementListeChainee::setNextElement(ElementListeChainee* m_nextElement0)
{
  this->m_nextElement=m_nextElement0;
}

Machine* ElementListeChainee::getMachine(void)
{
  return this->m_machine;
}

ElementListeChainee* ElementListeChainee::getNextElement(void)
{
  return this->m_nextElement;
}



