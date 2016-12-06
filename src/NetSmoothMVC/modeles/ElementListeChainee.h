#ifndef ELEMENTLISTECHAINEE_DEF
#define ELEMENTLISTECHAINEE_DEF

#include <iostream>
#include <vector>

#include "Machine.h"
#include "Entitee.h"

class ElementListeChainee
{

  public:

    ElementListeChainee(Machine* m_machine0,ElementListeChainee* m_nextElement0);
    ~ElementListeChainee();
    
    void setMachine(Machine* m_machine0);
    void setNextElement(ElementListeChainee* m_nextElement0);

    Machine* getMachine();
    ElementListeChainee* getNextElement();

  private:
    /* 	les adresses des deux extrémitées du
     *	cable (ext comme extrémitée) 
     */
    Machine* m_machine;
    ElementListeChainee* m_nextElement;
};

#endif
