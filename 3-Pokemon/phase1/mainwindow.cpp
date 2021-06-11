#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTime>
#include "pokemonsubtype.h"

const int enemyInitialHp=300;       //敌方初始生命值
int enemyHp=300;                    //敌方生命值

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    //将界面中展示的控件全部设置为只读
    ui->infomation->setReadOnly(true);
    ui->ATK->setReadOnly(true);
    ui->DEF->setReadOnly(true);
    ui->HP->setReadOnly(true);
    ui->level->setReadOnly(true);
    ui->EXP->setReadOnly(true);
    ui->enemyHP->setReadOnly(true);
    ui->SPD->setReadOnly(true);
    ui->name->setReadOnly(true);
    ui->type->setReadOnly(true);

    getPokemon();
}

MainWindow::~MainWindow()
{
    delete ui;

    delete myPokemon;
}

void MainWindow::getPokemon()       //获得/更换一只宝可梦
{
    //随机获得一种宝可梦
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int type=qrand()%12;
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
        break;
    }

    //随即设置初始属性
    uint atk=qrand()%10+51;      //基础攻击51~60
    uint def=qrand()%10+11;      //基础防御11~20
    uint maxHp=qrand()%100+501;  //基础生命501~600
    uint spd=qrand()%10+21;      //基础攻速21~30
    myPokemon->setAttributeValue(pokemonType[type/3],pokemonSubtype[type],atk,def,maxHp,maxHp,spd);

    //在界面中显示各项属性
    ui->type->setText(pokemonType[type/3]);
    ui->name->setText(pokemonSubtype[type]);
    ui->level->setText(QString::number(1));
    ui->EXP->setText(QString::number(0)+"/"+QString::number(levelUpExperience[2]-levelUpExperience[1]));
    ui->ATK->setText(QString::number(atk));
    ui->DEF->setText(QString::number(def));
    ui->HP->setText(QString::number(maxHp)+"/"+QString::number(maxHp));
    ui->SPD->setText(QString::number(spd));
    ui->enemyHP->setText(QString::number(enemyHp)+"/"+QString::number(enemyInitialHp));

    //将攻击、受击、获得经验按钮设为可用
    ui->gainExpBtn->setDisabled(false);
    if(enemyHp!=0)      //敌方未死，则可以攻击或受击
    {
        ui->attackBtn->setDisabled(false);
        ui->takeDamageBtn->setDisabled(false);
    }

}


void MainWindow::on_attackBtn_clicked()     //攻击
{
    int damage=myPokemon->getAtk();
    ui->infomation->insertPlainText("我方宝可梦向敌人发动技能'"+myPokemon->attack()+"'"
                                    +"，造成"+QString::number(damage)+"点伤害！\n");
    if(enemyHp<=damage)
    {
        enemyHp=0;
        ui->enemyHP->setText(QString::number(0)+"/"+QString::number(enemyInitialHp));
        ui->infomation->insertPlainText("敌方宝可梦死亡，恭喜您获得了胜利!\n");
        ui->attackBtn->setDisabled(true);       //敌方死亡后将不再无法攻击
        ui->takeDamageBtn->setDisabled(true);   //也不会再受到攻击
    }
    else        //敌方未死亡
    {
        enemyHp-=damage;
        ui->enemyHP->setText(QString::number(enemyHp)+"/"+QString::number(enemyInitialHp));
    }

}

void MainWindow::on_takeDamageBtn_clicked()     //受击
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int damage=myPokemon->takeDamage(qrand()%100+1);     //随机受到敌方攻击力为1~100的攻击
    ui->infomation->insertPlainText("敌方发动攻击，对我方宝可梦造成"+QString::number(damage)+"点伤害!\n");
    updateHp(myPokemon->getHp(),myPokemon->getMaxHp());

    if(myPokemon->judgeDeath())     //我方宝可梦死亡，攻击、受击、获取经验按钮失效
    {
        ui->attackBtn->setDisabled(true);
        ui->gainExpBtn->setDisabled(true);
        ui->takeDamageBtn->setDisabled(true);
        ui->infomation->insertPlainText("我方宝可梦死亡，请重新获取一只宝可梦!\n");
    }
}

void MainWindow::on_gainExpBtn_clicked()        //获得经验
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    uint experience=qrand()%9+1;       //随机获取1~9点经验
    ui->infomation->insertPlainText("宝可梦获得了"+QString::number(experience)+"经验！\n");
    int tmp=myPokemon->gainExp(experience);

    if(tmp!=-1)
    {
        ui->infomation->insertPlainText("恭喜您的宝可梦升到了"+QString::number(tmp)+"级！\n");
        updateAttributeValue(myPokemon->getAtk(),myPokemon->getMaxHp(),myPokemon->getDef(),myPokemon->getSpd());
    }

    updateLevelAndExp(myPokemon->getLevel(),myPokemon->getExp());
}

void MainWindow::on_clear_clicked()             //清除信息界面
{
    ui->infomation->clear();
}

void MainWindow::updateAttributeValue(uint atk, uint maxHp, uint def, uint spd)     //更新属性值
{
    ui->ATK->setText(QString::number(atk));
    ui->HP->setText(QString::number(maxHp)+"/"+QString::number(maxHp));
    ui->DEF->setText(QString::number(def));
    ui->SPD->setText(QString::number(spd));
}

void MainWindow::updateHp(uint hp,uint maxHp)   //更新生命值
{
    ui->HP->setText(QString::number(hp)+"/"+QString::number(maxHp));
}

void MainWindow::updateLevelAndExp(uint level,uint exp)     //更新等级经验值
{
    ui->level->setText(QString::number(level));
    ui->EXP->setText(QString::number(exp-levelUpExperience[level])+"/"+
                     QString::number(levelUpExperience[level+1]-levelUpExperience[level]));
}

void MainWindow::on_getPokemonBtn_clicked()     //获取/更换宝可梦
{
    delete myPokemon;
    ui->infomation->clear();
    getPokemon();
}

void MainWindow::on_resetEnemy_clicked()            //重置敌人生命值
{
    enemyHp=enemyInitialHp;
    ui->infomation->insertPlainText("重置敌人生命值\n");
    ui->enemyHP->setText(QString::number(enemyHp)+"/"+QString::number(enemyInitialHp));

    if(!myPokemon->judgeDeath())
    {
        ui->attackBtn->setDisabled(false);
        ui->takeDamageBtn->setDisabled(false);
    }


}
