/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Punch.h
 * Author: Dedster
 *
 * Created on April 1, 2018, 5:22 PM
 */

#ifndef PUNCH_H
#define PUNCH_H

#include <string>
#include <cstring>


using namespace std;
class Punch
{
    float acc;
    int power, cost;
    char name[255];
    string side, bodyPart;
public:
    static string bodyPartList[3];
    static string sides[2];
    /**
     @param acc Accuracy
     @param power How much damage it'll do (on average)
     @param cost How much stamina it will cost
     @param name Name of the punch, as it will be displayed
     */ 
    Punch(float acc, int power, int cost, string name): acc(acc),
            power(power), cost(cost){strcpy(this->name, name.c_str());}

    Punch();;
    int getCost(){return cost;}
    int getPower(){return power;}
    string getSide(){return side;}
    string getBodyPart(){return bodyPart;}
    void setSide(string side){this->side = side;}
    void setBodyPart(string bodyPart){this->bodyPart = bodyPart;}
    void randomize();
    float getAcc(){return acc;}
    string getName(){return name;}
    
};



#endif /* PUNCH_H */

