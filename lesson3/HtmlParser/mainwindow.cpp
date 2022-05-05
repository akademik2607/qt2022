#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QAbstractButton::clicked, this, &MainWindow::showInfo);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showInfo()
{
    QString fileName = QFileDialog::getOpenFileName
            (nullptr, QString{"Файл с разметкой"}, QString{"/"}, QString{"Html(*html)"});
    if(!fileName.isEmpty()) {
        QString text = getHtml(fileName);
        QString wether = getDegrees(text);
        wether += ", ";
        wether += getBrightness(text);
        showLabelText(wether, ui->weatherInfo);
        std::vector<QString> currencies = getCurrencies(text);
        showLabelText(currencies.at(0), ui->dollarInfo);
        showLabelText(currencies.at(1), ui->euroInfo);
        showLabelText(currencies.at(2), ui->brentInfo);
    }

}

QString MainWindow::getDegrees(const QString& html)
{
    return getHtmlData("(<span class=\"weather__temp-period.+?>)([+-]\\d+°)(</span>)", html);
}

QString MainWindow::getBrightness(const QString &html)
{
    qDebug() << getHtmlData("(<div class=\"weather__description.+?>)(.+?)(</div>)", html);
    return getHtmlData("(<div class=\"weather__description.+?>)(.+?)(</div>)", html);
}

QString MainWindow::getHtmlData(const QString& pattern, const QString& html)
{
    QRegularExpression re{pattern};
    QRegularExpressionMatch match = re.match(html);

    return match.captured(2);
}

std::vector<QString> MainWindow::getCurrencies(const QString &html)
{
    QRegularExpression re{QString{"(<div class=\"rate__currency.+?>)(.+?)(</div>)"}};
    QRegularExpressionMatchIterator matches = re.globalMatch(html);
    qDebug() << matches.hasNext();
    std::vector<QString> vec{};
    while(matches.hasNext()) {
        QRegularExpressionMatch match = matches.next();
        qDebug() << match.hasMatch();
        qDebug() << match.captured(2);
        vec.emplace_back(QString{match.captured(2)});
    }
    return vec;
}

void MainWindow::showLabelText(const QString &text, QLabel *label)
{
    label->setText(text);
}

QString MainWindow::getHtml(const QString &fileName)
{
    QFile file{fileName};
    if(file.open(QIODevice::ReadOnly)){
        QTextStream stream{&file};
        return stream.readAll();
    }
    return QString{};
}

