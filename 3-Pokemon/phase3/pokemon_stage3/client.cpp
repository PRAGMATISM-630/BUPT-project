#include "client.h"
#include "Server.h"
#include "ui_client.h"

/////////////////////////////
//
//  filename: client.cpp
//  function: 客户端界面函数
//
/////////////////////////////

int lastUi=0;                           //记录上一个界面编号，以便返回上个界面（图形界面相关变量）
enum battleType{levelUpBattle,duel};    //比赛类型：升级赛/决斗赛
battleType currentBattleType;           //当前比赛类型
QString currentUserName;                //当前帐号用户名
extern QString pokemonName;             //宝可梦名字
int rPort=QRandomGenerator::global()->bounded(0,8888);


Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);

    //设置窗口大小
    setFixedSize(QSize(800,600));

    //设置窗口标题
    setWindowTitle("pokemon");

    //设置边框样式
    setStyleSheet();

    //设置按钮图标
    setButtonIcon();

    //将其他界面的控件隐藏，只显示登陆界面的控件
    hideWidget();

    //设置背景图片
    setBackground();

    //其他设置
    otherSettings();

    //设置定时器
    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(updateMyBullet()));
    timer->setTimerType(Qt::PreciseTimer);

    timer2=new QTimer;
    connect(timer2,SIGNAL(timeout()),this,SLOT(updateEnemyBullet()));
    timer2->setTimerType(Qt::PreciseTimer);

    timer3=new QTimer;
    connect(timer3,SIGNAL(timeout()),this,SLOT(on_ui6_normalAttack_clicked()));
    timer3->setTimerType(Qt::PreciseTimer);

    //初始化后续用来显示的表格
    table=nullptr;
    table2=nullptr;

    //与服务器建立通信
    udpSocket=new QUdpSocket(this);
    QHostAddress sender=udpSocket->localAddress();
    quint16 senderPort=udpSocket->localPort();
    udpSocket->bind(sender,senderPort);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(readPendingDatagrams()));
}


Client::~Client()
{
    delete ui;
}



void Client::updateDatabase()const                           //更新数据库
{
    user *oneUser=new user;

    oneUser->userName=currentUserName;
    oneUser->clientState=UPDATE_DATABASE;                      //当前操作为更新数据库
    oneUser->pokemonInfo=pokemonVector;                         //更新后的宝可梦数据

    //设置胜负场数、胜率、宝可梦数量
    oneUser->win=win;
    oneUser->lose=lose;
    if(win+lose==0)
        oneUser->winningPercentage=0;
    else
        oneUser->winningPercentage=double(win)/double(win+lose);
    //qDebug()<<"胜率:"<<oneUser->winningPercentage;
    oneUser->numPokemon=numPokemon;
    oneUser->numSuperPokemon=numSuperPokemon;

    //封装数据报
    QByteArray byteArray;
    byteArray.append((char*)oneUser,sizeof(user));
    udpSocket->writeDatagram(byteArray,QHostAddress::LocalHost,rPort);       //将数据报发送给服务器
}

QString Client::getChineseName(QString str)const             //获取宝可梦中文名
{
    if(str=="charmander") return "小火龙";
    if(str=="charizard") return "喷火龙";
    if(str=="talonflame") return "烈箭鹰";
    if(str=="bulbasaur") return "妙蛙种子";
    if(str=="sentret") return "尾立";
    if(str=="psyduck") return "可达鸭";
    if(str=="squirtle") return "杰尼龟";
    if(str=="gyarados") return "暴鲤龙";
    if(str=="suicune") return "水君";
    if(str=="pikachu") return "皮卡丘";
    if(str=="jigglypuff") return "胖丁";
    if(str=="pachirisu") return "帕奇利兹";
    if(str=="highAtk")  return "力量型";
    if(str=="highDef")  return "防御型";
    if(str=="highHp")  return "肉盾型";
    if(str=="highSpd")  return "敏捷型";
    exit(1);
}

pokemon *Client::getPokemon()                           //生成宝可梦
{
    pokemon *myPokemon;
    //随机获得一种宝可梦
    int type=QRandomGenerator::global()->bounded(0,12);         //生成随机数，确定宝可梦种类
    switch(type)
    {
    case 0:
        myPokemon=new charmander;
        break;
    case 1:
        myPokemon=new charizard;
        break;
    case 2:
        myPokemon=new talonflame;
        break;
    case 3:
        myPokemon=new bulbasaur;
        break;
    case 4:
        myPokemon=new sentret;
        break;
    case 5:
        myPokemon=new psyduck;
        break;
    case 6:
        myPokemon=new squirtle;
        break;
    case 7:
        myPokemon=new gyarados;
        break;
    case 8:
        myPokemon=new suicune;
        break;
    case 9:
        myPokemon=new pikachu;
        break;
    case 10:
        myPokemon=new jigglypuff;
        break;
    case 11:
        myPokemon=new pachirisu;
        break;
    default:
        myPokemon=nullptr;
        //qDebug()<<"Random number error";
        exit(1);
        break;
    }

    //随即设置初始属性
    uint atk=QRandomGenerator::global()->bounded(51,60);      //基础攻击51~60
    uint def=QRandomGenerator::global()->bounded(11,20);      //基础防御11~20
    uint maxHp=QRandomGenerator::global()->bounded(501,600);  //基础生命501~600
    uint spd=QRandomGenerator::global()->bounded(21,30);      //基础攻速21~30

    myPokemon->setAttributeValue(pokemonType[type/3],pokemonSubtype[type],atk,def,maxHp,maxHp,spd);     //设置属性值

    return myPokemon;
}

void Client::sendPokemon()                              //送出宝可梦
{
    //切换至宝可梦展示界面
    changeUi(4);

    ui->ui4_returnMainUi->setHidden(true);      //设置为不可返回

    //显示提示
    ui->hint->setHidden(false);
    ui->hint->setText(tr("战斗失败，请选择一只宝可梦送出"));

    //系统选出的供用户选择的宝可梦数量
    int choice=3;
    if(numPokemon<3)
        choice=numPokemon;

    otherPokemonVector.clear();

    int num[numPokemon];
    for(int i=0;i<numPokemon;i++)
        num[i]=0;

    QMap<int,int>seq;

    int i=1;
    while(i<=choice)        //取出choice只宝可梦
    {
        int x=QRandomGenerator::global()->bounded(0,numPokemon);
        if(num[x]==0)
        {
            num[x]=1;
            seq[i]=x;
        }
        else continue;
        otherPokemonVector.append(pokemonVector[x]);
        i++;
        //qDebug()<<x;
    }

    numOtherPokemon=otherPokemonVector.size();

    table=new QTableWidget(this);               //新建表格
    table->setGeometry(0,50,800,540);           //设置表格大小
    table->setColumnCount(5);                               //设置列数为5
    table->setRowCount(numOtherPokemon);                         //设置行数为宝可梦数

    //设置每列宽度或每行高度
    table->setColumnWidth(0,80);
    table->setColumnWidth(1,160);
    table->setColumnWidth(2,160);
    table->setColumnWidth(3,300);
    table->setColumnWidth(4,60);
    for(int i=0;i<numOtherPokemon;i++)
        table->setRowHeight(i,150);

    //设置列标签
    QStringList headerLabels;
    headerLabels << "序号" << "宝可梦" << "基本属性" <<"详细属性"<<"";
    table->setHorizontalHeaderLabels(headerLabels);

    //设置行标签
    QStringList rowLabels;
    for(int i=1;i<=numOtherPokemon;i++)
        rowLabels << "";
    table->setVerticalHeaderLabels(rowLabels);

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);  //内容不可修改

    QSignalMapper *signalMapper =new QSignalMapper(this);

    for(int row=0;row<numOtherPokemon;row++)
    {
        QTableWidgetItem *item0,*item2,*item3;          //表格项

        item0 = new QTableWidgetItem;
        item2 = new QTableWidgetItem;
        item3 = new QTableWidgetItem;

        item0->setTextAlignment(Qt::AlignCenter);       //居中显示
        item2->setTextAlignment(Qt::AlignCenter);
        item3->setTextAlignment(Qt::AlignCenter);

        item0->setText(QString::number(seq[row+1]));
        table->setItem(row,0,item0);                    //设置第0列显示


        QString name=otherPokemonVector[row]->getName();     //宝可梦名字
        QString path="./resourse/"+name+".png";         //图片所在路径
        QPixmap *pixmap=new QPixmap(path);
        QLabel *label = new QLabel;
        label->setScaledContents(true);
        label->setPixmap(*pixmap);
        table->setCellWidget(row,1,label);              //设置第1列图片显示


        QString type=otherPokemonVector[row]->getType();     //宝可梦类型
        int level=otherPokemonVector[row]->getLevel();
        int exp=otherPokemonVector[row]->getExp();
        QString str="类型: " + getChineseName(type) + "\n\n" + "名字: " + getChineseName(name) + "\n\n"
                +"等级: " + QString::number(level) + "\n\n" + "经验: " + QString::number(exp);
        item2->setText(str);
        table->setItem(row,2,item2);                    //设置第2列显示


        int atk=otherPokemonVector[row]->getAtk();
        int def=otherPokemonVector[row]->getDef();
        //int hp=otherPokemonVector[row]->getHp();
        int maxhp=otherPokemonVector[row]->getMaxHp();
        int spd=otherPokemonVector[row]->getSpd();
        str="攻击: " + QString::number(atk) + "\n\n"
           + "防御: " + QString::number(def) + "\n\n"
           + "速度: " + QString::number(spd) + "\n\n"
           + "生命值: " + QString::number(maxhp) + "/" + QString::number(maxhp);
        item3->setText(str);
        table->setItem(row,3,item3);                    //设置第3列显示

        QPushButton *btn=new QPushButton;
        btn->setText("送出");
        btn->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
        table->setCellWidget(row,4,btn);               //设置第4列显示
        signalMapper->setMapping(btn,QString("%1").arg(row));
        connect(btn,SIGNAL(clicked()),signalMapper,SLOT(map()));
    }
    connect(signalMapper,SIGNAL(mapped(const QString &)),this,SLOT(selectSendPokemon(const QString &)));

    table->show();
}

void Client::closeEvent(QCloseEvent *event)             //关闭界面时更新数据库
{
    updateDatabase();
}

void Client::getOtherPokemonInfo(const QString &str)    //获取用户名并向服务器查询他的宝可梦信息
{
    int row=str.toInt();            //获取表格所在行
    QString name=table2->item(row,1)->text();       //获取表格row行1列内容

    //封装数据报
    user *oneUser=new user;
    oneUser->userName=name;
    oneUser->clientState=GET_POKEMON_INFO;

    QByteArray byteArray;
    byteArray.append((char*)oneUser,sizeof(user));
    udpSocket->writeDatagram(byteArray,QHostAddress::LocalHost,rPort);       //将数据报发送给服务器

}

void Client::selectMyPokemon(const QString &str)        //选择我方宝可梦进行战斗
{
    table->hide();
    int row=str.toInt();
    myPokemon=pokemonVector[row];      //选择的我方宝可梦

    ui->ui4_returnMainUi->setHidden(true);      //设置为不可返回
    ui->ui5_hint->setText(tr("请选择敌方宝可梦"));

    otherPokemonVector.clear();
    for(int i=1;i<=15;i++)
    {
        pokemon* enemy=getPokemon();            //随机生成系统的宝可梦
        enemy->gainExp(levelUpExperience[i]);   //每个等级的宝可梦各一只，供用户选择
        otherPokemonVector.append(enemy);
    }

    numOtherPokemon=otherPokemonVector.size();

    table=new QTableWidget(this);
    table->setGeometry(0,50,800,540);         //设置表格大小
    table->setColumnCount(5);                               //设置列数为5
    table->setRowCount(numOtherPokemon);                         //设置行数为宝可梦数

    table->setColumnWidth(0,80);                    //设置每列宽度或每行高度
    table->setColumnWidth(1,160);
    table->setColumnWidth(2,160);
    table->setColumnWidth(3,300);
    table->setColumnWidth(4,60);

    for(int i=0;i<numOtherPokemon;i++)
        table->setRowHeight(i,150);

    QStringList headerLabels;                       //设置列标签
    headerLabels << "序号" << "宝可梦" << "基本属性" <<"详细属性"<<"";
    table->setHorizontalHeaderLabels(headerLabels);

    QStringList rowLabels;                          //设置行标签
    for(int i=1;i<=numOtherPokemon;i++)
        rowLabels << "";
    table->setVerticalHeaderLabels(rowLabels);

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);  //内容不可修改

    QSignalMapper *signalMapper =new QSignalMapper(this);

    for(int row=0;row<numOtherPokemon;row++)
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


        QString name=otherPokemonVector[row]->getName();     //宝可梦名字
        QString path="./resourse/"+name+".png";         //图片所在路径
        QPixmap *pixmap=new QPixmap(path);
        QLabel *label = new QLabel;
        label->setScaledContents(true);
        label->setPixmap(*pixmap);
        table->setCellWidget(row,1,label);              //设置第1列图片显示


        QString type=otherPokemonVector[row]->getType();     //宝可梦类型
        int level=otherPokemonVector[row]->getLevel();
        int exp=otherPokemonVector[row]->getExp();
        QString str="类型: " + getChineseName(type) + "\n\n" + "名字: " + getChineseName(name) + "\n\n"
                +"等级: " + QString::number(level) + "\n\n" + "经验: " + QString::number(exp);
        item2->setText(str);
        table->setItem(row,2,item2);                    //设置第2列显示


        int atk=otherPokemonVector[row]->getAtk();
        int def=otherPokemonVector[row]->getDef();
        //int hp=otherPokemonVector[row]->getHp();
        int maxhp=otherPokemonVector[row]->getMaxHp();
        int spd=otherPokemonVector[row]->getSpd();
        str="攻击: " + QString::number(atk) + "\n\n"
           + "防御: " + QString::number(def) + "\n\n"
           + "速度: " + QString::number(spd) + "\n\n"
           + "生命值: " + QString::number(maxhp) + "/" + QString::number(maxhp);
        item3->setText(str);
        table->setItem(row,3,item3);                    //设置第3列显示

        QPushButton *btn=new QPushButton;
        btn->setText("战斗!");
        btn->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
        table->setCellWidget(row,4,btn);               //设置第4列显示
        signalMapper->setMapping(btn,QString("%1").arg(row));
        connect(btn,SIGNAL(clicked()),signalMapper,SLOT(map()));
    }
    connect(signalMapper,SIGNAL(mapped(const QString &)),this,SLOT(selectEnemyPokemon(const QString &)));

    table->show();

}

void Client::selectEnemyPokemon(const QString &str)     //选择要对战的敌方宝可梦
{
    table->hide();
    int row=str.toInt();
    enemyPokemon=otherPokemonVector[row];

    ui->ui5_hint->setHidden(true);
    //qDebug()<<enemy->getName();


    changeUi(6);
    initializeUi6();
}

void Client::selectSendPokemon(const QString &str)      //选择要送出的宝可梦
{
    ui->hint->setHidden(true);
    table->hide();
    int row=str.toInt();
    int pokemonSeq=table->item(row,0)->text().toInt();
    numPokemon--;
    if(numPokemon==0)       //所有宝可梦输光了时系统自动分发一个宝可梦
    {
        pokemon* aPokemon=getPokemon();
        pokemonVector.append(aPokemon);
        numPokemon++;

        pokemonName=aPokemon->getName();
        getnewpokemon=new getNewPokemon;        //打开获得宝可梦界面
        getnewpokemon->show();
    }

    if(pokemonVector[pokemonSeq]->getLevel()==15)   //送走15级宝可梦
    {
        numSuperPokemon--;
    }
    pokemonVector.erase(pokemonVector.begin()+pokemonSeq);
    updateDatabase();
}

void Client::readPendingDatagrams()                     //接收来自服务器的信息
{
    QHostAddress sender;
    quint16 senderPort;

    while(udpSocket->hasPendingDatagrams())
    {
        message msg;
        udpSocket->readDatagram((char*)&msg,sizeof(msg),&sender,&senderPort);
        if(msg.serverState==GET_POKEMON_INFO)           //登录或注册时获取服务器发来的宝可梦信息
        {
            win=msg.win;
            lose=msg.lose;
            winningPercentage=msg.winningPercentage;
            numSuperPokemon=msg.numSuperPokemon;
            //qDebug()<<win<<' '<<lose;

            pokemonVector=msg.pokemonInfo;          //获取宝可梦信息
            numPokemon=pokemonVector.size();
            changeUi(2);
        }
        else if(msg.serverState==GET_OTHER_POKEMON_INFO)    //查看他人宝可梦信息
        {
            lastUi=3;
            changeUi(4);        //宝可梦展示界面
            otherPokemonVector.clear();
            otherPokemonVector=msg.pokemonInfo;
            numOtherPokemon=otherPokemonVector.size();

            table=new QTableWidget(this);
            table->setGeometry(0,50,800,540);         //设置表格大小
            table->setColumnCount(4);                               //设置列数为4
            table->setRowCount(numOtherPokemon);                         //设置行数为宝可梦数

            table->setColumnWidth(0,80);                    //设置每列宽度或每行高度
            table->setColumnWidth(1,160);
            table->setColumnWidth(2,160);
            table->setColumnWidth(3,360);
            for(int i=0;i<numOtherPokemon;i++)
                table->setRowHeight(i,150);

            QStringList headerLabels;                       //设置列标签
            headerLabels << "序号" << "宝可梦" << "基本属性" <<"详细属性";
            table->setHorizontalHeaderLabels(headerLabels);

            QStringList rowLabels;                          //设置行标签
            for(int i=1;i<=numOtherPokemon;i++)
                rowLabels << "";
            table->setVerticalHeaderLabels(rowLabels);

            table->setEditTriggers(QAbstractItemView::NoEditTriggers);  //内容不可修改

            for(int row=0;row<numOtherPokemon;row++)
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


                QString name=otherPokemonVector[row]->getName();     //宝可梦名字
                QString path="./resourse/"+name+".png";         //图片所在路径
                QPixmap *pixmap=new QPixmap(path);
                QLabel *label = new QLabel;
                label->setScaledContents(true);
                label->setPixmap(*pixmap);
                table->setCellWidget(row,1,label);              //设置第1列图片显示


                QString type=otherPokemonVector[row]->getType();     //宝可梦类型
                int level=otherPokemonVector[row]->getLevel();
                int exp=otherPokemonVector[row]->getExp();
                QString str="类型: " + getChineseName(type) + "\n\n" + "名字: " + getChineseName(name) + "\n\n"
                        +"等级: " + QString::number(level) + "\n\n" + "经验: " + QString::number(exp);
                item2->setText(str);
                table->setItem(row,2,item2);                    //设置第2列显示


                int atk=otherPokemonVector[row]->getAtk();
                int def=otherPokemonVector[row]->getDef();
                int hp=otherPokemonVector[row]->getHp();
                int maxhp=otherPokemonVector[row]->getMaxHp();
                int spd=otherPokemonVector[row]->getSpd();
                str="攻击: " + QString::number(atk) + "\n\n"
                   + "防御: " + QString::number(def) + "\n\n"
                   + "速度: " + QString::number(spd) + "\n\n"
                   + "生命值: " + QString::number(hp) + "/" + QString::number(maxhp);
                item3->setText(str);
                table->setItem(row,3,item3);                    //设置第3列显示

            }

            table->show();
        }
        else if(msg.serverState==GET_ALL_PLAYERS)       //查看所有用户信息
        {
            userVector=msg.userInfo;
            numUser=userVector.size();
            //qDebug()<<"用户数：";
            //qDebug()<<numUser;

            changeUi(3);        //用户展示界面

            table2=new QTableWidget(this);
            table2->setGeometry(0,50,800,540);         //设置表格大小
            table2->setColumnCount(4);                               //设置列数为4
            table2->setRowCount(numUser);                         //设置行数为用户数

            table2->setColumnWidth(0,80);                    //设置每列宽度或每行高度
            table2->setColumnWidth(1,160);
            table2->setColumnWidth(2,360);
            table2->setColumnWidth(3,160);
            for(int i=0;i<numUser;i++)
                table2->setRowHeight(i,90);

            QStringList headerLabels;                       //设置列标签
            headerLabels << "序号" << "用户" << "备注" <<"";
            table2->setHorizontalHeaderLabels(headerLabels);

            QStringList rowLabels;                          //设置行标签
            for(int i=1;i<=numUser;i++)
                rowLabels << "";
            table2->setVerticalHeaderLabels(rowLabels);

            table2->setEditTriggers(QAbstractItemView::NoEditTriggers);  //内容不可修改

            QSignalMapper *signalMapper =new QSignalMapper(this);

            for(int row=0;row<numUser;row++)
            {
                QTableWidgetItem *item0,*item1,*item2,*item3;
                item0 = new QTableWidgetItem;
                item1 = new QTableWidgetItem;
                item2 = new QTableWidgetItem;
                item3 = new QTableWidgetItem;
                item0->setTextAlignment(Qt::AlignCenter);       //居中显示
                item1->setTextAlignment(Qt::AlignCenter);
                item2->setTextAlignment(Qt::AlignCenter);
                item3->setTextAlignment(Qt::AlignCenter);

                item0->setText(QString::number(row+1));
                table2->setItem(row,0,item0);                   //设置第0列显示

                item1->setText(userVector[row]->userName);
                table2->setItem(row,1,item1);                   //设置第1列显示

                item2->setText(tr("胜场:")+QString::number(userVector[row]->win)
                               +tr("      负场")+QString::number(userVector[row]->lose)+"\n"
                               +tr("胜率:")+QString::number(int(userVector[row]->winningPercentage*100))+"%\n"
                               +tr("宝可梦数量:")+QString::number(userVector[row]->numPokemon)+"\n"
                               +tr("满级宝可梦数量:")+QString::number(userVector[row]->numSuperPokemon));
                table2->setItem(row,2,item2);                   //设置第2列显示

                QPushButton *btn=new QPushButton;
                btn->setText("查看ta的宝可梦");
                btn->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
                table2->setCellWidget(row,3,btn);               //设置第3列显示


                signalMapper->setMapping(btn,QString("%1").arg(row));
                connect(btn,SIGNAL(clicked()),signalMapper,SLOT(map()));
            }

            connect(signalMapper,SIGNAL(mapped(const QString &)),this,SLOT(getOtherPokemonInfo(const QString &)));

            table2->show();
        }
    }
}

void Client::on_ui3_returnMainUi_clicked()              //返回主界面
{
    if(table2)
        table2->hide();
    lastUi=3;
    changeUi(2);
}

void Client::on_ui4_returnMainUi_clicked()              //返回主界面
{
    if(table)
        table->hide();

    changeUi(lastUi);
    lastUi=4;

}

void Client::on_ui5_return_clicked()                    //返回上一界面
{
    lastUi=5;
    changeUi(2);
}

void Client::on_ui5_rules_clicked()                     //打开新界面——展示战斗规则
{
    rules=new rule;
    rules->show();
}

void Client::on_ui6_rules_clicked()                     //打开新界面——展示战斗规则
{
    rules=new rule;
    rules->show();
}

void Client::on_ui8_returnMainUi_clicked()              //返回主界面
{
    changeUi(2);
}




