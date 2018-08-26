/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   boxerWidget.h
 * Author: Dedster
 *
 * Created on June 17, 2018, 4:44 PM
 */

#ifndef BOXERWIDGET_H
#define BOXERWIDGET_H
#include <string>
#include <stdlib.h>
#include "QGroupBox"
#include <unordered_map>

#include "Boxer.h"
#include "ui_boxerWidget.h"

using std::string;

class boxerWidget : public QGroupBox
{
    Q_OBJECT      
public:
    boxerWidget(QWidget *parent = 0);
    boxerWidget(QWidget *parent, string defName);
    Boxer getBoxer();
    string getImageFolderName();
    string getName();
    void update(Boxer b);
    unordered_map<string, QPixmap*> getImages(){return images;}
    
public slots:
   //     void randomize();
    void loadBoxer();
    void saveBoxer();
    void setT(const QString& s);
private:
    Ui::boxerWidget widget;
    Boxer boxer;
    unordered_map<string, QPixmap*> images;
private slots:
    void loadImages();
};

#endif /* BOXERWIDGET_H */

