/********************************************************************************
** Form generated from reading UI file 'ui6.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI6_H
#define UI_UI6_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *ui6_myPokemon;
    QLabel *ui6_enemyPokemon;
    QLineEdit *ui6_ATK;
    QLineEdit *ui6_HP;
    QLineEdit *ui6_DEF;
    QLineEdit *ui6_SPD;
    QLineEdit *ui6_ATK_2;
    QLineEdit *ui6_SPD_2;
    QLineEdit *ui6_DEF_2;
    QLineEdit *ui6_HP_2;
    QLabel *ui6_myfire;
    QLabel *ui6_enemyfire;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(800, 600);
        ui6_myPokemon = new QLabel(Form);
        ui6_myPokemon->setObjectName(QString::fromUtf8("ui6_myPokemon"));
        ui6_myPokemon->setGeometry(QRect(60, 240, 211, 211));
        ui6_enemyPokemon = new QLabel(Form);
        ui6_enemyPokemon->setObjectName(QString::fromUtf8("ui6_enemyPokemon"));
        ui6_enemyPokemon->setGeometry(QRect(530, 240, 211, 211));
        ui6_ATK = new QLineEdit(Form);
        ui6_ATK->setObjectName(QString::fromUtf8("ui6_ATK"));
        ui6_ATK->setGeometry(QRect(110, 80, 113, 20));
        ui6_HP = new QLineEdit(Form);
        ui6_HP->setObjectName(QString::fromUtf8("ui6_HP"));
        ui6_HP->setGeometry(QRect(110, 50, 113, 20));
        ui6_DEF = new QLineEdit(Form);
        ui6_DEF->setObjectName(QString::fromUtf8("ui6_DEF"));
        ui6_DEF->setGeometry(QRect(110, 110, 113, 20));
        ui6_SPD = new QLineEdit(Form);
        ui6_SPD->setObjectName(QString::fromUtf8("ui6_SPD"));
        ui6_SPD->setGeometry(QRect(110, 140, 113, 20));
        ui6_ATK_2 = new QLineEdit(Form);
        ui6_ATK_2->setObjectName(QString::fromUtf8("ui6_ATK_2"));
        ui6_ATK_2->setGeometry(QRect(580, 80, 113, 20));
        ui6_SPD_2 = new QLineEdit(Form);
        ui6_SPD_2->setObjectName(QString::fromUtf8("ui6_SPD_2"));
        ui6_SPD_2->setGeometry(QRect(580, 140, 113, 20));
        ui6_DEF_2 = new QLineEdit(Form);
        ui6_DEF_2->setObjectName(QString::fromUtf8("ui6_DEF_2"));
        ui6_DEF_2->setGeometry(QRect(580, 110, 113, 20));
        ui6_HP_2 = new QLineEdit(Form);
        ui6_HP_2->setObjectName(QString::fromUtf8("ui6_HP_2"));
        ui6_HP_2->setGeometry(QRect(580, 50, 113, 20));
        ui6_myfire = new QLabel(Form);
        ui6_myfire->setObjectName(QString::fromUtf8("ui6_myfire"));
        ui6_myfire->setGeometry(QRect(60, 490, 211, 51));
        ui6_enemyfire = new QLabel(Form);
        ui6_enemyfire->setObjectName(QString::fromUtf8("ui6_enemyfire"));
        ui6_enemyfire->setGeometry(QRect(530, 490, 211, 51));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        ui6_myPokemon->setText(QCoreApplication::translate("Form", "\346\210\221\346\226\271\345\256\235\345\217\257\346\242\246\350\264\264\345\233\276", nullptr));
        ui6_enemyPokemon->setText(QCoreApplication::translate("Form", "\346\225\214\346\226\271\345\256\235\345\217\257\346\242\246\350\264\264\345\233\276", nullptr));
        ui6_DEF->setText(QString());
        ui6_DEF_2->setText(QString());
        ui6_myfire->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        ui6_enemyfire->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI6_H
