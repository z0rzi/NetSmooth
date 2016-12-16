#include "vueinformationcontroleur.h"

VueInformationControleur::VueInformationControleur(VueInformation* vue0, QObject *parent) : QObject(parent)
{
    vue = vue0;
    connect(this->vue->getLastV4()->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne4()));
    connect(this->vue->getLastV6()->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne6()));
    connect(this->vue,SIGNAL(refresh()),this,SLOT(refreshVue()));
}

void VueInformationControleur::ajoutLigne4()
{
    VueEntitee* vueSource = (VueEntitee*)vue->getSource();
    if (vueSource != NULL)
    {
        if(vueSource->getModele()->getType() != TYPE_HUB)
        {
            QPushButton* b = qobject_cast<QPushButton*>(sender());
            if(b->text() == "OK")
            {
                int n;
                vue->getLastV4()->bloquer();
                Machine* source = (Machine*)vueSource->getModele();
                struct paramRoutage route = {vue->getLastV4()->getEinter()->toPlainText().toStdString(),
                                    vue->getLastV4()->getEdest()->toPlainText().toStdString(),
                                    vue->getLastV4()->getEpass()->toPlainText().toStdString()};
                source->addRouteConfig(route);
                source->appliquerParamRoutage();
                LigneRoute* newLigne = new LigneRoute();
                QGridLayout* layout = new QGridLayout();
                layout = vue->getLayoutRoute4();
                n = vue->getNbr4()+1;
                vue->getLastV4()->getValider()->setText("X");
                layout->addWidget(newLigne,n,0,1,3);
                vue->setNbr4(vue->getNbr4()+1);
                connect(newLigne->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne4()));
                vue->setlastV4(newLigne);
            }
            else if(b->text() == "X")
            {
                b->parentWidget()->deleteLater();
                vue->setNbr4(vue->getNbr4()-1);
            }
        }
    }
}

void VueInformationControleur::ajoutLigneVide4()
{
    int n;
    LigneRoute* newLigne = new LigneRoute();
    QGridLayout* layout;
    layout = vue->getLayoutRoute4();
    n = vue->getNbr4();
    layout->addWidget(newLigne,n,0,1,3);
    connect(newLigne->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne4()));
    vue->setlastV4(newLigne);
}

void VueInformationControleur::ajoutLigne4(const char* interface, const char* destination, const char* passerelle)
{
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
    connect(newLigne->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne4()));
    LigneRoute* vide = new LigneRoute();
    layout->addWidget(vide,vue->getNbr4(),0,1,3);
    vue->setlastV4(vide);
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
        vector<struct paramRoutage> routeConf = o->getRouteConfig();
        /**********ROUTE***************/
        this->viderLigne4();
        this->ajoutLigneVide4();
        if(!routeConf.empty())
        {
            for(i=0;i<routeConf.size();i++)
            {
                const char* interface = routeConf[i].interface.c_str();
                const char* destination = routeConf[i].destination.c_str();
                const char* passerelle = routeConf[i].passerelle.c_str();
                this->ajoutLigne4(interface,destination,passerelle);
            }
        }

    }
}

void VueInformationControleur::viderLigne4()
{
    int i;
    QGridLayout* lr = vue->getLayoutRoute4();
    cout << "nbr4 : " << vue->getNbr4() << endl;
    for(i=1;i<=vue->getNbr4();i++)
    {
        lr->itemAtPosition(i,0)->widget()->deleteLater();
    }
    vue->setNbr4(1);
}
