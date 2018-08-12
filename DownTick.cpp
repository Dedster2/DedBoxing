/*
 * Copyright (C) 2018 Dedster
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   DownTick.cpp
 * Author: Dedster
 * 
 * Created on August 12, 2018, 1:33 PM
 */

#include "DownTick.h"
#include "Boxer.h"

DownTick::DownTick(Boxer *a, Boxer *b, int downLimit)
{
    Boxer *downed = (a->isDown())?a:b;
    Boxer *opponent = (a->isDown())?b:a;
    if(downed->getDowns() + 1 >= downLimit)
    {
        tko = true;       
    }
        downedCopy = *downed;
        boxers[0] = *a;
        boxers[1] = *b;
    
}

string DownTick::toString()
{
    cout << downedCopy.getName();
    string s = downedCopy.getName() + " DOWN";
    return s;
}

