#ifndef ADDBOOKWINDOW_H
#define ADDBOOKWINDOW_H

#include <QMainWindow>
#include <book.h>

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

    Book getData();
};

#endif // ADDBOOKWINDOW_H
