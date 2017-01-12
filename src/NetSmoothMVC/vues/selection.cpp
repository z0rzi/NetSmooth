#include "selection.h"

Selection::Selection(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(150,500);

    this->setEnSelection(SOURIS);

    this->m_souris = new QPushButton(tr("Souris"),this);
    this->m_machine = new QPushButton(tr("Machine"), this);
    this->m_passerelle = new QPushButton(tr("Passerelle"), this);
    this->m_hub = new QPushButton(tr("Hub"), this);
    this->m_cable = new QPushButton(tr("Cable"), this);
    this->m_sc = new SelectionControleur(this);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_souris,0,0);
    layout->addWidget(m_machine,1,0);
    layout->addWidget(m_passerelle,2,0);
    layout->addWidget(m_hub,3,0);
    layout->addWidget(m_cable,4,0);
    this->setLayout(layout);

}

int Selection::getEnSelection()
{
    return m_enSelection;
}

void Selection::setEnSelection(int es)
{
    m_enSelection = es;
}

QPushButton* Selection::getSouris()
{
    return this->m_souris;
}

QPushButton* Selection::getMachine()
{
    return this->m_machine;
}

QPushButton* Selection::getPasserelle()
{
    return this->m_passerelle;
}

QPushButton* Selection::getHub()
{
    return this->m_hub;
}

QPushButton* Selection::getCable()
{
    return this->m_cable;
}
