#include "modeles/Cable.h"

using namespace std;

Cable::Cable(Entitee* ext1, Entitee* ext2)
        :m_ext1(ext1), m_ext2(ext2)
{
}

void Cable::getExtremites(Entitee** arr) const
{
    arr[0]=m_ext1;
    arr[1]=m_ext2;
}

VueCable* Cable::getVue()
{
    return this->m_vue;
}

void Cable::setVue(VueCable* vue)
{
    this->m_vue=vue;
}

Cable* Cable::creerCable(Entitee* ext1, Entitee* ext2)
{
    Cable* c = new Cable(ext1, ext2);
    ext1->addCable(c);
    ext2->addCable(c);

    return c;
}
