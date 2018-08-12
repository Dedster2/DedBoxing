/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   roundTab.cpp
 * Author: Dedster
 *
 * Created on July 22, 2018, 9:45 AM
 */

#include "roundTab.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

roundTab::roundTab(QWidget *parent): QWidget(parent)
{
    widget.setupUi(this);
}

void roundTab::setup(Round r)
{
    int l = r.getRoundLength();
    Boxer *Boxers = r.getBoxers();
    cout << Boxers[0].getName();
    for (int i = 0; i < l; i++)
    {
        widget.list->addItem(QString::fromStdString(r.getTick(i)->toString()));
    }
        widget.boxerStats1->update(Boxers[0]);
        widget.boxerStats2->update(Boxers[1]);
        this->r = r;
}


void roundTab::setRoundNum(int n)
{
    widget.label->setText(QString::fromStdString("ROUND " + to_string(n)));
}

void roundTab::test(int i)
{
    cout << i << endl;
    GameTick *g = r.getTick(i);
    Boxer *b = g->getBoxers();
    widget.boxerStats1->update(b[0]);
    widget.boxerStats2->update(b[1]);
}
