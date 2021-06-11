/********************************************************************************
** Form generated from reading UI file 'ui2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI2_H
#define UI_UI2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QToolButton *ui2_myPokemon;
    QToolButton *ui2_allPlayers;
    QToolButton *ui2_returnSignIn;
    QToolButton *ui2_saveAndQuit_2;
    QToolButton *ui2_battle;
    QToolButton *ui2_prize;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(800, 600);
        ui2_myPokemon = new QToolButton(Form);
        ui2_myPokemon->setObjectName(QString::fromUtf8("ui2_myPokemon"));
        ui2_myPokemon->setGeometry(QRect(340, 30, 120, 140));
        ui2_allPlayers = new QToolButton(Form);
        ui2_allPlayers->setObjectName(QString::fromUtf8("ui2_allPlayers"));
        ui2_allPlayers->setGeometry(QRect(100, 180, 120, 140));
        ui2_returnSignIn = new QToolButton(Form);
        ui2_returnSignIn->setObjectName(QString::fromUtf8("ui2_returnSignIn"));
        ui2_returnSignIn->setGeometry(QRect(150, 420, 120, 140));
        ui2_saveAndQuit_2 = new QToolButton(Form);
        ui2_saveAndQuit_2->setObjectName(QString::fromUtf8("ui2_saveAndQuit_2"));
        ui2_saveAndQuit_2->setGeometry(QRect(540, 420, 120, 140));
        ui2_battle = new QToolButton(Form);
        ui2_battle->setObjectName(QString::fromUtf8("ui2_battle"));
        ui2_battle->setGeometry(QRect(300, 200, 210, 230));
        ui2_prize = new QToolButton(Form);
        ui2_prize->setObjectName(QString::fromUtf8("ui2_prize"));
        ui2_prize->setGeometry(QRect(590, 180, 120, 140));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        ui2_myPokemon->setText(QCoreApplication::translate("Form", "\345\256\235\345\217\257\346\242\246", nullptr));
        ui2_allPlayers->setText(QCoreApplication::translate("Form", "\347\216\251\345\256\266", nullptr));
        ui2_returnSignIn->setText(QCoreApplication::translate("Form", "\347\231\273\345\207\272", nullptr));
        ui2_saveAndQuit_2->setText(QCoreApplication::translate("Form", "\344\277\235\345\255\230\345\271\266\351\200\200\345\207\272", nullptr));
        ui2_battle->setText(QCoreApplication::translate("Form", "\346\210\230\346\226\227", nullptr));
        ui2_prize->setText(QCoreApplication::translate("Form", "\346\210\230\347\273\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI2_H
