/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Match.h
 * Author: Dedster
 *
 * Created on May 20, 2018, 2:07 PM
 */

#ifndef MATCH_H
#define MATCH_H
#include "Boxer.h"
#include "Round.h"
#include "dedGame.h"
#include <stdio.h>
#include <string>

class Match {
public:
    Match();
    ~Match();
    Match(const Match& other);
    Match& operator=(const Match& other);
    Match(Boxer *boxers);
    void startMatch();
    void newRound(int roundNumber);
    void setBoxers(Boxer a, Boxer b){boxers[0] = a; boxers[1] = b;}
    int getNumRounds(){return curRound;}
    Round** getRounds(){return rounds;}

    /**
     Picks the two boxers to fight
     */
    void selectBoxer();
    
    /**
     Pits the two selected boxers against each other
     @param numRounds how many rounds
     @param downCount Number of downs until TKO
     @param roundTime How long each round will last, in ticks 
     */
    void startMatch(int numRounds, int downCount, int roundTime);
    
private:
    int curRound;
    int roundTime, downLimit, numRounds;
    Boxer boxers[2];
    Round **rounds;
    void clearRounds();
    
    //void printTime();
    void printStats();
    void throwPunch();
};

#endif /* MATCH_H */

