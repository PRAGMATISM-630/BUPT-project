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
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *centralwidget;
    QLabel *ui6_enemyPokemon;
    QLineEdit *ui6_HP_2;
    QLineEdit *ui6_ATK;
    QLineEdit *ui6_SPD;
    QLineEdit *ui6_ATK_2;
    QLineEdit *ui6_DEF;
    QLineEdit *ui6_DEF_2;
    QLineEdit *ui6_SPD_2;
    QLineEdit *ui6_HP;
    QLabel *ui6_myPokemon;
    QToolButton *ui4_returnMainUi;
    QToolButton *ui5_return;
    QToolButton *ui3_returnMainUi;
    QToolButton *ui5_levelUp;
    QToolButton *ui5_battle;
    QLabel *ui5_hint;
    QToolButton *ui6_normalAttack;
    QToolButton *ui6_skill;
    QLabel *ui6_turn;
    QLabel *ui6_bullet;
    QLabel *ui7_winLose;
    QLabel *ui7_pokemon;
    QLabel *ui7_prize;
    QPushButton *ui7_ack;
    QLabel *ui7_exp;
    QLabel *ui6_bullet_2;
    QLabel *ui6_damage;
    QLabel *ui6_mark;
    QToolButton *ui6_enemyTurn;
    QToolButton *ui6_returnMainUi;
    QToolButton *ui2_myPokemon;
    QToolButton *ui2_prize;
    QToolButton *ui2_saveAndQuit;
    QToolButton *ui2_battle;
    QToolButton *ui2_allPlayers;
    QToolButton *ui2_returnSignIn;
    QLabel *ui8_silver2;
    QLabel *ui8_bronze1;
    QToolButton *ui8_win;
    QLabel *ui8_silver1;
    QLabel *ui8_golden1;
    QToolButton *ui8_lose;
    QToolButton *ui8_per;
    QLabel *ui8_bronze2;
    QLabel *ui8_golden2;
    QToolButton *ui8_returnMainUi;
    QLabel *hint;
    QToolButton *ui6_autobattle;
    QLabel *ui6_enemyfire;
    QLabel *ui6_myfire;
    QLabel *ui8_normal;
    QLabel *ui8_super;
    QToolButton *ui5_rules;
    QToolButton *ui6_rules;
    QToolButton *ui1_background;
    QPushButton *ui1_signUp;
    QLineEdit *ui1_userName;
    QLabel *ui1_label;
    QPushButton *ui1_signIn;
    QLineEdit *ui1_password;
    QLabel *ui1_label_2;
    QLabel *ui1_img4;
    QLabel *ui1_img1;
    QLabel *ui1_img3;
    QLabel *ui1_trademark;
    QLabel *ui1_img2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(800, 600);
        centralwidget = new QWidget(Client);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ui6_enemyPokemon = new QLabel(centralwidget);
        ui6_enemyPokemon->setObjectName(QString::fromUtf8("ui6_enemyPokemon"));
        ui6_enemyPokemon->setGeometry(QRect(521, 240, 211, 211));
        ui6_HP_2 = new QLineEdit(centralwidget);
        ui6_HP_2->setObjectName(QString::fromUtf8("ui6_HP_2"));
        ui6_HP_2->setGeometry(QRect(570, 50, 131, 25));
        ui6_HP_2->setFocusPolicy(Qt::NoFocus);
        ui6_ATK = new QLineEdit(centralwidget);
        ui6_ATK->setObjectName(QString::fromUtf8("ui6_ATK"));
        ui6_ATK->setGeometry(QRect(82, 80, 131, 25));
        ui6_ATK->setFocusPolicy(Qt::NoFocus);
        ui6_SPD = new QLineEdit(centralwidget);
        ui6_SPD->setObjectName(QString::fromUtf8("ui6_SPD"));
        ui6_SPD->setGeometry(QRect(82, 140, 131, 25));
        ui6_SPD->setFocusPolicy(Qt::NoFocus);
        ui6_ATK_2 = new QLineEdit(centralwidget);
        ui6_ATK_2->setObjectName(QString::fromUtf8("ui6_ATK_2"));
        ui6_ATK_2->setGeometry(QRect(570, 80, 131, 25));
        ui6_ATK_2->setFocusPolicy(Qt::NoFocus);
        ui6_DEF = new QLineEdit(centralwidget);
        ui6_DEF->setObjectName(QString::fromUtf8("ui6_DEF"));
        ui6_DEF->setGeometry(QRect(82, 110, 131, 25));
        ui6_DEF->setFocusPolicy(Qt::NoFocus);
        ui6_DEF_2 = new QLineEdit(centralwidget);
        ui6_DEF_2->setObjectName(QString::fromUtf8("ui6_DEF_2"));
        ui6_DEF_2->setGeometry(QRect(570, 110, 131, 25));
        ui6_DEF_2->setFocusPolicy(Qt::NoFocus);
        ui6_SPD_2 = new QLineEdit(centralwidget);
        ui6_SPD_2->setObjectName(QString::fromUtf8("ui6_SPD_2"));
        ui6_SPD_2->setGeometry(QRect(570, 140, 131, 25));
        ui6_SPD_2->setFocusPolicy(Qt::NoFocus);
        ui6_HP = new QLineEdit(centralwidget);
        ui6_HP->setObjectName(QString::fromUtf8("ui6_HP"));
        ui6_HP->setGeometry(QRect(82, 50, 131, 25));
        ui6_HP->setFocusPolicy(Qt::NoFocus);
        ui6_myPokemon = new QLabel(centralwidget);
        ui6_myPokemon->setObjectName(QString::fromUtf8("ui6_myPokemon"));
        ui6_myPokemon->setGeometry(QRect(50, 240, 211, 211));
        ui4_returnMainUi = new QToolButton(centralwidget);
        ui4_returnMainUi->setObjectName(QString::fromUtf8("ui4_returnMainUi"));
        ui4_returnMainUi->setGeometry(QRect(10, 10, 80, 40));
        ui5_return = new QToolButton(centralwidget);
        ui5_return->setObjectName(QString::fromUtf8("ui5_return"));
        ui5_return->setGeometry(QRect(10, 10, 80, 40));
        ui3_returnMainUi = new QToolButton(centralwidget);
        ui3_returnMainUi->setObjectName(QString::fromUtf8("ui3_returnMainUi"));
        ui3_returnMainUi->setGeometry(QRect(10, 10, 80, 40));
        ui5_levelUp = new QToolButton(centralwidget);
        ui5_levelUp->setObjectName(QString::fromUtf8("ui5_levelUp"));
        ui5_levelUp->setGeometry(QRect(90, 130, 250, 380));
        ui5_battle = new QToolButton(centralwidget);
        ui5_battle->setObjectName(QString::fromUtf8("ui5_battle"));
        ui5_battle->setGeometry(QRect(440, 130, 250, 380));
        ui5_hint = new QLabel(centralwidget);
        ui5_hint->setObjectName(QString::fromUtf8("ui5_hint"));
        ui5_hint->setGeometry(QRect(210, 10, 371, 41));
        ui6_normalAttack = new QToolButton(centralwidget);
        ui6_normalAttack->setObjectName(QString::fromUtf8("ui6_normalAttack"));
        ui6_normalAttack->setGeometry(QRect(310, 450, 65, 85));
        ui6_skill = new QToolButton(centralwidget);
        ui6_skill->setObjectName(QString::fromUtf8("ui6_skill"));
        ui6_skill->setGeometry(QRect(410, 450, 65, 85));
        ui6_turn = new QLabel(centralwidget);
        ui6_turn->setObjectName(QString::fromUtf8("ui6_turn"));
        ui6_turn->setGeometry(QRect(260, 20, 261, 71));
        ui6_bullet = new QLabel(centralwidget);
        ui6_bullet->setObjectName(QString::fromUtf8("ui6_bullet"));
        ui6_bullet->setGeometry(QRect(270, 290, 50, 50));
        ui7_winLose = new QLabel(centralwidget);
        ui7_winLose->setObjectName(QString::fromUtf8("ui7_winLose"));
        ui7_winLose->setGeometry(QRect(210, 30, 351, 151));
        ui7_pokemon = new QLabel(centralwidget);
        ui7_pokemon->setObjectName(QString::fromUtf8("ui7_pokemon"));
        ui7_pokemon->setGeometry(QRect(110, 180, 251, 251));
        ui7_prize = new QLabel(centralwidget);
        ui7_prize->setObjectName(QString::fromUtf8("ui7_prize"));
        ui7_prize->setGeometry(QRect(480, 150, 191, 141));
        ui7_ack = new QPushButton(centralwidget);
        ui7_ack->setObjectName(QString::fromUtf8("ui7_ack"));
        ui7_ack->setGeometry(QRect(500, 420, 141, 51));
        ui7_exp = new QLabel(centralwidget);
        ui7_exp->setObjectName(QString::fromUtf8("ui7_exp"));
        ui7_exp->setGeometry(QRect(480, 320, 191, 71));
        ui6_bullet_2 = new QLabel(centralwidget);
        ui6_bullet_2->setObjectName(QString::fromUtf8("ui6_bullet_2"));
        ui6_bullet_2->setGeometry(QRect(480, 290, 50, 50));
        ui6_damage = new QLabel(centralwidget);
        ui6_damage->setObjectName(QString::fromUtf8("ui6_damage"));
        ui6_damage->setGeometry(QRect(710, 160, 91, 61));
        ui6_mark = new QLabel(centralwidget);
        ui6_mark->setObjectName(QString::fromUtf8("ui6_mark"));
        ui6_mark->setGeometry(QRect(280, 190, 221, 61));
        ui6_enemyTurn = new QToolButton(centralwidget);
        ui6_enemyTurn->setObjectName(QString::fromUtf8("ui6_enemyTurn"));
        ui6_enemyTurn->setGeometry(QRect(340, 360, 70, 70));
        ui6_returnMainUi = new QToolButton(centralwidget);
        ui6_returnMainUi->setObjectName(QString::fromUtf8("ui6_returnMainUi"));
        ui6_returnMainUi->setGeometry(QRect(10, 10, 80, 40));
        ui2_myPokemon = new QToolButton(centralwidget);
        ui2_myPokemon->setObjectName(QString::fromUtf8("ui2_myPokemon"));
        ui2_myPokemon->setGeometry(QRect(330, 60, 120, 140));
        ui2_prize = new QToolButton(centralwidget);
        ui2_prize->setObjectName(QString::fromUtf8("ui2_prize"));
        ui2_prize->setGeometry(QRect(550, 180, 120, 140));
        ui2_saveAndQuit = new QToolButton(centralwidget);
        ui2_saveAndQuit->setObjectName(QString::fromUtf8("ui2_saveAndQuit"));
        ui2_saveAndQuit->setGeometry(QRect(500, 400, 120, 140));
        ui2_battle = new QToolButton(centralwidget);
        ui2_battle->setObjectName(QString::fromUtf8("ui2_battle"));
        ui2_battle->setGeometry(QRect(290, 200, 210, 230));
        ui2_allPlayers = new QToolButton(centralwidget);
        ui2_allPlayers->setObjectName(QString::fromUtf8("ui2_allPlayers"));
        ui2_allPlayers->setGeometry(QRect(120, 180, 120, 140));
        ui2_returnSignIn = new QToolButton(centralwidget);
        ui2_returnSignIn->setObjectName(QString::fromUtf8("ui2_returnSignIn"));
        ui2_returnSignIn->setGeometry(QRect(170, 400, 120, 140));
        ui8_silver2 = new QLabel(centralwidget);
        ui8_silver2->setObjectName(QString::fromUtf8("ui8_silver2"));
        ui8_silver2->setGeometry(QRect(210, 330, 121, 161));
        ui8_bronze1 = new QLabel(centralwidget);
        ui8_bronze1->setObjectName(QString::fromUtf8("ui8_bronze1"));
        ui8_bronze1->setGeometry(QRect(50, 90, 121, 161));
        ui8_win = new QToolButton(centralwidget);
        ui8_win->setObjectName(QString::fromUtf8("ui8_win"));
        ui8_win->setGeometry(QRect(570, 120, 151, 81));
        ui8_silver1 = new QLabel(centralwidget);
        ui8_silver1->setObjectName(QString::fromUtf8("ui8_silver1"));
        ui8_silver1->setGeometry(QRect(210, 90, 121, 161));
        ui8_golden1 = new QLabel(centralwidget);
        ui8_golden1->setObjectName(QString::fromUtf8("ui8_golden1"));
        ui8_golden1->setGeometry(QRect(370, 90, 121, 161));
        ui8_lose = new QToolButton(centralwidget);
        ui8_lose->setObjectName(QString::fromUtf8("ui8_lose"));
        ui8_lose->setGeometry(QRect(570, 270, 151, 81));
        ui8_per = new QToolButton(centralwidget);
        ui8_per->setObjectName(QString::fromUtf8("ui8_per"));
        ui8_per->setGeometry(QRect(570, 420, 151, 81));
        ui8_bronze2 = new QLabel(centralwidget);
        ui8_bronze2->setObjectName(QString::fromUtf8("ui8_bronze2"));
        ui8_bronze2->setGeometry(QRect(50, 330, 121, 161));
        ui8_golden2 = new QLabel(centralwidget);
        ui8_golden2->setObjectName(QString::fromUtf8("ui8_golden2"));
        ui8_golden2->setGeometry(QRect(370, 330, 121, 161));
        ui8_returnMainUi = new QToolButton(centralwidget);
        ui8_returnMainUi->setObjectName(QString::fromUtf8("ui8_returnMainUi"));
        ui8_returnMainUi->setGeometry(QRect(10, 10, 80, 40));
        hint = new QLabel(centralwidget);
        hint->setObjectName(QString::fromUtf8("hint"));
        hint->setGeometry(QRect(180, 10, 421, 51));
        ui6_autobattle = new QToolButton(centralwidget);
        ui6_autobattle->setObjectName(QString::fromUtf8("ui6_autobattle"));
        ui6_autobattle->setGeometry(QRect(355, 340, 70, 90));
        ui6_enemyfire = new QLabel(centralwidget);
        ui6_enemyfire->setObjectName(QString::fromUtf8("ui6_enemyfire"));
        ui6_enemyfire->setGeometry(QRect(520, 480, 211, 41));
        ui6_myfire = new QLabel(centralwidget);
        ui6_myfire->setObjectName(QString::fromUtf8("ui6_myfire"));
        ui6_myfire->setGeometry(QRect(50, 480, 211, 41));
        ui8_normal = new QLabel(centralwidget);
        ui8_normal->setObjectName(QString::fromUtf8("ui8_normal"));
        ui8_normal->setGeometry(QRect(170, 260, 201, 40));
        ui8_super = new QLabel(centralwidget);
        ui8_super->setObjectName(QString::fromUtf8("ui8_super"));
        ui8_super->setGeometry(QRect(170, 500, 201, 40));
        ui5_rules = new QToolButton(centralwidget);
        ui5_rules->setObjectName(QString::fromUtf8("ui5_rules"));
        ui5_rules->setGeometry(QRect(690, 50, 50, 50));
        ui6_rules = new QToolButton(centralwidget);
        ui6_rules->setObjectName(QString::fromUtf8("ui6_rules"));
        ui6_rules->setGeometry(QRect(730, 40, 50, 50));
        ui1_background = new QToolButton(centralwidget);
        ui1_background->setObjectName(QString::fromUtf8("ui1_background"));
        ui1_background->setGeometry(QRect(280, 245, 220, 230));
        ui1_signUp = new QPushButton(centralwidget);
        ui1_signUp->setObjectName(QString::fromUtf8("ui1_signUp"));
        ui1_signUp->setGeometry(QRect(300, 410, 181, 31));
        ui1_userName = new QLineEdit(centralwidget);
        ui1_userName->setObjectName(QString::fromUtf8("ui1_userName"));
        ui1_userName->setGeometry(QRect(360, 281, 121, 25));
        ui1_label = new QLabel(centralwidget);
        ui1_label->setObjectName(QString::fromUtf8("ui1_label"));
        ui1_label->setGeometry(QRect(300, 280, 54, 21));
        ui1_signIn = new QPushButton(centralwidget);
        ui1_signIn->setObjectName(QString::fromUtf8("ui1_signIn"));
        ui1_signIn->setGeometry(QRect(300, 370, 181, 31));
        ui1_password = new QLineEdit(centralwidget);
        ui1_password->setObjectName(QString::fromUtf8("ui1_password"));
        ui1_password->setGeometry(QRect(360, 320, 121, 25));
        ui1_password->setEchoMode(QLineEdit::Password);
        ui1_label_2 = new QLabel(centralwidget);
        ui1_label_2->setObjectName(QString::fromUtf8("ui1_label_2"));
        ui1_label_2->setGeometry(QRect(300, 320, 54, 21));
        ui1_img4 = new QLabel(centralwidget);
        ui1_img4->setObjectName(QString::fromUtf8("ui1_img4"));
        ui1_img4->setGeometry(QRect(520, 370, 180, 180));
        ui1_img1 = new QLabel(centralwidget);
        ui1_img1->setObjectName(QString::fromUtf8("ui1_img1"));
        ui1_img1->setGeometry(QRect(20, 200, 180, 180));
        ui1_img3 = new QLabel(centralwidget);
        ui1_img3->setObjectName(QString::fromUtf8("ui1_img3"));
        ui1_img3->setGeometry(QRect(600, 210, 180, 180));
        ui1_trademark = new QLabel(centralwidget);
        ui1_trademark->setObjectName(QString::fromUtf8("ui1_trademark"));
        ui1_trademark->setGeometry(QRect(170, 0, 445, 236));
        ui1_img2 = new QLabel(centralwidget);
        ui1_img2->setObjectName(QString::fromUtf8("ui1_img2"));
        ui1_img2->setGeometry(QRect(80, 370, 180, 180));
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
        ui6_enemyPokemon->setText(QCoreApplication::translate("Client", "\346\225\214\346\226\271\345\256\235\345\217\257\346\242\246\350\264\264\345\233\276", nullptr));
        ui6_DEF->setText(QString());
        ui6_DEF_2->setText(QString());
        ui6_myPokemon->setText(QCoreApplication::translate("Client", "\346\210\221\346\226\271\345\256\235\345\217\257\346\242\246\350\264\264\345\233\276", nullptr));
        ui4_returnMainUi->setText(QCoreApplication::translate("Client", "\350\277\224\345\233\236", nullptr));
        ui5_return->setText(QCoreApplication::translate("Client", "\350\277\224\345\233\236", nullptr));
        ui3_returnMainUi->setText(QCoreApplication::translate("Client", "\350\277\224\345\233\236", nullptr));
        ui5_levelUp->setText(QCoreApplication::translate("Client", "\n"
"\345\215\207\347\272\247\350\265\233\n"
"\n"
"\n"
"\351\200\211\346\213\251\345\256\235\345\217\257\346\242\246\344\270\216\346\234\215\345\212\241\345\231\250\350\277\233\350\241\214\350\231\232\346\213\237\345\206\263\346\226\227\n"
"\n"
"\345\217\257\344\273\245\344\270\272\345\256\235\345\217\257\346\242\246\350\216\267\345\276\227\347\273\217\351\252\214\n"
"\n"
"\350\203\234\345\210\251\344\270\215\344\274\232\350\216\267\345\276\227\345\256\235\345\217\257\346\242\246\n"
"\n"
"\345\244\261\350\264\245\344\271\237\344\270\215\344\274\232\345\244\261\345\216\273\345\256\235\345\217\257\346\242\246", nullptr));
        ui5_battle->setText(QCoreApplication::translate("Client", "\n"
"\345\206\263\346\226\227\350\265\233\n"
"\n"
"\n"
"\351\200\211\346\213\251\345\256\235\345\217\257\346\242\246\344\270\216\346\234\215\345\212\241\345\231\250\350\277\233\350\241\214\350\231\232\346\213\237\345\206\263\346\226\227\n"
"\n"
"\345\217\257\344\273\245\344\270\272\345\256\235\345\217\257\346\242\246\350\216\267\345\276\227\347\273\217\351\252\214\n"
"\n"
"\350\203\234\345\210\251\345\217\257\344\273\245\350\216\267\345\276\227\350\257\245\346\210\230\350\203\234\347\232\204\345\256\235\345\217\257\346\242\246\n"
"\n"
"\345\244\261\350\264\245\345\210\231\347\224\261\347\224\250\346\210\267\351\200\211\346\213\251\345\244\261\345\216\273\344\270\200\344\270\252\345\256\235\345\217\257\346\242\246", nullptr));
        ui5_hint->setText(QCoreApplication::translate("Client", "hint", nullptr));
        ui6_normalAttack->setText(QCoreApplication::translate("Client", "\346\231\256\346\224\273", nullptr));
        ui6_skill->setText(QCoreApplication::translate("Client", "\346\212\200\350\203\275", nullptr));
        ui6_turn->setText(QCoreApplication::translate("Client", "TextLabel", nullptr));
        ui6_bullet->setText(QCoreApplication::translate("Client", "TextLabel", nullptr));
        ui7_winLose->setText(QCoreApplication::translate("Client", "winLose", nullptr));
        ui7_pokemon->setText(QCoreApplication::translate("Client", "pokemon", nullptr));
        ui7_prize->setText(QCoreApplication::translate("Client", "prize", nullptr));
        ui7_ack->setText(QCoreApplication::translate("Client", "\347\241\256\350\256\244", nullptr));
        ui7_exp->setText(QCoreApplication::translate("Client", "exp", nullptr));
        ui6_bullet_2->setText(QCoreApplication::translate("Client", "TextLabel", nullptr));
        ui6_damage->setText(QCoreApplication::translate("Client", "damage", nullptr));
        ui6_mark->setText(QCoreApplication::translate("Client", "mark", nullptr));
        ui6_enemyTurn->setText(QString());
        ui6_returnMainUi->setText(QCoreApplication::translate("Client", "\350\277\224\345\233\236", nullptr));
        ui2_myPokemon->setText(QCoreApplication::translate("Client", "\345\256\235\345\217\257\346\242\246", nullptr));
        ui2_prize->setText(QCoreApplication::translate("Client", "\346\210\230\347\273\251", nullptr));
        ui2_saveAndQuit->setText(QCoreApplication::translate("Client", "\344\277\235\345\255\230\345\271\266\351\200\200\345\207\272", nullptr));
        ui2_battle->setText(QCoreApplication::translate("Client", "\346\210\230\346\226\227", nullptr));
        ui2_allPlayers->setText(QCoreApplication::translate("Client", "\347\216\251\345\256\266", nullptr));
        ui2_returnSignIn->setText(QCoreApplication::translate("Client", "\347\231\273\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        ui8_silver2->setToolTip(QCoreApplication::translate("Client", "\346\213\245\346\234\21110\345\217\252\346\273\241\347\272\247\345\256\235\345\217\257\346\242\246\346\227\266\350\216\267\345\276\227", nullptr));
#endif // QT_CONFIG(tooltip)
        ui8_silver2->setText(QCoreApplication::translate("Client", "TextLabel", nullptr));
#if QT_CONFIG(tooltip)
        ui8_bronze1->setToolTip(QCoreApplication::translate("Client", "\346\213\245\346\234\2115\345\217\252\345\256\235\345\217\257\346\242\246\346\227\266\350\216\267\345\276\227", nullptr));
#endif // QT_CONFIG(tooltip)
        ui8_bronze1->setText(QCoreApplication::translate("Client", "TextLabel", nullptr));
        ui8_win->setText(QCoreApplication::translate("Client", "\350\203\234\345\234\272\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        ui8_silver1->setToolTip(QCoreApplication::translate("Client", "\346\213\245\346\234\21110\345\217\252\345\256\235\345\217\257\346\242\246\346\227\266\350\216\267\345\276\227", nullptr));
#endif // QT_CONFIG(tooltip)
        ui8_silver1->setText(QCoreApplication::translate("Client", "TextLabel", nullptr));
#if QT_CONFIG(tooltip)
        ui8_golden1->setToolTip(QCoreApplication::translate("Client", "\346\213\245\346\234\21115\345\217\252\345\256\235\345\217\257\346\242\246\346\227\266\350\216\267\345\276\227", nullptr));
#endif // QT_CONFIG(tooltip)
        ui8_golden1->setText(QCoreApplication::translate("Client", "TextLabel", nullptr));
        ui8_lose->setText(QCoreApplication::translate("Client", "\350\264\237\345\234\272\357\274\232", nullptr));
        ui8_per->setText(QCoreApplication::translate("Client", "\350\203\234\347\216\207\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        ui8_bronze2->setToolTip(QCoreApplication::translate("Client", "\346\213\245\346\234\2115\345\217\252\346\273\241\347\272\247\345\256\235\345\217\257\346\242\246\346\227\266\350\216\267\345\276\227", nullptr));
#endif // QT_CONFIG(tooltip)
        ui8_bronze2->setText(QCoreApplication::translate("Client", "TextLabel", nullptr));
#if QT_CONFIG(tooltip)
        ui8_golden2->setToolTip(QCoreApplication::translate("Client", "\346\213\245\346\234\21115\345\217\252\346\273\241\347\272\247\345\256\235\345\217\257\346\242\246\346\227\266\350\216\267\345\276\227", nullptr));
#endif // QT_CONFIG(tooltip)
        ui8_golden2->setText(QCoreApplication::translate("Client", "TextLabel", nullptr));
        ui8_returnMainUi->setText(QCoreApplication::translate("Client", "\350\277\224\345\233\236", nullptr));
        hint->setText(QCoreApplication::translate("Client", "hint", nullptr));
        ui6_autobattle->setText(QCoreApplication::translate("Client", "\350\207\252\345\212\250\346\210\230\346\226\227", nullptr));
        ui6_enemyfire->setText(QCoreApplication::translate("Client", "TextLabel", nullptr));
        ui6_myfire->setText(QCoreApplication::translate("Client", "TextLabel", nullptr));
        ui8_normal->setText(QCoreApplication::translate("Client", "\345\256\235\345\217\257\346\242\246\345\276\275\347\253\240", nullptr));
        ui8_super->setText(QCoreApplication::translate("Client", "\351\253\230\347\272\247\345\256\235\345\217\257\346\242\246\345\276\275\347\253\240", nullptr));
        ui5_rules->setText(QString());
        ui6_rules->setText(QString());
        ui1_background->setText(QString());
        ui1_signUp->setText(QCoreApplication::translate("Client", "\346\263\250\345\206\214\345\271\266\347\231\273\345\275\225", nullptr));
        ui1_label->setText(QCoreApplication::translate("Client", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        ui1_signIn->setText(QCoreApplication::translate("Client", "\347\231\273\345\275\225", nullptr));
        ui1_label_2->setText(QCoreApplication::translate("Client", "\345\257\206\347\240\201\357\274\232", nullptr));
        ui1_img4->setText(QCoreApplication::translate("Client", "TextLabel", nullptr));
        ui1_img1->setText(QCoreApplication::translate("Client", "TextLabel", nullptr));
        ui1_img3->setText(QCoreApplication::translate("Client", "TextLabel", nullptr));
        ui1_trademark->setText(QCoreApplication::translate("Client", "TextLabel", nullptr));
        ui1_img2->setText(QCoreApplication::translate("Client", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
