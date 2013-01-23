#include "fileparser.h"
#include <QString>
#include <QHash>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <sensorvalue.h>

QHash<QString, QVector<SensorValue>> FileParser::parse() {
    QHash<QString, QVector<SensorValue>> hash;
    qDebug() << "file: " << this->fName;
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

