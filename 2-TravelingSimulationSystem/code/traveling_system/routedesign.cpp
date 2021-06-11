/*
    该模块包含了
    1.初始化城市与路线信息
    2.采用最短路径算法设计的非限时策略
    3.采用了DFS算法设计的限时策略
    等功能
*/

#include<QDebug>
#include<QFile>
#include<QTextStream>
#include<QByteArray>
#include<QStringList>

#include"header.h"


const double inf = 1e9;					//无穷大
const int MAX_TRANSITION_TIMES=4;       //最大中转次数，超过这个次数的路线显然不合理而不考虑

cityinfo city_info[MAX_CITIES];         //存储城市对应的风险信息
static bool visited[MAX_CITIES];        //DFS中用于记录城市是否访问过
timetable Timetable[MAX_ROUTES];        //时刻表

int cities,routes;                      //记录城市数和路线数，方便别的文件访问


/* 对地图信息进行初始化 */
void Map::Initialize()
{
    QFile file("./resource/routeinfo.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not open the file 'routeinfo.txt'";
        return;
    }
    QTextStream fin(&file);

    fin>>num_cities;
    fin>>num_routes;

    cities=num_cities;
    routes=num_routes;

    for (int i = 1; i <= cities; i++)
    {
        fin>>city_info[i].city_name>>city_info[i].city_risk_index;
        Citylist[i].name = i;
        Citylist[i].first_route = nullptr;
    }

    file.close();


    QFile file2("./resource/trafficinfo.txt");
    if(!file2.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not open the file 'trafficinfo.txt'";
        return;
    }
    QTextStream fin2(&file2);

    QString num,from,to;
    int start,end,time;
    int cnt=1;

    while(!fin2.atEnd())
    {
        fin2>>num>>from>>to>>start>>end>>time;
        if(from!="")
        {
            Route R=new route;
            R->route_seq=num;
            R->origin=Get_seq(from);
            R->destination=Get_seq(to);
            R->start_time=start;
            R->end_time=end;
            R->total_time=time;
            R->next = Citylist[R->origin].first_route;
            Citylist[R->origin].first_route = R;

            //将输入图里的信息同时保存到时刻表结构中
            Timetable[cnt].route_seq = num;
            Timetable[cnt].origin = R->origin;
            Timetable[cnt].destination = R->destination;
            Timetable[cnt].start_time = start;
            Timetable[cnt].end_time = end;
            Timetable[cnt].total_time = time;

            cnt++;
        }
    }

    file2.close();
}


/* 采用没有时间限制的最少风险策略用的Dijkstra算法 */
QString Map::Extended_non_time_limited(userplan& plan)
{
    int src = plan.origin;						//起点
    int des = plan.destination;					//终点

    double total_risk[MAX_CITIES];				//从起点到该城市的总风险
    int arrive_time[MAX_CITIES] = { 0 };		//到达该城市的时间
    int path[MAX_CITIES];						//记录上一个城市
    QString route_name[MAX_CITIES];				//记录上一个城市到该城市的车次

    for (int i = 1; i <= cities; i++)			//初始化
    {
        total_risk[i] = inf;
        path[i] = i;
        visited[i] = false;
    }
    total_risk[src] = 0;
    arrive_time[src] = 0;

    double min_risk = inf;						//标记算法里保存的最小风险值
    int min_risk_city = src;					//最小风险值对应的城市

    while (!visited[min_risk_city])
    {
        min_risk = inf;
        visited[min_risk_city] = true;

        Route R = Citylist[min_risk_city].first_route;

        while (R)
        {
            //交通工具上的风险系数
            QByteArray ba = (R->route_seq).toLatin1();
            char* ch=ba.data();
            double trans_risk_index = Get_transport_risk_index(ch[0]);

            //停留城市的风险系数
            double city_risk_index = city_info[R->origin].city_risk_index;

            //当前路线上的总风险
            int stay_time = R->start_time - arrive_time[R->origin];
            if (stay_time < 0)			//得到负数说明当天该车次已没有班次，需等到第二天
                stay_time += 24;
            else if (stay_time == 0)	//计算城市停留风险时我们默认最短停留时间为1h
                stay_time++;
            double tmp = R->total_time * city_risk_index
                * trans_risk_index;
            if (R->origin != src)
                tmp += stay_time * city_risk_index;


            //更新城市风险值，记录相关路径信息
            if (total_risk[R->destination] > inf - 1		//之前无路线到达
                || total_risk[R->origin] + tmp < total_risk[R->destination])
            {
                total_risk[R->destination] = total_risk[R->origin] + tmp;
                path[R->destination] = R->origin;
                arrive_time[R->destination] = R->end_time;
                route_name[R->destination] = R->route_seq;
            }

            //更新风险最小的城市
            if (!visited[R->destination] && min_risk > total_risk[R->destination])
            {
                min_risk = total_risk[R->destination];
                min_risk_city = R->destination;
            }
            R = R->next;
        }

        //更新风险最小的城市
        for (int i = 1; i <= num_cities; i++)
            if (!visited[i] && total_risk[i] < min_risk)
            {
                min_risk = total_risk[i];
                min_risk_city = i;
            }
    }

    QString route_list = "";
    Get_path_list(path, route_name, des, route_list);

    return route_list;
}


QString str[1000] = { "" };				//存放路线信息


/* DFS搜索所有在规定中转次数内可能到达目的地的所有路径 */
void Map::DFS(QString* str, int src, int des, int& hop, int& cnt)
{
    if (src == des)
    {
        cnt++;
        return;
    }

    if (hop == MAX_TRANSITION_TIMES)				//剪枝，减去中转次数超过限制的分枝
        return;

    Route R = Citylist[src].first_route;
    while (R)
    {
        if (!visited[R->destination])
        {
            QString tmp = str[cnt];

            str[cnt] += (R->route_seq + " ");       //在路径信息中添加班次号
            visited[R->destination] = true;			//标记为访问
            DFS(str, R->destination, des, ++hop, cnt);

            hop--;									//回溯
            str[cnt] = tmp;
            visited[R->destination] = false;
        }
        R = R->next;
    }
}


/* 限时最小风险策略下的算法 */
QString Map::Extended_time_limited(userplan& plan)
{
    for (int i = 0; i < 1000; i++)			//初始化
        str[i] = "";
    for (int i = 1; i <= cities; i++)		//初始化为未访问
        visited[i] = false;

    int src = plan.origin;					//起点
    int des = plan.destination;				//终点

    int hop = 0;							//计算中转次数
    int cnt = 0;							//路线数
    visited[src] = true;

    DFS(str, src, des, hop, cnt);
    qDebug()<<str[0];


    //现在所有的路径信息已经存放在str中，下面开始计算并选出最小风险的
    double min_risk = inf;                          //限时条件下最小风险值
    int min_risk_route = 0;							//限时条件下最小风险值对应的线路
    int min_risk_total_time = plan.required_time;	//限时条件下最小风险值对应的时间

    for (int i = 0; i < cnt; i++)
    {
        QStringList route_list=str[i].split(" ");
        int num=route_list.size();

        double city_risk;			//城市风险系数
        double trans_risk;			//交通工具风险系数
        int timer = 0;				//计时器
        double total_risk = 0.0;	//风险累计值
        int arr_time;				//到达时间
        timetable* tmp = Get_route_info(route_list[0],Timetable);

        QByteArray ba = (tmp->route_seq).toLatin1();
        char* ch=ba.data();
        trans_risk= Get_transport_risk_index(ch[0]);
        city_risk = city_info[tmp->origin].city_risk_index;

        timer += tmp->total_time;
        total_risk += (tmp->total_time * trans_risk * city_risk);
        arr_time = tmp->end_time;

        for (int j = 1; j < num-1 && timer<=plan.required_time; j++)
        {
            tmp = Get_route_info(route_list[j],Timetable);
            int stay_time = tmp->start_time - arr_time;
            if (stay_time < 0)		//跨天
                stay_time += 24;

            QByteArray ba = (tmp->route_seq).toLatin1();
            char* ch=ba.data();

            timer += (stay_time + tmp->total_time);
            trans_risk= Get_transport_risk_index(ch[0]);
            city_risk = city_info[tmp->origin].city_risk_index;
            total_risk += (stay_time * city_risk);
            total_risk += (tmp->total_time * trans_risk * city_risk);
            if (stay_time == 0)				//强制停留一小时
                total_risk += city_risk;
            arr_time = tmp->end_time;
        }

        if (timer > plan.required_time) continue;
        else if (total_risk < min_risk)
        {
            min_risk=total_risk;
            min_risk_route = i;
            min_risk_total_time = timer;
        }
    }


    if (min_risk > inf - 1)
    {
        qDebug() << "没有路线可以在规定时间内可达";
        return "";
    }
    else
        return str[min_risk_route];
}


QList<QString> Map::Basic_non_time_limited(userplan& plan)
{
    QList<QString>routelists;               //同为风险值最小的路线列表
    routelists.clear();
    int num=0;                              //同为风险值最小的路线数

    for (int i = 0; i < 1000; i++)			//初始化
        str[i] = "";
    for (int i = 1; i <= cities; i++)		//初始化为未访问
        visited[i] = false;

    int src = plan.origin;					//起点
    int des = plan.destination;				//终点

    int hop = 0;							//计算中转次数
    int cnt = 0;							//路线数
    visited[src] = true;

    DFS(str, src, des, hop, cnt);

    //现在所有的路径信息已经存放在str中，下面开始计算并选出最小风险的
    double min_risk = inf;                          //最小风险值
    int min_risk_route = 0;							//最小风险值对应的线路

    for (int i = 0; i < cnt; i++)
    {
        QStringList route_list=str[i].split(" ");
        int size=route_list.size()-1;

        double city_risk;			//城市风险系数
        double total_risk = 0.0;	//风险累计值
        int arr_time;				//到达时间
        timetable* tmp = Get_route_info(route_list[0],Timetable);
        city_risk = city_info[tmp->origin].city_risk_index;

        arr_time = tmp->end_time;
        for (int j = 1; j < size; j++)
        {
            tmp = Get_route_info(route_list[j],Timetable);
            int stay_time = tmp->start_time - arr_time;
            if (stay_time < 0)		//跨天
                stay_time += 24;


            city_risk = city_info[tmp->origin].city_risk_index;
            total_risk += (stay_time * city_risk);

            if (stay_time == 0)				//强制停留一小时
                total_risk += city_risk;
            arr_time = tmp->end_time;
        }

        if (total_risk < min_risk)
        {
            routelists.clear();
            num=0;

            min_risk=total_risk;
            min_risk_route = i;

            routelists.insert(1,str[min_risk_route]);
        }
        else if(total_risk==min_risk)
        {
            min_risk=total_risk;
            min_risk_route = i;

            routelists.insert(++num,str[min_risk_route]);
        }
    }


    if (min_risk > inf - 1)
    {
        qDebug() << "没有路线可以在规定时间内可达";
        routelists.clear();
    }

    return routelists;
}

QList<QString> Map::Basic_time_limited(userplan& plan)
{
    QList<QString>routelists;               //同为风险值最小的路线列表
    routelists.clear();
    int num=0;                              //同为风险值最小的路线数

    for (int i = 0; i < 1000; i++)			//初始化
        str[i] = "";
    for (int i = 1; i <= cities; i++)		//初始化为未访问
        visited[i] = false;

    int src = plan.origin;					//起点
    int des = plan.destination;				//终点

    int hop = 0;							//计算中转次数
    int cnt = 0;							//路线数
    visited[src] = true;

    DFS(str, src, des, hop, cnt);


    //现在所有的路径信息已经存放在str中，下面开始计算并选出最小风险的
    double min_risk = inf;                          //限时条件下最小风险值
    int min_risk_route = 0;							//限时条件下最小风险值对应的线路
    int min_risk_total_time = plan.required_time;	//限时条件下最小风险值对应的时间

    for (int i = 0; i < cnt; i++)
    {
        QStringList route_list=str[i].split(" ");
        int size=route_list.size()-1;

        double city_risk;			//城市风险系数
        int timer = 0;				//计时器
        double total_risk = 0.0;	//风险累计值
        int arr_time;				//到达时间
        timetable* tmp = Get_route_info(route_list[0],Timetable);

        city_risk = city_info[tmp->origin].city_risk_index;

        timer += tmp->total_time;
        arr_time = tmp->end_time;

        for (int j = 1; j < size && timer<=plan.required_time; j++)
        {
            tmp = Get_route_info(route_list[j],Timetable);
            int stay_time = tmp->start_time - arr_time;
            if (stay_time < 0)		//跨天
                stay_time += 24;

            timer += (stay_time + tmp->total_time);
            city_risk = city_info[tmp->origin].city_risk_index;
            total_risk += (stay_time * city_risk);
            if (stay_time == 0)				//强制停留一小时
                total_risk += city_risk;
            arr_time = tmp->end_time;
        }

        if (timer > plan.required_time) continue;
        else if (total_risk < min_risk)
        {
            routelists.clear();
            num=0;

            min_risk=total_risk;
            min_risk_route = i;
            min_risk_total_time = timer;

            routelists.insert(1,str[min_risk_route]);
        }
        else if(total_risk==min_risk)
        {
            min_risk=total_risk;
            min_risk_route = i;
            min_risk_total_time = timer;

            routelists.insert(++num,str[min_risk_route]);
        }
    }

    if (min_risk > inf - 1)
    {
        qDebug() << "没有路线可以在规定时间内可达";
        routelists.clear();
    }

    return routelists;
}



