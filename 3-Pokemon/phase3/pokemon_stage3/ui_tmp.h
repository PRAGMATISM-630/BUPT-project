/********************************************************************************
** Form generated from reading UI file 'tmp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TMP_H
#define UI_TMP_H

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
    QLineEdit *ui1_userName;
    QLabel *ui1_label_2;
    QLineEdit *ui1_password;
    QPushButton *ui1_signUp;
    QLabel *ui1_label;
    QPushButton *ui1_signIn;
    QLabel *ui1_trademark;
    QLabel *ui1_img1;
    QLabel *ui1_img2;
    QLabel *ui1_img3;
    QLabel *ui1_img4;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(800, 600);
        ui1_userName = new QLineEdit(Form);
        ui1_userName->setObjectName(QString::fromUtf8("ui1_userName"));
        ui1_userName->setGeometry(QRect(350, 281, 121, 25));
        ui1_label_2 = new QLabel(Form);
        ui1_label_2->setObjectName(QString::fromUtf8("ui1_label_2"));
        ui1_label_2->setGeometry(QRect(290, 320, 54, 21));
        ui1_password = new QLineEdit(Form);
        ui1_password->setObjectName(QString::fromUtf8("ui1_password"));
        ui1_password->setGeometry(QRect(350, 320, 121, 25));
        ui1_password->setEchoMode(QLineEdit::Password);
        ui1_signUp = new QPushButton(Form);
        ui1_signUp->setObjectName(QString::fromUtf8("ui1_signUp"));
        ui1_signUp->setGeometry(QRect(290, 410, 181, 31));
        ui1_label = new QLabel(Form);
        ui1_label->setObjectName(QString::fromUtf8("ui1_label"));
        ui1_label->setGeometry(QRect(290, 280, 54, 21));
        ui1_signIn = new QPushButton(Form);
        ui1_signIn->setObjectName(QString::fromUtf8("ui1_signIn"));
        ui1_signIn->setGeometry(QRect(290, 370, 181, 31));
        ui1_trademark = new QLabel(Form);
        ui1_trademark->setObjectName(QString::fromUtf8("ui1_trademark"));
        ui1_trademark->setGeometry(QRect(230, 60, 300, 160));
        ui1_img1 = new QLabel(Form);
        ui1_img1->setObjectName(QString::fromUtf8("ui1_img1"));
        ui1_img1->setGeometry(QRect(30, 210, 150, 150));
        ui1_img2 = new QLabel(Form);
        ui1_img2->setObjectName(QString::fromUtf8("ui1_img2"));
        ui1_img2->setGeometry(QRect(100, 300, 150, 150));
        ui1_img3 = new QLabel(Form);
        ui1_img3->setObjectName(QString::fromUtf8("ui1_img3"));
        ui1_img3->setGeometry(QRect(630, 230, 150, 150));
        ui1_img4 = new QLabel(Form);
        ui1_img4->setObjectName(QString::fromUtf8("ui1_img4"));
        ui1_img4->setGeometry(QRect(550, 350, 150, 150));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        ui1_label_2->setText(QCoreApplication::translate("Form", "\345\257\206\347\240\201\357\274\232", nullptr));
        ui1_signUp->setText(QCoreApplication::translate("Form", "\346\263\250\345\206\214\345\271\266\347\231\273\345\275\225", nullptr));
        ui1_label->setText(QCoreApplication::translate("Form", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        ui1_signIn->setText(QCoreApplication::translate("Form", "\347\231\273\345\275\225", nullptr));
        ui1_trademark->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        ui1_img1->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        ui1_img2->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        ui1_img3->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        ui1_img4->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TMP_H
