/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Punch.cpp
 * Author: Dedster
 * 
 * Created on April 1, 2018, 5:22 PM
 */

#include <string>

#include "Punch.h"

string Punch::bodyPartList[] = {"Head", "Torso", "Stomach"};
string Punch::sides[] =  {"Left", "Right"};

Punch::Punch()
{
}


void Punch::randomize()
{
    bodyPart = bodyPartList[rand() % 3];
    side = sides[rand() % 2];
}



