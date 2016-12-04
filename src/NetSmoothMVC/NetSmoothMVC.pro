QT += widgets

HEADERS += \
    selection.h \
    information.h \
    vueprincipale.h \
    vuemachine.h \
    selectioncontroleur.h \
    vueprincipalecontroleur.h \
    vueentitee.h \
    vuehub.h \
    vueentiteecontroleur.h \
    vuepasserelle.h \
    vuemachinecontroleur.h \
    clicklabel.h \
    vuehubcontroleur.h \
    vuepasserellecontroleur.h\
Machine.h\
Entitee.h\
Ordinateur.h\
Passerelle.h\
Hub.h\
DataBase.h\
Cable.h\
Bridge.h

SOURCES += \
    selection.cpp \
    information.cpp \
    vueprincipale.cpp \
    vuemachine.cpp \
    main.cpp \
    selectioncontroleur.cpp \
    vueprincipalecontroleur.cpp \
    vueentitee.cpp \
    vuehub.cpp \
    vueentiteecontroleur.cpp \
    vuepasserelle.cpp \
    vuemachinecontroleur.cpp \
    clicklabel.cpp \
    vuehubcontroleur.cpp \
    vuepasserellecontroleur.cpp\
Machine.cpp\
Entitee.cpp\
Ordinateur.cpp\
Passerelle.cpp\
Hub.cpp\
DataBase.cpp\
Cable.cpp\
Bridge.cpp

QMAKE_LIBS += -llxc
