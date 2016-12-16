#include "selectioncontroleur.h"

SelectionControleur::SelectionControleur(Selection *vue0, QObject *parent) : QObject(parent)
{
      vue = vue0;

      connect(vue->souris,SIGNAL(clicked(bool)),this,SLOT(changeEnSelection()));
      connect(vue->machine,SIGNAL(clicked(bool)),this,SLOT(changeEnSelection()));
      connect(vue->passerelle,SIGNAL(clicked(bool)),this,SLOT(changeEnSelection()));
      connect(vue->hub,SIGNAL(clicked(bool)),this,SLOT(changeEnSelection()));
      connect(vue->cable,SIGNAL(clicked(bool)),this,SLOT(changeEnSelection()));
}

void SelectionControleur::changeEnSelection()
{
   QPushButton* b = qobject_cast<QPushButton*>(sender());

   if(b->text() == "Souris")
   {
       Selection::setEnSelection(SOURIS);
       cout << "Souris !" << endl << endl;
   }
   if(b->text() == "Machine")
   {
       Selection::setEnSelection(MACHINE);
       cout << "Machine !" << endl << endl;
   }
   if(b->text() == "Passerelle")
   {
       Selection::setEnSelection(PASSERELLE);
       cout << "Passerelle !" << endl << endl;
   }
   if(b->text() == "Hub")
   {
       Selection::setEnSelection(HUB);
       cout << "Hub !" << endl << endl;
   }
   if(b->text() == "Cable")
   {
       Selection::setEnSelection(CABLE);
       cout << "Cable !" << endl << endl;
   }
}

