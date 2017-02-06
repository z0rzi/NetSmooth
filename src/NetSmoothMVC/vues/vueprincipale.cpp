#include "vueprincipale.h"

VuePrincipale* VuePrincipale::instance;

QWidget* VuePrincipale::ca = NULL;


VuePrincipale::VuePrincipale(QWidget *parent) : QWidget(parent)
{
    this->largeurCase = LARGEUR_CASE_INI;
    this->hauteurCase = HAUTEUR_CASE_INI;

    for(int ligne = 0 ; ligne < NB_CASE_Y ; ligne++)
        for(int col = 0 ; col < NB_CASE_X ; col++)
            this->grille[ligne][col] = VIDE;

    this->setMinimumSize(NB_CASE_X*LARGEUR_CASE_MIN,NB_CASE_Y*HAUTEUR_CASE_MIN);
    this->setMaximumSize(NB_CASE_X*LARGEUR_CASE_MAX,NB_CASE_Y*HAUTEUR_CASE_MAX);

    this->m_scene = new QGraphicsScene(this);
    this->m_view = new MaGraphicsView(m_scene,this);
    //this->m_view->setMouseTracking(true);
    this->m_vpc = new VuePrincipaleControleur(this);

    this->m_scene->setSceneRect(0,0,NB_CASE_X*LARGEUR_CASE_INI,NB_CASE_Y*HAUTEUR_CASE_INI);
    this->m_scene->setBackgroundBrush(Qt::white);

    this->m_view->show();
    this->ca=this;
    VuePrincipale::instance=this;
}

void VuePrincipale::mousePressEvent(QMouseEvent *e)
{
    if(Selection::getEnSelection()==CABLE){
        Selection::setEnSelection(SOURIS);
        VueCable::setPremiereSelection(NULL);
        VueCable::setSecondeSelection(NULL);
    }
    else if(Selection::getEnSelection()==SUPPRIMER)
    {
    }
    else if (e->buttons() == Qt::LeftButton)
    {
        this->m_pos = QWidget::mapFromGlobal(QCursor::pos());
        emit clickSouris(m_pos);
    }
}

void VuePrincipale::mouseDoubleClickEvent(QMouseEvent *e)
{
}

QWidget* VuePrincipale::getwidget()
{
    return ca;
}


VueEntitee *VuePrincipale::ajoutEntitee(int x, int y, int type)
{
    VueEntitee* e;
    if(type == TYPE_ORDINATEUR)
    {
        e = new VueMachine();
        //VueMachineControleur* c = new VueMachineControleur((VueMachine*)e);
        //e->setGeometry(x,y,130,130);
        this->m_scene->addItem(e);
    }
    if(type == TYPE_PASSERELLE)
    {
        e = new VuePasserelle();
        VuePasserelleControleur* c = new VuePasserelleControleur((VuePasserelle*)e);
        //e->setGeometry(x,y,130,130);
        this->m_scene->addItem(e);
    }
    if(type == TYPE_HUB)
    {
        e = new VueHub();
        VueHubControleur* c = new VueHubControleur((VueHub*)e);
        //e->setGeometry(x,y,130,130);
        this->m_scene->addItem(e);
    }

    this->m_view->setScene(this->m_scene);
    this->m_view->show();

    Selection::setEnSelection(SOURIS);

    return e;
}

void VuePrincipale::paintEntitee(QPoint m_posSouris)
{
    if(Selection::getEnSelection() == MACHINE)
    {
        VueMachine* e = new VueMachine();
        VueMachineControleur* c = new VueMachineControleur(e);
        //e->setGeometry(m_posSouris.x(),m_posSouris.y(),130,130);
        e->setOffset(m_posSouris.x(),m_posSouris.y());
        this->m_scene->addItem(e);
    }
    if(Selection::getEnSelection() == PASSERELLE)
    {
        VuePasserelle* e = new VuePasserelle();
        VuePasserelleControleur* c = new VuePasserelleControleur(e);
        //e->setGeometry(m_posSouris.x(),m_posSouris.y(),130,130);
        e->setOffset(m_posSouris.x(),m_posSouris.y());
        this->m_scene->addItem(e);
    }
    if(Selection::getEnSelection() == HUB)
    {
        VueHub* e = new VueHub();
        VueHubControleur* c = new VueHubControleur(e);
        //e->setGeometry(m_posSouris.x(),m_posSouris.y(),130,130);
        e->setOffset(m_posSouris.x(),m_posSouris.y());
        this->m_scene->addItem(e);
    }

    this->m_view->setScene(this->m_scene);
    this->m_view->show();

    Selection::setEnSelection(SOURIS);
}

QGraphicsScene* VuePrincipale::getScene()
{

    return this->m_scene;
}

MaGraphicsView* VuePrincipale::getView()
{
    return this->m_view;
}

VuePrincipale* VuePrincipale::getInstanceOf()
{
    if(VuePrincipale::instance == NULL)
        VuePrincipale::instance = new VuePrincipale();
    return VuePrincipale::instance;
}

bool VuePrincipale::deplacerEntitee(VueEntitee *v,QPoint* pos)
{
    QPoint* grillePos = this->localFromGlobal(pos);

    if(this->grille[grillePos->y()][grillePos->x()] == VIDE)
    {
        v->setOffset(grillePos->x()*this->largeurCase,
                grillePos->y()*this->hauteurCase);

        this->grille[grillePos->y()][grillePos->x()] = OCCUPE;
        return true;
    }
    return false;
}

QPoint* VuePrincipale::localFromGlobal(QPoint* pos)
{
    return new QPoint(pos->x()/this->largeurCase,
                      pos->y()/this->hauteurCase);
}

void VuePrincipale::resizeEvent(QResizeEvent* e)
{
    this->m_view->setMinimumSize(this->width(),this->height());
    this->m_view->setMaximumSize(this->width(),this->height());
}

