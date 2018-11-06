#include "addinstanceswindow.h"
#include "ui_addinstanceswindow.h"

AddInstancesWindow::AddInstancesWindow(QWidget *parent, int id) :
    QMainWindow(parent),
    ui(new Ui::AddInstancesWindow), idBook{id}
{
    ui->setupUi(this);
}

AddInstancesWindow::~AddInstancesWindow()
{
    delete ui;
}

void AddInstancesWindow::on_pushButton_clicked()
{
    std::vector<unsigned int> ids = LibraryDB::addInstances(idBook, ui->spinBox->value());


    QString mess = "ID добавленных экземпляров: ";
    for (auto i : ids)
        mess += "\n" + QString::number(i);
    showMessage(mess);
}
