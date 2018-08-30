/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boxer.cpp
 * Author: Dedster
 * 
 * Created on April 1, 2018, 4:59 PM
 */

#include "Boxer.h"
#include "dedGame.h"
#include "Punch.h"
#include <fstream>
#include <string.h>
#include <cstring>
#include <math.h>
#define DECAYRATE  0.997127

Boxer::Boxer() {
    hp = 100;
    stamina = 100;
    maxStamina = 100;
    downs = 0;
    curDecay = 0;
    totalDowns = 0;
    punchesLanded = punchesThrown = damageDealt = damageTaken = numBlocks = 0;
    numPunches = 4;
    punchList[0] = Punch(.9, 2, 1, "Jab");
    punchList[1] = Punch(.75, 4, 2, "Straight");
    punchList[2] = Punch(.5, 8, 3, "Upper");
    punchList[3] = Punch(.65, 6, 2, "Hook");
    setState("Null");
}



void Boxer::setStats(float str, float frt, float tch, float def, float speed,
        string name)
{
    mStr = strength = str;
    mFort = fort = frt;
    mTech = tech = tch;
    mDef = this->def = def;
    mSpd = this->speed = speed;
    this->name = name;
}

void Boxer::saveToFile()
{
    string fileName = name + ".bxr";
    ofstream outFile((fileName).c_str(), ios::binary);
    outFile.write((char*) &strength, sizeof(float));
    outFile.write((char*) &fort, sizeof(float));
    outFile.write((char*) &tech, sizeof(float));
    outFile.write((char*) &def, sizeof(float));
    outFile.write((char*) &speed, sizeof(float));
    outFile.write((char*) &numPunches, sizeof(int));
    for(int i = 0; i < numPunches; i++)
        outFile.write((char*) &punchList[i], sizeof(Punch));
}

bool Boxer::loadFromFile(string name)
{
    float st, ft, tc, df, sp;
    int n;
    string fileName = name + ".bxr";
    ifstream boxerFile;
    boxerFile.open(fileName.c_str(), ios::binary);
    if(!boxerFile.is_open())
            return false;
        boxerFile.read((char*) &st, sizeof(float));
        boxerFile.read((char*) &ft, sizeof(float));
        boxerFile.read((char*) &tc, sizeof(float));
        boxerFile.read((char*) &df, sizeof(float));
        boxerFile.read((char*) &sp, sizeof(float));
        boxerFile.read((char*) &n, sizeof(int));
        cout << name + " found with following stats:" << endl
                << "Strength: " << st << endl
                << "Fortitude: " << ft << endl
                << "Technique: " << tc << endl
                << "Defense: " << df << endl
                << "Speed: " << sp << endl
                << "Number of Punches: " << n << endl;
        if(confirmMessage("Load boxer?: "))
        {
            
//            punchList = new Punch[n];
//            for (int i = 0; i < n; i++)
//            {
//                boxerFile.read((char*) &punchList[i], sizeof(Punch));
//            }
            
            punchList[0] = Punch(.9, 1, 1, "Jab");
            punchList[1] = Punch(.75, 3, 2, "Straight");
            punchList[2] = Punch(.5, 5, 6, "Upper");
            punchList[3] = Punch (.7, 4, 4, "Hook");
            setStats(st,ft,tc,df,sp, name);
            numPunches = 4;
            boxerFile.close();
            return true;
        }
        boxerFile.close();
        return false;
}

void Boxer::createNew(string name)
{
    this->name = name;
    cout << "Strength?" << endl;
    cin >> strength;
    cout << "Fortitude?" << endl;
    cin >> fort;
    cout << "Technique?" << endl;
    cin >> tech;
    cout << "Defense?" << endl;
    cin >> def;
    cout << "Speed?" << endl;
    cin >> speed;
    mStr = strength;
    mFort = fort;
    mTech = tech;
    mDef = this->def;
    mSpd = this->speed;
    /**
     * 
     
    cout  << "How many punches?" << endl;
    cin << n;
     **/

    this->saveToFile();
            /**
     * for(int i = 0; i < n; i++)
    {
        punchList[i] = Boxer();
    }
    **/
        
}

void Boxer::throwPunch(Boxer* o) {
    Punch p = selectedPunch;
    if (p.getCost() >= stamina)
    {
        cout << name << " takes a moment to breath" << endl;
        stamina +=1;
        o->throwPunch(this);
        return;
    }
    cout << name << " throws a " << p.getName() << " at " << o->getName() 
            << endl;
    if(!succeedsRoll(tech, o->speed))
    {
        cout << o->name << " dodges it." << endl;
        float miss = o->hp - o->stamina;
        o->stamina = min((float) o->hp, o->stamina +(o->hp/10));
        o->regen();
        return;
    }
    
    int damage = p.getPower() * getMult(strength, o->fort);
//   decay(p.getCost());
  //  damage *= 1.5;
    float mult = (rand() % 1500 / 1000.0) + .5;
    damage *= mult;
    damage = max(damage, 1);

    if(!hits(*o))
    {
        cout << o->name << " blocks it and takes " << damage / 2 << " damage." 
                <<endl;
        o->stamina -= damage / 2;
        return;
    }
    cout << o->name << " takes " << damage << " damage. ( x" << mult << " )" << endl;
    o->takesDamage(damage);
}

bool Boxer::outSpeeds(Boxer o)
{
    return succeedsRoll(speed * selectedPunch.getAcc(), 
            o.speed * o.selectedPunch.getAcc() );
}


bool Boxer::hits(Boxer o)
{
    punchesThrown++;
    if (succeedsRoll(tech * selectedPunch.getAcc(), o.speed / 2.0))
    {
        punchesLanded++;
        return true;
    }
    return false;
}

string Boxer::printStats()
{
    int i = 0;
    stringstream s;
    
    //This is for standard 3 kd rules, but since I made them customizable
//    for (i = 0; i < 3 && i < downs; i++)
//    {
//        s.append("X");
//    }
//    for(i; i < 3; i++)
//        s.append("O");
    
    s << "Downs: " << downs << "(" << totalDowns << ") | " << name
            << ": " << (int)stamina << " / "<< (int)hp << endl << "Strength: "
            << strength << " Defense: "<< fort << " Hit:" << tech 
            << " Block: " << def << " Speed: "
            << speed << " " <<endl;
    return s.str();
}

void Boxer::takesDamage(float d)
{
    damageTaken += d;
    hp = max(0.0, hp - d + 0.0);
    stamina -= 5 * d;
    decay(d);
}

void Boxer::decay(int x)
{
//    float ratio =  pow(0.997127, 100-hp); //currently set to 75% at 0 hp.
//    curDecay = ratio;
    curDecay = 100 - stamina;
    float ratio = pow(DECAYRATE, curDecay);
            
    strength = max(1, (int) (mStr * ratio));
    fort = max(1, (int) (mFort * ratio));
    tech = max(1, (int) (mTech * ratio));
    def = max(1, (int) (mDef * ratio));
    speed = max(1, (int) (mSpd * ratio));
    
}
bool Boxer::isDown()
{
    return stamina <= 0;
}

int Boxer::down(Boxer* o)
{
    downs++;
    totalDowns++;
    int i;
    int curHealed = 0;
    int target = max(3, 7 - hp / 10) + stamina / -15;
    if (hp <= 1)
        target = 999999;
    for (i = 0; i < 10 && curHealed < target; i++)
    {
        curHealed++;
    }
    if (i == 10)
    {
        return 10;
    }
    stamina = 0;
    stamina = hp;
    o->recoverHalf();
    return i;
}



void Boxer::regen()
{
    stamina = min(stamina + 2.0, hp + 0.0);
    float ratio = pow(DECAYRATE, curDecay);
            
    strength = max(1, (int) (mStr * ratio));
    fort = max(1, (int) (mFort * ratio));
    tech = max(1, (int) (mTech * ratio));
    def = max(1, (int) (mDef * ratio));
    speed = max(1, (int) (mSpd * ratio));
}

void Boxer::regen(float x)
{
    //hp = min(hp + x / 5 + 0.0, 100.0);
    stamina = min(stamina + 0.0 + x, hp + 0.0);
}


void Boxer::recoverHalf()
{
   // hp= min(100, hp + 5);
    int missing = hp - stamina;
    stamina += missing / 2;
}

void Boxer::interval(int x)
{
   // hp = min(100, hp + (hp) / 10);
    //stamina = hp;
    min(100.0, hp * 1.0 + x);
    stamina = hp;
    curDecay *= -0.007 * hp + .95;
    downs = punchesLanded = punchesThrown = damageDealt = damageTaken = numBlocks = 0;
}

void Boxer::selectPunch()
{
    selectedPunch = punchList[rand() % numPunches];
    selectedPunch.randomize();
}

Punch Boxer::getPunch()
{
    return selectedPunch;
}

float Boxer::calcDamage(Boxer b)
{
    float damage = selectedPunch.getPower() * getMult(strength, b.fort);
    float mult = (rand() % 1500 / 1000.0) + .5;
    damage *= mult;
    damage = max(damage, (float)1);
    return damage;
}

bool Boxer::blocks(Boxer b)
{
    if(!succeedsRoll(b.tech * b.selectedPunch.getAcc(), def))
    {
        numBlocks++;
        return true;
    }
    return false;
}

void Boxer::tempDamage(float damage)
{
    damageTaken += damage;
    stamina-= damage * 4;
}

bool Boxer::clinchReq()
{
    return false;
}

void Boxer::getStats(int *stats)
{
    stats[0] = strength;
    stats[1] = fort;
    stats[2] = tech;
    stats[3] = def;
    stats[4] = speed;
}

