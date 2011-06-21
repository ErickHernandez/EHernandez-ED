/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 20. Jun 18:05:04 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *tab_2;
    QTableWidget *tableWidget;
    QPushButton *pbFloyd;
    QGroupBox *groupBox;
    QPushButton *pbAddArista;
    QPushButton *pbDeleteArista;
    QPushButton *pbEditArista;
    QLineEdit *lePeso;
    QLineEdit *leInicio;
    QLineEdit *leFinal;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QGroupBox *groupBox_2;
    QComboBox *cmbStart;
    QLabel *label;
    QLabel *label_2;
    QComboBox *cmbDestiny;
    QListView *list;
    QLabel *label_3;
    QPushButton *pbGo;
    QComboBox *cmbDay;
    QComboBox *cmbHour;
    QPushButton *pbSwitch_Graph;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_2;
    QListWidget *places;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1059, 587);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(122, 122, 122);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 30, 801, 521));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-30, 0, 831, 501));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tableWidget = new QTableWidget(tab_2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 701, 411));
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);
        pbFloyd = new QPushButton(tab_2);
        pbFloyd->setObjectName(QString::fromUtf8("pbFloyd"));
        pbFloyd->setGeometry(QRect(710, 10, 75, 23));
        tabWidget->addTab(tab_2, QString());
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(810, 40, 231, 171));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        pbAddArista = new QPushButton(groupBox);
        pbAddArista->setObjectName(QString::fromUtf8("pbAddArista"));
        pbAddArista->setGeometry(QRect(20, 20, 111, 23));
        pbDeleteArista = new QPushButton(groupBox);
        pbDeleteArista->setObjectName(QString::fromUtf8("pbDeleteArista"));
        pbDeleteArista->setGeometry(QRect(20, 80, 111, 23));
        pbEditArista = new QPushButton(groupBox);
        pbEditArista->setObjectName(QString::fromUtf8("pbEditArista"));
        pbEditArista->setGeometry(QRect(20, 50, 111, 23));
        lePeso = new QLineEdit(groupBox);
        lePeso->setObjectName(QString::fromUtf8("lePeso"));
        lePeso->setGeometry(QRect(150, 130, 71, 20));
        leInicio = new QLineEdit(groupBox);
        leInicio->setObjectName(QString::fromUtf8("leInicio"));
        leInicio->setGeometry(QRect(150, 30, 71, 20));
        leFinal = new QLineEdit(groupBox);
        leFinal->setObjectName(QString::fromUtf8("leFinal"));
        leFinal->setGeometry(QRect(150, 80, 71, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(150, 10, 46, 13));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(150, 60, 46, 13));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(150, 110, 46, 13));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(810, 230, 231, 321));
        groupBox_2->setFont(font);
        cmbStart = new QComboBox(groupBox_2);
        cmbStart->setObjectName(QString::fromUtf8("cmbStart"));
        cmbStart->setGeometry(QRect(20, 40, 151, 22));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 61, 16));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 61, 16));
        cmbDestiny = new QComboBox(groupBox_2);
        cmbDestiny->setObjectName(QString::fromUtf8("cmbDestiny"));
        cmbDestiny->setGeometry(QRect(20, 90, 151, 22));
        list = new QListView(groupBox_2);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(20, 140, 191, 171));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 120, 91, 16));
        pbGo = new QPushButton(groupBox_2);
        pbGo->setObjectName(QString::fromUtf8("pbGo"));
        pbGo->setGeometry(QRect(180, 70, 41, 31));
        cmbDay = new QComboBox(centralWidget);
        cmbDay->setObjectName(QString::fromUtf8("cmbDay"));
        cmbDay->setGeometry(QRect(390, 10, 161, 22));
        cmbHour = new QComboBox(centralWidget);
        cmbHour->setObjectName(QString::fromUtf8("cmbHour"));
        cmbHour->setGeometry(QRect(560, 10, 151, 22));
        pbSwitch_Graph = new QPushButton(centralWidget);
        pbSwitch_Graph->setObjectName(QString::fromUtf8("pbSwitch_Graph"));
        pbSwitch_Graph->setGeometry(QRect(720, 10, 91, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1059, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setMinimumSize(QSize(148, 365));
        dockWidget->setAcceptDrops(false);
        dockWidget->setFloating(true);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        places = new QListWidget(dockWidgetContents_2);
        places->setObjectName(QString::fromUtf8("places"));
        places->setGeometry(QRect(10, 10, 141, 331));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        places->setFont(font1);
        dockWidget->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(4), dockWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GPS", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Grafo", 0, QApplication::UnicodeUTF8));
        pbFloyd->setText(QApplication::translate("MainWindow", "Floyd", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "MAtriz Floyd", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Arista", 0, QApplication::UnicodeUTF8));
        pbAddArista->setText(QApplication::translate("MainWindow", "Add Arista", 0, QApplication::UnicodeUTF8));
        pbDeleteArista->setText(QApplication::translate("MainWindow", "Delete Arista", 0, QApplication::UnicodeUTF8));
        pbEditArista->setText(QApplication::translate("MainWindow", "Edit Arista", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Nodo 1", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Nodo 2", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Peso", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Look For..", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Start Place", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Destiny", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Best Way to Go", 0, QApplication::UnicodeUTF8));
        pbGo->setText(QApplication::translate("MainWindow", "GO!", 0, QApplication::UnicodeUTF8));
        cmbDay->clear();
        cmbDay->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Select a Day", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Monday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Tuesday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Wednesday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Thursday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Friday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Saturday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Sunday", 0, QApplication::UnicodeUTF8)
        );
        cmbHour->clear();
        cmbHour->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Select an Hour", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "0-1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1-2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2-3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3-4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4-5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5-6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6-7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7-8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8-9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9-10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10-11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "11-12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "12-13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "13-14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "14-15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "15-16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "16-17", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "17-18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "18-19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "19-20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "20-21", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "21-22", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "22-23", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "23-0", 0, QApplication::UnicodeUTF8)
        );
        pbSwitch_Graph->setText(QApplication::translate("MainWindow", "Switch Graph", 0, QApplication::UnicodeUTF8));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "Places", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
