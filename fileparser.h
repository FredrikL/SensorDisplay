#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QString>
#include <QHash>
#include <QVector>
#include "sensorvalue.h"

class FileParser
{
public:
    FileParser(QString fileName) : fName(fileName) {}
    QHash<QString, QVector<SensorValue>> parse();

private:
    QString fName;
    bool recValue;
    QString key;
};

#endif // FILEPARSER_H
