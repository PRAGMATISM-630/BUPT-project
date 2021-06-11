#ifndef CLIENT_H
#define CLIENT_H

/////////////////////////////
//
//  filename: client.h
//  function: 定义了客户端相关的类
//
/////////////////////////////

#include "pokemonsubtype.h"
#include "getnewpokemon.h"
#include "rule.h"

#include <QMainWindow>
#include <QUdpSocket>
#include <QVector>
#include <QTableWidget>
#include <QSignalMapper>
#include <QPixmap>
#include <QRandomGenerator>
#include <QMovie>
#include <QIcon>
#include <QCloseEvent>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <windows.h>


enum state{SIGN_IN,SIGN_UP,GET_POKEMON_INFO,GET_ALL_PLAYERS,GET_OTHER_POKEMON_INFO,UPDATE_DATABASE,USER_INFO};
//操作类型：登录/注册/获取宝可梦信息/查看所有玩家信息/获取其他玩家的宝可梦信息/更新数据库/用户信息

struct user     //用户信息结构体，也是客户端与服务器端通信的单元
{
    state clientState;              //操作类型
    QString userName;               //用户名
    QString password;               //密码
    QVector<pokemon*>pokemonInfo;   //宝可梦仓库，用于更新数据库
    int win,lose;                   //胜负场    
    int numPokemon,numSuperPokemon; //宝可梦和高级宝可梦数量
    double winningPercentage;       //胜率
};


QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Client : public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

    //界面设计
    void changeUi(int n)const;                  //切换界面
    void setStyleSheet()const;                  //设置样式
    void hideWidget()const;                     //隐藏控件
    void setButtonIcon()const;                  //设置按钮图标
    void setBackground();                       //设置背景图片
    void otherSettings()const;                  //其他设置

    //战斗相关
    void initializeUi6();                       //初始化战斗界面
    void enemyTurn();                           //敌方回合
    void enemyTurnSkill();                      //敌方回合使用技能
    void updateMyFire();                        //更新我方怒气值
    void updateEnemyFire();                     //更新敌方怒气值
    void sendPokemon();                         //决斗赛战斗失败时送走一只宝可梦
    pokemon* getPokemon();                      //获取宝可梦


    void updateDatabase()const;                  //更新数据库

    QString getChineseName(QString)const;        //将名字翻译为中文


protected:
    void closeEvent(QCloseEvent *event);    //重写关闭事件


private slots:
    void updateMyBullet();                      //更新我方子弹坐标

    void updateEnemyBullet();                   //更新敌方子弹坐标

    void getOtherPokemonInfo(const QString &);  //查看其他用户的宝可梦信息

    void selectMyPokemon(const QString &);      //选择我方参战宝可梦

    void selectEnemyPokemon(const QString &);   //选择敌方参战宝可梦

    void selectSendPokemon(const QString &);    //选择送出的宝可梦

    void readPendingDatagrams();                //读取服务器端的数据报

    void on_ui1_signIn_clicked();               //登录界面——登录

    void on_ui1_signUp_clicked();               //登录界面——注册

    void on_ui2_returnSignIn_clicked();         //主界面——返回登陆界面

    void on_ui2_saveAndQuit_clicked();          //主界面——保存并退出

    void on_ui2_myPokemon_clicked();            //主界面——查看我的宝可梦

    void on_ui2_allPlayers_clicked();           //主界面——查看所有用户

    void on_ui2_battle_clicked();               //主界面——战斗

    void on_ui2_prize_clicked();                //主界面——查看成就界面

    void on_ui3_returnMainUi_clicked();         //用户展示界面——返回主界面

    void on_ui4_returnMainUi_clicked();         //宝可梦展示界面——返回主界面

    void on_ui5_return_clicked();               //战斗选择界面——返回

    void on_ui5_levelUp_clicked();              //战斗选择界面——升级赛

    void on_ui5_battle_clicked();               //战斗选择界面——决斗赛

    void on_ui5_rules_clicked();                //战斗选择界面——查看规则提示

    void on_ui6_normalAttack_clicked();         //战斗界面——普通攻击

    void on_ui6_enemyTurn_clicked();            //战斗界面——敌方回合

    void on_ui6_returnMainUi_clicked();         //战斗界面——退出战斗

    void on_ui6_autobattle_clicked();           //战斗界面——自动战斗

    void on_ui6_skill_clicked();                //战斗界面——释放技能

    void on_ui6_rules_clicked();                //战斗界面——查看规则提示

    void on_ui7_ack_clicked();                  //战斗结算界面——确认

    void on_ui8_returnMainUi_clicked();         //成就界面——返回主界面


private:
    Ui::Client *ui;                 //ui界面

    getNewPokemon *getnewpokemon;   //新窗口——获得新宝可梦

    rule *rules;                    //新窗口——规则

    QUdpSocket *udpSocket;          //UDP套接字

    QVector<pokemon*>pokemonVector,otherPokemonVector;  //宝可梦容器（宝可梦仓库）

    QVector<user*>userVector;       //用户容器

    QTableWidget *table,*table2;    //表格（分别用于展示宝可梦和用户）

    QLabel *label;                  //label控件

    int numPokemon,numOtherPokemon,numUser;             //自己宝可梦数量,查询用户的宝可梦数量，用户数量

    int numSuperPokemon;            //高级（满级）宝可梦数量

    //战斗数据
    pokemon* myPokemon,*enemyPokemon;                   //战斗时选择的我方宝可梦和敌方宝可梦

    int win,lose;                   //胜负场数

    double winningPercentage;       //胜率

    QTimer *timer,*timer2,*timer3;  //计时器
};
#endif // CLIENT_H
