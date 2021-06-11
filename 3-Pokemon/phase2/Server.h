#ifndef SERVER_H
#define SERVER_H

#include "pokemonsubtype.h"
#include "client.h"

#include <QWidget>
#include <QRandomGenerator>
#include <QVector>
#include <QMessageBox>
#include <QUdpSocket>
#include <QSqlDatabase>
#include <QSqlQuery>


//struct pokemonInfo
//{
//    QString type;       //种类
//    QString name;       //名字
//    uint level;         //等级
//    uint exp;           //经验值
//    uint atk;           //攻击值
//    uint def;           //防御值
//    uint maxHp;         //最大生命值
//    int hp;             //当前生命值
//    uint spd;           //攻速
//    //QString skill;      //技能
//};

struct message
{
    state serverState;                  //操作类型
    QVector<pokemon*>pokemonInfo;       //宝可梦仓库
    QVector<user*>userInfo;             //用户列表
};

namespace Ui {
class server;
}

class server : public QWidget
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = nullptr);
    ~server();

    pokemon* getPokemon();

private slots:
    void readPendingDatagrams();

private:

    QUdpSocket *udpSocket;

    QSqlDatabase db;

};

#endif // SERVER_H
