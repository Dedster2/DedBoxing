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
        
    string t = side + bodyPart + punchThrown.getName() + ":" + bodyPart + punchThrown.getName() + ":" + 
       side +  punchThrown.getName() + ":" +  punchThrown.getName() + ":Punch";
    thrower->setState(t);

    reciever = (thrower == a)?*b:*a;
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


