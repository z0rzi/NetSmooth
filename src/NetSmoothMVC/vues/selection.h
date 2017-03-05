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
    QPushButton* getSupprimer();

private:
    void setButtonStyle(QPushButton* b, std::string imgPath);
    static int m_enSelection;
    QPushButton *m_souris;
    QPushButton *m_machine;
    QPushButton *m_passerelle;
    QPushButton *m_hub;
    QPushButton *m_cable;
    QPushButton *m_supprimer;
    SelectionControleur *m_sc;
};

#endif // SELECTION_H
