#include"pokemon.h"


/////////////////////////////
//
//  filename: pokemon.cpp
//  function: 宝可梦类的方法
//
/////////////////////////////

pokemon::pokemon()                  //构造函数
{
    level=1;
    exp=0;
}

pokemon::~pokemon(){}               //析构函数

bool pokemon::gainExp(int Exp)      //获得经验函数
{
    bool levelUp=false;          //判断是否升级的标志
    if(level==15)                //15级为满级
        return false;
    exp+=Exp;
    while(exp>=levelUpExperience[level+1])  //升级后各属性提升
    {
        level++;
        levelUp=true;

        if(level==15)       //15级满级
        {
            Exp=levelUpExperience[level];
            return levelUp;
        }

        //升级时四项属性线性增加
        atk+=5;
        maxHp+=60;
        def+=2;
        spd+=3;

        //主属性获得额外的10%的指数增幅
        if(type=="highAtk") atk*=1.1;
        if(type=="highDef") def*=1.1;
        if(type=="highHp") maxHp*=1.1;
        if(type=="highSpd") spd*=1.1;

    }
    return levelUp;
}

int pokemon::takeDamage(int dmg,bool &dodge)            //承受伤害函数
{
    int n=QRandomGenerator::global()->bounded(0,10);         //n是0~9之间的随机数
    double dodgeProbability=0.1;    //闪避率10%
    if(n<int(dodgeProbability*10))  //n为0时闪避
    {
        qDebug()<<"闪避";
        dodge=true;
        return 0;
    }
    else dodge=false;

    int tmp=dmg-def;        //敌方攻击值减去我方防御值
    if(tmp>0)               //敌人攻击值高于我方防御值，造成伤害
    {
        if(hp<tmp)          //我方死亡
            tmp=hp;         //造成的伤害只能为死亡前所剩生命值
        hp-=tmp;
    }
    else                    //敌方攻击未能破防
        tmp=0;
    return tmp;
}

bool pokemon::judgeDeath()const          //判断是否死亡
{
    if(hp==0)
        return true;
    else
        return false;
}

void pokemon::setAttributeValue(QString Type, QString Name, int Atk, int Def, int MaxHp, int Hp, int Spd)   //设置属性值
{
    type=Type;
    name=Name;
    atk=Atk;
    def=Def;
    maxHp=MaxHp;
    hp=Hp;
    spd=Spd;
}

void pokemon::setLevelAndExp(int Level, int Exp)        //设置等级和经验值
{
    level=Level;
    exp=Exp;
}

void pokemon::updateHp(int hp)                          //更新生命值
{
    this->hp=hp;
}

void pokemon::updateLevelAndExpTest()                   //测试函数，用于检验数据库是否更新
{
    level++;
    exp+=5;
}
