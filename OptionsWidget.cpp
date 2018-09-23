/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OptionsWidget.cpp
 * Author: Dedster
 * 
 * Created on July 8, 2018, 8:54 PM
 */

#include "OptionsWidget.h"

OptionsWidget::OptionsWidget(QWidget* parent): QGroupBox(parent)
{
    widget.setupUi(this);
    setTitle("Options");
    connect(widget.chkSounds, &QCheckBox::toggled, this, &toggleSound);
};

void OptionsWidget::startClicked()
{
    
    emit sendOptions(widget.sbRounds->value(), widget.sbDown->value(), 
            widget.sbLength->value(), widget.chkSpoilers->isChecked());
    widget.pbSaveTxt->setEnabled(true);
}

void OptionsWidget::saveClicked()
{
    QString fName = QFileDialog::getSaveFileName(this, tr("Save Match"), "", "Matches (*.txt)");
    emit sendFileName(fName);
}


void OptionsWidget::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::LanguageChange) {
        widget.retranslateUi(this);
    } else
        QWidget::changeEvent(event);
}

