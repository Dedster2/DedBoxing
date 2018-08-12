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
 * File:   TKOTick.h
 * Author: Dedster
 *
 * Created on August 12, 2018, 3:29 PM
 */

#ifndef TKOTICK_H
#define TKOTICK_H

#include "GameTick.h"


class TKOTick: public GameTick{
public:
    TKOTick(Boxer *a, Boxer *b);
    std::string toString();

private:
    Boxer tkoee;
};

#endif /* TKOTICK_H */

