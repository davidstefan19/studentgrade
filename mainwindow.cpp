#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addstudentdialog.h"

#include <QFileDialog>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QHeaderView>
#include <QStyleFactory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // --- Configure table ---
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(
        QStringList() << "Nume" << "Prenume" << "Data" << "Nota" << "Grupa");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // --- Populate style combo ---
    ui->comboStyle->addItems(QStyleFactory::keys());
    connect(ui->comboStyle, &QComboBox::currentTextChanged,
            this, &MainWindow::applyStyle);
    // set default style
    if (!QStyleFactory::keys().isEmpty()) {
        ui->comboStyle->setCurrentIndex(0);
        applyStyle(ui->comboStyle->currentText());
    }

    // --- Connect buttons ---
    connect(ui->btnAdd,    &QPushButton::clicked, this, &MainWindow::onAddStudent);
    connect(ui->btnDelete, &QPushButton::clicked, this, &MainWindow::onDeleteStudent);
    connect(ui->btnImport, &QPushButton::clicked, this, &MainWindow::loadFromXml);
    connect(ui->btnExport, &QPushButton::clicked, this, &MainWindow::saveToXml);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddStudent()
{
    AddStudentDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        Student s;
        s.nume    = dlg.getNume();
        s.prenume = dlg.getPrenume();
        s.data    = dlg.getData();
        s.nota    = dlg.getNota();
        s.grupa   = dlg.getGrupa();
        students.append(s);
        refreshTable();
    }
}

void MainWindow::onDeleteStudent()
{
    int r = ui->tableWidget->currentRow();
    if (r < 0 || r >= students.size()) {
        QMessageBox::warning(this, "Ștergere",
                             "Selectează un student pentru ștergere.");
        return;
    }
    students.removeAt(r);
    refreshTable();
}

void MainWindow::refreshTable()
{
    ui->tableWidget->setRowCount(students.size());
    for (int i = 0; i < students.size(); ++i) {
        const auto &s = students.at(i);
        ui->tableWidget->setItem(i, 0,
                                 new QTableWidgetItem(s.nume));
        ui->tableWidget->setItem(i, 1,
                                 new QTableWidgetItem(s.prenume));
        ui->tableWidget->setItem(i, 2,
                                 new QTableWidgetItem(s.data.toString("dd.MM.yyyy")));
        ui->tableWidget->setItem(i, 3,
                                 new QTableWidgetItem(QString::number(s.nota)));
        ui->tableWidget->setItem(i, 4,
                                 new QTableWidgetItem(s.grupa));
    }
}

void MainWindow::saveToXml()
{
    QString fn = QFileDialog::getSaveFileName(
        this, "Salvează XML", {}, "XML Files (*.xml)");
    if (fn.isEmpty()) return;

    QFile file(fn);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Eroare",
                             "Nu pot deschide fișierul pentru scriere.");
        return;
    }

    QXmlStreamWriter w(&file);
    w.setAutoFormatting(true);
    w.writeStartDocument();
    w.writeStartElement("students");
    for (auto &s : students) {
        w.writeStartElement("student");
        w.writeTextElement("nume",    s.nume);
        w.writeTextElement("prenume", s.prenume);
        w.writeTextElement("data",    s.data.toString(Qt::ISODate));
        w.writeTextElement("nota",    QString::number(s.nota));
        w.writeTextElement("grupa",   s.grupa);
        w.writeEndElement(); // student
    }
    w.writeEndElement(); // students
    w.writeEndDocument();
    file.close();
    QMessageBox::information(this, "Export", "Export finalizat.");
}

void MainWindow::loadFromXml()
{
    QString fn = QFileDialog::getOpenFileName(
        this, "Deschide XML", {}, "XML Files (*.xml)");
    if (fn.isEmpty()) return;

    QFile file(fn);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Eroare",
                             "Nu pot deschide fișierul pentru citire.");
        return;
    }

    QXmlStreamReader r(&file);
    students.clear();
    while (!r.atEnd() && !r.hasError()) {
        r.readNext();
        if (r.isStartElement() && r.name() == "student") {
            Student s;
            while (!(r.isEndElement() && r.name() == "student")) {
                r.readNext();
                if (r.isStartElement()) {
                    if (r.name() == "nume")    s.nume    = r.readElementText();
                    if (r.name() == "prenume") s.prenume = r.readElementText();
                    if (r.name() == "data")    s.data    = QDate::fromString(r.readElementText(), Qt::ISODate);
                    if (r.name() == "nota")    s.nota    = r.readElementText().toFloat();
                    if (r.name() == "grupa")   s.grupa   = r.readElementText();
                }
            }
            students.append(s);
        }
    }
    file.close();
    if (r.hasError())
        QMessageBox::warning(this, "Eroare", "Fișier XML invalid.");
    else
        refreshTable();
}

void MainWindow::applyStyle(const QString &styleName)
{
    qApp->setStyle(styleName);
}
