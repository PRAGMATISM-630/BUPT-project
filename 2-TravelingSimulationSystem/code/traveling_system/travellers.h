#ifndef TRAVELLERS_H
#define TRAVELLERS_H

#include"gui.h"



struct travellers
{
    userplan plan;

    QString routelist;              //记录一个解决方案的所有班次
    bool go_or_arrive[5000]={0};    //用于记录是否有出发或到达事件发生
    QMap<QString,QString>ma;        //时间与事件的映射
    QMap<int,int>time_x;            //时间与横坐标的映射
    QMap<int,int>time_y;            //时间与纵坐标的映射
    QList<QString>list;

};

#endif // TRAVELLERS_H
