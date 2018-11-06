#ifndef RETURNBOOKWINDOW_H
#define RETURNBOOKWINDOW_H

#include <QMainWindow>
#include <vector>
#include "librarydb.h"
#include <QString>
#include <QListWidgetItem>

namespace Ui {
class ReturnBookWindow;
}

class ReturnBookWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReturnBookWindow(int pIdReader, QWidget *parent = nullptr);
    ~ReturnBookWindow();

private slots:

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::ReturnBookWindow *ui;
    int idReader;
    void fillList();
};

#endif // RETURNBOOKWINDOW_H
