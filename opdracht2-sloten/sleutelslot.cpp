#include "sleutelslot.h"
#include <iostream>

Sleutelslot::Sleutelslot(std::string s): sleutel(s)
{
    this->vergrendeld = false; // sleutel ontgrendeld bij aanmaken van een sleutelslot
}

void Sleutelslot::ontgrendel(std::string inputSleutelString)
{
    if (inputSleutelString != ""){
        if(inputSleutelString == sleutel)
            this->vergrendeld = false;
        else
            std::cout << "Fout: onjuist wachtwoord." << std::endl;
    } else
        std::cout << "Fout: geen wachtwoord." << std::endl;
    // extra toevoeging: een pop-up foutmelding
}

void Sleutelslot::vergrendel()
{
    this->vergrendeld = true;
}

bool Sleutelslot::isVergrendeld()
{
    return this->vergrendeld;
}
