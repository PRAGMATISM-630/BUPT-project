/********************************************************************************
** Form generated from reading UI file 'getnewpokemon.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETNEWPOKEMON_H
#define UI_GETNEWPOKEMON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_getNewPokemon
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *getNewPokemon)
    {
        if (getNewPokemon->objectName().isEmpty())
            getNewPokemon->setObjectName(QString::fromUtf8("getNewPokemon"));
        getNewPokemon->resize(800, 600);
        label = new QLabel(getNewPokemon);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 30, 511, 51));
        label_2 = new QLabel(getNewPokemon);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 130, 300, 300));
        pushButton = new QPushButton(getNewPokemon);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 490, 161, 41));

        retranslateUi(getNewPokemon);

        QMetaObject::connectSlotsByName(getNewPokemon);
    } // setupUi

    void retranslateUi(QWidget *getNewPokemon)
    {
        getNewPokemon->setWindowTitle(QCoreApplication::translate("getNewPokemon", "Form", nullptr));
        label->setText(QCoreApplication::translate("getNewPokemon", "\350\216\267\345\276\227\346\226\260\347\232\204\345\256\235\345\217\257\346\242\246\357\274\201", nullptr));
        label_2->setText(QCoreApplication::translate("getNewPokemon", "\345\256\235\345\217\257\346\242\246\350\264\264\345\233\276", nullptr));
        pushButton->setText(QCoreApplication::translate("getNewPokemon", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class getNewPokemon: public Ui_getNewPokemon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETNEWPOKEMON_H
