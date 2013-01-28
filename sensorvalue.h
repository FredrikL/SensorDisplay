#ifndef SENSORVALUE_H
#define SENSORVALUE_H

#include <QString>

class SensorValue
{
public:
    SensorValue(QString d, int r, int e, int s1, int s2, int s3, int s4) : date(d), room(r), evaporator(e), sensor1(s1), sensor2(s2), sensor3(s3), sensor4(s4) {}

    SensorValue(const SensorValue&);

    QString getDate() {return this->date; }
    int getRoom() { return this->room;}
    int getEvaporator() { return this->evaporator; }
    int getSensor1() { return this->sensor1; }
    int getSensor2() { return this->sensor2; }
    int getSensor3() { return this->sensor3; }
    int getSensor4() { return this->sensor4; }

private:
    QString date;
    int room;
    int evaporator;
    int sensor1;
    int sensor2;
    int sensor3;
    int sensor4;
};

#endif // SENSORVALUE_H
