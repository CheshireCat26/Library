#include "addbookwindow.h"
#include "ui_addbookwindow.h"
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>

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
    QSqlQuery query;

    QString name, author, isbn, topics, description;
    int year, id;
    getData(name, author, isbn, topics, description, year, id);


}

void AddBookWindow::getData(QString& name, QString& author, QString& isbn,
                            QString& topics, QString& description, int& year,
                            int& id)
{
    QSqlQuery query;

    name = ui->lineEditName->text();
    author = ui->lineEditAuthor->text();
    isbn = ui->lineEditISBN->text();
    topics = ui->lineEditTopics->text();
    description = ui->lineEditDecrtiption->text();
    year = ui->lineEditYear->text().toInt();

    query.exec("SELECT MAX(ID) FROM Book");
    if (query.next())
        id = query.value(0).toInt() + 1;
    else
        id = 0;
}

void  AddBookWindow::sentDataToDB (QString& name, QString& author, QString& isbn,
                                   QString& topics, QString& description, int& year,
                                   int& id)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Book (Name, Author, ISBN, Topics, Description, Year, ID) "
                  "VALUES (:name, :author, :isbn, :topics, "
                  ":description, :year, :id)");
    query.bindValue(":name", name);
    query.bindValue(":author", author);
    query.bindValue(":isbn", isbn);
    query.bindValue(":topics", topics);
    query.bindValue(":description", description);
    query.bindValue(":year", year);
    query.bindValue(":id", id);
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
