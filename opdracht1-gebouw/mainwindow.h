#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class Sensor;
class Deur;

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

 private:
    Ui::MainWindow *ui;
    // Deur *sd, *d1, *d2;
    // Sensor *s1;
    shared_ptr<Sensor> s1;
    shared_ptr<Deur> sd, d1, d2;
};
#endif // MAINWINDOW_H
