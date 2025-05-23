#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "hallsensor.h"
#include "schuifdeur.h"
#include "draaideur.h"

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
    if(sd->isDeurOpen())
        sd->sluit();
    else
        sd->open();
    update();
}

void MainWindow::draaideur1Knop()
{
    if(d1->isDeurOpen())
        d1->sluit();
    else
        d1->open();
    update();
}

void MainWindow::draaideur2Knop()
{
    if(d2->isDeurOpen())
        d2->sluit();
    else
        d2->open();
    update();
}
