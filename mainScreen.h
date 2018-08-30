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
#include <unordered_map>
#include "QTextStream"

class mainScreen : public QMainWindow {
    Q_OBJECT
public:
    mainScreen();
public slots:
    void newRound(int roundNum);
    void startMatch(int numRounds, int downCount, int roundLength, bool spoilers);
    void setImages(string s1, string s2);
    void saveMatch(QString s);
    
 signals:
    void sendMatch(Match *m, bool spoilers);
private:
    Ui::mainScreen widget;
    boxerWidget *b, *b2;
    Match m;
    std::unordered_map<std::string, QPixmap*> leftImages; 
    std::unordered_map<std::string, QPixmap*> rightImages;

private slots:
 
};

#endif /* _MAINSCREEN_H */
