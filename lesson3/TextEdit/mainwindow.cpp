#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QWindow>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->saveButton, &QAbstractButton::clicked, this, &MainWindow::saveFile);
    connect(ui->openButton, &QAbstractButton::clicked, this, &MainWindow::openFile);
    connect(ui->refButton, &QAbstractButton::clicked, this, &MainWindow::showReference);
    QFile file{":/text/refer"};
    file.open(QIODevice::ReadOnly);

    ui->plainTextEdit->setPlainText(file.readAll());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr,QString{"Сохранение файла"},QString{"/"}, QString{"Text(*txt)"});
    if(!fileName.isEmpty()) {
        QFile file(fileName);
        qDebug() << file.filesystemFileName();
        if(file.open(QIODevice::WriteOnly)){
            QTextStream stream{&file};
            stream << getEditText();
            file.close();
        }

    }
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName
            (nullptr,QString{"Открытие файла"}, QString{"/"}, QString{"Text(*txt)"});
    if(!fileName.isEmpty()) {
        QFile file(fileName);
        qDebug() << file.filesystemFileName();
        if(file.open(QIODevice::ReadOnly)){
            QTextStream stream{&file};
           setText(stream.readAll());
        }

    }
}

QString MainWindow::getEditText()
{
    return ui->plainTextEdit->toPlainText();
}

void MainWindow::setText(QString text)
{
    ui->plainTextEdit->setPlainText(text);
}

void MainWindow::showReference()
{
    QLabel* label = new QLabel{};
    QFile file{":/text/refer"};
    file.open(QIODevice::ReadOnly);
    QTextStream stream{&file};
    label->setText(stream.readAll());
    label->setGeometry(500, 300, 200, 200);
    label->setWindowTitle(QString{"Справка"});
    label->show();
}


