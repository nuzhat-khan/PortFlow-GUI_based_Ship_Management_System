#include "guest_info.h"
#include "ui_guest_info.h"

guest_info::guest_info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::guest_info)
{
    ui->setupUi(this);
    ui-> stackedWidget->setCurrentIndex(0);
}

guest_info::~guest_info()
{
    delete ui;
}

void guest_info::on_back_button_clicked()
{
    emit login_page_clicked();
}

void guest_info::on_give_suggestions_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void guest_info::on_back_button_2_clicked()
{
    ui-> stackedWidget->setCurrentIndex(0);
}

void guest_info::on_submit_button_clicked()
{
    QString suggestion_input = ui->suggestion_lineEdit->text();
    QSqlQuery query;
    query.prepare("INSERT INTO guest_suggestion (suggestion) "
                  "VALUES (:suggestion)");
    query.bindValue(":suggestion", suggestion_input);

    if (query.exec())
    {
        QMessageBox::information(this, "Success", "Submitted successfully.");
        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        QMessageBox::critical(this, "Failed", query.lastError().text());
    }
    ui->suggestion_lineEdit->clear();
}

void guest_info::on_about_us_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void guest_info::on_back_button_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
