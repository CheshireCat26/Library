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

    if (exist(book))
    {
        showMessage("Эта книга уже добавлена в БД");
        return;
    }

    LibraryDB::insertBook(book);
    addAndShowInstences(countIns, book.getId());
    this->close();
}

Book AddBookWindow::getData(int &countInst)
{
    QString name = ui->lineEditName->text();
    QString author = ui->lineEditAuthor->text();
    QString isbn = ui->lineEditISBN->text();
    QString topics = ui->lineEditTopics->text();
    QString description = ui->textEditDescription->toPlainText();
    int year = ui->lineEditYear->text().toInt();
    countInst = ui->spinBox->value();
    int id = LibraryDB::getNewIDBook();

    qDebug() << topics;

    return Book(name, author, isbn, devideString(topics), description, year, id);
}

void AddBookWindow::addAndShowInstences(int count, int bookID)
{
    std::vector<unsigned int> ids = LibraryDB::addInstances(bookID, count);
    QString message = "Номера добавленных экзепляров книги: ";
    for (auto i : ids)
        message += '\n' + QString::number(i);

    showMessage(message);
}

bool AddBookWindow::exist(Book &book)
{
    std::vector<Book> b = LibraryDB::getLikeBook(book);
    if (b.size() == 0)
        return false;
    else
        return true;
}
