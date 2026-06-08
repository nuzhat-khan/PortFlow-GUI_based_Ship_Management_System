#ifndef MANAGER_INFO_H
#define MANAGER_INFO_H

#include <QMessageBox>
#include <QDebug>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQueryModel>

namespace Ui {
class manager_info;
}

class manager_info : public QWidget
{
    Q_OBJECT

public:
    explicit manager_info(QWidget *parent = nullptr);
    ~manager_info();

private slots:
    void on_back_button_clicked();

    void on_login_button_clicked();

    void on_log_out_button_clicked();

    void on_add_operator_button_clicked();

    void on_remove_operator_button_clicked();

    void on_back_button_4_clicked();

    void on_change_manager_button_clicked();

    void on_back_button_5_clicked();

    void on_ok_change_button_clicked();

    void on_add_button_clicked();

    void on_load_operator_table_button_clicked();

    void on_remove_button_clicked();

    void on_back_button_2_clicked();

    void on_back_button_3_clicked();

    void on_back_button_6_clicked();

    void on_generate_report_button_clicked();

    void on_refresh_1_button_clicked();

    void on_refresh_2_button_clicked();

    void on_refresh_3_button_clicked();

    void on_refresh_4_button_clicked();

private:
    Ui::manager_info *ui;
    QString manager_login_email, manager_login_password;
    QString new_manager_email, new_manager_password;
    QString operator_name,operator_id,operator_password,operator_phone;
    void loadTable();
    void loadTable1();
    void loadTable2();
    void loadTable3();
    void loadTable4();
    QString remove_id;

signals:
void login_page_clicked();
};

#endif // MANAGER_INFO_H
