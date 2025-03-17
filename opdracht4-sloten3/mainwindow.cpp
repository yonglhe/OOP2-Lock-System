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
#include "drukbox.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    s1 = shared_ptr<Hallsensor>(new Hallsensor(515, 160));
    sd = shared_ptr<Schuifdeur>(new Schuifdeur(505, 250, 80, s1.get()));
    d1 = shared_ptr<Draaideur>(new Draaideur(250, 140, 40, true));
    d2 = shared_ptr<Draaideur>(new Draaideur(295, 290, 30, false));

    // Voeg sleutelslot en codeslot in schuifdeur
    sd->voegSlotToe(new Sleutelslot("password"));
    sd->voegSlotToe(new Codeslot(111));

    // Voeg codeslot en sleutelslot in draaideur 1
    d1->voegSlotToe(new Codeslot(222));
    d1->voegSlotToe(new Sleutelslot("password"));

    // Voeg codeslot en herkenningsslot in draaideur 2
    d2->voegSlotToe(new Codeslot(333));

    afdruk = new Drukbox(ui->textBrowser);
    d2->voegSlotToe(new Herkenningsslot(afdruk));

    connect(ui->hallsensor, &QPushButton::clicked, this, &MainWindow::hallsensor);
    connect(ui->schuifdeurKnop, &QPushButton::clicked, this, &MainWindow::schuifdeurKnop);
    connect(ui->draaideur1Knop, &QPushButton::clicked, this, &MainWindow::draaideur1Knop);
    connect(ui->draaideur2Knop, &QPushButton::clicked, this, &MainWindow::draaideur2Knop);
    connect(ui->knopToegang, &QPushButton::clicked, this, &MainWindow::knopToegang);
    connect(ui->knopGeenToegang, &QPushButton::clicked, this, &MainWindow::knopGeenToegang);
    connect(ui->kaartenbakKnop, &QPushButton::clicked, this, &MainWindow::kaartenbakKnop);
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
    if(sd->isDeurOpen()) {
        sd->sluit();
        for(auto& i:sd->getSlotList()){
            i->vergrendel();
        }
    } else {
        sd->getSlotList().front()->ontgrendel(ui->schuifPassSlot1->text().toStdString());
        sd->getSlotList().back()->ontgrendel(ui->schuifCodeSlot1->text().toStdString());
        if(!sd->getSlotList().front()->isVergrendeld() && !sd->getSlotList().back()->isVergrendeld()){
            sd->open();
        }
    }
    update();
}

void MainWindow::draaideur1Knop()
{
    if(d1->isDeurOpen()) {
        d1->sluit();
        for(auto& i:d1->getSlotList()){
            i->vergrendel();
        }
    } else {
        d1->getSlotList().front()->ontgrendel(ui->draaiCodeSlot1->text().toStdString());
        d1->getSlotList().back()->ontgrendel(ui->draaiPassSlot1->text().toStdString());
        if(!d1->getSlotList().front()->isVergrendeld() && !d1->getSlotList().back()->isVergrendeld()){
            d1->open();
        }
    }
    update();
}

void MainWindow::draaideur2Knop()
{
    if(d2->isDeurOpen()) {
        d2->sluit();
        for(auto& i:d2->getSlotList()){
            i->vergrendel();
        }
    } else {
        d2->getSlotList().front()->ontgrendel(ui->draaiCodeSlot2->text().toStdString());
        d2->getSlotList().back()->ontgrendel(ui->draaiHerkenSlot1->text().toStdString());
        if(!d2->getSlotList().front()->isVergrendeld() && !d2->getSlotList().back()->isVergrendeld()){
            d2->open();
        }
    }
    update();
}

void MainWindow::knopToegang()
{
    for(auto const& slot: d2->getSlotList()){
        auto* herkenslot = dynamic_cast<Herkenningsslot*>(slot); // convert pointer type slot to pointer type herkenningslot
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
        auto* herkenslot = dynamic_cast<Herkenningsslot*>(slot); // convert pointer type slot to pointer type herkenningslot
        if(herkenslot != nullptr){
            std::string input = ui->lineEdit->text().toStdString();
            herkenslot->voegAutorisatieToe(input, false);

            // auto deKaartenbak = herkenslot->getKaartenbak();
            // auto zoek(deKaartenbak.find(input));

            // if(zoek != deKaartenbak.end()){
            //     std::cout << zoek->second << std::endl;
            //     zoek->second = false;
            //     std::cout << zoek->second << std::endl;
            //     std::cout << input << " heeft geen toegang meer." <<std::endl;
            }
    }
    ui->lineEdit->clear();
}

void MainWindow::kaartenbakKnop()
{
    for(auto const& slot: d2->getSlotList()){
        auto* herkenslot = dynamic_cast<Herkenningsslot*>(slot); // convert pointer type slot to pointer type herkenningslot
        if(herkenslot != nullptr){
            afdruk->clearMedium();
            herkenslot->toonKaartenbak();
        }
    }
}
