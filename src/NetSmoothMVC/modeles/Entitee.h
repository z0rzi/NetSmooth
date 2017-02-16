#ifndef ENTITEE_DEF
#define ENTITEE_DEF

class Cable;
class VueEntitee;

#include <iostream>
#include <stdio.h>
#include <string>
#include <strings.h>
#include "Constantes.h"
#include "Bridge.h"
#include <vector>

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
};

class Entitee
{
public:
        /*	Entitee(int numType, int type)
                 *
                 *	Constructeur de la classe, il initialise le
                 *	nom de bridge par defaut (ou bridge Initial) pour hub
                 *	et passerelles
                 *
                 *	ARGS
                 *	-numtype :
                 *		numero de la machine créée, il doit
                 *		etre unique pour chaque ma de meme
                 *		type
                 *
                 *	-type :
                 *		numero correspondant au type, se
                 *		réferer au fichier
                 *		Constantes.h -> TYPE_****
                 */
        Entitee(int id, int type);

        /*	string getBridgeInit() const
                 *
                 *	permet de recupérer le bridge Initial de la machine
                 *
                 *	RETURN VALUE
                 *	nom du bridge initial
                 *
                 *	NOTE
                 *	Mais dis moi Jammie, c'est quoi un bridge initial?
                 *		   vas voir dans la description des
                 *		   attributs de la classe plus bas
                 */
        std::string getBridgeInit(void) const;

        /*	string getBridgeActuel() const
                 *
                 *	permet de recupérer le bridge Actuel de la machine
                 *
                 *	RETURN VALUE
                 *	nom du bridge actuel
                 *
                 *	NOTE
                 *	Mais dis moi Jammie, c'est quoi un bridge Actuel?
                 *		   vas voir dans la description des
                 *		   attributs de la classe plus bas
                 */
        std::string getBridgeActuel(void) const;

        /*	void setBridgeActuel(string bridge)
                 *
                 *	permet de définir le bridge Actuel de la machine
                 *
                 *	ARGS
                 *	-bridge
                 *		nom du bridge actuel a associer a l'entitee
                 *
                 *	NOTE
                 *	Mais dis moi Jammie, c'est quoi un bridge Actuel?
                 *		   vas voir dans la description des
                 *		   attributs de la classe plus bas
                 */
        void setBridgeActuel(std::string bridge);

        /*	bool getEtatEntitee()
                 *
                 *	permet d'obtenir l'etat de la machine
                 *
                 *	RETURN VALUE
                 *	elle retourne un booleen : true si la
                 *	machine est allumée et false sinon.
                 *
                 *	NOTE
                 *	cette methode est applicable sur n'importe
                 *	quel entitee, cad Machine, Passerelle ou Hub
                 */
        bool getEtatEntitee(void);

        /*	void setEtatEntitee(bool etat)
                 *
                 *	permet de modifier l'etat de la machine
                 *
                 *	ARGS
                 *	-etat:
                 *		booleen: true si vous avez
                 *		allumé la machine, false si
                 *		vous l'avez eteinte
                 *
                 *	NOTE
                 *	cette methode est applicable sur n'importe
                 *	quel entitee, cad Machine, Passerelle ou Hub
                 */
        void setEtatEntitee(bool etat);

        /*	int getType()
                 *
                 *	permet de connaitre le type de l'entitee
                 *
                 *	RETURN VALUE
                 *	retourne un entier representant le type; se réferer
                 *	au fichier Constantes.h -> TYPE_****
                 */
        int getType(void);

        /*	vector<Cable*> getCables()
                 *
                 *	permet de recuperer les cables auxquels est
                 *	connecté l'entitée
                 *
                 *	RETURN VALUE
                 *	renvoie un "vector" (=tableau plus ou moins)
                 *	d'adresses de Cables dans lequel tous les
                 *	cables auquels l'entitee est relié sont repertoriés
                 */
        std::vector<Cable*> getCables(void);

        /*	void addCable(Cable* cable)
                 *
                 *	permet d'ajouter un cable a la liste des cables
                 *	de l'entitée
                 *
                 *	ARGS
                 *	-cable:
                 *		adresse du cable a ajouter
                 *
                 *	NOTE
                 *	ne pas créer le cable a ajouter dans un une
                 *	structure conditionnelle ou une boucle, sinon
                 *	le cable disparaitra *POOF*
                 *
                 */
        void addCable(Cable *cable);

        /*	void setConnexion(bool con)
                 *
                 *	permet de dire si la machine est connectée a un bridge
                 *	ou non
                 *
                 *	ARGS
                 *	-con
                 *		true si la machine a été connecté a un
                 *		bridge, false elle en a été déconnectée
                 */
        void setConnexion(bool con);

        /*	bool getConnexion() const
                 *
                 *	permet de savoir si la machine est connectée a un bridge
                 *
                 *	RETURN VALUE
                 *	true si la machine est connectée, false sinon
                 */
        bool getConnexion(void) const;

        void setID(int id);

        int getID(void);

        /*	void appliquerBridgeEntiteeSuivante(string bridge)
                 *
                 *	permet de "contaminer" tous les bridges d'un meme
                 *	sous réseau en leur appliquant a tous le meme bridgeActuel,
                 *	en partant de "this"
                 *
                 *	ex: Soit R un reseau dans lequel, pour chaque machine,
                 *	    bridgeActuel = "brP1".
                 *	    Soit M0 un Ordinateur qui appartient a R.
                 *	    si on lance <M0.appliquerBridgeEntiteeSuivante("brM0")>,
                 *	    alors, tout le réseau va avoir brM0 en bridgeActuel
                 *
                 *	ARGS
                 *	-bridge
                 *		nom du bridge que tout le monde doit adopter
                 */
        void appliquerBridgeEntiteeSuivante(std::string bridge);

        /*	void modifBridgesSousReseau_entiteeLancee()
                 *
                 *	permet de modifier les connexions des machines avec les
                 *	bridges lorsqu'on lance une nouvelle Entitee
                 *	Les bridges s'attribuent comme suit:
                 *
                 *	je regarde les environs (=entitees avec qui je suis connecté)
                 *
                 *	si personne dans les environs
                 *	{
                 *	    je sort, pas de connexions aux bridges necessaires
                 *	}
                 *	si quelqu'un dans les environs
                 *	{
                 *	    je regarde son type
                 *
                 *	    si il est superieur a nous
                 *	    {
                 *	        si il est deja connecté a un bridge
                 *	        {
                 *	            je prend son bridge actuel
                 *	        }
                 *	        si il n'est pas connecté a un bridge
                 *	        {
                 *	            je prend son bridgeInit, je le
                 *	            fait prendre son bridgeInit
                 *	            je le dis au'il est connecté
                 *	        }
                 *	        je dis que je suis connecté
                 *	    }
                 *	    si il est inferieur a nous
                 *	    {
                 *	        je le fait prendre lui et tout son
                 *	        sous-reseau mon bridgeInit
                 *	        je prend mon bridgeInit, et je dit que je suis connecté
                 *	    }
                 *
                 *	    je fait prendre a toutes mes connexions mon nouveau bridge
                 *	}
                 *
                 */
        void modifBridgesSousReseau_entiteeLancee();

        bool verifAlone(Entitee* source);

        /*	void modifBridgesSousReseau_entiteeStoppee()
                 *
                 *	permet de modifier les connexions des machines avec les
                 *	bridges lorsqu'on stoppe une Entitee
                 */
        void modifBridgesSousReseau_entiteeStoppee();

        /*	void launchEntitee()
                 *
                 *	permet de lancer une Entitee, et d'executer toutes les
                 *	opérations annexes a ce lancement
                 */
        void launchEntitee();

        /*	void stopEntitee()
                 *
                 *	permet de stopper une Entitee, et d'executer toutes les
                 *	opérations annexes a cet arret
                 */
        void stopEntitee();

        /*	Methodes virtuelles pures
                 *
                 *	ces methodes sont décrites dans la classe Machine. Les declarer
                 *	ici en tant que methodes virtuelles pures evite les transtypages
                 *	du type < ((Machine*)this)->lancerContainer() >
                 */
        std::string getNom();
        void setNom(std::string nom);

        virtual std::vector<struct paramIp*> getIpConfig() = 0 ;
        virtual void lireModifContainer() = 0;
        virtual void appliquerParamIp() = 0;
        virtual void appliquerParamRoutage4() = 0;
        virtual void appliquerParamRoutage6() = 0;
        virtual int lancerContainer() = 0;
        virtual void stopperContainer() = 0;
        virtual void lierABridge() = 0;
        virtual void separerDeBridge() = 0;
        virtual void majIpContainer() = 0;
        virtual void majRouteContainer() = 0;
        void setVue(VueEntitee* v);
        VueEntitee* getVue();

        virtual ~Entitee() {};
protected:
        /*	m_bridgeInit
                 *
                 *	chaine de caractere representant le bridge Initial de l'entitee
                 *	c'est le bridge que son reseau va adopter si elle est de
                 *	priorité superieur a son entourage. Il est initialisé lors de
                 *	la création de l'entitee, et ne peut pas etre changé. il est
                 *	unique a chaque entitee, les Ordinateurs n'ont pas de bridge
                 *	Initial (il est a "\0"), car il est inutil de créer un bridge
                 *	si une machine n'est connecté a personnem et, si elle est
                 *	connectée a quelqu'un, alors, elle prend le bridgeInit de
                 *	cette Entitee.
                 *
                 *	NOTE
                 *	voir la methode modifBridgesSousReseau_entiteeLancee, et
                 *	les parametre m_bridgeInit et m_bridgeActuel pour mieux
                 *	comprendre le mecanisme
                 */
        std::string m_bridgeInit;

        /*	m_bridgeActuel
                 *
                 *	chaine de caractere representant le bridge auquel l'entitee
                 *	est connécté, si elle est allumée (le dernier bridge auquel
                 *	elle s'est connectée sinon). lors de l'allumage de la machine,
                 *	soit l'entitee est l'entitee de plus grande prioritée parmis
                 *	son entourage, et donc, elle et tout les sous réseaux qu'elle
                 *	touche adoptent son bridge Initial, ou, il y a une Entitee
                 *	de prioritée superieur dans son entourage, auquel cas,
                 *	elle et tous les sous reseaux qu'elle touche prennent le
                 *	bridge actuel de l'entitee de plus haute prioritée.
                 *
                 *	NOTE
                 *	voir la methode modifBridgesSousReseau_entiteeLancee, et
                 *	les parametre m_bridgeInit et m_bridgeActuel pour mieux
                 *	comprendre le mecanisme
                 */
        std::string m_bridgeActuel;

        bool m_estConnecteAuBridge;

        /*	m_running
                 *
                 *	variable representant l'etat de l'entitée
                 *	elle vaut true si la machine est allumée et
                 *	false sinon
                 */
        bool m_running;

        /*	m_cableList
                 *
                 *	liste de Cables auquel l'entitee est reliée
                 *	ATTENTION, rien au niveau du code n'empeche
                 *	de mettre 2 cables sur une machine,
                 *	IL NE FAUT PAS LE FAIRE, sinon ca va tout casser
                 *	au demarage de la machine... TOUT CASSER!!!
                 */
        std::vector<Cable*> m_cableList;

        int m_type;
        int m_id;

        std::string m_nom;

        VueEntitee* m_vue;
};

#endif
