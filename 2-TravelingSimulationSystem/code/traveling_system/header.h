/*
    该文件定义了所有与城市信息，路线信息相关的数据结构
*/

#ifndef HEADER_H
#define HEADER_H

#include"gui.h"


//城市风险系数常量
const double LOW_RISK(0.2);			//低风险
const double MID_RISK(0.5);			//中风险
const double HIGH_RISK(0.9);		//高风险


//交通工具风险系数常量
const int BUS_RISK(2);              //汽车风险
const int TRAIN_RISK(5);            //火车风险
const int AIR_RISK(9);              //飞机风险


//允许最大城市和路线数量
const int MAX_CITIES(15);           //最大城市数量
const int MAX_ROUTES(100);          //最大路线数量


//城市信息结构
struct cityinfo
{
    QString city_name;              //城市名
    double city_risk_index;			//风险指数
};


//时刻表信息
struct timetable
{
    QString route_seq;              //车次/航班号
    int origin;                     //起点
    int destination;                //终点
    int start_time;                 //出发时间
    int end_time;                   //到达时间
    int total_time;                 //历经时间
};


//地图类，其中存储图用的是邻接表方式
class Map
{
private:
    int num_cities;					//城市数量
    int num_routes;					//所有的汽车、火车车次数，飞机航班数总和，统称为路线数

    typedef struct route			//路线
    {
        QString route_seq;          //车次/航班号
        int origin;                 //起点
        int destination;            //终点
        int start_time;				//出发时间
        int end_time;				//到达时间
        int total_time;				//历经时间
        route* next;				//下一条路线
    }*Route;

    struct citylist					//城市列表
    {
        int name;                   //当前城市序号
        Route first_route;			//当前城市出发的第一条路线
    };

    citylist Citylist[MAX_CITIES];

public:
    void Initialize();                                      //初始化地图信息

    QList<QString> Basic_non_time_limited(userplan&);       //非限时策略算法（基础版本：只计算停留在城市的风险）
    QList<QString> Basic_time_limited(userplan&);           //限时策略算法（基础版本）
    QString Extended_non_time_limited(userplan&);           //非限时策略算法（扩展版本：计算了交通工具上的风险）
    QString Extended_time_limited(userplan&);               //限时策略算法（扩展版本）


    void DFS(QString* str, int src, int des, int& hop, int& cnt);

};


//为实现路线设计与输出模块用到的辅助函数

//将城市名映射到序号
int Get_seq(QString str);

//将序号转换为城市名
QString Get_name(int i);

//根据班次号首字母确定交通方式，并返回对应的风险值
double Get_transport_risk_index(char ch);

//以班次号为索引查询时刻表
timetable* Get_route_info(QString str, timetable* Timetable);

//提取出用Dijkstra算法得到的单条路径的车次列表(path是整条路线上route的集合）
void Get_path_list(int* path, QString* route_name, int des, QString& str);

//得到最后要输出的路线结果
QString Get_path_info(QString str, timetable* Timetable);

#endif // HEADER_H
