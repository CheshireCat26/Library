#include "addreaderwindow.h"
#include "ui_addreaderwindow.h"

AddReaderWindow::AddReaderWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddReaderWindow)
{
    ui->setupUi(this);
}

AddReaderWindow::~AddReaderWindow()
{
    delete ui;
}

void AddReaderWindow::on_pushButton_clicked()
{
    Reader addReader = getDate();
    if (!exist(addReader))
        LibraryDB::insertReader(addReader);
    else
        showMessage("Уже существует читатель с данным email");

    this->close();
}

Reader AddReaderWindow::getDate()
{
    QString name = ui->lineEditName->text();
    QString surname = ui->lineEditlSurname->text();
    QString patronimyc = ui->lineEditPatronimyc->text();
    QString phoneNumber = ui->lineEditPhoneNumber->text();
    QString email = ui->lineEditEmail->text();
    int id = LibraryDB::getNewIDReader();
    return Reader(name, surname, patronimyc, phoneNumber, email, id, false);
}

bool AddReaderWindow::exist(Reader reader)
{
    if (LibraryDB::getReader(reader.getEmail()).getId() == -1)
        return false;
    else
        return true;
}
