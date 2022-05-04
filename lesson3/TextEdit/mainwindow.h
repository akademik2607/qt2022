#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

Q_SLOT void saveFile();
Q_SLOT void openFile();
private:
    QString getEditText();
    void setText(QString text);
    void showReference();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
