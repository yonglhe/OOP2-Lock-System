#include "slotexception.h"

Slotexception::Slotexception(std::string p, std::string i): kaartId(i), slotPlaats(p)
{

}

std::string Slotexception::kaartVanBinnendringer() const
{
    return kaartId;
}
std::string Slotexception::plaatsVanHetSlot() const
{
    return slotPlaats;
}
