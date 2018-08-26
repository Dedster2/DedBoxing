/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Dedster
 *
 * Created on June 16, 2018, 1:51 PM
 */

#include <QApplication>

#include "mainScreen.h"
#include "boxerWidget.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Match.h"
#include "Boxer.h"
int main(int argc, char *argv[])
{
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);
    cout << "Ded was here, engel's a loser.\n";
    QApplication app(argc, argv);
   // //create and show your widgets here
    mainScreen *s = new mainScreen();
    s->show();    
    int a = app.exec();
    return a;
}
