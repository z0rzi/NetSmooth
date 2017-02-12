#ifndef VUEFORMULAIREIP_H
#define VUEFORMULAIREIP_H

#include <iostream>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QTextEdit>
#include <QGridLayout>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include "modeles/Entitee.h"
#include "controleurs/VueFormulaireIPControleur.h"

class VueFormulaireIP : public QWidget
{

    Q_OBJECT
public:
    explicit VueFormulaireIP(int numInterface, Entitee* modele,QWidget *parent = 0);

    void setModele(Entitee* e);
    Entitee* getModele();

    void refresh();
    void appliquerModification();

private:

    int m_numInterface;
    Entitee* m_modele;
    QLabel* m_nomInterface;
    QTextEdit* m_ipv4;
    QTextEdit* m_ipv6;
    QTextEdit* m_mask;
    QGridLayout* m_layout;

signals:

public slots:
};

#endif
