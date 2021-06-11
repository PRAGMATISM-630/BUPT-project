/*
    该模块为图形界面展示模块
*/

#include<QFile>
#include<QTextStream>
#include<QDebug>
#include<QStringList>
#include<QMap>
#include<QMessageBox>
#include<QDateTime>
#include<QPixmap>


#include "gui.h"
#include "ui_gui.h"
#include "header.h"
#include "log.h"
#include "travellers.h"

bool is_basic=false;                    //是否使用拓展版本，默认为使用
bool ack[20]={0};                       //判断相应序号的旅客是否确定了解决方案，20为默认的最大旅客数
QString solution[20]={""};                   //保存乘客选择的解决方案，20

extern int cities,routes;
extern timetable Timetable[MAX_ROUTES];

int coord_x[MAX_CITIES];
int coord_y[MAX_CITIES];

const int icon_width(35);
const int icon_height(35);

/*记录时间*/
int day=0;
int hour=0;
int total_hours=0;


int num_travellers=0;                   //旅客总数
int current_traveller_seq=-1;            //当前旅客编号
QList<travellers>traveller_list;

GUI::GUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GUI)
{
    ui->setupUi(this);

    //提示用户选择基础版本或扩展版本
    QMessageBox message(QMessageBox::Warning,"提示","是否使用扩展版本（考虑乘坐交通工具的风险）",QMessageBox::Yes|QMessageBox::No,nullptr);
    if(message.exec()==QMessageBox::Yes)
        is_basic=false;
    else is_basic=true;

    //图形界面设置
    setFixedSize(1350,775);
    setWindowTitle("旅游查询与模拟系统");

    /*地图显示*/
    QPixmap *pixmap = new QPixmap("./resource/map.png");
    pixmap->scaled(ui->mymap->size(), Qt::KeepAspectRatio);
    ui->mymap->setScaledContents(true);
    ui->mymap->setPixmap(*pixmap);

    /*旅客图标显示*/
    QPixmap *pixmap2=new QPixmap("./resource/loc.png");
    pixmap2->scaled(ui->myicon->size(), Qt::KeepAspectRatio);
    ui->myicon->setScaledContents(true);
    ui->myicon->setPixmap(*pixmap2);
    ui->myicon->setHidden(true);


    /*时间显示*/
    ui->lcdNumber->setDigitCount(2);
    ui->lcdNumber_2->setDigitCount(2);

    /*计时器*/
    m_Timer =new QTimer;
    connect(m_Timer,SIGNAL(timeout()),this,SLOT(update_info()));
    m_Timer->setTimerType(Qt::PreciseTimer);

    ui->label_8->setVisible(false);
    ui->get_choice->setVisible(false);
    ui->unchecked->setVisible(false);
    ui->myicon->setGeometry(1400,800,1,1);
}

GUI::~GUI()
{
    delete ui;
}


void Get_coordinate()
{
    QFile file("./resource/coordinateinfo.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not open the file 'coordinateinfo.txt'.";
        return;
    }
    QTextStream fin(&file);

    for(int i=1;i<=cities;i++)
        fin>>coord_x[i]>>coord_y[i];

    file.close();
}


void GUI::Store_time_info(const QString &s)         //存储用于输出的时间-事件对
{
    traveller_list[current_traveller_seq].ma.clear();

    for(int i=0;i<5000;i++)
        traveller_list[current_traveller_seq].go_or_arrive[i]=false;

    QStringList list=s.split(" ");
    int list_size=list.size()-1;

    int last_route_time=-1;
    total_hours=24;
    day=1;
    hour=0;
    timetable* T;

    for(int i=0;i<list_size;i++)
    {
        T=Get_route_info(list[i],Timetable);
        total_hours+=((T->start_time-hour)>=0?(T->start_time-hour):(T->start_time-hour+24));     //添加在城市停留时间
        day=total_hours/24;
        hour=total_hours%24;

        for(int j=last_route_time+1;j<total_hours;j++)                                            //保存停留在城市的信息
            traveller_list[current_traveller_seq].ma.insert(QString::number(j),"位于城市"+Get_name(T->origin)+"\n");

        QString str=("从"+Get_name(T->origin)+"出发坐"+T->route_seq+"去往"+Get_name(T->destination)+"\n");
        traveller_list[current_traveller_seq].ma.insert(QString::number(total_hours),str);                                            //将时间与出发事件建立映射关系
        traveller_list[current_traveller_seq].go_or_arrive[total_hours]=true;

        int arr=total_hours+T->total_time;                                                       //保存位于交通工具上的信息
        str="位于"+Get_name(T->origin)+"去往"+Get_name(T->destination)+"的"
                +T->route_seq+"次"+(T->route_seq[0]=="A"?"航班上":"列车上")+"\n";
        for(total_hours++;total_hours<arr;total_hours++)
            traveller_list[current_traveller_seq].ma.insert(QString::number(total_hours),str);

        day=total_hours/24;
        hour=total_hours%24;

        str=("到达"+Get_name(T->destination)+"\n");
        if(i+1==list_size)
            str+=("到达目的地!\n");
        traveller_list[current_traveller_seq].ma.insert(QString::number(total_hours),str);                                            //将时间与到达事件建立映射关系
        traveller_list[current_traveller_seq].go_or_arrive[total_hours]=true;

        if(i+1!=list_size)
            last_route_time=total_hours;
    }
}


void GUI::Store_coordinate_info(const QString& s)   //存储各时刻旅客所处的坐标
{
    timetable* T;
    int seq_ori;
    int seq_des;
    int last_time=0;
    int next_time=0;
    
    traveller_list[current_traveller_seq].time_x.clear();
    traveller_list[current_traveller_seq].time_y.clear();
    QStringList list=s.split(" ");
    int list_size=list.size()-1;
    total_hours=day=hour=0;
    
    for(int i=0;i<list_size;i++)
    {
        T=Get_route_info(list[i],Timetable);
        seq_ori=T->origin;
        seq_des=T->destination;
        
        next_time=T->start_time;
        if(i==0)
            next_time+=24;
        int dur_time=next_time-last_time;
        if(dur_time<0)
            dur_time+=24;
        
        for(int j=0;j<=dur_time;j++)
        {
            traveller_list[current_traveller_seq].time_x.insert(total_hours,coord_x[seq_ori]);
            traveller_list[current_traveller_seq].time_y.insert(total_hours,coord_y[seq_ori]);
            total_hours++;
        }
        
        int tmp=T->total_time;
        double x_alter_per_hour=(static_cast<double>(coord_x[seq_des]-coord_x[seq_ori]))/tmp;     //一小时横坐标改变量
        double y_alter_per_hour=(static_cast<double>(coord_y[seq_des]-coord_y[seq_ori]))/tmp;     //一小时纵坐标改变量
        
        for(int j=1;j<=tmp;j++)
        {
            traveller_list[current_traveller_seq].time_x.insert(total_hours,coord_x[seq_ori]+j*x_alter_per_hour);
            traveller_list[current_traveller_seq].time_y.insert(total_hours,coord_y[seq_ori]+j*y_alter_per_hour);
            total_hours++;
        }
        total_hours--;
        
        last_time=T->end_time;
       
    }

    while(total_hours<5000)     //保持旅客停在终点
    {
        total_hours++;
        traveller_list[current_traveller_seq].time_x.insert(total_hours,coord_x[seq_des]);
        traveller_list[current_traveller_seq].time_y.insert(total_hours,coord_y[seq_des]);
    }

}


void GUI::on_get_origin_activated(int index)   //获取起点信息
{
    if(m_Timer->isActive())
        QMessageBox::about(NULL, "警告", "请先结束模拟");
    if(current_traveller_seq>=0)
        traveller_list[current_traveller_seq].plan.origin=index;
}


void GUI::on_get_destination_activated(int index)   //获取终点信息
{
    if(m_Timer->isActive())
        QMessageBox::about(NULL, "警告", "请先结束模拟");
    if(current_traveller_seq>=0)
        traveller_list[current_traveller_seq].plan.destination=index;
}


void GUI::on_get_strategy_clicked()            //获取策略信息
{
    if(m_Timer->isActive())
        QMessageBox::about(NULL, "警告", "请先结束模拟");
    if(current_traveller_seq>=0)
        traveller_list[current_traveller_seq].plan.traveling_strategy=NON_TIME_LIMITED;
}


void GUI::on_get_strategy_2_clicked()          //获取策略信息
{
    if(m_Timer->isActive())
        QMessageBox::about(NULL, "警告", "请先结束模拟");
    if(current_traveller_seq>=0)
        traveller_list[current_traveller_seq].plan.traveling_strategy=TIME_LIMITED;
}


void GUI::on_get_max_time_editingFinished()        //限时策略下限制时间
{
    if(m_Timer->isActive())
        QMessageBox::about(NULL, "警告", "请先结束模拟");
    if(current_traveller_seq>=0)
        traveller_list[current_traveller_seq].plan.required_time=ui->get_max_time->value();
}


void GUI::on_get_path_clicked()             //查询路线
{
    ui->textEdit->clear();
    if(current_traveller_seq==-1)
    {
        QMessageBox::about(NULL, "警告", "请至少添加并选择一名乘客再查询");
        return;
    }
    if(m_Timer->isActive())
    {
        QMessageBox::about(NULL, "警告", "请先结束模拟");
        return;
    }
    if(traveller_list[current_traveller_seq].plan.origin==0)
    {
        QMessageBox::about(NULL, "警告", "请选择出发城市");
        return;
    }
    if(traveller_list[current_traveller_seq].plan.destination==0)
    {
        QMessageBox::about(NULL, "警告", "请选择目的城市");
        return;
    }
    if(traveller_list[current_traveller_seq].plan.origin==traveller_list[current_traveller_seq].plan.destination)
    {
        QMessageBox::about(NULL, "警告", "出发城市不能与目的城市相同，请重新选择");
        return;
    }

    Create_log("开始查询");

    Map M;
    M.Initialize();

    QString output;
    if(!is_basic)       //使用拓展版本
    {
        ui->label_8->setVisible(false);
        ui->get_choice->setVisible(false);
        if (traveller_list[current_traveller_seq].plan.traveling_strategy == NON_TIME_LIMITED)
        {
            ui->solution->setText("解决方案（非限时最小风险）");
            qDebug() << "采用非限时策略";
            traveller_list[current_traveller_seq].routelist=M.Extended_non_time_limited(traveller_list[current_traveller_seq].plan);
        }
        else
        {
            ui->solution->setText("解决方案（限时最小风险）");
            qDebug() << "采用限时策略";
            traveller_list[current_traveller_seq].routelist=M.Extended_time_limited(traveller_list[current_traveller_seq].plan);
        }
        if (traveller_list[current_traveller_seq].routelist != "")
            output = Get_path_info(traveller_list[current_traveller_seq].routelist, Timetable);
        ui->textEdit->setText(output);
        if(ui->textEdit->toPlainText()=="")
            ui->textEdit->insertPlainText("没有路线可以在要求的时间内到达，请重新输入旅行时间!");

        Create_log("查询结果: \n"+output);
        Get_coordinate();

        if(ui->textEdit->toPlainText()!="没有路线可以在要求的时间内到达，请重新输入旅行时间!")
        {
            QMessageBox message(QMessageBox::Warning,"提示","是否确认选择该解决方案",QMessageBox::Yes|QMessageBox::No,nullptr);
            if(message.exec()==QMessageBox::No)
                return;
            else ack[current_traveller_seq]=true;

            solution[current_traveller_seq]=ui->textEdit->toPlainText();
            Store_time_info(traveller_list[current_traveller_seq].routelist);             //存储不同时刻发生的事件
            total_hours=hour=day=0;
            Store_coordinate_info(traveller_list[current_traveller_seq].routelist);       //存储不同时刻旅客的坐标
            total_hours=hour=day=0;
        }

    }
    else            //使用基础版本
    {
        ui->get_choice->clear();
        ui->label_8->setVisible(true);
        ui->get_choice->setVisible(true);
        ui->get_choice->addItem("请选择");

        int cnt=0;

        if(traveller_list[current_traveller_seq].plan.traveling_strategy == NON_TIME_LIMITED)
        {
            ui->solution->setText("解决方案（非限时最小风险）");
            traveller_list[current_traveller_seq].list=M.Basic_non_time_limited(traveller_list[current_traveller_seq].plan);
        }
        else
        {

            ui->solution->setText("解决方案（限时最小风险）");
            traveller_list[current_traveller_seq].list=M.Basic_time_limited(traveller_list[current_traveller_seq].plan);
        }
        for(auto r=traveller_list[current_traveller_seq].list.begin();r!=traveller_list[current_traveller_seq].list.end();r++)
        {
            output=Get_path_info(*r, Timetable);
            ui->textEdit->insertPlainText(QString::number(++cnt)+":\n"+output+"\n");
            ui->get_choice->addItem(QString::number(cnt));
        }
        if(ui->textEdit->toPlainText()=="")
            ui->textEdit->insertPlainText("没有路线可以在要求的时间内到达，请重新输入旅行时间!");
    }
}


void GUI::on_start_simulation_clicked()        //开始/暂停模拟
{   
    if(is_basic&&ui->get_choice->currentIndex()==0)
    {
        QMessageBox::about(NULL, "警告", "请选择解决方案");
        return;
    }

    if(current_traveller_seq<0||!ack[current_traveller_seq])
    {
        QMessageBox::about(NULL, "警告", "请先查询路线，再进行模拟");
        return;
    }

    if(solution[current_traveller_seq]!="")
        ui->textEdit->setText(solution[current_traveller_seq]);

    ui->myicon->setHidden(false);
    if(m_Timer->isActive())
    {
        m_Timer->stop();
        ui->start_simulation->setText("开始模拟");
    }
    else
    {
        Create_log("开始模拟");
        m_Timer->start(5000);
        ui->start_simulation->setText("暂停模拟");
    }
}


void GUI::on_stop_simulation_clicked()         //终止模拟
{
    m_Timer->stop();
    total_hours=day=hour=0;
    ui->lcdNumber->display(QString::number(day));
    ui->lcdNumber_2->display(QString::number(hour));
    ui->textEdit_2->clear();
    ui->start_simulation->setText("开始模拟");
}


void GUI::update_info()                 //更新界面显示
{
    /*显示时间*/
    total_hours++;
    day=total_hours/24;
    hour=total_hours%24;
    ui->lcdNumber->display(QString::number(day));
    ui->lcdNumber_2->display(QString::number(hour));


    /*显示模拟的旅行过程(文字）*/
    QString tmp=traveller_list[current_traveller_seq].ma.value(QString::number(total_hours));
    QString output=(QString::number(day)+"天"+QString::number(hour)+"时: ");
    if(traveller_list[current_traveller_seq].go_or_arrive[total_hours])
    {
        ui->textEdit_2->insertPlainText(output+tmp);
        Create_log(tmp);
    }

    /*显示模拟的旅行过程（地图）*/
    int x=traveller_list[current_traveller_seq].time_x.value(total_hours);
    int y=traveller_list[current_traveller_seq].time_y.value(total_hours);
    ui->myicon->setGeometry(x,y,icon_width,icon_height);

}


int query_day;             //用于记录查询旅客状态的日期和时间
int query_hour;


void GUI::on_get_day_activated(int index)      //获取查询日期
{
    query_day=index;
}


void GUI::on_get_hour_activated(int index)    //获取查询时间
{
    query_hour=index;
}


void GUI::on_get_user_state_clicked()             //开始查询旅客状态
{
    if(current_traveller_seq<0||!ack[current_traveller_seq])
    {
        QMessageBox::about(NULL, "警告", "请先查询路线并确定解决方案后，再进行旅客状态查询");
        return;
    }
    QString str=traveller_list[current_traveller_seq].ma.value(QString::number(query_day*24+query_hour));
    ui->textEdit_3->setText(str);
    Create_log("查询旅客状态信息："+QString::number(query_day)+"天"+QString::number(query_hour)+"时: \n");
    Create_log("查询结果: "+str);
}


void GUI::on_get_choice_activated(int index)    //获取用户选择的路线
{
    int choice=index-1;

    if(m_Timer->isActive())
    {
        QMessageBox::about(NULL, "警告", "请先结束模拟");
        return;
    }
    if(index==0)
    {
        QMessageBox::about(NULL,"提示","请选择一个解决方案");
        return;
    }


    Get_coordinate();

    if(ui->textEdit->toPlainText()!="没有路线可以在要求的时间内到达，请重新输入旅行时间!")
    {
        QMessageBox message(QMessageBox::Warning,"提示","是否确认选择该解决方案",QMessageBox::Yes|QMessageBox::No,nullptr);
        if(message.exec()==QMessageBox::No)
            return;
        else ack[current_traveller_seq]=true;

        solution[current_traveller_seq]=ui->textEdit->toPlainText();
        Store_time_info(traveller_list[current_traveller_seq].list[choice]);             //存储不同时刻发生的事件
        total_hours=hour=day=0;
        Store_coordinate_info(traveller_list[current_traveller_seq].list[choice]);       //存储不同时刻旅客的坐标
        total_hours=hour=day=0;
    }

}


void GUI::on_add_traveller_clicked()                //增加旅客
{
    ui->choose_traveller->addItem(QString::number(++num_travellers));
    travellers tmp;
    traveller_list.append(tmp);
}

void GUI::on_choose_traveller_activated(int index)
{
    if(index==0)
    {
        QMessageBox::about(NULL,"提示","请选择一名旅客");
        return;
    }
    current_traveller_seq=index-1;
    traveller_list[current_traveller_seq].plan.origin=0;
    traveller_list[current_traveller_seq].plan.destination=0;
    traveller_list[current_traveller_seq].plan.required_time=0;
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();

    ui->get_origin->setCurrentIndex(0);
    ui->get_destination->setCurrentIndex(0);
    ui->get_max_time->setValue(0);
    ui->get_strategy->setChecked(false);
    ui->get_strategy_2->setChecked(false);
    ui->unchecked->setChecked(true);
}

