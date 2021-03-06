#ifndef HUB_DEF
#define HUB_DEF

#include <iostream>
#include <vector>

#include "Entitee.h"

class DataBase;

class Hub : public Entitee
{
    public:
        /*	Hub()
         *
         *	constructeur de la classe, il appelle le constructeur
         *	de son parent
         */
        Hub(int id);
        ~Hub();

        /*	Methodes inutiles
         *
         *	ces methodes ne sont redéfinies ici que pour respecter
         *	les methodes virtuelles pures du parent, mais elles
         *	ne sont pas utiles ici (elles le sont dans l'autre
         *	enfant en revanche: Machine)
         *
         */
        std::vector<struct paramIp*> getIpConfig();
        void appliquerParamIp();
        void appliquerParamRoutage4();
        void appliquerParamRoutage6();
        int lancerContainer();
        void lierABridge();
        void separerDeBridge();
        void stopperContainer();
        void lireModifContainer();
        void majIpContainer();
        void majRouteContainer();
        void setIpConfig(struct paramIp* ip);

    private:
        /* 	numHub
         *
         * 	numero de Hub, s'incremente a chaque hub créé
         * 	il sert nottament a nommer les bridge
         */
};

#endif

