#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QDate>

struct Student {
    QString nume;
    QString prenume;
    QDate   data;
    float   nota;
    QString grupa;
};

#endif // STUDENT_H
