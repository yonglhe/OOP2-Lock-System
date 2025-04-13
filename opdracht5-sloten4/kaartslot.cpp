#include "kaartslot.h"
#include "slotexception.h"

std::multimap<std::string, Idkaart*> Kaartslot::idkaarten = {};

Kaartslot::Kaartslot(std::string p): plaats(p)
{
    vergrendeld = false;
}

void Kaartslot::vergrendel()
{
    vergrendeld = true;
}

void Kaartslot::ontgrendel(std::string eenSleutel)
{
    auto zoekSleutel = idkaarten.find(eenSleutel);
    if (zoekSleutel != idkaarten.end()){
        if (zoekSleutel->second->heeftToegangTot(this)){
            vergrendeld = false;
        } else
            std::cout<< "Id-kaart heeft geen toegang!"<<std::endl;
    } else {
        throw Slotexception(this->plaats, eenSleutel);
    }
}

void Kaartslot::voegIdKaartToe(Idkaart* eenIdKaart)
{
    // std::pair<std::string, Idkaart*>idkaart;
    // idkaart.first = eenIdKaart->userId()+ dePlaats();
    // idkaart.second = eenIdKaart;
    // idkaarten.insert(idkaart);
    idkaarten.insert({eenIdKaart->userId(), eenIdKaart});
    std::cout<<"Grootte van idkaarten-map: "<<idkaarten.size()<<std::endl;
}

void Kaartslot::verwijderIdKaart(std::string id)
{
    auto zoek(idkaarten.find(id));
    if (zoek != idkaarten.end()){
        idkaarten.erase(id);
    }
}

bool Kaartslot::isVergrendeld() const
{
    return vergrendeld;
}

std::string Kaartslot::dePlaats() const
{
    return plaats;
}

int Kaartslot::deMapGrootte() const
{
    return idkaarten.size();
}

std::multimap<std::string, Idkaart*> Kaartslot::getIdKaartenMap() const{
    return idkaarten;
}
