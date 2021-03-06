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
 * File:   CountTick.cpp
 * Author: Dedster
 * 
 * Created on August 12, 2018, 5:18 PM
 */

#include "CountTick.h"


CountTick::CountTick(Boxer* a, Boxer* b, Boxer* down, Boxer* opp, int count)
{
    this->count = count;
    boxers[0] = *a;
    boxers[1] = *b;
}


string CountTick::toString()
{
    return to_string(count + 1);
}


