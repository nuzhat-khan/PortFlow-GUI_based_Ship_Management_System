#ifndef OPERATOR_INFO_H
#define OPERATOR_INFO_H

#include <QMessageBox>
#include <QDebug>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QTimeEdit>
#include <QSqlTableModel>

namespace Ui {
class operator_info;
}

class operator_info : public QWidget
{
    Q_OBJECT

public:
    explicit operator_info(QWidget *parent = nullptr);
    ~operator_info();

private slots:
    void on_back_button_clicked();

    void on_login_button_clicked();

    void on_logout_button_clicked();

    void on_loaded_shipments_button_clicked();

    void on_view_shipment_status_clicked();

    void on_enter_button_clicked();

    void on_back_button_2_clicked();



    void on_refresh_button_clicked();

    void on_back_button_3_clicked();

    void on_back_button_4_clicked();

    void on_update_cargo_status_button_clicked();

    void on_back_button_9_clicked();

    void on_refresh_button_3_clicked();

    void on_update_button_clicked();

    void on_back_button_10_clicked();

    void on_review_feedback_button_clicked();

    void on_refresh_button_4_clicked();
    void on_refresh_button_5_clicked();

    void on_solve_button_1_clicked();

    void on_solve_button_2_clicked();

private:
    Ui::operator_info *ui;
    QString operator_login_id, operator_login_password;
    QString ship_name,ship_no,cargo_type,time,status;
    QString remove_id;
    QString cargo_status,code;
    void loadTable();
    void loadTable2();
    void loadTable3();
    void loadTable4();
    QSqlTableModel *model;


signals:
void login_page_clicked();
};

#endif // OPERATOR_INFO_H
