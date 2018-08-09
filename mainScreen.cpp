/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   mainScreen.cpp
 * Author: Dedster
 *
 * Created on June 16, 2018, 3:32 PM
 */


#include "mainScreen.h"
#include "boxerWidget.h"
#include "OptionsWidget.h"
#include "Match.h"
#include <condition_variable>


mainScreen::mainScreen()
{ 
    widget.setupUi(this); 
}

void mainScreen::startMatch(int numRounds, int downCount, int roundLength)
{    
    Boxer boxers[] = {widget.BoxerA->getBoxer(), widget.BoxerB->getBoxer()};
    m = new Match(boxers);
    m->startMatch(numRounds, downCount, roundLength);
    cout << "Returned\n";
    emit sendMatch(*m);
}



void mainScreen::newRound(int roundNum)
{
    cout << "Now starting round " << roundNum;
}

