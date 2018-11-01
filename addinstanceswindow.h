#ifndef ADDINSTANCESWINDOW_H
#define ADDINSTANCESWINDOW_H

#include <QMainWindow>
#include "librarydb.h"
#include <vector>
#include <QMessageBox>
#include <QString>

namespace Ui {
class AddInstancesWindow;
}

class AddInstancesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddInstancesWindow(QWidget *parent = nullptr, int id = -1);
    ~AddInstancesWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddInstancesWindow *ui;
    int idBook;
};

#endif // ADDINSTANCESWINDOW_H
