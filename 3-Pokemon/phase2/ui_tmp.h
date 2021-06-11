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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *ui3_label_7;
    QLineEdit *ui3_name;
    QLineEdit *ui3_level;
    QLineEdit *ui3_DEF;
    QLineEdit *ui3_ATK;
    QLabel *ui3_label_10;
    QLabel *ui3_label_4;
    QLineEdit *ui3_type;
    QLabel *ui3_label_2;
    QLabel *ui3_label_6;
    QLineEdit *ui3_HP;
    QLabel *ui3_label_9;
    QLineEdit *ui3_SPD;
    QLabel *ui3_label;
    QLineEdit *ui3_EXP;
    QLabel *ui3_label_8;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(400, 300);
        ui3_label_7 = new QLabel(Form);
        ui3_label_7->setObjectName(QString::fromUtf8("ui3_label_7"));
        ui3_label_7->setGeometry(QRect(80, 150, 51, 21));
        ui3_name = new QLineEdit(Form);
        ui3_name->setObjectName(QString::fromUtf8("ui3_name"));
        ui3_name->setGeometry(QRect(150, 90, 113, 20));
        ui3_level = new QLineEdit(Form);
        ui3_level->setObjectName(QString::fromUtf8("ui3_level"));
        ui3_level->setGeometry(QRect(150, 120, 113, 20));
        ui3_DEF = new QLineEdit(Form);
        ui3_DEF->setObjectName(QString::fromUtf8("ui3_DEF"));
        ui3_DEF->setGeometry(QRect(150, 240, 113, 20));
        ui3_ATK = new QLineEdit(Form);
        ui3_ATK->setObjectName(QString::fromUtf8("ui3_ATK"));
        ui3_ATK->setGeometry(QRect(150, 210, 113, 20));
        ui3_label_10 = new QLabel(Form);
        ui3_label_10->setObjectName(QString::fromUtf8("ui3_label_10"));
        ui3_label_10->setGeometry(QRect(80, 270, 71, 21));
        ui3_label_4 = new QLabel(Form);
        ui3_label_4->setObjectName(QString::fromUtf8("ui3_label_4"));
        ui3_label_4->setGeometry(QRect(80, 120, 51, 21));
        ui3_type = new QLineEdit(Form);
        ui3_type->setObjectName(QString::fromUtf8("ui3_type"));
        ui3_type->setGeometry(QRect(150, 60, 113, 20));
        ui3_label_2 = new QLabel(Form);
        ui3_label_2->setObjectName(QString::fromUtf8("ui3_label_2"));
        ui3_label_2->setGeometry(QRect(80, 210, 51, 21));
        ui3_label_6 = new QLabel(Form);
        ui3_label_6->setObjectName(QString::fromUtf8("ui3_label_6"));
        ui3_label_6->setGeometry(QRect(80, 240, 71, 21));
        ui3_HP = new QLineEdit(Form);
        ui3_HP->setObjectName(QString::fromUtf8("ui3_HP"));
        ui3_HP->setGeometry(QRect(150, 180, 113, 20));
        ui3_label_9 = new QLabel(Form);
        ui3_label_9->setObjectName(QString::fromUtf8("ui3_label_9"));
        ui3_label_9->setGeometry(QRect(80, 90, 51, 21));
        ui3_SPD = new QLineEdit(Form);
        ui3_SPD->setObjectName(QString::fromUtf8("ui3_SPD"));
        ui3_SPD->setGeometry(QRect(150, 270, 113, 20));
        ui3_label = new QLabel(Form);
        ui3_label->setObjectName(QString::fromUtf8("ui3_label"));
        ui3_label->setGeometry(QRect(80, 180, 51, 21));
        ui3_EXP = new QLineEdit(Form);
        ui3_EXP->setObjectName(QString::fromUtf8("ui3_EXP"));
        ui3_EXP->setGeometry(QRect(150, 150, 113, 20));
        ui3_label_8 = new QLabel(Form);
        ui3_label_8->setObjectName(QString::fromUtf8("ui3_label_8"));
        ui3_label_8->setGeometry(QRect(80, 60, 51, 21));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        ui3_label_7->setText(QCoreApplication::translate("Form", "\347\273\217\351\252\214\345\200\274\357\274\232", nullptr));
        ui3_DEF->setText(QString());
        ui3_label_10->setText(QCoreApplication::translate("Form", "\346\224\273\351\200\237\357\274\232", nullptr));
        ui3_label_4->setText(QCoreApplication::translate("Form", "\347\255\211\347\272\247\357\274\232", nullptr));
        ui3_label_2->setText(QCoreApplication::translate("Form", "\346\224\273\345\207\273\345\200\274\357\274\232", nullptr));
        ui3_label_6->setText(QCoreApplication::translate("Form", "\351\230\262\345\276\241\345\200\274\357\274\232", nullptr));
        ui3_label_9->setText(QCoreApplication::translate("Form", "\345\220\215\345\255\227\357\274\232", nullptr));
        ui3_label->setText(QCoreApplication::translate("Form", "\347\224\237\345\221\275\345\200\274\357\274\232", nullptr));
        ui3_label_8->setText(QCoreApplication::translate("Form", "\347\247\215\347\261\273\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TMP_H
