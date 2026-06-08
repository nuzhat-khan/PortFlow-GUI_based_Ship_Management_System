#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Nuzhat Khan/Documents/Qt_Projects/PortFlow/DATABASE/portflow_db.db");

    if (!db.open()) {
        qDebug() << "DB Open Failed:" << db.lastError().text();
    }

    return a.exec();
}
