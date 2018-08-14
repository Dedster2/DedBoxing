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

#include "BoxingTick.h"
#include "dedGame.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

BoxingTick::BoxingTick(Boxer a, Boxer b, Punch p, int damage, string time,
        int blockDodge): thrower(a), reciever(b), punchThrown(p),
        damageTaken(damage), blockDodgeFlag(blockDodge), time(time)
{
}

BoxingTick::BoxingTick()
{
}

BoxingTick::BoxingTick(Boxer *a, Boxer *b) : downTime(0)
{
    Boxer *iniA = a, *iniB = b;
    a->selectPunch();
    b->selectPunch();
    bodyPart = bodyPartList[rand() % 3];
    side = sides[rand() % 2];
    //swaps a and b if a is slower, such that a will always
    //be the one throwing the punch
    
    if (!a->outSpeeds(*b))
    {
        Boxer *tmp = a;
        a = b;
        b = tmp;
    }
    blockDodgeFlag = 0;
    punchThrown = a->getPunch();
    damageTaken = a->calcDamage(*b);
    damageTaken *= .75;
    cout << "DT = " << damageTaken << endl;
    if (!a->hits(*b))
    {
        blockDodgeFlag = 2;
        damageTaken = 0;
        downTime = 0;
    }
    
    else if (b->blocks(*a))
    {
        blockDodgeFlag = 1;
        damageTaken /= 2;
        b->tempDamage(damageTaken);
    }
    else
    {
        blockDodgeFlag = 0;
        b->takesDamage(damageTaken);
    }
    
    thrower = *a;
    reciever = *b;
    
    boxers[0] = *iniA;
    boxers[1] = *iniB;
}


    std::string BoxingTick::toString()
{
        cout<< blockDodgeFlag << endl;
    using namespace std;
    string out = thrower.getName() + " threw a " + side + " " +
            punchThrown.getName() + " at " + reciever.getName() +
            + "'s " + bodyPart + ". "  +
            reciever.getName();
    switch(blockDodgeFlag)
    {
        case 0:
            out.append(" takes " + to_string(damageTaken) + " damage.");
            break;
        case 1:
            out.append(" blocks it for " + to_string(damageTaken)
                    + " damage.");
            break;
        case 2:
            out.append(" dodges it");
            break;
    }
    
    if (downTime != 0)
    {
        out.append("DOWN!");
        for (int i = 0; i < downTime; i++)
        {
            out.append(to_string(i + 1) + "! ");
        }
    }
    return out;
}

int BoxingTick::getDownTime()
{
    return downTime;
}

int BoxingTick::getRecieverDowns()
{
    return reciever.getDowns();
}



