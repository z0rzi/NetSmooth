#include "vuehub.h"

VueHub::VueHub(VueEntitee *parent) : VueEntitee(parent)
{
    etat = false;
    zoneImg = new ClickLabel();
    QPixmap* img = new QPixmap();
    img->load("images/Huboff.png");
    *img = img->scaled(130,100);
    zoneImg->setPixmap(*img);
}
