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

    virtual QString attack()=0;
};


class charmander: public highAtk        //小火龙类
{
public:
    charmander();
    ~charmander();

    virtual QString attack() override;
};


class charizard: public highAtk        //喷火龙类
{
public:
    charizard();
    ~charizard();

    virtual QString attack() override;
};


class talonflame: public highAtk        //烈箭鹰类
{
public:
    talonflame();
    ~talonflame();

    virtual QString attack() override;
};



class highHp: public pokemon            //高生命类
{
public:
    highHp();
    ~highHp();

    virtual QString attack()=0;
};


class bulbasaur: public highHp          //妙蛙种子类
{
public:
    bulbasaur();
    ~bulbasaur();

    virtual QString attack() override;
};


class sentret: public highHp          //尾立类
{
public:
    sentret();
    ~sentret();

    virtual QString attack() override;
};

class psyduck: public highHp          //可达鸭类
{
public:
    psyduck();
    ~psyduck();

    virtual QString attack() override;
};



class highDef: public pokemon           //高防御类
{
public:
    highDef();
    ~highDef();

    virtual QString attack()=0;
};


class squirtle: public highDef          //杰尼龟类
{
public:
    squirtle();
    ~squirtle();

    virtual QString attack() override;
};


class gyarados: public highDef          //暴鲤龙类
{
public:
    gyarados();
    ~gyarados();

    virtual QString attack() override;
};


class suicune: public highDef          //水君类
{
public:
    suicune();
    ~suicune();

    virtual QString attack() override;
};



class highSpd: public pokemon           //高攻速类
{
public:
    highSpd();
    ~highSpd();

    virtual QString attack()=0;
};


class pikachu: public highSpd           //皮卡丘类
{
public:
   pikachu();
   ~pikachu();

   virtual QString attack() override;
};


class jigglypuff: public highSpd        //胖丁类
{
public:
   jigglypuff();
   ~jigglypuff();

   virtual QString attack() override;
};


class pachirisu: public highSpd         //帕奇利兹类
{
public:
   pachirisu();
   ~pachirisu();

   virtual QString attack() override;
};




#endif // POKEMONSUBTYPE_H


