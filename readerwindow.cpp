#include "readerwindow.h"
#include "ui_readerwindow.h"

ReaderWindow::ReaderWindow(Reader pReader, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReaderWindow),
    reader{pReader}
{
    ui->setupUi(this);
    construct();
}

ReaderWindow::~ReaderWindow()
{
    delete ui;
}

void ReaderWindow::on_pushButton_2_clicked()
{
    ReturnBookWindow *RBW = new ReturnBookWindow(reader.getId(), this);
    RBW->show();
}

void ReaderWindow::construct()
{
    reader = LibraryDB::getReader(reader.getId());
    ui->labelName->setText("Имя: " + reader.getName());
    ui->labelSurName->setText("Фамилия: " + reader.getSurName());
    ui->labelPatronymic->setText("Отчество: " + reader.getPatronymic());
    ui->labelPhoneNumber->setText("Номер телефона: " + reader.getPhoneNumber());
    ui->labelEmail->setText("Email: " + reader.getEmail());
    ui->radioButtonUnwanted->setChecked(reader.getUnwanted());

    if(reader.getUnwanted())
    {
        ui->labelUnwanted->setStyleSheet("color : red");
        ui->labelUnwanted->setText(tr("<font size=24>Нежелательный читатель</font>"));
    }
    else
    {
        ui->labelUnwanted->setText("");
    }
}

void ReaderWindow::on_radioButtonUnwanted_clicked()
{
    LibraryDB::changeUnwanted(reader.getId());
    construct();
}

void ReaderWindow::on_pushButton_clicked()
{
    LibraryDB::deleteReader(reader.getId());
    showMessage("Читатель удален");
    this->close();
}
