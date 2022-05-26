#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void showInfo();

private:
    QString getHtml(const QString& fileName);
    QString getDegrees(const QString& html);
    QString getBrightness(const QString& html);
    QString getHtmlData(const QString& pattern, const QString&);
    std::vector<QString> getCurrencies(const QString& html);
    void showLabelText(const QString& text, QLabel* label);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
