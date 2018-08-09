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
#include <string>
#include <iostream>

class BoxingTick
{
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
    BoxingTick();
    BoxingTick(Boxer a, Boxer b, Punch p, int damage, string time, int blockDodge);
    BoxingTick(Boxer *a, Boxer *b, string time);
    string printTick();
    string toString();
    int getDownTime();
    int getRecieverDowns();
    Boxer *getBoxers(){cout <<"R"; return boxers;}
private:
    Boxer thrower, reciever, boxers[2];
    Punch punchThrown;
    int damageTaken, blockDodgeFlag, downTime;
    string time;
};
#endif /* BOXINGTICK_H */
