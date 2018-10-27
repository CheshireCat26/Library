#ifndef BOOKWINDOW_H
#define BOOKWINDOW_H

#include <QMainWindow>

namespace Ui {
class BookWindow;
}

class BookWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookWindow(QWidget *parent = nullptr);
    ~BookWindow();

private:
    Ui::BookWindow *ui;
};

#endif // BOOKWINDOW_H
