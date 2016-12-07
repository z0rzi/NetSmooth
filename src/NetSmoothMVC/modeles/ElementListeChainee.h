#ifndef ELEMENTLISTECHAINEE_DEF
#define ELEMENTLISTECHAINEE_DEF

#include <iostream>
#include <vector>

#include "Machine.h"
#include "Entitee.h"

class ElementListeChainee
{

  public:

    ElementListeChainee(Entitee* m_entitee0,ElementListeChainee* m_nextElement0);
    ~ElementListeChainee();
    
    void setEntitee(Entitee* m_entitee0);
    void setNextElement(ElementListeChainee* m_nextElement0);

    Entitee* getEntitee();
    ElementListeChainee* getNextElement();

  private:
    /* 	les adresses des deux extrémitées du
     *	cable (ext comme extrémitée) 
     */
    Entitee* m_entitee;
    ElementListeChainee* m_nextElement;
};

#endif
