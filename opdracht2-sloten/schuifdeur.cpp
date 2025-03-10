#include "schuifdeur.h"
#include "sensor.h"

#include <QPaintDevice>
#include <QPainter>
#include <QPen>

Schuifdeur::Schuifdeur(int x, int y, unsigned int d, Sensor* s): Deur(x, y, d), sensor(s)
{
}

Schuifdeur::Schuifdeur(int x, int y, unsigned int d, Sensor* s, Slot* ss): Deur(x, y, d, ss), sensor(s)
{
}

void Schuifdeur::teken(QPaintDevice* tp)
{
    QPainter p(tp);
    p.setBrush(Qt::SolidPattern);
    p.setBrush(Qt::black);

    QPen pen(Qt::black, 4, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    p.setPen(pen);

    if(isDeurOpen()){
        p.drawLine(this->coordinaatX(), this->coordinaatY(), coordinaatX(), this->coordinaatY() + this->deurLengte());
    } else  {
        p.drawLine(this->coordinaatX(), this->coordinaatY(), this->coordinaatX(), this->coordinaatY() - this->deurLengte());
    }
}

void Schuifdeur::sluit()
{
    if(!sensor->isGeactiveerd()){
        this->setStatus(false);
        sensor->activeer();
    }
}

void Schuifdeur::open()
{
    if(sensor->isGeactiveerd()){
        this->setStatus(true);
        sensor->deactiveer();
    }
}
