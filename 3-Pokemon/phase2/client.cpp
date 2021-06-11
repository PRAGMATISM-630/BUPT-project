#include "client.h"
#include "Server.h"
#include "ui_client.h"



int lastUi=0;     //记录上一个界面编号，以便返回上个界面
QString currentUserName;    //当前帐号用户名

Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);

    //设置背景图片
    QPalette pal;
    QPixmap pixmap=QPixmap("./resourse/cover.png");
    pal.setBrush(QPalette::Background,QBrush(pixmap));
    setPalette(pal);

    setWindowTitle("pokemon");


    ui->ui1_background->setStyleSheet("QLabel{background-color:rgb(255,255,255);}");    //将QLabel设置为空白背景，防止图片挡住字体
    ui->ui1_label->raise();     //使ui1_label于背景上方显示

    //将其他界面的控件隐藏，只显示登陆界面的控件
    ui->ui2_myPokemon->setHidden(true);
    ui->ui2_allPlayers->setHidden(true);
    ui->ui2_saveAndQuit->setHidden(true);
    ui->ui2_returnSignIn->setHidden(true);
    ui->ui3_returnMainUi->setHidden(true);
    ui->ui4_returnMainUi->setHidden(true);

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

void Client::changeUi(int n)            //以隐藏和显示控件的方式来切换界面
{
    switch(n)
    {
    case 1:         //登录界面
        ui->ui1_label->setHidden(false);
        ui->ui1_label_2->setHidden(false);
        ui->ui1_signIn->setHidden(false);
        ui->ui1_signUp->setHidden(false);
        ui->ui1_password->setHidden(false);
        ui->ui1_userName->setHidden(false);
        ui->ui1_background->setHidden(false);

        ui->ui2_myPokemon->setHidden(true);
        ui->ui2_allPlayers->setHidden(true);
        ui->ui2_saveAndQuit->setHidden(true);
        ui->ui2_returnSignIn->setHidden(true);
        ui->ui4_returnMainUi->setHidden(true);
        ui->ui3_returnMainUi->setHidden(true);
        break;

    case 2:         //主界面
        ui->ui1_label->setHidden(true);
        ui->ui1_label_2->setHidden(true);
        ui->ui1_signIn->setHidden(true);
        ui->ui1_signUp->setHidden(true);
        ui->ui1_password->setHidden(true);
        ui->ui1_userName->setHidden(true);
        ui->ui1_background->setHidden(true);
        ui->ui3_returnMainUi->setHidden(true);
        ui->ui4_returnMainUi->setHidden(true);

        ui->ui2_myPokemon->setHidden(false);
        ui->ui2_allPlayers->setHidden(false);
        ui->ui2_saveAndQuit->setHidden(false);
        ui->ui2_returnSignIn->setHidden(false);
        break;

    case 3:         //用户列表展示界面
        ui->ui3_returnMainUi->setHidden(false);

        ui->ui1_label->setHidden(true);
        ui->ui1_label_2->setHidden(true);
        ui->ui1_signIn->setHidden(true);
        ui->ui1_signUp->setHidden(true);
        ui->ui1_password->setHidden(true);
        ui->ui1_userName->setHidden(true);
        ui->ui1_background->setHidden(true);
        ui->ui2_myPokemon->setHidden(true);
        ui->ui2_allPlayers->setHidden(true);
        ui->ui2_saveAndQuit->setHidden(true);
        ui->ui2_returnSignIn->setHidden(true);
        ui->ui4_returnMainUi->setHidden(true);
        break;


    case 4:         //宝可梦展示界面
        ui->ui4_returnMainUi->setHidden(false);

        ui->ui1_label->setHidden(true);
        ui->ui1_label_2->setHidden(true);
        ui->ui1_signIn->setHidden(true);
        ui->ui1_signUp->setHidden(true);
        ui->ui1_password->setHidden(true);
        ui->ui1_userName->setHidden(true);
        ui->ui1_background->setHidden(true);
        ui->ui2_myPokemon->setHidden(true);
        ui->ui2_allPlayers->setHidden(true);
        ui->ui2_saveAndQuit->setHidden(true);
        ui->ui2_returnSignIn->setHidden(true);
        ui->ui3_returnMainUi->setHidden(true);
        break;


    default:
        break;
    }
}

void Client::updateDatabase()                               //更新数据库
{
    user *oneUser=new user;

    oneUser->userName=currentUserName;
    oneUser->clientState=UPDATE_DATABASE;                      //当前操作为更新数据库
    oneUser->pokemonInfo=pokemonVector;                         //更新后的宝可梦数据

    //封装数据报
    QByteArray byteArray;
    byteArray.append((char*)oneUser,sizeof(user));
    udpSocket->writeDatagram(byteArray,QHostAddress::LocalHost,8888);       //将数据报发送给服务器
}

QString Client::getChineseName(QString str)
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

pokemon *Client::getPokemon()
{
    pokemon *myPokemon;
    //随机获得一种宝可梦
    int type=QRandomGenerator::global()->bounded(0,11);         //生成随机数，确定宝可梦种类
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
        qDebug()<<"Random number error";
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
    udpSocket->writeDatagram(byteArray,QHostAddress::LocalHost,8888);       //将数据报发送给服务器
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
    udpSocket->writeDatagram(byteArray,QHostAddress::LocalHost,8888);       //将数据报发送给服务器
}

void Client::getRow(const QString &str)                     //获取用户名并向服务器查询
{
    int row=str.toInt();            //获取表格所在行
    QString name=table2->item(row,1)->text();       //获取表格row行1列内容

    //封装数据报
    user *oneUser=new user;
    oneUser->userName=name;
    oneUser->clientState=GET_POKEMON_INFO;

    QByteArray byteArray;
    byteArray.append((char*)oneUser,sizeof(user));
    udpSocket->writeDatagram(byteArray,QHostAddress::LocalHost,8888);       //将数据报发送给服务器

}

void Client::readPendingDatagrams()         //接收来自服务器的信息
{
    QHostAddress sender;
    quint16 senderPort;

    while(udpSocket->hasPendingDatagrams())
    {
        message msg;
        udpSocket->readDatagram((char*)&msg,sizeof(msg),&sender,&senderPort);
        if(msg.serverState==GET_POKEMON_INFO)           //登录或注册时获取服务器发来的宝可梦信息
        {
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
        else if(msg.serverState==GET_ALL_PLAYERS)
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
                table2->setRowHeight(i,60);

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

                QPushButton *btn=new QPushButton;
                btn->setText("查看ta的宝可梦");
                table2->setCellWidget(row,3,btn);               //设置第3列显示


                signalMapper->setMapping(btn,QString("%1").arg(row));
                connect(btn,SIGNAL(clicked()),signalMapper,SLOT(map()));
            }

            connect(signalMapper,SIGNAL(mapped(const QString &)),this,SLOT(getRow(const QString &)));

            table2->show();
        }
    }
}

void Client::on_ui2_returnSignIn_clicked()      //返回登录界面
{
//    pokemonVector[0]->updateLevelAndExpTest();
//    pokemon *onePokemon=getPokemon();
//    pokemonVector.append(onePokemon);
    updateDatabase();
    changeUi(1);
}

void Client::on_ui2_saveAndQuit_clicked()       //退出游戏
{
//    pokemonVector[1]->updateLevelAndExpTest();
//    pokemon *onePokemon=getPokemon();
//    pokemonVector.append(onePokemon);
    updateDatabase();
    close();
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
        int hp=pokemonVector[row]->getHp();
        int maxhp=pokemonVector[row]->getMaxHp();
        int spd=pokemonVector[row]->getSpd();
        str="攻击: " + QString::number(atk) + "\n\n"
           + "防御: " + QString::number(def) + "\n\n"
           + "速度: " + QString::number(spd) + "\n\n"
           + "生命值: " + QString::number(hp) + "/" + QString::number(maxhp);
        item3->setText(str);
        table->setItem(row,3,item3);                    //设置第3列显示


    }

    table->show();
}

void Client::on_ui3_returnMainUi_clicked()      //返回界面
{
    if(table2)
        table2->hide();
    changeUi(2);
}

void Client::on_ui4_returnMainUi_clicked()      //返回界面
{
    if(table)
        table->hide();
    if(lastUi==2)
        changeUi(2);
    else if(lastUi==3)
        changeUi(3);

}

void Client::on_ui2_allPlayers_clicked()
{
    user *oneUser=new user;

    oneUser->clientState=GET_ALL_PLAYERS;           //操作为查看所有玩家信息

    QByteArray byteArray;
    byteArray.append((char*)oneUser,sizeof(user));
    udpSocket->writeDatagram(byteArray,QHostAddress::LocalHost,8888);       //发送给服务器
}


