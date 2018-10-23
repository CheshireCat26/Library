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

    QString name = ui->lineEditName->text();
    QString author = ui->lineEditAuthor->text();
    QString isbn = ui->lineEditISBN->text();
    QString topics = ui->lineEditTopics->text();
    QString desription = ui->lineEditDecrtiption->text();
    int year = ui->lineEditYear->text().toInt();
    int id;

    query.exec("SELECT MAX(ID) FROM Book");
    if (query.next())
        id = query.value(0).toInt() + 1;
    else
        id = 0;

    query.prepare("INSERT INTO Book (Name, Author, ISBN, Topics, Description, Year, ID) "
                  "VALUES (:name, :author, :isbn, :topics, "
                  ":desription, :year, :id)");
    query.bindValue(":name", name);
    query.bindValue(":author", author);
    query.bindValue(":isbn", isbn);
    query.bindValue(":topics", topics);
    query.bindValue(":desription", desription);
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
