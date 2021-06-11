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


const QVector<QString> SKILL={        //技能名，这里粗糙命名一下，后续进行改进
    //以下技能名称与上述宝可梦名依次对应
    "火焰攻击_I型","火焰攻击_II型","火焰攻击_III型",
    "土块攻击_I型","土块攻击_II型","土块攻击_III型",
    "水弹攻击_I型","水弹攻击_II型","水弹攻击_III型",
    "闪电攻击_I型","闪电攻击_II型","闪电攻击_III型"
};


class pokemon : public QObject      //宝可梦类
{
    Q_OBJECT

public:
    pokemon();                      //构造函数
    ~pokemon();                     //析构函数

//    virtual QString attack()=0;     //攻击函数
//    int gainExp(uint Exp);          //获得经验函数
//    int takeDamage(uint dmg);       //承受伤害函数
//    bool judgeDeath();              //判断死亡

    uint getLevel(){return level;}  //获取等级信息
    uint getExp(){return exp;}      //获取经验值信息
    uint getAtk(){return atk;}      //获取攻击值
    uint getMaxHp(){return maxHp;}  //获取最大生命值
    uint getHp(){return hp;}        //获取生命值信息
    uint getDef(){return def;}      //获取防御值
    uint getSpd(){return spd;}      //获取攻速值
    QString getType(){return type;} //获取种类
    QString getName(){return name;} //获取名字

    void setAttributeValue(QString Type,QString Name,uint Atk,uint Def,uint MaxHp,int Hp,uint Spd);       //设置宝可梦属性值
    void setLevelAndExp(uint Level,uint Exp);       //设置等级和经验值
    void updateLevelAndExpTest();    //测试函数，用于修改属性检测数据库是否同步变动

protected:
    QString type;       //种类
    QString name;       //名字
    uint level;         //等级
    uint exp;           //经验值
    uint atk;           //攻击值
    uint def;           //防御值
    uint maxHp;         //最大生命值
    int hp;             //当前生命值
    uint spd;           //攻速
    QString skill;      //技能

};


#endif // POKEMON_H
