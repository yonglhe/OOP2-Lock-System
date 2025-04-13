/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *schuifdeurKnop;
    QPushButton *hallsensor;
    QPushButton *draaideur1Knop;
    QPushButton *draaideur2Knop;
    QLineEdit *schuifPassSlot1;
    QLineEdit *draaiCodeSlot2;
    QLineEdit *draaiCodeSlot1;
    QLineEdit *schuifCodeSlot1;
    QLineEdit *draaiPassSlot1;
    QTextBrowser *textBrowser;
    QPushButton *knopToegang;
    QPushButton *knopGeenToegang;
    QLineEdit *lineEdit;
    QLineEdit *draaiHerkenSlot1;
    QPushButton *kaartenbakKnop;
    QLabel *labelKaartenbak;
    QLineEdit *idInput;
    QLineEdit *naamInput;
    QLineEdit *adresInput;
    QLabel *labelIdKaart;
    QLabel *labelId;
    QLabel *labelNaam;
    QLabel *labelAdres;
    QPushButton *knopMaakIdKaart;
    QPushButton *knopVerwijderIdKaart;
    QLineEdit *schuifKaartSlot1;
    QPushButton *kaartToegang;
    QPushButton *kaartGeenToegang;
    QLineEdit *draaiKaartSlot1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1002, 571);
        MainWindow->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; }"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        schuifdeurKnop = new QPushButton(centralwidget);
        schuifdeurKnop->setObjectName("schuifdeurKnop");
        schuifdeurKnop->setGeometry(QRect(520, 270, 31, 23));
        hallsensor = new QPushButton(centralwidget);
        hallsensor->setObjectName("hallsensor");
        hallsensor->setGeometry(QRect(520, 130, 31, 23));
        draaideur1Knop = new QPushButton(centralwidget);
        draaideur1Knop->setObjectName("draaideur1Knop");
        draaideur1Knop->setGeometry(QRect(250, 150, 31, 23));
        draaideur2Knop = new QPushButton(centralwidget);
        draaideur2Knop->setObjectName("draaideur2Knop");
        draaideur2Knop->setGeometry(QRect(310, 270, 31, 23));
        schuifPassSlot1 = new QLineEdit(centralwidget);
        schuifPassSlot1->setObjectName("schuifPassSlot1");
        schuifPassSlot1->setGeometry(QRect(560, 270, 141, 22));
        schuifPassSlot1->setAutoFillBackground(false);
        schuifPassSlot1->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; color: black;}"));
        draaiCodeSlot2 = new QLineEdit(centralwidget);
        draaiCodeSlot2->setObjectName("draaiCodeSlot2");
        draaiCodeSlot2->setGeometry(QRect(360, 270, 141, 22));
        draaiCodeSlot2->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; color: black;}"));
        draaiCodeSlot1 = new QLineEdit(centralwidget);
        draaiCodeSlot1->setObjectName("draaiCodeSlot1");
        draaiCodeSlot1->setGeometry(QRect(300, 150, 113, 22));
        draaiCodeSlot1->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; color: black;}"));
        schuifCodeSlot1 = new QLineEdit(centralwidget);
        schuifCodeSlot1->setObjectName("schuifCodeSlot1");
        schuifCodeSlot1->setGeometry(QRect(560, 300, 141, 22));
        schuifCodeSlot1->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; color: black;}"));
        draaiPassSlot1 = new QLineEdit(centralwidget);
        draaiPassSlot1->setObjectName("draaiPassSlot1");
        draaiPassSlot1->setGeometry(QRect(300, 180, 113, 22));
        draaiPassSlot1->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; color: black;}"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(720, 20, 256, 192));
        textBrowser->setStyleSheet(QString::fromUtf8("QTextBrowser { background-color: white; color:black}"));
        knopToegang = new QPushButton(centralwidget);
        knopToegang->setObjectName("knopToegang");
        knopToegang->setGeometry(QRect(750, 290, 80, 23));
        knopGeenToegang = new QPushButton(centralwidget);
        knopGeenToegang->setObjectName("knopGeenToegang");
        knopGeenToegang->setGeometry(QRect(850, 290, 80, 23));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(750, 260, 181, 22));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; color: black;}"));
        draaiHerkenSlot1 = new QLineEdit(centralwidget);
        draaiHerkenSlot1->setObjectName("draaiHerkenSlot1");
        draaiHerkenSlot1->setGeometry(QRect(360, 300, 141, 22));
        draaiHerkenSlot1->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; color: black;}"));
        kaartenbakKnop = new QPushButton(centralwidget);
        kaartenbakKnop->setObjectName("kaartenbakKnop");
        kaartenbakKnop->setGeometry(QRect(800, 220, 80, 23));
        labelKaartenbak = new QLabel(centralwidget);
        labelKaartenbak->setObjectName("labelKaartenbak");
        labelKaartenbak->setGeometry(QRect(800, 0, 91, 20));
        idInput = new QLineEdit(centralwidget);
        idInput->setObjectName("idInput");
        idInput->setGeometry(QRect(780, 360, 113, 22));
        idInput->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; color: black;}"));
        naamInput = new QLineEdit(centralwidget);
        naamInput->setObjectName("naamInput");
        naamInput->setGeometry(QRect(780, 390, 113, 22));
        naamInput->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; color: black;}"));
        adresInput = new QLineEdit(centralwidget);
        adresInput->setObjectName("adresInput");
        adresInput->setGeometry(QRect(780, 420, 113, 22));
        adresInput->setAutoFillBackground(false);
        adresInput->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; color: black;}"));
        labelIdKaart = new QLabel(centralwidget);
        labelIdKaart->setObjectName("labelIdKaart");
        labelIdKaart->setGeometry(QRect(810, 340, 58, 15));
        labelId = new QLabel(centralwidget);
        labelId->setObjectName("labelId");
        labelId->setGeometry(QRect(754, 362, 21, 16));
        labelNaam = new QLabel(centralwidget);
        labelNaam->setObjectName("labelNaam");
        labelNaam->setGeometry(QRect(731, 392, 41, 16));
        labelAdres = new QLabel(centralwidget);
        labelAdres->setObjectName("labelAdres");
        labelAdres->setGeometry(QRect(718, 422, 58, 15));
        knopMaakIdKaart = new QPushButton(centralwidget);
        knopMaakIdKaart->setObjectName("knopMaakIdKaart");
        knopMaakIdKaart->setGeometry(QRect(790, 450, 91, 23));
        knopVerwijderIdKaart = new QPushButton(centralwidget);
        knopVerwijderIdKaart->setObjectName("knopVerwijderIdKaart");
        knopVerwijderIdKaart->setGeometry(QRect(790, 480, 91, 23));
        schuifKaartSlot1 = new QLineEdit(centralwidget);
        schuifKaartSlot1->setObjectName("schuifKaartSlot1");
        schuifKaartSlot1->setGeometry(QRect(560, 350, 141, 22));
        schuifKaartSlot1->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; color: black;}"));
        kaartToegang = new QPushButton(centralwidget);
        kaartToegang->setObjectName("kaartToegang");
        kaartToegang->setGeometry(QRect(560, 380, 71, 23));
        kaartGeenToegang = new QPushButton(centralwidget);
        kaartGeenToegang->setObjectName("kaartGeenToegang");
        kaartGeenToegang->setGeometry(QRect(630, 380, 71, 23));
        draaiKaartSlot1 = new QLineEdit(centralwidget);
        draaiKaartSlot1->setObjectName("draaiKaartSlot1");
        draaiKaartSlot1->setGeometry(QRect(300, 210, 113, 22));
        draaiKaartSlot1->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; color: black;}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1002, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(accessibility)
        MainWindow->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        schuifdeurKnop->setText(QCoreApplication::translate("MainWindow", "sd", nullptr));
        hallsensor->setText(QCoreApplication::translate("MainWindow", "s1", nullptr));
        draaideur1Knop->setText(QCoreApplication::translate("MainWindow", "d1", nullptr));
        draaideur2Knop->setText(QCoreApplication::translate("MainWindow", "d2", nullptr));
#if QT_CONFIG(accessibility)
        schuifPassSlot1->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        schuifPassSlot1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter password:", nullptr));
        draaiCodeSlot2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter code:", nullptr));
        draaiCodeSlot1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter code:", nullptr));
        schuifCodeSlot1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter code:", nullptr));
        draaiPassSlot1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter password:", nullptr));
        knopToegang->setText(QCoreApplication::translate("MainWindow", "Access", nullptr));
        knopGeenToegang->setText(QCoreApplication::translate("MainWindow", "No access", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter name:", nullptr));
        draaiHerkenSlot1->setText(QString());
        draaiHerkenSlot1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter: identification", nullptr));
        kaartenbakKnop->setText(QCoreApplication::translate("MainWindow", "Show", nullptr));
        labelKaartenbak->setText(QCoreApplication::translate("MainWindow", "Cardbox Access", nullptr));
        labelIdKaart->setText(QCoreApplication::translate("MainWindow", "ID Card", nullptr));
        labelId->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        labelNaam->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        labelAdres->setText(QCoreApplication::translate("MainWindow", "Address:", nullptr));
        knopMaakIdKaart->setText(QCoreApplication::translate("MainWindow", "Add new card", nullptr));
        knopVerwijderIdKaart->setText(QCoreApplication::translate("MainWindow", "Remove card", nullptr));
        schuifKaartSlot1->setText(QString());
        schuifKaartSlot1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter ID number:", nullptr));
        kaartToegang->setText(QCoreApplication::translate("MainWindow", "Access", nullptr));
        kaartGeenToegang->setText(QCoreApplication::translate("MainWindow", "No access", nullptr));
        draaiKaartSlot1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter ID number:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
