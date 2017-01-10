#include "Passerelle.h"

using namespace std;

Passerelle::Passerelle(int id)
	:Machine(id, TYPE_PASSERELLE, "passerelle")
{
    for(int numInterface = 0; numInterface < NOMBRE_INTERFACES_PASSERELLE ; numInterface++)
    {
        ostringstream convert;
        convert << numInterface;
        struct paramIp* ip;
        *ip = {"eth"+convert.str(),"","",""};
        this->addIpConfig(ip);
    }
}

Passerelle::~Passerelle()
{
}
