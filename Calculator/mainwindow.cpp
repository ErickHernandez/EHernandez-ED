#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbSolve_clicked()
{
    if(this->ui->leEcuation->text().isEmpty())
        return;

    QList<QString> ecuation;
    QString temp = this->ui->leEcuation->text();

    for(int i = 0; i<temp.length(); i++)
        ecuation.push_back(temp.at(i));

    QString ans = this->logic.evaluate(ecuation);

    qDebug()<<ans;

    this->ui->leEcuation->clear();
    this->ui->leEcuation->setFocus();
}
