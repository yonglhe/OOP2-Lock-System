#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QLineEdit>

#include "hallsensor.h"
#include "schuifdeur.h"
#include "draaideur.h"
#include "codeslot.h"
#include "sleutelslot.h"
#include "herkenningsslot.h"
#include "kaartslot.h"
#include "drukbox.h"
#include "slotexception.h"

#define SCHUIDEUR_SLEUTELSLOT       "password"
#define SCHUIDEUR_CODESLOT          111
#define SCHUIDEUR_KAARTSLOT         "schuifdeur"
#define DRAAIDEUR1_SLEUTELSLOT      "password"
#define DRAAIDEUR1_CODESLOT         222
#define DRAAIDEUR1_KAARTSLOT        "draaideur"
#define DRAAIDEUR2_CODESLOT         333

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    s1 = shared_ptr<Hallsensor>(new Hallsensor(515, 160));
    sd = shared_ptr<Schuifdeur>(new Schuifdeur(505, 250, 80, s1.get()));
    d1 = shared_ptr<Draaideur>(new Draaideur(250, 140, 40, true));
    d2 = shared_ptr<Draaideur>(new Draaideur(295, 290, 30, false));

    sd_sleutelslot = shared_ptr<Sleutelslot>(new Sleutelslot(SCHUIDEUR_SLEUTELSLOT));
    sd_codeslot = shared_ptr<Codeslot>(new Codeslot(SCHUIDEUR_CODESLOT));
    sd_kaartslot = unique_ptr<Kaartslot>(new Kaartslot(SCHUIDEUR_KAARTSLOT));
    // Voeg sleutelslot, codeslot en kaartslot in schuifdeur
    sd->voegSlotToe(sd_sleutelslot.get());
    sd->voegSlotToe(sd_codeslot.get());
    sd->voegSlotToe(sd_kaartslot.get());        // voeg een kaarslot bij schuideur

    d1_sleutelslot = shared_ptr<Sleutelslot>(new Sleutelslot(DRAAIDEUR1_SLEUTELSLOT));
    d1_codeslot = shared_ptr<Codeslot>(new Codeslot(DRAAIDEUR1_CODESLOT));
    d1_kaartslot = unique_ptr<Kaartslot>(new Kaartslot(DRAAIDEUR1_KAARTSLOT));
    // Voeg codeslot, sleutelslot en kaartslot in draaideur 1
    d1->voegSlotToe(d1_sleutelslot.get());
    d1->voegSlotToe(d1_codeslot.get());
    d1->voegSlotToe(d1_kaartslot.get());        // voeg een kaartslot bij draaideur1

    d2_codeslot = shared_ptr<Codeslot>(new Codeslot(DRAAIDEUR2_CODESLOT));
    // Voeg codeslot en herkenningsslot in draaideur 2
    d2->voegSlotToe(d2_codeslot.get());
    //afdruk = shared_ptr<Afdrukker>(new Drukbox(ui->textBrowser));
    afdruk = new Drukbox(ui->textBrowser);
    d2_herkenslot = shared_ptr<Slot>(new Herkenningsslot(afdruk));
    d2->voegSlotToe(d2_herkenslot.get());

    // maak connectie met de knoppen van de ui (beter bij aanpassingen van knopnamen)
    connect(ui->hallsensor, &QPushButton::clicked, this, &MainWindow::hallsensor);
    connect(ui->schuifdeurKnop, &QPushButton::clicked, this, &MainWindow::schuifdeurKnop);
    connect(ui->draaideur1Knop, &QPushButton::clicked, this, &MainWindow::draaideur1Knop);
    connect(ui->draaideur2Knop, &QPushButton::clicked, this, &MainWindow::draaideur2Knop);
    connect(ui->knopToegang, &QPushButton::clicked, this, &MainWindow::knopToegang);
    connect(ui->knopGeenToegang, &QPushButton::clicked, this, &MainWindow::knopGeenToegang);
    connect(ui->kaartenbakKnop, &QPushButton::clicked, this, &MainWindow::kaartenbakKnop);
    connect(ui->knopMaakIdKaart, &QPushButton::clicked, this, &MainWindow::knopMaakIdKaart);
    connect(ui->knopVerwijderIdKaart, &QPushButton::clicked, this, &MainWindow::knopVerwijderIdKaart);
    connect(ui->kaartToegang, &QPushButton::clicked, this, &MainWindow::kaartToegang);
    connect(ui->kaartGeenToegang, &QPushButton::clicked, this, &MainWindow::kaartGeenToegang);
}
MainWindow::~MainWindow()
{
    // geheugen vrij maken
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPen pen;
    QImage image("/home/paco/codes/projects/oopr2/opdracht1-gebouw/Gebouw.png");

    pen.setColor(Qt::green);
    pen.setWidth(4);
    painter.setPen(pen);
    painter.drawImage(10,10,image);

    s1->teken(this);
    sd->teken(this);
    d1->teken(this);
    d2->teken(this);
}

void MainWindow::hallsensor()
{
    if(s1->isGeactiveerd()){
        s1->deactiveer();
    }else{
        s1->activeer();
    }
    update();
}

void MainWindow::schuifdeurKnop()
{
    std::string schuifPassSlot = ui->schuifPassSlot1->text().toStdString();
    std::string schuifCodeSlot = ui->schuifCodeSlot1->text().toStdString();
    std::string schuifKaartSlot = ui->schuifKaartSlot1->text().toStdString();

    int index = 0;
    //int size = sd->getSlotList().size();

    if(sd->isDeurOpen()) {
        sd->sluit();
        for(auto& i:sd->getSlotList()){
            i->vergrendel();
        }
    } else {
        for (auto& i : sd->getSlotList()) {
            if (index == 0)
                i->ontgrendel(schuifPassSlot);
            else if (index == 1)
                i->ontgrendel(schuifCodeSlot);
            else if (index == 2)
                try{
                    i->ontgrendel(schuifKaartSlot);
                } catch(Slotexception& e){
                    std::cout<< "Op de plek " <<e.plaatsVanHetSlot()<<std::endl;
                    std::cout<< "Geen idkaart voor " <<e.kaartVanBinnendringer()<<std::endl;
                }

            ++index;
        }
    }

    bool ontgrendel= false;
    for (auto slot : sd->getSlotList()) {
        if (slot->isVergrendeld()) {
            ontgrendel = false;
            break; // niet verder checken als een slot vergrendeld is
        }
        else
            ontgrendel = true;
    }
    if (ontgrendel) {
        sd->open();
    }
    update();
}

void MainWindow::draaideur1Knop()
{
    std::string draaiPassSlot = ui->draaiPassSlot1->text().toStdString();
    std::string draaiCodeSlot = ui->draaiCodeSlot1->text().toStdString();
    std::string draaiKaartSlot = ui->draaiKaartSlot1->text().toStdString();

    int index = 0;
    // int size = d1->getSlotList().size();

    if(d1->isDeurOpen()) {
        d1->sluit();
        for(auto& i:d1->getSlotList()){
            i->vergrendel();
        }
    } else {
        for (auto& i : d1->getSlotList()) {
            if (index == 0)
                i->ontgrendel(draaiPassSlot);
            else if (index == 1)
                i->ontgrendel(draaiCodeSlot);
            else if (index == 2)
                try{
                    i->ontgrendel(draaiKaartSlot);
                } catch(Slotexception& e){
                    std::cout<< "Op de plek " <<e.plaatsVanHetSlot()<<std::endl;
                    std::cout<< "Geen idkaart voor " <<e.kaartVanBinnendringer()<<std::endl;
                }
            ++index;
        }
    }
    bool ontgrendel= false;
    for (auto slot : d1->getSlotList()) {
        if (slot->isVergrendeld()) {
            ontgrendel = false;
            break; // niet verder checken als een slot vergrendeld is
        }
        else
            ontgrendel = true;
    }
    if (ontgrendel) {
        d1->open();
    }
    update();
}

void MainWindow::draaideur2Knop()
{
    std::string draaiCodeSlot2 = ui->draaiCodeSlot2->text().toStdString();
    std::string draaiHerkenSlot = ui->draaiHerkenSlot1->text().toStdString();

    int index = 0;
    int size = d2->getSlotList().size();

    if(d2->isDeurOpen()) {
        d2->sluit();
        for(auto& i:d2->getSlotList()){
            i->vergrendel();
        }
    } else {
        for (auto& i : d2->getSlotList()) {
            if (index == 0) {
                i->ontgrendel(draaiCodeSlot2);
            } else if (index == size - 1) {
                i->ontgrendel(draaiHerkenSlot);
            }
            ++index;
        }
    }
    bool ontgrendel= false;
    for (auto slot : d2->getSlotList()) {
        if (slot->isVergrendeld()) {
            ontgrendel = false;
            break; // niet verder checken als een slot vergrendeld is
        }
        else
            ontgrendel = true;
    }
    if (ontgrendel) {
        d2->open();
    }
    update();
}

void MainWindow::knopToegang()
{
    for(auto const& slot: d2->getSlotList()){
        auto* herkenslot = dynamic_cast<Herkenningsslot*>(slot); // converteer pointer type slot naar pointer type herkenningslot
        if(herkenslot != nullptr){
            std::string input = ui->lineEdit->text().toStdString();
            herkenslot->voegAutorisatieToe(input, true);
        }
    }
    ui->lineEdit->clear();
}

void MainWindow::knopGeenToegang()
{
    // zoekfunctie gebruiken om de naam de vinden
    // als hij in de kaartenbak staat, pas aan de toegang naar false

    for(auto const& slot: d2->getSlotList()){
        auto* herkenslot = dynamic_cast<Herkenningsslot*>(slot); // converteer pointer type slot naar pointer type herkenningslot
        if(herkenslot != nullptr){
            std::string input = ui->lineEdit->text().toStdString();
            herkenslot->voegAutorisatieToe(input, false);
        }
    }
    ui->lineEdit->clear();
}

void MainWindow::kaartenbakKnop()
{
    for(auto const& slot: d2->getSlotList()){
        auto* herkenslot = dynamic_cast<Herkenningsslot*>(slot); // converteer pointer type slot naar pointer type herkenningslot
        if(herkenslot != nullptr){
            afdruk->clearMedium();
            herkenslot->toonKaartenbak();
        }
    }
}

void MainWindow::knopMaakIdKaart()
{
    std::string id = ui->idInput->text().toStdString();
    std::string naam = ui->naamInput->text().toStdString();
    std::string adres = ui->adresInput->text().toStdString();

    idKaart = shared_ptr<Idkaart>(new Idkaart(id, naam, adres));    // ID-kaart wordt aangemaakt

    d1_kaartslot->voegIdKaartToe(idKaart.get());
    sd_kaartslot->voegIdKaartToe(idKaart.get());

    std::cout << "Idkaart met id: '" << id << "' is toegevoegd aan alle kaartsloten" <<std::endl;
    std::cout << "Er zijn nu " << sd_kaartslot->deMapGrootte() << " id-kaart(en)."<<std::endl;


    // for (const auto& pair : sd_kaartslot->getIdKaartenMap()) {      // toon alle idkaarten uit de map
    //     std::cout << "User ID: " << pair.first << std::endl;
    // }
}

void MainWindow::knopVerwijderIdKaart()
{
    std::string id = ui->idInput->text().toStdString();

    sd_kaartslot->verwijderIdKaart(id);
    d1_kaartslot->verwijderIdKaart(id);
    std::cout << "Idkaart met id: '" << id << "' is verwijderd." << std::endl;
    std::cout << "Er zijn nu " << sd_kaartslot->deMapGrootte() << " id-kaart(en)."<<std::endl;
}

void MainWindow::kaartToegang(){
    std::string id = ui->schuifKaartSlot1->text().toStdString();

    for(auto const& slot: sd->getSlotList()){
        auto* kaartslot = dynamic_cast<Kaartslot*>(slot);
        if(kaartslot != nullptr)
            idKaart->geefToegang(kaartslot);
    }
    for(auto const& slot: d1->getSlotList()){
        auto* kaartslot = dynamic_cast<Kaartslot*>(slot);
        if(kaartslot != nullptr)
            idKaart->geefToegang(kaartslot);
    }
    std::cout<< "Er zijn/is " << idKaart->deVectorGrootte() << " id-kaarten die toegang hebben." <<std::endl;
}

void MainWindow::kaartGeenToegang(){
    std::string id = ui->schuifKaartSlot1->text().toStdString();

    for(auto const& slot: sd->getSlotList()){
        auto* kaartslot = dynamic_cast<Kaartslot*>(slot);
        if(kaartslot != nullptr)
            idKaart->verwijdertoegang(kaartslot);
    }

    for(auto const& slot: d1->getSlotList()){
        auto* kaartslot = dynamic_cast<Kaartslot*>(slot);
        if(kaartslot != nullptr)
            idKaart->verwijdertoegang(kaartslot);
    }

    std::cout<< "Er zijn/is " << idKaart->deVectorGrootte() << " id-kaarten die toegang hebben." <<std::endl;
}
