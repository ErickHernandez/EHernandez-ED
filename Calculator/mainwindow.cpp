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
    this->ui->lineEdit->setFocus();

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
    int temp;

    this->ui->lineEdit->setCursorPosition(this->cursorPos);

    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->cursorPos = this->ui->lineEdit->cursorPosition();
        qDebug()<<this->cursorPos;
    }

    temp = this->cursorPos;

    text.insert(this->cursorPos,"(");
    this->ui->lineEdit->setText(text);
    this->input.push_front("(");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;

    this->parenthesis += 1;

}

void MainWindow::on_Bparent2_clicked()
{
    if(this->parenthesis >0)
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

       text.insert(this->cursorPos,")");
       this->ui->lineEdit->setText(text);
       this->input.push_front(")");

       if(temp != this->ui->lineEdit->cursorPosition())
           this->cursorPos = temp + 1;

       this->parenthesis -= 1;
    }
}

void MainWindow::on_Bcos_clicked()
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

    text.insert(this->cursorPos,"cos(");
    this->ui->lineEdit->setText(text);
    this->input.push_front("cos(");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 4;

    this->parenthesis += 1;
}

void MainWindow::on_Bsin_clicked()
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

    text.insert(this->cursorPos,"*");
    this->ui->lineEdit->setText(text);
    this->input.push_front("*");

    if(temp != this->ui->lineEdit->cursorPosition())
        this->cursorPos = temp+ 1;
}


void MainWindow::on_Bdel_clicked()
{
    if(this->ui->lineEdit->cursorPosition() == 0)
    {
        this->ui->lineEdit->setFocus();
        return;
    }

    if(!this->input.isEmpty())
    {
        if(this->ui->lineEdit->cursorPosition() != this->ui->lineEdit->text().length())
        {
            int pos = this->input.length()  - this->cursorPos; //Posicionandome en la pos correcta para eliminar
            this->input.removeAt(pos);//Removiendo Dato de la Lista
           // if(this->cursorPos != 1)
                this->cursorPos -= 1;

                if(this->cursorPos < 0)
                    this->cursorPos = 0;

                if(this->ui->lineEdit->cursorPosition() == 0)
                    this->cursorPos = 0;

                this->ui->lineEdit->setCursorPosition(this->cursorPos);
        }
        else
            this->input.pop_front();//yo tenia solo esta linea

        QString text;

        for(int i = this->input.count()-1; i>=0; i--)
        {
            text.append(this->input.at(i));
        }

        this->ui->lineEdit->setText(text);

        this->ui->lineEdit->setCursorPosition(this->cursorPos);
        this->ui->lineEdit->setFocus();
    }
}

void MainWindow::on_pushButton_clicked()
{
    for(int i = 0; i<this->input.length(); i++)
    {
        qDebug()<<" "<<this->input.at(i);
    }
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

        qDebug()<<this->ui->lineEdit->cursorPosition()<<" "<<this->cursorPos<<"  "<<this->input.at(this->cursorPos);
    }
    this->ui->lineEdit->setFocus();
}

void MainWindow::on_Bright_clicked()
{
    if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
    {
        this->ui->lineEdit->setFocus();
        return;
    }

    if(!this->ui->lineEdit->text().length() == 0)
    {
        if(this->ui->lineEdit->cursorPosition() == this->ui->lineEdit->text().length())
        {
            this->ui->lineEdit->cursorForward(false);
            //qDebug()<<this->ui->lineEdit->cursorPosition();
            this->ui->lineEdit->setCursorPosition(this->ui->lineEdit->text().length());
            this->ui->lineEdit->setFocus();
            return;
        }

        int pos = this->ui->lineEdit->cursorPosition();

        //qDebug()<<this->cursorPos<<" "<<this->input.at(pos);

//        if((this->input.at(this->cursorPos+1) == "sin(") || (this->input.at(this->cursorPos+1) == "cos("))
//            this->ui->lineEdit->setCursorPosition(pos+3);
//        else
            this->ui->lineEdit->setCursorPosition(pos+1);

        //qDebug()<<this->ui->lineEdit->cursorPosition()<<" "<<this->input.at(pos);

        this->ui->lineEdit->setFocus();

        this->cursorPos = this->ui->lineEdit->cursorPosition();


        //Hacer que el "del" se mueva..
    }
}
