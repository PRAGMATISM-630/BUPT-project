#include"pokemonsubtype.h"

/////////////////////////////
//
//  filename: pokemonsubtype.cpp
//  function: 宝可梦子类（四种类型）和子类的子类（十二种名字）的方法
//
/////////////////////////////

//4类，12子类，共16个构造函数
highAtk::highAtk()
{
    type="highAtk";
    level=1;
    exp=0;
}

charmander::charmander()
{
    type="charmander";
    level=1;
    exp=0;
    skill=SKILL[0];
}

charizard::charizard()
{
    type="charizard";
    level=1;
    exp=0;
    skill=SKILL[0];
}

talonflame::talonflame()
{
    type="talonflame";
    level=1;
    exp=0;
    skill=SKILL[0];
}

highHp::highHp()
{
    type="highHp";
    level=1;
    exp=0;
}

bulbasaur::bulbasaur()
{
    type="bulbasaur";
    level=1;
    exp=0;
    skill=SKILL[1];
}

sentret::sentret()
{
    type="sentret";
    level=1;
    exp=0;
    skill=SKILL[1];
}

psyduck::psyduck()
{
    type="psyduck";
    level=1;
    exp=0;
    skill=SKILL[1];
}

highDef::highDef()
{
    type="highDef";
    level=1;
    exp=0;
}

squirtle::squirtle()
{
    type="squirtle";
    level=1;
    exp=0;
    skill=SKILL[2];
}

gyarados::gyarados()
{
    type="gyarados";
    level=1;
    exp=0;
    skill=SKILL[2];
}

suicune::suicune()
{
    type="suicune";
    level=1;
    exp=0;
    skill=SKILL[2];
}

highSpd::highSpd()
{
    type="highSpd";
    level=1;
    exp=0;
}

pikachu::pikachu()
{
    type="pikachu";
    level=1;
    exp=0;
    skill=SKILL[3];
}

jigglypuff::jigglypuff()
{
    type="jigglypuff";
    level=1;
    exp=0;
    skill=SKILL[3];
}

pachirisu::pachirisu()
{
    type="pachirisu";
    level=1;
    exp=0;
    skill=SKILL[3];
}


//4类，12子类，共16个析构函数
highAtk::~highAtk(){}
charmander::~charmander(){}
charizard::~charizard(){}
talonflame::~talonflame(){}

highHp::~highHp(){}
bulbasaur::~bulbasaur(){}
sentret::~sentret(){}
psyduck::~psyduck(){}

highDef::~highDef(){}
squirtle::~squirtle(){}
gyarados::~gyarados(){}
suicune::~suicune(){}

highSpd::~highSpd(){}
pikachu::~pikachu(){}
jigglypuff::~jigglypuff(){}
pachirisu::~pachirisu(){}


//12个子类重写的攻击方法

int charmander::attack(bool &critical) const
{
    int atk=this->getAtk();     //面板攻击值
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    double criticalProbability=0.2;     //暴击概率0.2
    double criticalRatio=1.5;       //暴击伤害倍率1.5
    double n=QRandomGenerator::global()->bounded(0,10);         //n是0~9之间的随机数
    int realAtk=0;      //最终真实攻击
    if(n<int(criticalProbability*10))   //n为0或1时为真，对应20%概率触发暴击
    {
        realAtk=atk*ratio*criticalRatio;
        qDebug()<<"暴击！";
        //......
        critical=true;
    }
    else
    {
        realAtk=atk*ratio;         //真实攻击值在面板攻击上下10%浮动
        critical=false;
    }

    return realAtk;
}

int charizard::attack(bool &critical) const
{
    int atk=this->getAtk();     //面板攻击值
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    double criticalProbability=0.2;     //暴击概率0.2
    double criticalRatio=1.5;       //暴击伤害倍率1.5
    double n=QRandomGenerator::global()->bounded(0,10);         //n是0~9之间的随机数
    int realAtk=0;      //最终真实攻击
    if(n<int(criticalProbability*10))   //n为0或1时为真，对应20%概率触发暴击
    {
        realAtk=atk*ratio*criticalRatio;
        qDebug()<<"暴击！";
        //......
        critical=true;
    }
    else
    {
        realAtk=atk*ratio;         //真实攻击值在面板攻击上下10%浮动
        critical=false;
    }

    return realAtk;
}

int talonflame::attack(bool &critical) const
{
    int atk=this->getAtk();     //面板攻击值
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    double criticalProbability=0.2;     //暴击概率0.2
    double criticalRatio=1.5;       //暴击伤害倍率1.5
    double n=QRandomGenerator::global()->bounded(0,10);         //n是0~9之间的随机数
    int realAtk=0;      //最终真实攻击
    if(n<int(criticalProbability*10))   //n为0或1时为真，对应20%概率触发暴击
    {
        realAtk=atk*ratio*criticalRatio;
        qDebug()<<"暴击！";
        //......
        critical=true;
    }
    else
    {
        realAtk=atk*ratio;         //真实攻击值在面板攻击上下10%浮动
        critical=false;
    }

    return realAtk;
}

int bulbasaur::attack(bool &critical) const
{
    int atk=this->getAtk();     //面板攻击值
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    double criticalProbability=0.2;     //暴击概率0.2
    double criticalRatio=1.5;       //暴击伤害倍率1.5
    double n=QRandomGenerator::global()->bounded(0,10);         //n是0~9之间的随机数
    int realAtk=0;      //最终真实攻击
    if(n<int(criticalProbability*10))   //n为0或1时为真，对应20%概率触发暴击
    {
        realAtk=atk*ratio*criticalRatio;
        qDebug()<<"暴击！";
        //......
        critical=true;
    }
    else
    {
        realAtk=atk*ratio;         //真实攻击值在面板攻击上下10%浮动
        critical=false;
    }
    return realAtk;
}

int sentret::attack(bool &critical) const
{
    int atk=this->getAtk();     //面板攻击值
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    double criticalProbability=0.2;     //暴击概率0.2
    double criticalRatio=1.5;       //暴击伤害倍率1.5
    double n=QRandomGenerator::global()->bounded(0,10);         //n是0~9之间的随机数
    int realAtk=0;      //最终真实攻击
    if(n<int(criticalProbability*10))   //n为0或1时为真，对应20%概率触发暴击
    {
        realAtk=atk*ratio*criticalRatio;
        qDebug()<<"暴击！";
        //......
        critical=true;
    }
    else
    {
        realAtk=atk*ratio;         //真实攻击值在面板攻击上下10%浮动
        critical=false;
    }

    return realAtk;
}

int psyduck::attack(bool &critical) const
{
    int atk=this->getAtk();     //面板攻击值
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    double criticalProbability=0.2;     //暴击概率0.2
    double criticalRatio=1.5;       //暴击伤害倍率1.5
    double n=QRandomGenerator::global()->bounded(0,10);         //n是0~9之间的随机数
    int realAtk=0;      //最终真实攻击
    if(n<int(criticalProbability*10))   //n为0或1时为真，对应20%概率触发暴击
    {
        realAtk=atk*ratio*criticalRatio;
        qDebug()<<"暴击！";
        //......
        critical=true;
    }
    else
    {
        realAtk=atk*ratio;         //真实攻击值在面板攻击上下10%浮动
        critical=false;
    }

    return realAtk;
}

int squirtle::attack(bool &critical) const
{
    int atk=this->getAtk();     //面板攻击值
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    double criticalProbability=0.2;     //暴击概率0.2
    double criticalRatio=1.5;       //暴击伤害倍率1.5
    double n=QRandomGenerator::global()->bounded(0,10);         //n是0~9之间的随机数
    int realAtk=0;      //最终真实攻击
    if(n<int(criticalProbability*10))   //n为0或1时为真，对应20%概率触发暴击
    {
        realAtk=atk*ratio*criticalRatio;
        qDebug()<<"暴击！";
        //......
        critical=true;
    }
    else
    {
        realAtk=atk*ratio;         //真实攻击值在面板攻击上下10%浮动
        critical=false;
    }
    return realAtk;
}

int gyarados::attack(bool &critical) const
{
    int atk=this->getAtk();     //面板攻击值
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    double criticalProbability=0.2;     //暴击概率0.2
    double criticalRatio=1.5;       //暴击伤害倍率1.5
    double n=QRandomGenerator::global()->bounded(0,10);         //n是0~9之间的随机数
    int realAtk=0;      //最终真实攻击
    if(n<int(criticalProbability*10))   //n为0或1时为真，对应20%概率触发暴击
    {
        realAtk=atk*ratio*criticalRatio;
        qDebug()<<"暴击！";
        //......
        critical=true;
    }
    else
    {
        realAtk=atk*ratio;         //真实攻击值在面板攻击上下10%浮动
        critical=false;
    }

    return realAtk;
}

int suicune::attack(bool &critical) const
{
    int atk=this->getAtk();     //面板攻击值
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    double criticalProbability=0.2;     //暴击概率0.2
    double criticalRatio=1.5;       //暴击伤害倍率1.5
    double n=QRandomGenerator::global()->bounded(0,10);         //n是0~9之间的随机数
    int realAtk=0;      //最终真实攻击
    if(n<int(criticalProbability*10))   //n为0或1时为真，对应20%概率触发暴击
    {
        realAtk=atk*ratio*criticalRatio;
        qDebug()<<"暴击！";
        //......
        critical=true;
    }
    else
    {
        realAtk=atk*ratio;         //真实攻击值在面板攻击上下10%浮动
        critical=false;
    }

    return realAtk;
}

int pikachu::attack(bool &critical) const
{
    int atk=this->getAtk();     //面板攻击值
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    double criticalProbability=0.2;     //暴击概率0.2
    double criticalRatio=1.5;       //暴击伤害倍率1.5
    double n=QRandomGenerator::global()->bounded(0,10);         //n是0~9之间的随机数
    int realAtk=0;      //最终真实攻击
    if(n<int(criticalProbability*10))   //n为0或1时为真，对应20%概率触发暴击
    {
        realAtk=atk*ratio*criticalRatio;
        qDebug()<<"暴击！";
        //......
        critical=true;
    }
    else
    {
        realAtk=atk*ratio;         //真实攻击值在面板攻击上下10%浮动
        critical=false;
    }

    return realAtk;
}

int jigglypuff::attack(bool &critical) const
{
    int atk=this->getAtk();     //面板攻击值
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    double criticalProbability=0.2;     //暴击概率0.2
    double criticalRatio=1.5;       //暴击伤害倍率1.5
    double n=QRandomGenerator::global()->bounded(0,10);         //n是0~9之间的随机数
    int realAtk=0;      //最终真实攻击
    if(n<int(criticalProbability*10))   //n为0或1时为真，对应20%概率触发暴击
    {
        realAtk=atk*ratio*criticalRatio;
        qDebug()<<"暴击！";
        //......
        critical=true;
    }
    else
    {
        realAtk=atk*ratio;         //真实攻击值在面板攻击上下10%浮动
        critical=false;
    }

    return realAtk;
}

int pachirisu::attack(bool &critical) const
{
    int atk=this->getAtk();     //面板攻击值
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    double criticalProbability=0.2;     //暴击概率0.2
    double criticalRatio=1.5;       //暴击伤害倍率1.5
    double n=QRandomGenerator::global()->bounded(0,10);         //n是0~9之间的随机数
    int realAtk=0;      //最终真实攻击
    if(n<int(criticalProbability*10))   //n为0或1时为真，对应20%概率触发暴击
    {
        realAtk=atk*ratio*criticalRatio;
        qDebug()<<"暴击！";
        //......
        critical=true;
    }
    else
    {
        realAtk=atk*ratio;         //真实攻击值在面板攻击上下10%浮动
        critical=false;
    }

    return realAtk;
}

//12个子类重写的使用技能方法
int charmander::useSkill(skillName &name) const  //愤怒：攻击力提高100%，且100%触发暴击(火系）
{
    int atk=this->getAtk();
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    int realAtk=atk*ratio*1.5*2;        //面板攻击*基础倍率*暴击倍率*技能倍率
    name=RAGE;
    qDebug()<<"技能：愤怒\n面板攻击:"<<atk;
    qDebug()<<"攻击倍率:"<<ratio;
    qDebug()<<"实际攻击:"<<realAtk;
    return realAtk; //最终攻击
}

int charizard::useSkill(skillName &name) const  //愤怒：攻击力提高100%，且100%触发暴击(火系）
{
    int atk=this->getAtk();
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    int realAtk=atk*ratio*1.5*2;        //面板攻击*基础倍率*暴击倍率*技能倍率
    name=RAGE;
    qDebug()<<"技能：愤怒\n面板攻击:"<<atk;
    qDebug()<<"攻击倍率:"<<ratio;
    qDebug()<<"实际攻击:"<<realAtk;
    return realAtk; //最终攻击
}

int talonflame::useSkill(skillName &name) const  //愤怒：攻击力提高100%，且100%触发暴击(火系）
{
    int atk=this->getAtk();
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    int realAtk=atk*ratio*1.5*2;        //面板攻击*基础倍率*暴击倍率*技能倍率
    name=RAGE;
    qDebug()<<"技能：愤怒\n面板攻击:"<<atk;
    qDebug()<<"攻击倍率:"<<ratio;
    qDebug()<<"实际攻击:"<<realAtk;
    return realAtk; //最终攻击
}

int bulbasaur::useSkill(skillName &name) const   //顽强：每损失3%最大生命，下次攻击造成的伤害提高10%（土系）
{
    int hp1=this->getMaxHp();   //最大生命
    int hp2=hp1-this->getHp();  //当前已损失生命
    int percentage=hp2*100/hp1; //损失生命所占百分比
    double skillRatio=int(percentage/3)*0.1+1;   //技能倍率

    int atk=this->getAtk();
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    int realAtk=atk*ratio*skillRatio;        //面板攻击*基础倍率*技能倍率

    qDebug()<<"技能：顽强\n损失生命比率："<<percentage;
    qDebug()<<"技能倍率："<<skillRatio;
    qDebug()<<"攻击倍率："<<ratio;


    double criticalProbability=0.2;     //暴击概率0.2
    double criticalRatio=1.5;       //暴击伤害倍率1.5
    double n=QRandomGenerator::global()->bounded(0,10);         //n是0~9之间的随机数
    if(n<int(criticalProbability*10))   //n为0或1时为真，对应20%概率触发暴击
    {
        realAtk*=criticalRatio;
        qDebug()<<"暴击！";
    }
    qDebug()<<"实际攻击:"<<realAtk;


    name=TENACITY;
    return realAtk;    //最终攻击
}

int sentret::useSkill(skillName &name) const   //顽强：每损失3%最大生命，下次攻击造成的伤害提高10%（土系）
{
    int hp1=this->getMaxHp();   //最大生命
    int hp2=hp1-this->getHp();  //当前已损失生命
    int percentage=hp2*100/hp1; //损失生命所占百分比
    double skillRatio=int(percentage/3)*0.1+1;   //技能倍率

    int atk=this->getAtk();
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    int realAtk=atk*ratio*skillRatio;        //面板攻击*基础倍率*技能倍率

    double criticalProbability=0.2;     //暴击概率0.2
    double criticalRatio=1.5;           //暴击伤害倍率1.5
    double n=QRandomGenerator::global()->bounded(0,10);         //n是0~9之间的随机数
    if(n<int(criticalProbability*10))   //n为0或1时为真，对应20%概率触发暴击
    {
        realAtk*=criticalRatio;
        qDebug()<<"暴击！";
    }

    name=TENACITY;
    return realAtk;    //最终攻击
}

int psyduck::useSkill(skillName &name) const   //顽强：每损失3%最大生命，下次攻击造成的伤害提高10%（土系）
{
    int hp1=this->getMaxHp();   //最大生命
    int hp2=hp1-this->getHp();  //当前已损失生命
    int percentage=hp2*100/hp1; //损失生命所占百分比
    double skillRatio=int(percentage/3)*0.1+1;   //技能倍率

    int atk=this->getAtk();
    double ratio=1+double(QRandomGenerator::global()->bounded(-10,11))/100;   //攻击比率为0.9~1.1
    int realAtk=atk*ratio*skillRatio;        //面板攻击*基础倍率*技能倍率

    qDebug()<<"技能：顽强\n损失生命比率："<<percentage;
    qDebug()<<"技能倍率："<<skillRatio;
    qDebug()<<"攻击倍率："<<ratio;


    double criticalProbability=0.2;     //暴击概率0.2
    double criticalRatio=1.5;       //暴击伤害倍率1.5
    double n=QRandomGenerator::global()->bounded(0,10);         //n是0~9之间的随机数
    if(n<int(criticalProbability*10))   //n为0或1时为真，对应20%概率触发暴击
    {
        realAtk*=criticalRatio;
        qDebug()<<"暴击！";
    }
    qDebug()<<"实际攻击:"<<realAtk;


    name=TENACITY;
    return realAtk;    //最终攻击
}

int squirtle::useSkill(skillName &name) const  //回复：回复已损失生命的30%（水系）
{
    int hp=this->getMaxHp()-this->getHp();      //已损失生命
    name=REFRESH;
    qDebug()<<"技能：回复\n回复生命："<<hp*3/10;
    return hp*3/10;    //己方将回复的生命值
}

int gyarados::useSkill(skillName &name) const  //回复：回复已损失生命的30%（水系）
{
    int hp=this->getMaxHp()-this->getHp();      //已损失生命
    name=REFRESH;
    qDebug()<<"技能：回复\n回复生命："<<hp*3/10;
    return hp*3/10;    //己方将回复的生命值
}

int suicune::useSkill(skillName &name) const  //回复：回复已损失生命的30%（水系）
{
    int hp=this->getMaxHp()-this->getHp();      //已损失生命
    name=REFRESH;
    qDebug()<<"技能：回复\n回复生命："<<hp*3/10;
    return hp*3/10;    //己方将回复的生命值
}

int pikachu::useSkill(skillName &name) const  //反弹：对敌方造成上次被攻击所受伤害250%的伤害 (电系)
{
    name=REBOUND;
    return -1;      //无效
}

int pachirisu::useSkill(skillName &name) const  //反弹：对敌方造成上次被攻击所受伤害250%的伤害 (电系)
{
    name=REBOUND;
    return -1;      //无效
}

int jigglypuff::useSkill(skillName &name) const  //反弹：对敌方造成上次被攻击所受伤害250%的伤害 (电系)
{
    name=REBOUND;
    return -1;      //无效
}
