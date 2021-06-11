/********************************************************************************
** Form generated from reading UI file 'ui7.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI7_H
#define UI_UI7_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *ui7_winLose;
    QLabel *ui7_pokemon;
    QLabel *ui7_prize;
    QLabel *ui7_exp;
    QPushButton *ui7_ack_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(800, 600);
        ui7_winLose = new QLabel(Form);
        ui7_winLose->setObjectName(QString::fromUtf8("ui7_winLose"));
        ui7_winLose->setGeometry(QRect(200, 60, 351, 91));
        ui7_pokemon = new QLabel(Form);
        ui7_pokemon->setObjectName(QString::fromUtf8("ui7_pokemon"));
        ui7_pokemon->setGeometry(QRect(100, 200, 251, 251));
        ui7_prize = new QLabel(Form);
        ui7_prize->setObjectName(QString::fromUtf8("ui7_prize"));
        ui7_prize->setGeometry(QRect(470, 170, 141, 141));
        ui7_exp = new QLabel(Form);
        ui7_exp->setObjectName(QString::fromUtf8("ui7_exp"));
        ui7_exp->setGeometry(QRect(450, 340, 191, 71));
        ui7_ack_2 = new QPushButton(Form);
        ui7_ack_2->setObjectName(QString::fromUtf8("ui7_ack_2"));
        ui7_ack_2->setGeometry(QRect(480, 440, 141, 51));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        ui7_winLose->setText(QCoreApplication::translate("Form", "winLose", nullptr));
        ui7_pokemon->setText(QCoreApplication::translate("Form", "pokemon", nullptr));
        ui7_prize->setText(QCoreApplication::translate("Form", "prize", nullptr));
        ui7_exp->setText(QCoreApplication::translate("Form", "exp", nullptr));
        ui7_ack_2->setText(QCoreApplication::translate("Form", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI7_H
