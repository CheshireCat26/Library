#include "findbookwindow.h"
#include "ui_findbookwindow.h"
#include "utility.h"
#include <QtSql/QSqlQuery>
#include <vector>
#include "book.h"
#include <QDebug>

FindBookWindow::FindBookWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FindBook)
{
    ui->setupUi(this);
}

FindBookWindow::~FindBookWindow()
{
    delete ui;
}

void FindBookWindow::on_lineEditName_textChanged(const QString &arg1)
{
    searchBook.setName(arg1);
    FindBookAndDisplay();
}

void FindBookWindow::on_lineEditAuthor_textChanged(const QString &arg1)
{
    searchBook.setAuthor(arg1);
    FindBookAndDisplay();
}

void FindBookWindow::on_lineEditIsbn_textChanged(const QString &arg1)
{
    searchBook.setIsbn(arg1);
    FindBookAndDisplay();
}

void FindBookWindow::on_lineEditTopics_textChanged(const QString &arg1)
{
    searchBook.setTopics(devideString(arg1));
    FindBookAndDisplay();
}

void FindBookWindow::FindBookAndDisplay()
{
    std::vector<Book> books = FindBook();

    for (auto debug : books)
        qDebug() << debug.getName() << '\n';

    DisplayBook(books);
}

std::vector<Book> FindBookWindow::FindBook()
{
    QSqlQuery query;
    QString quer = "SELECT * FROM Book WHERE (Name LIKE \'%"+ searchBook.getName() +"%\') AND (Author LIKE \'%" + searchBook.getAuthor() + "%\') AND (ISBN LIKE \'%"+ searchBook.getIsbn() +"%\') AND (Topics LIKE \'%"+ splitStrings(searchBook.getTopics()) +"%\')";
    query.prepare(quer);
    query.exec();
    std::vector<Book> ret;

    while (query.next())
        ret.push_back(Book(query.value(0).toString(), query.value(1).toString(), query.value(2).toString(),
                           devideString(query.value(3).toString()), query.value(4).toString(),
                           query.value(5).toInt(), query.value(6).toInt()));

    return ret;
}

void FindBookWindow::DisplayBook(std::vector<Book> b)
{
    ui->listWidget->clear();
    for (Book i : b)
        ui->listWidget->addItem(i.getAuthor() + ". " + i.getName());
}
