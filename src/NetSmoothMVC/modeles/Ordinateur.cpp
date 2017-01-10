#include "Ordinateur.h"

using namespace std;

Ordinateur::Ordinateur(int id)
	:Machine(id, TYPE_ORDINATEUR, "ordinateur")
{

    for(int numInterface = 0; numInterface < NOMBRE_INTERFACES_ORDINATEUR ; numInterface++)
    {
        cout << "ok x " << endl;
        ostringstream convert;
        convert << numInterface;

        //POURQUOI MALLOC NE FONCTIONNE PAS?? VINCENT
        //struct paramIp* ip = (struct paramIp*) malloc(sizeof(struct paramIp));
        struct paramIp* ip = new paramIp();
        ip->interface="eth"+convert.str();
        ip->ipv4="";
        ip->ipv6="";
        ip->maskv4="";

        this->addIpConfig(ip);
        cout << "ok deux " << endl;
    }

}

Ordinateur::~Ordinateur(void)
{

}
