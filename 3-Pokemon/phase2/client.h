#ifndef CLIENT_H
#define CLIENT_H

#include "pokemonsubtype.h"

#include <QMainWindow>
#include <QUdpSocket>
#include <QVector>
#include <QTableWidget>
#include <QSignalMapper>
#include <QPixmap>
#include <QRandomGenerator>


enum state{SIGN_IN,SIGN_UP,GET_POKEMON_INFO,GET_ALL_PLAYERS,GET_OTHER_POKEMON_INFO,UPDATE_DATABASE};
//操作类型：登录/注册/获取宝可梦信息/查看所有玩家信息/获取其他玩家的宝可梦信息/更新数据库

struct user
{
    state clientState;              //操作类型
    QString userName;               //用户名
    QString password;               //密码
    QVector<pokemon*>pokemonInfo;   //宝可梦仓库，用于更新数据库
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

    void changeUi(int n);                   //切换界面
    void updateDatabase();                  //更新数据库
    QString getChineseName(QString);        //将名字翻译为中文
    pokemon* getPokemon();                  //获取宝可梦


private slots:
    void getRow(const QString &);

    void readPendingDatagrams();

    void on_ui1_signIn_clicked();

    void on_ui1_signUp_clicked();

    void on_ui2_returnSignIn_clicked();

    void on_ui2_saveAndQuit_clicked();

    void on_ui2_myPokemon_clicked();

    void on_ui4_returnMainUi_clicked();

    void on_ui2_allPlayers_clicked();

    void on_ui3_returnMainUi_clicked();

private:
    Ui::Client *ui;

    QUdpSocket *udpSocket;

    QVector<pokemon*>pokemonVector,otherPokemonVector;

    QVector<user*>userVector;

    QTableWidget *table,*table2;

    int numPokemon,numOtherPokemon,numUser;     //自己宝可梦数量,查询用户的宝可梦数量，用户数量
};
#endif // CLIENT_H
