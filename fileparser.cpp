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
    QFile file(this->fName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return hash;

    QTextStream in(&file);
    QString line = in.readLine();
    while(!line.isNull()){
        if(line.startsWith(" ;Start Stop;")){
            auto values = parseRun(&in);
            if(values.size() > 10){ // todo: size to break at ?
                hash.insert(values[0].getDate(), values);
            }
        }
        line = in.readLine();
    }

    return hash;
}

std::vector<SensorValue> FileParser::parseRun(QTextStream *in) {
    std::vector<SensorValue> r;

    QString line = in->readLine();
    while(!line.isNull()){
        if(line.startsWith(" ;Start Stop;")){
            break;
        } else if(!line.startsWith(" ")){
            auto value = handleLine(&line);
            r.push_back(value);
        }
        line = in->readLine();
    }

    return r;
}

SensorValue& FileParser::handleLine(QString *line) {
    QStringList parts = line->split(";");
    QStringList dt = parts.value(0).split(" ");
    QStringList date = dt.value(0).split("/");

    QString* d = new QString(date.value(2) + "-" + date.value(1) + "-" + date.value(0)+ " " + dt.value(2)); // memleak?

    SensorValue v(*d,
                  parts.value(3).toInt(),
                  parts.value(4).toInt(),
                  parts.value(5).toInt(),
                  parts.value(6).toInt(),
                  parts.value(7).toInt(),
                  parts.value(8).toInt());

    return v;
}
