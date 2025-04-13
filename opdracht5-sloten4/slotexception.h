#ifndef SLOTEXCEPTION_H
#define SLOTEXCEPTION_H

#include <exception>
#include <string>


class Slotexception: public std::exception
{
public:
    Slotexception(std::string, std::string);
    std::string kaartVanBinnendringer() const;
    std::string plaatsVanHetSlot() const;

private:
    std::string kaartId;
    std::string slotPlaats;
};

#endif // SLOTEXCEPTION_H
