#include"pokemon.h"


pokemon::pokemon()               //构造函数
{
    level=1;
    exp=0;
}

pokemon::~pokemon(){}            //析构函数          

int pokemon::gainExp(uint Exp)   //获得经验函数
{
    bool levelUp=false;          //判断是否升级的标志
    exp+=Exp;
    while(exp>=levelUpExperience[level+1])  //升级后各属性提升
    {
        level++;

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

        //升级时生命值回复满
        hp=maxHp;

        levelUp=true;
    }
    if(levelUp)
        return level;
    else
        return -1;              //返回-1表示未升级
}


int pokemon::takeDamage(uint dmg)     //承受伤害函数
{
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

bool pokemon::judgeDeath()            //判断是否死亡
{
    if(hp==0)
        return true;
    else
        return false;
}

void pokemon::setAttributeValue(QString Type, QString Name, uint Atk, uint Def, uint MaxHp, int Hp, uint Spd)   //设置属性值
{
    type=Type;
    name=Name;
    atk=Atk;
    def=Def;
    maxHp=MaxHp;
    hp=Hp;
    spd=Spd;
}


