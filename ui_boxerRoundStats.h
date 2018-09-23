/********************************************************************************
** Form generated from reading UI file 'boxerRoundStats.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOXERROUNDSTATS_H
#define UI_BOXERROUNDSTATS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_boxerRoundStats
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lePunchThrown;
    QLabel *label_2;
    QLineEdit *lePunchLand;
    QLabel *label_5;
    QLineEdit *leDamageTake;
    QLabel *label_6;
    QLineEdit *leDowns;
    QLabel *label_4;
    QLineEdit *leBlocked;
    QLabel *label_3;
    QProgressBar *pbHealth;

    void setupUi(QWidget *boxerRoundStats)
    {
        if (boxerRoundStats->objectName().isEmpty())
            boxerRoundStats->setObjectName(QStringLiteral("boxerRoundStats"));
        boxerRoundStats->resize(558, 595);
        verticalLayout = new QVBoxLayout(boxerRoundStats);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(boxerRoundStats);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lePunchThrown = new QLineEdit(boxerRoundStats);
        lePunchThrown->setObjectName(QStringLiteral("lePunchThrown"));
        lePunchThrown->setEnabled(false);
        lePunchThrown->setToolTipDuration(0);

        formLayout->setWidget(0, QFormLayout::FieldRole, lePunchThrown);

        label_2 = new QLabel(boxerRoundStats);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lePunchLand = new QLineEdit(boxerRoundStats);
        lePunchLand->setObjectName(QStringLiteral("lePunchLand"));
        lePunchLand->setEnabled(false);
        lePunchLand->setToolTipDuration(0);

        formLayout->setWidget(1, QFormLayout::FieldRole, lePunchLand);

        label_5 = new QLabel(boxerRoundStats);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setCursor(QCursor(Qt::IBeamCursor));
        label_5->setFrameShape(QFrame::NoFrame);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        leDamageTake = new QLineEdit(boxerRoundStats);
        leDamageTake->setObjectName(QStringLiteral("leDamageTake"));
        leDamageTake->setEnabled(false);
        leDamageTake->setToolTipDuration(0);

        formLayout->setWidget(2, QFormLayout::FieldRole, leDamageTake);

        label_6 = new QLabel(boxerRoundStats);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        leDowns = new QLineEdit(boxerRoundStats);
        leDowns->setObjectName(QStringLiteral("leDowns"));
        leDowns->setEnabled(false);
        leDowns->setToolTipDuration(0);

        formLayout->setWidget(3, QFormLayout::FieldRole, leDowns);

        label_4 = new QLabel(boxerRoundStats);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        leBlocked = new QLineEdit(boxerRoundStats);
        leBlocked->setObjectName(QStringLiteral("leBlocked"));
        leBlocked->setEnabled(false);
        leBlocked->setToolTipDuration(0);

        formLayout->setWidget(4, QFormLayout::FieldRole, leBlocked);

        label_3 = new QLabel(boxerRoundStats);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_3);

        pbHealth = new QProgressBar(boxerRoundStats);
        pbHealth->setObjectName(QStringLiteral("pbHealth"));
        pbHealth->setBaseSize(QSize(0, 0));
        pbHealth->setValue(28);
        pbHealth->setOrientation(Qt::Horizontal);
        pbHealth->setInvertedAppearance(false);
        pbHealth->setTextDirection(QProgressBar::TopToBottom);

        formLayout->setWidget(5, QFormLayout::FieldRole, pbHealth);


        verticalLayout->addLayout(formLayout);


        retranslateUi(boxerRoundStats);

        QMetaObject::connectSlotsByName(boxerRoundStats);
    } // setupUi

    void retranslateUi(QWidget *boxerRoundStats)
    {
        boxerRoundStats->setWindowTitle(QApplication::translate("boxerRoundStats", "boxerRoundStats", nullptr));
        label->setText(QApplication::translate("boxerRoundStats", "Punches Thrown", nullptr));
        label_2->setText(QApplication::translate("boxerRoundStats", "Punches Landed", nullptr));
        label_5->setText(QApplication::translate("boxerRoundStats", "Damage Taken", nullptr));
        label_6->setText(QApplication::translate("boxerRoundStats", "Downs", nullptr));
        label_4->setText(QApplication::translate("boxerRoundStats", "Punches Blocked", nullptr));
        label_3->setText(QApplication::translate("boxerRoundStats", "Health", nullptr));
    } // retranslateUi

};

namespace Ui {
    class boxerRoundStats: public Ui_boxerRoundStats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOXERROUNDSTATS_H
