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
    cout << "Spoilers are now " << ((spoilers)?"ON":"OFF") << endl;
}



void mainScreen::newRound(int roundNum)
{
}

void mainScreen::setImages(string s1, string s2)
{

    istringstream is1(s1);
    istringstream is2(s2);
    string part = s1;
    do 
    {
        if(leftImages.count(part) != 0)
        {
            widget.imgLeft->setPixmap(*leftImages[part]);
            break;
        }
    }while (getline(is1, part, ':'));
    
    part = s2;
    do 
    {
        if(rightImages.count(part) != 0)
        {
            widget.imgRight->setPixmap(*rightImages[part]); 
            break;
        }
    } while (getline(is2, part, ':'));
}

void mainScreen::saveMatch(QString s)
{
    cout << "Test";
    QFile file(s);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        cout<< "FUC";
        return;   
    }
    QTextStream out(&file);
    out << QString::fromStdString(m.toString());
    file.close();
}
