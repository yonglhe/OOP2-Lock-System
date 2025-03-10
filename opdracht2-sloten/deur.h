#ifndef DEUR_H
#define DEUR_H

#include "slot.h"

class QPaintDevice;
class Deur
{
public:
    Deur(int, int, unsigned int);
    Deur(int, int, unsigned int, Slot*);
    virtual ~Deur();

    virtual void teken(QPaintDevice*);
    virtual void open();
    virtual void sluit();
    virtual void setStatus(bool);

    virtual bool isDeurOpen() const;
    virtual unsigned int deurLengte() const;
    virtual int coordinaatX() const;
    virtual int coordinaatY() const;
    virtual Slot* getSlot() const;


private:
    bool status;
    int x_coordinaat, y_coordinaat;
    unsigned int lengte;
    Slot* slot;
};

#endif // DEUR_H
