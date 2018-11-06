#include "bookwindow.h"
#include "ui_bookwindow.h"

BookWindow::BookWindow(QWidget *parent, int bookID) :
    QMainWindow(parent),
    ui(new Ui::BookWindow)
{
    ui->setupUi(this);
    book = LibraryDB::getBook(bookID);

    ui->labelName->setText(book.getName());
    ui->labelAuthor->setText(book.getAuthor());
    ui->labelTopics->setText("Жанры: " + splitStrings(book.getTopics()));
    ui->textDecription->setReadOnly(true);
    ui->textDecription->setDocument(new QTextDocument(book.getDescription()));
}

BookWindow::~BookWindow()
{
    delete ui;
}

void BookWindow::on_pushButtonAddInstance_clicked()
{
    AddInstancesWindow *AIW = new AddInstancesWindow(this, book.getId());
    AIW->show();
}

void BookWindow::on_pushButtonGiveBook_clicked()
{
    GiveBookWindow *GBW = new GiveBookWindow(book.getId(), this);
    GBW->show();
}

void BookWindow::on_pushButton_2_clicked()
{
    DeleteInstancesWindow *DIW = new DeleteInstancesWindow(book.getId(), this);
    DIW->show();
}
