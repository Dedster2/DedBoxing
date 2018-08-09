/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Round.h
 * Author: Dedster
 *
 * Created on July 15, 2018, 12:38 PM
 */

#ifndef ROUND_H
#define ROUND_H

#include "BoxingTick.h"


class Round {
public:
    Round(int tickLength);
    Round(){}

    /**
     * Appends the current tick to the round
     * @param tick Tick to be added to the current end of the round
     * @returns True if no more ticks can be added to this round
     */
    bool logTick(BoxingTick tick);
    /**
     * Checks if the match should end due to (t)ko.
     * @param limit The number of downs needed for a TKO.
     * @return True if TKO'd or KO'd. False otherwise.
     */
    bool checkDowns(int limit);
    void printRound();
    void createTick(Boxer *a, Boxer *b);
    int getRoundLength(){return curTick;}
    BoxingTick getTick(int n){return ticks[n];}
    Boxer *getBoxers(); //todo:get boxers from the last tick
private:
    int tickLength, curTick;
    int numDowns();
    
    int down(Boxer bx);
    BoxingTick *ticks;
    
    
};

#endif /* ROUND_H */

