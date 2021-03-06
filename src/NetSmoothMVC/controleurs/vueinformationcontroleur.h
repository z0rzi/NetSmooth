#ifndef VUEINFORMATIONCONTROLEUR_H
#define VUEINFORMATIONCONTROLEUR_H

#include <QObject>
#include <iostream>
#include "vues/vueentitee.h"
#include "vues/constantes.h"
#include "modeles/Entitee.h"
#include "modeles/Machine.h"
#include "vues/selection.h"
#include "modeles/Save.h"

using namespace std;

#include "vues/vueinformation.h"

class VueInformationControleur : public QObject
{
    Q_OBJECT
public:
    explicit VueInformationControleur(VueInformation* vue, QPushButton* all, QPushButton* rafr, QPushButton* name, QObject *parent = 0);

private:
    VueInformation* vue;

signals:

public slots:
    void actionClickAllumer();
    void rafraichir();
    void rename();
};

#endif // VUEINFORMATIONCONTROLEUR_H
