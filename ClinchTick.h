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
 * File:   ClinchTick.h
 * Author: Dedster
 *
 * Created on August 13, 2018, 7:50 PM
 */

#ifndef CLINCHTICK_H
#define CLINCHTICK_H

#include "GameTick.h"
#include "Boxer.h"


class ClinchTick : public GameTick {
public:
    ClinchTick(Boxer *a, Boxer *b, Boxer *starter);
    string toString();
private:
    Boxer *starter;
};

#endif /* CLINCHTICK_H */

