#include "mainwindow.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>

static QSqlDatabase db;

int main(int argc, char *argv[])
{

    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL Server};SERVER=DESKTOP-L9PSBQ7\\MSSQLSERVER11;DATABASE=Library;Trusted_Connection=yes;");
    db.setUserName("DESKTOP-L9PSBQ7\\nail1");
    if (!db.open())
    {
        QMessageBox dbErr(QMessageBox::Critical,
                          "Ошибка подключения",
                          "Не удалось подключаится к базе данных Library",
                          QMessageBox::Ok);

        dbErr.exec();
        return 1;
     }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
