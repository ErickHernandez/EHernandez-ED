#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->parenthesis = this->cursorPos = 0;
    this->input.clear();
    this->signs.push_back("/");
    this->signs.push_back("*");
    this->signs.push_back("+");
    this->signs.push_back("-");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Bans_clicked()
{
    if(this->parenthesis != 0)
        QMessageBox::warning(this,"Error","Close all the parenthesis to operate!");
    else
    {

    }
}

void MainWindow::on_Bparent1_clicked()
{
    QString text = this->ui->lineEdit->text();
    text.append("(");
    this->ui->lineEdit->setText(text);

    this->input.push_front("(");
    this->parenthesis += 1;
}

void MainWindow::on_Bparent2_clicked()
{
    if(this->parenthesis >0)
    {
       QString text = this->ui->lineEdit->text();
       text.append(")");
       this->ui->lineEdit->setText(text);

       this->input.push_front( ")");
       this->parenthesis -= 1;
    }
}

void MainWindow::on_Bcos_clicked()
{
    QString text = this->ui->lineEdit->text();
    text.append("cos(");
    this->ui->lineEdit->setText(text);

    this->input.push_front("cos(");
    this->parenthesis += 1;
}

void MainWindow::on_Bsin_clicked()
{
    /*QString text = this->ui->lineEdit->text();
    text.append("sin(");
    this->ui->lineEdit->setText(text);

    this->input.push_front("sin(");
    this->parenthesis += 1;*/
    QString text = this->ui->lineEdit->text();
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,"sin(");
    this->ui->lineEdit->setText(text);
    this->input.push_front("sin(");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 4;

    this->parenthesis += 1;
}

void MainWindow::on_Bclear_clicked()
{
    this->ui->lineEdit->clear();
    this->parenthesis = 0;
    this->input.clear();
}

void MainWindow::on_Bcero_clicked()
{
    QString text = this->ui->lineEdit->text();
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,"0");
    this->ui->lineEdit->setText(text);
    this->input.push_front("0");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;
}

void MainWindow::on_Bone_clicked()
{
    QString text = this->ui->lineEdit->text();
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,"1");
    this->ui->lineEdit->setText(text);
    this->input.push_front("1");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;
}

void MainWindow::on_Btwo_clicked()
{
    QString text = this->ui->lineEdit->text();
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,"2");
    this->ui->lineEdit->setText(text);
    this->input.push_front("2");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;
}

void MainWindow::on_Bthree_clicked()
{
    QString text = this->ui->lineEdit->text();
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,"3");
    this->ui->lineEdit->setText(text);
    this->input.push_front("3");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;
}

void MainWindow::on_Bfour_clicked()
{
    QString text = this->ui->lineEdit->text();
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,"4");
    this->ui->lineEdit->setText(text);
    this->input.push_front("4");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;
}

void MainWindow::on_Bfive_clicked()
{
    QString text = this->ui->lineEdit->text();
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,"5");
    this->ui->lineEdit->setText(text);
    this->input.push_front("5");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;
}

void MainWindow::on_Bsix_clicked()
{
    QString text = this->ui->lineEdit->text();
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,"6");
    this->ui->lineEdit->setText(text);
    this->input.push_front("6");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;
}

void MainWindow::on_Bseven_clicked()
{
    QString text = this->ui->lineEdit->text();
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,"7");
    this->ui->lineEdit->setText(text);
    this->input.push_front("7");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;
}

void MainWindow::on_Beight_clicked()
{
    QString text = this->ui->lineEdit->text();
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,"8");
    this->ui->lineEdit->setText(text);
    this->input.push_front("8");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;
}

void MainWindow::on_Bnine_clicked()
{
    QString text = this->ui->lineEdit->text();
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,"9");
    this->ui->lineEdit->setText(text);
    this->input.push_front("9");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;
}

void MainWindow::on_Bpoint_clicked()
{
    QString text = this->ui->lineEdit->text();
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,".");
    this->ui->lineEdit->setText(text);
    this->input.push_front(".");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;
}

void MainWindow::on_Bplus_clicked()
{
    QString text = this->ui->lineEdit->text();
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,"+");
    this->ui->lineEdit->setText(text);
    this->input.push_front("+");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;
}

void MainWindow::on_Bminus_clicked()
{
    QString text = this->ui->lineEdit->text();
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,"-");
    this->ui->lineEdit->setText(text);
    this->input.push_front("-");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;
}

void MainWindow::on_Btime_clicked()
{
    QString text = this->ui->lineEdit->text();
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,"*");
    this->ui->lineEdit->setText(text);
    this->input.push_front("*");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;
}

void MainWindow::on_Bdiv_clicked()
{
    QString text = this->ui->lineEdit->text();
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,"/");
    this->ui->lineEdit->setText(text);
    this->input.push_front("/");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;
}

void MainWindow::on_Bpow_clicked()
{
    QString text = this->ui->lineEdit->text();
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,"^");
    this->ui->lineEdit->setText(text);
    this->input.push_front("^");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;
}


void MainWindow::on_Bdel_clicked()
{
    if(!this->input.isEmpty())
    {
        this->input.pop_front();

        QString text;

        for(int i = this->input.count()-1; i>=0; i--)
        {
            text.append(this->input.at(i));
        }

        this->ui->lineEdit->setText(text);
    }
}

void MainWindow::on_pushButton_clicked()
{
    this->ui->lineEdit->setCursorPosition(3);
    this->ui->lineEdit->setFocus();
}

void MainWindow::on_Bleft_clicked()
{
    if(!this->ui->lineEdit->text().length() == 0)
    {
        int pos = this->ui->lineEdit->cursorPosition();
        this->ui->lineEdit->setCursorPosition(pos-1);
        this->ui->lineEdit->setFocus();

        this->cursorPos = this->ui->lineEdit->cursorPosition();

        //Hacer que el "del" se mueva..
    }

}
