#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTableWidgetItem>
#include <QStringList>
#include <QList>
#include "grafo.h"
#include "gps.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <QVector>

using namespace std;

#include "renderarea.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    RenderArea *AreaRender;
    GPS *gps;
    //float **A;
    QVector<QVector<float> > A;
    void CargarTabladeGrafo();
    void CargarTablaFloyd();    
    void Floyd();
    void readFile();
    void LoadGraph(QStringList nodos, QStringList aristas);
    int dia;
    QString hora;
    QList<QString> nodes;
    int NodeIndx(QString etiq);
    void inicializarVectors();

private slots:            
    void on_pbGo_clicked();
    void on_pbFloyd_clicked();
    void on_pbEditArista_clicked();
    void on_pbSwitch_Graph_clicked();
    void on_pbDeleteArista_clicked();
    void on_pbAddArista_clicked();
};

#endif // MAINWINDOW_H
