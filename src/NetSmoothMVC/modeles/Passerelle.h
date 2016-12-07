#ifndef PASSERELLE_DEF
#define PASSERELLE_DEF

#include <iostream>
#include <lxc/lxccontainer.h>

#include "Machine.h"


class Passerelle : public Machine
{
	public:
		/*	Passerelle(struct lxc_container* container)
		 *
		 *	constructeur de la classe, initialise le container
		 *	et appelle le constructeur de son parent
		 *	
		 *	ARGS
		 *	-container:
		 *		adresse du container associé a la
		 *		Passerelle
		 */
		Passerelle(int id);

	private:
		/*	numPass
		 *
		 *	numero de la passerelle, il est unique a chaque
		 *	passerelle; il s'incrémente a la création de
		 *	passerelle
		 *	(donc pour la 5eme passerelle créée, il vaudra 4)
		 */
};

#endif
