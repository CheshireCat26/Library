#ifndef ADDBOOKWINDOW_H
#define ADDBOOKWINDOW_H

#include <QMainWindow>

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


    void getData(QString& name, QString& author, QString& isbn,
                 QString& topics, QString& description, int& year,
                 int& id);
    void sentDataToDB(QString& name, QString& author, QString& isbn,
                 QString& topics, QString& description, int& year,
                 int& id);
};

#endif // ADDBOOKWINDOW_H
