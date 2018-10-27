#include "librarydb.h"
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QString>
#include <QVariant>

QSqlDatabase LibraryDB::db = QSqlDatabase::addDatabase("QODBC");

void LibraryDB::Connect()
 {
     db.setDatabaseName("DRIVER={SQL Server};SERVER=DESKTOP-L9PSBQ7\\MSSQLSERVER11;DATABASE=Library;Trusted_Connection=yes;");
     db.setUserName("DESKTOP-L9PSBQ7\\nail1");
     if (!db.open())
     {
         QMessageBox dbErr(QMessageBox::Critical,
                           "Ошибка подключения",
                           "Не удалось подключаится к базе данных Library",
                           QMessageBox::Ok);

         dbErr.exec();
      }
}

void LibraryDB::InsterBook(Book& book)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Book (Name, Author, ISBN, Topics, Description, Year, ID) "
                  "VALUES (:name, :author, :isbn, :topics, :description, :year, :id)");

    query.bindValue(":name", book.getName());
    query.bindValue(":author", book.getAuthor());
    query.bindValue(":isbn", book.getIsbn());
    query.bindValue(":topics", splitStrings(book.getTopics()));
    query.bindValue(":description", book.getDescription());
    query.bindValue(":year", book.getYear());
    query.bindValue(":id", book.getId());


    if(!query.exec())
    {
        QSqlError error = query.lastError();
        QMessageBox dbErr(QMessageBox::Critical,
                          "Ошибка запроса",
                          error.text(),
                          QMessageBox::Ok);

        dbErr.exec();
    }
}

std::vector<Book> LibraryDB::getLikeBook(Book& like)
{
    QSqlQuery query;
    QString quer = "SELECT * FROM Book WHERE (Name LIKE \'%"+ like.getName() +"%\') AND (Author LIKE \'%" + like.getAuthor() + "%\') AND (ISBN LIKE \'%"+ like.getIsbn() +"%\') AND (Topics LIKE \'%"+ splitStrings(like.getTopics()) +"%\')";
    query.prepare(quer);
    query.exec();
    std::vector<Book> ret;

    while (query.next())
        ret.push_back(Book(query.value(0).toString(), query.value(1).toString(), query.value(2).toString(),
                           devideString(query.value(3).toString()), query.value(4).toString(),
                           query.value(5).toInt(), query.value(6).toInt()));

    return ret;
}

QString splitStrings(std::vector<QString> strs)
{
    QString ret;
    for (int i = 0; i < static_cast<int>(strs.size()); i++)
    {
        ret += strs[static_cast<unsigned int>(i)];
        if (i < static_cast<int>(strs.size()) - 1)
            ret += ", ";
    }

    return ret;
}

std::vector<QString> devideString(QString str)
{
    std::vector<QString> ret;
    QString buff;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ',' && ' ')
            buff += str[i];
        else if (buff.size() != 0)
        {
            ret.push_back(buff);
            buff.clear();
        }
    }

    if (buff.size() > 0)
        ret.push_back(buff);

    return ret;
}
