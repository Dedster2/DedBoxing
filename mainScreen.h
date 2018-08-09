/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mainScreen.h
 * Author: Dedster
 *
 * Created on June 16, 2018, 3:32 PM
 */

#ifndef _MAINSCREEN_H
#define _MAINSCREEN_H

#include "ui_mainScreen.h"
#include "boxerWidget.h"

class mainScreen : public QMainWindow {
    Q_OBJECT
public:
    mainScreen();
public slots:
    void newRound(int roundNum);
    void startMatch(int numRounds, int downCount, int roundLength);
    
 signals:
    void sendMatch(Match m);
private:
    Ui::mainScreen widget;
    boxerWidget *b, *b2;
    Match *m;

private slots:

};

#endif /* _MAINSCREEN_H */
