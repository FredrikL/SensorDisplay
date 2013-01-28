#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QString>
#include <QHash>
#include <QTextStream>
#include <vector>
#include "sensorvalue.h"

class FileParser
{
public:
    FileParser(QString fileName) : fName(fileName) {}
    QHash<QString, std::vector<SensorValue>> parse();

private:
    std::vector<SensorValue> parseRun(QTextStream*);
    SensorValue& handleLine(QString *) ;

    QString fName;
    bool recValue;
    QString currentKey;
};

#endif // FILEPARSER_H
