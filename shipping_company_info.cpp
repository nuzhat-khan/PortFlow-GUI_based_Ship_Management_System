#include "shipping_company_info.h"
#include "ui_shipping_company_info.h"

shipping_company_info::shipping_company_info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shipping_company_info)
{
    ui->setupUi(this);
    ui-> stackedWidget->setCurrentIndex(0);
}

shipping_company_info::~shipping_company_info()
{
    delete ui;
}

void shipping_company_info::on_login_button_clicked()
{
    login_email = ui-> login_email_input->text();
    login_password = ui-> login_password_input -> text();

    QSqlQuery query;
    query.prepare("SELECT * FROM shipping_company_account WHERE email = :email AND password = :password");
    query.bindValue(":email", login_email);
    query.bindValue(":password", login_password);

    if (query.exec() && query.next()) {
        QMessageBox::information(this, "Log in", "Successfully logged in");
        ui->stackedWidget->setCurrentIndex(2);
    } else {
        QMessageBox::warning(this, "Log in failed!", "Please try again.");
    }
    ui->login_email_input->clear();
    ui->login_password_input->clear();
    ui-> company_name_input -> setText(login_email);
    ui-> company_name_label -> setText(login_email);
}

void shipping_company_info::on_back_button_clicked()
{
    emit login_page_clicked();
}

void shipping_company_info::on_signup_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void shipping_company_info::on_ok_button_clicked()
{
   signup_email= ui-> signup_email_input -> text();
   signup_password= ui-> signup_password_input -> text();


        QSqlQuery query;
        query.prepare("INSERT INTO shipping_company_account (email,password)"
                      "VALUES (:email, :password)");

        query.bindValue(":email", signup_email);
        query.bindValue(":password", signup_password);

        if (query.exec())
        {
            QMessageBox::information(this, "Sign Up", "Account created successfully.");
            ui->stackedWidget->setCurrentIndex(0);
        }
        else
        {
            QMessageBox::critical(this, "Failed", "Account already exists");
        }

        ui->signup_email_input->clear();
        ui->signup_password_input->clear();

}

void shipping_company_info::on_back_button_2_clicked()
{
    ui-> stackedWidget -> setCurrentIndex(0);
}

void shipping_company_info::on_back_button_3_clicked()
{
    ui-> stackedWidget -> setCurrentIndex(0);
}

void shipping_company_info::on_create_shipment_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void shipping_company_info::on_logout_button_clicked()
{
    emit login_page_clicked();
    ui->stackedWidget->setCurrentIndex(0);
}

void shipping_company_info::on_back_button_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void shipping_company_info::on_enter_button_clicked()
{
    ship_name= login_email;
    cargo_type= ui-> cargo_type_input -> text();
    code=ui->code_input->text();
    time = ui->time_input->time().toString("h:mm AP");


    QSqlQuery query;
    query.prepare("INSERT INTO cargo_info (name, code, time, destination)"
                  "VALUES (:name, :code, :time, :destination)");

    query.bindValue(":name", ship_name);
    query.bindValue(":code", code);
    query.bindValue(":time", time);
    query.bindValue(":destination", cargo_type);
    if (query.exec())
    {
        QMessageBox::information(this, "Success", "Entered successfully.");
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        QMessageBox::critical(this, "Failed", query.lastError().text());
    }

    ui->code_input->clear();
    ui->cargo_type_input->clear();
    ui->time_input->setTime(QTime(0,0));
}

void shipping_company_info::loadTable()
{
    QString name = login_email;
    model->setFilter(QString("name = '%1'").arg(name));
    model->select();
}

void shipping_company_info::on_refresh_button_clicked()
{
    model = new QSqlTableModel(this);
    model->setTable("cargo_info");
    model->select();

    ui->tableView_track->setModel(model);
    ui->tableView_track->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    loadTable();
}

void shipping_company_info::on_track_shipment_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void shipping_company_info::on_back_button_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void shipping_company_info::on_back_button_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void shipping_company_info::on_feedback_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void shipping_company_info::on_submit_button_clicked()
{
    QString feedback_input = ui->feedback_lineEdit->text();
    QSqlQuery query;
    query.prepare("INSERT INTO shipping_feedback (feedback) "
                  "VALUES (:feedback)");
    query.bindValue(":feedback", feedback_input);

    if (query.exec())
    {
        QMessageBox::information(this, "Success", "Submitted successfully.");
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        QMessageBox::critical(this, "Failed", query.lastError().text());
    }
    ui->feedback_lineEdit->clear();
}


