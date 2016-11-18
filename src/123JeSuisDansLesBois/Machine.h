#ifndef MACHINE_DEF
#define MACHINE_DEF

#include <iostream>
#include <lxc/lxccontainer.h>

#include "Entitee.h"
#include "Cable.h"

class Machine : public Entitee
{
	public:
		Machine(struct lxc_container* container);
		struct lxc_container* getContainer(void) const;

	private:
		struct lxc_container *m_container;
		std::string m_ipv4;
		std::string m_masqueIpv4;
		std::string m_ipv6;
		std::string m_masqueIpv6;
		static int numMachine;
};

#endif
