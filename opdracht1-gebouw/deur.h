#ifndef DEUR_H
#define DEUR_H

class QPaintDevice;
class Deur
{
public:
    Deur(int, int, unsigned int);
    virtual ~Deur();

    virtual void teken(QPaintDevice*);
    virtual void open();
    virtual void sluit();
    virtual void setStatus(bool);

    virtual bool isDeurOpen() const;
    virtual unsigned int deurLengte() const;
    virtual int coordinaatX() const;
    virtual int coordinaatY() const;


private:
    bool status;
    int x_coordinaat, y_coordinaat;
    unsigned int lengte;
};

#endif // DEUR_H
