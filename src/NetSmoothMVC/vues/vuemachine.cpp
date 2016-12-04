#include "vuemachine.h"

VueMachine::VueMachine(VueEntitee *parent) : VueEntitee(parent)
{
  struct lxc_container* cnt1 = lxc_container_new("machine0",NULL);
  this->ordi = new Ordinateur(cnt1);
    etat = false;
    zoneImg = new ClickLabel();
    QPixmap* img = new QPixmap();
    img->load("./images/ordinateuroff.png");
    *img = img->scaled(130,100);
    zoneImg->setPixmap(*img);
}

