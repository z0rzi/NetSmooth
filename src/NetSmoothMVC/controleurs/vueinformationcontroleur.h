#ifndef VUEINFORMATIONCONTROLEUR_H
#define VUEINFORMATIONCONTROLEUR_H

#include <QObject>
#include <iostream>
#include "vues/vueentitee.h"
#include "vues/constantes.h"
#include "modeles/Entitee.h"
#include "modeles/Machine.h"
#include "vues/selection.h"

using namespace std;

class VueInformation;

#include "vues/vueinformation.h"

class VueInformationControleur : public QObject
{
    Q_OBJECT
public:
    explicit VueInformationControleur(VueInformation* vue, QObject *parent = 0);
    void ajoutLigne4(const char* interface, const char* destination, const char* passerelle);
    void ajoutLigne6(const char* interface, const char* destination, const char* passerelle);
    void viderLigne4();
    void ajoutLigneVide4();

private:
    VueInformation* vue;

signals:

public slots:
    void ajoutLigne4();
    void ajoutLigne6();
    void refreshVue();
    void allumer();
};

#endif // VUEINFORMATIONCONTROLEUR_H
