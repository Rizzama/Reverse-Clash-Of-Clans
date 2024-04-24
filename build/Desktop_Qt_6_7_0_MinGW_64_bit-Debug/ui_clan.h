/********************************************************************************
** Form generated from reading UI file 'clan.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLAN_H
#define UI_CLAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Clan
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Clan)
    {
        if (Clan->objectName().isEmpty())
            Clan->setObjectName("Clan");
        Clan->resize(800, 600);
        centralwidget = new QWidget(Clan);
        centralwidget->setObjectName("centralwidget");
        Clan->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Clan);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        Clan->setMenuBar(menubar);
        statusbar = new QStatusBar(Clan);
        statusbar->setObjectName("statusbar");
        Clan->setStatusBar(statusbar);

        retranslateUi(Clan);

        QMetaObject::connectSlotsByName(Clan);
    } // setupUi

    void retranslateUi(QMainWindow *Clan)
    {
        Clan->setWindowTitle(QCoreApplication::translate("Clan", "Clan", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Clan: public Ui_Clan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLAN_H
