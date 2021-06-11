#include"log.h"

void Create_log(const QString &s)
{
    QFile file("log.txt");
    if(!(file.open(QIODevice::ReadWrite|QIODevice::Append)))
    {
        qDebug() << "Could not open the file 'log.txt'";
        return;
    }

    QTextStream out(&file);
    QDateTime current_data_time=QDateTime::currentDateTime();
    QString str=current_data_time.toString("yyyy.MM.dd hh:mm:ss\t");
    out<<(str+s+"\n");
}
