#include "herkenningsslot.h"
#include <iostream>
#include <sstream>

Herkenningsslot::Herkenningsslot(Afdrukker* a): afdruk(a) {
    vergrendeld = true;
}

void Herkenningsslot::vergrendel()
{
    vergrendeld = true;
}

void Herkenningsslot::ontgrendel(std::string inputNaam)
{
     // zoek de naam in de kaartenbak en controleer of hij/zij toegang heeft
    if(inputNaam != ""){
        auto zoek(kaartenbak.find(inputNaam));
        if (zoek != kaartenbak.end()){
            if (zoek->second == true)
                vergrendeld = false;
            else if (zoek->second == false)
                vergrendeld = true;
        }
    } else
        std::cout<<"Fout: geen input gevonden."<<std::endl;
}

bool Herkenningsslot::isVergrendeld() const
{
    return vergrendeld;
}

void Herkenningsslot::toonKaartenbak()
{
    std::stringstream output;
    std::map<std::string, bool>:: iterator i;
    for(i=kaartenbak.begin(); i!=kaartenbak.end(); i++){
        output << i->first <<" : "<< (i->second ? "toegang" : "geen toegang") << std::endl;
    }
    afdruk->toonText(output.str());
}

void Herkenningsslot::voegAutorisatieToe(std::string naam, bool toegang)
{
    std::pair<std::map<std::string, bool>::iterator, bool> controler;
    if (naam != "") {
        std::pair<std::string, bool> invoer;
        invoer.first = naam;
        invoer.second = toegang;
        controler = kaartenbak.insert(invoer);
        if (controler.first->second == true)
            std::cout << controler.first->first << " heeft toegang." << std::endl;
        else
            std::cout << controler.first->first << " heeft geen toegang." << std::endl;
    } else
        std::cout << "Voer een naam in!" << std::endl;
}

std::map<std::string, bool> Herkenningsslot::getKaartenbak()
{
    return kaartenbak;
}
