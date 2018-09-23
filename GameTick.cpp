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
 * File:   GameTick.cpp
 * Author: Dedster
 * 
 * Created on August 9, 2018, 7:44 PM
 */

#include <QtCore/qcoreapplication.h>

#include "GameTick.h"

GameTick::GameTick()
{
}

std::string GameTick::toString()
{
}

Boxer* GameTick::getBoxers()
{
    return boxers;
}

GameTick::~ GameTick()
{
}

QString GameTick::toQString()
{
    return tr("");
}

QString GameTick::localizeString(string str)
{
    if(str == "Jab")
        return tr("Jab");
    if(str == "Hook")
        return tr("Hook");
    if(str == "Straight")
        return tr("Straight");
    if(str == "Upper")
        return tr("Upper");
    if(str == "Left")
        return tr("Left");
    if(str == "Right")
        return tr("Right");
    if(str == "Head")
        return tr("Head");
    if(str == "Torso")
        return tr("Torso");
    if(str == "Stomach")
        return tr("Stomach");
    return tr("Unknown string");
}

void GameTick::playSound(QSoundEffect *qsfx)
{
}
