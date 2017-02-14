#include <QWidget>
#include <QGridLayout>
#include <QToolBar>
#include <QMenu>
#include <QFileDialog>

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
    VuePrincipale *vp = VuePrincipale::getInstanceOf();
    QGridLayout *g = new QGridLayout();
    VueInformation *vi= VueInformation::getInstanceOf();

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
        QFileDialog* fl = new QFileDialog();
        fl->setDefaultSuffix(*(new QString("ns")));
        fl->setDirectory(*(new QString("../saves")));
        fl->setViewMode(QFileDialog::List);
        fl->setAcceptMode(QFileDialog::AcceptSave);
        QString bob = fl->getSaveFileName();
        Save::save_session(bob.toStdString());
}

void Fenetre::load()
{
        QFileDialog* fl = new QFileDialog();
        fl->setDirectory(*(new QString("../saves")));
        fl->setViewMode(QFileDialog::List);
        fl->setAcceptMode(QFileDialog::AcceptOpen);
        QString bob = fl->getOpenFileName();
        Save::load_session(bob.toStdString());
}

void Fenetre::quit()
{
        exit(0);
}
