/********************************************************************************
** Form generated from reading UI file 'OptionsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSWIDGET_H
#define UI_OPTIONSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *sbRounds;
    QLabel *label_2;
    QSpinBox *sbDown;
    QLabel *label_3;
    QSpinBox *sbLength;
    QCheckBox *chkSpoilers;
    QLabel *label_4;
    QCheckBox *chkSounds;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QPushButton *pbSaveTxt;

    void setupUi(QWidget *OptionsWidget)
    {
        if (OptionsWidget->objectName().isEmpty())
            OptionsWidget->setObjectName(QStringLiteral("OptionsWidget"));
        OptionsWidget->resize(576, 300);
        verticalLayout = new QVBoxLayout(OptionsWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(OptionsWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setBaseSize(QSize(3, 0));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        sbRounds = new QSpinBox(OptionsWidget);
        sbRounds->setObjectName(QStringLiteral("sbRounds"));
        sbRounds->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbRounds->setMinimum(1);
        sbRounds->setValue(12);
        sbRounds->setDisplayIntegerBase(10);

        formLayout->setWidget(0, QFormLayout::FieldRole, sbRounds);

        label_2 = new QLabel(OptionsWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        sbDown = new QSpinBox(OptionsWidget);
        sbDown->setObjectName(QStringLiteral("sbDown"));
        sbDown->setMinimum(1);
        sbDown->setValue(3);

        formLayout->setWidget(1, QFormLayout::FieldRole, sbDown);

        label_3 = new QLabel(OptionsWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        sbLength = new QSpinBox(OptionsWidget);
        sbLength->setObjectName(QStringLiteral("sbLength"));
        sbLength->setMinimum(1);
        sbLength->setMaximum(999);
        sbLength->setValue(36);

        formLayout->setWidget(2, QFormLayout::FieldRole, sbLength);

        chkSpoilers = new QCheckBox(OptionsWidget);
        chkSpoilers->setObjectName(QStringLiteral("chkSpoilers"));
        chkSpoilers->setBaseSize(QSize(0, 0));
        chkSpoilers->setChecked(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, chkSpoilers);

        label_4 = new QLabel(OptionsWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        chkSounds = new QCheckBox(OptionsWidget);
        chkSounds->setObjectName(QStringLiteral("chkSounds"));
        chkSounds->setChecked(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, chkSounds);

        label_5 = new QLabel(OptionsWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        startButton = new QPushButton(OptionsWidget);
        startButton->setObjectName(QStringLiteral("startButton"));

        horizontalLayout->addWidget(startButton);

        pbSaveTxt = new QPushButton(OptionsWidget);
        pbSaveTxt->setObjectName(QStringLiteral("pbSaveTxt"));
        pbSaveTxt->setEnabled(false);

        horizontalLayout->addWidget(pbSaveTxt);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(OptionsWidget);
        QObject::connect(startButton, SIGNAL(clicked()), OptionsWidget, SLOT(startClicked()));
        QObject::connect(pbSaveTxt, SIGNAL(clicked()), OptionsWidget, SLOT(saveClicked()));

        QMetaObject::connectSlotsByName(OptionsWidget);
    } // setupUi

    void retranslateUi(QWidget *OptionsWidget)
    {
        OptionsWidget->setWindowTitle(QApplication::translate("OptionsWidget", "Form", nullptr));
        label->setText(QApplication::translate("OptionsWidget", "Rounds", nullptr));
        sbRounds->setSuffix(QString());
        label_2->setText(QApplication::translate("OptionsWidget", "Down Limit", nullptr));
        label_3->setText(QApplication::translate("OptionsWidget", "Round Length", nullptr));
        chkSpoilers->setText(QString());
        label_4->setText(QApplication::translate("OptionsWidget", "Spoilers", nullptr));
        chkSounds->setText(QString());
        label_5->setText(QApplication::translate("OptionsWidget", "Sounds", nullptr));
        startButton->setText(QApplication::translate("OptionsWidget", "Start Match", nullptr));
        pbSaveTxt->setText(QApplication::translate("OptionsWidget", "Save Match to .txt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionsWidget: public Ui_OptionsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSWIDGET_H
