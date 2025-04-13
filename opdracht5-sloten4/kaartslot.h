#ifndef KAARTSLOT_H
#define KAARTSLOT_H

#include "slot.h"
#include "idkaart.h"


#include <map>

class Slotexception;
class Kaartslot: public Slot
{
public:
    Kaartslot(std::string);
    void vergrendel();
    void ontgrendel(std::string);
    void voegIdKaartToe(Idkaart*);
    void verwijderIdKaart(std::string);
    bool isVergrendeld() const;
    std::string dePlaats() const;
    int deMapGrootte() const;
    std::multimap<std::string, Idkaart*> getIdKaartenMap() const;


private:
    std::string plaats;
    bool vergrendeld;
    // static std::map<std::string, Idkaart*> idkaarten; // de string is de plaats
    static std::multimap<std::string, Idkaart*> idkaarten;
};

#endif // KAARTSLOT_H
