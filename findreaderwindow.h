#ifndef FINDREADERWINDOW_H
#define FINDREADERWINDOW_H

#include <QMainWindow>
#include "librarydb.h"
#include "readerwindow.h"

namespace Ui {
class FindReaderWindow;
}

class FindReaderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FindReaderWindow(QWidget *parent = nullptr);
    ~FindReaderWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FindReaderWindow *ui;
};

#endif // FINDREADERWINDOW_H
