#ifndef HALLSENSOR_H
#define HALLSENSOR_H

#include "sensor.h"

class Hallsensor: public Sensor
{
public:
    Hallsensor(int, int);
    void teken(QPaintDevice*) override;
};

#endif // HALLSENSOR_H
