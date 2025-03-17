#include "codeslot.h"
#include <iostream>

Codeslot::Codeslot(int c): code(c)
{
    this->vergrendeld = false;
}

void Codeslot::ontgrendel(std::string inputCodeString)
{
    if (inputCodeString != ""){
        int inputCode = std::stoi(inputCodeString);
        if(inputCode == code)
            this->vergrendeld = false;
        else
            std::cout << "Fout: onjuiste code." << std::endl;
    } else
        std::cout << "Fout: geen code." << std::endl;
    // extra toevoeging: een pop-up foutmelding
}

void Codeslot::vergrendel()
{
    this->vergrendeld = true;
}

bool Codeslot::isVergrendeld() const
{
    return this->vergrendeld;
}
