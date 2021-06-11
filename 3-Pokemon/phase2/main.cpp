#include "client.h"
#include "Server.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client w;
    w.show();

    server s;

    return a.exec();
}
