#ifndef ADDREADERWINDOW_H
#define ADDREADERWINDOW_H

#include <QMainWindow>
#include "reader.h"
#include "librarydb.h"

namespace Ui {
class AddReaderWindow;
}

class AddReaderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddReaderWindow(QWidget *parent = nullptr);
    ~AddReaderWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddReaderWindow *ui;
    Reader getDate();
    bool exist(Reader reader);
};

#endif // ADDREADERWINDOW_H
