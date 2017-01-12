#include "vuecable.h"
#include "modeles/DataBase.h"
#include "vues/vueprincipale.h"
#include <qpainter.h>

VueEntitee* VueCable::PremiereSelection = NULL;
VueEntitee* VueCable::SecondeSelection = NULL;

VueCable::VueCable(VueEntitee* v1, VueEntitee* v2,QWidget *parent)
        : QWidget(parent),m_v1(v1),m_v2(v2)
{
        this->cable = Cable::creerCable(v1->getModele(),v2->getModele());

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
        int x1,y1;  //représente les coordonnées dans le widget de la première vue
        int x2,y2; //de la deuxième vue
        int width,height;
        int tailleEntitee = this->m_v1->height();
        VueEntitee *haut, *bas, *droite, *gauche;

        if(this->m_v1->pos().x() > this->m_v2->pos().x())
        {
            gauche=this->m_v2;
            droite=this->m_v1;
        }
        else
        {
            gauche=this->m_v1;
            droite=this->m_v2;
        }
        if(this->m_v1->pos().y() > this->m_v2->pos().y())
        {
            haut=this->m_v2;
            bas=this->m_v1;
        }
        else
        {
            haut=this->m_v1;
            bas=this->m_v2;
        }

        if(gauche==haut)
        {
            x1=y1=tailleEntitee/2;
            x2=droite->pos().x()-gauche->pos().x()+tailleEntitee/2;
            y2=bas->pos().y()-haut->pos().y()+tailleEntitee/2;
        }
        else
        {
                y1=bas->pos().y()-haut->pos().y()+tailleEntitee/2;
                x1=tailleEntitee/2;
                x2=droite->pos().x()-gauche->pos().x()+tailleEntitee/2;
                y2=tailleEntitee/2;
        }
        height = bas->pos().y()-haut->pos().y()+tailleEntitee;
        width = droite->pos().x()-gauche->pos().x()+tailleEntitee;

        painter.drawLine(x1,y1,x2,y2);
        this->setGeometry(gauche->pos().x(),haut->pos().y(),width,height);

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
                QGraphicsProxyWidget* proxy = vue->getScene()->addWidget(vueCable);
                vue->getView()->setScene(vue->getScene());
                vue->getView()->show();

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
