/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BoxingTick.h
 * Author: Dedster
 *
 * Created on July 15, 2018, 12:44 PM
 */

#ifndef BOXINGTICK_H
#define BOXINGTICK_H

#include "Boxer.h"
#include "Punch.h"
#include "GameTick.h"
#include <string>
#include <iostream>

class PunchThrownTick: public GameTick
{
    Q_DECLARE_TR_FUNCTIONS(GameTick)
public:
    /**
     * 
     * @param a The boxer throwing the punch
     * @param b The other boxer
     * @param p The punch being thrown
     * @param damage The damage incurred
     * @param time Time the punch happened as a string
     * @param blockDodge 0 if the punch hit, 1 if blocked, 2 if dodged
     */
    PunchThrownTick();
    PunchThrownTick(Boxer a, Boxer b, Punch p, int damage, string time, int blockDodge);
    PunchThrownTick(Boxer *a, Boxer *b, Boxer *thrower);
    string printTick();
    std::string toString();
    QString toQString();
    int getDownTime();
    int getRecieverDowns();
    void playSound(QSoundEffect* qsfx);

private:
    Boxer thrower, reciever;
    Punch punchThrown;
    int blockDodgeFlag, downTime;
    float damageTaken;
    string time;
    string bodyPart, side;
    static QSoundEffect *sfx;
    
    void buildStates();
};
#endif /* BOXINGTICK_H */
