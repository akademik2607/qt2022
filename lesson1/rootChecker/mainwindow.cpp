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
    double c = ui->cEdit->text().toDouble();
    auto res_1 = ui->firstRoot;
    auto res_2 = ui->secondRoot;
    RootTaker rt(a, b, c);
    QPair<states, QPair<double, double>> result = rt.getResult();
    if(result.first == states::TWO_ROOTS || result.first == states::ONE_ROOT) {
        res_1->setText(QString::number(result.second.first));
        res_2->setText(QString::number(result.second.second));
    } else if(result.first == states::NOT_SQUARE) {
        res_1->setText(QString("NotSquare"));
        res_2->setText(QString::number(result.second.first));
    } else if(result.first == states::NO_ROOTS) {
        res_1->setText(QString("NoRoots"));
        res_2->setText(QString("NoRoots"));
    }
}

