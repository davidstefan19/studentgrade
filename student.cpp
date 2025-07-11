#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
    QString nume;
    QString prenume;
    QString grupa;
    float nota;

    Student() {}
    Student(QString n, QString p, QString g, float no)
        : nume(n), prenume(p), grupa(g), nota(no) {}
};

#endif // STUDENT_H
