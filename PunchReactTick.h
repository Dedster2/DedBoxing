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
 * File:   PunchReactTick.h
 * Author: Dedster
 *
 * Created on August 25, 2018, 9:15 PM
 */

#ifndef PUNCHREACTTICK_H
#define PUNCHREACTTICK_H

#include "Boxer.h"
#include "GameTick.h"


class PunchReactTick : public GameTick {
public:
    PunchReactTick(Boxer *a, Boxer *b, Boxer *thrower, Boxer *reciever);
    PunchReactTick(const PunchReactTick& orig);
    string toString();
    virtual ~PunchReactTick();
private:
    int blockDodgeFlag;
    float damageTaken;
    Boxer reciever;

};

#endif /* PUNCHREACTTICK_H */

