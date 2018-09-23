/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   boxerRoundStats.h
 * Author: Dedster
 *
 * Created on August 1, 2018, 9:29 PM
 */

#ifndef _BOXERROUNDSTATS_H
#define _BOXERROUNDSTATS_H

#include "ui_boxerRoundStats.h"
#include "Boxer.h"
#include <string>
#include <iostream>

class boxerRoundStats : public QWidget {
    Q_OBJECT
public:
    boxerRoundStats(QWidget *parent);
    void update(Boxer b);
    virtual ~boxerRoundStats();
private:
    Ui::boxerRoundStats widget;
    int scope;
    Boxer b;
    void changeEvent(QEvent *event);
private slots:
    void switchStats(int id);
};

#endif /* _BOXERROUNDSTATS_H */
