#ifndef SAVE_DEF
#define SAVE_DEF

#include <iostream>
#include <vector>
#include <QObject>
#include <fstream>
#include "DataBase.h"
#include "../vues/vueentitee.h"

class Save
{
        public:
                static void save_session(std::string fileName);
                static void load_session(std::string fileName);

        private:
};

#endif

