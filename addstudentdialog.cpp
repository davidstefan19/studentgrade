#include "addstudentdialog.h"
#include "ui_addstudentdialog.h"

AddStudentDialog::AddStudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStudentDialog)
{
    ui->setupUi(this);
    ui->dateEditData->setDate(QDate::currentDate());
    ui->spinNota->setRange(1.0, 10.0);
    ui->spinNota->setSingleStep(0.1);
    ui->spinNota->setDecimals(1);
}

AddStudentDialog::~AddStudentDialog()
{
    delete ui;
}

QString AddStudentDialog::getNume() const    { return ui->lineNume->text(); }
QString AddStudentDialog::getPrenume() const { return ui->linePrenume->text(); }
QDate   AddStudentDialog::getData() const    { return ui->dateEditData->date(); }
float   AddStudentDialog::getNota() const    { return ui->spinNota->value(); }
QString AddStudentDialog::getGrupa() const   { return ui->lineGrupa->text(); }
