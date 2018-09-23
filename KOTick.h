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
 * File:   KOTick.h
 * Author: alper_000
 *
 * Created on September 3, 2018, 7:34 PM
 */

#ifndef KOTICK_H
#define KOTICK_H

#include "GameTick.h"


class KOTick : public GameTick{
public:
    KOTick(Boxer *a, Boxer *b, Boxer *downed, Boxer *opponent);
    KOTick(const KOTick& orig);
    virtual ~KOTick();
    string toString();
private:
    Boxer winner, loser;
};

#endif /* KOTICK_H */

