/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OptionsWidget.h
 * Author: Dedster
 *
 * Created on July 8, 2018, 8:54 PM
 */

#ifndef OPTIONSWIDGET_H
#define OPTIONSWIDGET_H
#include <QWidget>
#include <QtWidgets/qgroupbox.h>
#include <QtWidgets/qpushbutton.h>
#include "ui_OptionsWidget.h"

class OptionsWidget: public QGroupBox
{
    Q_OBJECT
    public:
        OptionsWidget(QWidget *parent = 0);
    private slots:
        void startClicked();
    signals:
        void sendOptions(int numRounds, int downCount, int roundLength);
    
    private:
        Ui::OptionsWidget widget;
            
};
#endif /* OPTIONSWIDGET_H */
