#ifndef VUEMACHINE_H
#define VUEMACHINE_H

#include "vueentitee.h"
#include <iostream>

using namespace std;

class VueMachine : public VueEntitee
{
	Q_OBJECT
	public:
		explicit VueMachine(VueEntitee *parent = 0);
		Ordinateur* getOrdinateur(void);
	private:
		Ordinateur* ordinateur=NULL;

};

#endif // VUEMACHINE_H
