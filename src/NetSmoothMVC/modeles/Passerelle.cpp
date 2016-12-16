#include "Passerelle.h"

using namespace std;

Passerelle::Passerelle(int id)
	:Machine(id, TYPE_PASSERELLE, "passerelle")
{
    cout << "A"<<endl;
}

Passerelle::~Passerelle()
{
}
