#include "selectioncontroleur.h"

SelectionControleur::SelectionControleur(Selection *vue0, QObject *parent) : QObject(parent)
{
      vue = vue0;

      connect(vue->getSouris(),SIGNAL(clicked(bool)),this,SLOT(changeEnSelection()));
      connect(vue->getMachine(),SIGNAL(clicked(bool)),this,SLOT(changeEnSelection()));
      connect(vue->getPasserelle(),SIGNAL(clicked(bool)),this,SLOT(changeEnSelection()));
      connect(vue->getHub(),SIGNAL(clicked(bool)),this,SLOT(changeEnSelection()));
      connect(vue->getCable(),SIGNAL(clicked(bool)),this,SLOT(changeEnSelection()));
}

void SelectionControleur::changeEnSelection()
{
   QPushButton* b = qobject_cast<QPushButton*>(sender());

   if(b->text() == "Souris")
   {
       Selection::setEnSelection(SOURIS);
   }
   if(b->text() == "Machine")
   {
       Selection::setEnSelection(MACHINE);
   }
   if(b->text() == "Passerelle")
   {
       Selection::setEnSelection(PASSERELLE);
   }
   if(b->text() == "Hub")
   {
       Selection::setEnSelection(HUB);
   }
   if(b->text() == "Cable")
   {
       Selection::setEnSelection(CABLE);
   }
}

