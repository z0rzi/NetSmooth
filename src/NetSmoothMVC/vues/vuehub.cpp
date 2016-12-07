#include "vuehub.h"
#include "modeles/DataBase.h"

VueHub::VueHub(VueEntitee *parent) : VueEntitee(parent)
{
	this->hub=DataBase::getNewHub();
	etat = false;
	zoneImg = new ClickLabel();
	QPixmap* img = new QPixmap();
	img->load("../build-NetSmoothMVC-Desktop-Debug/images/Huboff.png");
	*img = img->scaled(130,100);
	zoneImg->setPixmap(*img);
}

Hub* VueHub::getHub()
{
    return this->hub;
}

void VueHub::setHub(Hub* hub0)
{
  this->hub=hub0;
}
