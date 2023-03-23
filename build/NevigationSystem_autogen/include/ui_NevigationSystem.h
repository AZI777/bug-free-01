/********************************************************************************
** Form generated from reading UI file 'NevigationSystem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEVIGATIONSYSTEM_H
#define UI_NEVIGATIONSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NevigationSystem
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *NevigationSystem)
    {
        if (NevigationSystem->objectName().isEmpty())
            NevigationSystem->setObjectName(QString::fromUtf8("NevigationSystem"));
        NevigationSystem->resize(800, 600);
        centralwidget = new QWidget(NevigationSystem);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        NevigationSystem->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NevigationSystem);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        NevigationSystem->setMenuBar(menubar);
        statusbar = new QStatusBar(NevigationSystem);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        NevigationSystem->setStatusBar(statusbar);

        retranslateUi(NevigationSystem);

        QMetaObject::connectSlotsByName(NevigationSystem);
    } // setupUi

    void retranslateUi(QMainWindow *NevigationSystem)
    {
        NevigationSystem->setWindowTitle(QCoreApplication::translate("NevigationSystem", "NevigationSystem", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NevigationSystem: public Ui_NevigationSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEVIGATIONSYSTEM_H
