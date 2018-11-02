#ifndef ADDBOOKWINDOW_H
#define ADDBOOKWINDOW_H

#include <QMainWindow>
#include "book.h"
#include "librarydb.h"
#include <QString>
#include <QMessageBox>
#include <vector>
#include <QDebug>

namespace Ui {
class AddBookWindow;
}

class AddBookWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddBookWindow(QWidget *parent = nullptr);
    ~AddBookWindow();

private slots:
    void on_pushButtonAdd_clicked();

private:
    Ui::AddBookWindow *ui;

    Book getData(int &countInst);
    void addAndShowInstences(int count, int bookID);
    bool exist(Book& book);
};

#endif // ADDBOOKWINDOW_H
