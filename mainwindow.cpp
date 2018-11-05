#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    AddBookWindow *ABW = new AddBookWindow(this);
    ABW->show();
}

void MainWindow::on_pushButton_clicked()
{
    FindBookWindow *FBW = new FindBookWindow(this);
    FBW->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    AddReaderWindow *ARW = new AddReaderWindow(this);
    ARW->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    FindReaderWindow *FRW = new FindReaderWindow(this);
    FRW->show();
}
