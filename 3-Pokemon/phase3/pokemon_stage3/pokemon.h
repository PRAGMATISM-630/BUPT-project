#ifndef POKEMON_H
#define POKEMON_H

/////////////////////////////
//
//  filename: pokemon.h
//  function: 该文件定义了宠物小精灵的基类
//
/////////////////////////////

#include<QVector>
#include<QString>
#include<QObject>
#include<QRandomGenerator>
#include<QDebug>

const int MAX_LEVEL=15;         //满级15级

const QVector<int> levelUpExperience={0,0,10,25,50,80,120,180,250,350,500,700,950,1250,1600,2000}; //各等级所需经验值

const QVector<QString> pokemonType =        //宝可梦类型
{
    "highAtk",           //高攻击类(ATK: attack)
    "highHp",            //高生命类(HP: health point)
    "highDef",           //高防御类(DEF: defense)
    "highSpd"            //高攻速类(SPD: speed)
};

const QVector<QString> pokemonSubtype =   //宝可梦子类型
{
    //火系，对应HIGH_ATK类
    "charmander", //小火龙
    "charizard",   //喷火龙
    "talonflame", //烈箭鹰

    //土系，对应HIGH_HP类
    "bulbasaur",  //妙蛙种子
    "sentret",    //尾立
    "psyduck",    //可达鸭

    //水系，对应HIGH_DEF类
    "squirtle",   //杰尼龟
    "gyarados",   //暴鲤龙
    "suicune",    //水君

    //电系，对应HIGH_SPD类
    "pikachu",    //皮卡丘
    "jigglypuff", //胖丁
    "pachirisu"   //帕奇利兹
};

const QVector<QString> SKILL={
    "rage",     //愤怒：攻击力提高100%，且100%触发暴击(火系）
    "tenacity", //顽强：每损失3%最大生命，下次攻击造成的伤害提高10%（土系）
    "refresh",  //回复：回复已损失生命的30%（水系）
    "rebound"   //反弹：对敌方造成上次被攻击所受伤害250%的伤害 (电系）
};

enum skillName{RAGE,TENACITY,REFRESH,REBOUND};     //技能名


class pokemon : public QObject              //宝可梦类
{
    Q_OBJECT

public:
    pokemon();                                  //构造函数
    ~pokemon();                                 //析构函数

    virtual int attack(bool &)const=0 ;         //攻击函数
    virtual int useSkill(skillName &)const=0;   //使用技能
    bool gainExp(int Exp);                      //获得经验函数
    int takeDamage(int dmg,bool &);             //承受伤害函数
    bool judgeDeath()const;                     //判断死亡

    int getLevel()const{return level;}          //获取等级信息
    int getExp()const{return exp;}              //获取经验值信息
    int getAtk()const{return atk;}              //获取攻击值
    int getMaxHp()const{return maxHp;}          //获取最大生命值
    int getHp()const{return hp;}                //获取生命值信息
    int getDef()const{return def;}              //获取防御值
    int getSpd()const{return spd;}              //获取攻速值
    QString getType()const{return type;}        //获取种类
    QString getName()const{return name;}        //获取名字

    void setAttributeValue(QString Type,QString Name,int Atk,int Def,int MaxHp,int Hp,int Spd);       //设置宝可梦属性值
    void setLevelAndExp(int Level,int Exp); //设置等级和经验值
    void updateHp(int hp);                  //更新生命值
    void updateLevelAndExpTest();           //测试函数，用于修改属性检测数据库是否同步变动

protected:
    QString type;       //种类
    QString name;       //名字
    int level;          //等级
    int exp;            //经验值
    int atk;            //攻击值
    int def;            //防御值
    int maxHp;          //最大生命值
    int hp;             //当前生命值
    int spd;            //攻速
    QString skill;      //技能
};


#endif // POKEMON_H
