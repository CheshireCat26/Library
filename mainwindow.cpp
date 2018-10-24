#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addbookwindow.h"
#include "findbookwindow.h"

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
