#include "addbookwindow.h"
#include "ui_addbookwindow.h"
#include "librarydb.h"
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <vector>
#include <QDebug>

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
    LibraryDB::InsterBook(book);
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

    qDebug() << topics;

    return Book(name, author, isbn, devideString(topics), description, year, id);
}
