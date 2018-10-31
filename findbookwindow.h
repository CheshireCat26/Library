#ifndef FINDBOOK_H
#define FINDBOOK_H

#include "bookwindow.h"
#include "ui_findbookwindow.h"
#include "librarydb.h"
#include "book.h"
#include <QMainWindow>
#include <vector>
#include <QListWidgetItem>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QStringList>


namespace Ui {
class FindBook;
}

class FindBookWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FindBookWindow(QWidget *parent = nullptr);
    ~FindBookWindow();

private slots:
    void on_lineEditName_textChanged(const QString &arg1);

    void on_lineEditAuthor_textChanged(const QString &arg1);
    void on_lineEditIsbn_textChanged(const QString &arg1);

    void on_lineEditTopics_textChanged(const QString &arg1);

    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::FindBook *ui;
    Book searchBook;

    void FindBookAndDisplay();
    void DisplayBook(std::vector<Book> b);
};

#endif // FINDBOOK_H
