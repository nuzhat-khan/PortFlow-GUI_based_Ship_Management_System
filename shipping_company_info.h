#ifndef SHIPPING_COMPANY_INFO_H
#define SHIPPING_COMPANY_INFO_H

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
class shipping_company_info;
}

class shipping_company_info : public QWidget
{
    Q_OBJECT

public:
    explicit shipping_company_info(QWidget *parent = nullptr);
    ~shipping_company_info();

private slots:
    void on_login_button_clicked();

    void on_back_button_clicked();

    void on_signup_button_clicked();

    void on_ok_button_clicked();

    void on_back_button_2_clicked();

    void on_back_button_3_clicked();

    void on_create_shipment_button_clicked();

    void on_logout_button_clicked();

    void on_back_button_4_clicked();

    void on_enter_button_clicked();



    void on_refresh_button_clicked();

    void on_track_shipment_button_clicked();

    void on_back_button_5_clicked();

    void on_back_button_6_clicked();

    void on_feedback_button_clicked();

    void on_submit_button_clicked();

private:
    Ui::shipping_company_info *ui;
    QString login_email,login_password;
    QString signup_email,signup_password;
    QString ship_name,cargo_type,code,time;
    QString feedback_input;
    void loadTable();
    QSqlTableModel *model;

signals:
    void login_page_clicked();
};

#endif // SHIPPING_COMPANY_INFO_H
