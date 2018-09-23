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
 * File:   GameTick.h
 * Author: Dedster
 *
 * Created on August 9, 2018, 7:44 PM
 */

#ifndef GAMETICK_H
#define GAMETICK_H
#include <string>
#include <iostream>
#include <QtCore/qstring.h>
#include <QtCore/qcoreapplication.h>
#include <QtMultimedia/qsoundeffect.h>

#include "Boxer.h"
/**
 * Basically anything that would pop into the list
 **/

class GameTick {
    Q_DECLARE_TR_FUNCTIONS(GameTick)
public:
    GameTick();
    virtual ~GameTick();
    virtual std::string toString();
    virtual QString toQString();
    virtual void playSound(QSoundEffect *qsfx);
    Boxer* getBoxers();
    QString localizeString(string str);
private:
    
protected:
    Boxer boxers[2];
};

#endif /* GAMETICK_H */

