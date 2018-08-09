/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Round.cpp
 * Author: Dedster
 * 
 * Created on July 15, 2018, 12:38 PM
 */

#include "Round.h"


Round::Round(int tickLength) : tickLength(tickLength), curTick(0),
        ticks(new BoxingTick[tickLength])
{
}

Boxer* Round::getBoxers()
{
    return ticks[curTick-1].getBoxers();
}




void Round::createTick(Boxer* a, Boxer* b)
{
    int seconds = curTick * 5;
    string secondString = (seconds % 60 < 10)?
        ("0" + to_string(seconds % 60)):
        to_string(seconds % 60);
    string timeString = to_string(seconds / 60) + ":" + secondString;
    
    
    BoxingTick *t = new BoxingTick(a, b, timeString);
    logTick(*t);
    

}

bool Round::logTick(BoxingTick tick)
{
    ticks[curTick] = tick;
    return (++curTick == tickLength);
}

void Round::printRound()
{
    //cout << "ROUND SUMMARY";
    for(int i = 0; i < tickLength; i++)
    {
        //ticks[i].printTick();
    }
}

bool Round::checkDowns(int limit)
{
    BoxingTick t = ticks[curTick - 1];
    int dt = t.getDownTime();
    if (dt != 0)
    {
        return (t.getRecieverDowns() >= limit || dt >= 10);
    }
    return false;
}
