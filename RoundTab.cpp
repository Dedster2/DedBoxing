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
#include "mainScreen.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <experimental/filesystem>
#include <QtCore/qstring.h>

roundTab::roundTab(QWidget *parent): QWidget(parent), sound(true)
{   
    widget.setupUi(this);
    autoOn = false;
    timer = new QTimer(this);
    connect(timer, &timer->timeout, this, &advance);
}

roundTab::roundTab(bool sound, QWidget* parent):sound(sound)
{
    widget.setupUi(this);
    autoOn = false;
    timer = new QTimer(this);
    connect(timer, &timer->timeout, this, &advance);
}


void roundTab::setup(Round *r, bool spoilers)
{
    widget.list->clear();
    int l = r->getRoundLength();
    Boxer *Boxers = r->getBoxers();
    for (int i = 0; i < l; i++)
    {
        QString qs = r->getTick(i)->toQString();
        if(qs == "")
            widget.list->addItem(QString::fromStdString(r->getTick(i)->toString()));
        else
            widget.list->addItem(qs);
        if(i != 0 && spoilers)
        {
            widget.list->item(i)->setHidden(true);
        }
    }
        widget.boxerStats1->update(Boxers[0]);
        widget.boxerStats2->update(Boxers[1]);
        this->r = r;
}


void roundTab::setRoundNum(int n)
{
    widget.label->setText(tr("ROUND %1").arg(n));
}

void roundTab::test(int i)
{
    QSoundEffect *sfx = new QSoundEffect(this);
    if(i < 0)
    {
        i = 0;
    }
    GameTick *g = r->getTick(i);
    Boxer *b = g->getBoxers();
    widget.boxerStats1->update(b[0]);
    widget.boxerStats2->update(b[1]);
    
    setImages(b[0].getState(), b[1].getState());
    if(sound)
        g->playSound(sfx);
    if(i != widget.list->count() - 1 && widget.list->item(i + 1)->isHidden())
        widget.list->item(i + 1)->setHidden(false);
            
    if(i == widget.list->count() - 1)
    {
        emit endRound();
    }
    delete sfx;
}

roundTab::~ roundTab()
{
}

void roundTab::toggleAuto()
{
    if(!autoOn)
    {
        widget.list->setEnabled(false);
        widget.toggleAuto->setText(tr("Disable Autoplay"));
        autoOn = true;
        timer->start(1000);
    }
    else
    {
        timer->stop();
        widget.list->setEnabled(true);
        widget.toggleAuto->setText(tr("Enable Autoplay"));
        autoOn = false;
    }
}

void roundTab::advance()
{
    int curRow = widget.list->currentRow();
    if(curRow != widget.list->count() - 1)
    {
        widget.list->setCurrentRow(curRow + 1);
    }
    else
    {
        emit toggleAuto();
    }
}

void roundTab::reveal()
{
    for(int i = 0; i < widget.list->count(); i++)
        widget.list->item(i)->setHidden(false);
    emit endRound();
}


void roundTab::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        widget.retranslateUi(this);
        widget.label->setText(tr("ROUND %1").arg(objectName().toInt() + 1));
        setup(r, false);
    } else
        QWidget::changeEvent(event);
}

void roundTab::toggleSound(bool val)
{
    sound = val;
}
