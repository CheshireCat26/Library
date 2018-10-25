#ifndef FINDBOOK_H
#define FINDBOOK_H

#include <QMainWindow>
#include <book.h>
#include <vector>

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

private:
    Ui::FindBook *ui;
    Book searchBook;

    void FindBookAndDisplay();
    std::vector<Book> FindBook();
    void DisplayBook(std::vector<Book> b);
};

#endif // FINDBOOK_H
