#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "langvige_model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Q_SLOT void changeViewMode(bool isGhecked);
    Q_SLOT void addLangvige();
    Q_SLOT void removeLangvige();
private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
