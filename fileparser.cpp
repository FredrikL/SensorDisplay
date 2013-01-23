#include "fileparser.h"
#include <QString>
#include <QHash>
#include <QFile>
#include <QTextStream>
#include <QDebug>

QHash<QString, QString> FileParser::parse() {
    QHash<QString, QString> hash;

    QFile file(this->fName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return hash;
    int count = 0;
    QTextStream in(&file);
    QString line = in.readLine();
    while(!line.isNull()){
        line = in.readLine();
        count++;
    }

    qDebug() << count << " lines";
    return hash;
}
