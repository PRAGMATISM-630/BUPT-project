/********************************************************************************
** Form generated from reading UI file 'ui8.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI8_H
#define UI_UI8_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *ui8_bronze1;
    QLabel *ui8_silver1;
    QLabel *ui8_golden1;
    QLabel *ui8_bronze2;
    QLabel *ui8_silver2;
    QLabel *ui8_golden2;
    QToolButton *ui8_win;
    QToolButton *ui8_lose;
    QToolButton *ui8_per;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(800, 600);
        ui8_bronze1 = new QLabel(Form);
        ui8_bronze1->setObjectName(QString::fromUtf8("ui8_bronze1"));
        ui8_bronze1->setGeometry(QRect(40, 100, 121, 161));
        ui8_silver1 = new QLabel(Form);
        ui8_silver1->setObjectName(QString::fromUtf8("ui8_silver1"));
        ui8_silver1->setGeometry(QRect(200, 100, 121, 161));
        ui8_golden1 = new QLabel(Form);
        ui8_golden1->setObjectName(QString::fromUtf8("ui8_golden1"));
        ui8_golden1->setGeometry(QRect(360, 100, 121, 161));
        ui8_bronze2 = new QLabel(Form);
        ui8_bronze2->setObjectName(QString::fromUtf8("ui8_bronze2"));
        ui8_bronze2->setGeometry(QRect(40, 370, 121, 161));
        ui8_silver2 = new QLabel(Form);
        ui8_silver2->setObjectName(QString::fromUtf8("ui8_silver2"));
        ui8_silver2->setGeometry(QRect(200, 370, 121, 161));
        ui8_golden2 = new QLabel(Form);
        ui8_golden2->setObjectName(QString::fromUtf8("ui8_golden2"));
        ui8_golden2->setGeometry(QRect(360, 370, 121, 161));
        ui8_win = new QToolButton(Form);
        ui8_win->setObjectName(QString::fromUtf8("ui8_win"));
        ui8_win->setGeometry(QRect(560, 130, 151, 81));
        ui8_lose = new QToolButton(Form);
        ui8_lose->setObjectName(QString::fromUtf8("ui8_lose"));
        ui8_lose->setGeometry(QRect(560, 280, 151, 81));
        ui8_per = new QToolButton(Form);
        ui8_per->setObjectName(QString::fromUtf8("ui8_per"));
        ui8_per->setGeometry(QRect(560, 430, 151, 81));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        ui8_bronze1->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        ui8_silver1->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        ui8_golden1->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        ui8_bronze2->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        ui8_silver2->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        ui8_golden2->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        ui8_win->setText(QCoreApplication::translate("Form", "\350\203\234\345\234\272\357\274\232", nullptr));
        ui8_lose->setText(QCoreApplication::translate("Form", "\350\264\237\345\234\272\357\274\232", nullptr));
        ui8_per->setText(QCoreApplication::translate("Form", "\350\203\234\347\216\207\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI8_H
