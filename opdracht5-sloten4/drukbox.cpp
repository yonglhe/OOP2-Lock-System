#include "drukbox.h"

Drukbox::Drukbox(QTextBrowser* q): textbox(q)
{

}

void Drukbox::toonText(std::string text)
{
    textbox->append(QString::fromStdString(text));
}

void Drukbox::clearMedium()
{
    textbox->clear();
}
