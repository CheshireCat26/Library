#include "librarydb.h"
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QString>
#include <QVariant>
#include "QDebug"

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

Book LibraryDB::getBook(int id)
{
    QSqlQuery query;
    query.exec("SELECT * FROM Book WHERE ID =" + QString::number(id));
    query.next();
    return Book(query.value(0).toString(), query.value(1).toString(), query.value(2).toString(),
                devideString(query.value(3).toString()), query.value(4).toString(),
                query.value(5).toInt(), id);
}

void LibraryDB::insertBook(Book& book)
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

int LibraryDB::getNewIDBook()
{
    QSqlQuery query;
    query.exec("SELECT MAX(ID) FROM Book");
    return getNewID(query);
}

std::vector<unsigned int> LibraryDB::addInstances(int bookID, int number)
{
    int count = 0;
    std::vector<unsigned int> ids;
    for (unsigned int i = 0; i < pow(2, 32) && count < number; i++)
    {
        QSqlQuery query;
        query.exec("SELECT ID FROM Instance WHERE ID = " + QString::number(i));
        if (query.next())
            continue;

        query.prepare("INSERT INTO Instance (ID, ID_Book) VALUES(?, ?)");
        query.addBindValue(QString::number(i));
        query.addBindValue(QString::number(bookID));
        query.exec();

        count++;
        ids.push_back(i);
    }

    return ids;
}

int LibraryDB::getNewID(QSqlQuery &query)
{
    if (query.next())
        return query.value(0).toInt() + 1;
    else
        return 0;
}

Reader LibraryDB::getReader(int id)
{
    QSqlQuery query;
    query.exec("SELECT * FROM Reader WHERE ID =" + QString::number(id));
    if(query.next())
    {
        return Reader(query.value(0).toString(), query.value(1).toString(),
                      query.value(2).toString(), query.value(3).toString(),
                      query.value(4).toString(), id, query.value(6).toBool());
    }
    else
    {
        return Reader();
    }

}

Reader LibraryDB::getReader(QString email)
{
    QSqlQuery query;
    query.exec("SELECT * FROM Reader WHERE Email LIKE \'"+ email + "\'");
    if (query.next())
        return Reader(query.value(0).toString(), query.value(1).toString(),
                      query.value(2).toString(), query.value(3).toString(),
                      email, query.value(5).toInt(), query.value(6).toBool());
    else
        return Reader();

}

void LibraryDB::insertReader(Reader &reader)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Reader (Name, Surname, Patronymic, [Phone number], Email, ID, Unwanted) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(reader.getName());
    query.addBindValue(reader.getSurName());
    query.addBindValue(reader.getPatronymic());
    query.addBindValue(reader.getPhoneNumber());
    query.addBindValue(reader.getEmail());
    query.addBindValue(reader.getId());
    query.addBindValue(reader.getUnwanted());
    query.exec();
}

int LibraryDB::getNewIDReader()
{
    QSqlQuery query;
    query.exec("SELECT MAX(ID) FROM Reader");
    return getNewID(query);
}

void LibraryDB::changeUnwanted(int idReader)
{
    QSqlQuery query;
    Reader reader = getReader(idReader);
    if (reader.getUnwanted())
        query.exec("UPDATE Reader SET Unwanted=0");
    else
       query.exec("UPDATE Reader SET Unwanted=1");
}

void LibraryDB::deleteBook(int idBook)
{
    deleteAllBookInstances(idBook);

    QSqlQuery query;
    query.exec("DELETE FROM Book WHERE ID=" + QString::number(idBook));
}

int LibraryDB::getFreeInstatnce(int idBook)
{
    QSqlQuery query;
    query.exec("SELECT ID FROM Instance WHERE ID_Book = " + QString::number(idBook) +" AND ID_Reader IS NULL ");
    if (query.next())
    {
        return query.value(0).toInt();
    }
    else
        return -1;
}

void LibraryDB::giveBook(int idInstance, int idReader, QDate dateReturn)
{
    QSqlQuery query;
    query.exec("UPDATE Instance SET ID_Reader=" + QString::number(idReader) +
               ",[Date give]=\'" + QDate::currentDate().toString("dd.MM.yyyy") +
               "\',[Date return]=\'" + dateReturn.toString("dd.MM.yyyy") +
               "\'WHERE ID=" + QString::number(idInstance));
}

std::vector<int> LibraryDB::getIdTakenInstances(int idReader)
{
    QSqlQuery query;
    query.exec("SELECT ID FROM Instance WHERE ID_Reader=" + QString::number(idReader));

    std::vector<int> ids;
    while(query.next())
        ids.push_back(query.value(0).toInt());

    return ids;
}

void LibraryDB::returnBook(int idInstance)
{
    QSqlQuery query;
    query.exec("UPDATE Instance SET ID_Reader=NULL,[Date give]=NULL,[Date return]=NULL WHERE ID=" + QString::number(idInstance));
}

void LibraryDB::deleteReader(int idReader)
{
    freeAllInstances(idReader);

    QSqlQuery query;
    query.exec("DELETE FROM Reader WHERE ID=" + QString::number(idReader));
}

void LibraryDB::freeAllInstances(int idReader)
{
    QSqlQuery query;
    query.exec("UPDATE Instance SET ID_Reader=NULL,[Date give]=NULL,[Date return]=NULL WHERE ID_Reader=" + QString::number(idReader));
}

std::vector<int> LibraryDB::getIdInstancesBook(int idBook)
{
    QSqlQuery query;
    query.exec("SELECT ID FROM Instance WHERE ID_Book=" + QString::number(idBook));

    std::vector<int> ids;
    while(query.next())
        ids.push_back(query.value(0).toInt());

    return ids;
}

void LibraryDB::deleteInstance(int idInstance)
{
    QSqlQuery query;
    query.exec("DELETE FROM Instance WHERE ID=" + QString::number(idInstance));
}

void LibraryDB::deleteAllBookInstances(int idBook)
{
    QSqlQuery query;
    query.exec("DELETE FROM Instance WHERE ID_Book=" + QString::number(idBook));
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

void showMessage(QString message)
{
    QMessageBox MB;
    MB.setText(message);
    MB.exec();
}
