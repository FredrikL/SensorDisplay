#include <QString>
#include "sensorvalue.h"

SensorValue::SensorValue(const SensorValue &other){
    date = other.date;
    room = other.room;
    evaporator = other.evaporator;
    sensor1 = other.sensor1;
    sensor2 = other.sensor2;
    sensor3 = other.sensor3;
    sensor4 = other.sensor4;
}
