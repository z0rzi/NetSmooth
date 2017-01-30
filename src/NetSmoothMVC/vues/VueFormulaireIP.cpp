#include "VueFormulaireIP.h"

VueFormulaireIP::VueFormulaireIP(int numInterface, Entitee* modele, QWidget *parent)
        : m_modele(modele),m_numInterface(numInterface),QWidget(parent)
{

    QLabel* labelIpv4 = new QLabel("ipv4 :");
    QLabel* labelIpv6 = new QLabel("ipv6 :");
    QLabel* labelMask = new QLabel("Masque ipv4 :");
    QPushButton* valider = new QPushButton("valider");

    this->m_nomInterface = new QLabel();
    this->m_ipv4 = new QTextEdit();
    this->m_mask = new QTextEdit();
    this->m_ipv6 = new QTextEdit();
    this->m_layout = new QGridLayout();

    this->m_ipv4->setFixedHeight(25);
    this->m_mask->setFixedHeight(25);
    this->m_ipv6->setFixedHeight(25);

    this->m_layout->addWidget(labelIpv4,0,0);
    this->m_layout->addWidget(this->m_ipv4,0,1);
    this->m_layout->addWidget(labelMask,1,0);
    this->m_layout->addWidget(this->m_mask,1,1);
    this->m_layout->addWidget(labelIpv6,2,0);
    this->m_layout->addWidget(this->m_ipv6,2,1);
    this->m_layout->addWidget(valider,3,2);

    this->setLayout(this->m_layout);

    VueFormulaireIPControleur* cntrl = new VueFormulaireIPControleur(this,valider);
}

void VueFormulaireIP::setModele(Entitee* e)
{
    this->m_modele = e;
}

void VueFormulaireIP::refresh()
{
    if(this->m_modele == NULL || this->m_numInterface > this->m_modele->getIpConfig().size())
        perror("VueFormulaireIP refresh");
    else
    {
        struct paramIp* ip = this->m_modele->getIpConfig()[this->m_numInterface];

        this->m_nomInterface->setText(QString::fromStdString(ip->interface));
        this->m_ipv4->setText(QString::fromStdString(ip->ipv4));
        this->m_mask->setText(QString::fromStdString(ip->maskv4));
        this->m_ipv6->setText(QString::fromStdString(ip->ipv6));
    }
}

void VueFormulaireIP::appliquerModification()
{

    if(this->m_modele == NULL || this->m_numInterface > this->m_modele->getIpConfig().size())
        perror("VueFormulaireIP appliquerModification");
    else
    {
        struct paramIp* ip = this->m_modele->getIpConfig()[this->m_numInterface];

        ip->ipv4 = this->m_ipv4->toPlainText().toStdString();
        ip->maskv4 = this->m_mask->toPlainText().toStdString();
        ip->ipv6 = this->m_ipv6->toPlainText().toStdString();

        this->m_modele->appliquerParamIp();

    }

}
