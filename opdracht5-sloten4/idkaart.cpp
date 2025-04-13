#include "idkaart.h"

Idkaart::Idkaart(std::string i, std::string n, std::string a): id(i), naamEigenaar(n), adresEigenaar(a)
{

}

void Idkaart::geefToegang(Kaartslot* slot)
{
    toegang.push_back(slot);
    std::cout << "Slot met id: " << this->id << " heeft nu toegang." << std::endl;
}

void Idkaart::verwijdertoegang(Kaartslot* slot)
{
    for (auto i = toegang.begin(); i != toegang.end(); ) {
        if (*i == slot) {
            i = toegang.erase(i); // erase returns de volgende geldige iterator
        } else {
            ++i;    // alleen verhogen als er niet wordt geincrement
        }
    }
    std::cout << "Slot met id: " << this->id << " heeft geen toegang meer." << std::endl;
}


bool Idkaart::heeftToegangTot(Kaartslot* slot)
{
    for (auto i = toegang.begin(); i != toegang.end(); i++){
        if(*i == slot){
            return true;
        }
    }
    return false;
}

std::string Idkaart::userId() const
{
    return id;
}

int Idkaart::deVectorGrootte() const
{
    return toegang.size();
}
