#ifndef LIBRARYDB_H
#define LIBRARYDB_H

#include "book.h"
#include "reader.h"
#include <vector>
#include <QtSql/QSqlDatabase>



class LibraryDB
{
public:
    static void Connect();

    static Book getBook(int id);
    static std::vector<Book> getLikeBook(Book& like);
    static void insertBook(Book& book);

    static std::vector<unsigned int> addInstances(int bookID, int number);

    static Reader getReader(int id);
    static void insertReader(Reader& reader);

private:
    static QSqlDatabase db;
};


QString splitStrings(std::vector<QString> strs);
std::vector<QString> devideString(QString str);

#endif // LIBRARYDB_H
