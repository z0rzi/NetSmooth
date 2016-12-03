#ifndef MACHINE_DEF
#define MACHINE_DEF

#include <iostream>
#include <lxc/lxccontainer.h>

#include "Machine.h"

class Ordinateur : public Machine
{
	public:
		/*	Ordinateur(struct lxc_container* container)
		 *
		 *	constructeur de la classe, il initialise le container
		 *	associé a la machine, et appelle le constructeur de
		 *	parrent
		 *	
		 *	ARGS
		 *	-container:
		 *		container a associer a la machine
		 */
		Ordinateur(struct lxc_container* container);

	private:

		/*	numOrdi
		 *
		 * 	numero de la machine, il est unique a chaque
		 *	machine; il s'incrémente a la création de
		 *	machine
		 *	(donc pour la 5eme machine créée, il vaudra 4)
		 */
		static int numOrdi;
};

#endif
