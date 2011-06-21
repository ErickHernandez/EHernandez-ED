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

void MainWindow::on_actionLoad_Puzzle_triggered()
{
    QString path = QFileDialog::getOpenFileName(this,"Opening File","","*.txt");

    if(path != "")
    {
        //this->game.LoadDictionary(path);
        this->game.LoadSoup(path,50,50);
        this->PaintPuzzle(50,50);
    }
}

void MainWindow::on_actionLoad_Dictionary_triggered()
{
    QString path = QFileDialog::getOpenFileName(this,"Opening File","","*.txt");

    if(path != "")
        this->game.LoadDictionary(path);
}

void MainWindow::PaintPuzzle(int row, int col)
{
    this->ui->dataTable->setRowCount(row);
    this->ui->dataTable->setColumnCount(col);

    QString letra;

    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            letra = this->game.puzzle[i][j];
            QTableWidgetItem *item = new QTableWidgetItem(letra);
            this->ui->dataTable->setItem(i,j,item);
        }
        this->ui->dataTable->setColumnWidth(i,20);
        this->ui->dataTable->setRowHeight(i,20);
    }

}

void MainWindow::on_pbSolve_clicked()
{
    this->ui->list->addItems(this->game.Solve());
    qDebug()<<"palabras: "<<this->ui->list->count();
    this->update();
}
