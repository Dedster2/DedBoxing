/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Match.cpp
 * Author: Dedster
 * 
 * Created on May 20, 2018, 2:07 PM
 */

#include "Match.h"
#include "dedGame.h"
#include "mainScreen.h"
#include "Round.h"
#include <array>

using namespace std;
Match::Match() {
    //seconds = 0;
    roundTime = 300;
    downLimit = 5;
    numRounds = 12;
    curRound = 0;
}
Match::Match(Boxer* boxers)
{
    //seconds = 0;
    roundTime = 36;
    downLimit = 5;
    numRounds = 12;
    curRound = 0;
    this->boxers[0] = boxers[0];
    this->boxers[1] = boxers[1];
}




void Match::selectBoxer(){
    string s;
    for(int i = 0; i < 2; i++)
    {
        while (true)
        {
            cout << "Enter the name of Boxer " << i + 1 << "." << endl;
            cin >> s;
            if(boxers[i].loadFromFile(s))
                break;
            if (confirmMessage(s + ".bxr not found. Create?"))
            {
                boxers[i].createNew(s);
                break;
            }
        }
    }
}

void Match::startMatch(int numRounds, int downCount, int roundTime)
{
    clearRounds();
    this->numRounds = numRounds;
    this->downLimit = downCount;
    this->roundTime = roundTime;
    startMatch();
}

void Match::startMatch(){
    bool over = false;
    rounds = new Round*[numRounds];
    for(int i = 0; i < numRounds && !over; i++)
    {
        curRound = i + 1;
        rounds[i] = new Round(roundTime, downLimit);
        if(rounds[i]->createRound(&boxers[0], &boxers[1]))
            break;
    }
}

void Match::throwPunch()
{
    for(int i = 0; i <2; i++)
    {
        boxers[i].selectPunch();
    }
    if(boxers[0].outSpeeds(boxers[1]))
        boxers[0].throwPunch(&boxers[1]);
    else
        boxers[1].throwPunch(&boxers[0]);
}

void Match::printStats()
{
    for(int i = 0; i < 2; i++)
    {
        boxers[i].printStats();
        cout << endl;
    }
}

Match::~ Match()
{
    for(int i = 0; i < curRound; i++)
        delete rounds[i];
    delete[] rounds;
}

Match::Match(const Match& other)
{
//    for(int i = 0; i < curRound; i++)
//        delete rounds[i];
//    delete[] rounds;
//    numRounds = other.numRounds;
//    this->downLimit = other.downLimit;
//    this->roundTime = other.roundTime;
//    boxers[0] = other.boxers[0];
//    boxers[1] = other.boxers[1];
}

Match& Match::operator=(const Match& other)
{

}

void Match::clearRounds()
{
    if (curRound != 0)
    {
        for(int i = 0; i < curRound; i++)
            delete rounds[i];
      delete[] rounds;
    }
}

string Match::toString()
{
    string out = "Rounds: ";
    out.append(to_string(curRound));
    out.append("\n");
    out.append(boxers[0].getName() + " VS " + boxers[1].getName() + "\n");
    out.append(rounds[0]->getTick(0)->getBoxers()[0].printStats() + "\n");
    out.append(rounds[0]->getTick(0)->getBoxers()[1].printStats() + "\n");
    for(int i = 0; i < curRound; i++)
    {
        out.append("ROUND " + to_string(i + 1) + "\n");
        out.append(rounds[i]->toString());
    }
    return out;
    
}
