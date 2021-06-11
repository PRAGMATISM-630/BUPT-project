#include "client.h"
#include "Server.h"
#include "ui_client.h"

/////////////////////////////
//
//  filename: battle.cpp
//  function: 与战斗相关的函数
//
/////////////////////////////

enum battleType{levelUpBattle,duel};        //比赛类型：升级赛/决斗赛
extern battleType currentBattleType;        //当前比赛类型

extern int lastUi;              //上个界面，用于界面之间的切换标记

QString pokemonName;            //宝可梦名字
int success=-1,fail=-1;         //标记胜利和失败，1表示真，0表示假，-1表示未定状态
int myLastDmg=0,enemyLastDmg=0; //我方/敌方上回合所受伤害
int myfire=0,enemyfire=0;       //双方怒气值
int count=0;                    //回合数（测试用）
bool flag=false;                //标记
bool side=0;                    //行动方，0表示我方行动，1表示敌方行动


void Client::on_ui5_levelUp_clicked()       //升级赛
{
    currentBattleType=levelUpBattle;            //当前为升级赛

    lastUi=5;                                   //上个界面为5（战斗选择界面）
    changeUi(4);                                //转到宝可梦展示界面

    ui->ui5_hint->setHidden(false);             //显示提示
    ui->ui5_hint->setText(tr("请选择我方宝可梦"));

    table=new QTableWidget(this);               //新建表格，展示宝可梦列表
    table->setGeometry(0,50,800,540);           //设置表格大小
    table->setColumnCount(5);                   //设置列数为5
    table->setRowCount(numPokemon);             //设置行数为宝可梦数

    //设置每列宽度或每行高度
    table->setColumnWidth(0,80);
    table->setColumnWidth(1,160);
    table->setColumnWidth(2,160);
    table->setColumnWidth(3,300);
    table->setColumnWidth(4,60);
    for(int i=0;i<numPokemon;i++)
        table->setRowHeight(i,150);

    //设置列标签
    QStringList headerLabels;
    headerLabels << "序号" << "宝可梦" << "基本属性" <<"详细属性"<<"";
    table->setHorizontalHeaderLabels(headerLabels);

    //设置行标签
    QStringList rowLabels;
    for(int i=1;i<=numPokemon;i++)
        rowLabels << "";
    table->setVerticalHeaderLabels(rowLabels);

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);  //内容不可修改

    //设置按钮匹配
    QSignalMapper *signalMapper =new QSignalMapper(this);

    for(int row=0;row<numPokemon;row++)
    {
        QTableWidgetItem *item0,*item2,*item3;          //表格项

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


        //获取各项属性以展示
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

        //设置按钮
        QPushButton *btn=new QPushButton;
        btn->setText("出战!");
        btn->setStyleSheet("border:2px groove gray;border-radius:15px;padding:2px 4px;");
        table->setCellWidget(row,4,btn);               //设置第4列显示

        //将按钮点击与获取按钮行槽函数相匹配
        signalMapper->setMapping(btn,QString("%1").arg(row));
        connect(btn,SIGNAL(clicked()),signalMapper,SLOT(map()));
    }

    connect(signalMapper,SIGNAL(mapped(const QString &)),this,SLOT(selectMyPokemon(const QString &)));

    //展示表格
    table->show();
}

void Client::on_ui5_battle_clicked()        //决斗赛
{
    currentBattleType=duel;                 //当前为决斗赛

    lastUi=5;                               //上个界面为5（战斗选择界面）
    changeUi(4);                            //切换到宝可梦展示界面

    ui->ui5_hint->setHidden(false);         //显示提示
    ui->ui5_hint->setText(tr("请选择我方宝可梦"));

    table=new QTableWidget(this);           //新建表格
    table->setGeometry(0,50,800,540);       //设置表格大小
    table->setColumnCount(5);               //设置列数为5
    table->setRowCount(numPokemon);         //设置行数为宝可梦数

    //设置每列宽度或每行高度
    table->setColumnWidth(0,80);
    table->setColumnWidth(1,160);
    table->setColumnWidth(2,160);
    table->setColumnWidth(3,300);
    table->setColumnWidth(4,60);
    for(int i=0;i<numPokemon;i++)
        table->setRowHeight(i,150);

    //设置列标签
    QStringList headerLabels;
    headerLabels << "序号" << "宝可梦" << "基本属性" <<"详细属性"<<"";
    table->setHorizontalHeaderLabels(headerLabels);

    //设置行标签
    QStringList rowLabels;
    for(int i=1;i<=numPokemon;i++)
        rowLabels << "";
    table->setVerticalHeaderLabels(rowLabels);

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);  //内容不可修改

    QSignalMapper *signalMapper =new QSignalMapper(this);

    for(int row=0;row<numPokemon;row++)
    {
        QTableWidgetItem *item0,*item2,*item3;          //表格项

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


        //获取各项属性展示
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

        //设置按钮
        QPushButton *btn=new QPushButton;
        btn->setText("出战!");
        btn->setStyleSheet("border:2px groove gray;border-radius:15px;padding:2px 4px;");
        table->setCellWidget(row,4,btn);               //设置第4列显示

        //将按钮点击与获取按钮行槽函数相匹配
        signalMapper->setMapping(btn,QString("%1").arg(row));
        connect(btn,SIGNAL(clicked()),signalMapper,SLOT(map()));
    }
    connect(signalMapper,SIGNAL(mapped(const QString &)),this,SLOT(selectMyPokemon(const QString &)));

    //展示表格
    table->show();
}

void Client::initializeUi6()                //初始化战斗界面
{
    //双方初始满生命
    myPokemon->updateHp(myPokemon->getMaxHp());
    enemyPokemon->updateHp(enemyPokemon->getMaxHp());

    //我方宝可梦贴图
    QString name=myPokemon->getName();              //宝可梦名字
    QString path="./resourse/"+name+".png";         //图片所在路径
    QImage image(path);
    QPixmap pixmap=QPixmap::fromImage(image.mirrored(true,false));  //镜像旋转
    ui->ui6_myPokemon->setPixmap(pixmap);
    ui->ui6_myPokemon->setScaledContents(true);

    //根据宝可梦类型获取技能，并显示提示条
    QString type=myPokemon->getType();
    QString imageName;
    if(type=="highAtk")
    {
        imageName="fire";
        ui->ui6_skill->setToolTip(tr("技能:愤怒\n本次攻击100%触发暴击，且攻击力提高100%"));
        ui->ui6_myPokemon->setToolTip(tr("技能:愤怒\n本次攻击100%触发暴击，且攻击力提高100%"));
    }
    else if(type=="highHp")
    {
        imageName="soil";
        ui->ui6_skill->setToolTip(tr("技能:顽强\n每损失3%最大生命，本次攻击造成的伤害提高10%"));
        ui->ui6_myPokemon->setToolTip(tr("技能:顽强\n每损失3%最大生命，本次攻击造成的伤害提高10%"));
    }
    else if(type=="highDef")
    {
        imageName="water";
        ui->ui6_skill->setToolTip(tr("技能:回复\n回复已损失生命的30%"));
        ui->ui6_myPokemon->setToolTip(tr("技能:回复\n回复已损失生命的30%"));
    }
    else if(type=="highSpd")
    {
        imageName="lightning";
        ui->ui6_skill->setToolTip(tr("技能:反弹\n对敌方造成上次被攻击所受伤害250%的伤害"));
        ui->ui6_myPokemon->setToolTip(tr("技能:反弹\n对敌方造成上次被攻击所受伤害250%的伤害"));
    }

    //设置我方子弹贴图
    QPixmap *pixmap2 = new QPixmap("./resourse/"+imageName+".png");
    pixmap2->scaled(ui->ui6_bullet->size(), Qt::KeepAspectRatio);
    ui->ui6_bullet->setScaledContents(true);
    ui->ui6_bullet->setPixmap(*pixmap2);

    //展示我方初始属性值
    ui->ui6_ATK->setText("攻击:"+QString::number(myPokemon->getAtk()));
    ui->ui6_DEF->setText("防御:"+QString::number(myPokemon->getDef()));
    ui->ui6_SPD->setText("速度:"+QString::number(myPokemon->getSpd()));
    ui->ui6_HP->setText("生命:"+QString::number(myPokemon->getHp())+"/"+QString::number(myPokemon->getMaxHp()));

    //敌方宝可梦贴图
    name=enemyPokemon->getName();     //宝可梦名字
    path="./resourse/"+name+".png";         //图片所在路径
    pixmap=QPixmap(path);
    ui->ui6_enemyPokemon->setPixmap(pixmap);
    ui->ui6_enemyPokemon->setScaledContents(true);

    //根据宝可梦类型获取技能，并显示提示条
    type=enemyPokemon->getType();
    if(type=="highAtk")
    {
        imageName="fire";
        ui->ui6_enemyPokemon->setToolTip(tr("技能:愤怒\n本次攻击100%触发暴击，且攻击力提高100%"));
    }
    else if(type=="highHp")
    {
        imageName="soil";
        ui->ui6_enemyPokemon->setToolTip(tr("技能:顽强\n每损失3%最大生命，本次攻击造成的伤害提高10%"));
    }
    else if(type=="highDef")
    {
        imageName="water";
        ui->ui6_enemyPokemon->setToolTip(tr("技能:回复\n回复已损失生命的30%"));
    }
    else if(type=="highSpd")
    {
        imageName="lightning";
        ui->ui6_enemyPokemon->setToolTip(tr("技能:反弹\n对敌方造成上次被攻击所受伤害250%的伤害"));
    }

    //设置敌方子弹贴图
    QImage image2("./resourse/"+imageName+".png");
    pixmap=QPixmap::fromImage(image2.mirrored(true,false));
    ui->ui6_bullet_2->setPixmap(pixmap);
    ui->ui6_bullet_2->setScaledContents(true);

    //展示敌方属性值
    ui->ui6_ATK_2->setText("攻击:"+QString::number(enemyPokemon->getAtk()));
    ui->ui6_DEF_2->setText("防御:"+QString::number(enemyPokemon->getDef()));
    ui->ui6_SPD_2->setText("速度:"+QString::number(enemyPokemon->getSpd()));
    ui->ui6_HP_2->setText("生命:"+QString::number(enemyPokemon->getHp())+"/"+QString::number(enemyPokemon->getMaxHp()));

    //双方初始怒气值为0
    myfire=enemyfire=0;
    ui->ui6_myfire->setHidden(true);
    ui->ui6_enemyfire->setHidden(true);

    //怒气值为0禁用技能
    ui->ui6_skill->setDisabled(true);

    flag=false;

    int spd1=myPokemon->getSpd();
    int spd2=enemyPokemon->getSpd();

    if(spd1>=spd2)  //我方速度值更高时
    {
        side=0;
        ui->ui6_turn->setText(tr("我方回合"));
        ui->ui6_enemyTurn->setDisabled(true);
        ui->ui6_normalAttack->setDisabled(false);
        if(myfire==5)
        {
            ui->ui6_skill->setDisabled(false);      //怒气值为5时可以使用技能
        }

    }
    else            //敌方速度值更高
    {
        side=1;
        ui->ui6_turn->setText(tr("敌方回合"));
        ui->ui6_enemyTurn->setDisabled(false);
        ui->ui6_normalAttack->setDisabled(true);
        ui->ui6_skill->setDisabled(true);       //禁用技能
        Sleep(1000);
        on_ui6_enemyTurn_clicked();         //敌方按下普通攻击
    }
}

void Client::updateMyBullet()               //更新我方子弹坐标
{
    QPoint point=ui->ui6_bullet->pos();         //获取当前子弹坐标

    if(point.x()<=720)
    {
        ui->ui6_bullet->setGeometry(point.x()+10,point.y(),50,50);  //子弹右移，重置坐标

        if(point.x()>=480)
        {
            ui->ui6_bullet->setHidden(true);    //不显示子弹

            if(fail==0) //胜利
            {
                flag=true;

                if(timer3->isActive())  //如果是自动战斗则停止定时器
                    timer3->stop();

                //设置自动战斗按钮贴图
                QIcon icon=QIcon("./resourse/auto.png");
                ui->ui6_autobattle->setText("自动战斗");
                ui->ui6_autobattle->setIcon(icon);
                ui->ui6_autobattle->setIconSize(QSize(70,70));
                ui->ui6_autobattle->setStyleSheet("background-color:rgba(0,0,0,0)");
                ui->ui6_autobattle->setFocusPolicy(Qt::NoFocus);
                ui->ui6_autobattle->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

                //切换至战斗结算界面
                changeUi(7);

                //奖杯贴图
                ui->ui7_prize->setHidden(false);
                QPixmap *pixmap = new QPixmap("./resourse/prize.png");
                pixmap->scaled(ui->ui7_prize->size(), Qt::KeepAspectRatio);
                ui->ui7_prize->setScaledContents(true);
                ui->ui7_prize->setPixmap(*pixmap);

                //胜负指示贴图
                pixmap=new QPixmap("./resourse/win.png");
                pixmap->scaled(ui->ui7_winLose->size(), Qt::KeepAspectRatio);
                ui->ui7_winLose->setScaledContents(true);
                ui->ui7_winLose->setPixmap(*pixmap);

                //我方参战宝可梦贴图
                QString name=myPokemon->getName();     //宝可梦名字
                QString path="./resourse/"+name+".png";         //图片所在路径
                QImage image(path);
                *pixmap=QPixmap::fromImage(image.mirrored(true,false));
                ui->ui7_pokemon->setPixmap(*pixmap);
                ui->ui7_pokemon->setScaledContents(true);

                //获取经验值展示
                ui->ui7_exp->setFont(QFont("仿宋",25));
                ui->ui7_exp->setText("exp +200");

                //初始化到未定状态
                fail=-1;
            }
        }
    }
    else if(flag==false)
    {
            on_ui6_enemyTurn_clicked();         //敌方进行普攻
    }
}

void Client::updateEnemyBullet()            //更新敌方子弹坐标
{
    //获取子弹坐标
    QPoint point=ui->ui6_bullet_2->pos();


    if(point.x()<=270)
    {
        ui->ui6_bullet_2->setHidden(true);      //隐藏子弹

        if(fail==1)
        {
            if(timer3->isActive())              //如果位于自动战斗则停止计时器
                timer3->stop();

            //设置自动战斗贴图
            QIcon icon=QIcon("./resourse/auto.png");
            ui->ui6_autobattle->setText("自动战斗");
            ui->ui6_autobattle->setIcon(icon);
            ui->ui6_autobattle->setIconSize(QSize(70,70));
            ui->ui6_autobattle->setStyleSheet("background-color:rgba(0,0,0,0)");
            ui->ui6_autobattle->setFocusPolicy(Qt::NoFocus);
            ui->ui6_autobattle->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

            //切换至战斗结算界面
            changeUi(7);

            //失败时隐藏奖杯
            ui->ui7_prize->setHidden(true);

            //设置胜负指示贴图
            QPixmap *pixmap=new QPixmap("./resourse/lose.png");
            pixmap->scaled(ui->ui7_winLose->size(), Qt::KeepAspectRatio);
            ui->ui7_winLose->setScaledContents(true);
            ui->ui7_winLose->setPixmap(*pixmap);

            //设置参展宝可梦贴图
            QString name=myPokemon->getName();     //宝可梦名字
            QString path="./resourse/"+name+".png";         //图片所在路径
            QImage image(path);
            *pixmap=QPixmap::fromImage(image.mirrored(true,false));
            ui->ui7_pokemon->setPixmap(*pixmap);
            ui->ui7_pokemon->setScaledContents(true);

            //获取经验值展示
            ui->ui7_exp->setFont(QFont("仿宋",25));
            ui->ui7_exp->setText("exp +100");

            fail=-1;
        }
        return;
    }
    else
    {
        //更新敌方子弹坐标
        ui->ui6_bullet_2->setGeometry(point.x()-10,point.y(),50,50);
    }
}

void Client::on_ui6_skill_clicked()         //我方使用技能
{
    //使用技能，怒气值清零
    myfire=0;
    ui->ui6_myfire->setHidden(true);

    if(side==0)
    {
        bool dodge;     //标记闪避
        skillName name; //技能名
        int atk=myPokemon->useSkill(name);      //使用技能

        switch(name)
        {
        case RAGE:
        case TENACITY:
        {
            updateEnemyFire();  //敌方受击，更新怒气值
            ui->ui6_bullet->setVisible(true);   //子弹可见
            ui->ui6_bullet->setGeometry(270,290,50,50);
            timer->start(30);   //启动我方子弹移动定时器

            int dmg=enemyPokemon->takeDamage(atk,dodge);    //敌方宝可梦承受伤害
            //qDebug()<<"最终伤害："<<dmg;
            if(dodge==true)     //成功闪避
            {
                ui->ui6_mark->setHidden(false);
                ui->ui6_mark->setText(tr("闪避"));
            }
            else
            {
                ui->ui6_mark->setText(tr(name==RAGE?"技能：愤怒":"技能：顽强"));
                ui->ui6_mark->setHidden(false);
            }

            enemyLastDmg=dmg;       //设置敌方上回合所受伤害

            //显示伤害数字
            ui->ui6_damage->setText(tr("-")+QString::number(dmg));
            ui->ui6_damage->setHidden(false);
            ui->ui6_damage->setGeometry(580,180,90,60);

            //更新敌方生命值展示
            ui->ui6_HP_2->setText("生命:"+QString::number(enemyPokemon->getHp())+"/"+QString::number(enemyPokemon->getMaxHp()));

            break;
        }

        case REFRESH:

            myPokemon->updateHp(myPokemon->getHp()+atk);    //回复生命
            ui->ui6_HP->setText("生命:"+QString::number(myPokemon->getHp())+"/"+QString::number(myPokemon->getMaxHp()));
            ui->ui6_damage->setText(tr("+")+QString::number(atk));
            ui->ui6_damage->setHidden(false);
            ui->ui6_damage->setGeometry(110,180,90,60);
            ui->ui6_bullet->setVisible(false);
            ui->ui6_bullet->setGeometry(270,290,50,50);
            timer->start(30);

            ui->ui6_mark->setText(tr("技能：回复"));
            ui->ui6_mark->setHidden(false);

            break;

        case REBOUND:
        {
            updateEnemyFire();
            int atk=myLastDmg*2.5;      //我方上回合所受伤害的2.5倍
            //qDebug()<<"技能：反弹\n上次所受伤害："<<myLastDmg;

            ui->ui6_bullet->setVisible(true);
            ui->ui6_bullet->setGeometry(270,290,50,50);
            timer->start(30);

            int dmg=enemyPokemon->takeDamage(atk,dodge);
            //qDebug()<<"最终伤害："<<dmg;
            if(dodge==true)
            {
                ui->ui6_mark->setHidden(false);
                ui->ui6_mark->setText(tr("闪避"));
            }
            else
            {
                ui->ui6_mark->setText(tr("技能：反弹"));
                ui->ui6_mark->setHidden(false);
            }

            enemyLastDmg=dmg;       //设置敌方上回合所受伤害

            //显示伤害数字
            ui->ui6_damage->setText(tr("-")+QString::number(dmg));
            ui->ui6_damage->setHidden(false);
            ui->ui6_damage->setGeometry(580,180,90,60);

            //更新敌方生命值显示
            ui->ui6_HP_2->setText("生命:"+QString::number(enemyPokemon->getHp())+"/"+QString::number(enemyPokemon->getMaxHp()));

            break;
        }

        default:
            break;
        }

        if(enemyPokemon->judgeDeath())      //胜利
        {

            win++;      //胜利局数增加

            if(currentBattleType==levelUpBattle)    //升级赛，只获得经验
            {
                myPokemon->updateHp(myPokemon->getMaxHp()); //回复满生命值
                if(myPokemon->gainExp(200)&&myPokemon->getLevel()==15)       //满级
                {
                    numSuperPokemon++;
                }

            }
            else if(currentBattleType==duel)        //决斗赛，获得战胜的宝可梦，同时获得经验
            {
                if(myPokemon->gainExp(200)&&myPokemon->getLevel()==15)       //满级
                {
                    numSuperPokemon++;
                }
                myPokemon->updateHp(myPokemon->getMaxHp()); //回复满生命值
                enemyPokemon->updateHp(enemyPokemon->getMaxHp());
                if(enemyPokemon->getLevel()==15)       //满级
                {
                    numSuperPokemon++;
                }
                pokemonVector.append(enemyPokemon);
                numPokemon++;
                pokemonName=enemyPokemon->getName();
                success=1;
            }
            updateDatabase();

            fail=0;


        }

        //修改为我方子弹到达敌方时切换
        side=1;
        ui->ui6_turn->setText(tr("敌方回合"));
        ui->ui6_normalAttack->setDisabled(true);
        ui->ui6_skill->setDisabled(true);
        ui->ui6_enemyTurn->setDisabled(false);


    }
}

void Client::enemyTurnSkill()               //敌方回合使用技能
{
    //使用技能，怒气值清零
    enemyfire=0;
    ui->ui6_enemyfire->setHidden(true);

    if(side==1)
    {
        bool dodge;         //标记闪避
        skillName name;     //技能名
        int atk=enemyPokemon->useSkill(name);   //使用技能

        switch(name)
        {
        case RAGE:
        case TENACITY:
        {
            updateMyFire();
            ui->ui6_bullet_2->setVisible(true);
            ui->ui6_bullet_2->setGeometry(480,290,50,50);
            timer2->start(30);

            int dmg=myPokemon->takeDamage(atk,dodge);
            //qDebug()<<"最终伤害："<<dmg;
            if(dodge==true)
            {
                ui->ui6_mark->setHidden(false);
                ui->ui6_mark->setText(tr("闪避"));
            }
            else
            {
                ui->ui6_mark->setText(tr(name==RAGE?"技能：愤怒":"技能：顽强"));
                ui->ui6_mark->setHidden(false);
            }

            myLastDmg=dmg;
            ui->ui6_damage->setText(tr("-")+QString::number(dmg));
            ui->ui6_damage->setHidden(false);
            ui->ui6_damage->setGeometry(110,180,90,60);

            ui->ui6_HP->setText("生命:"+QString::number(myPokemon->getHp())+"/"+QString::number(myPokemon->getMaxHp()));

            break;
        }

        case REFRESH:

            enemyPokemon->updateHp(enemyPokemon->getHp()+atk);    //回复生命
            ui->ui6_HP_2->setText("生命:"+QString::number(enemyPokemon->getHp())+"/"+QString::number(enemyPokemon->getMaxHp()));
            ui->ui6_damage->setText(tr("+")+QString::number(atk));
            ui->ui6_damage->setHidden(false);
            ui->ui6_damage->setGeometry(580,180,90,60);
            ui->ui6_bullet_2->setVisible(false);
            ui->ui6_bullet_2->setGeometry(480,290,50,50);
            timer2->start(30);

            ui->ui6_mark->setText(tr("技能：回复"));
            ui->ui6_mark->setHidden(false);

            break;

        case REBOUND:
        {
            updateMyFire();
            int atk=enemyLastDmg*2.5;      //我方上回合所受伤害的2.5倍
            //qDebug()<<"技能：反弹\n上次所受伤害："<<myLastDmg;

            ui->ui6_bullet_2->setVisible(true);
            ui->ui6_bullet_2->setGeometry(480,290,50,50);
            timer2->start(30);

            int dmg=myPokemon->takeDamage(atk,dodge);
            //qDebug()<<"最终伤害："<<dmg;
            if(dodge==true)
            {
                ui->ui6_mark->setHidden(false);
                ui->ui6_mark->setText(tr("闪避"));
            }
            else
            {
                ui->ui6_mark->setText(tr("技能：反弹"));
                ui->ui6_mark->setHidden(false);
            }

            myLastDmg=dmg;
            ui->ui6_damage->setText(tr("-")+QString::number(dmg));
            ui->ui6_damage->setHidden(false);
            ui->ui6_damage->setGeometry(110,180,90,60);

            ui->ui6_HP->setText("生命:"+QString::number(myPokemon->getHp())+"/"+QString::number(myPokemon->getMaxHp()));

            break;
        }



        default:
            break;
        }



        if(myPokemon->judgeDeath())
        {
            lose++;
            if(currentBattleType==levelUpBattle)    //升级赛，只获得经验
            {
                if(myPokemon->gainExp(100)&&myPokemon->getLevel()==15)       //满级
                {
                    numSuperPokemon++;
                }
                myPokemon->updateHp(myPokemon->getMaxHp()); //回复满生命值
            }
            else if(currentBattleType==duel)        //决斗赛，失去宝可梦
            {
                success=0;
                if(myPokemon->gainExp(100)&&myPokemon->getLevel()==15)       //满级
                {
                    numSuperPokemon++;
                }
                myPokemon->updateHp(myPokemon->getMaxHp()); //回复满生命值

            }
            updateDatabase();

            fail=1;

        }

        //修改为敌人子弹到达我方时转换
        side=0;
        ui->ui6_turn->setText(tr("我方回合"));
        if(!timer3->isActive())
        {
            ui->ui6_normalAttack->setDisabled(false);
            if(myfire==5)
            {
                ui->ui6_skill->setDisabled(false);
            }
        }
        ui->ui6_enemyTurn->setDisabled(true);
    }
}

void Client::on_ui6_normalAttack_clicked()  //我方回合普通攻击
{
    if(timer3->isActive()&&myfire==5)       //自动战斗状态下，我方怒气值积累到5
    {
        on_ui6_skill_clicked();     //自动释放技能
        return;
    }
    if(side==0)
    {
        updateEnemyFire();
        bool critical,dodge;
        int atk=myPokemon->attack(critical);
        ui->ui6_bullet->setVisible(true);
        ui->ui6_bullet->setGeometry(270,290,50,50);
        timer->start(30);
        int dmg=enemyPokemon->takeDamage(atk,dodge);        //敌方承受伤害

        if(dodge==true)
        {
            ui->ui6_mark->setHidden(false);
            ui->ui6_mark->setText(tr("闪避"));
        }
        else if(critical==true)
        {
            ui->ui6_mark->setHidden(false);
            ui->ui6_mark->setText(tr("暴击"));
        }
        else
            ui->ui6_mark->setHidden(true);

        enemyLastDmg=dmg;
        ui->ui6_damage->setText(tr("-")+QString::number(dmg));
        ui->ui6_damage->setHidden(false);
        ui->ui6_damage->setGeometry(580,180,90,60);
        //Sleep(500);
        //ui->ui6_damage->setHidden(true);

        ////qDebug()<<"第"<<++count<<"回合：我方伤害："<<dmg;
        ui->ui6_HP_2->setText("生命:"+QString::number(enemyPokemon->getHp())+"/"+QString::number(enemyPokemon->getMaxHp()));

        if(enemyPokemon->judgeDeath())      //胜利
        {

            win++;
            if(currentBattleType==levelUpBattle)    //升级赛，只获得经验
            {
                myPokemon->updateHp(myPokemon->getMaxHp()); //回复满生命值
                if(myPokemon->gainExp(200)&&myPokemon->getLevel()==15)       //满级
                {
                    numSuperPokemon++;
                }

            }
            else if(currentBattleType==duel)        //决斗赛，获得战胜的宝可梦，同时获得经验
            {
                if(myPokemon->gainExp(200)&&myPokemon->getLevel()==15)       //满级
                {
                    numSuperPokemon++;
                }
                myPokemon->updateHp(myPokemon->getMaxHp()); //回复满生命值
                enemyPokemon->updateHp(enemyPokemon->getMaxHp());
                if(enemyPokemon->getLevel()==15)       //满级
                {
                    numSuperPokemon++;
                }
                pokemonVector.append(enemyPokemon);
                numPokemon++;
                pokemonName=enemyPokemon->getName();
                success=1;
            }
            updateDatabase();

            fail=0;


        }

        //修改为我方子弹到达敌方时切换
        side=1;
        ui->ui6_turn->setText(tr("敌方回合"));
        ui->ui6_normalAttack->setDisabled(true);
        ui->ui6_skill->setDisabled(true);
        ui->ui6_enemyTurn->setDisabled(false);
    }
}

void Client::on_ui6_enemyTurn_clicked()     //敌方回合普通攻击
{
    if(enemyfire==5)       //自动战斗状态下，敌方怒气值积累到5
    {
        enemyTurnSkill();     //自动释放技能
        return;
    }
    if(side==1)
    {
        updateMyFire();
        ui->ui6_bullet_2->setVisible(true);
        ui->ui6_bullet_2->setGeometry(480,290,50,50);
        timer2->start(30);

        bool critical,dodge;
        int atk=enemyPokemon->attack(critical);
        int dmg=myPokemon->takeDamage(atk,dodge);

        if(dodge==true)
        {
            ui->ui6_mark->setHidden(false);
            ui->ui6_mark->setText(tr("闪避"));
        }
        else if(critical==true)
        {
            ui->ui6_mark->setHidden(false);
            ui->ui6_mark->setText(tr("暴击"));
        }
        else
            ui->ui6_mark->setHidden(true);

        myLastDmg=dmg;      //我方所受伤害
        ui->ui6_damage->setText(tr("-")+QString::number(dmg));
        ui->ui6_damage->setHidden(false);
        ui->ui6_damage->setGeometry(110,180,90,60);
        //Sleep(500);
        //ui->ui6_damage->setHidden(true);

        ////qDebug()<<"第"<<++count<<"回合：敌方伤害："<<dmg;
        ui->ui6_HP->setText("生命:"+QString::number(myPokemon->getHp())+"/"+QString::number(myPokemon->getMaxHp()));

        if(myPokemon->judgeDeath())
        {
            lose++;
            if(currentBattleType==levelUpBattle)    //升级赛，只获得经验
            {
                if(myPokemon->gainExp(100)&&myPokemon->getLevel()==15)       //满级
                {
                    numSuperPokemon++;
                }
                myPokemon->updateHp(myPokemon->getMaxHp()); //回复满生命值
            }
            else if(currentBattleType==duel)        //决斗赛，失去宝可梦
            {
                success=0;
                if(myPokemon->gainExp(100)&&myPokemon->getLevel()==15)       //满级
                {
                    numSuperPokemon++;
                }
                myPokemon->updateHp(myPokemon->getMaxHp()); //回复满生命值

            }
            updateDatabase();

            fail=1;

        }


        //修改为敌人子弹到达我方时转换
        side=0;
        ui->ui6_turn->setText(tr("我方回合"));
        if(!timer3->isActive())
        {
            ui->ui6_normalAttack->setDisabled(false);
            if(myfire==5)
            {
                ui->ui6_skill->setDisabled(false);
            }
        }
        ui->ui6_enemyTurn->setDisabled(true);
    }
}

void Client::on_ui7_ack_clicked()           //战斗结束界面确认
{
    if(success==1)  //胜利
    {
        getnewpokemon=new getNewPokemon;        //打开获得宝可梦界面
        getnewpokemon->show();
    }
    else if(success==0)
    {
        changeUi(4);
        sendPokemon();      //失去一只宝可梦

        //if(numPokemon!=0) success=-1;    //重置为初始值
        updateDatabase();           //更新数据库
    }

    changeUi(2);
}

void Client::on_ui6_returnMainUi_clicked()  //退出战斗返回主界面
{
    QMessageBox::StandardButton defaultBtn=QMessageBox::NoButton;
    QMessageBox::StandardButton result;
    result=QMessageBox::question(this,"警告","战斗中退出将不会获得经验，是否继续退出？",
                                 QMessageBox::Yes|QMessageBox::No,defaultBtn);
    if(result==QMessageBox::Yes)
    {
        //回到主界面，所有定时器停止
        changeUi(2);
        timer3->stop();
        timer->stop();
        timer2->stop();

        //设置为自动战斗图标
        QIcon icon=QIcon("./resourse/auto.png");
        ui->ui6_autobattle->setText("自动战斗");
        ui->ui6_autobattle->setIcon(icon);
        ui->ui6_autobattle->setIconSize(QSize(70,70));
        ui->ui6_autobattle->setStyleSheet("background-color:rgba(0,0,0,0)");
        ui->ui6_autobattle->setFocusPolicy(Qt::NoFocus);
        ui->ui6_autobattle->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    }
    else return;
}

void Client::on_ui6_autobattle_clicked()    //启动/取消自动战斗
{
    if(!timer3->isActive())     //非自动战斗状态
    {
        //启动自动战斗
        timer3->start(2500);    //每2.5秒展示一个回合的动画

        //图标设置为停止
        QIcon icon=QIcon("./resourse/pause.png");
        ui->ui6_autobattle->setText("取消自动");
        ui->ui6_autobattle->setIcon(icon);
        ui->ui6_autobattle->setIconSize(QSize(70,70));
        ui->ui6_autobattle->setStyleSheet("background-color:rgba(0,0,0,0)");
        ui->ui6_autobattle->setFocusPolicy(Qt::NoFocus);
        ui->ui6_autobattle->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        //自动战斗下禁止手动普攻或技能
        ui->ui6_normalAttack->setDisabled(true);
        ui->ui6_skill->setDisabled(true);

    }
    else                        //自动战斗状态
    {
        //取消自动战斗
        timer3->stop();         //停止动画自动展示

        //图标设置为自动
        QIcon icon=QIcon("./resourse/auto.png");
        ui->ui6_autobattle->setText("自动战斗");
        ui->ui6_autobattle->setIcon(icon);
        ui->ui6_autobattle->setIconSize(QSize(70,70));
        ui->ui6_autobattle->setStyleSheet("background-color:rgba(0,0,0,0)");
        ui->ui6_autobattle->setFocusPolicy(Qt::NoFocus);
        ui->ui6_autobattle->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        //解除自动战斗，可以使用普攻
        ui->ui6_normalAttack->setDisabled(false);

        //怒气值满条件下允许使用技能
        if(myfire==5)
            ui->ui6_skill->setDisabled(false);
    }

}

void Client::updateMyFire()                 //更新我方怒气值
{
    //我方受击，增加我方怒气值
    int num=QRandomGenerator::global()->bounded(1,3);   //生成1~2个怒气值
    myfire+=num;
    if(myfire>5)        //上限为5点
        myfire=5;
    //qDebug()<<myfire;

    //设置怒气值贴图
    if(myfire==0)
    {
        ui->ui6_myfire->setHidden(true);
    }
    else
    {      
        ui->ui6_myfire->setHidden(false);
        QString path="./resourse/nuqi"+QString::number(myfire)+".png";
        QPixmap *pixmap = new QPixmap(path);
        pixmap->scaled(ui->ui6_myfire->size(), Qt::KeepAspectRatio);
        ui->ui6_myfire->setScaledContents(true);
        ui->ui6_myfire->setPixmap(*pixmap);
    }
}

void Client::updateEnemyFire()              //更新敌方怒气值
{
    //敌方受击，增加敌方怒气值
    int num=QRandomGenerator::global()->bounded(1,3);   //生成1~2个怒气值
    enemyfire+=num;
    if(enemyfire>5)        //上限为5点
        enemyfire=5;
    qDebug()<<enemyfire;

    //设置怒气值贴图
    if(enemyfire==0)
    {
        ui->ui6_enemyfire->setHidden(true);
    }
    else
    {
        ui->ui6_enemyfire->setHidden(false);
        QString path="./resourse/nuqi"+QString::number(enemyfire)+".png";
        QPixmap *pixmap = new QPixmap(path);
        pixmap->scaled(ui->ui6_enemyfire->size(), Qt::KeepAspectRatio);
        ui->ui6_enemyfire->setScaledContents(true);
        ui->ui6_enemyfire->setPixmap(*pixmap);
    }
}


