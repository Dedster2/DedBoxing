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
 * File:   PunchReactTick.cpp
 * Author: Dedster
 * 
 * Created on August 25, 2018, 9:15 PM
 */

#include "PunchReactTick.h"

PunchReactTick::PunchReactTick(Boxer *a, Boxer *b, Boxer* thrower, Boxer* reciever)
{
    Punch punchThrown = thrower->getPunch();
    string side = thrower->getPunch().getSide(), bodyPart = thrower->getPunch().getBodyPart();
    damageTaken = thrower->calcDamage(*reciever);
    damageTaken *= .75;
    if (!thrower->hits(*reciever))
    {
        blockDodgeFlag = 2;
        damageTaken = 0;
        reciever->setState("Dodge");
    }
    else if (reciever->blocks(*thrower))
    {
        blockDodgeFlag = 1;
        damageTaken /= 2;
        reciever->tempDamage(damageTaken);
        reciever->setState("Block");
    }
    else
    {
        blockDodgeFlag = 0;
        reciever->takesDamage(damageTaken);
        string t = side + bodyPart + punchThrown.getName() + "Hit:" + bodyPart + punchThrown.getName() + "Hit:" + 
        side + punchThrown.getName() + "Hit:" + bodyPart +  "Hit:" + punchThrown.getName()  + "Hit:Hit"; 
        reciever->setState(t);
    }
    boxers[0] = *a;
    boxers[1] = *b;
    this->reciever = *reciever;
}

string PunchReactTick::toString()
{
    string out  = reciever.getName();
    switch(blockDodgeFlag)
    {
        case 0:
            out.append(" takes " + to_string(damageTaken) + " damage.");
            break;
        case 1:
            out.append(" blocks it for " + to_string(damageTaken)
                    + " damage.");
            break;
        case 2:
            out.append(" dodges it");
            break;
    }
    return out;
    
}

PunchReactTick::PunchReactTick(const PunchReactTick& orig)
{
}

PunchReactTick::~ PunchReactTick()
{
}

