#include <QWidget>
#include <QGridLayout>
#include <QToolBar>
#include <QMenu>

#include "vues/selection.h"
#include "vues/vueprincipale.h"
#include "vues/vueinformation.h"
#include "controleurs/vueinformationcontroleur.h"
#include "vues/fenetre.h"

Fenetre::Fenetre(QWidget *parent) : QMainWindow(parent)
{
    QWidget *w = new QWidget();
    QToolBar* tb = new QToolBar();
    QAction* afichier = new QAction(NULL);
    QMenu* mfichier = new QMenu();
    QAction* aopt = new QAction(NULL);
    QMenu* mopt = new QMenu();
    Selection *s = new Selection();
    VuePrincipale *vp = new VuePrincipale();
    QGridLayout *g = new QGridLayout();
    VueInformation *vi= VueInformation::getInstanceOf();
    VueInformationControleur *vic = new VueInformationControleur(vi);

    g->addWidget(s,0,0,0);
    g->addWidget(vp,0,1,0);
    g->addWidget(vi,0,2,0);
    w->setLayout(g);
    mopt->addAction("Preferences...");
    aopt->setMenu(mopt);
    aopt->setText("Options");
    mfichier->addAction("Sauvegarder",this,SLOT(save()));
    mfichier->addAction("Charger",this,SLOT(load()));
    mfichier->addAction("Quitter",this,SLOT(quit()));
    afichier->setText("Fichier");
    afichier->setMenu(mfichier);
    tb->addAction(afichier);
    tb->addAction(aopt);
    this->setCentralWidget(w);
    this->addToolBar(tb);
}

void Fenetre::save()
{
   Save::save_session("bobo");
}

void Fenetre::load()
{
   Save::load_session("bobo");
}

void Fenetre::quit()
{
   exit(0);
}
