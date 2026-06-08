#include "operator_info.h"
#include "ui_operator_info.h"

operator_info::operator_info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::operator_info)
{
    ui->setupUi(this);
    ui-> stackedWidget->setCurrentIndex(0);
    ui->comboBox->addItem("Outgoing");
    ui->comboBox->addItem("Received");

    ui->comboBox_2->addItem("All");
    ui->comboBox_2->addItem("Outgoing");
    ui->comboBox_2->addItem("Received");

    ui->update_status_box->addItem("Pending");
    ui->update_status_box->addItem("On arrival");
}

operator_info::~operator_info()
{
    delete ui;
}

void operator_info::on_back_button_clicked()
{
    emit login_page_clicked();
}



void operator_info::on_login_button_clicked()
{
    operator_login_id = ui-> operator_id_input->text();
    operator_login_password = ui-> operator_password_input -> text();

    QSqlQuery query;
    query.prepare("SELECT * FROM add_operator_info WHERE id = :id AND password = :password");
    query.bindValue(":id", operator_login_id);
    query.bindValue(":password", operator_login_password);

    if (query.exec() && query.next()) {
        QMessageBox::information(this, "Log in", "Successfully logged in");
        ui->stackedWidget->setCurrentIndex(1);
    } else {
        QMessageBox::warning(this, "Log in failed!", "Please try again.");
    }
    ui->operator_id_input->clear();
    ui->operator_password_input->clear();
}


void operator_info::on_logout_button_clicked()
{
    emit login_page_clicked();
     ui-> stackedWidget->setCurrentIndex(0);
}

void operator_info::on_loaded_shipments_button_clicked()
{
    ui-> stackedWidget->setCurrentIndex(2);
}

void operator_info::on_view_shipment_status_clicked()
{
    ui-> stackedWidget->setCurrentIndex(3);
}

void operator_info::on_enter_button_clicked()
{
    ship_name= ui-> ship_name_input -> text();
    ship_no= ui-> ship_no_input -> text();
    cargo_type= ui-> cargo_type_input -> text();
    time = ui->time_input->time().toString("h:mm AP");
    status = ui->comboBox->currentText();


    QSqlQuery query;
    query.prepare("INSERT INTO shipment_info (name, no, cargo, time, status)"
                  "VALUES (:name, :no, :cargo, :time, :status)");

    query.bindValue(":name", ship_name);
    query.bindValue(":no", ship_no);
    query.bindValue(":cargo", cargo_type);
    query.bindValue(":time", time);
    query.bindValue(":status", status);

    if (query.exec())
    {
        QMessageBox::information(this, "Success", "Loaded successfully.");
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::critical(this, "Failed", query.lastError().text());
    }

    ui->ship_name_input->clear();
    ui->ship_no_input->clear();
    ui->cargo_type_input->clear();
    ui->time_input->setTime(QTime(0,0));
}

void operator_info::on_back_button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void operator_info::loadTable()
{
    QString status = ui->comboBox_2->currentText();

    if (status == "All") {
        model->setFilter("");
    }
    else {
        model->setFilter(QString("status = '%1'").arg(status));
    }

    model->select();
}


void operator_info::on_refresh_button_clicked()
{
    model = new QSqlTableModel(this);
    model->setTable("shipment_info");
    model->select();

    ui->tableView_ship->setModel(model);
    ui->tableView_ship->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->comboBox_2, &QComboBox::currentTextChanged,
            this, &operator_info::loadTable);
}

void operator_info::on_back_button_3_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(0);
}

void operator_info::on_back_button_4_clicked()
{
    ui-> stackedWidget -> setCurrentIndex(1);
}

void operator_info::on_update_cargo_status_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void operator_info::on_back_button_9_clicked()
{
     ui-> stackedWidget -> setCurrentIndex(1);
}

void operator_info::loadTable2()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT name, code, time, destination, status FROM cargo_info");

    ui->tableView_track->setModel(model);
    ui->tableView_track->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void operator_info::on_refresh_button_3_clicked()
{
    loadTable2();
}

void operator_info::on_update_button_clicked()
{
    cargo_status= ui-> update_status_box->currentText();;
    code=ui->code_update->text();
     QSqlQuery query;
     query.prepare("UPDATE cargo_info SET status = :status WHERE code = :code");
     query.bindValue(":status", cargo_status);
     query.bindValue(":code", code);

     if (query.exec() && query.numRowsAffected() > 0)
     {
         QMessageBox::information(this, "Updated", "Status updated successfully.");
     }
     else
     {
         QMessageBox::warning(this, "Failed","Update failed.\nError: " + query.lastError().text());
     }
     ui->code_update->clear();
}

void operator_info::on_back_button_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void operator_info::on_review_feedback_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void operator_info::loadTable3()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT sl_no, feedback, status FROM shipping_feedback");

    ui->tableView_feedback->setModel(model);
    ui->tableView_feedback->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void operator_info::on_refresh_button_4_clicked()
{
    loadTable3();
}

void operator_info::loadTable4()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT sl_no, suggestion, status FROM guest_suggestion");

    ui->tableView_suggestion->setModel(model);
    ui->tableView_suggestion->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void operator_info::on_refresh_button_5_clicked()
{
    loadTable4();
}

void operator_info::on_solve_button_1_clicked()
{
        int id = ui->feed_id_input->text().toInt();

        QSqlQuery query;
        query.prepare("UPDATE shipping_feedback "
                      "SET status = 'Solved' "
                      "WHERE sl_no = :id");

        query.bindValue(":id", id);

        if (query.exec())
        {
            if (query.numRowsAffected() > 0)
            {
                QMessageBox::information(this, "Success", "Status updated to Solved.");
            }
            else
            {
                QMessageBox::warning(this, "Not found", "No record found with this ID.");
            }
        }
        else
        {
            QMessageBox::critical(this, "Error", query.lastError().text());
        }
        ui->feed_id_input->clear();

}

void operator_info::on_solve_button_2_clicked()
{
    int id = ui->sug_id_input->text().toInt();

    QSqlQuery query;
    query.prepare("UPDATE guest_suggestion "
                  "SET status = 'Solved' "
                  "WHERE sl_no = :id");

    query.bindValue(":id", id);

    if (query.exec())
    {
        if (query.numRowsAffected() > 0)
        {
            QMessageBox::information(this, "Success", "Status updated to Solved.");
        }
        else
        {
            QMessageBox::warning(this, "Not found", "No record found with this ID.");
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
    ui->sug_id_input->clear();
}
