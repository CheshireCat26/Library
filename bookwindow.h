#ifndef BOOKWINDOW_H
#define BOOKWINDOW_H

#include "book.h"
#include "librarydb.h"
#include "addinstanceswindow.h"
#include "givebookwindow.h"
#include <QMainWindow>
#include <QString>

namespace Ui {
class BookWindow;
}

class BookWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookWindow(QWidget *parent = nullptr, int bookID = -1);
    ~BookWindow();

private slots:
    void on_pushButtonAddInstance_clicked();

    void on_pushButtonGiveBook_clicked();

private:
    Ui::BookWindow *ui;
    Book book;
};

#endif // BOOKWINDOW_H
