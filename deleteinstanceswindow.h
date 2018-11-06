#ifndef DELETEINSTANCESWINDOW_H
#define DELETEINSTANCESWINDOW_H

#include <QMainWindow>
#include <vector>
#include "librarydb.h"
#include <QString>
#include <QListWidgetItem>

namespace Ui {
class DeleteInstancesWindow;
}

class DeleteInstancesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteInstancesWindow(int pIdBook,QWidget *parent = nullptr);
    ~DeleteInstancesWindow();

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::DeleteInstancesWindow *ui;
    int idBook;

    void fillList();
};

#endif // DELETEINSTANCESWINDOW_H
