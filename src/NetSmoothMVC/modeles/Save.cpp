#include "Save.h"

using namespace std;


void Save::load_session(string fileName)
{
        ifstream fichier(fileName.c_str(), ios::in);
        if(!fichier)
                return;

        string line;

        while(getline(fichier, line))
        {
            cout << line;
        }
}

void Save::save_session(string fileName)
{
        ElementListeChainee* ent;
        int i, j, k;
        bool ok;
        ofstream fichier(fileName.c_str(), ios::out|ios::trunc);
        if(!fichier)
        {
            cout << "marche po" << endl;
            return;
        }
    cout << "marche" << endl;
        vector<Cable*> cables;

        fichier << "{" << endl;

        for(i=0 ; i<3 ; i++)
        {
                ent=new ElementListeChainee;
                if(i==0)
                        ent->nextElement=DataBase::getListPasserelle();
                if(i==1)
                        ent->nextElement=DataBase::getListOrdinateur();
                if(i==2)
                        ent->nextElement=DataBase::getListHub();

                while(ent->nextElement!=NULL)
                {
                        fichier << "(" << endl;
                        ent=ent->nextElement;

                        Entitee* e=ent->entitee;

                        vector<Cable*> cab=e->getCables();

                        for(j=0 ; j<cab.size() ; j++)
                        {
                            ok=true;
                            for(k=0 ; k<cables.size() ; k++)
                                if(cab[j]==cables[k])
                                    ok=false;

                            if(ok==true)
                                cables.push_back(cab[j]);
                        }

                        fichier << e->getID() << endl;
                        fichier << e->getType() << endl;
                        //fichier << e->getNom() << endl;
                        fichier << e->getBridgeInit() << endl;
                        //fichier << e->getX() << endl;
                        //fichier << e->getY() << endl;
                        if(e->getType()!=TYPE_HUB)
                        {
                                Machine* m=(Machine*)e;
                                vector<paramIp*> ips=e->getIpConfig();
                                for(j=0 ; j<ips.size() ; j++)
                                {
                                        fichier << "\\" << endl;
                                        fichier << ips[j]->interface << endl;
                                        fichier << ips[j]->ipv4 << endl;
                                        fichier << ips[j]->maskv4 << endl;
                                        fichier << ips[j]->ipv6 << endl;
                                        fichier << "/" << endl;
                                }
                                vector<paramRoutage> r4=((Machine*)e)->getRouteConfig4();
                                for(j=0 ; j<r4.size() ; j++)
                                {
                                        fichier << "[4" << endl;
                                        fichier << r4[j].interface << endl;
                                        fichier << r4[j].destination << endl;
                                        fichier << r4[j].passerelle << endl;
                                        fichier << "]4" << endl;
                                }
                                vector<paramRoutage> r6=((Machine*)e)->getRouteConfig6();
                                for(j=0 ; j<r6.size() ; j++)
                                {
                                        fichier << "[6" << endl;
                                        fichier << r6[j].interface << endl;
                                        fichier << r6[j].destination << endl;
                                        fichier << r6[j].passerelle << endl;
                                        fichier << "]6" << endl;
                                }
                        }

                        fichier << ")" << endl;
                }
        }
        fichier << "}" << endl;

        for(i=0 ; i<cables.size() ; i++)
        {
            Cable* c=cables[i];
            Entitee* tab[2];
            c->getExtremites(tab);
            fichier << "<" << endl;
            fichier << tab[0]->getType() << endl;
            fichier << tab[0]->getID() << endl;
            fichier << tab[1]->getType() << endl;
            fichier << tab[1]->getID() << endl;
            fichier << ">" << endl;
        }
        fichier.close();
}
