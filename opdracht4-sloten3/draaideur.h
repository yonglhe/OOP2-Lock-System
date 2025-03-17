#ifndef DRAAIDEUR_H
#define DRAAIDEUR_H

#include "deur.h"
#include "slot.h"

class Draaideur: public Deur
{
public:
    Draaideur(int, int, unsigned int, bool);
    Draaideur(int, int, unsigned int, bool, Slot*);
    virtual void teken(QPaintDevice*) override;
    virtual void open() override;
    virtual void sluit() override;
    virtual bool isLiggend() const;

private:
    bool liggend;
};

#endif // DRAAIDEUR_H
