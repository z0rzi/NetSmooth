#include "vuecable.h"
#include "modeles/DataBase.h"
#include "vues/vueprincipale.h"
#include <qpainter.h>

VueEntitee* VueCable::PremiereSelection = NULL;
VueEntitee* VueCable::SecondeSelection = NULL;

VueCable::VueCable(VueEntitee* v1, VueEntitee* v2, QGraphicsItem* parent)
        : QGraphicsPathItem(parent),m_v1(v1),m_v2(v2)
{
        this->m_cable = Cable::creerCable(v1->getModele(),v2->getModele());
        this->m_cable->setVue(this);

        this->setFlag(QGraphicsItem::ItemIsFocusable,true);
        this->setFlag(QGraphicsItem::ItemIsSelectable,true);
}

VueCable::~VueCable()
{
    delete(this->m_cable);
}

/*     isSeq(int xinit, int yinit, double coef, int x1, int y1, int x2, int y2)
 *
 *      Permet de determiner si la droite, qui passe par (xinit, yinit) et qui
 *      a pour coefficient directeur coef, coupe le segment x1,y1,x2,y2 ou non.
 */
bool VueCable::isSeq(int xinit, int yinit, double coef, int x1, int y1, int x2, int y2)
{
    if(x1==x2)
    {
        y1=yinit-y1;
        y2=yinit-y2;
        float res1=((y1))/coef;
        float res2=((y2))/coef;
        x1-=xinit;
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
        if((y1>=res1 && y1<=res2) || (y1>=res2 && y1<=res1))
            return true;
    }
    return false;
}


void VueCable::updatePath()
{
        VuePrincipale* vp = VuePrincipale::getInstanceOf();

        /* taille d'une case en pixels: */
        int unitx = vp->getScene()->width()/NB_CASE_X;
        int unity = vp->getScene()->height()/NB_CASE_Y;

        /* x,y = point de depart ; goalx, goaly = point d'arrive */
        int x=m_v1->getColGrille()+2, y=m_v1->getLigneGrille()+2;
        int goalx=m_v2->getColGrille()+2, goaly=m_v2->getLigneGrille()+2;

        QPainterPath* paintpath = new QPainterPath(*(new QPoint(x*unitx, y*unity)));

        int i=1, j=1, gx=x, gy=y;

        if(goalx<x)     /* si il faut aller vers la gauche */
        {
            gx=goalx;
            gy=goaly;
            i=-1;
        }

        if(goaly<y)     /* sil il faut monter */
            j=-1;

        float rapport;
        if(x!=goalx)
                rapport=-1*((y-goaly)*1.0)/((x-goalx)*1.0);     /* coefficient directeur */


        /* direction determine si il faut evoluer en vertical ou en horizontal */
        bool direction=(rapport>1)?true:(rapport<-1)?true:false, goalReached=false;
        int k=0;

        /* force oblige le cable a aller horizontalement (quand y==ygoal) */
        bool force=false;

        while(!goalReached)
        {
                if(force || ( direction && y!=goaly))       //horizontal
                {       /* si c'est son tour, et que il n'est pas au meme niveau que le goal
                         * ex: x=10; goalx=10; on ne peut plus se deplacer horzontalement
                         */

                    paintpath->lineTo(x*unitx, (y+j)*unity);
                    if(k==0 || this->isSeq(gx, gy, rapport, x, y, x, y+j))
                        direction=!direction;
                    y+=j;
                    force=false;
                }
                else if(x!=goalx)                   //vertical
                {       /* si c'est son tour, et que il n'est pas au meme niveau que le goal */

                    paintpath->lineTo((x+i)*unitx, y*unity);
                    if(k==0 || this->isSeq(gx, gy, rapport, x, y, x+i, y))
                        direction=!direction;
                    x+=i;
                }
                else
                    force=true;
                k++;

                if(x==goalx && y==goaly)
                    goalReached=true;
        }

        this->setPath(*paintpath);
}

void VueCable::mousePressEvent(QGraphicsSceneMouseEvent *e)
{

    if(Selection::getEnSelection() == SUPPRIMER)
        emit(this->deleteCableSignal());

        QGraphicsItem::mousePressEvent(e);
}

Cable* VueCable::getModele()
{
        return this->m_cable;
}

void VueCable::creerVueCable(VueEntitee *v)
{
        if(VueCable::getPremiereSelection()==NULL)
                VueCable::setPremiereSelection(v);
        else
        {
                VuePrincipale* vue = (VuePrincipale*) VuePrincipale::getwidget();
                VueCable* vc = new VueCable(VueCable::getPremiereSelection(),v);
                new VueCableControleur(vc);
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
