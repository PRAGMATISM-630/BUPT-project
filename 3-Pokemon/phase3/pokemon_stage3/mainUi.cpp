#include "client.h"
#include "Server.h"
#include "ui_client.h"

/////////////////////////////
//
//  filename: mainUi.cpp
//  function: 主界面处理函数，通过点击按钮触发切换其他界面
//
/////////////////////////////

extern int lastUi;      //上一个界面
extern int rPort;


void Client::on_ui2_prize_clicked()             //成就界面
{
    lastUi=2;           //上个界面为2（主界面）

    changeUi(8);        //切换至成就界面

    updateDatabase();   //更新数据库

    //设置胜负场数、胜率显示
    if(win+lose==0)
        winningPercentage=0;
    else
        winningPercentage=double(win)/double(win+lose);
    ui->ui8_win->setText(tr("胜场:")+QString::number(win));
    ui->ui8_lose->setText(tr("负场:")+QString::number(lose));
    ui->ui8_per->setText(tr("胜率:")+QString::number(int(winningPercentage*100))+tr("%"));

    //设置宝可梦徽章贴图
    if(numPokemon<5)
    {
        ui->ui8_bronze1->setDisabled(true);
        ui->ui8_silver1->setDisabled(true);
        ui->ui8_golden1->setDisabled(true);
    }
    else if(numPokemon<10)
    {
        ui->ui8_bronze1->setDisabled(false);
        ui->ui8_silver1->setDisabled(true);
        ui->ui8_golden1->setDisabled(true);
    }
    else if(numPokemon<15)
    {
        ui->ui8_bronze1->setDisabled(false);
        ui->ui8_silver1->setDisabled(false);
        ui->ui8_golden1->setDisabled(true);
    }
    else
    {
        ui->ui8_bronze1->setDisabled(false);
        ui->ui8_silver1->setDisabled(false);
        ui->ui8_golden1->setDisabled(false);
    }

    //设置高级宝可梦徽章贴图
    if(numSuperPokemon<5)
    {
        ui->ui8_bronze2->setDisabled(true);
        ui->ui8_silver2->setDisabled(true);
        ui->ui8_golden2->setDisabled(true);
    }
    else if(numSuperPokemon<10)
    {
        ui->ui8_bronze2->setDisabled(false);
        ui->ui8_silver2->setDisabled(true);
        ui->ui8_golden2->setDisabled(true);
    }
    else if(numSuperPokemon<15)
    {
        ui->ui8_bronze2->setDisabled(false);
        ui->ui8_silver2->setDisabled(false);
        ui->ui8_golden2->setDisabled(true);
    }
    else
    {
        ui->ui8_bronze2->setDisabled(false);
        ui->ui8_silver2->setDisabled(false);
        ui->ui8_golden2->setDisabled(false);
    }
}

void Client::on_ui2_returnSignIn_clicked()      //返回登录界面
{
    updateDatabase();       //更新数据库
    lastUi=2;
    changeUi(1);            //返回登录界面
}

void Client::on_ui2_saveAndQuit_clicked()       //退出游戏
{
    updateDatabase();   //更新数据库
    close();            //关闭界面
}

void Client::on_ui2_allPlayers_clicked()        //查看其它玩家
{
    user *oneUser=new user;

    oneUser->clientState=GET_ALL_PLAYERS;           //操作为查看所有玩家信息

    QByteArray byteArray;
    byteArray.append((char*)oneUser,sizeof(user));
    udpSocket->writeDatagram(byteArray,QHostAddress::LocalHost,rPort);       //发送给服务器
}

void Client::on_ui2_battle_clicked()            //进入战斗选择界面
{
    lastUi=2;
    changeUi(5);        //切换至战斗选择界面
}

void Client::on_ui2_myPokemon_clicked()         //查看宝可梦仓库
{
    lastUi=2;
    changeUi(4);        //宝可梦展示界面

    table=new QTableWidget(this);
    table->setGeometry(0,50,800,540);         //设置表格大小
    table->setColumnCount(4);                               //设置列数为4
    table->setRowCount(numPokemon);                         //设置行数为宝可梦数

    table->setColumnWidth(0,80);                    //设置每列宽度或每行高度
    table->setColumnWidth(1,160);
    table->setColumnWidth(2,160);
    table->setColumnWidth(3,360);

    for(int i=0;i<numPokemon;i++)
        table->setRowHeight(i,150);

    QStringList headerLabels;                       //设置列标签
    headerLabels << "序号" << "宝可梦" << "基本属性" <<"详细属性";
    table->setHorizontalHeaderLabels(headerLabels);

    QStringList rowLabels;                          //设置行标签
    for(int i=1;i<=numPokemon;i++)
        rowLabels << "";
    table->setVerticalHeaderLabels(rowLabels);

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);  //内容不可修改

    for(int row=0;row<numPokemon;row++)
    {
        QTableWidgetItem *item0,*item2,*item3;
        item0 = new QTableWidgetItem;
        item2 = new QTableWidgetItem;
        item3 = new QTableWidgetItem;
        item0->setTextAlignment(Qt::AlignCenter);       //居中显示
        item2->setTextAlignment(Qt::AlignCenter);
        item3->setTextAlignment(Qt::AlignCenter);

        item0->setText(QString::number(row+1));
        table->setItem(row,0,item0);                    //设置第0列显示


        QString name=pokemonVector[row]->getName();     //宝可梦名字
        QString path="./resourse/"+name+".png";         //图片所在路径
        QPixmap *pixmap=new QPixmap(path);
        QLabel *label = new QLabel;
        label->setScaledContents(true);
        label->setPixmap(*pixmap);
        table->setCellWidget(row,1,label);              //设置第1列图片显示


        QString type=pokemonVector[row]->getType();     //宝可梦类型
        int level=pokemonVector[row]->getLevel();
        int exp=pokemonVector[row]->getExp();
        QString str="类型: " + getChineseName(type) + "\n\n" + "名字: " + getChineseName(name) + "\n\n"
                +"等级: " + QString::number(level) + "\n\n" + "经验: " + QString::number(exp);
        item2->setText(str);
        table->setItem(row,2,item2);                    //设置第2列显示


        int atk=pokemonVector[row]->getAtk();
        int def=pokemonVector[row]->getDef();
        //int hp=pokemonVector[row]->getHp();
        int maxhp=pokemonVector[row]->getMaxHp();
        int spd=pokemonVector[row]->getSpd();
        str="攻击: " + QString::number(atk) + "\n\n"
           + "防御: " + QString::number(def) + "\n\n"
           + "速度: " + QString::number(spd) + "\n\n"
           + "生命值: " + QString::number(maxhp) + "/" + QString::number(maxhp);
        item3->setText(str);
        table->setItem(row,3,item3);                    //设置第3列显示
    }

    table->show();
}
