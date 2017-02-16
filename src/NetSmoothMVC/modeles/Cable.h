#ifndef CABLE_DEF
#define CABLE_DEF

class VueCable;

#include <iostream>
#include <vector>
#include "vues/vuecable.h"

class Entitee;

#include "Entitee.h"


class Cable
{

public:
    Cable(Entitee *ext1, Entitee *ext2);

    /*	void getExtremitees(Entitee** arr) const
         *
         *	ARGS
         *	-arr:
         *		doit etre un tableau vide de 2 cases:
         *	     	Entitee bobo[2]; par exemple
         *	    	le code rempli ce tableau avec les
         *	    	adresses des extremitées du cable
         */
    void getExtremites(Entitee** arr) const;

    VueCable* getVue();
    void setVue(VueCable* vue);

    static Cable* creerCable(Entitee* ext1, Entitee* ext2);

private:
    /* 	m_ext1 & m_ext2
         *
         *  	les adresses des deux extrémitées du
         *	cable (ext comme extrémitée)
         */
    Entitee *m_ext1;
    Entitee *m_ext2;
    VueCable* m_vue;
};

#endif
