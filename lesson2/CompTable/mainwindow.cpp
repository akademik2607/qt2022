#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHeaderView>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStandardItemModel* model = new QStandardItemModel{};
    model->setHorizontalHeaderLabels(QStringList{"No", "Имя компьютера", "Ip адрес", "MAC адрес"});
//    model->insertRow(0, QList{"1", "Comp-1", "234.21.234.345", "JKJL-678K-J678-87JH"});
    model->setItem(0, 0, new QStandardItem("1"));
    model->setItem(0, 1, new QStandardItem("Comp-1"));
    model->setItem(0, 2, new QStandardItem("234.21.234.345"));
    model->setItem(0, 3, new QStandardItem("JKJL-678K-J678-87JH"));
    model->setItem(2, 0, new QStandardItem("3"));
    model->setItem(2, 1, new QStandardItem("Comp-3"));
    model->setItem(2, 2, new QStandardItem("234.21.234.347"));
    model->setItem(2, 3, new QStandardItem("JKJL-678K-J678-8745"));
    model->setItemData(ui->tableView->currentIndex(), QMap<int, QVariant>{{Qt::BackgroundRole, QColor{Qt::yellow}}});
    ui->tableView->setModel(model);

    connect(ui->pushButton, &QAbstractButton::clicked, this, &MainWindow::changeStyle);






}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeStyle()
{
    auto model = ui->tableView->model();
    model->setItemData(ui->tableView->currentIndex(), QMap<int, QVariant>{{Qt::BackgroundRole, QColor{Qt::yellow}}});
}

