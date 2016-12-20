#include "vueinformationcontroleur.h"

VueInformationControleur::VueInformationControleur(VueInformation* vue0, QObject *parent) : QObject(parent)
{
    vue = vue0;
    //connect(this->vue->getLastV4()->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne4()));
  //  connect(this->vue->getLastV6()->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne6()));
    //connect(this->vue->getRoutes(),SIGNAL(refresh()),this,SLOT(refreshVue()));
    connect(this->vue->getAllumer(),SIGNAL(clicked(bool)),this,SLOT(allumer()));
}

void VueInformationControleur::allumer()
{
    QPixmap* img = new QPixmap();
    VueEntitee* vueE = VueEntitee::getLabelEnSelection();
    if (vueE == NULL)
    {
        cout << "erreur selection" << endl;
        return;
    }
    if(vueE->getModele()->getType()==TYPE_ORDINATEUR)
    {
        if (vueE->etat == false)
        {
            vueE->etat = true;
            struct paramIp ip;
            ip.ipv4=vue->getEipv4()->toPlainText().toStdString();
            ip.maskv4=vue->getEmipv4()->toPlainText().toStdString();
            ip.ipv6=vue->getEipv6()->toPlainText().toStdString();
            ip.interface="eth0";
            Machine* m = (Machine*)vueE->getModele();
            m->addIpConfig(ip);
            vueE->getModele()->launchEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/ordinateuron.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
        else
        {
            vueE->etat = false;
            vueE->getModele()->stopEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/ordinateuroff.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
    }
    else if(vueE->getModele()->getType()==TYPE_PASSERELLE)
    {
        if (vueE->etat == false)
        {
            vueE->etat = true;
            struct paramIp ip;
            ip.ipv4=vue->getEipv4()->toPlainText().toStdString();
            ip.maskv4=vue->getEmipv4()->toPlainText().toStdString();
            ip.ipv6=vue->getEipv6()->toPlainText().toStdString();
            ip.interface="eth0";
            Passerelle* p = (Passerelle*)vueE->getModele();
            p->addIpConfig(ip);
            vueE->getModele()->launchEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/passerelleon.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
        else
        {
            vueE->etat = false;
            vueE->getModele()->stopEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/passerelleoff.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
    }
    else if(vueE->getModele()->getType()==TYPE_HUB)
    {
        if (vueE->etat == false)
        {
            vueE->etat = true;
            Hub* p = (Hub*)vueE->getModele();
            vueE->getModele()->launchEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/Hubon.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
        else
        {
            vueE->etat = false;
            vueE->getModele()->stopEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/Huboff.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
    }
}

/*void VueInformationControleur::ajoutLigne4()
{
    cout << "ajoutLigne4()" <<endl <<endl;
    VueEntitee* vueSource = (VueEntitee*)vue->getSource();
    if (vueSource != NULL)
    {
        if(vueSource->getModele()->getType() != TYPE_HUB)
    {
        Machine* source = (Machine*)vueSource->getModele();
        QPushButton* b = qobject_cast<QPushButton*>(sender());
        cout << "bouton sélectionné :" << b->parentWidget() << endl;
        LigneRoute* parent = (LigneRoute*)b->parentWidget();
        if(b->text() == "OK")
        {
            int n, id;
            id=source->getNewIdRoute();
            struct paramRoutage route = {id,vue->getLastV4()->getEinter()->toPlainText().toStdString(),
                                vue->getLastV4()->getEdest()->toPlainText().toStdString(),
                                vue->getLastV4()->getEpass()->toPlainText().toStdString()};
            vue->getLastV4()->bloquer();
            cout << id <<endl;
            parent->setId(id);
            source->addRouteConfig(route);
            source->appliquerParamRoutage();
            cout << "id2 : " << id << endl;
            LigneRoute* newLigne = new LigneRoute();
            QGridLayout* layout = new QGridLayout();
            layout = vue->getLayoutRoute4();
            n = vue->getNbr4()+1;
            vue->getLastV4()->getValider()->setText("X");
            layout->addWidget(newLigne,n,0,1,3);
            vue->setNbr4(vue->getNbr4()+1);
            connect(newLigne->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne4()));
            vue->setlastV4(newLigne);
            cout << endl;
        }
        else if(b->text() == "X")
        {
            cout << "parentId = " << parent->getId() << endl;
            cout << "nb40 = " << vue->getNbr4() << endl;
            source->removeParamRoute(parent->getId());
            b->parentWidget()->deleteLater();

            cout <<"ligne supprimée" << b->parentWidget() << endl;
            vue->setNbr4(vue->getNbr4()-1);
            cout << "nb41 = " << vue->getNbr4() << endl;

        }
    }
    }
}

void VueInformationControleur::ajoutLigneVide4()
{
    cout << "ajoutLigneVide4" <<endl <<endl;
    int n;
    LigneRoute* newLigne = new LigneRoute();
    QGridLayout* layout;
    layout = vue->getLayoutRoute4();
    n = vue->getNbr4();
    cout << "nbre4 ligne vide : " << n << endl;
    layout->addWidget(newLigne,n,0,1,3);
    connect(newLigne->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne4()));
    vue->setlastV4(newLigne);
}

void VueInformationControleur::ajoutLigne4(const char* interface, const char* destination, const char* passerelle)
{
    cout <<"ajoutLigne4(...)" << endl<< endl;
    int n;
    LigneRoute* newLigne = vue->getLastV4();
    QGridLayout* layout;
    newLigne->getEdest()->setText(destination);
    newLigne->getEpass()->setText(passerelle);
    newLigne->getEinter()->setText(interface);
    layout = vue->getLayoutRoute4();
    vue->getLastV4()->getValider()->setText("X");
    n = vue->getNbr4();
    vue->setNbr4(n+1);
    LigneRoute* vide = new LigneRoute();
    layout->addWidget(vide,vue->getNbr4(),0,1,3);
    vue->setlastV4(vide);
    connect(vide->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne4()));
}

void VueInformationControleur::ajoutLigne6(const char* interface, const char* destination, const char* passerelle)
{
    int n;
    vue->getLastV6()->bloquer();
    LigneRoute* newLigne = new LigneRoute();
    QGridLayout* layout;
    newLigne->getEdest()->setText(destination);
    newLigne->getEpass()->setText(passerelle);
    newLigne->getEinter()->setText(interface);
    layout = vue->getLayoutRoute6();
    n = vue->getNbr6()+1;
    vue->getLastV6()->getValider()->setText("X");
    layout->addWidget(newLigne,n,0,1,3);
    vue->setNbr6(n+1);
    connect(newLigne->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne6()));
    vue->setlastV6(newLigne);
}

void VueInformationControleur::ajoutLigne6()
{
    QPushButton* b = qobject_cast<QPushButton*>(sender());
    if(b->text() == "OK")
    {
        int n;
        vue->getLastV6()->bloquer();
        LigneRoute* newLigne = new LigneRoute();
        QGridLayout* layout = new QGridLayout();
        layout = vue->getLayoutRoute6();
        n = vue->getNbr6()+1;
        vue->getLastV6()->getValider()->setText("X");
        layout->addWidget(newLigne,n,0,1,3);
        vue->setNbr6(n+1);
        connect(newLigne->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne6()));
        vue->setlastV6(newLigne);
    }
    else if(b->text() == "X")
    {
        b->parentWidget()->deleteLater();
        vue->setNbr6(vue->getNbr6()-1);
    }
}

void VueInformationControleur::refreshVue()
{
    int i;
    VueEntitee* s = (VueEntitee*)vue->getSource();
    if(s->getModele()->getType()==TYPE_HUB)
    {
        vue->vider();
    }
    else
    {
        Machine* o = (Machine*)s->getModele();
        vector<struct paramIp> ipConf = o->getIpConfig();
        if(!ipConf.empty())
        {
            const char* c = ipConf[0].ipv4.c_str();
            vue->getEipv4()->setText(c);
            c = ipConf[0].maskv4.c_str();
            vue->getEmipv4()->setText(c);
            c = ipConf[0].ipv6.c_str();
            vue->getEipv6()->setText(c);
        }
        //vector<struct paramRoutage> routeConf = o->getRouteConfig();
        /**********ROUTE***************/
        /*this->viderLigne4();
        this->ajoutLigneVide4();
        if(!routeConf.empty())
        {
            for(i=0;i<routeConf.size();i++)
            {
                cout << "routeConf : " << i << endl;
                const char* interface = routeConf[i].interface.c_str();
                const char* destination = routeConf[i].destination.c_str();
                const char* passerelle = routeConf[i].passerelle.c_str();
                this->ajoutLigne4(interface,destination,passerelle);
            }
        }
        */
        /*this->vue->getRoutes()->refresh();

    }
}

void VueInformationControleur::viderLigne4()
{
    int i;
    QGridLayout* lr = vue->getLayoutRoute4();
    cout << "nbr4 viderligne4: " << vue->getNbr4() << endl;
    for(i=1;i<vue->getNbr4();i++)
    {
        lr->itemAtPosition(i,0)->widget()->deleteLater();
    }
    cout << "fin nbre4"<<endl;
    vue->setNbr4(1);
}
*/
