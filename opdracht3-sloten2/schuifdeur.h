#ifndef SCHUIFDEUR_H
#define SCHUIFDEUR_H

#include "deur.h"
#include "slot.h"

class Sensor;
class Schuifdeur: public Deur
{
public:
    Schuifdeur(int, int, unsigned int, Sensor*);
    Schuifdeur(int, int, unsigned int, Sensor*, Slot*);
    virtual void teken(QPaintDevice*) override;
    virtual void open() override;
    virtual void sluit() override;

private:
    Sensor* sensor;
};

#endif // SCHUIFDEUR_H
