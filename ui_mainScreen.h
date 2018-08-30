/********************************************************************************
** Form generated from reading UI file 'mainScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
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
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    boxerWidget *BoxerA;
    OptionsWidget *optionsPane;
    boxerWidget *BoxerB;
    QHBoxLayout *horizontalLayout_2;
    QLabel *imgLeft;
    RoundTabs *Test;
    QLabel *imgRight;

    void setupUi(QMainWindow *mainScreen)
    {
        if (mainScreen->objectName().isEmpty())
            mainScreen->setObjectName(QStringLiteral("mainScreen"));
        mainScreen->resize(1109, 800);
        mainScreen->setBaseSize(QSize(800, 800));
        mainScreen->setCursor(QCursor(Qt::ArrowCursor));
        centralwidget = new QWidget(mainScreen);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
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

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        imgLeft = new QLabel(centralwidget);
        imgLeft->setObjectName(QStringLiteral("imgLeft"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imgLeft->sizePolicy().hasHeightForWidth());
        imgLeft->setSizePolicy(sizePolicy);
        imgLeft->setFrameShape(QFrame::Panel);
        imgLeft->setFrameShadow(QFrame::Sunken);
        imgLeft->setLineWidth(3);
        imgLeft->setMidLineWidth(3);
        imgLeft->setScaledContents(true);

        horizontalLayout_2->addWidget(imgLeft);

        Test = new RoundTabs(centralwidget);
        Test->setObjectName(QStringLiteral("Test"));

        horizontalLayout_2->addWidget(Test);

        imgRight = new QLabel(centralwidget);
        imgRight->setObjectName(QStringLiteral("imgRight"));
        sizePolicy.setHeightForWidth(imgRight->sizePolicy().hasHeightForWidth());
        imgRight->setSizePolicy(sizePolicy);
        imgRight->setSizeIncrement(QSize(0, 0));
        imgRight->setFrameShape(QFrame::Panel);
        imgRight->setFrameShadow(QFrame::Sunken);
        imgRight->setLineWidth(3);
        imgRight->setMidLineWidth(3);
        imgRight->setScaledContents(true);

        horizontalLayout_2->addWidget(imgRight);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        mainScreen->setCentralWidget(centralwidget);

        retranslateUi(mainScreen);
        QObject::connect(optionsPane, SIGNAL(sendOptions(int,int,int,bool)), mainScreen, SLOT(startMatch(int,int,int,bool)));
        QObject::connect(Test, SIGNAL(setImages(string,string)), mainScreen, SLOT(setImages(string,string)));
        QObject::connect(mainScreen, SIGNAL(sendMatch(Match*,bool)), Test, SLOT(createRounds(Match*,bool)));
        QObject::connect(optionsPane, SIGNAL(sendFileName(QString)), mainScreen, SLOT(saveMatch(QString)));

        QMetaObject::connectSlotsByName(mainScreen);
    } // setupUi

    void retranslateUi(QMainWindow *mainScreen)
    {
        mainScreen->setWindowTitle(QApplication::translate("mainScreen", "LACEUP", nullptr));
        BoxerA->setTitle(QApplication::translate("mainScreen", "Left", nullptr));
        optionsPane->setTitle(QApplication::translate("mainScreen", "Options", nullptr));
        BoxerB->setTitle(QApplication::translate("mainScreen", "Right", nullptr));
        imgLeft->setText(QString());
        imgRight->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mainScreen: public Ui_mainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
