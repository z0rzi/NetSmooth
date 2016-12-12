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
    int x1,y1,  //représente les coordonnées dans le widget de la première vue
                    x2,y2, //de la deuxième vue
                    width,height,
                    hautGaucheX, hautGaucheY;//Pour setGeometry (haut gauche du rectangle)


    if(this->m_v1->pos().x() > this->m_v2->pos().x())
    {
        x1 =  this->m_v1->pos().x()-this->m_v2->pos().x();
        x2 = 0;
        width = x1;
        hautGaucheX = this->m_v2->pos().x();

        if(this->m_v1->pos().y() > this->m_v2->pos().y())
        {
            y1 = this->m_v1->pos().y()-this->m_v2->pos().y();
            y2 = 0;
            height = y1;
            hautGaucheY = this->m_v2->pos().y();
        }
        else if(this->m_v1->pos().y() < this->m_v2->pos().y())
        {
            y1 = 0;
            y2 = this->m_v2->pos().y()-this->m_v1->pos().y();
            height = y2;
            hautGaucheY = this->m_v1->pos().y();

        }
        else//m_v1y==m_v2y
        {
            y1=0;
            y2=0;
            height = 5; // epaisseur du trait
            hautGaucheY = this->m_v2->pos().y();
        }
    }
    else if(this->m_v1->pos().x() < this->m_v2->pos().x())
    {
        x1 = 0;
        x2 = this->m_v2->pos().x()-this->m_v1->pos().x();
        width = x2;
        hautGaucheX = this->m_v1->pos().x();

        if(this->m_v1->pos().y() > this->m_v2->pos().y())
        {
            y1 = this->m_v1->pos().y()-this->m_v2->pos().y();
            y2 = 0;
            height = y1;
            hautGaucheY = this->m_v2->pos().y();
        }
        else if(this->m_v1->pos().y() < this->m_v2->pos().y())
        {
            y1 = 0;
            y2 = this->m_v2->pos().y()-this->m_v1->pos().y();
            height = y2;
            hautGaucheY = this->m_v1->pos().y();
        }
        else
        {
            y1=0;
            y2=0;
            height = 5; // epaisseur du trait
            hautGaucheY = this->m_v1->pos().y();
        }
    }
    else
    {
        x1=0;
        x2=0;
        width = 5; //epaisseur du trait
        hautGaucheX=this->m_v1->pos().x();

        if(this->m_v1->pos().y() > this->m_v2->pos().y())
        {
            y1 = this->m_v1->pos().y()-this->m_v2->pos().y();
            y2 = 0;
            height = y1;
            hautGaucheY = this -> m_v2->pos().y();
        }
        else if(this->m_v1->pos().y() < this->m_v2->pos().y())
        {
            y1 = 0;
            y2 = this->m_v2->pos().y()-this->m_v1->pos().y();
            height = y2;
            hautGaucheY = this -> m_v1->pos().y();
        }
        else //si les deux vues sont confondues
        {
            return;
        }
    }

    painter.drawLine(x1,y1,x2,y2);
    this->setGeometry(hautGaucheX,hautGaucheY,width,height);
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
