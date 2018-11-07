#include "findreaderwindow.h"
#include "ui_findreaderwindow.h"

FindReaderWindow::FindReaderWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FindReaderWindow)
{
    ui->setupUi(this);
}

FindReaderWindow::~FindReaderWindow()
{
    delete ui;
}

void FindReaderWindow::on_pushButton_clicked()
{
    int id = ui->lineEdit->text().toInt();
    Reader reader = LibraryDB::getReader(id);

    if(reader.getId() != -1)
    {
        ReaderWindow *RW = new ReaderWindow(reader, this);
        RW->show();
    }
    else
        showMessage("Читатель не найден");
}
