#include "draaideur.h"

#include <QPaintDevice>
#include <QPainter>
#include <QPen>

Draaideur::Draaideur(int x, int y, unsigned int d, bool l): Deur(x, y, d), liggend(l)
{
}

Draaideur::Draaideur(int x, int y, unsigned int d, bool l, Slot* cs): Deur(x, y, d, cs), liggend(l)
{
}

void Draaideur::teken(QPaintDevice* tp)
{
    QPainter p(tp);
    p.setBrush(Qt::SolidPattern);
    p.setBrush(Qt::black);

    QPen pen(Qt::black, 4, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    p.setPen(pen);

    if(isLiggend()){
        if(isDeurOpen()){
            p.drawLine(this->coordinaatX(), this->coordinaatY(), this->coordinaatX() + this->deurLengte(), this->coordinaatY()); // close door for d1
        } else  {
            p.drawLine(this->coordinaatX(), this->coordinaatY(), this->coordinaatX(), this->coordinaatY() - this->deurLengte()); // open door for d1
        }
    } else {
        if(isDeurOpen()){
            p.drawLine(this->coordinaatX(), this->coordinaatY(), this->coordinaatX(), this->coordinaatY() - this->deurLengte()); // close door for d2
        } else  {
            p.drawLine(this->coordinaatX(), this->coordinaatY(), this->coordinaatX() - this->deurLengte(), this->coordinaatY()); // open door for d2
        }
    }
}

bool Draaideur::isLiggend() const
{
    return liggend;
}

void Draaideur::open()
{
    this->setStatus(true);
}

void Draaideur::sluit()
{
    this->setStatus(false);
}
