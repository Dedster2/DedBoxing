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
    this->boxers = new Boxer[2];
    //seconds = 0;
    roundTime = 300;
    downLimit = 5;
    numRounds = 12;
}
Match::Match(Boxer* boxers)
{
    //seconds = 0;
    roundTime = 36;
    downLimit = 5;
    numRounds = 12;
    this->boxers = boxers;
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
    this->numRounds = numRounds;
    this->downLimit = downCount;
    this->roundTime = roundTime;
    startMatch();
    cout << "Now leaving\n";
}

void Match::startMatch(){
    cout << "Starting match between " << boxers[0].getName() << " and "
            << boxers[1].getName()<<endl;
    
    for (int i = 0; i < 2; i++)
    {
        boxers[i].printStats();
    }
    bool over = false;
    float healthRecov = 15;
    float factor = .50;
    rounds = new Round[numRounds];
    for(int i = 0; i < numRounds && !over; i++)
    {
        curRound = i + 1;
        rounds[i] = *(new Round(roundTime, downLimit));
        cout<< "ROUND " << i + 1 << "!\nKAN\nFIGHT!\n";
        if(rounds[i].createRound(&boxers[0], &boxers[1]))
            break;
    }
    cout << "Now leaving match\n";
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

