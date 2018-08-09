/********************************************************************************
** Form generated from reading UI file 'OptionsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSWIDGET_H
#define UI_OPTIONSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *sbRounds;
    QLabel *label_2;
    QSpinBox *sbDown;
    QLabel *label_3;
    QSpinBox *sbLength;
    QPushButton *startButton;

    void setupUi(QWidget *OptionsWidget)
    {
        if (OptionsWidget->objectName().isEmpty())
            OptionsWidget->setObjectName(QStringLiteral("OptionsWidget"));
        OptionsWidget->resize(576, 300);
        verticalLayout = new QVBoxLayout(OptionsWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(11, -1, -1, -1);
        splitter = new QSplitter(OptionsWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setBaseSize(QSize(3, 0));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        sbRounds = new QSpinBox(layoutWidget);
        sbRounds->setObjectName(QStringLiteral("sbRounds"));
        sbRounds->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbRounds->setMinimum(1);
        sbRounds->setValue(12);
        sbRounds->setDisplayIntegerBase(10);

        formLayout->setWidget(0, QFormLayout::FieldRole, sbRounds);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        sbDown = new QSpinBox(layoutWidget);
        sbDown->setObjectName(QStringLiteral("sbDown"));
        sbDown->setMinimum(1);
        sbDown->setValue(3);

        formLayout->setWidget(1, QFormLayout::FieldRole, sbDown);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        sbLength = new QSpinBox(layoutWidget);
        sbLength->setObjectName(QStringLiteral("sbLength"));
        sbLength->setMinimum(1);
        sbLength->setMaximum(999);
        sbLength->setValue(36);

        formLayout->setWidget(2, QFormLayout::FieldRole, sbLength);

        splitter->addWidget(layoutWidget);
        startButton = new QPushButton(splitter);
        startButton->setObjectName(QStringLiteral("startButton"));
        splitter->addWidget(startButton);

        verticalLayout->addWidget(splitter);


        retranslateUi(OptionsWidget);
        QObject::connect(startButton, SIGNAL(clicked(bool)), OptionsWidget, SLOT(startClicked()));

        QMetaObject::connectSlotsByName(OptionsWidget);
    } // setupUi

    void retranslateUi(QWidget *OptionsWidget)
    {
        OptionsWidget->setWindowTitle(QApplication::translate("OptionsWidget", "Form", nullptr));
        label->setText(QApplication::translate("OptionsWidget", "Rounds", nullptr));
        sbRounds->setSuffix(QString());
        label_2->setText(QApplication::translate("OptionsWidget", "Down Limit", nullptr));
        label_3->setText(QApplication::translate("OptionsWidget", "Round Length", nullptr));
        startButton->setText(QApplication::translate("OptionsWidget", "Start Match", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionsWidget: public Ui_OptionsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSWIDGET_H
