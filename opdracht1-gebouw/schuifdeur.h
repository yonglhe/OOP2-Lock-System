#ifndef SCHUIFDEUR_H
#define SCHUIFDEUR_H


#include "deur.h"

class Sensor;
class Schuifdeur: public Deur
{
public:
    Schuifdeur(int, int, unsigned int, Sensor*);
    virtual void teken(QPaintDevice*) override;
    virtual void open() override;
    virtual void sluit() override;

private:
    Sensor* sensor;
};

#endif // SCHUIFDEUR_H
