#!/bin/bash
make clean

qmake $PWD/../NetSmoothMVC/NetSmoothMVC.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug && /usr/bin/make qmake_all

make
