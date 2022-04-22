/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *aEdit;
    QLineEdit *bEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *angleEdit;
    QLabel *label_3;
    QRadioButton *grad;
    QRadioButton *rad;
    QPushButton *pushButton;
    QLabel *label_4;
    QLineEdit *resultEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 310);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        aEdit = new QLineEdit(centralwidget);
        aEdit->setObjectName(QString::fromUtf8("aEdit"));
        aEdit->setGeometry(QRect(70, 70, 113, 26));
        bEdit = new QLineEdit(centralwidget);
        bEdit->setObjectName(QString::fromUtf8("bEdit"));
        bEdit->setGeometry(QRect(240, 70, 113, 26));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 20, 121, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 20, 131, 20));
        angleEdit = new QLineEdit(centralwidget);
        angleEdit->setObjectName(QString::fromUtf8("angleEdit"));
        angleEdit->setGeometry(QRect(420, 70, 113, 26));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(420, 20, 63, 20));
        grad = new QRadioButton(centralwidget);
        grad->setObjectName(QString::fromUtf8("grad"));
        grad->setGeometry(QRect(460, 10, 110, 24));
        grad->setChecked(true);
        rad = new QRadioButton(centralwidget);
        rad->setObjectName(QString::fromUtf8("rad"));
        rad->setGeometry(QRect(460, 40, 110, 24));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(590, 70, 93, 29));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(590, 20, 71, 20));
        resultEdit = new QLineEdit(centralwidget);
        resultEdit->setObjectName(QString::fromUtf8("resultEdit"));
        resultEdit->setGeometry(QRect(680, 20, 113, 26));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\262\320\260\321\217 \321\201\321\202\320\276\321\200\320\276\320\275\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\202\321\200\320\276\321\200\320\260\321\217 \321\201\321\202\320\276\321\200\320\276\320\275\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273", nullptr));
        grad->setText(QCoreApplication::translate("MainWindow", "\320\223\321\200\320\260\320\264\321\203\321\201\321\213", nullptr));
        rad->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\264\320\270\320\260\320\275\321\213", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
