/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   boxerRoundStats.cpp
 * Author: Dedster
 *
 * Created on August 1, 2018, 9:29 PM
 */

#include <QtCore/qstring.h>

#include "boxerRoundStats.h"

boxerRoundStats::boxerRoundStats(QWidget *parent):QWidget(parent)
{
    widget.setupUi(this);
}

void boxerRoundStats::update(Boxer b)
{
    widget.leDamageTake->setText
    (QString::fromStdString(to_string(b.getDamageTaken())));
    
    widget.lePunchLand->setText
    (QString::fromStdString(to_string(b.getPunchLanded())));
    
    widget.lePunchThrown->setText
    (QString::fromStdString(to_string(b.getPunchThrown())));
    
    widget.leDowns->setText
    (QString::fromStdString(to_string(b.getDowns())));
    widget.leBlocked->setText
    (QString::fromStdString(to_string(b.getBlocks())));
    int health = max(0, b.getHealthValue());
    widget.pbHealth->setValue(health);
    //widget.stats->update(b);
}



boxerRoundStats::~ boxerRoundStats()
{
}
