#ifndef ORDINATEUR_DEF
#define ORDINATEUR_DEF

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <signal.h>
#include <unistd.h>
#include <strings.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <lxc/lxccontainer.h>

class Entitee;

#include "Entitee.h"

/*	paramRoutage
 *
 *	structure qui permet de stocker les parametres de routage d'une machine pour les
 *	lui appliquer lors de son démarage
 */
struct paramRoutage
{
	std::string interface;
	std::string destination;
	std::string passerelle;
};

/*	paramIp
 *
 *	structure qui permet de stocker les parametres IP d'une machine pour les
 *	lui appliquer lors de son démarage
 */
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
		/*	Machine(int num, int type, struct lxc_container* c)
		 *
		 *	Constructeur de la classe, il appelle le constructeur
		 *	de Entitee et initialise l'argument container
		 *
		 *	ARGS
		 *	-num
		 *		numero de la machine
		 *	-type
		 *		type de la machine (TYPE_ORDINATEUR ou TYPE_PASSERELLE)
		 *	-c
		 *		container associé a la machine
		 */
		Machine(int num, int type, struct lxc_container* c);

		/*	struct lxc_container* getContainer() const
		 *
		 *	permet de recuperer le container associé a la machine
		 *	
		 *	RETURN VALUE
		 *	adresse du container associé a la machine
		 */
		struct lxc_container* getContainer(void) const;
		
		/*	void addIpConfig(struct paramIp ip)
		 *
		 *	permet d'ajouter une configuration IP a une machine
		 *
		 *	ARGS
		 *	-ip
		 *		structure contenant les parametres IP
		 *		a ajouter
		 */
		void addIpConfig(struct paramIp ip);

		/*	vector<struct paramIp> getIpConfig() const
		 *
		 *	permet de recuperer les configurations IP d'une machine
		 *
		 *	RETURN VALUE
		 *	tableau (sous forme de vector) contenant toutes les 
		 *	configurations IP
		 */
		std::vector<struct paramIp> getIpConfig() const;

		/*	void addRouteConfig(struct paramRoutage route)
		 *
		 *	permet d'ajouter une configuration de routage a une machine
		 *
		 *	ARGS
		 *	-route
		 *		structure contenant les parametres de routage
		 *		a ajouter
		 */
		void addRouteConfig(struct paramRoutage route);

		/*	vector<struct paramRoutage> getRouteConfig() const
		 *
		 *	permet de recuperer les configurations de routage d'une machine
		 *
		 *	RETURN VALUE
		 *	tableau (sous forme de vector) contenant touts les
		 *	parametres de routage de la machine
		 */
		std::vector<struct paramRoutage> getRouteConfig() const;
		
		/*	int lancerContainer()
		 *
		 *	permet de lancer le container associé a la machine
		 *
		 *	NOTE
		 *	Si vous voulez lancer la machine, utilisez la methode
		 *	launchEntitee de la classe entitee, cette methode ne lance
		 *	que le container, et ne fait pas toutes les opérations
		 *	annexes necessaire au bon lancement de la machine
		 */
		int lancerContainer();

		/*	int stopperContainer()
		 *
		 *	permet de stopper le container associé a la machine
		 *
		 *	RETURN VALUE
		 *	0 en cas de succes, -1 sinon
		 */
		void stopperContainer();

		/*	void force_stopperContainer()
		 *
		 *	permet de stopper le container associé a la machine, de
		 *	maniere plus violente que stopperContainer (il tue le PID
		 *	du container)
		 */
		void force_stopperContainer();

		/*	void lierABridge()
		 *
		 *	permet de lier le container au bridge actuel
		 *
		 *	NOTE
		 *	fonction a utiliser uniquement lorsque le container (et
		 *	donc la machine) est lancé
		 */
		void lierABridge();
		
		/*	void appliquerParamIp()
		 *
		 *	permet d'appliquer les parametres IP qui ont étés préalablement
		 *	ajoutés avec addIpConfig()
		 *
		 *	NOTE
		 *	fonction a utiliser uniquement lorsque le container (et
		 *	donc la machine) est lancé
		 */
		void appliquerParamIp();

		/*	void appliquerParamRoutage()
		 *
		 *	permet d'appliquer les parametres de routage qui ont étés 
		 *	préalablementi ajoutés avec addRouteConfig()
		 *
		 *	NOTE
		 *	fonction a utiliser uniquement lorsque le container (et
		 *	donc la machine) est lancé
		 */
		void appliquerParamRoutage();
		
		/*	void lancerCommandeDansContainer(char** commande)
		 *
		 *	permet de lancer une commande dans le container
		 *
		 *	ARGS
		 *	-commande:
		 *		chaine de caracteres a deux dimensions
		 *		representant la commande
		 *		exemple:char** cmd={"echo", "HelloWord", NULL};
		 *
		 *	NOTE
		 *	Le dernier element de la chaine doit etre NULL, comme dans
		 *	l'exemple ci dessus
		 *
		 *	fonction a utiliser uniquement lorsque le container (et
		 *	donc la machine) est lancé
		 */
		void lancerCommandeDansContainer(const char** commande);
		
		/*	void lancerXterm()
		 *
		 *	permet de lancer une fenetre Xterm representant le 
		 *	terminal de la machine
		 */
		void lancerXterm();
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
