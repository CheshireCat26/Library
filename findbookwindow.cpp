#include "findbookwindow.h"
#include "ui_findbookwindow.h"
#include "librarydb.h"
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
    std::vector<Book> books = LibraryDB::getLikeBook(searchBook);
    DisplayBook(books);
}

void FindBookWindow::DisplayBook(std::vector<Book> b)
{
    ui->listWidget->clear();
    for (Book i : b)
        ui->listWidget->addItem(i.getAuthor() + ". " + i.getName());
}
