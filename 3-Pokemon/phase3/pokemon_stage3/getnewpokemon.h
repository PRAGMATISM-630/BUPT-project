#ifndef GETNEWPOKEMON_H
#define GETNEWPOKEMON_H


/////////////////////////////
//
//  filename: getnewpokemon.h
//  function: 用户获得新宝可梦时启动新界面
//
/////////////////////////////

#include <QWidget>

namespace Ui {
class getNewPokemon;
}

class getNewPokemon : public QWidget
{
    Q_OBJECT

public:
    explicit getNewPokemon(QWidget *parent = nullptr);
    ~getNewPokemon();

private slots:
    void on_pushButton_clicked();       //确认

private:
    Ui::getNewPokemon *ui;
};

#endif // GETNEWPOKEMON_H
