#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QList>
#include <QMessageBox>
#include <QDebug>

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
    int parenthesis, cursorPos;
    QList<QString> input;
    QList<QString> signs; // signs precedence table //

private slots:
    void on_Bleft_clicked();
    void on_pushButton_clicked();
    void on_Bdel_clicked();
    void on_Bans_clicked();    
    void on_Bpow_clicked();
    void on_Bdiv_clicked();
    void on_Btime_clicked();
    void on_Bminus_clicked();
    void on_Bplus_clicked();
    void on_Bpoint_clicked();
    void on_Bnine_clicked();
    void on_Beight_clicked();
    void on_Bsix_clicked();
    void on_Bfive_clicked();
    void on_Bfour_clicked();
    void on_Bthree_clicked();
    void on_Btwo_clicked();
    void on_Bone_clicked();
    void on_Bcero_clicked();
    void on_Bseven_clicked();
    void on_Bclear_clicked();    
    void on_Bsin_clicked();
    void on_Bcos_clicked();
    void on_Bparent2_clicked();
    void on_Bparent1_clicked();
};

#endif // MAINWINDOW_H
