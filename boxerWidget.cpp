/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   boxerWidget.cpp
 * Author: Dedster
 * 
 * Created on June 17, 2018, 4:44 PM
 */

#include "boxerWidget.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <QtCore/qstring.h>
#include <QtCore/qdatastream.h>
#include "QtCore/qtextstream.h"
#include "QFileDialog"
#include "QMessageBox"
#include <string>
#include <experimental/filesystem>

boxerWidget::boxerWidget(QWidget *parent): QGroupBox(parent)
{
    widget.setupUi(this);
    const string s = "UNDECLARED";
    connect(this, this->objectNameChanged, widget.leName, widget.leName->setText);
}
boxerWidget::boxerWidget(QWidget* parent, string defName): QGroupBox(parent)
{
    widget.setupUi(this);
    connect(this, this->objectNameChanged, widget.leName, widget.leName->setText);
}

//void boxerWidget::randomize()
//{
//    int array[5];
//    int total = sbTotalStats->value();
//    for (int i = 0; i < 4; i++)
//    {
//        int curVal = rand() % total;
//        array[i] = curVal;
//        total -= curVal;
//    }
//    array[4] = total;
//    for(int i = 4; i > 0; i--)
//    {
//        int j =  rand() % (i + 1);
//        int t = array[j];
//        array[j] = array[i];
//        array[i] = t;
//    }
//    
//    for(int i = 0; i < 5; i++)
//    {
//       std::cout << "Value of " << i << " = " << array[i] << std::endl;
//    }
//    sbStr->setValue(array[0]);
//    sbDef->setValue(array[1]);
//    sbHit->setValue(array[2]);
//    sbBlk->setValue(array[3]);
//    sbSpeed->setValue(array[4]);
//}

void boxerWidget::setT(const QString& s)
{
    setTitle(s);
}

string boxerWidget::getName()
{
    return widget.leName->text().toStdString();
}

Boxer boxerWidget::getBoxer()
{
    boxer.setStats(widget.sbStrength->value(), widget.sbDefense->value(), 
            widget.sbHit->value(), widget.sbBlock->value(),
            widget.sbSpeed->value(), widget.leName->text().toStdString());
    return boxer;
}

void boxerWidget::loadBoxer()
{
    QString fName = QFileDialog::getOpenFileName(this, tr("Load Boxer"), "", "Boxer (*.bxr)");
    QFile file(fName);
    if (!file.open(QIODevice::ReadOnly)) 
    {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
    }
    QDataStream in(&file);
    float st, ft, tc, df, sp;
    int l;
    char* boxerName = new char[255];
    in.readRawData((char*) &st, sizeof(float));
    in.readRawData((char*) &ft, sizeof(float));
    in.readRawData((char*) &tc, sizeof(float));
    in.readRawData((char*) &df, sizeof(float));
    in.readRawData((char*) &sp, sizeof(float));
    in.readRawData((char*) &l, sizeof(int));
    in.readRawData(boxerName, sizeof(char) * l);
    
    string nameString(boxerName, l);
    widget.sbStrength->setValue(st);
    widget.sbDefense->setValue(ft);
    widget.sbHit->setValue(tc);
    widget.sbBlock->setValue(df);
    widget.sbSpeed->setValue(sp);
    widget.leName->setText(QString::fromStdString(nameString));
}

void boxerWidget::saveBoxer()
{
    QString def = widget.leName->text();
    
    //Opens file dialog defaulting with current name
    QString fName = QFileDialog::getSaveFileName
            (this, tr("Save Boxer"), def, "Boxer (*.bxr)");
    QFile file(fName);
    if (!file.open(QIODevice::WriteOnly)) 
    {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
    }
    QDataStream out(&file);
    float st, ft, tc, df, sp;
    st = widget.sbStrength->value();
    ft = widget.sbDefense->value();
    tc = widget.sbHit->value();
    df = widget.sbBlock->value();
    sp = widget.sbSpeed->value();
    string name = widget.leName->text().toStdString();
    int l = name.size();
    
    
    out.writeRawData((char*) &st, sizeof(float));
    out.writeRawData((char*) &ft, sizeof(float));
    out.writeRawData((char*) &tc, sizeof(float));
    out.writeRawData((char*) &df, sizeof(float));
    out.writeRawData((char*) &sp, sizeof(float));
    out.writeRawData((char*) &l,  sizeof(int));
    out.writeRawData(name.c_str(), sizeof(char)*l);
        
}

void boxerWidget::update(Boxer b)
{
    widget.leName->setText(QString::fromStdString(b.getName()));
    int stats[5];
    b.getStats(stats);
    widget.sbStrength->setValue(stats[0]);
    widget.sbDefense->setValue(stats[1]);
    widget.sbHit->setValue(stats[2]);
    widget.sbBlock->setValue(stats[3]);
    widget.sbSpeed->setValue(stats[4]);
}

string boxerWidget::getImageFolderName()
{
    return widget.leImgFolder->text().toStdString();
}

void boxerWidget::loadImages()
{
    using std::experimental::filesystem::path;
    QString folderName = QFileDialog::getExistingDirectory
            (this,"Load Image Folder", "./images/");
    widget.leImgFolder->setText(folderName.split('/').back());
    //clear current set of images
    for(std::pair<string, QPixmap*> p:images)
    {
        delete p.second;
    }
    images.clear();
    widget.lblInfo->setText("");
    
    //sets images
     path pA(folderName.toStdString());
     addImagesFromFolder(pA);
    
}

void boxerWidget::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        widget.retranslateUi(this);
    } else
        QWidget::changeEvent(event);
}

void boxerWidget::addImagesFromFolder(std::experimental::filesystem::path pA)
{
    using std::experimental::filesystem::path;
    using std::experimental::filesystem::directory_entry;
    if(!pA.empty())
    for(std::experimental::filesystem::directory_entry s
            : std::experimental::filesystem::directory_iterator(pA) )
    {
        if(std::experimental::filesystem::is_directory(s.status()))
            addImagesFromFolder(s);
        else if(s.path().extension().string() == ".txt")
        {
            QFile fa(QString::fromStdString(s.path().string()));
            if(!fa.open(QIODevice::ReadOnly | QIODevice::Text))
                break;
            
            QTextStream in(&fa);
            while (!in.atEnd()) 
            {
                QString line = in.readLine();
                QString curS = widget.lblInfo->toPlainText();
                widget.lblInfo->setText(curS.append(line + "\n"));
            }
        }
        else
        {
            string fName = s.path().stem().string();
            images[fName] = new QPixmap(QString::fromStdString(s.path().string()));
        }
    }
}
