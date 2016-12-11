#include "vuecable.h"
#include "modeles/DataBase.h"
#include "vues/vueprincipale.h"
#include <qpainter.h>

VueEntitee* VueCable::PremiereSelection = NULL;
VueEntitee* VueCable::SecondeSelection = NULL;

VueCable::VueCable(VueEntitee* v1, VueEntitee* v2,QWidget *parent)
        : QWidget(parent),m_v1(v1),m_v2(v2)
{
    this->cable = Cable::creerCable(v1->getModele(),v2->getModele());//à faire

    /**********TRANSPARENCE****************/
    this->setAttribute( Qt::WA_TranslucentBackground);
    this->setWindowFlags (Qt::FramelessWindowHint);
    this->setAutoFillBackground(false);
    /**************************************/
}

void VueCable::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QPen myPen(Qt::black, 2, Qt::SolidLine);
    painter.setPen(myPen);
    painter.drawLine(this->m_v1->pos(),this->m_v2->pos());
    this->setGeometry(this->m_v1->pos().x(),this->m_v1->pos().y(),this->m_v2->pos().x(),this->m_v2->pos().y());
}

Cable* VueCable::getModele()
{
    return this->cable;
}

void VueCable::creerVueCable(VueEntitee *v)
{
    if(VueCable::getPremiereSelection()==NULL)
        VueCable::setPremiereSelection(v);
    else
    {
        VuePrincipale* vue = (VuePrincipale*) VuePrincipale::getwidget();
        VueCable* vueCable = new VueCable(VueCable::getPremiereSelection(),v);
        //        VueCableControleur *c = new VueCableControleur(vueCable);
        QGraphicsProxyWidget* proxy = vue->scene->addWidget(vueCable);
        vue->view->setScene(vue->scene);
        vue->view->show();

        VueCable::setPremiereSelection(NULL);
        Selection::setEnSelection(SOURIS);
    }
}

VueEntitee* VueCable::getPremiereSelection()
{
    return VueCable::PremiereSelection;
}

VueEntitee* VueCable::getSecondeSelection()
{
    return VueCable::SecondeSelection;
}

void VueCable::setPremiereSelection(VueEntitee *v)
{
    VueCable::PremiereSelection = v;
}

void VueCable::setSecondeSelection(VueEntitee *v)
{
    VueCable::SecondeSelection = v;
}
