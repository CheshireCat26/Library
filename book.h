#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book
{
    QString name;
    QString author;
    QString isbn;
    QString topics;
    QString description;
    int year;
    int id;
public:
    Book() : year{0}, id{0} {}
    Book (QString Pname, QString Pauthor, QString Pisbn,
          QString Ptopics, QString Pdescription, int Pyear,
          int Pid) : name{Pname}, author{Pauthor}, isbn{Pisbn},
                     topics{Ptopics}, description{Pdescription},
                     year{Pyear}, id{Pid} {}

    QString getName() { return name; }
    QString getAuthor() { return author; }
    QString getIsbn() { return isbn; }
    QString getTopics() { return topics; }
    QString getDescription() { return description; }
    int getYear() { return year; }
    int getId() { return id; }
};

#endif // BOOK_H
