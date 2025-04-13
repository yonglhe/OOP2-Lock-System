#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Sensor;
class Deur;
class Slot;
class Kaartslot;
// class Afdrukker;
class Drukbox;
class Idkaart;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    ~MainWindow();

 private slots:
    void hallsensor();
    void schuifdeurKnop();
    void draaideur1Knop();
    void draaideur2Knop();
    void knopToegang();
    void knopGeenToegang();
    void kaartenbakKnop();
    void knopMaakIdKaart();
    void knopVerwijderIdKaart();
    void kaartToegang();
    void kaartGeenToegang();

 private:
    Ui::MainWindow *ui;
    shared_ptr<Sensor> s1;
    shared_ptr<Deur> sd, d1, d2;
    shared_ptr<Slot> sd_sleutelslot, sd_codeslot;
    shared_ptr<Slot> d1_sleutelslot, d1_codeslot;
    shared_ptr<Slot> d2_codeslot, d2_herkenslot;

    unique_ptr<Kaartslot> sd_kaartslot;
    unique_ptr<Kaartslot> d1_kaartslot;

    shared_ptr<Idkaart> idKaart;
    Drukbox* afdruk;
};
#endif // MAINWINDOW_H
