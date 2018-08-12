/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boxer.h
 * Author: Dedster
 *
 * Created on April 1, 2018, 4:59 PM
 */


#ifndef BOXER_H
#define BOXER_H
using namespace std;
#include <string.h>
#include "Punch.h"

class Boxer {
public:
    Boxer();
    bool loaded;
    bool hitStun;
    
    /**
     * Sets the stats to the input
     * @param str Strength
     * @param frt Fortitude
     * @param tch Technique
     * @param def Defense
     * @param name Name
     */
    void setStats(float str, float frt, float tch, float def, float speed,
        string name);
    
    
    
    /**
     * Saves the current boxer into the current Directory
     * Will be saved as name.bxr
     */
    void saveToFile();
    
    /**
     * Attempts to read a boxer from the current directory
     * @param name The name of the boxer attempted to load, sans the extension
     * @return True if successful, false otherwise
     */
    bool loadFromFile(string name);
    
    /**
     * Creates a new boxer, and saves it.
     */
    void createNew(string name);
    
    void throwPunch(Boxer* o);
    
    /** Returns true if rolls faster*/
    bool outSpeeds(Boxer o);
    
    bool hits(Boxer o);
    void takesDamage(int d);
    /**
     * Re-calculates stats.
     */
    void decay(int x);
    void printStats();
    void tempDamage(int damage);
    bool isDown();
    int down(Boxer* o);
    bool blocks(Boxer b);
    int calcDamage(Boxer b);
    void regen(float x);
    void regen();
    void recoverHalf();
    int getDowns(){return downs;}
    void interval(int x);
    int getPunchThrown(){return punchesThrown;}
    int getPunchLanded(){return punchesLanded;}
    int getDamageTaken(){return damageTaken;}
    int getHealthValue(){return stamina;}
    void selectPunch();
    Punch getPunch();
    
    string getHealth(){return "(" + to_string((int)stamina) + "/" + to_string(hp) + ")";}
    string getName(){return name;}

private:
    float strength, fort, tech, def, mStr, mFort, mTech, mDef, speed, mSpd,
            stamina, curDecay;
    
    int hp, maxStamina, numPunches, lastDamage, downs, totalDowns;
    int punchesLanded, punchesThrown, damageDealt, damageTaken;
    string name;
    Punch* punchList;
    Punch selectedPunch;
};

#endif /* BOXER_H */

