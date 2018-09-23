/*
 * Copyright (C) 2018 alper_000
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
 * File:   KOTick.cpp
 * Author: alper_000
 * 
 * Created on September 3, 2018, 7:34 PM
 */

#include "KOTick.h"


KOTick::KOTick(Boxer* a, Boxer* b, Boxer* downed, Boxer* opponent)
{
    downed->setState("KO:Downed");
    opponent->setState("WinKO:Win:ObserveDowned");
    boxers[0] = *a;
    boxers[1] = *b;
    winner = *opponent;
    loser = *downed;
}


KOTick::KOTick(const KOTick& orig)
{
}

KOTick::~ KOTick()
{
}

string KOTick::toString()
{
    return loser.getName() + " was knocked out by " + winner.getName() + "'s " +
            winner.getPunch().getFullName() + ".";
}
