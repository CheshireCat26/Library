#include "bookwindow.h"
#include "ui_bookwindow.h"

BookWindow::BookWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BookWindow)
{
    ui->setupUi(this);
}

BookWindow::~BookWindow()
{
    delete ui;
}
