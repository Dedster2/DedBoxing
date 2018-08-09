/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RoundTabs.cpp
 * Author: Dedster
 * 
 * Created on July 15, 2018, 9:31 AM
 */

#include "RoundTabs.h"
#include "roundTab.h"
#include <string>
RoundTabs::RoundTabs(QWidget *parent) : QTabWidget(parent)
{
    widget.setupUi(this);
}




void RoundTabs::createRounds(Match m)
{
    int numRounds = m.getNumRounds();
    Round* rounds = m.getRounds();
        cout << "ADDING ROUNDS " << numRounds;
        clear();
    for(int i = 0; i < numRounds; i++)
    {
        roundTab *t = new roundTab(this);
        addTab(t, QString::fromStdString("ROUND " + to_string(i + 1)));
        t->setRoundNum(i + 1);
        t->setup(rounds[i]);
    }
}
