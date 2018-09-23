/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   roundTab.h
 * Author: Dedster
 *
 * Created on July 22, 2018, 9:45 AM
 */

#ifndef _ROUNDTAB_H
#define _ROUNDTAB_H

#include "ui_roundTab.h"
#include "Round.h"
#include <string>
#include <unordered_map>
#include "QTimer"

class roundTab : public QWidget {
    Q_OBJECT
public:
    roundTab(QWidget *parent = 0);
    roundTab(bool sound, QWidget *parent = 0);
    ~roundTab();
    void setRoundNum(int n);
    void setup(Round *r, bool spoilers);
    
signals:
    void setImages(string s1, string s2);
    void endRound();

public slots:
    void toggleSound(bool val);
private:
    Ui::roundTab widget;
    Round *r;
    bool autoOn;
    QTimer *timer;
    void changeEvent(QEvent *event);
    void playSound(GameTick *gt);
    bool sound;

private slots:
    void toggleAuto();
    void reveal();
   
    
private slots:
    void test(int i);
    void advance();
};



#endif /* _ROUNDTAB_H */
