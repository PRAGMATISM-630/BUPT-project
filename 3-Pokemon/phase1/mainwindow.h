#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "pokemon.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    void getPokemon();      //获取宝可梦
    
    void updateHp(uint hp,uint maxHp);      //更新生命值
    
    void updateLevelAndExp(uint level, uint exp);       //更新等级经验值

    void updateAttributeValue(uint atk,uint maxHp,uint def,uint spd);   //更新属性值

private slots:
    void on_attackBtn_clicked();        //攻击测试
    
    void on_takeDamageBtn_clicked();    //承受伤害测试
    
    void on_gainExpBtn_clicked();       //获得经验测试

    void on_clear_clicked();            //清空状态栏

    void on_getPokemonBtn_clicked();    //获取/更换宝可梦测试

    void on_resetEnemy_clicked();       //重置敌人生命值

private:
    Ui::MainWindow *ui;
    
    pokemon* myPokemon;
};

#endif // MAINWINDOW_H
