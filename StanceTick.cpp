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
 * File:   StanceTick.cpp
 * Author: Dedster
 * 
 * Created on August 25, 2018, 10:33 PM
 */

#include "StanceTick.h"
#include "Boxer.h"

StanceTick::StanceTick(Boxer* a, Boxer* b)
{
    a->setState("Stance");
    b->setState("Stance");
    boxers[0] = *a;
    boxers[1] = *b;
}


StanceTick::StanceTick(const StanceTick& orig)
{
}

StanceTick::~ StanceTick()
{
}

string StanceTick::toString()
{
    return boxers[0].getName() + ":"  + boxers[0].getHealth() + " " + boxers[1].getName() +
            ":" + boxers[1].getHealth();
}
