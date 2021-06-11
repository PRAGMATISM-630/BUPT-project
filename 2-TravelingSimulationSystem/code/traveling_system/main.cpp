#include "gui.h"
#include <QApplication>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont f("Microsoft YaHei",10,60);
    a.setFont(f);
    GUI w;
    w.show();

    return a.exec();
}
