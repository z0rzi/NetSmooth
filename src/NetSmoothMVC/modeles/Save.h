#ifndef SAVE_DEF
#define SAVE_DEF

#include <iostream>
#include <vector>
#include <QObject>
#include <fstream>
#include "DataBase.h"

class Save
{
        public:
                static void save_profile(std::string fileName);

        private:

        public slots:
                static void sauvegarder(std::string fn);
};

#endif

