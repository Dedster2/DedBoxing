/********************************************************************************
** Form generated from reading UI file 'roundTab.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUNDTAB_H
#define UI_ROUNDTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "boxerroundstats.h"

QT_BEGIN_NAMESPACE

class Ui_roundTab
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *list;
    QLabel *label;
    QHBoxLayout *layoutStats;
    boxerRoundStats *boxerStats1;
    boxerRoundStats *boxerStats2;
    QHBoxLayout *horizontalLayout;
    QPushButton *toggleAuto;
    QPushButton *pbSpoilerUnhide;
    QCheckBox *statScope;

    void setupUi(QWidget *roundTab)
    {
        if (roundTab->objectName().isEmpty())
            roundTab->setObjectName(QStringLiteral("roundTab"));
        roundTab->setWindowModality(Qt::WindowModal);
        roundTab->resize(801, 579);
        verticalLayout_2 = new QVBoxLayout(roundTab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        list = new QListWidget(roundTab);
        list->setObjectName(QStringLiteral("list"));

        verticalLayout->addWidget(list);

        label = new QLabel(roundTab);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        layoutStats = new QHBoxLayout();
        layoutStats->setObjectName(QStringLiteral("layoutStats"));
        boxerStats1 = new boxerRoundStats(roundTab);
        boxerStats1->setObjectName(QStringLiteral("boxerStats1"));

        layoutStats->addWidget(boxerStats1);

        boxerStats2 = new boxerRoundStats(roundTab);
        boxerStats2->setObjectName(QStringLiteral("boxerStats2"));

        layoutStats->addWidget(boxerStats2);


        verticalLayout->addLayout(layoutStats);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 4);

        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toggleAuto = new QPushButton(roundTab);
        toggleAuto->setObjectName(QStringLiteral("toggleAuto"));

        horizontalLayout->addWidget(toggleAuto);

        pbSpoilerUnhide = new QPushButton(roundTab);
        pbSpoilerUnhide->setObjectName(QStringLiteral("pbSpoilerUnhide"));

        horizontalLayout->addWidget(pbSpoilerUnhide);


        verticalLayout_2->addLayout(horizontalLayout);

        statScope = new QCheckBox(roundTab);
        statScope->setObjectName(QStringLiteral("statScope"));
        statScope->setLayoutDirection(Qt::LeftToRight);
        statScope->setAutoFillBackground(false);
        statScope->setTristate(false);

        verticalLayout_2->addWidget(statScope);


        retranslateUi(roundTab);
        QObject::connect(list, SIGNAL(currentRowChanged(int)), roundTab, SLOT(test(int)));
        QObject::connect(toggleAuto, SIGNAL(clicked()), roundTab, SLOT(toggleAuto()));
        QObject::connect(pbSpoilerUnhide, SIGNAL(clicked()), roundTab, SLOT(reveal()));
        QObject::connect(statScope, SIGNAL(stateChanged(int)), boxerStats1, SLOT(switchStats(int)));
        QObject::connect(statScope, SIGNAL(stateChanged(int)), boxerStats2, SLOT(switchStats(int)));

        QMetaObject::connectSlotsByName(roundTab);
    } // setupUi

    void retranslateUi(QWidget *roundTab)
    {
        roundTab->setWindowTitle(QApplication::translate("roundTab", "roundTab", nullptr));
        label->setText(QApplication::translate("roundTab", "Round 1", nullptr));
        toggleAuto->setText(QApplication::translate("roundTab", "Enable Autoplay", nullptr));
        pbSpoilerUnhide->setText(QApplication::translate("roundTab", "Reveal Round", nullptr));
        statScope->setText(QApplication::translate("roundTab", "Show stats since match start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class roundTab: public Ui_roundTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUNDTAB_H
