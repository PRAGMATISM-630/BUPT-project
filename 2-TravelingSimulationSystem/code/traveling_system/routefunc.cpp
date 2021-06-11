/*
    该文件包含了所有为实现“路线设计与输出模块”用到的辅助函数
*/

#include<QStringList>
#include<QString>
#include<QDebug>

#include"header.h"

extern int routes;


/* 将城市名映射到序号 */
int Get_seq(QString str)
{
    str=str.toLower();                   //将字符串中所有字符转成小写，以应对用户输入大写字母的情况
    if (str == "beijing")	return 1;
    if (str == "shanghai")	return 2;
    if (str == "wuhan")		return 3;
    if (str == "haerbin")	return 4;
    if (str == "chengdu")	return 5;
    if (str == "guangzhou") return 6;
    if (str == "xian")		return 7;
    if (str == "wulumuqi")	return 8;
    if (str == "lasa")		return 9;
    if (str == "haikou")	return 10;
}


/* 将城市序号转换为城市名 */
QString Get_name(int i)
{
    switch(i)
    {
    case 1:
        return "北京";
    case 2:
        return "上海";
    case 3:
        return "武汉";
    case 4:
        return "哈尔滨";
    case 5:
        return "成都";
    case 6:
        return "广州";
    case 7:
        return "西安";
    case 8:
        return "乌鲁木齐";
    case 9:
        return "拉萨";
    case 10:
        return "海口";
    default:
        qDebug()<<"City name error!";
        return "";
    }
}


/* 根据班次号首字母确定交通方式，并返回对应的风险值 */
double Get_transport_risk_index(char ch)
{
    double index = 0;
    switch (ch)
    {
    case 'A':index = AIR_RISK; break;
    case 'T':index = TRAIN_RISK; break;
    case 'B':index = BUS_RISK; break;
    default:break;
    }
    return index;
}


/* 以班次号为索引顺序查找时刻表 */
timetable* Get_route_info(QString str, timetable* Timetable)
{
    for (int i = 1; i <= routes; i++)
    {
        if (str == Timetable[i].route_seq)
            return &Timetable[i];
    }

    qDebug() << "Search failure!";						//查找失败
    return NULL;
}


/* 提取出用Dijkstra算法得到的一个解决方案的车次列表 */
void Get_path_list(int* path, QString* route_name, int des, QString& str)
{
    if (path[des] != des)
    {
        Get_path_list(path, route_name, path[des], str);
        str += (route_name[des] + " ");
    }
}


/* 得到最后要输出的路线结果 */
QString Get_path_info(QString str,timetable* Timetable)
{
    QString output="";

    QStringList list=str.split(" ");
    int num=list.size();
    for(int i=0;i<num-1;i++)
    {
        qDebug()<<list[i];
        timetable* T = Get_route_info(list[i], Timetable);
        output += (QString::number(T->start_time)+ "时         " + T->route_seq
                   + "          "+QString::number(T->end_time)+"时\n"+Get_name(T->origin)
                   +"------------->  "+Get_name(T->destination)+"\n");
    }
    return output;
}


