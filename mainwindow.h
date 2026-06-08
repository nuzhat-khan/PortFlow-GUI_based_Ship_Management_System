#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMainWindow>
#include <manager_info.h>
#include <operator_info.h>
#include <shipping_company_info.h>
#include <guest_info.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_get_started_button_clicked();
    void on_back_button_clicked();
    void on_next_button_clicked();
    void move_login_page();

private:
    Ui::MainWindow *ui;
    manager_info manage;
    operator_info operate;
    shipping_company_info company;
    guest_info guest;
    QSqlDatabase db;
};
#endif // MAINWINDOW_H
