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
#include "ClinchTick.h"
#include "PunchReactTick.h"
#include "StanceTick.h"


Round::Round(int tickLength, int downLimit) : tickLength(tickLength), 
        downLimit(downLimit), curTick(0), ticks(new GameTick*[tickLength * 5])
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
        ticks[curTick++] = new StanceTick(a, b);
        if((a->clinchReq() && rand() % 100 < 20) 
            ||(b->clinchReq() && rand() % 100 < 20) )
        {
            Boxer* low = (a->getHealthValue() < b->getHealthValue())?a:b;
            ticks[curTick++] = new ClinchTick(a, b, low);
        }
        else
        {
            a->selectPunch();
            b->selectPunch();
            Boxer *thrower = (a->outSpeeds(*b))?a:b;
            Boxer *reciever = ((thrower != a)?a:b);
            ticks[curTick++] = new PunchThrownTick(a, b, thrower);
            ticks[curTick++] = new PunchReactTick(a, b, thrower, reciever);
        }
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
        a->regen();
        b->regen();
        boxingTicks++;   
    }
    ticks[curTick++] = new IntervalTick(a, b);
    return false;
}

Round::~ Round()
{
    for (int i = 0; i < curTick; i++)
        delete ticks[i];
    delete[] ticks;
}
