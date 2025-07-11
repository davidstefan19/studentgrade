/********************************************************************************
** Form generated from reading UI file 'addstudentdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTUDENTDIALOG_H
#define UI_ADDSTUDENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddStudentDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineNume;
    QLineEdit *lineGrupa;
    QLineEdit *linePrenume;
    QDateEdit *dateEditData;
    QDoubleSpinBox *spinNota;

    void setupUi(QDialog *AddStudentDialog)
    {
        if (AddStudentDialog->objectName().isEmpty())
            AddStudentDialog->setObjectName("AddStudentDialog");
        AddStudentDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddStudentDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        lineNume = new QLineEdit(AddStudentDialog);
        lineNume->setObjectName("lineNume");
        lineNume->setGeometry(QRect(30, 30, 113, 28));
        lineGrupa = new QLineEdit(AddStudentDialog);
        lineGrupa->setObjectName("lineGrupa");
        lineGrupa->setGeometry(QRect(30, 60, 113, 28));
        linePrenume = new QLineEdit(AddStudentDialog);
        linePrenume->setObjectName("linePrenume");
        linePrenume->setGeometry(QRect(30, 90, 113, 28));
        dateEditData = new QDateEdit(AddStudentDialog);
        dateEditData->setObjectName("dateEditData");
        dateEditData->setGeometry(QRect(20, 210, 110, 29));
        dateEditData->setCalendarPopup(true);
        spinNota = new QDoubleSpinBox(AddStudentDialog);
        spinNota->setObjectName("spinNota");
        spinNota->setGeometry(QRect(230, 110, 63, 29));
        spinNota->setMinimum(1.000000000000000);
        spinNota->setMaximum(10.000000000000000);

        retranslateUi(AddStudentDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddStudentDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddStudentDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddStudentDialog);
    } // setupUi

    void retranslateUi(QDialog *AddStudentDialog)
    {
        AddStudentDialog->setWindowTitle(QCoreApplication::translate("AddStudentDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddStudentDialog: public Ui_AddStudentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTUDENTDIALOG_H
