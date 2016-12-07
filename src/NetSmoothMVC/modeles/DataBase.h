#ifndef DATABASE_DEF
#define DATABASE_DEF

#include "Machine.h"
#include "Passerelle.h"
#include "Hub.h"
#include "Entitee.h"
#include "ElementListeChainee.h"
#include "Ordinateur.h"

class DataBase
{

	public:

    static Ordinateur* getNewOrdinateur(void);
    static Passerelle* getNewPasserelle(void);
    static Hub* getNewHub(void);
    static void detruireOrdinateur(Ordinateur* ordi);
    static void detruirePasserelle(Passerelle* passerelle);
    static void detruireHub(Hub* hub);

	private:
    static int m_nbreOrdinateur;
    static int m_nbrePasserelle;
    static int m_nbreHub;
    static ElementListeChainee* m_premierHub;
    static ElementListeChainee* m_premierOrdinateur;
    static ElementListeChainee* m_premierePasserelle;
};

#endif
