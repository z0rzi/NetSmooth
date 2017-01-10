#include "Ordinateur.h"

using namespace std;

Ordinateur::Ordinateur(int id)
	:Machine(id, TYPE_ORDINATEUR, "ordinateur")
{

    for(int numInterface = 0; numInterface < NOMBRE_INTERFACES_ORDINATEUR ; numInterface++)
    {
        ostringstream convert;
        convert << numInterface;
        struct paramIp ip = {"eth"+convert.str(),"","",""};
        this->addIpConfig(ip);
    }

}

Ordinateur::~Ordinateur(void)
{

}
