#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QString>
#include <QTimer>


namespace Ui {
class GUI;
}

class GUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit GUI(QWidget *parent = 0);
    ~GUI();
    void Store_time_info(const QString& s);
    void Store_coordinate_info(const QString& s);

private slots:
    void on_get_path_clicked();                     //查询路线
    void on_get_user_state_clicked();               //查询某时刻旅客状态
    void on_start_simulation_clicked();             //开始/暂停模拟
    void on_stop_simulation_clicked();              //终止模拟

    void on_get_strategy_clicked();                 //获取策略信息
    void on_get_strategy_2_clicked();               //获取策略信息

    void on_get_origin_activated(int index);        //获取起点信息
    void on_get_destination_activated(int index);   //获取终点信息
    void on_get_day_activated(int index);           //获取查询日期
    void on_get_hour_activated(int index);          //获取查询时间
    void on_get_choice_activated(int index);        //获取用户选择的路线


    void on_get_max_time_editingFinished();         //限时策略下限制时间

    void update_info();                             //更新界面

    //void on_get_edition_activated(int index);       //获取选择的版本

    void on_add_traveller_clicked();

    void on_choose_traveller_activated(int index);

private:
    Ui::GUI *ui;
    QTimer* m_Timer;
};


enum strategy { NON_TIME_LIMITED, TIME_LIMITED };


void Get_coordinate();

struct userplan
{
    QString name;                   //用户名
    int origin;                     //出发地
    int destination;                //目的地
    strategy traveling_strategy;	//旅行策略
    int required_time;				//采用限时策略时要求的限制时间
};

#endif // GUI_H
