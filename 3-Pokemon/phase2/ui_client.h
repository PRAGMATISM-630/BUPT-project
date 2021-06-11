/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *centralwidget;
    QPushButton *ui2_myPokemon;
    QPushButton *ui2_allPlayers;
    QPushButton *ui2_saveAndQuit;
    QPushButton *ui2_returnSignIn;
    QPushButton *ui4_returnMainUi;
    QPushButton *ui3_returnMainUi;
    QLabel *ui1_label;
    QLabel *ui1_background;
    QPushButton *ui1_signUp;
    QLineEdit *ui1_password;
    QPushButton *ui1_signIn;
    QLineEdit *ui1_userName;
    QLabel *ui1_label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(800, 600);
        centralwidget = new QWidget(Client);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ui2_myPokemon = new QPushButton(centralwidget);
        ui2_myPokemon->setObjectName(QString::fromUtf8("ui2_myPokemon"));
        ui2_myPokemon->setGeometry(QRect(310, 90, 171, 81));
        ui2_allPlayers = new QPushButton(centralwidget);
        ui2_allPlayers->setObjectName(QString::fromUtf8("ui2_allPlayers"));
        ui2_allPlayers->setGeometry(QRect(310, 190, 171, 81));
        ui2_saveAndQuit = new QPushButton(centralwidget);
        ui2_saveAndQuit->setObjectName(QString::fromUtf8("ui2_saveAndQuit"));
        ui2_saveAndQuit->setGeometry(QRect(310, 390, 171, 81));
        ui2_returnSignIn = new QPushButton(centralwidget);
        ui2_returnSignIn->setObjectName(QString::fromUtf8("ui2_returnSignIn"));
        ui2_returnSignIn->setGeometry(QRect(310, 290, 171, 81));
        ui4_returnMainUi = new QPushButton(centralwidget);
        ui4_returnMainUi->setObjectName(QString::fromUtf8("ui4_returnMainUi"));
        ui4_returnMainUi->setGeometry(QRect(10, 10, 81, 31));
        ui3_returnMainUi = new QPushButton(centralwidget);
        ui3_returnMainUi->setObjectName(QString::fromUtf8("ui3_returnMainUi"));
        ui3_returnMainUi->setGeometry(QRect(10, 10, 81, 31));
        ui1_label = new QLabel(centralwidget);
        ui1_label->setObjectName(QString::fromUtf8("ui1_label"));
        ui1_label->setGeometry(QRect(300, 200, 54, 21));
        ui1_background = new QLabel(centralwidget);
        ui1_background->setObjectName(QString::fromUtf8("ui1_background"));
        ui1_background->setGeometry(QRect(280, 160, 221, 231));
        ui1_signUp = new QPushButton(centralwidget);
        ui1_signUp->setObjectName(QString::fromUtf8("ui1_signUp"));
        ui1_signUp->setGeometry(QRect(300, 330, 181, 31));
        ui1_password = new QLineEdit(centralwidget);
        ui1_password->setObjectName(QString::fromUtf8("ui1_password"));
        ui1_password->setGeometry(QRect(360, 240, 121, 21));
        ui1_password->setEchoMode(QLineEdit::Password);
        ui1_signIn = new QPushButton(centralwidget);
        ui1_signIn->setObjectName(QString::fromUtf8("ui1_signIn"));
        ui1_signIn->setGeometry(QRect(300, 290, 181, 31));
        ui1_userName = new QLineEdit(centralwidget);
        ui1_userName->setObjectName(QString::fromUtf8("ui1_userName"));
        ui1_userName->setGeometry(QRect(360, 201, 121, 20));
        ui1_label_2 = new QLabel(centralwidget);
        ui1_label_2->setObjectName(QString::fromUtf8("ui1_label_2"));
        ui1_label_2->setGeometry(QRect(300, 240, 54, 21));
        Client->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Client);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        Client->setMenuBar(menubar);
        statusbar = new QStatusBar(Client);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Client->setStatusBar(statusbar);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QMainWindow *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "Client", nullptr));
        ui2_myPokemon->setText(QCoreApplication::translate("Client", "\346\237\245\347\234\213\347\262\276\347\201\265", nullptr));
        ui2_allPlayers->setText(QCoreApplication::translate("Client", "\346\237\245\347\234\213\347\216\251\345\256\266", nullptr));
        ui2_saveAndQuit->setText(QCoreApplication::translate("Client", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
        ui2_returnSignIn->setText(QCoreApplication::translate("Client", "\350\277\224\345\233\236\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        ui4_returnMainUi->setText(QCoreApplication::translate("Client", "\350\277\224\345\233\236", nullptr));
        ui3_returnMainUi->setText(QCoreApplication::translate("Client", "\350\277\224\345\233\236", nullptr));
        ui1_label->setText(QCoreApplication::translate("Client", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        ui1_background->setText(QString());
        ui1_signUp->setText(QCoreApplication::translate("Client", "\346\263\250\345\206\214\345\271\266\347\231\273\345\275\225", nullptr));
        ui1_signIn->setText(QCoreApplication::translate("Client", "\347\231\273\345\275\225", nullptr));
        ui1_label_2->setText(QCoreApplication::translate("Client", "\345\257\206\347\240\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
