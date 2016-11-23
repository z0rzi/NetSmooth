#ifndef ORDINATEUR_DEF
#define ORDINATEUR_DEF

#include <iostream>
#include <vector>
#include <lxc/lxccontainer.h>

class Entitee;

#include "Entitee.h"

struct paramRoutage
{
	std::string interface;
	std::string destination;
	std::string passerelle;
};
struct paramIp
{
	std::string interface;
	std::string ipv4;
	std::string maskv4;
	std::string ipv6;
	std::string maskv6;
};


class Machine : public Entitee
{
	public:
		Machine(int num, int type, struct lxc_container* c);
		/*	getContainer
		 *
		 *	permet de recuperer le container associé a la machine
		 *	
		 *	RETURN VALUE
		 *	adresse du container associé a la machine
		 */
		struct lxc_container* getContainer(void) const;

		void addIpConfig(struct paramIp ip);
		std::vector<struct paramIp> getIpConfig() const;

		void addRouteConfig(struct paramRoutage route);
		std::vector<struct paramRoutage> getRouteConfig() const;
	private:

		/*	container associé a la machine, quand on
		 *	fait tourner la machine, c'est ce container
		 *	que l'on lance
		 */
		struct lxc_container *m_container;

		std::vector<struct paramIp> m_paramIp;

		std::vector<struct paramRoutage> m_paramRoutage;
};

#endif
