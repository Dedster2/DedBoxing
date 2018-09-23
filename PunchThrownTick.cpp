/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BoxingTick.cpp
 * Author: Dedster
 * 
 * Created on July 15, 2018, 12:44 PM
 */

#include "PunchThrownTick.h"
#include "dedGame.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "QString"

PunchThrownTick::PunchThrownTick(Boxer a, Boxer b, Punch p, int damage, string time,
        int blockDodge): thrower(a), reciever(b), punchThrown(p),
        blockDodgeFlag(blockDodge),  damageTaken(damage), time(time)
{
}

PunchThrownTick::PunchThrownTick()
{
}

PunchThrownTick::PunchThrownTick(Boxer *a, Boxer *b, Boxer *thrower) : downTime(0)
{
    
    //keeps original set of a, b to store
    blockDodgeFlag = 0;
    punchThrown = thrower->getPunch();
    side = punchThrown.getSide(), bodyPart = punchThrown.getBodyPart();
    
    QString qst = "%1%2%3:%2%3:%1%3:%3:%1%2Punch:%1Punch:Punch";
    qst = qst.arg(qst.fromStdString(side)).
        arg(qst.fromStdString(bodyPart)).
        arg(qst.fromStdString(punchThrown.getName()));
    string t = side + bodyPart + punchThrown.getName() + ":" + bodyPart + punchThrown.getName() + ":" + 
       side +  punchThrown.getName() + ":" +  punchThrown.getName() + ":Punch";
    t = qst.toStdString();
    thrower->setState(t);

    Boxer *rec = (thrower == a)?b:a;
    reciever = (thrower == a)?*b:*a;
    if(rec->isDown())
        rec->setState("Punchdrunk:Stance");
    else
        if(rec->getState().find("unch") == string::npos)
            rec->setState("Stance");
    this->thrower = *thrower;
                
    
    boxers[0] = *a;
    boxers[1] = *b;
}


std::string PunchThrownTick::toString()
{
    string out = thrower.getName() + " threw a " + side + " " +
            punchThrown.getName() + " at " + reciever.getName() +
            + "'s " + bodyPart + ". ";
    return out;
}

int PunchThrownTick::getDownTime()
{
    return downTime;
}

int PunchThrownTick::getRecieverDowns()
{
    return reciever.getDowns();
}

QString PunchThrownTick::toQString()
{
    return tr("%1 threw a %2 %3 at %4's %5. ")
            .arg(QString::fromStdString(thrower.getName()))
            .arg(localizeString(side))
            .arg(localizeString(punchThrown.getName()))
            .arg(QString::fromStdString(reciever.getName()))
            .arg(localizeString(bodyPart));
}

void PunchThrownTick::playSound(QSoundEffect* qsfx)
{
    playSoundFromString(sfx, "throw.wav");
}


QSoundEffect* PunchThrownTick::sfx = new QSoundEffect();