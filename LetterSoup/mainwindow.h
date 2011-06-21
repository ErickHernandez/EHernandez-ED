#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <soup.h>
#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QTableWidgetItem>

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
    void LoadPuzzle();
    void LoadDictionary();//enviarla a dictionary
    void PaintPuzzle(int row, int col);
    Soup game;


private slots:
    void on_pbSolve_clicked();
    void on_actionLoad_Dictionary_triggered();
    void on_actionLoad_Puzzle_triggered();
};

#endif // MAINWINDOW_H
