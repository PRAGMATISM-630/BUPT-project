#include "client.h"
#include "Server.h"

#include <QApplication>

/////////////////////////////
//
//  filename: main.cpp
//  function: 主函数
//
/////////////////////////////

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFont f("微软雅黑",11);
    a.setFont(f);   //设置全局字体

    Client w;       //新建客户端
    w.show();       //显示客户端

    server s;       //新建服务器（不显示）

    return a.exec();
}
