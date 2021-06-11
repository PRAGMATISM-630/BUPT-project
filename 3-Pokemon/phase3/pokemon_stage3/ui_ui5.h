/********************************************************************************
** Form generated from reading UI file 'ui5.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI5_H
#define UI_UI5_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *ui5_return;
    QPushButton *ui5_levelUp;
    QPushButton *ui5_battle;
    QToolButton *ui5_rules;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(800, 600);
        ui5_return = new QPushButton(Form);
        ui5_return->setObjectName(QString::fromUtf8("ui5_return"));
        ui5_return->setGeometry(QRect(10, 10, 81, 31));
        ui5_levelUp = new QPushButton(Form);
        ui5_levelUp->setObjectName(QString::fromUtf8("ui5_levelUp"));
        ui5_levelUp->setGeometry(QRect(110, 130, 231, 351));
        ui5_battle = new QPushButton(Form);
        ui5_battle->setObjectName(QString::fromUtf8("ui5_battle"));
        ui5_battle->setGeometry(QRect(430, 130, 231, 351));
        ui5_rules = new QToolButton(Form);
        ui5_rules->setObjectName(QString::fromUtf8("ui5_rules"));
        ui5_rules->setGeometry(QRect(670, 20, 50, 50));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        ui5_return->setText(QCoreApplication::translate("Form", "\350\277\224\345\233\236", nullptr));
        ui5_levelUp->setText(QCoreApplication::translate("Form", "\345\215\207\347\272\247\350\265\233\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\351\200\211\346\213\251\345\256\235\345\217\257\346\242\246\344\270\216\346\234\215\345\212\241\345\231\250\350\277\233\350\241\214\350\231\232\346\213\237\345\206\263\346\226\227\n"
"\n"
"\350\203\234\345\210\251\345\217\257\344\273\245\350\216\267\345\276\227\345\244\247\351\207\217\347\273\217\351\252\214\n"
"\n"
"\345\244\261\350\264\245\345\217\257\344\273\245\350\216\267\345\276\227\345\260\221\351\207\217\347\273\217\351\252\214\n"
"\n"
"\345\244\261\350\264\245\344\270\215\344\274\232\345\244\261\345\216\273\345\256\235\345\217\257\346\242\246", nullptr));
        ui5_battle->setText(QCoreApplication::translate("Form", "\345\206\263\346\226\227\350\265\233\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\351\200\211\346\213\251\345\256\235\345\217\257\346\242\246\344\270\216\346\234\215\345\212\241\345\231\250\350\277\233\350\241\214\350\231\232\346\213\237\345\206\263\346\226\227\n"
"\n"
"\345\217\257\344\273\245\344\270\272\345\256\235\345\217\257\346\242\246\350\216\267\345\276\227\345\260\221\351\207\217\347\273\217\351\252\214\n"
"\n"
"\350\203\234\345\210\251\345\217\257\344\273\245\350\216\267\345\276\227\350\257\245\346\210\230\350\203\234\347\232\204\345\256\235\345\217\257\346\242\246\n"
"\n"
"\345\244\261\350\264\245\345\210\231\344\274\232\347\224\261\347\224\250\346\210\267\351\200\211\346\213\251\345\244\261\345\216\273\344\270\200\344\270\252\345\256\235\345\217\257\346\242\246", nullptr));
        ui5_rules->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI5_H
