#ifndef DRUKBOX_H
#define DRUKBOX_H

#include "afdrukker.h"
#include "QTextBrowser"

class Drukbox: public Afdrukker
{
public:
    Drukbox(QTextBrowser*);
    void toonText(std::string);
    void clearMedium();

private:
    QTextBrowser* textbox;
};

#endif // DRUKBOX_H
