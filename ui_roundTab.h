/********************************************************************************
** Form generated from reading UI file 'roundTab.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUNDTAB_H
#define UI_ROUNDTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "boxerroundstats.h"

QT_BEGIN_NAMESPACE

class Ui_roundTab
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *list;
    QLabel *label;
    QHBoxLayout *layoutStats;
    boxerRoundStats *boxerStats1;
    boxerRoundStats *boxerStats2;

    void setupUi(QWidget *roundTab)
    {
        if (roundTab->objectName().isEmpty())
            roundTab->setObjectName(QStringLiteral("roundTab"));
        roundTab->setWindowModality(Qt::WindowModal);
        roundTab->resize(719, 579);
        horizontalLayout_2 = new QHBoxLayout(roundTab);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
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

        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(roundTab);
        QObject::connect(list, SIGNAL(currentRowChanged(int)), roundTab, SLOT(test(int)));

        QMetaObject::connectSlotsByName(roundTab);
    } // setupUi

    void retranslateUi(QWidget *roundTab)
    {
        roundTab->setWindowTitle(QApplication::translate("roundTab", "roundTab", nullptr));
        label->setText(QApplication::translate("roundTab", "Round 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class roundTab: public Ui_roundTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUNDTAB_H
