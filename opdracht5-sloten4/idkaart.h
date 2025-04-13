#ifndef IDKAART_H
#define IDKAART_H

#include <iostream>
#include <string>
#include <vector>

class Kaartslot;

class Idkaart
{
public:
    Idkaart(std::string, std::string, std::string);
    void geefToegang(Kaartslot*);
    void verwijdertoegang(Kaartslot*);
    bool heeftToegangTot(Kaartslot*);
    std::string userId() const;
    int deVectorGrootte() const;

private:
    std::string id;
    std::vector<Kaartslot*> toegang;
    std::string naamEigenaar;
    std::string adresEigenaar;
};

#endif // IDKAART_H
