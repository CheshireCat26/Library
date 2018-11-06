#ifndef READERWINDOW_H
#define READERWINDOW_H

#include <QMainWindow>
#include "reader.h"
#include "returnbookwindow.h"

namespace Ui {
class ReaderWindow;
}

class ReaderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReaderWindow(Reader pReader, QWidget *parent = nullptr);
    ~ReaderWindow();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::ReaderWindow *ui;
    Reader reader;
};

#endif // READERWINDOW_H
