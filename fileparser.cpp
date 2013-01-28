#include "fileparser.h"
#include <QString>
#include <QHash>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStringList>
#include <vector>
#include "sensorvalue.h"

QHash<QString, std::vector<SensorValue>> FileParser::parse() {
    QHash<QString, std::vector<SensorValue>> hash;
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

std::vector<SensorValue> FileParser::parseRun(QTextStream *in) {
    std::vector<SensorValue> r;

    QString line = in->readLine();
    while(!line.isNull()){
        if(line.startsWith(" ;Start Stop;")){
            break;
        } else {
            auto value = handleLine(&line);
            r.push_back(value);
        }

        line = in->readLine();
    }

    return r;
}

SensorValue& FileParser::handleLine(QString *line) {
    QStringList parts = line->split(";");

    SensorValue v(parts.value(0),
                  parts.value(3).toInt(),
                  parts.value(4).toInt(),
                  parts.value(5).toInt(),
                  parts.value(6).toInt(),
                  parts.value(7).toInt(),
                  parts.value(8).toInt());

    return v;
}
