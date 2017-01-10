#ifndef SELECTION_H
#define SELECTION_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class SelectionControleur;

#include "controleurs/selectioncontroleur.h"
#include "vues/constantes.h"


class Selection : public QWidget
{
    Q_OBJECT
public:
    explicit Selection(QWidget *parent = 0);
    static int getEnSelection();
    static void setEnSelection(int es);
    QPushButton* getSouris();
    QPushButton* getMachine();
    QPushButton* getPasserelle();
    QPushButton* getHub();
    QPushButton* getCable();

private:
    static int enSelection;
    QPushButton *souris;
    QPushButton *machine;
    QPushButton *passerelle;
    QPushButton *hub;
    QPushButton *cable;
    SelectionControleur *sc;
};

#endif // SELECTION_H
