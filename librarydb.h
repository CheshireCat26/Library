#ifndef LIBRARYDB_H
#define LIBRARYDB_H

#include "book.h"
#include <vector>
#include <QtSql/QSqlDatabase>



class LibraryDB
{
public:
    static void Connect();
    static Book getBook(int id);
    static std::vector<Book> getLikeBook(Book& like);
    static void InsterBook(Book& book);


private:
    static QSqlDatabase db;
};


QString splitStrings(std::vector<QString> strs);
std::vector<QString> devideString(QString str);

#endif // LIBRARYDB_H