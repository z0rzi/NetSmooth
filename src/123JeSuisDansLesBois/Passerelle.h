#ifndef PASSERELLE_DEF
#define PASSERELLE_DEF

#include <iostream>
#include <lxc/lxccontainer.h>

#include "Cable.h"
#include "Ordinateur.h"


class Passerelle : public Ordinateur
{
	public:
		/*	Passerelle
		 *
		 *	constructeur de la classe, initialise le container
		 *	et appelle le constructeur de son parent
		 *	
		 *	ARGS
		 *	-container:	adresse du container associé a la
		 *			Passerelle
		 */
		Passerelle(struct lxc_container* container);

	private:
		static int numPass;
};

#endif
