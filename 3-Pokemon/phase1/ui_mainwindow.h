/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *attackBtn;
    QPushButton *takeDamageBtn;
    QPushButton *gainExpBtn;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *HP;
    QLineEdit *ATK;
    QLineEdit *enemyHP;
    QLabel *label_5;
    QTextEdit *infomation;
    QLineEdit *DEF;
    QLabel *label_6;
    QPushButton *clear;
    QLineEdit *EXP;
    QLineEdit *level;
    QLabel *label_4;
    QLabel *label_7;
    QPushButton *getPokemonBtn;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *type;
    QLineEdit *name;
    QLineEdit *SPD;
    QLabel *label_10;
    QPushButton *resetEnemy;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(569, 526);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        attackBtn = new QPushButton(centralWidget);
        attackBtn->setObjectName(QString::fromUtf8("attackBtn"));
        attackBtn->setGeometry(QRect(80, 90, 91, 51));
        takeDamageBtn = new QPushButton(centralWidget);
        takeDamageBtn->setObjectName(QString::fromUtf8("takeDamageBtn"));
        takeDamageBtn->setGeometry(QRect(220, 90, 91, 51));
        gainExpBtn = new QPushButton(centralWidget);
        gainExpBtn->setObjectName(QString::fromUtf8("gainExpBtn"));
        gainExpBtn->setGeometry(QRect(360, 90, 91, 51));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 300, 51, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 330, 51, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 420, 71, 21));
        HP = new QLineEdit(centralWidget);
        HP->setObjectName(QString::fromUtf8("HP"));
        HP->setGeometry(QRect(140, 300, 113, 20));
        ATK = new QLineEdit(centralWidget);
        ATK->setObjectName(QString::fromUtf8("ATK"));
        ATK->setGeometry(QRect(140, 330, 113, 20));
        enemyHP = new QLineEdit(centralWidget);
        enemyHP->setObjectName(QString::fromUtf8("enemyHP"));
        enemyHP->setGeometry(QRect(140, 420, 113, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(280, 170, 71, 16));
        infomation = new QTextEdit(centralWidget);
        infomation->setObjectName(QString::fromUtf8("infomation"));
        infomation->setGeometry(QRect(280, 200, 241, 241));
        DEF = new QLineEdit(centralWidget);
        DEF->setObjectName(QString::fromUtf8("DEF"));
        DEF->setGeometry(QRect(140, 360, 113, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 360, 71, 21));
        clear = new QPushButton(centralWidget);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(440, 170, 75, 23));
        EXP = new QLineEdit(centralWidget);
        EXP->setObjectName(QString::fromUtf8("EXP"));
        EXP->setGeometry(QRect(140, 270, 113, 20));
        level = new QLineEdit(centralWidget);
        level->setObjectName(QString::fromUtf8("level"));
        level->setGeometry(QRect(140, 240, 113, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 240, 51, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 270, 51, 21));
        getPokemonBtn = new QPushButton(centralWidget);
        getPokemonBtn->setObjectName(QString::fromUtf8("getPokemonBtn"));
        getPokemonBtn->setGeometry(QRect(190, 20, 151, 51));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(70, 180, 51, 21));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(70, 210, 51, 21));
        type = new QLineEdit(centralWidget);
        type->setObjectName(QString::fromUtf8("type"));
        type->setGeometry(QRect(140, 180, 113, 20));
        name = new QLineEdit(centralWidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(140, 210, 113, 20));
        SPD = new QLineEdit(centralWidget);
        SPD->setObjectName(QString::fromUtf8("SPD"));
        SPD->setGeometry(QRect(140, 390, 113, 20));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(70, 390, 71, 21));
        resetEnemy = new QPushButton(centralWidget);
        resetEnemy->setObjectName(QString::fromUtf8("resetEnemy"));
        resetEnemy->setGeometry(QRect(20, 420, 41, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 569, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        attackBtn->setText(QCoreApplication::translate("MainWindow", "\346\224\273\345\207\273", nullptr));
        takeDamageBtn->setText(QCoreApplication::translate("MainWindow", "\346\211\277\345\217\227\346\224\273\345\207\273", nullptr));
        gainExpBtn->setText(QCoreApplication::translate("MainWindow", "\350\216\267\345\276\227\347\273\217\351\252\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\224\237\345\221\275\345\200\274\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\224\273\345\207\273\345\200\274\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\225\214\346\226\271\347\224\237\345\221\275\345\200\274\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\344\277\241\346\201\257\347\212\266\346\200\201\346\240\217\357\274\232", nullptr));
        DEF->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "\351\230\262\345\276\241\345\200\274\357\274\232", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\255\211\347\272\247\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\347\273\217\351\252\214\345\200\274\357\274\232", nullptr));
        getPokemonBtn->setText(QCoreApplication::translate("MainWindow", "\350\216\267\345\217\226/\346\233\264\346\215\242\345\256\235\345\217\257\346\242\246", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\347\247\215\347\261\273\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\345\220\215\345\255\227\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\346\224\273\351\200\237\357\274\232", nullptr));
        resetEnemy->setText(QCoreApplication::translate("MainWindow", "\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
