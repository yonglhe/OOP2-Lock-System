#include "hallsensor.h"

#include <QPaintDevice>
#include <QPainter>
#include <QPen>

Hallsensor::Hallsensor(int x, int y): Sensor(x, y)
{
    this->deactiveer();
}

void Hallsensor::teken(QPaintDevice* tp)
{
    QPainter p(tp);
    QColor kleur;
    p.setBrush(Qt::SolidPattern);
    if(this->isGeactiveerd())
        kleur=Qt::blue;
    else
        kleur=Qt::yellow;

    p.setBrush(kleur);
    QPen pen(kleur,2,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    p.setPen(pen);
    p.drawEllipse(this->coordinaatX(),this->coordinaatY(),20,20);
}
