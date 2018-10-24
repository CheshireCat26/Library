#include "findbookwindow.h"
#include "ui_findbookwindow.h"
#include "utility.h"
#include <QtSql/QSqlQuery>

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
    FindBook();
}

void FindBookWindow::on_lineEditAuthor_textChanged(const QString &arg1)
{
    searchBook.setAuthor(arg1);
    FindBook();
}

void FindBookWindow::on_lineEditIsbn_textChanged(const QString &arg1)
{
    searchBook.setIsbn(arg1);
    FindBook();
}

void FindBookWindow::on_lineEditTopics_textChanged(const QString &arg1)
{
    searchBook.setTopics(devideString(arg1));
    FindBook();
}

void FindBookWindow::FindBook()
{
    QSqlQuery query;
}
