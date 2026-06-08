#ifndef GUEST_INFO_H
#define GUEST_INFO_H

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
class guest_info;
}

class guest_info : public QWidget
{
    Q_OBJECT

public:
    explicit guest_info(QWidget *parent = nullptr);
    ~guest_info();

private slots:

    void on_back_button_clicked();

    void on_give_suggestions_button_clicked();

    void on_back_button_2_clicked();

    void on_submit_button_clicked();

    void on_about_us_button_clicked();

    void on_back_button_3_clicked();

private:
    Ui::guest_info *ui;

signals:
    void login_page_clicked();
};

#endif // GUEST_INFO_H
