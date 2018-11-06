#include "deleteinstanceswindow.h"
#include "ui_deleteinstanceswindow.h"

DeleteInstancesWindow::DeleteInstancesWindow(int pIdBook, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteInstancesWindow),
    idBook{pIdBook}
{
    ui->setupUi(this);
    fillList();
}

DeleteInstancesWindow::~DeleteInstancesWindow()
{
    delete ui;
}

void DeleteInstancesWindow::fillList()
{
    std::vector<int> ids = LibraryDB::getIdInstancesBook(idBook);
    for (int i : ids)
        ui->listWidget->addItem(QString::number(i));
}

void DeleteInstancesWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    LibraryDB::deleteInstance(item->text().toInt());
    showMessage("Успешное удаление");

    ui->listWidget->clear();
    fillList();
}
