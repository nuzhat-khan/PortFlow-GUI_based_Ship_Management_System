#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QIcon>
#include <QPixmap>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    ui-> stackedWidget->setCurrentIndex(0);
    ui-> enter_as_box -> addItem("         Manager");
    ui-> enter_as_box -> addItem("         Operator");
    ui-> enter_as_box -> addItem("Shipping Company/Agent");
    ui-> enter_as_box -> addItem("          Guest");
    ui-> stackedWidget -> insertWidget(2,&manage);
    ui-> stackedWidget -> insertWidget(3,&operate);
    ui-> stackedWidget -> insertWidget(4,&company);
    ui-> stackedWidget -> insertWidget(5,&guest);
    connect(&manage, SIGNAL(login_page_clicked()), this, SLOT(move_login_page()));
    connect(&operate, SIGNAL(login_page_clicked()), this, SLOT(move_login_page()));
    connect(&company, SIGNAL(login_page_clicked()), this, SLOT(move_login_page()));
    connect(&guest, SIGNAL(login_page_clicked()), this, SLOT(move_login_page()));

}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::on_get_started_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_next_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(ui->enter_as_box->currentIndex()+2);
}

void MainWindow::move_login_page()
{
    ui->stackedWidget->setCurrentIndex(1);
}
