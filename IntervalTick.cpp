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
 * File:   IntervalTick.cpp
 * Author: Dedster
 * 
 * Created on August 12, 2018, 3:56 PM
 */

#include "IntervalTick.h"
#include "Boxer.h"
#include "dedGame.h"


IntervalTick::IntervalTick(Boxer* a, Boxer* b)
{
    a->setState("Corner");
    b->setState("Corner");
    boxers[0] = *a;
    boxers[1] = *b;
    a->interval(5);
    b->interval(5);
}

string IntervalTick::toString()
{
    return "KAN";
}

void IntervalTick::playSound(QSoundEffect *qsfx)
{
    playSoundFromString(sfx, "bell.wav");
}


QSoundEffect* IntervalTick::sfx = new QSoundEffect();