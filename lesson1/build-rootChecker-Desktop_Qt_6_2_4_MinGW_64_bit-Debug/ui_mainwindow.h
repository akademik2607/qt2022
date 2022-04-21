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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *aEdit;
    QLineEdit *bEdit;
    QLineEdit *cEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *firstRoot;
    QPushButton *pushButton;
    QLabel *label_4;
    QLineEdit *secondRoot;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(683, 238);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        aEdit = new QLineEdit(centralwidget);
        aEdit->setObjectName(QString::fromUtf8("aEdit"));
        aEdit->setGeometry(QRect(40, 70, 113, 26));
        bEdit = new QLineEdit(centralwidget);
        bEdit->setObjectName(QString::fromUtf8("bEdit"));
        bEdit->setGeometry(QRect(180, 70, 113, 26));
        cEdit = new QLineEdit(centralwidget);
        cEdit->setObjectName(QString::fromUtf8("cEdit"));
        cEdit->setGeometry(QRect(330, 70, 113, 26));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 16, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 40, 63, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 40, 63, 20));
        firstRoot = new QLineEdit(centralwidget);
        firstRoot->setObjectName(QString::fromUtf8("firstRoot"));
        firstRoot->setGeometry(QRect(40, 140, 113, 26));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 140, 93, 29));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 110, 71, 20));
        secondRoot = new QLineEdit(centralwidget);
        secondRoot->setObjectName(QString::fromUtf8("secondRoot"));
        secondRoot->setGeometry(QRect(180, 140, 113, 26));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(180, 110, 63, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 683, 26));
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
        label->setText(QCoreApplication::translate("MainWindow", "a", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "b", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "c", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "1 \320\272\320\276\321\200\320\265\320\275\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "2 \320\272\320\276\321\200\320\265\320\275\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
