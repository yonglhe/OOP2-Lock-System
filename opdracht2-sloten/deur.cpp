#include "deur.h"

#include <QPaintDevice>
#include <QPainter>
#include <QPen>

Deur::Deur(int x, int y, unsigned int d): x_coordinaat(x), y_coordinaat(y), lengte(d)
{
    status = true;
}

Deur::Deur(int x, int y, unsigned int d, Slot* s): x_coordinaat(x), y_coordinaat(y), lengte(d), slot(s)
{
    status = true;
}

Deur::~Deur()
{
}

void Deur::teken(QPaintDevice* tp){
    QPainter p(tp);
    p.drawLine(10,10,10,10);
}

void Deur::open()
{
    status = true;
}

void Deur::sluit()
{
    status = false;
}

void Deur::setStatus(bool s)
{
    status = s;
}

bool Deur::isDeurOpen() const
{
    return status;
}

unsigned int Deur::deurLengte() const
{
    return lengte;
}

int Deur::coordinaatX() const
{
    return x_coordinaat;
}

int Deur::coordinaatY() const
{
    return y_coordinaat;
}

Slot* Deur::getSlot() const
{
    return slot;
}
