#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

#include "hallsensor.h"
#include "schuifdeur.h"
#include "draaideur.h"
#include "codeslot.h"
#include "sleutelslot.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);

    // s1=new Hallsensor(515, 160);
    // sd=new Schuifdeur(505, 250, 80, s1);
    // d1=new Draaideur(250, 140, 40, true);
    // d2=new Draaideur(295, 290, 30, false);

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

    // Voeg alleen codeslot in draaideur 2
    d2->voegSlotToe(new Codeslot(333));


    connect(ui->hallsensor, &QPushButton::clicked, this, &MainWindow::hallsensor);
    connect(ui->schuifdeurKnop, &QPushButton::clicked, this, &MainWindow::schuifdeurKnop);
    connect(ui->draaideur1Knop, &QPushButton::clicked, this, &MainWindow::draaideur1Knop);
    connect(ui->draaideur2Knop, &QPushButton::clicked, this, &MainWindow::draaideur2Knop);
}
MainWindow::~MainWindow()
{
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
            (*i).vergrendel();
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
            (*i).vergrendel();
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
            (*i).vergrendel();
        }
    } else {
        d2->getSlotList().front()->ontgrendel(ui->draaiCodeSlot2->text().toStdString());
        if(!d2->getSlotList().front()->isVergrendeld() && !d2->getSlotList().back()->isVergrendeld()){
            d2->open();
        }
    }
    update();
}
