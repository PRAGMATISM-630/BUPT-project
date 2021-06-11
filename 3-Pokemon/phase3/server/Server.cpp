#include "Server.h"
#include "client.h"

/////////////////////////////
//
//  filename: Server.cpp
//  function: 服务器端函数
//
/////////////////////////////

extern int rPort;

server::server(QWidget *parent) :
    QWidget(parent)
{
    db=QSqlDatabase::addDatabase("QSQLITE");            //使用QSQLITE数据库
    db.setDatabaseName("database.db");                  //设置数据库名字
    if(!db.open())                                      //数据库打开失败
    {
        qDebug()<<"database open failed";
    }

    QSqlQuery query;
    //query.exec("DROP TABLE user");                    //清空用户账户信息数据库
    query.exec("CREATE TABLE user("                     //建立用户账户信息数据库
               "username VARCHAR(40) NOT NULL,"         //用户名
               "password VARCHAR(40) NOT NULL,"         //密码
               "win INTEGER NOT NULL,"                  //胜场
               "lose INTEGER NOT NULL,"                 //负场
               "winningpercentage DOUBLE NOT NULL,"     //胜率
               "numpokemon INTEGER NOT NULL,"           //宝可梦数量
               "numsuperpokemon INTEGER NOT NULL)");    //高级宝可梦数量

    //query.exec("DROP TABLE pokemon");                 //清空宝可梦信息数据库
    query.exec("CREATE TABLE pokemon("                  //建立宝可梦信息数据库
               "username VARCHAR(40) NOT NULL,"         //主人用户名
               "type VARCHAR(40) NOT NULL,"             //类型
               "name VARCHAR(40) NOT NULL,"             //名字
               "level INTEGER NOT NULL,"                //等级
               "exp INTEGER NOT NULL,"                  //经验
               "atk INTEGER NOT NULL,"                  //攻击
               "def INTEGER NOT NULL,"                  //防御
               "maxhp INTEGER NOT NULL,"                //最大生命值
               "hp INTEGER NOT NULL,"                   //当前生命值
               "spd INTEGER NOT NULL)");                //速度


    udpSocket=new QUdpSocket(this);                     //与客户端之间使用UDP通信
    udpSocket->bind(QHostAddress::LocalHost,rPort);      //本地地址，端口号rPort
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(readPendingDatagrams()));   //建立连接
}

server::~server()
{
}

pokemon *server::getPokemon()const                   //获取宝可梦
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
        qDebug()<<"Random number error";
        exit(1);
        break;
    }

    //随机设置初始属性
    uint atk=QRandomGenerator::global()->bounded(51,60);      //基础攻击51~60
    uint def=QRandomGenerator::global()->bounded(11,20);      //基础防御11~20
    uint maxHp=QRandomGenerator::global()->bounded(501,600);  //基础生命501~600
    uint spd=QRandomGenerator::global()->bounded(21,30);      //基础攻速21~30

    myPokemon->setAttributeValue(pokemonType[type/3],pokemonSubtype[type],atk,def,maxHp,maxHp,spd);     //设置属性值

    return myPokemon;
}

void server::readPendingDatagrams()const             //从客户端获取的数据报
{
    QHostAddress sender;                        //IP地址
    quint16 senderPort;                         //端口号

    while(udpSocket->hasPendingDatagrams())     //收到数据报
    {
        user oneUser;
        udpSocket->readDatagram((char*)&oneUser,sizeof(oneUser),&sender,&senderPort);   //读取数据报信息到oneUser中

        QString name=oneUser.userName;          //用户名


        if(oneUser.clientState==SIGN_UP)       //注册
        {
            QVector<pokemon*>pokemonVector;     //宝可梦仓库
            pokemonVector.clear();

            QSqlQuery query;
            query.exec("select * from user where username=\""+name+"\";" );     //查询user表中username项值为name的项
            if(query.next())     //用户名已存在，注册失败
            {
                qDebug()<<"用户名已存在，注册失败\n";
                QMessageBox::about(NULL, "警告", "该用户名已被注册，请直接登录或更换用户名进行注册");
            }

            else        //该用户名未被注册
            {
                if(oneUser.userName=="")        //用户名为空，注册失败
                    QMessageBox::about(NULL, "警告", "用户名不能为空");

                else if(oneUser.password=="")   //密码为空，注册失败
                    QMessageBox::about(NULL, "警告", "密码不能为空");

                else
                {
                    qDebug()<<"注册成功\n";

                    QMessageBox::about(NULL, "提示", "注册成功");

                    QSqlQuery query;
                    query.prepare("INSERT INTO user (username, password,win,lose,winningpercentage,numpokemon,numsuperpokemon) "
                                     "VALUES (:username,:password,:win,:lose,:winningpercentage,:numpokemon,:numsuperpokemon)");      //设置数据库表格格式

                    query.bindValue(":username", name);                     //绑定数据
                    query.bindValue(":password", oneUser.password );
                    query.bindValue(":win", 0 );
                    query.bindValue(":lose", 0 );
                    query.bindValue(":winningpercentage", 0 );
                    query.bindValue(":numpokemon", 3 );
                    query.bindValue(":numsuperpokemon", 0 );
                    query.exec();                                           //向数据库中添加数据项

                    for(int i=1;i<=3;i++)       //首次登录随机获得三只宝可梦
                    {
                        pokemon *myPokemon=getPokemon();
                        pokemonVector.append(myPokemon);

                        //设置数据库表格格式
                        query.prepare("INSERT INTO pokemon (username,type,name,level,exp,atk,def,maxhp,hp,spd) "
                                         "VALUES (:username,:type,:name,:level,:exp,:atk,:def,:maxhp,:hp,:spd)");
                        //绑定数据
                        query.bindValue(":username", name);
                        query.bindValue(":type", myPokemon->getType());
                        query.bindValue(":name", myPokemon->getName());
                        query.bindValue(":level", myPokemon->getLevel());
                        query.bindValue(":exp", myPokemon->getExp());
                        query.bindValue(":atk", myPokemon->getAtk());
                        query.bindValue(":def", myPokemon->getDef());
                        query.bindValue(":maxhp", myPokemon->getMaxHp());
                        query.bindValue(":hp", myPokemon->getHp());
                        query.bindValue(":spd",myPokemon->getSpd());
                        query.exec();
                    }

                    //生成发回客户端的数据报，将宝可梦信息发回给客户端
                    message *msg=new message;
                    msg->serverState=GET_POKEMON_INFO;
                    msg->pokemonInfo=pokemonVector;
                    msg->win=0;
                    msg->lose=0;
                    msg->winningPercentage=0;
                    msg->numPokemon=3;
                    msg->numSuperPokemon=0;

                    QByteArray byteArray;
                    byteArray.append((char*)msg,sizeof(message));
                    udpSocket->writeDatagram(byteArray,sender,senderPort);      //发送数据报


                }
            }
        }

        else if(oneUser.clientState==SIGN_IN)      //登录
        {            
            QVector<pokemon*>pokemonVector;
            pokemonVector.clear();

            QSqlQuery query;
            query.exec("select * from user where username=\""+name+"\";" );     //查询user表中username项值为name的项


            if(!query.next ())    //用户名不存在
                QMessageBox::about(NULL, "警告", "用户名不存在");

            else if(query.value(1).toString()!=oneUser.password)   //密码错误
                QMessageBox::about(NULL, "警告", "密码错误");

            else if(oneUser.userName==""||oneUser.password=="")      //用户名或密码为空
                QMessageBox::about(NULL, "警告", "用户名或密码不能为空");

            else
            {
                qDebug()<<"登陆成功\n";

                QSqlQuery query;
                query.exec("select * from pokemon where username=\""+name+"\";" );      //查询pokemon表中username项值为name的项

                while(query.next())             //从数据库中取出宝可梦信息，放入容器中
                {

                    pokemon* aPokemon;

                    QString type=query.value(1).toString();
                    QString name=query.value(2).toString();

                    if(name=="charmander") aPokemon=new charmander;
                    else if(name=="charizard") aPokemon=new charizard;
                    else if(name=="talonflame") aPokemon=new talonflame;
                    else if(name=="bulbasaur") aPokemon=new bulbasaur;
                    else if(name=="sentret") aPokemon=new sentret;
                    else if(name=="psyduck") aPokemon=new psyduck;
                    else if(name=="squirtle") aPokemon=new squirtle;
                    else if(name=="gyarados") aPokemon=new gyarados;
                    else if(name=="suicune") aPokemon=new suicune;
                    else if(name=="pikachu") aPokemon=new pikachu;
                    else if(name=="jigglypuff") aPokemon=new jigglypuff;
                    else if(name=="pachirisu") aPokemon=new pachirisu;

                    int level=query.value(3).toInt();
                    int exp=query.value(4).toInt();
                    int atk=query.value(5).toInt();
                    int def=query.value(6).toInt();
                    int maxhp=query.value(7).toInt();
                    int hp=query.value(8).toInt();
                    int spd=query.value(9).toInt();

                    aPokemon->setAttributeValue(type,name,atk,def,maxhp,hp,spd);
                    aPokemon->setLevelAndExp(level,exp);
                    pokemonVector.append(aPokemon);

                }

                message *msg=new message;
                msg->serverState=GET_POKEMON_INFO;
                msg->pokemonInfo=pokemonVector;

                query.exec("select * from user where username=\""+name+"\";" );
                if(query.next())
                {
                    //将宝可梦信息封装为数据报

                    msg->win=query.value(2).toInt();;
                    msg->lose=query.value(3).toInt();
                    msg->winningPercentage=query.value(4).toDouble();
                    msg->numPokemon=query.value(5).toInt();
                    msg->numSuperPokemon=query.value(6).toInt();
                }

                QByteArray byteArray;
                byteArray.append((char*)msg,sizeof(message));
                udpSocket->writeDatagram(byteArray,sender,senderPort);          //将数据报发送给客户端
            }
        }

        else if(oneUser.clientState==GET_POKEMON_INFO)      //查看他人宝可梦信息
        {
            QVector<pokemon*>pokemonVector;
            pokemonVector.clear();
            //qDebug()<<name;


            QSqlQuery query;
            query.exec("select * from pokemon where username=\""+name+"\";" );      //查询pokemon表中username项值为name的项
            while(query.next())     //从数据库中取出宝可梦信息，放入容器中
            {
                pokemon* aPokemon;

                QString type=query.value(1).toString();
                QString name=query.value(2).toString();

                if(name=="charmander") aPokemon=new charmander;
                else if(name=="charizard") aPokemon=new charizard;
                else if(name=="talonflame") aPokemon=new talonflame;
                else if(name=="bulbasaur") aPokemon=new bulbasaur;
                else if(name=="sentret") aPokemon=new sentret;
                else if(name=="psyduck") aPokemon=new psyduck;
                else if(name=="squirtle") aPokemon=new squirtle;
                else if(name=="gyarados") aPokemon=new gyarados;
                else if(name=="suicune") aPokemon=new suicune;
                else if(name=="pikachu") aPokemon=new pikachu;
                else if(name=="jigglypuff") aPokemon=new jigglypuff;
                else if(name=="pachirisu") aPokemon=new pachirisu;

                int level=query.value(3).toInt();
                int exp=query.value(4).toInt();
                int atk=query.value(5).toInt();
                int def=query.value(6).toInt();
                int maxhp=query.value(7).toInt();
                int hp=query.value(8).toInt();
                int spd=query.value(9).toInt();

                aPokemon->setAttributeValue(type,name,atk,def,maxhp,hp,spd);
                aPokemon->setLevelAndExp(level,exp);
                pokemonVector.append(aPokemon);
            }



            //将宝可梦信息封装为数据报
            message *msg=new message;
            msg->serverState=GET_OTHER_POKEMON_INFO;
            msg->pokemonInfo=pokemonVector;

            QByteArray byteArray;
            byteArray.append((char*)msg,sizeof(message));
            udpSocket->writeDatagram(byteArray,sender,senderPort);          //将数据报发送给客户端

        }

        else if(oneUser.clientState==GET_ALL_PLAYERS)               //查看所有玩家信息
        {
            message *msg=new message;                           //生成数据报
            msg->serverState=GET_ALL_PLAYERS;
            msg->userInfo.clear();

            QSqlQuery query;
            query.exec("select * from user;" );             //从数据库user表中取出所有项
            while(query.next())                             //将所用用户的信息封装进数据报中
            {

                user *oneUser=new user;
                oneUser->userName=query.value(0).toString();
                oneUser->win=query.value(2).toInt();
                oneUser->lose=query.value(3).toInt();
                oneUser->winningPercentage=query.value(4).toDouble();
                oneUser->numPokemon=query.value(5).toInt();
                oneUser->numSuperPokemon=query.value(6).toInt();

                msg->userInfo.append(oneUser);
            }

            qDebug()<<"用户："<<msg->userInfo.size();

            QByteArray byteArray;
            byteArray.clear();
            byteArray.append((char*)msg,sizeof(message));
            udpSocket->writeDatagram(byteArray,sender,senderPort);         //将数据报发送给客户端

        }

        else if(oneUser.clientState==UPDATE_DATABASE)                   //更新数据库
        {
            int win=oneUser.win;
            int lose=oneUser.lose;
            double winningpercentage=oneUser.winningPercentage;
            int numpokemon=oneUser.numPokemon;
            int numsuperpokemon=oneUser.numSuperPokemon;

            QString password;
            QSqlQuery query;
            query.exec("select * from user where username=\""+name+"\";" );
            if(query.next())
                password=query.value(1).toString();

            query.exec("delete from user where username=\""+name+"\";" );

            query.prepare("INSERT INTO user (username, password,win,lose,winningpercentage,numpokemon,numsuperpokemon) "
                             "VALUES (:username,:password,:win,:lose,:winningpercentage,:numpokemon,:numsuperpokemon)");      //设置数据库表格格式
            query.bindValue(":username", name);                     //绑定数据
            query.bindValue(":password", password );
            query.bindValue(":win", win );
            query.bindValue(":lose", lose );
            query.bindValue(":winningpercentage", winningpercentage );
            query.bindValue(":numpokemon", numpokemon );
            query.bindValue(":numsuperpokemon", numsuperpokemon );
            query.exec();                                           //向数据库中添加数据项



            QVector<pokemon*>pokemonVector=oneUser.pokemonInfo;


            query.exec("delete from pokemon where username=\""+name+"\";" );        //删除数据库Pokemon表中username值为name的所有项

            query.prepare("INSERT INTO pokemon (username,type,name,level,exp,atk,def,maxhp,hp,spd) "        //设置数据格式
                             "VALUES (:username,:type,:name,:level,:exp,:atk,:def,:maxhp,:hp,:spd)");
            for(int i=0;i<pokemonVector.size();i++)                         //重新插入数据项至数据库中
            {
                //绑定数据
                query.bindValue(":username", name);
                query.bindValue(":type", pokemonVector[i]->getType());
                query.bindValue(":name", pokemonVector[i]->getName());
                query.bindValue(":level", pokemonVector[i]->getLevel());
                query.bindValue(":exp", pokemonVector[i]->getExp());
                query.bindValue(":atk", pokemonVector[i]->getAtk());
                query.bindValue(":def", pokemonVector[i]->getDef());
                query.bindValue(":maxhp", pokemonVector[i]->getMaxHp());
                query.bindValue(":hp", pokemonVector[i]->getHp());
                query.bindValue(":spd",pokemonVector[i]->getSpd());

                query.exec();               //执行数据插入
            }
        }
    }
}


