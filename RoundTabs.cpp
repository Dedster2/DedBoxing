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
#include <experimental/filesystem>
RoundTabs::RoundTabs(QWidget *parent) : QTabWidget(parent)
{
    uiWidget.setupUi(this);

}




void RoundTabs::createRounds(Match *m, bool spoilers)
{
    int numRounds = m->getNumRounds();
    Round** rounds = m->getRounds();

    while(widget(0))
    {
       delete widget(0);
    }
    
    for(int i = 0; i < numRounds; i++)
    {
        roundTab *t = new roundTab();
        t->setObjectName(QString::fromStdString((to_string(i))));
        addTab(t, QString::fromStdString("ROUND " + to_string(i + 1)));
        t->setRoundNum(i + 1);
        t->setup(rounds[i], spoilers);
        connect(t, &t->setImages, this, &setImages);
        connect(t, &t->endRound, this, &showNext);
        if(spoilers && i != 0)
        {
            removeTab(1);
        }
    }
        
}

RoundTabs::~ RoundTabs()
{
}

void RoundTabs::showNext()
{
    int i  = currentIndex() + 1;
    if(count() == i)
    {
        roundTab *t = findChild<roundTab *>((QString::fromStdString((to_string(i)))));
        addTab(t, QString::fromStdString("ROUND " + to_string(i + 1)));
    }
}
