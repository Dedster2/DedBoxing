/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   mainScreen.cpp
 * Author: Dedster
 *
 * Created on June 16, 2018, 3:32 PM
 */


#include "mainScreen.h"
#include "boxerWidget.h"
#include "OptionsWidget.h"
#include "Match.h"
#include <sstream>
#include <experimental/filesystem>



mainScreen::mainScreen()
{ 
    
    widget.setupUi(this); 
    txtr = new QTranslator(this);
    connect(widget.optionsPane, &widget.optionsPane->toggleSound, widget.Test,
            &widget.Test->toggleSound);
    createMenus();
}

void mainScreen::startMatch(int numRounds, int downCount, int roundLength,
        bool spoilers)
{   
    Boxer boxers[] = {widget.BoxerA->getBoxer(), widget.BoxerB->getBoxer()};
    leftImages = widget.BoxerA->getImages();
    rightImages = widget.BoxerB->getImages();
    m.setBoxers(boxers[0], boxers[1]);
    m.startMatch(numRounds, downCount, roundLength);
    sendMatch(&m, spoilers);
}



void mainScreen::newRound(int roundNum)
{
}

void mainScreen::setImages(string s1, string s2)
{
    cout << "Setting " << s1 << " and " << s2 << endl;
    istringstream is1(s1);
    istringstream is2(s2);
    string part = s1;
    do 
    {
        if(leftImages.count(part) != 0 && 
                //Doesn't set the image if the state didn't change
                !(widget.stanceLeft->text().compare(
                QString::fromStdString(s1)) == 0))
        {
            int l = leftImages[part].size();
            widget.imgLeft->setPixmap(*leftImages[part][rand() % l]);
            break;
        }
    }while (getline(is1, part, ':'));
    
    part = s2;
    do 
    {
        if(rightImages.count(part) != 0 &&
                !(widget.stanceRight->text().compare(
                QString::fromStdString(s2)) == 0))
        {
            int r = rightImages[part].size();
            widget.imgRight->setPixmap(*rightImages[part][rand() % r]); 
            break;
        }
    } while (getline(is2, part, ':'));
    widget.stanceLeft->setText(QString::fromStdString(s1));
    widget.stanceRight->setText(QString::fromStdString(s2));
}

void mainScreen::saveMatch(QString s)
{
    QFile file(s);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;   
    }
    QTextStream out(&file);
    out << QString::fromStdString(m.toString());
    file.close();
}

void mainScreen::setLanguage(QAction* act)
{
    cout << act->text().toStdString();
    QApplication::instance()->removeTranslator(txtr);
    txtr->load(tr("%1.qm").arg(act->text()));
    QApplication::instance()->installTranslator(txtr);
    widget.retranslateUi(this);
}

void mainScreen::createMenus()
{
    menu = menuBar()->addMenu(tr("&Language"));
    langGroup = new QActionGroup(this);
    
    en = new QAction(tr("English"), this);
    sp = new QAction(tr("Spanish"), this);
    jp = new QAction(tr("Japanese"), this);
    cn = new QAction(tr("Chinese"), this);
    kr = new QAction(tr("Korean"), this);
    
    en->setCheckable(true);
    sp->setCheckable(true);
    jp->setCheckable(true);
    cn->setCheckable(true);
    kr->setCheckable(true);
    
    langGroup->addAction(en);
    langGroup->addAction(jp);
    langGroup->addAction(kr);
    langGroup->addAction(sp);
    langGroup->addAction(cn);
    menu->addAction(en);
    menu->addAction(sp);
    menu->addAction(jp);
    menu->addAction(kr);
    menu->addAction(cn);
    
    en->setChecked(true);
    
    connect(langGroup, &QActionGroup::triggered,this, &setLanguage);
}
