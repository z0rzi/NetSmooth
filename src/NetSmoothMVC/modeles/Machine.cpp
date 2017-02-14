#include "Machine.h"
#include <fstream>
#include <string>
#include <bitset>
#include <sstream>

using namespace std;



Machine::Machine(int id, int type, const char* cntName)
        :Entitee(id, type)
{
    char buff[20];
    sprintf(buff, "%s%d\0", cntName, id);
    cout << "buff = '" << buff << "'" << endl;
    cout << "cntName = '" << cntName << "'" << endl;
    m_container=lxc_container_new(buff, NULL);
    m_container->set_config_item(m_container, "lxc.utsname", buff);
    this->reinitNetworkConfig();
}

void Machine::addIpConfig(struct paramIp* ip)
{
    this->m_paramIp.push_back(ip);
}

void Machine::setIpConfig(struct paramIp* ip)
{
    std::cout <<this->m_paramIp.size()<< std::endl;
    for(int i = 0; i<this->m_paramIp.size() ; i++)
    {
                std::cout << this->m_paramIp[i]->interface+";"+ip->interface << std::endl;
        if(ip->interface.compare(this->m_paramIp[i]->interface.c_str()) == 0)
        {
            this->m_paramIp[i]->ipv4 = ip->ipv4;
            this->m_paramIp[i]->maskv4 = ip->maskv4;
            this->m_paramIp[i]->ipv6 = ip->ipv6;
            break;
        }
    }
}

vector<struct paramIp*> Machine::getIpConfig()
{
    return this->m_paramIp;
}

void Machine::addRouteConfig4(struct paramRoutage route)
{
    this->m_paramRoutage4.push_back(route);
}

vector<struct paramRoutage> Machine::getRouteConfig4() const
{
    return this->m_paramRoutage4;
}

vector<struct paramRoutage> Machine::getRouteConfig6() const
{
    return this->m_paramRoutage6;
}

void Machine::addRouteConfig6(struct paramRoutage route)
{
    this->m_paramRoutage6.push_back(route);
}

struct lxc_container* Machine::getContainer(void) const
{
    return m_container;
}

int Machine::lancerContainer()
{
    int tst;

    tst = this->m_container->start(this->m_container, 0, NULL);
    if(!tst)
    {
        char cntName[20];
        bzero(cntName, 20);
        this->m_container->get_config_item(this->m_container, "lxc.utsname", cntName, 20);
        cout << "Failed to start the container '" << cntName << "'" << endl;
        return -1;
    }
    cout << "container succefully started" << endl;
    return 0;
}

void Machine::stopperContainer()
{
    int tst;this->lancerContainer();

    tst = this->m_container->shutdown(this->m_container, 1);
    if(!tst)
    {
        printf("Failed to cleanly stop the container, forcing.\n");
        force_stopperContainer();	/*plus violent que shutdown*/
    }
    cout << "container succesfully stopped" << endl;
}

void Machine::force_stopperContainer()
{
    int x=fork();

    if(x==-1)
    {
        perror("fork");
        exit(1);
    }
    if(x==0)
    {
        char cntName[20];
        this->m_container->get_config_item(this->m_container, "lxc.utsname", cntName, 20);
        execl("../NetSmoothMVC/scripts/stopperContainer.sh", "stopContainer", cntName, NULL);
        exit(0);
    }
    int useless;
    while(wait(&useless)<0);
}
void Machine::separerDeBridge()
{
    int x=fork();

    if(x==-1)
    {
        perror("fork");
        exit(1);
    }
    if(x==0)
    {
        char cntName[20];
        this->m_container->get_config_item(this->m_container, "lxc.utsname", cntName, 20);
        execl("../NetSmoothMVC/scripts/unjoinCntAndBridge.sh", "joinCntBridge", cntName,this->m_bridgeActuel.c_str(), NULL);
        exit(0);
    }
    int useless;
    while(wait(&useless)<0);
}
void Machine::lierABridge()
{
    int x=fork();

    if(x==-1)
    {
        perror("fork");
        exit(1);
    }
    if(x==0)
    {
        char cntName[20];
        this->m_container->get_config_item(this->m_container, "lxc.utsname", cntName, 20);
        execl("../NetSmoothMVC/scripts/joinCntAndBridge.sh", "joinCntBridge", cntName,this->m_bridgeActuel.c_str(), NULL);
        exit(0);
    }
    int useless;
    while(wait(&useless)<0);
}

void Machine::lancerCommandeDansContainer(const char** commande)
{
        lxc_attach_options_t options = LXC_ATTACH_OPTIONS_DEFAULT;
        lxc_attach_command_t cmd={(char*)commande[0], (char**)commande};		/* rien de compliqué par ici, juste */
        pid_t pid=(this->m_container)->init_pid(this->m_container);					/* transférer les arguments la ou il faut
                 * pour lancer une commande dans le container*/

        this->m_container->attach(this->m_container, lxc_attach_run_command, &cmd, &options, &pid);
}

void Machine::appliquerParamIp()
{
    int i;

    vector<struct paramIp*> tab=this->getIpConfig();
    for(i=0 ; i<tab.size() ; i++)
    {
        if(tab[i]->ipv4 != "" && tab[i]->maskv4 != "")
        {
                const char* cmd[]={"ifconfig", tab[i]->interface.c_str(), tab[i]->ipv4.c_str(), "netmask", tab[i]->maskv4.c_str(), "up", NULL};
                this->lancerCommandeDansContainer(cmd);
        }
        else
        {
                const char* cmd[]={"ifconfig", tab[i]->interface.c_str(), "default", NULL};
                this->lancerCommandeDansContainer(cmd);
        }
        if(tab[i]->ipv6 != "")
        {
                const char* cmd[]={"ifconfig", tab[i]->interface.c_str(), "add", tab[i]->ipv6.c_str(), NULL};
                this->lancerCommandeDansContainer(cmd);
        }
    }
}

void Machine::supprimerContainerRoutage4(int id)
{
    bool found = false;
    vector<struct paramRoutage> tab=this->getRouteConfig4();
    int indice;

    for(indice=0 ; indice<this->m_paramRoutage4.size() && !found ; indice++)
    {
        found = false;
        {
            if(this->m_paramRoutage4[indice].id == id)
            {
                found = true;
            }
        }
    }
    cout << "indice " << indice << endl;
    const char* cmd[]={"route", "del", "-net", tab[indice-1].destination.c_str(), "gw", tab[indice-1].passerelle.c_str(), "dev", tab[indice-1].interface.c_str(), NULL};

    this->lancerCommandeDansContainer(cmd);
}

void Machine::supprimerContainerRoutage6(int id)
{
    bool found = false;
    vector<struct paramRoutage> tab=this->getRouteConfig6();
    int indice;

    for(indice=0 ; indice<this->m_paramRoutage6.size() && !found ; indice++)
    {
        found = false;
        {
            if(this->m_paramRoutage6[indice].id == id)
            {
                found = true;
            }
        }
    }
    const char* cmd[]={"route", "del", "-inet6", tab[indice-1].destination.c_str(), "gw", tab[indice-1].passerelle.c_str(), "dev", tab[indice-1].interface.c_str(), NULL};

    this->lancerCommandeDansContainer(cmd);
}

void Machine::appliquerParamRoutage4()
{

    int i;

    vector<struct paramRoutage> tab = this->getRouteConfig4();
    for(i=0 ; i<tab.size() ; i++)
    {
        const char* cmd[]={"route", "add", "-net", tab[i].destination.c_str(), "gw", tab[i].passerelle.c_str(), "dev", tab[i].interface.c_str(), NULL};

        this->lancerCommandeDansContainer(cmd);
    }
}
/* 
 *	lance un xterm qui représente le terminal d'une Machine (donc d'un container)
 */
void Machine::lancerXterm()
{
    int x=fork();

    if(x==-1)
    {
        perror("fork");
        exit(1);
    }
    if(x==0)
    {
        char cntName[20];
        this->getContainer()->get_config_item(this->getContainer(), "lxc.utsname", cntName, 20);
        execl("../NetSmoothMVC/scripts/launchXtermRoot.sh", "launchCnt", cntName, this->getNom().c_str(), NULL);
        exit(0);
    }
}

void Machine::reinitNetworkConfig()
{
    int x=fork();

    if(x==-1)
    {
        perror("fork");
        exit(1);
    }
    if(x==0)
    {
        char cntName[20];
        this->getContainer()->get_config_item(this->getContainer(), "lxc.utsname", cntName, 20);
        execl("../NetSmoothMVC/scripts/reinitConfigContainer.sh", "reinit", cntName, NULL);
        exit(0);
    }
}

void Machine::majIpContainer()
{
        const char* cmd[]={"/.scr/majIpconfig.sh", NULL};

        this->lancerCommandeDansContainer(cmd);
}

void Machine::majRouteContainer()
{
        const char* cmd[]={"/.scr/majRouteconfig.sh", NULL};

        this->lancerCommandeDansContainer(cmd);
}

int Machine::getNewIdRoute4()
{
        bool found = false;
        int id;

        for(id = 0 ; !found ; id++)
        {
                found = true;
                for(int i=0;i<this->m_paramRoutage4.size();i++)
                {
                        if(this->m_paramRoutage4[i].id == id)
                                found = false;
                }
        }

        cout << "id == >" << id << endl;
        return id-1;
}

void Machine::lireModifContainer()
{
        int i, j;
        char cntName[20];
        bzero(cntName, 20);
        this->m_container->get_config_item(this->m_container, "lxc.utsname", cntName, 20);
        string name(cntName);
        ifstream ipFile(("/var/lib/lxc/"+name+"/rootfs/.networkInfo/ipConfig.info").c_str(), ios::in);
        string line;
        while(getline(ipFile, line))
        {
                bool ok=false;
                for(i=0 ; i<this->m_paramIp.size() && !ok ; i++)
                {
                        if(line == this->m_paramIp[i]->interface)
                                ok=true;
                }
                i--;
                if(ok)
                {
                        this->m_paramIp[i]->interface=line;

                        getline(ipFile, line);
                        this->m_paramIp[i]->ipv4=line;

                        getline(ipFile, line);
                        this->m_paramIp[i]->maskv4=line;

                        getline(ipFile, line);
                        this->m_paramIp[i]->ipv6=line;
                }
        }
        ipFile.close();

        vector<struct paramRoutage> *p = new vector<paramRoutage>;
        ifstream routeFile(("/var/lib/lxc/"+name+"/rootfs/.networkInfo/routeConfig.info").c_str(), ios::in);
        i=0;
        while(getline(routeFile, line))
        {
                struct paramRoutage *tmp = new struct paramRoutage;
                tmp->id=i;

                tmp->interface=line;

                getline(routeFile, line);
                string dest=line;

                int m=0;
                string buff="";
                getline(routeFile, line);
                tmp->passerelle=line;

                getline(routeFile, line);
                for(j=0 ; j<line.size() ; j++)
                        if(line[j]=='.')
                        {
                                if(buff=="255")
                                        m+=8;
                                else if(buff=="0")
                                        j=line.size();
                                else
                                {
                                        int nb=atoi(buff.c_str());
                                        string binary = bitset<8>(nb).to_string();
                                        int e=0;
                                        while(binary[e]!='0')
                                                e++;
                                        m+=e;
                                }
                                buff="";
                        }
                        else
                                buff+=line[j];
                stringstream ss;
                ss << m;
                tmp->destination=dest+"/"+ss.str();
                p->push_back(*tmp);
                i++;
        }
        this->m_paramRoutage4 = *p;
        routeFile.close();
}


void Machine::removeParamRoute4(int id)
{
        bool found = false;

        for(int i = 0 ; i < this->m_paramRoutage4.size() && !found ; i++)
        {

                if(this->m_paramRoutage4[i].id == id)
                {
                        found = true;
                        this->supprimerContainerRoutage4(id);
                        this->m_paramRoutage4.erase(this->m_paramRoutage4.begin() + i);
                }

        }
}

void Machine::removeParamRoute6(int id)
{
        bool found = false;

        for(int i = 0 ; i < this->m_paramRoutage6.size() && !found ; i++)
        {

                if(this->m_paramRoutage6[i].id == id)
                {
                        found = true;
                        this->supprimerContainerRoutage6(id);
                        this->m_paramRoutage6.erase(this->m_paramRoutage6.begin() + i);
                }

        }
}

void Machine::appliquerParamRoutage6()
{
        int i;

        vector<struct paramRoutage> tab = this->getRouteConfig6();
        for(i=0 ; i<tab.size() ; i++)
        {
                const char* cmd[]={"route", "add", "-inet6", tab[i].destination.c_str(), "gw", tab[i].passerelle.c_str(), "dev", tab[i].interface.c_str(), NULL};

                this->lancerCommandeDansContainer(cmd);
        }
}
