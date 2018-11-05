#ifndef GIVEBOOKWINDOW_H
#define GIVEBOOKWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QMessageBox>
#include "librarydb.h"

namespace Ui {
class GiveBookWindow;
}

class GiveBookWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GiveBookWindow(int pIdBook, QWidget *parent = nullptr);
    ~GiveBookWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GiveBookWindow *ui;
    int idBook;
};

#endif // GIVEBOOKWINDOW_H
