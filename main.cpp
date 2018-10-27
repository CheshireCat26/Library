#include "mainwindow.h"
#include "librarydb.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    LibraryDB::Connect();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
