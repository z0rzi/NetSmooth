#ifndef PASSERELLE_DEF
#define PASSERELLE_DEF

#include <iostream>
#include <lxc/lxccontainer.h>

#include "Entitee.h"
#include "Cable.h"

class Passerelle : public Entitee
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

		/*	getContainer
		 *
		 *	renvoie le container associé a la passerelle
		 *	
		 *	RETURN VALUE
		 *	adresse du container associé a la passerelle
		 */
		struct lxc_container* getContainer(void) const;

	private:
		/*	container associé a la passerelle, quand on
		 *	fait tourner la passerelle, c'est ce container
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

		/*	numero de la passerelle, il est unique a chaque
		*	passerelle; il s'incrémente a la création de
		*	passerelle 
		*	(donc pour la 5eme passerelle créée, il vaudra 4)
		*/
		static int numPass;
};

#endif
