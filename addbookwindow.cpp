#include "addbookwindow.h"
#include "ui_addbookwindow.h"
#include "utility.h"
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <vector>

AddBookWindow::AddBookWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddBookWindow)
{
    ui->setupUi(this);
}

AddBookWindow::~AddBookWindow()
{
    delete ui;
}

void AddBookWindow::on_pushButtonAdd_clicked()
{
    Book book = getData();
    AddBookInDB(book);
    this->close();
}

Book AddBookWindow::getData()
{
    QSqlQuery query;

    QString name = ui->lineEditName->text();
    QString author = ui->lineEditAuthor->text();
    QString isbn = ui->lineEditISBN->text();
    QString topics = ui->lineEditTopics->text();
    QString description = ui->textEditDescription->toPlainText();
    int year = ui->lineEditYear->text().toInt();
    int id;
    query.exec("SELECT MAX(ID) FROM Book");
    if (query.next())
        id = query.value(0).toInt() + 1;
    else
        id = 0;

    return Book(name, author, isbn, devideString(topics), description, year, id);
}

void  AddBookWindow::AddBookInDB (Book& book)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Book (Name, Author, ISBN, Topics, Description, Year, ID) "
                  "VALUES (:name, :author, :isbn, :topics, "
                  ":description, :year, :id)");
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
