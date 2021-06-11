#include "client.h"
#include "ui_client.h"

/////////////////////////////
//
//  filename: changeUi.cpp
//  function: 切换界面函数
//
/////////////////////////////

void Client::changeUi(int n)const            //以隐藏和显示控件的方式来切换界面
{
    switch(n)
    {
    case 1:         //登录界面
        ui->ui1_label->setHidden(false);
        ui->ui1_label_2->setHidden(false);
        ui->ui1_signIn->setHidden(false);
        ui->ui1_signUp->setHidden(false);
        ui->ui1_password->setHidden(false);
        ui->ui1_userName->setHidden(false);
        ui->ui1_background->setHidden(false);
        ui->ui1_img1->setHidden(false);
        ui->ui1_img2->setHidden(false);
        ui->ui1_img3->setHidden(false);
        ui->ui1_img4->setHidden(false);
        ui->ui1_trademark->setHidden(false);

        ui->ui2_prize->setHidden(true);
        ui->ui2_myPokemon->setHidden(true);
        ui->ui2_allPlayers->setHidden(true);
        ui->ui2_saveAndQuit->setHidden(true);
        ui->ui2_returnSignIn->setHidden(true);
        ui->ui2_battle->setHidden(true);
        ui->ui4_returnMainUi->setHidden(true);
        ui->ui3_returnMainUi->setHidden(true);
        ui->ui5_battle->setHidden(true);
        ui->ui5_return->setHidden(true);
        ui->ui5_levelUp->setHidden(true);
        ui->ui5_rules->setHidden(true);
        ui->ui5_hint->setHidden(true);
        ui->ui6_HP->setHidden(true);
        ui->ui6_HP_2->setHidden(true);
        ui->ui6_ATK->setHidden(true);
        ui->ui6_ATK_2->setHidden(true);
        ui->ui6_DEF->setHidden(true);
        ui->ui6_DEF_2->setHidden(true);
        ui->ui6_SPD->setHidden(true);
        ui->ui6_SPD_2->setHidden(true);
        ui->ui6_rules->setHidden(true);
        ui->ui6_enemyPokemon->setHidden(true);
        ui->ui6_myPokemon->setHidden(true);
        ui->ui6_skill->setHidden(true);
        ui->ui6_normalAttack->setHidden(true);
        ui->ui6_turn->setHidden(true);
        ui->ui6_bullet->setHidden(true);
        ui->ui6_bullet_2->setHidden(true);
        ui->ui6_damage->setHidden(true);
        ui->ui6_mark->setHidden(true);
        ui->ui6_enemyTurn->setHidden(true);
        ui->ui6_returnMainUi->setHidden(true);
        ui->ui6_autobattle->setHidden(true);
        ui->ui6_myfire->setHidden(true);
        ui->ui6_enemyfire->setHidden(true);
        ui->ui7_exp->setHidden(true);
        ui->ui7_ack->setHidden(true);
        ui->ui7_prize->setHidden(true);
        ui->ui7_pokemon->setHidden(true);
        ui->ui7_winLose->setHidden(true);
        ui->ui8_win->setHidden(true);
        ui->ui8_lose->setHidden(true);
        ui->ui8_per->setHidden(true);
        ui->ui8_bronze1->setHidden(true);
        ui->ui8_bronze2->setHidden(true);
        ui->ui8_silver1->setHidden(true);
        ui->ui8_silver2->setHidden(true);
        ui->ui8_golden1->setHidden(true);
        ui->ui8_golden2->setHidden(true);
        ui->ui8_returnMainUi->setHidden(true);
        ui->ui8_normal->setHidden(true);
        ui->ui8_super->setHidden(true);
        break;

    case 2:         //主界面
        ui->ui1_img1->setHidden(true);
        ui->ui1_img2->setHidden(true);
        ui->ui1_img3->setHidden(true);
        ui->ui1_img4->setHidden(true);
        ui->ui1_trademark->setHidden(true);
        ui->ui1_label->setHidden(true);
        ui->ui1_label_2->setHidden(true);
        ui->ui1_signIn->setHidden(true);
        ui->ui1_signUp->setHidden(true);
        ui->ui1_password->setHidden(true);
        ui->ui1_userName->setHidden(true);
        ui->ui1_background->setHidden(true);
        ui->ui3_returnMainUi->setHidden(true);
        ui->ui4_returnMainUi->setHidden(true);
        ui->ui5_battle->setHidden(true);
        ui->ui5_return->setHidden(true);
        ui->ui5_levelUp->setHidden(true);
        ui->ui5_rules->setHidden(true);
        ui->ui5_hint->setHidden(true);
        ui->ui6_HP->setHidden(true);
        ui->ui6_HP_2->setHidden(true);
        ui->ui6_ATK->setHidden(true);
        ui->ui6_ATK_2->setHidden(true);
        ui->ui6_DEF->setHidden(true);
        ui->ui6_DEF_2->setHidden(true);
        ui->ui6_SPD->setHidden(true);
        ui->ui6_SPD_2->setHidden(true);
        ui->ui6_enemyPokemon->setHidden(true);
        ui->ui6_myPokemon->setHidden(true);
        ui->ui6_skill->setHidden(true);
        ui->ui6_rules->setHidden(true);
        ui->ui6_normalAttack->setHidden(true);
        ui->ui6_turn->setHidden(true);
        ui->ui6_bullet->setHidden(true);
        ui->ui6_bullet_2->setHidden(true);
        ui->ui6_damage->setHidden(true);
        ui->ui6_mark->setHidden(true);
        ui->ui6_enemyTurn->setHidden(true);
        ui->ui6_returnMainUi->setHidden(true);
        ui->ui6_autobattle->setHidden(true);
        ui->ui6_myfire->setHidden(true);
        ui->ui6_enemyfire->setHidden(true);
        ui->ui7_exp->setHidden(true);
        ui->ui7_ack->setHidden(true);
        ui->ui7_prize->setHidden(true);
        ui->ui7_pokemon->setHidden(true);
        ui->ui7_winLose->setHidden(true);
        ui->ui8_win->setHidden(true);
        ui->ui8_lose->setHidden(true);
        ui->ui8_per->setHidden(true);
        ui->ui8_bronze1->setHidden(true);
        ui->ui8_bronze2->setHidden(true);
        ui->ui8_silver1->setHidden(true);
        ui->ui8_silver2->setHidden(true);
        ui->ui8_golden1->setHidden(true);
        ui->ui8_golden2->setHidden(true);
        ui->ui8_returnMainUi->setHidden(true);
        ui->ui8_normal->setHidden(true);
        ui->ui8_super->setHidden(true);

        ui->ui2_myPokemon->setHidden(false);
        ui->ui2_allPlayers->setHidden(false);
        ui->ui2_saveAndQuit->setHidden(false);
        ui->ui2_returnSignIn->setHidden(false);
        ui->ui2_battle->setHidden(false);
        ui->ui2_prize->setHidden(false);
        break;

    case 3:         //用户列表展示界面
        ui->ui3_returnMainUi->setHidden(false);

        ui->ui1_img1->setHidden(true);
        ui->ui1_img2->setHidden(true);
        ui->ui1_img3->setHidden(true);
        ui->ui1_img4->setHidden(true);
        ui->ui1_trademark->setHidden(true);
        ui->ui1_label->setHidden(true);
        ui->ui1_label_2->setHidden(true);
        ui->ui1_signIn->setHidden(true);
        ui->ui1_signUp->setHidden(true);
        ui->ui1_password->setHidden(true);
        ui->ui1_userName->setHidden(true);
        ui->ui1_background->setHidden(true);
        ui->ui2_prize->setHidden(true);
        ui->ui2_myPokemon->setHidden(true);
        ui->ui2_allPlayers->setHidden(true);
        ui->ui2_saveAndQuit->setHidden(true);
        ui->ui2_returnSignIn->setHidden(true);
        ui->ui2_battle->setHidden(true);
        ui->ui4_returnMainUi->setHidden(true);
        ui->ui5_battle->setHidden(true);
        ui->ui5_return->setHidden(true);
        ui->ui5_levelUp->setHidden(true);
        ui->ui5_rules->setHidden(true);
        ui->ui5_hint->setHidden(true);
        ui->ui6_HP->setHidden(true);
        ui->ui6_HP_2->setHidden(true);
        ui->ui6_ATK->setHidden(true);
        ui->ui6_ATK_2->setHidden(true);
        ui->ui6_DEF->setHidden(true);
        ui->ui6_DEF_2->setHidden(true);
        ui->ui6_SPD->setHidden(true);
        ui->ui6_SPD_2->setHidden(true);
        ui->ui6_enemyPokemon->setHidden(true);
        ui->ui6_myPokemon->setHidden(true);
        ui->ui6_skill->setHidden(true);
        ui->ui6_normalAttack->setHidden(true);
        ui->ui6_turn->setHidden(true);
        ui->ui6_bullet->setHidden(true);
        ui->ui6_bullet_2->setHidden(true);
        ui->ui6_damage->setHidden(true);
        ui->ui6_mark->setHidden(true);
        ui->ui6_enemyTurn->setHidden(true);
        ui->ui6_returnMainUi->setHidden(true);
        ui->ui6_autobattle->setHidden(true);
        ui->ui6_myfire->setHidden(true);
        ui->ui6_enemyfire->setHidden(true);
        ui->ui6_rules->setHidden(true);
        ui->ui7_exp->setHidden(true);
        ui->ui7_ack->setHidden(true);
        ui->ui7_prize->setHidden(true);
        ui->ui7_pokemon->setHidden(true);
        ui->ui7_winLose->setHidden(true);
        ui->ui8_win->setHidden(true);
        ui->ui8_lose->setHidden(true);
        ui->ui8_per->setHidden(true);
        ui->ui8_bronze1->setHidden(true);
        ui->ui8_bronze2->setHidden(true);
        ui->ui8_silver1->setHidden(true);
        ui->ui8_silver2->setHidden(true);
        ui->ui8_golden1->setHidden(true);
        ui->ui8_golden2->setHidden(true);
        ui->ui8_returnMainUi->setHidden(true);
        ui->ui8_normal->setHidden(true);
        ui->ui8_super->setHidden(true);
        break;


    case 4:         //宝可梦展示界面
        ui->ui4_returnMainUi->setHidden(false);

        ui->ui1_img1->setHidden(true);
        ui->ui1_img2->setHidden(true);
        ui->ui1_img3->setHidden(true);
        ui->ui1_img4->setHidden(true);
        ui->ui1_trademark->setHidden(true);
        ui->ui1_label->setHidden(true);
        ui->ui1_label_2->setHidden(true);
        ui->ui1_signIn->setHidden(true);
        ui->ui1_signUp->setHidden(true);
        ui->ui1_password->setHidden(true);
        ui->ui1_userName->setHidden(true);
        ui->ui1_background->setHidden(true);
        ui->ui2_myPokemon->setHidden(true);
        ui->ui2_allPlayers->setHidden(true);
        ui->ui2_saveAndQuit->setHidden(true);
        ui->ui2_prize->setHidden(true);
        ui->ui2_returnSignIn->setHidden(true);
        ui->ui2_battle->setHidden(true);
        ui->ui3_returnMainUi->setHidden(true);
        ui->ui5_battle->setHidden(true);
        ui->ui5_return->setHidden(true);
        ui->ui5_levelUp->setHidden(true);
        ui->ui5_rules->setHidden(true);
        ui->ui5_hint->setHidden(true);
        ui->ui6_HP->setHidden(true);
        ui->ui6_HP_2->setHidden(true);
        ui->ui6_ATK->setHidden(true);
        ui->ui6_ATK_2->setHidden(true);
        ui->ui6_DEF->setHidden(true);
        ui->ui6_DEF_2->setHidden(true);
        ui->ui6_SPD->setHidden(true);
        ui->ui6_SPD_2->setHidden(true);
        ui->ui6_enemyPokemon->setHidden(true);
        ui->ui6_myPokemon->setHidden(true);
        ui->ui6_skill->setHidden(true);
        ui->ui6_normalAttack->setHidden(true);
        ui->ui6_turn->setHidden(true);
        ui->ui6_bullet->setHidden(true);
        ui->ui6_bullet_2->setHidden(true);
        ui->ui6_damage->setHidden(true);
        ui->ui6_mark->setHidden(true);
        ui->ui6_enemyTurn->setHidden(true);
        ui->ui6_returnMainUi->setHidden(true);
        ui->ui6_autobattle->setHidden(true);
        ui->ui6_myfire->setHidden(true);
        ui->ui6_enemyfire->setHidden(true);
        ui->ui6_rules->setHidden(true);
        ui->ui7_exp->setHidden(true);
        ui->ui7_ack->setHidden(true);
        ui->ui7_prize->setHidden(true);
        ui->ui7_pokemon->setHidden(true);
        ui->ui7_winLose->setHidden(true);
        ui->ui8_win->setHidden(true);
        ui->ui8_lose->setHidden(true);
        ui->ui8_per->setHidden(true);
        ui->ui8_bronze1->setHidden(true);
        ui->ui8_bronze2->setHidden(true);
        ui->ui8_silver1->setHidden(true);
        ui->ui8_silver2->setHidden(true);
        ui->ui8_golden1->setHidden(true);
        ui->ui8_golden2->setHidden(true);
        ui->ui8_returnMainUi->setHidden(true);
        ui->ui8_normal->setHidden(true);
        ui->ui8_super->setHidden(true);
        break;


    case 5:         //战斗选择界面

        ui->ui1_img1->setHidden(true);
        ui->ui1_img2->setHidden(true);
        ui->ui1_img3->setHidden(true);
        ui->ui1_img4->setHidden(true);
        ui->ui1_trademark->setHidden(true);
        ui->ui1_label->setHidden(true);
        ui->ui1_label_2->setHidden(true);
        ui->ui1_signIn->setHidden(true);
        ui->ui1_signUp->setHidden(true);
        ui->ui1_password->setHidden(true);
        ui->ui1_userName->setHidden(true);
        ui->ui1_background->setHidden(true);
        ui->ui2_myPokemon->setHidden(true);
        ui->ui2_allPlayers->setHidden(true);
        ui->ui2_saveAndQuit->setHidden(true);
        ui->ui2_prize->setHidden(true);
        ui->ui2_returnSignIn->setHidden(true);
        ui->ui2_battle->setHidden(true);
        ui->ui3_returnMainUi->setHidden(true);
        ui->ui4_returnMainUi->setHidden(true);
        ui->ui6_HP->setHidden(true);
        ui->ui6_HP_2->setHidden(true);
        ui->ui6_ATK->setHidden(true);
        ui->ui6_ATK_2->setHidden(true);
        ui->ui6_DEF->setHidden(true);
        ui->ui6_DEF_2->setHidden(true);
        ui->ui6_SPD->setHidden(true);
        ui->ui6_SPD_2->setHidden(true);
        ui->ui6_enemyPokemon->setHidden(true);
        ui->ui6_myPokemon->setHidden(true);
        ui->ui6_skill->setHidden(true);
        ui->ui6_normalAttack->setHidden(true);
        ui->ui6_turn->setHidden(true);
        ui->ui6_bullet->setHidden(true);
        ui->ui6_bullet_2->setHidden(true);
        ui->ui6_damage->setHidden(true);
        ui->ui6_mark->setHidden(true);
        ui->ui6_enemyTurn->setHidden(true);
        ui->ui6_returnMainUi->setHidden(true);
        ui->ui6_autobattle->setHidden(true);
        ui->ui6_myfire->setHidden(true);
        ui->ui6_enemyfire->setHidden(true);
        ui->ui6_rules->setHidden(true);
        ui->ui7_exp->setHidden(true);
        ui->ui7_ack->setHidden(true);
        ui->ui7_prize->setHidden(true);
        ui->ui7_pokemon->setHidden(true);
        ui->ui7_winLose->setHidden(true);
        ui->ui8_win->setHidden(true);
        ui->ui8_lose->setHidden(true);
        ui->ui8_per->setHidden(true);
        ui->ui8_bronze1->setHidden(true);
        ui->ui8_bronze2->setHidden(true);
        ui->ui8_silver1->setHidden(true);
        ui->ui8_silver2->setHidden(true);
        ui->ui8_golden1->setHidden(true);
        ui->ui8_golden2->setHidden(true);
        ui->ui8_returnMainUi->setHidden(true);
        ui->ui8_normal->setHidden(true);
        ui->ui8_super->setHidden(true);

        ui->ui5_battle->setHidden(false);
        ui->ui5_return->setHidden(false);
        ui->ui5_levelUp->setHidden(false);
        ui->ui5_hint->setHidden(true);
        ui->ui5_rules->setHidden(false);
        break;

    case 6:         //战斗界面
        ui->ui1_img1->setHidden(true);
        ui->ui1_img2->setHidden(true);
        ui->ui1_img3->setHidden(true);
        ui->ui1_img4->setHidden(true);
        ui->ui1_trademark->setHidden(true);
        ui->ui6_HP->setHidden(false);
        ui->ui6_HP_2->setHidden(false);
        ui->ui6_ATK->setHidden(false);
        ui->ui6_ATK_2->setHidden(false);
        ui->ui6_DEF->setHidden(false);
        ui->ui6_DEF_2->setHidden(false);
        ui->ui6_SPD->setHidden(false);
        ui->ui6_SPD_2->setHidden(false);
        ui->ui6_enemyPokemon->setHidden(false);
        ui->ui6_rules->setHidden(false);
        ui->ui6_myPokemon->setHidden(false);
        ui->ui6_skill->setHidden(false);
        ui->ui6_normalAttack->setHidden(false);
        ui->ui6_turn->setHidden(false);
        ui->ui6_enemyTurn->setHidden(true);
        ui->ui6_returnMainUi->setHidden(false);
        ui->ui6_bullet->setHidden(true);
        ui->ui6_bullet_2->setHidden(true);
        ui->ui6_damage->setHidden(true);
        ui->ui6_mark->setHidden(true);
        ui->ui6_autobattle->setHidden(false);
        ui->ui6_myfire->setHidden(true);
        ui->ui6_enemyfire->setHidden(true);
        ui->ui8_win->setHidden(true);
        ui->ui8_lose->setHidden(true);
        ui->ui8_per->setHidden(true);
        ui->ui8_bronze1->setHidden(true);
        ui->ui8_bronze2->setHidden(true);
        ui->ui8_silver1->setHidden(true);
        ui->ui8_silver2->setHidden(true);
        ui->ui8_golden1->setHidden(true);
        ui->ui8_golden2->setHidden(true);
        ui->ui8_returnMainUi->setHidden(true);
        ui->ui8_normal->setHidden(true);
        ui->ui8_super->setHidden(true);


        ui->ui1_label->setHidden(true);
        ui->ui1_label_2->setHidden(true);
        ui->ui1_signIn->setHidden(true);
        ui->ui1_signUp->setHidden(true);
        ui->ui1_password->setHidden(true);
        ui->ui1_userName->setHidden(true);
        ui->ui1_background->setHidden(true);
        ui->ui2_myPokemon->setHidden(true);
        ui->ui2_prize->setHidden(true);
        ui->ui2_allPlayers->setHidden(true);
        ui->ui2_saveAndQuit->setHidden(true);
        ui->ui2_returnSignIn->setHidden(true);
        ui->ui2_battle->setHidden(true);
        ui->ui3_returnMainUi->setHidden(true);
        ui->ui4_returnMainUi->setHidden(true);
        ui->ui5_battle->setHidden(true);
        ui->ui5_return->setHidden(true);
        ui->ui5_levelUp->setHidden(true);
        ui->ui5_rules->setHidden(true);
        ui->ui5_hint->setHidden(true);
        ui->ui7_exp->setHidden(true);
        ui->ui7_ack->setHidden(true);
        ui->ui7_prize->setHidden(true);
        ui->ui7_pokemon->setHidden(true);
        ui->ui7_winLose->setHidden(true);
        break;

    case 7:         //战斗结算界面
        ui->ui7_exp->setHidden(false);
        ui->ui7_ack->setHidden(false);
        //ui->ui7_prize->setHidden(false);
        ui->ui7_pokemon->setHidden(false);
        ui->ui7_winLose->setHidden(false);

        ui->ui1_img1->setHidden(true);
        ui->ui1_img2->setHidden(true);
        ui->ui1_img3->setHidden(true);
        ui->ui1_img4->setHidden(true);
        ui->ui1_trademark->setHidden(true);
        ui->ui1_label->setHidden(true);
        ui->ui1_label_2->setHidden(true);
        ui->ui1_signIn->setHidden(true);
        ui->ui1_signUp->setHidden(true);
        ui->ui1_password->setHidden(true);
        ui->ui1_userName->setHidden(true);
        ui->ui1_background->setHidden(true);
        ui->ui2_myPokemon->setHidden(true);
        ui->ui2_allPlayers->setHidden(true);
        ui->ui2_saveAndQuit->setHidden(true);
        ui->ui2_prize->setHidden(true);
        ui->ui2_returnSignIn->setHidden(true);
        ui->ui2_battle->setHidden(true);
        ui->ui3_returnMainUi->setHidden(true);
        ui->ui4_returnMainUi->setHidden(true);
        ui->ui5_battle->setHidden(true);
        ui->ui5_return->setHidden(true);
        ui->ui5_levelUp->setHidden(true);
        ui->ui5_hint->setHidden(true);
        ui->ui5_rules->setHidden(true);
        ui->ui6_HP->setHidden(true);
        ui->ui6_HP_2->setHidden(true);
        ui->ui6_ATK->setHidden(true);
        ui->ui6_ATK_2->setHidden(true);
        ui->ui6_DEF->setHidden(true);
        ui->ui6_DEF_2->setHidden(true);
        ui->ui6_SPD->setHidden(true);
        ui->ui6_SPD_2->setHidden(true);
        ui->ui6_enemyPokemon->setHidden(true);
        ui->ui6_myPokemon->setHidden(true);
        ui->ui6_skill->setHidden(true);
        ui->ui6_normalAttack->setHidden(true);
        ui->ui6_autobattle->setHidden(true);
        ui->ui6_turn->setHidden(true);
        ui->ui6_rules->setHidden(true);
        ui->ui6_bullet->setHidden(true);
        ui->ui6_bullet_2->setHidden(true);
        ui->ui6_damage->setHidden(true);
        ui->ui6_mark->setHidden(true);
        ui->ui6_enemyTurn->setHidden(true);
        ui->ui6_returnMainUi->setHidden(true);
        ui->ui6_myfire->setHidden(true);
        ui->ui6_enemyfire->setHidden(true);
        ui->ui8_win->setHidden(true);
        ui->ui8_lose->setHidden(true);
        ui->ui8_per->setHidden(true);
        ui->ui8_bronze1->setHidden(true);
        ui->ui8_bronze2->setHidden(true);
        ui->ui8_silver1->setHidden(true);
        ui->ui8_silver2->setHidden(true);
        ui->ui8_golden1->setHidden(true);
        ui->ui8_golden2->setHidden(true);
        ui->ui8_returnMainUi->setHidden(true);
        ui->ui8_normal->setHidden(true);
        ui->ui8_super->setHidden(true);
        break;

    case 8:         //成就界面
        ui->ui8_win->setHidden(false);
        ui->ui8_lose->setHidden(false);
        ui->ui8_per->setHidden(false);
        ui->ui8_bronze1->setHidden(false);
        ui->ui8_bronze2->setHidden(false);
        ui->ui8_silver1->setHidden(false);
        ui->ui8_silver2->setHidden(false);
        ui->ui8_golden1->setHidden(false);
        ui->ui8_golden2->setHidden(false);
        ui->ui8_returnMainUi->setHidden(false);
        ui->ui8_normal->setHidden(false);
        ui->ui8_super->setHidden(false);
        ui->ui6_rules->setHidden(true);

        ui->ui1_img1->setHidden(true);
        ui->ui1_img2->setHidden(true);
        ui->ui1_img3->setHidden(true);
        ui->ui1_img4->setHidden(true);
        ui->ui1_trademark->setHidden(true);
        ui->ui1_label->setHidden(true);
        ui->ui1_label_2->setHidden(true);
        ui->ui1_signIn->setHidden(true);
        ui->ui1_signUp->setHidden(true);
        ui->ui1_password->setHidden(true);
        ui->ui1_userName->setHidden(true);
        ui->ui1_background->setHidden(true);
        ui->ui2_prize->setHidden(true);
        ui->ui2_myPokemon->setHidden(true);
        ui->ui2_allPlayers->setHidden(true);
        ui->ui2_saveAndQuit->setHidden(true);
        ui->ui2_returnSignIn->setHidden(true);
        ui->ui2_battle->setHidden(true);
        ui->ui4_returnMainUi->setHidden(true);
        ui->ui3_returnMainUi->setHidden(true);
        ui->ui5_battle->setHidden(true);
        ui->ui5_return->setHidden(true);
        ui->ui5_levelUp->setHidden(true);
        ui->ui5_hint->setHidden(true);
        ui->ui5_rules->setHidden(true);
        ui->ui6_HP->setHidden(true);
        ui->ui6_HP_2->setHidden(true);
        ui->ui6_ATK->setHidden(true);
        ui->ui6_ATK_2->setHidden(true);
        ui->ui6_DEF->setHidden(true);
        ui->ui6_DEF_2->setHidden(true);
        ui->ui6_SPD->setHidden(true);
        ui->ui6_SPD_2->setHidden(true);
        ui->ui6_enemyPokemon->setHidden(true);
        ui->ui6_myPokemon->setHidden(true);
        ui->ui6_skill->setHidden(true);
        ui->ui6_normalAttack->setHidden(true);
        ui->ui6_turn->setHidden(true);
        ui->ui6_bullet->setHidden(true);
        ui->ui6_bullet_2->setHidden(true);
        ui->ui6_damage->setHidden(true);
        ui->ui6_mark->setHidden(true);
        ui->ui6_enemyTurn->setHidden(true);
        ui->ui6_returnMainUi->setHidden(true);
        ui->ui6_autobattle->setHidden(true);
        ui->ui6_myfire->setHidden(true);
        ui->ui6_enemyfire->setHidden(true);
        ui->ui7_exp->setHidden(true);
        ui->ui7_ack->setHidden(true);
        ui->ui7_prize->setHidden(true);
        ui->ui7_pokemon->setHidden(true);
        ui->ui7_winLose->setHidden(true);
        break;
    default:
        break;
    }
}
