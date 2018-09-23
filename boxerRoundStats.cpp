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
    scope = 0;
}

void boxerRoundStats::update(Boxer b)
{
    this->b = b;
    int stats[6];
    b.getRoundStats(stats, scope);

            widget.leDamageTake->setText
        (QString::fromStdString(to_string(stats[0])));

            widget.lePunchLand->setText
        (QString::fromStdString(to_string(stats[1])));

            widget.lePunchThrown->setText
        (QString::fromStdString(to_string(stats[2])));

            widget.leDowns->setText
        (QString::fromStdString(to_string(stats[3])));
            widget.leBlocked->setText
        (QString::fromStdString(to_string(stats[4])));
            widget.pbHealth->setValue(max(0,stats[5]));
    //widget.stats->update(b);
}



boxerRoundStats::~ boxerRoundStats()
{
}

void boxerRoundStats::switchStats(int id)
{
    scope = id;
    update(b);
}

void boxerRoundStats::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        widget.retranslateUi(this);
    } else
        QWidget::changeEvent(event);
}