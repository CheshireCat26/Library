#include "givebookwindow.h"
#include "ui_givebookwindow.h"
#include <QString>

GiveBookWindow::GiveBookWindow(int pIdBook, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GiveBookWindow),
    idBook{pIdBook}
{
    ui->setupUi(this);
}

GiveBookWindow::~GiveBookWindow()
{
    delete ui;
}

void GiveBookWindow::on_pushButton_clicked()
{
    int idReader = ui->lineEditIdReader->text().toInt();
    Reader reader = LibraryDB::getReader(idReader);
    if (reader.getId() != -1)
    {
        QDate date = ui->dateEditReturn->date();

        int idInstance = LibraryDB::getFreeInstatnce(idBook);
        if (idInstance != -1)
        {
            LibraryDB::giveBook(idInstance, idReader, date);
            showMessage("Книга успешно выдана\n ID выданного экземпляра: "
                        + QString::number(idInstance));
        }
        else
            showMessage("Нет свободного экземпляра книги");
    }
    else
        showMessage("Не найдено читателя с данным ID");
}
