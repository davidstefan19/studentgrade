#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QDate>
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddStudent();
    void onDeleteStudent();
    void saveToXml();
    void loadFromXml();
    void applyStyle(const QString &styleName);

private:
    Ui::MainWindow *ui;
    QList<Student>  students;
    void refreshTable();
};

#endif // MAINWINDOW_H
