#include "client.h"
#include "Server.h"
#include "ui_client.h"

/////////////////////////////
//
//  filename: signInSignUp.cpp
//  function: 登录注册相关函数
//
/////////////////////////////

extern QString currentUserName;             //当前帐号用户名
extern int rPort;

void Client::on_ui1_signIn_clicked()        //请求登录，向服务器发送账号和密码
{
    user *oneUser=new user;

    //封装数据报
    oneUser->userName=ui->ui1_userName->text();     //获取用户输入的账号
    oneUser->password=ui->ui1_password->text();     //获取用户输入的密码
    oneUser->clientState=SIGN_IN;                   //当前操作为登录
    currentUserName=oneUser->userName;              //记录当前用户名

    QByteArray byteArray;
    byteArray.append((char*)oneUser,sizeof(user));
    udpSocket->writeDatagram(byteArray,QHostAddress::LocalHost,rPort);       //将数据报发送给服务器
}

void Client::on_ui1_signUp_clicked()        //请求注册，向服务器发送账号和密码
{
    user *oneUser=new user;

    //封装数据报
    oneUser->userName=ui->ui1_userName->text();     //获取用户输入的账号
    oneUser->password=ui->ui1_password->text();     //获取用户输入的密码
    oneUser->clientState=SIGN_UP;                   //当前操作为注册
    currentUserName=oneUser->userName;              //记录当前用户名

    QByteArray byteArray;
    byteArray.append((char*)oneUser,sizeof(user));
    udpSocket->writeDatagram(byteArray,QHostAddress::LocalHost,rPort);       //将数据报发送给服务器
}
