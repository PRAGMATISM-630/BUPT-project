#include "rule.h"
#include "ui_rule.h"

/////////////////////////////
//
//  filename: rule.cpp
//  function: 查看规则时的新界面
//
/////////////////////////////

rule::rule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rule)
{
    //窗口固定大小
    setFixedSize(QSize(600,440));

    //设置窗口标题
    setWindowTitle(tr("rules"));

    //设置控件样式
    ui->setupUi(this);
    ui->rules->setFont(QFont("仿宋",15));
    ui->ack->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->rules->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
}

rule::~rule()
{
    delete ui;
}

void rule::on_ack_clicked()
{
    this->close();      //关闭界面
}
