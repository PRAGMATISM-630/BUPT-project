#ifndef POKEMONSUBTYPE_H
#define POKEMONSUBTYPE_H

/////////////////////////////
//
//  filename: pokemonsubtype.h
//  function: 该文件定义了宠物小精灵的高攻击类、高生命类、高防御类、高攻速类及它们的子类
//
/////////////////////////////

#include"pokemon.h"

class highAtk: public pokemon           //高攻击类
{
public:
    highAtk();
    ~highAtk();

    virtual int attack(bool &)const=0;
    virtual int useSkill(skillName &)const=0;
};


class charmander: public highAtk        //小火龙类
{
public:
    charmander();
    ~charmander();

    virtual int attack(bool &) const override;   //攻击
    virtual int useSkill(skillName &) const override;   //使用技能
};


class charizard: public highAtk        //喷火龙类
{
public:
    charizard();
    ~charizard();

    virtual int attack(bool &) const override;   //攻击
    virtual int useSkill(skillName &) const override;   //使用技能
};


class talonflame: public highAtk        //烈箭鹰类
{
public:
    talonflame();
    ~talonflame();

    virtual int attack(bool &) const override;   //攻击
    virtual int useSkill(skillName &) const override;   //使用技能
};



class highHp: public pokemon            //高生命类
{
public:
    highHp();
    ~highHp();

    virtual int attack(bool &)const=0;
    virtual int useSkill(skillName &)const=0;
};


class bulbasaur: public highHp          //妙蛙种子类
{
public:
    bulbasaur();
    ~bulbasaur();

    virtual int attack(bool &) const override;   //攻击
    virtual int useSkill(skillName &) const override;   //使用技能
};


class sentret: public highHp          //尾立类
{
public:
    sentret();
    ~sentret();

    virtual int attack(bool &) const override;   //攻击
    virtual int useSkill(skillName &) const override;   //使用技能
};

class psyduck: public highHp          //可达鸭类
{
public:
    psyduck();
    ~psyduck();

    virtual int attack(bool &) const override;   //攻击
    virtual int useSkill(skillName &) const override;   //使用技能
};



class highDef: public pokemon           //高防御类
{
public:
    highDef();
    ~highDef();

    virtual int attack(bool &)const=0;
    virtual int useSkill(skillName &)const=0;
};


class squirtle: public highDef          //杰尼龟类
{
public:
    squirtle();
    ~squirtle();

    virtual int attack(bool &) const override;   //攻击
    virtual int useSkill(skillName &) const override;   //使用技能
};


class gyarados: public highDef          //暴鲤龙类
{
public:
    gyarados();
    ~gyarados();

    virtual int attack(bool &) const override;   //攻击
    virtual int useSkill(skillName &) const override;   //使用技能
};


class suicune: public highDef          //水君类
{
public:
    suicune();
    ~suicune();

    virtual int attack(bool &) const override;   //攻击
    virtual int useSkill(skillName &) const override;   //使用技能
};



class highSpd: public pokemon           //高攻速类
{
public:
    highSpd();
    ~highSpd();

    virtual int attack(bool &)const=0;
    virtual int useSkill(skillName &)const=0;
};


class pikachu: public highSpd           //皮卡丘类
{
public:
   pikachu();
   ~pikachu();

   virtual int attack(bool &) const override;   //攻击
   virtual int useSkill(skillName &) const override;   //使用技能
};


class jigglypuff: public highSpd        //胖丁类
{
public:
   jigglypuff();
   ~jigglypuff();

   virtual int attack(bool &) const override;   //攻击
   virtual int useSkill(skillName &) const override;   //使用技能
};


class pachirisu: public highSpd         //帕奇利兹类
{
public:
   pachirisu();
   ~pachirisu();

   virtual int attack(bool &) const override;   //攻击
   virtual int useSkill(skillName &) const override;   //使用技能
};




#endif // POKEMONSUBTYPE_H


