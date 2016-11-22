#include "Machine.h"
#include "Cable.h"
#include "Entitee.h"
#include <lxc/lxccontainer.h>

using namespace std;

int Machine::numMachine=0;

Machine::Machine(struct lxc_container *container)
		:Entitee(numMachine, TYPE_MACHINE), m_container(container)
{
	numMachine++;
}

struct lxc_container* Machine::getContainer(void) const
{
	return m_container;
}

void Machine::setIpConfig(struct paramIp* ip)
{
	m_paramIp=ip;
  if(m_paramIp->interface == "")
    goto End;
 // FAIRE VERIFICATIONS DU CONTENU m_param
  
  lxc_attach_options_t options = LXC_ATTACH_OPTIONS_DEFAULT;
  pid_t pid;

  char* argsV4[]={"ifconfig",m_paramIp->interface,m_paramIp->ipv4,"netmask",m_paramIp->maskv4,"up"};
  char* argsV6[]={"ifconfig",m_paramIp->interface,m_paramIp->ipv6,"netmask",m_paramIp->maskv6,"up"};
  
  lxc_attach_command_t commandV4= {"ifconfig",argsV4};
  lxc_attach_command_t commandV6= {"ifconfig",argsV6};
  
  if(m_container->attach(m_container,lxc_attach_run_command,commandV4,&options,&pid)!=0)
  {
    perror("attach Machine::setIpConfig");
  }

  if(m_container->attach(m_container,lxc_attach_run_command,commandV4,&options,&pid)!=0)
  {
    perror("attach Machine::setIpConfig");
  }

  End:

}

struct paramIp* Machine::getIpConfig() const
{
	return m_paramIp;
}
