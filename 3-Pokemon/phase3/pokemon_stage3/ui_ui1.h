/********************************************************************************
** Form generated from reading UI file 'ui1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI1_H
#define UI_UI1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLineEdit *ui1_password;
    QLabel *ui1_label;
    QPushButton *ui1_signUp;
    QLabel *ui1_label_2;
    QPushButton *ui1_signIn;
    QLineEdit *ui1_userName;
    QLabel *ui1_background;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(636, 552);
        ui1_password = new QLineEdit(Form);
        ui1_password->setObjectName(QString::fromUtf8("ui1_password"));
        ui1_password->setGeometry(QRect(280, 229, 121, 21));
        ui1_password->setEchoMode(QLineEdit::Password);
        ui1_label = new QLabel(Form);
        ui1_label->setObjectName(QString::fromUtf8("ui1_label"));
        ui1_label->setGeometry(QRect(220, 189, 54, 21));
        ui1_signUp = new QPushButton(Form);
        ui1_signUp->setObjectName(QString::fromUtf8("ui1_signUp"));
        ui1_signUp->setGeometry(QRect(220, 319, 181, 31));
        ui1_label_2 = new QLabel(Form);
        ui1_label_2->setObjectName(QString::fromUtf8("ui1_label_2"));
        ui1_label_2->setGeometry(QRect(220, 229, 54, 21));
        ui1_signIn = new QPushButton(Form);
        ui1_signIn->setObjectName(QString::fromUtf8("ui1_signIn"));
        ui1_signIn->setGeometry(QRect(220, 279, 181, 31));
        ui1_userName = new QLineEdit(Form);
        ui1_userName->setObjectName(QString::fromUtf8("ui1_userName"));
        ui1_userName->setGeometry(QRect(280, 190, 121, 20));
        ui1_background = new QLabel(Form);
        ui1_background->setObjectName(QString::fromUtf8("ui1_background"));
        ui1_background->setGeometry(QRect(200, 150, 221, 231));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        ui1_label->setText(QCoreApplication::translate("Form", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        ui1_signUp->setText(QCoreApplication::translate("Form", "\346\263\250\345\206\214\345\271\266\347\231\273\345\275\225", nullptr));
        ui1_label_2->setText(QCoreApplication::translate("Form", "\345\257\206\347\240\201\357\274\232", nullptr));
        ui1_signIn->setText(QCoreApplication::translate("Form", "\347\231\273\345\275\225", nullptr));
        ui1_background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI1_H
