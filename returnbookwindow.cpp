#include "returnbookwindow.h"
#include "ui_returnbookwindow.h"

ReturnBookWindow::ReturnBookWindow(int pIdReader, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReturnBookWindow),
    idReader{pIdReader}
{
    ui->setupUi(this);
    fillList();
}

ReturnBookWindow::~ReturnBookWindow()
{
    delete ui;
}

void ReturnBookWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    LibraryDB::returnBook(item->text().toInt());
    showMessage("Книга возвращена");
    ui->listWidget->clear();
    fillList();
}

void ReturnBookWindow::fillList()
{
    std::vector<int> ids = LibraryDB::getIdTakenInstances(idReader);
    for (int i : ids)
    {
        ui->listWidget->addItem(QString::number(i));
    }
}
