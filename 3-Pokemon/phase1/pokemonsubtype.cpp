#include"pokemonsubtype.h"

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
    skill=SKILL[1];
}

talonflame::talonflame()
{
    type="talonflame";
    level=1;
    exp=0;
    skill=SKILL[2];
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
    skill=SKILL[3];
}

sentret::sentret()
{
    type="sentret";
    level=1;
    exp=0;
    skill=SKILL[4];
}

psyduck::psyduck()
{
    type="psyduck";
    level=1;
    exp=0;
    skill=SKILL[5];
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
    skill=SKILL[6];
}

gyarados::gyarados()
{
    type="gyarados";
    level=1;
    exp=0;
    skill=SKILL[7];
}

suicune::suicune()
{
    type="suicune";
    level=1;
    exp=0;
    skill=SKILL[8];
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
    skill=SKILL[9];
}

jigglypuff::jigglypuff()
{
    type="jigglypuff";
    level=1;
    exp=0;
    skill=SKILL[10];
}

pachirisu::pachirisu()
{
    type="pachirisu";
    level=1;
    exp=0;
    skill=SKILL[11];
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


//12个子类重写的攻击函数，目前函数功能只实现返回技能名，后续改进


QString charmander::attack()
{
    return skill;
}

QString charizard::attack()
{
    return skill;
}

QString talonflame::attack()
{
    return skill;
}

QString bulbasaur::attack()
{
    return skill;
}

QString sentret::attack()
{
    return skill;
}

QString psyduck::attack()
{
    return skill;
}

QString squirtle::attack()
{
    return skill;
}

QString gyarados::attack()
{
    return skill;
}

QString suicune::attack()
{
    return skill;
}

QString pikachu::attack()
{
    return skill;
}

QString jigglypuff::attack()
{
    return skill;
}

QString pachirisu::attack()
{
    return skill;
}
