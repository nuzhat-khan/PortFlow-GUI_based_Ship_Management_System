#include "manager_info.h"
#include "ui_manager_info.h"


manager_info::manager_info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manager_info)
{
    ui->setupUi(this);
    ui-> stackedWidget ->setCurrentIndex(0);
}

manager_info::~manager_info()
{
    delete ui;
}

void manager_info::on_login_button_clicked()
{
    manager_login_email = ui-> manager_email_input->text();
    manager_login_password = ui-> manager_password_input -> text();

    QSqlQuery query;
    query.prepare("SELECT * FROM manager_info WHERE email = :email AND password = :password");
    query.bindValue(":email", manager_login_email);
    query.bindValue(":password", manager_login_password);

    if (query.exec() && query.next()) {
        QMessageBox::information(this, "Log in", "Successfully logged in");
        ui->stackedWidget->setCurrentIndex(1);
    } else {
        QMessageBox::warning(this, "Log in failed!", "Please try again.");
    }

    ui->manager_email_input->clear();
    ui->manager_password_input->clear();

}

void manager_info::on_log_out_button_clicked()
{
    emit login_page_clicked();
    ui->stackedWidget->setCurrentIndex(0);
}

void manager_info::on_back_button_clicked()
{
    emit login_page_clicked();
}

void manager_info::on_add_operator_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void manager_info::on_remove_operator_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void manager_info::on_back_button_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void manager_info::on_change_manager_button_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void manager_info::on_back_button_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void manager_info::on_ok_change_button_clicked()
{
    new_manager_email= ui-> new_manager_email_input -> text();
    new_manager_password= ui-> new_manager_password_input -> text();

     QSqlQuery query;
     query.prepare("UPDATE manager_info SET email = :new_email, password = :new_password");
     query.bindValue(":new_email", new_manager_email);
     query.bindValue(":new_password", new_manager_password);
     if (query.exec() && query.numRowsAffected() > 0)
     {
         QMessageBox::information(this, "Updated", "Manager information updated successfully.");
         emit login_page_clicked();
         ui->stackedWidget->setCurrentIndex(0);
     }
     else
     {
         QMessageBox::warning(this, "Failed","Update failed.\nError: " + query.lastError().text());
     }
     ui->new_manager_email_input->clear();
     ui->new_manager_password_input->clear();

}

void manager_info::on_add_button_clicked()
{
    operator_name= ui-> add_operator_name -> text();
    operator_id= ui-> add_operator_id -> text();
    operator_password= ui-> add_operator_password -> text();
    operator_phone= ui-> add_operator_phone -> text();

    QSqlQuery query;
    query.prepare("INSERT INTO add_operator_info (name, id, password, phone)"
                  "VALUES (:name, :id, :password, :phone)");

    query.bindValue(":name", operator_name);
    query.bindValue(":id", operator_id);
    query.bindValue(":password", operator_password);
    query.bindValue(":phone", operator_phone);

    if (query.exec())
    {
        QMessageBox::information(this, "Success", "Operator added successfully.");
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::critical(this, "Failed", query.lastError().text());
    }

    ui->add_operator_name->clear();
    ui->add_operator_id->clear();
    ui->add_operator_password->clear();
    ui->add_operator_phone->clear();
}

void manager_info::loadTable()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT name, id, password, phone FROM add_operator_info");

    ui->tableView_remove_operator->setModel(model);
    ui->tableView_remove_operator->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void manager_info::on_load_operator_table_button_clicked()
{
    loadTable();
}

void manager_info::on_remove_button_clicked()
{
    remove_id = ui->remove_operator_id->text();

    QSqlQuery query;
    query.prepare("DELETE FROM add_operator_info WHERE id = :id");

    query.bindValue(":id", remove_id);

    if (query.exec()) {
        QMessageBox::information(this, "Deleted", "Record deleted successfully.");
    } else {
        QMessageBox::warning(this, "Delete Failed", query.lastError().text());
    }
    ui->remove_operator_id->clear();
}

void manager_info::on_back_button_2_clicked()
{
    ui-> stackedWidget -> setCurrentIndex(0);
}

void manager_info::on_back_button_3_clicked()
{
    ui-> stackedWidget -> setCurrentIndex(1);
}

void manager_info::on_back_button_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void manager_info::on_generate_report_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void manager_info::loadTable1()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT name, no, cargo, time, status FROM shipment_info");

    ui->tableView_shipment_info->setModel(model);
    ui->tableView_shipment_info->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void manager_info::on_refresh_1_button_clicked()
{
    loadTable1();
}

void manager_info::loadTable2()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT name, code, time, destination, status FROM cargo_info");

    ui->tableView_cargo_info->setModel(model);
    ui->tableView_cargo_info->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void manager_info::on_refresh_2_button_clicked()
{
    loadTable2();
}

void manager_info::loadTable3()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT sl_no, feedback, status FROM shipping_feedback");

    ui->tableView_shipping_feedback->setModel(model);
    ui->tableView_shipping_feedback->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void manager_info::on_refresh_3_button_clicked()
{
    loadTable3();
}

void manager_info::loadTable4()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT sl_no, suggestion, status FROM guest_suggestion");

    ui->tableView_guest_suggestion->setModel(model);
    ui->tableView_guest_suggestion->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void manager_info::on_refresh_4_button_clicked()
{
    loadTable4();
}
