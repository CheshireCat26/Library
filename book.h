#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <vector>

class Book
{
    QString name;
    QString author;
    QString isbn;
   std::vector<QString> topics;
    QString description;
    int year;
    int id;
public:
    Book() : year{0}, id{-1} {}
    Book (QString Pname, QString Pauthor, QString Pisbn,
          std::vector<QString> Ptopics, QString Pdescription, int Pyear,
          int Pid) : name{Pname}, author{Pauthor}, isbn{Pisbn},
                     topics{Ptopics}, description{Pdescription},
                     year{Pyear}, id{Pid} {}

    QString getName() const { return name; }
    QString getAuthor() const { return author; }
    QString getIsbn() const { return isbn; }
    std::vector<QString> getTopics() const { return topics; }
    QString getDescription() const { return description; }
    int getYear() const { return year; }
    int getId() const { return id; }

    void setName(QString n) { name = n; }
    void setAuthor(QString a) { author = a; }
    void setIsbn(QString i) { isbn = i; }
    void setTopics(std::vector<QString> t) {topics = t; }
    void setDescription(QString d) {description = d; }
    void setYear(int y) { year = y; }
    void setId(int i) { id = i; }
};

#endif // BOOK_H
