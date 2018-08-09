/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RoundTabs.h
 * Author: Dedster
 *
 * Created on July 15, 2018, 9:31 AM
 */

#ifndef ROUNDTABS_H
#define ROUNDTABS_H
#include "ui_roundTabs.h"
#include <string>
#include "Match.h"

class RoundTabs: public QTabWidget {
    Q_OBJECT
public:
    RoundTabs(QWidget *parent = 0);
    Ui::Form widget;
public slots:
    void createRounds(Match m);
private:

};

#endif /* ROUNDTABS_H */

