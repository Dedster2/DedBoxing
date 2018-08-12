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
#include "DownTick.h"
#include "TKOTick.h"
#include "IntervalTick.h"
#include "CountTick.h"


Round::Round(int tickLength, int downLimit) : tickLength(tickLength), 
        downLimit(downLimit), curTick(0), ticks(new GameTick*[tickLength * 3])
{
}

Boxer* Round::getBoxers()
{
    return boxersEnd;
}





void Round::printRound()
{
    //cout << "ROUND SUMMARY";
    for(int i = 0; i < tickLength; i++)
    {
        //ticks[i].printTick();
    }
}


bool Round::createRound(Boxer* a, Boxer* b)
{
    int boxingTicks = 0;
    while(boxingTicks < tickLength)
    {
        ticks[curTick++] = new BoxingTick(a, b);
        if (a->isDown() || b->isDown())
        {
            Boxer *downed = (a->isDown())?a:b;
            Boxer *opponent = (a->isDown())?b:a;
            DownTick *downTick;
             ticks[curTick++] = downTick =  new DownTick(a, b, downLimit);
            //if (downTick.ko())
            {
                //ticks[curTick++] = new KOTick(a, b);
                //return;
            }
            if (downTick->tko)
            {
                ticks[curTick++] = new TKOTick(a,b);
                return true;
            }
            else
            {
                CountTick *ct = new CountTick(a, b, downed, opponent);
                ticks[curTick++] = ct;
                if(ct->ko())
                {
                    return true;
                }
                
            }
        }
        boxingTicks++;   
    }
    ticks[curTick++] = new IntervalTick(a, b);
    return false;
}
