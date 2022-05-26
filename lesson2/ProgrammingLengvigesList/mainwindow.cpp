#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    LangvigeModel* model = new LangvigeModel();
    ui->listView->setModel(model);
    ui->listView->setDragEnabled(true);
    ui->listView->viewport()->setAcceptDrops(true);
    ui->listView->setDropIndicatorShown(true);
    ui->listView->setDragDropMode(QAbstractItemView::DragDropMode::DragDrop);
    ui->listView->setViewMode(QListView::ListMode);

    connect(ui->checkBox, &QAbstractButton::toggled, this, &MainWindow::changeViewMode);
    connect(ui->addButton, &QAbstractButton::clicked, this, &MainWindow::addLangvige);
    connect(ui->removeButton, &QAbstractButton::clicked, this, &MainWindow::removeLangvige );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeViewMode(bool isChecked)
{
    if(isChecked) {
        ui->listView->setViewMode(QListView::IconMode);
    } else {
        ui->listView->setViewMode(QListView::ListMode);
    }
}

void MainWindow::addLangvige()
{
    QString text = ui->addEdit->text();
    if(text.isEmpty()) return;
    LangvigeModel* model = dynamic_cast<LangvigeModel*>(ui->listView->model());

    if(model) {
        model->addData(text);
    }

}

void MainWindow::removeLangvige()
{
    QModelIndex index = ui->listView->currentIndex();
    ui->listView->model()->removeRows(index.row(), 1, QModelIndex{});
}

