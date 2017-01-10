#include "VueFormulaireIP.h"

VueFormulaireIP::VueFormulaireIP(int numInterface, Entitee* modele, QWidget *parent)
        : m_modele(modele),m_numInterface(numInterface),QGridLayout(parent)
{

    QLabel* labelIpv4 = new QLabel("ipv4 :");
    QLabel* labelIpv6 = new QLabel("ipv6 :");
    QLabel* labelMask = new QLabel("Masque ipv4 :");

    this->m_nomInterface = new QLabel();
    this->m_ipv4 = new QTextEdit();
    this->m_mask = new QTextEdit();
    this->m_ipv6 = new QTextEdit();

    this->m_ipv4->setFixedHeight(25);
    this->m_mask->setFixedHeight(25);
    this->m_ipv6->setFixedHeight(25);

    this->addWidget(labelIpv4,0,0);
    this->addWidget(this->m_ipv4,0,1);
    this->addWidget(labelMask,1,0);
    this->addWidget(this->m_mask,1,1);
    this->addWidget(labelIpv6,2,0);
    this->addWidget(this->m_ipv6,2,1);

    this->appliquerModification();
    this->refresh();
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
        ip->ipv4  = "salut!";
    }

}
