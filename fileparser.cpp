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
        if(line.startsWith(" ;Start Stop;")){
            auto values = parseRun(&in);
            qDebug() << "count " << values.size() << ", first itm: " << values[0].getDate();
        }
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
        qDebug() << line;
        if(line.startsWith(" ;Start Stop;")){
            break;
        } else if(!line.startsWith(" ")){
            auto value = handleLine(&line);
            qDebug() << value.getDate();
            r.push_back(value);
        }

        line = in->readLine();
    }

    return r;
}

SensorValue& FileParser::handleLine(QString *line) {
    QStringList parts = line->split(";");
    QString d = "";
    d.append(parts.value(0));
    SensorValue v(d,
                  parts.value(3).toInt(),
                  parts.value(4).toInt(),
                  parts.value(5).toInt(),
                  parts.value(6).toInt(),
                  parts.value(7).toInt(),
                  parts.value(8).toInt());

    qDebug()  << v.getDate();

    return v;
}
