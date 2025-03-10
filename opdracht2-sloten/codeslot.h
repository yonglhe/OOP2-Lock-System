#ifndef CODESLOT_H
#define CODESLOT_H

#include <slot.h>

class Codeslot: public Slot
{
public:
    Codeslot(int);
    void ontgrendel(std::string);
    void vergrendel();
    bool isVergrendeld();

private:
    int code;
    bool vergrendeld;
};

#endif // CODESLOT_H
