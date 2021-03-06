#ifndef VUEIP_H
#define VUEIP_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTextEdit>
#include <QLabel>
#include <QLayout>
#include <QTabWidget>

#include "modeles/Entitee.h"
#include "vues/vueentitee.h"
#include "vues/VueFormulaireIP.h"

class VueIPControleur;

class VueIP : public QWidget
{
    Q_OBJECT
public:
    explicit VueIP(QWidget *parent=0);
    void refresh();
    void setSource(Entitee* e);
    std::vector<VueFormulaireIP*> getFormulairesIP();
void clearLayout(QLayout *layout);

private:
    std::vector<VueFormulaireIP*> m_formulairesIP;
    QGridLayout* m_layout;
    VueIPControleur* controleur = NULL;


signals:


public slots:
};

#endif
