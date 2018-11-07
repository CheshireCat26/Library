#ifndef LIBRARYDB_H
#define LIBRARYDB_H

#include "book.h"
#include "reader.h"
#include <vector>
#include <QtSql/QSqlDatabase>
#include <QDate>
#include <QMessageBox>

class LibraryDB
{
public:
    static void Connect();

    static Book getBook(int id);
    static std::vector<Book> getLikeBook(Book& like);
    static void insertBook(Book& book);
    static int getNewIDBook();
    static void deleteBook(int idBook);
    static void giveBook(int idInstance, int idReader, QDate dateReturn);
    static void returnBook(int idInstance);
    static void deleteReader(int idReader);
    static void freeAllInstances(int idReader);

    static int getNewID(QSqlQuery& query);

    static Reader getReader(int id);
    static Reader getReader(QString email);
    static void insertReader(Reader& reader);
    static int getNewIDReader();
    static void changeUnwanted(int idReader);

    static int getFreeInstatnce (int idBook);
    static std::vector<int> getIdTakenInstances(int idReader);
    static std::vector<int> getIdInstancesBook(int idBook);
    static void deleteInstance(int idInstance);
    static void deleteAllBookInstances(int idBook);
    static std::vector<unsigned int> addInstances(int bookID, int number);

private:
    static QSqlDatabase db;
};


QString splitStrings(std::vector<QString> strs);
std::vector<QString> devideString(QString str);
void showMessage(QString message);

#endif // LIBRARYDB_H
