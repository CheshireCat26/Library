#include "readerwindow.h"
#include "ui_readerwindow.h"

ReaderWindow::ReaderWindow(Reader pReader, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReaderWindow),
    reader{pReader}
{
    ui->setupUi(this);
    ui->labelName->setText("Имя: " + reader.getName());
    ui->labelSurName->setText("Фамилия: " + reader.getSurName());
    ui->labelPatronymic->setText("Отчество: " + reader.getPatronymic());
    ui->labelPhoneNumber->setText("Номер телефона: " + reader.getPhoneNumber());
    ui->labelEmail->setText("Email: " + reader.getEmail());
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
