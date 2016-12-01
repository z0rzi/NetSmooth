#include "vuepasserelle.h"

VuePasserelle::VuePasserelle(VueEntitee *parent) : VueEntitee(parent)
{
    etat = false;
    zoneImg = new ClickLabel();
    QPixmap* img = new QPixmap();
    img->load("/home/user/NetSmooth/NetSmoothMVC/images/passerelleoff.png");
    *img = img->scaled(130,100);
    zoneImg->setPixmap(*img);
}
