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
    QLineEdit *sleutelSlot;
    QLineEdit *codeSlot2;
    QLineEdit *codeSlot1;
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
        sleutelSlot = new QLineEdit(centralwidget);
        sleutelSlot->setObjectName("sleutelSlot");
        sleutelSlot->setGeometry(QRect(560, 270, 113, 22));
        codeSlot2 = new QLineEdit(centralwidget);
        codeSlot2->setObjectName("codeSlot2");
        codeSlot2->setGeometry(QRect(360, 270, 113, 22));
        codeSlot1 = new QLineEdit(centralwidget);
        codeSlot1->setObjectName("codeSlot1");
        codeSlot1->setGeometry(QRect(300, 150, 113, 22));
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
        sleutelSlot->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
