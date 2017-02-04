QT += widgets

HEADERS += \
    vues/selection.h \
    vues/information.h \
    vues/vueprincipale.h \
    vues/vuemachine.h \
    controleurs/selectioncontroleur.h \
    controleurs/vueprincipalecontroleur.h \
    vues/vueentitee.h \
    vues/vuehub.h \
    controleurs/vueentiteecontroleur.h \
    vues/vuepasserelle.h \
    controleurs/vuemachinecontroleur.h \
    controleurs/vuehubcontroleur.h \
    controleurs/vuepasserellecontroleur.h\
    modeles/Machine.h\
    modeles/Entitee.h\
    modeles/Ordinateur.h\
    modeles/Passerelle.h\
    modeles/Constantes.h\
    modeles/Hub.h\
    modeles/DataBase.h\
    modeles/Cable.h\
    modeles/Bridge.h\
    modeles/Cable.h\
    modeles/ElementListeChainee.h\
    modeles/Save.h\
    vues/vuecable.h\
    vues/constantes.h\
    vues/vueinformation.h\
    vues/ligneroute.h\
    controleurs/vueinformationcontroleur.h\
    vues/vueRoutes.h\
    controleurs/vueRoutesControleur.h\
    controleurs/VueIPControleur.h\
    vues/VueIP.h\
    vues/VueFormulaireIP.h\
    controleurs/VueFormulaireIPControleur.h \
    vues/fenetre.h

SOURCES += \
    main.cpp\
    vues/selection.cpp \
    vues/information.cpp \
    vues/vueprincipale.cpp \
    vues/vuemachine.cpp \
    controleurs/selectioncontroleur.cpp \
    controleurs/vueprincipalecontroleur.cpp \
    vues/vueentitee.cpp \
    vues/vuehub.cpp \
    controleurs/vueentiteecontroleur.cpp \
    vues/vuepasserelle.cpp \
    controleurs/vuemachinecontroleur.cpp \
    controleurs/vuehubcontroleur.cpp \
    controleurs/vuepasserellecontroleur.cpp\
    modeles/Machine.cpp\
    modeles/Entitee.cpp\
    modeles/Ordinateur.cpp\
    modeles/Passerelle.cpp\
    modeles/Hub.cpp\
    modeles/DataBase.cpp\
    modeles/Cable.cpp\
    modeles/Bridge.cpp\
    modeles/ElementListeChainee.cpp\
    modeles/Save.cpp\
    vues/vuecable.cpp\
    vues/vueinformation.cpp\
    vues/ligneroute.cpp\
    controleurs/vueinformationcontroleur.cpp\
    vues/vueRoutes.cpp\
    controleurs/vueRoutesControleur.cpp\
    controleurs/VueIPControleur.cpp\
    vues/VueIP.cpp\
    vues/VueFormulaireIP.cpp\
    controleurs/VueFormulaireIPControleur.cpp \
    vues/fenetre.cpp

QMAKE_LIBS += -llxc
