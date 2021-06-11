#include "client.h"
#include "ui_client.h"

/////////////////////////////
//
//  filename: uiDesign.cpp
//  function: ui界面设计相关函数
//
/////////////////////////////


void Client::setStyleSheet()const                    //设置样式
{
    ui->ui1_signIn->setStyleSheet("border:2px groove gray;border-radius:15px;padding:2px 4px;");
    ui->ui1_signUp->setStyleSheet("border:2px groove gray;border-radius:15px;padding:2px 4px;");
    ui->ui5_battle->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->ui5_levelUp->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->ui1_password->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->ui1_userName->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->ui6_ATK->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->ui6_ATK_2->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->ui6_DEF->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->ui6_DEF_2->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->ui6_HP->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->ui6_HP_2->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->ui6_SPD->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->ui6_SPD_2->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->ui7_ack->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->ui8_per->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->ui8_win->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->ui8_lose->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");

}

void Client::hideWidget()const                       //隐藏控件
{
    ui->hint->setHidden(true);
    ui->ui5_hint->setHidden(true);
    ui->ui2_myPokemon->setHidden(true);
    ui->ui2_allPlayers->setHidden(true);
    ui->ui2_saveAndQuit->setHidden(true);
    ui->ui2_returnSignIn->setHidden(true);
    ui->ui2_battle->setHidden(true);
    ui->ui2_prize->setHidden(true);
    ui->ui3_returnMainUi->setHidden(true);
    ui->ui4_returnMainUi->setHidden(true);
    ui->ui5_battle->setHidden(true);
    ui->ui5_return->setHidden(true);
    ui->ui5_levelUp->setHidden(true);
    ui->ui5_rules->setHidden(true);
    ui->ui6_HP->setHidden(true);
    ui->ui6_HP_2->setHidden(true);
    ui->ui6_ATK->setHidden(true);
    ui->ui6_ATK_2->setHidden(true);
    ui->ui6_DEF->setHidden(true);
    ui->ui6_DEF_2->setHidden(true);
    ui->ui6_SPD->setHidden(true);
    ui->ui6_SPD_2->setHidden(true);
    ui->ui6_enemyPokemon->setHidden(true);
    ui->ui6_myPokemon->setHidden(true);
    ui->ui6_skill->setHidden(true);
    ui->ui6_normalAttack->setHidden(true);
    ui->ui6_rules->setHidden(true);
    ui->ui6_turn->setHidden(true);
    ui->ui6_bullet->setHidden(true);
    ui->ui6_bullet_2->setHidden(true);
    ui->ui6_enemyTurn->setHidden(true);
    ui->ui6_autobattle->setHidden(true);
    ui->ui6_damage->setHidden(true);
    ui->ui6_mark->setHidden(true);
    ui->ui6_returnMainUi->setHidden(true);
    ui->ui6_myfire->setHidden(true);
    ui->ui6_enemyfire->setHidden(true);
    ui->ui7_exp->setHidden(true);
    ui->ui7_ack->setHidden(true);
    ui->ui7_prize->setHidden(true);
    ui->ui7_pokemon->setHidden(true);
    ui->ui7_winLose->setHidden(true);
    ui->ui8_win->setHidden(true);
    ui->ui8_lose->setHidden(true);
    ui->ui8_per->setHidden(true);
    ui->ui8_bronze1->setHidden(true);
    ui->ui8_bronze2->setHidden(true);
    ui->ui8_silver1->setHidden(true);
    ui->ui8_silver2->setHidden(true);
    ui->ui8_golden1->setHidden(true);
    ui->ui8_golden2->setHidden(true);
    ui->ui8_returnMainUi->setHidden(true);
    ui->ui8_normal->setHidden(true);
    ui->ui8_super->setHidden(true);

}

void Client::setButtonIcon()const                    //设置按钮图标
{
    QIcon icon("./resourse/icon.png");
    ui->ui2_myPokemon->setIcon(icon);
    ui->ui2_myPokemon->setIconSize(QSize(120,120));
    ui->ui2_myPokemon->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui2_myPokemon->setFocusPolicy(Qt::NoFocus);
    ui->ui2_myPokemon->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    icon=QIcon("./resourse/prize.png");
    ui->ui2_prize->setIcon(icon);
    ui->ui2_prize->setIconSize(QSize(120,120));
    ui->ui2_prize->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui2_prize->setFocusPolicy(Qt::NoFocus);
    ui->ui2_prize->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    icon=QIcon("./resourse/quit.png");
    ui->ui2_returnSignIn->setIcon(icon);
    ui->ui2_returnSignIn->setIconSize(QSize(120,120));
    ui->ui2_returnSignIn->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui2_returnSignIn->setFocusPolicy(Qt::NoFocus);
    ui->ui2_returnSignIn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    icon=QIcon("./resourse/users.png");
    ui->ui2_allPlayers->setIcon(icon);
    ui->ui2_allPlayers->setIconSize(QSize(120,120));
    ui->ui2_allPlayers->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui2_allPlayers->setFocusPolicy(Qt::NoFocus);
    ui->ui2_allPlayers->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    icon=QIcon("./resourse/close.png");
    ui->ui2_saveAndQuit->setIcon(icon);
    ui->ui2_saveAndQuit->setIconSize(QSize(120,120));
    ui->ui2_saveAndQuit->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui2_saveAndQuit->setFocusPolicy(Qt::NoFocus);
    ui->ui2_saveAndQuit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    icon=QIcon("./resourse/battle.png");
    ui->ui2_battle->setIcon(icon);
    ui->ui2_battle->setIconSize(QSize(210,210));
    ui->ui2_battle->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui2_battle->setFocusPolicy(Qt::NoFocus);
    ui->ui2_battle->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    icon=QIcon("./resourse/return.png");
    ui->ui3_returnMainUi->setIcon(icon);
    ui->ui3_returnMainUi->setIconSize(QSize(40,40));
    ui->ui3_returnMainUi->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui3_returnMainUi->setFocusPolicy(Qt::NoFocus);
    ui->ui3_returnMainUi->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->ui4_returnMainUi->setIcon(icon);
    ui->ui4_returnMainUi->setIconSize(QSize(40,40));
    ui->ui4_returnMainUi->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui4_returnMainUi->setFocusPolicy(Qt::NoFocus);
    ui->ui4_returnMainUi->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->ui6_returnMainUi->setIcon(icon);
    ui->ui6_returnMainUi->setIconSize(QSize(40,40));
    ui->ui6_returnMainUi->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui6_returnMainUi->setFocusPolicy(Qt::NoFocus);
    ui->ui6_returnMainUi->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->ui8_returnMainUi->setIcon(icon);
    ui->ui8_returnMainUi->setIconSize(QSize(40,40));
    ui->ui8_returnMainUi->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui8_returnMainUi->setFocusPolicy(Qt::NoFocus);
    ui->ui8_returnMainUi->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);


    ui->ui5_return->setIcon(icon);
    ui->ui5_return->setIconSize(QSize(40,40));
    ui->ui5_return->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui5_return->setFocusPolicy(Qt::NoFocus);
    ui->ui5_return->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    icon=QIcon("./resourse/levelup.png");
    ui->ui5_levelUp->setIcon(icon);
    ui->ui5_levelUp->setIconSize(QSize(100,100));
    //ui->ui5_levelUp->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui5_levelUp->setFocusPolicy(Qt::NoFocus);
    ui->ui5_levelUp->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    icon=QIcon("./resourse/pk.png");
    ui->ui5_battle->setIcon(icon);
    ui->ui5_battle->setIconSize(QSize(100,100));
    //ui->ui5_battle->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui5_battle->setFocusPolicy(Qt::NoFocus);
    ui->ui5_battle->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    icon=QIcon("./resourse/auto.png");
    ui->ui6_enemyTurn->setIcon(icon);
    ui->ui6_enemyTurn->setIconSize(QSize(70,70));
    ui->ui6_enemyTurn->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui6_enemyTurn->setFocusPolicy(Qt::NoFocus);
    ui->ui6_enemyTurn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    icon=QIcon("./resourse/auto.png");
    ui->ui6_autobattle->setIcon(icon);
    ui->ui6_autobattle->setIconSize(QSize(70,70));
    ui->ui6_autobattle->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui6_autobattle->setFocusPolicy(Qt::NoFocus);
    ui->ui6_autobattle->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    icon=QIcon("./resourse/attack.png");
    ui->ui6_normalAttack->setIcon(icon);
    ui->ui6_normalAttack->setIconSize(QSize(65,65));
    ui->ui6_normalAttack->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui6_normalAttack->setFocusPolicy(Qt::NoFocus);
    ui->ui6_normalAttack->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    icon=QIcon("./resourse/skill.png");
    ui->ui6_skill->setIcon(icon);
    ui->ui6_skill->setIconSize(QSize(65,65));
    ui->ui6_skill->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui6_skill->setFocusPolicy(Qt::NoFocus);
    ui->ui6_skill->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    icon=QIcon("./resourse/wenhao.png");
    ui->ui5_rules->setIcon(icon);
    ui->ui5_rules->setIconSize(QSize(50,50));
    ui->ui5_rules->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui5_rules->setFocusPolicy(Qt::NoFocus);
    ui->ui5_rules->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    ui->ui6_rules->setIcon(icon);
    ui->ui6_rules->setIconSize(QSize(50,50));
    ui->ui6_rules->setStyleSheet("background-color:rgba(0,0,0,0)");
    ui->ui6_rules->setFocusPolicy(Qt::NoFocus);
    ui->ui6_rules->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);


}

void Client::setBackground()                         //设置标题界面（登录界面）背景图片
{
    QPalette pallBackground=this->palette();
    QImage Image("./resourse/background.jpg");
    //QImage Image("./resourse/cover.png");
    QImage autoFillImage=Image.scaled(this->width(),this->height(),Qt::IgnoreAspectRatio);
    pallBackground.setBrush(QPalette::Window,QBrush(autoFillImage));
    this->setPalette(pallBackground);

    QString path="./resourse/jigglypuff.png";         //图片所在路径
    QImage image(path);
    QPixmap pixmap=QPixmap::fromImage(image.mirrored(true,false));
    ui->ui1_img1->setPixmap(pixmap);
    ui->ui1_img1->setScaledContents(true);

    path="./resourse/bulbasaur.png";         //图片所在路径
    QImage image2(path);
    QPixmap pixmap2=QPixmap::fromImage(image2.mirrored(true,false));
    ui->ui1_img2->setPixmap(pixmap2);
    ui->ui1_img2->setScaledContents(true);

    path="./resourse/squirtle.png";         //图片所在路径
    QImage image3(path);
    QPixmap pixmap3=QPixmap::fromImage(image3.mirrored(false,false));
    ui->ui1_img3->setPixmap(pixmap3);
    ui->ui1_img3->setScaledContents(true);

    path="./resourse/pikachu.png";         //图片所在路径
    QImage image4(path);
    QPixmap pixmap4=QPixmap::fromImage(image4.mirrored(false,false));
    ui->ui1_img4->setPixmap(pixmap4);
    ui->ui1_img4->setScaledContents(true);

    path="./resourse/trademark.png";         //图片所在路径
    QImage image5(path);
    QPixmap pixmap5=QPixmap::fromImage(image5.mirrored(false,false));
    ui->ui1_trademark->setPixmap(pixmap5);
    ui->ui1_trademark->setScaledContents(true);
}

void Client::otherSettings()const                    //其他设置
{
    ui->ui1_background->setStyleSheet("border:2px groove gray;border-radius:15px;padding:2px 4px;");

    //ui->ui1_label->raise();     //使ui1_label于背景上方显示

    ui->hint->setAlignment(Qt::AlignCenter);
    ui->ui5_hint->setAlignment(Qt::AlignCenter);
    ui->ui6_turn->setAlignment(Qt::AlignCenter);
    ui->ui6_damage->setAlignment(Qt::AlignCenter);
    ui->ui6_mark->setAlignment(Qt::AlignCenter);
    ui->ui8_super->setAlignment(Qt::AlignCenter);
    ui->ui8_normal->setAlignment(Qt::AlignCenter);

    QFont font;
    font.setPointSize(30);
    font.setFamily("仿宋");
    font.setBold(true);
    ui->ui6_turn->setFont(font);

    QPalette pa;
    pa.setColor(QPalette::WindowText,QColor(31,30,51));
    ui->ui6_turn->setPalette(pa);

    font.setPointSize(20);
    font.setFamily("仿宋");
    font.setBold(true);
    ui->ui6_damage->setFont(font);

    pa.setColor(QPalette::WindowText,Qt::red);
    ui->ui6_damage->setPalette(pa);

    font.setPointSize(25);
    font.setFamily("仿宋");
    font.setBold(true);
    ui->ui6_mark->setFont(font);

    pa.setColor(QPalette::WindowText,Qt::blue);
    ui->ui6_mark->setPalette(pa);

    ui->ui5_hint->setFont(QFont("微软雅黑",14));
    ui->hint->setFont(QFont("微软雅黑",18));
    ui->ui8_super->setFont(QFont("仿宋",16));
    ui->ui8_normal->setFont(QFont("仿宋",16));

    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::red);
    ui->ui5_hint->setPalette(palette);
    ui->hint->setPalette(palette);
    //ui->ui7_ack->setFlat(true);

    QPixmap *pixmap = new QPixmap("./resourse/bronze.png");
    pixmap->scaled(ui->ui8_bronze1->size(), Qt::KeepAspectRatio);
    ui->ui8_bronze1->setScaledContents(true);
    ui->ui8_bronze1->setPixmap(*pixmap);

    pixmap = new QPixmap("./resourse/bronze_2.png");
    pixmap->scaled(ui->ui8_bronze2->size(), Qt::KeepAspectRatio);
    ui->ui8_bronze2->setScaledContents(true);
    ui->ui8_bronze2->setPixmap(*pixmap);

    pixmap = new QPixmap("./resourse/silver.png");
    pixmap->scaled(ui->ui8_silver1->size(), Qt::KeepAspectRatio);
    ui->ui8_silver1->setScaledContents(true);
    ui->ui8_silver1->setPixmap(*pixmap);

    pixmap = new QPixmap("./resourse/silver_2.png");
    pixmap->scaled(ui->ui8_silver2->size(), Qt::KeepAspectRatio);
    ui->ui8_silver2->setScaledContents(true);
    ui->ui8_silver2->setPixmap(*pixmap);

    pixmap = new QPixmap("./resourse/golden.png");
    pixmap->scaled(ui->ui8_golden1->size(), Qt::KeepAspectRatio);
    ui->ui8_golden1->setScaledContents(true);
    ui->ui8_golden1->setPixmap(*pixmap);

    pixmap = new QPixmap("./resourse/golden_2.png");
    pixmap->scaled(ui->ui8_golden2->size(), Qt::KeepAspectRatio);
    ui->ui8_golden2->setScaledContents(true);
    ui->ui8_golden2->setPixmap(*pixmap);


}

