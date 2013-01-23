#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QString>
#include <QHash>

class FileParser
{
public:
    FileParser(QString fileName) : fName(fileName) {};
    QHash<QString, QString> parse();

private:
    QString fName;
};

#endif // FILEPARSER_H
