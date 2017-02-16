#include "vuecable.h"
#include "modeles/DataBase.h"
#include "vues/vueprincipale.h"
#include <qpainter.h>

VueEntitee* VueCable::PremiereSelection = NULL;
VueEntitee* VueCable::SecondeSelection = NULL;

VueCable::VueCable(VueEntitee* v1, VueEntitee* v2, QGraphicsItem* parent)
        : QGraphicsPathItem(parent),m_v1(v1),m_v2(v2)
{
        this->cable = Cable::creerCable(v1->getModele(),v2->getModele());
        this->cable->setVue(this);

        this->setFlag(QGraphicsItem::ItemIsFocusable,true);
        this->setFlag(QGraphicsItem::ItemIsSelectable,true);

        /**********TRANSPARENCE****************/
    /*
        this->setAttribute( Qt::WA_TranslucentBackground);
        this->setWindowFlags (Qt::FramelessWindowHint);
        this->setAutoFillBackground(false);
        */
        /**************************************/
}

bool VueCable::isSeq(int xinit, int yinit, double coef, int x1, int y1, int x2, int y2)
{
    if(x1==x2)
    {
        y1=yinit-y1;
        y2=yinit-y2;
        float res1=((y1))/coef;
        float res2=((y2))/coef;
        x1-=xinit;
        //cout << "res1 = " << res1 << " ; res2 = " << res2 << " ; y1 = " << y1 << " ; y2 = " << y2 << " ; yinit = " << yinit << " ; x = " << x1 << endl;
        if((x1>=res1 && x1<=res2) || (x1>=res2 && x1<=res1))
            return true;
    }
    else if(y1==y2)
    {
            x1-=xinit;
            x2-=xinit;
        float res1=coef*x1;
        float res2=coef*x2;
        y1=yinit-y1;
        //cout << "res1 = " << res1 << " ; res2 = " << res2 << " ; x1 = " << x1 << " ; x2 = " << x2 << " ; xinit = " << xinit << " ; y = " << y1 << endl;
        if((y1>=res1 && y1<=res2) || (y1>=res2 && y1<=res1))
            return true;
    }
    return false;
}

void VueCable::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{

        QPen pen(Qt::black, 2, Qt::SolidLine);
        painter->setPen(pen);
        VuePrincipale* vp = VuePrincipale::getInstanceOf();

        int unitx = vp->getScene()->width()/NB_CASE_X;
        int unity = vp->getScene()->height()/NB_CASE_Y;

        int x=m_v1->getColGrille()+2, y=m_v1->getLigneGrille()+2;
        int goalx=m_v2->getColGrille()+2, goaly=m_v2->getLigneGrille()+2;

        int i=1, j=1, gx=x, gy=y;
        if(goalx<x)
        {
            gx=goalx;
            gy=goaly;
            i=-1;
        }
        if(goaly<y)
            j=-1;

        float rapport;
        if(x!=goalx)
                rapport=((y-goaly)*1.0)/((x-goalx)*1.0);
        rapport*=-1;


        bool bi=(rapport>1)?true:(rapport<-1)?true:false, goalReached=false;
        int k=0;
        bool force=false;
        while(!goalReached)
        {
                if(force || bi && ((y<goaly && j>0) || (y>goaly && j<0)))    //horizontal
                {
                    painter->drawLine(x*unitx, y*unity, x*unitx, (y+j)*unity);
                    if(k==0 || this->isSeq(gx, gy, rapport, x, y, x, y+j))
                        bi=!bi;
                    y+=j;
                    force=false;
                }
                else if((x<goalx && i>0) || (x>goalx && i<0))   //vertical
                {
                    painter->drawLine(x*unitx, y*unity, (x+i)*unitx, y*unity);
                    if(k==0 || this->isSeq(gx, gy, rapport, x, y, x+i, y))
                        bi=!bi;
                    x+=i;
                }
                else
                    force=true;
                k++;

                if(x==goalx && y==goaly)
                    goalReached=true;

        }
        /*
        int x1,y1;  //représente les coordonnées dans le widget de la première vue
        int x2,y2; //de la deuxième vue
        int width,height;
        int tailleEntitee = 250;//this->m_v1->height();
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
        */
}

void VueCable::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
        cout << "clickCable" << endl;
        QGraphicsItem::mousePressEvent(e);
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
                VueCable* vc = new VueCable(VueCable::getPremiereSelection(),v);
                //        VueCableControleur *c = new VueCableControleur(vueCable);
                vue->getScene()->addItem(vc);
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
