/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QComboBox *comboStyle;
    QPushButton *btnAdd;
    QPushButton *btnDelete;
    QTableWidget *tableWidget;
    QPushButton *btnExport;
    QPushButton *btnImport;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        comboStyle = new QComboBox(centralwidget);
        comboStyle->setObjectName("comboStyle");

        verticalLayout->addWidget(comboStyle);

        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName("btnAdd");

        verticalLayout->addWidget(btnAdd);

        btnDelete = new QPushButton(centralwidget);
        btnDelete->setObjectName("btnDelete");

        verticalLayout->addWidget(btnDelete);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setColumnCount(4);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);

        verticalLayout->addWidget(tableWidget);

        btnExport = new QPushButton(centralwidget);
        btnExport->setObjectName("btnExport");

        verticalLayout->addWidget(btnExport);

        btnImport = new QPushButton(centralwidget);
        btnImport->setObjectName("btnImport");

        verticalLayout->addWidget(btnImport);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Student Grade Manager", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "Adauga student", nullptr));
        btnDelete->setText(QCoreApplication::translate("MainWindow", "Sterge student", nullptr));
        btnExport->setText(QCoreApplication::translate("MainWindow", "Exporta \"XML\"", nullptr));
        btnImport->setText(QCoreApplication::translate("MainWindow", "Importa \"XML\"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
