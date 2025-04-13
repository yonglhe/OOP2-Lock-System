#ifndef SLEUTELSLOT_H
#define SLEUTELSLOT_H

#include <slot.h>

class Sleutelslot: public Slot
{
public:
    Sleutelslot(std::string);
    void ontgrendel(std::string) ;
    void vergrendel();
    bool isVergrendeld() const;

private:
    std::string sleutel;
    bool vergrendeld;
};

#endif // SLEUTELSLOT_H
