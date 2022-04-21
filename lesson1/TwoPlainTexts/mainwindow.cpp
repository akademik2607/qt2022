#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString text = ui->getEdit->toPlainText();
    ui->resultEdit->appendPlainText(text);
}


void MainWindow::on_pushButton_2_clicked()
{
    QString text = ui->getEdit->toPlainText();
    ui->resultEdit->setPlainText(text);
}


void MainWindow::on_pushButton_3_clicked()
{
    QString text = ui->getEdit->toPlainText();
    ui->resultEdit->setPlainText("");
    ui->resultEdit->appendHtml("<font color='red'>" + text + "</font>");
}

