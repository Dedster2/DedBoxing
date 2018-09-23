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
#include "KOTick.h"
#include "PunchDrunkState.h"


Round::Round(int tickLength, int downLimit) : tickLength(tickLength), 
        downLimit(downLimit), curTick(0), ticks(new GameTick*[999999])
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
    int i = 5;
    while(boxingTicks < tickLength)
    {
        if(!(i < 5 && rand() % (i+1) == 0))
        {
            if (a->isDown() || b->isDown())
            {
                i = 5;
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
                        ticks[curTick++] = new KOTick(a,b, downed, opponent);
                        return true;
                    }
                }
            }
            ticks[curTick++] = new StanceTick(a, b);
            i = 1;
        }
        a->selectPunch();
        b->selectPunch();
        Boxer *thrower = (a->outSpeeds(*b))?a:b;
        Boxer *reciever = ((thrower != a)?a:b);
        bool wasHit = false;
        ticks[curTick++] = new PunchThrownTick(a, b, thrower);
        PunchReactTick *pr = new PunchReactTick(a, b, thrower, reciever);
        ticks[curTick++] = pr;
        wasHit = pr->wasHit();
        i++;
//        while(wasHit && i < 4 && rand() % (i + 1) == 0)
//        {
//            thrower->selectPunch();
//            ticks[curTick++] = (reciever->isDown())?
//                (new PunchDrunkTick(a, b, thrower)):
//                 (new PunchThrownTick(a, b, thrower));
//            PunchReactTick *pr = new PunchReactTick(a, b, thrower, reciever);
//            ticks[curTick++] = pr;
//            wasHit = pr->wasHit();
//        }
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

string Round::toString()
{
    string s("");
    for(int i = 0; i < curTick; i++)
    {
        s.append(ticks[i]->toString() + "\n");
    }
    GameTick *last = ticks[curTick - 1];
    for(int i = 0; i < 2; i++)
    {
        Boxer &cB = last->getBoxers()[i];
        s.append("\n" + cB.getName() + "\n");
        s.append("Punches Thrown :" + to_string(cB.getPunchThrown()) + "\n");
        s.append("Punches Landed :" + to_string(cB.getPunchLanded()) + "\n");
        s.append("Damage Taken: " + to_string(cB.getDamageTaken()) + "\n");
        s.append("Knock Downs: " + to_string(cB.getDowns()) + "\n");
        s.append("Punches Blocked:  " + to_string(cB.getBlocks()) + "\n");
        s.append("Health: " + cB.getHealth() +  "\n\n");
    }
    return s;
}
