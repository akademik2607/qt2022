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
    double a = ui->aEdit->text().toDouble();
    double b = ui->bEdit->text().toDouble();
    double angle = ui->angleEdit->text().toDouble();
    auto resultWidget = ui->resultEdit;
    bool isRad;
    if(ui->rad->isChecked()) {
        isRad = true;
    } else {
        isRad = false;
    }
    TrianleSquare ts(a, b, angle, isRad);
    resultWidget->setText(QString::number(ts.getSquare()));

}

