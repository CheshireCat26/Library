#include "findbookwindow.h"


FindBookWindow::FindBookWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FindBook)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList{"Автор", "Название", "Год издания"});
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
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(static_cast<int>(b.size()));
    int row{0};
    for (Book i : b)
    {
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(i.getAuthor()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(i.getName()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(i.getYear())));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(i.getId())));
        row++;
    }

    ui->tableWidget->setHorizontalHeaderLabels(QStringList{"Автор", "Название", "Год издания"});
}

void FindBookWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QTableWidgetItem *item = ui->tableWidget->item(row, 3);
    QString id = item->text();
    BookWindow *BW = new BookWindow(this, item->text().toInt());
    BW->show();
}
