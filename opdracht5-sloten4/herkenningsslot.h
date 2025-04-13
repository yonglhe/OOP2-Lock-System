#ifndef HERKENNINGSSLOT_H
#define HERKENNINGSSLOT_H

#include "slot.h"
#include "afdrukker.h"
#include <map>

class Herkenningsslot: public Slot
{
public:
    Herkenningsslot(Afdrukker*);
    void vergrendel();
    void ontgrendel(std::string);
    bool isVergrendeld() const;
    void toonKaartenbak();
    void voegAutorisatieToe(std::string, bool);
    std::map<std::string, bool> getKaartenbak();

private:
    bool vergrendeld;
    std::map<std::string, bool> kaartenbak;
    Afdrukker* afdruk;
};

#endif // HERKENNINGSSLOT_H
