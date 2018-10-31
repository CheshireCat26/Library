#include "addbookwindow.h"
#include "ui_addbookwindow.h"

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
    int countIns;
    Book book = getData(countIns);
    LibraryDB::insertBook(book);
    addAndShowInstences(countIns, book.getId());
    this->close();
}

Book AddBookWindow::getData(int &countInst)
{
    QSqlQuery query;

    QString name = ui->lineEditName->text();
    QString author = ui->lineEditAuthor->text();
    QString isbn = ui->lineEditISBN->text();
    QString topics = ui->lineEditTopics->text();
    QString description = ui->textEditDescription->toPlainText();
    int year = ui->lineEditYear->text().toInt();
    countInst = ui->spinBox->value();
    int id;
    query.exec("SELECT MAX(ID) FROM Book");
    if (query.next())
        id = query.value(0).toInt() + 1;
    else
        id = 0;

    qDebug() << topics;

    return Book(name, author, isbn, devideString(topics), description, year, id);
}

void AddBookWindow::addAndShowInstences(int count, int bookID)
{
    std::vector<unsigned int> ids = LibraryDB::addInstances(bookID, count);
    QString message = "Номера добавленных экзепляров книги: ";
    for (auto i : ids)
        message += '\n' + QString::number(i);

    QMessageBox MB;
    MB.setText(message);
    MB.exec();
}
