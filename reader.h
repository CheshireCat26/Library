#ifndef READER_H
#define READER_H

#include <QString>

class Reader
{
private:
    QString name;
    QString surname;
    QString patronymic;
    QString phoneNumber;
    QString email;
    int id;
    bool unwanted;
public:
    Reader() : id{-1}, unwanted{false} {}
    Reader(QString pName, QString pSurname, QString pPatronymic,
           QString pPhoneNumber, QString pEmail, int pId,
           bool pUnwanted)
        : name{pName}, surname{pSurname}, patronymic{pPatronymic},
          phoneNumber{pPhoneNumber}, email{pEmail}, id{pId},
          unwanted{pUnwanted}
    {}

    QString getName() { return name; }
    QString getSurName() { return surname; }
    QString getPatronymic() { return patronymic; }
    QString getPhoneNumber() { return phoneNumber; }
    QString getEmail() { return email; }
    int getId() { return id; }
    bool getUnwanted() { return unwanted; }
};

#endif // READER_H
