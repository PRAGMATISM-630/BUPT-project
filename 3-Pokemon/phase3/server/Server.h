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


struct message      //数据报结构体，用于与客户端的通信
{
    state serverState;                          //操作类型
    QVector<pokemon*>pokemonInfo;               //宝可梦仓库
    QVector<user*>userInfo;                     //用户列表
    int win,lose,numPokemon,numSuperPokemon;    //胜负场，宝可梦数，高级宝可梦数
    double winningPercentage;                   //胜率
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

    pokemon* getPokemon()const;              //初次登录时由服务器端创建宝可梦分发给用户

private slots:
    void readPendingDatagrams()const;        //从客户端读取数据报

private:

    QUdpSocket *udpSocket;  //UDP套接字

    QSqlDatabase db;        //数据库

};

#endif // SERVER_H
