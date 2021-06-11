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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *ui2_allPlayers;
    QPushButton *ui2_myPokemon;
    QPushButton *ui2_saveAndQuit;
    QPushButton *ui2_returnSignIn;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(583, 521);
        ui2_allPlayers = new QPushButton(Form);
        ui2_allPlayers->setObjectName(QString::fromUtf8("ui2_allPlayers"));
        ui2_allPlayers->setGeometry(QRect(190, 160, 171, 81));
        ui2_myPokemon = new QPushButton(Form);
        ui2_myPokemon->setObjectName(QString::fromUtf8("ui2_myPokemon"));
        ui2_myPokemon->setGeometry(QRect(190, 60, 171, 81));
        ui2_saveAndQuit = new QPushButton(Form);
        ui2_saveAndQuit->setObjectName(QString::fromUtf8("ui2_saveAndQuit"));
        ui2_saveAndQuit->setGeometry(QRect(190, 360, 171, 81));
        ui2_returnSignIn = new QPushButton(Form);
        ui2_returnSignIn->setObjectName(QString::fromUtf8("ui2_returnSignIn"));
        ui2_returnSignIn->setGeometry(QRect(190, 260, 171, 81));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        ui2_allPlayers->setText(QCoreApplication::translate("Form", "\346\237\245\347\234\213\347\216\251\345\256\266", nullptr));
        ui2_myPokemon->setText(QCoreApplication::translate("Form", "\346\237\245\347\234\213\347\262\276\347\201\265", nullptr));
        ui2_saveAndQuit->setText(QCoreApplication::translate("Form", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
        ui2_returnSignIn->setText(QCoreApplication::translate("Form", "\350\277\224\345\233\236\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI2_H
