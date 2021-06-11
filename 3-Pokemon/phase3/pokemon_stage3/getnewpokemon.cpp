#include "getnewpokemon.h"
#include "ui_getnewpokemon.h"


/////////////////////////////
//
//  filename: getnewpokemon.cpp
//  function: 获取新宝可梦时的提示界面
//
/////////////////////////////

extern QString pokemonName;     //宝可梦名
extern int success;             //标记胜利

getNewPokemon::getNewPokemon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::getNewPokemon)
{
    ui->setupUi(this);
    setWindowTitle("New Pokemon!");
    setFixedSize(800,600);

    //设置标题
    ui->label->setAlignment(Qt::AlignCenter);
    QFont font;
    font.setPointSize(25);
    font.setFamily("仿宋");
    font.setBold(true);
    ui->label->setFont(font);
    QPalette pa;
    pa.setColor(QPalette::WindowText,QColor(31,30,51));
    ui->label->setPalette(pa);

    if(success==0)
    {
        ui->label->setFont(QFont("仿宋",15));
        ui->label->setText("您失去了您的所有宝可梦，系统给您补充了一个");
    }

    //宝可梦贴图
    QString path="./resourse/"+pokemonName+".png";         //图片所在路径
    QImage image(path);
    QPixmap pixmap=QPixmap::fromImage(image.mirrored(true,false));
    ui->label_2->setPixmap(pixmap);
    ui->label_2->setScaledContents(true);

    //确认按钮
    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:15px;padding:2px 4px;");

    success=-1;         //置为初始值
}

getNewPokemon::~getNewPokemon()
{
    delete ui;
}

void getNewPokemon::on_pushButton_clicked()
{
    this->close();  //关闭
}
