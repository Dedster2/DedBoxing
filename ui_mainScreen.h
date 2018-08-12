/********************************************************************************
** Form generated from reading UI file 'mainScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "boxerWidget.h"
#include "optionswidget.h"
#include "roundtabs.h"

QT_BEGIN_NAMESPACE

class Ui_mainScreen
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    boxerWidget *BoxerA;
    OptionsWidget *optionsPane;
    boxerWidget *BoxerB;
    RoundTabs *Test;

    void setupUi(QMainWindow *mainScreen)
    {
        if (mainScreen->objectName().isEmpty())
            mainScreen->setObjectName(QStringLiteral("mainScreen"));
        mainScreen->resize(800, 800);
        mainScreen->setBaseSize(QSize(800, 800));
        mainScreen->setCursor(QCursor(Qt::ArrowCursor));
        centralwidget = new QWidget(mainScreen);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        BoxerA = new boxerWidget(centralwidget);
        BoxerA->setObjectName(QStringLiteral("BoxerA"));

        horizontalLayout->addWidget(BoxerA);

        optionsPane = new OptionsWidget(centralwidget);
        optionsPane->setObjectName(QStringLiteral("optionsPane"));

        horizontalLayout->addWidget(optionsPane);

        BoxerB = new boxerWidget(centralwidget);
        BoxerB->setObjectName(QStringLiteral("BoxerB"));

        horizontalLayout->addWidget(BoxerB);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        Test = new RoundTabs(centralwidget);
        Test->setObjectName(QStringLiteral("Test"));

        verticalLayout->addWidget(Test);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 2);

        horizontalLayout_2->addLayout(verticalLayout);

        mainScreen->setCentralWidget(centralwidget);

        retranslateUi(mainScreen);
        QObject::connect(optionsPane, SIGNAL(sendOptions(int,int,int)), mainScreen, SLOT(startMatch(int,int,int)));
        QObject::connect(mainScreen, SIGNAL(sendMatch(Match)), Test, SLOT(createRounds(Match)));

        QMetaObject::connectSlotsByName(mainScreen);
    } // setupUi

    void retranslateUi(QMainWindow *mainScreen)
    {
        mainScreen->setWindowTitle(QApplication::translate("mainScreen", "DedBoxing", nullptr));
        BoxerA->setTitle(QApplication::translate("mainScreen", "Left", nullptr));
        optionsPane->setTitle(QApplication::translate("mainScreen", "Options", nullptr));
        BoxerB->setTitle(QApplication::translate("mainScreen", "Right", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainScreen: public Ui_mainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
