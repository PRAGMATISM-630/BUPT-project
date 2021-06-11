#ifndef RULE_H
#define RULE_H

/////////////////////////////
//
//  filename: rule.h
//  function: 用户查看规则时启动新界面
//
/////////////////////////////

#include <QWidget>

namespace Ui {
class rule;
}

class rule : public QWidget
{
    Q_OBJECT

public:
    explicit rule(QWidget *parent = nullptr);
    ~rule();

private slots:
    void on_ack_clicked();  //确认

private:
    Ui::rule *ui;
};

#endif // RULE_H
