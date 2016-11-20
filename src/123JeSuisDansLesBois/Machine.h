#ifndef MACHINE_DEF
#define MACHINE_DEF

#include <iostream>
#include <lxc/lxccontainer.h>

#include "Entitee.h"
#include "Cable.h"

class Machine : public Entitee
{
	public:
		/*	Machine
		 *
		 *	constructeur de la classe, il initialise le container
		 *	associé a la machine, et appelle le constructeur de
		 *	parrent
		 *	
		 *	ARGS
		 *	-container:	container a associer a la machine
		 */
		Machine(struct lxc_container* container);

		/*	getContainer
		 *
		 *	permet de recuperer le container associé a la machine
		 *	
		 *	RETURN VALUE
		 *	adresse du container associé a la machine
		 */
		struct lxc_container* getContainer(void) const;

	private:
		/*	container associé a la machine, quand on
		 *	fait tourner la machine, c'est ce container
		 *	que l'on lance
		 */
		struct lxc_container *m_container;

		/*	ipv4 de la machine
		 */
		std::string m_ipv4;

		/*	masque ipv4 de la machine
		 */
		std::string m_masqueIpv4;

		/*	ipv6 de la machine
		 */
		std::string m_ipv6;

		/*	masque ipv6 de la machine
		 */
		std::string m_masqueIpv6;

		/*	numero de la machine, il est unique a chaque
		*	machine; il s'incrémente a la création de
		*	machine
		*	(donc pour la 5eme machine créée, il vaudra 4)
		*/
		static int numMachine;
};

#endif
