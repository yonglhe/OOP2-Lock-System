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
    QLabel *labelHalsensor;
    QLineEdit *schuifPassSlot1;
    QLineEdit *draaiCodeSlot2;
    QLineEdit *draaiCodeSlot1;
    QLineEdit *schuifCodeSlot1;
    QLineEdit *draaiPassSlot1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(750, 550);
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
        labelHalsensor = new QLabel(centralwidget);
        labelHalsensor->setObjectName("labelHalsensor");
        labelHalsensor->setGeometry(QRect(540, 160, 58, 15));
        schuifPassSlot1 = new QLineEdit(centralwidget);
        schuifPassSlot1->setObjectName("schuifPassSlot1");
        schuifPassSlot1->setGeometry(QRect(560, 270, 113, 22));
        schuifPassSlot1->setAutoFillBackground(false);
        schuifPassSlot1->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; }"));
        draaiCodeSlot2 = new QLineEdit(centralwidget);
        draaiCodeSlot2->setObjectName("draaiCodeSlot2");
        draaiCodeSlot2->setGeometry(QRect(360, 270, 113, 22));
        draaiCodeSlot2->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; }"));
        draaiCodeSlot1 = new QLineEdit(centralwidget);
        draaiCodeSlot1->setObjectName("draaiCodeSlot1");
        draaiCodeSlot1->setGeometry(QRect(300, 150, 113, 22));
        draaiCodeSlot1->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; }"));
        schuifCodeSlot1 = new QLineEdit(centralwidget);
        schuifCodeSlot1->setObjectName("schuifCodeSlot1");
        schuifCodeSlot1->setGeometry(QRect(560, 300, 113, 22));
        schuifCodeSlot1->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; }"));
        draaiPassSlot1 = new QLineEdit(centralwidget);
        draaiPassSlot1->setObjectName("draaiPassSlot1");
        draaiPassSlot1->setGeometry(QRect(300, 180, 113, 22));
        draaiPassSlot1->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: white; }"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 750, 20));
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
        schuifdeurKnop->setText(QCoreApplication::translate("MainWindow", "VD", nullptr));
        hallsensor->setText(QCoreApplication::translate("MainWindow", "s1", nullptr));
        draaideur1Knop->setText(QCoreApplication::translate("MainWindow", "d1", nullptr));
        draaideur2Knop->setText(QCoreApplication::translate("MainWindow", "d2", nullptr));
        labelHalsensor->setText(QCoreApplication::translate("MainWindow", "halsensor", nullptr));
#if QT_CONFIG(accessibility)
        schuifPassSlot1->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        schuifPassSlot1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter password:", nullptr));
        draaiCodeSlot2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter code:", nullptr));
        draaiCodeSlot1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter code:", nullptr));
        schuifCodeSlot1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter code:", nullptr));
        draaiPassSlot1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
