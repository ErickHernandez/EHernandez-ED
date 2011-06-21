#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->dockWidget->setWindowOpacity(0.7);
    //this->AreaRender = new RenderArea();--

    // Crea la red interna, con 6 nodos, con 5 de alcance
    // y los nodos se generan entre 600 a 500 (area )

    //this->gps = new GPS(50,100.0,730,470);//--


    // Al AreaRender siempre pasarle de parametro solo el grafo y no todo
    // GPS para no modificar lo que ya se tenia
    //this->AreaRender->setGrafo(gps->grafo);//--

    //this->ui->gridLayout->addWidget(this->AreaRender,0,0,1,1);--

    //this->CargarTabladeGrafo();

    /*this->A = new float*[this->gps->grafo->getSize()];
        for (int i=0; i<this->gps->grafo->getSize();i++)
            this->A[i] = new float[this->gps->grafo->getSize()];*/

        this->readFile();                
}


MainWindow::~MainWindow()
{
    delete ui;
    delete this->AreaRender;
    delete this->gps;
}

void MainWindow::on_pbAddArista_clicked()
{
    if(this->ui->leInicio->text() != "" && this->ui->leFinal->text() !="" && this->ui->lePeso->text()!= "")
    {
        this->gps->grafo->addArista(ui->leInicio->text().toInt(),
                           ui->leFinal->text().toInt(),
                           ui->lePeso->text().toFloat());

        this->AreaRender->update();
    }
}

void MainWindow::Floyd()
{
/*    this->A = new float*[this->gps->grafo->getSize()];
    for (int i=0; i<this->gps->grafo->getSize();i++)
        this->A[i] = new float[this->gps->grafo->getSize()];*///lo pase al mainwindow constructor

    //Copiar la matriz del grafo en A (copia)
    for (int i=0;i<this->gps->grafo->getSize();i++)
    {
        for (int j=0; j<this->gps->grafo->getSize();j++)                   
            A[i][j] = this->gps->grafo->getPesoArista(i,j);                

    }
    // Algoritmo de Floyd
    for (int k =0; k<gps->grafo->getSize();k++)
        for (int i =0; i<gps->grafo->getSize();i++)
            for (int j =0; j<gps->grafo->getSize();j++)
            {
               float peso = A[i][k] + A[k][j];
               if(peso < Grafo::INFINITO)
                   if (peso < A[i][j])
                       A[i][j] = peso ;


             }


    this->CargarTablaFloyd();


}
void MainWindow::CargarTabladeGrafo()
{
    this->ui->tableWidget->setRowCount(this->gps->grafo->getSize());
    this->ui->tableWidget->setColumnCount(this->gps->grafo->getSize());    
    // QTableWidgetItem *item = new QTableWidgetItem("X");

    for (int i=0;i<this->gps->grafo->getSize();i++)
    {
        for (int j=0; j<this->gps->grafo->getSize();j++)
        {
            //QString dato; dato.setNum(gps->grafo->getPesoArista(i,j));
            QString dato; dato.setNum(this->A[i][j]);
            QTableWidgetItem *item = new QTableWidgetItem(dato);
            this->ui->tableWidget->setItem(i,j,item);
        }
    }
    for(int i=0;i<gps->grafo->getSize();i++)
    {
     QString temp;
     temp.setNum(i);
     ui->tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(temp));
     ui->tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(temp));
    }
 }




void MainWindow::CargarTablaFloyd()
{
    this->ui->tableWidget->setRowCount(this->gps->grafo->getSize());
    this->ui->tableWidget->setColumnCount(this->gps->grafo->getSize());

    for (int i=0;i<this->gps->grafo->getSize();i++)
    {
        for (int j=0; j<this->gps->grafo->getSize();j++)
        {
            QString dato; dato.setNum(A[i][j]);
            QTableWidgetItem *item = new QTableWidgetItem(dato);
            this->ui->tableWidget->setItem(i,j,item);
        }
    }

}

void MainWindow::readFile()
{
    ifstream fs("Nodos.txt");

    int cant = 0;
    char data[128];
    QString line;
    QStringList nodos, aristas;

    while(true)
    {
        fs.getline(data,128);
        line = QString(data);

        if(line == "/")
            break;

        if((line != "(Nodos)") && (line != "(Pesos)"))
        {
            if(line.startsWith("*-"))
                nodos.push_back(line.mid(1,line.length()));

            if(line.startsWith("#"))
                aristas.push_back(line.mid(1,line.length()));
        }

        cant++;
    }
    fs.close();

    this->LoadGraph(nodos, aristas);

}

void MainWindow::LoadGraph(QStringList nodos, QStringList aristas)
{
    this->gps = new GPS(nodos.length(),730,470);//
    this->inicializarVectors();

//    this->AreaRender = new RenderArea();
//    this->AreaRender->setGrafo(gps->grafo);//
//    this->ui->gridLayout->addWidget(this->AreaRender,0,0,1,1);

    QString temp;
    QStringList n;

    for(int i = 0; i<nodos.length(); i++)
    {
        temp = nodos.at(i);
        n = temp.split('-',QString::SkipEmptyParts);

        //this->gps->grafo->nodos[i].etiqueta = n.at(0);
        temp = n.at(1);
        this->gps->grafo->nodos[i].x = temp.toInt();
        temp = n.at(2);
        this->gps->grafo->nodos[i].y = temp.toInt();        

        this->nodes.push_back(n.at(0));
        nodos.replace(i,QString().setNum(i).append(" " + n.at(0)));

    }

    this->AreaRender = new RenderArea();
    this->AreaRender->setGrafo(gps->grafo);//
    this->ui->gridLayout->addWidget(this->AreaRender,0,0,1,1);
    this->ui->places->addItems(nodos);
    this->ui->cmbStart->addItems(nodos);
    this->ui->cmbDestiny->addItems(nodos);


    int day, peso, nodo1, nodo2;
    QString hora, etiq1, etiq2;

    for(int i = 0; i<aristas.length(); i++)
    {
        temp = aristas.at(i);
        n = temp.split('-',QString::SkipEmptyParts);

        temp = n.at(0);
        day = temp.toInt();
        hora = n.at(1);
        hora.append("-");
        hora.append(n.at(2));
        etiq1 = n.at(3);
        etiq2 = n.at(4);
        temp = n.at(5);
        peso = temp.toInt();
        nodo1 = this->NodeIndx(etiq1);
        nodo2 = this->NodeIndx(etiq2);

        if(day>=1 && day<=7)
        {
            this->gps->week[(day-1)][hora][nodo1][nodo2] = peso;
            this->gps->week[(day-1)][hora][nodo2][nodo1] = peso;

        }
    }

}

void MainWindow::on_pbSwitch_Graph_clicked()
{

    int day = this->ui->cmbDay->currentIndex();
    QString hour = this->ui->cmbHour->currentText();

    if(day != 0)
    {
        if(this->ui->cmbHour->currentIndex() != 0)
        {
            this->A = this->gps->week[(day-1)][hour];

            this->gps->grafo->setData(this->A);

            this->Floyd();
            this->update();
        }
    }
}

int MainWindow::NodeIndx(QString etiq)
{
    for(int i = 0; i<this->nodes.length(); i++)
    {
        if(this->nodes.at(i) == etiq)
            return i;
    }
}

void MainWindow::inicializarVectors()
{
    int cant = this->gps->grafo->getSize();

    for(int i = 0; i<7; i++)
    {
        //for(int j = 0; j<cant; j++)
        //{
            this->gps->week[i]["0-1"].resize(cant);
            this->gps->week[i]["1-2"].resize(cant);
            this->gps->week[i]["2-3"].resize(cant);
            this->gps->week[i]["3-4"].resize(cant);
            this->gps->week[i]["4-5"].resize(cant);
            this->gps->week[i]["5-6"].resize(cant);
            this->gps->week[i]["6-7"].resize(cant);
            this->gps->week[i]["7-8"].resize(cant);
            this->gps->week[i]["8-9"].resize(cant);
            this->gps->week[i]["9-10"].resize(cant);
            this->gps->week[i]["10-11"].resize(cant);
            this->gps->week[i]["11-12"].resize(cant);
            this->gps->week[i]["12-13"].resize(cant);
            this->gps->week[i]["13-14"].resize(cant);
            this->gps->week[i]["14-15"].resize(cant);
            this->gps->week[i]["15-16"].resize(cant);
            this->gps->week[i]["16-17"].resize(cant);
            this->gps->week[i]["17-18"].resize(cant);
            this->gps->week[i]["18-19"].resize(cant);
            this->gps->week[i]["19-20"].resize(cant);
            this->gps->week[i]["20-21"].resize(cant);
            this->gps->week[i]["21-22"].resize(cant);
            this->gps->week[i]["22-23"].resize(cant);
            this->gps->week[i]["23-0"].resize(cant);


            for(int x = 0; x<cant; x++)
            {
                this->gps->week[i]["0-1"][x].resize(cant);
                this->gps->week[i]["1-2"][x].resize(cant);
                this->gps->week[i]["2-3"][x].resize(cant);
                this->gps->week[i]["3-4"][x].resize(cant);
                this->gps->week[i]["4-5"][x].resize(cant);
                this->gps->week[i]["5-6"][x].resize(cant);
                this->gps->week[i]["6-7"][x].resize(cant);
                this->gps->week[i]["7-8"][x].resize(cant);
                this->gps->week[i]["8-9"][x].resize(cant);
                this->gps->week[i]["9-10"][x].resize(cant);
                this->gps->week[i]["10-11"][x].resize(cant);
                this->gps->week[i]["11-12"][x].resize(cant);
                this->gps->week[i]["12-13"][x].resize(cant);
                this->gps->week[i]["13-14"][x].resize(cant);
                this->gps->week[i]["14-15"][x].resize(cant);
                this->gps->week[i]["15-16"][x].resize(cant);
                this->gps->week[i]["16-17"][x].resize(cant);
                this->gps->week[i]["17-18"][x].resize(cant);
                this->gps->week[i]["18-19"][x].resize(cant);
                this->gps->week[i]["19-20"][x].resize(cant);
                this->gps->week[i]["20-21"][x].resize(cant);
                this->gps->week[i]["21-22"][x].resize(cant);
                this->gps->week[i]["22-23"][x].resize(cant);
                this->gps->week[i]["23-0"][x].resize(cant);

            }
        //}

    }

    for(int x = 0; x<7; x++)
    {
        for(int i = 0; i<cant; i++)
        {
            for(int j = 0; j<cant; j++)
            {
                if(i == j)
                {
                    this->gps->week[x]["0-1"][i][j] = 0;
                    this->gps->week[x]["1-2"][i][j] = 0;
                    this->gps->week[x]["2-3"][i][j] = 0;
                    this->gps->week[x]["3-4"][i][j] = 0;
                    this->gps->week[x]["4-5"][i][j] = 0;
                    this->gps->week[x]["5-6"][i][j] = 0;
                    this->gps->week[x]["6-7"][i][j] = 0;
                    this->gps->week[x]["7-8"][i][j] = 0;
                    this->gps->week[x]["8-9"][i][j] = 0;
                    this->gps->week[x]["9-10"][i][j] = 0;
                    this->gps->week[x]["10-11"][i][j] = 0;
                    this->gps->week[x]["11-12"][i][j] = 0;
                    this->gps->week[x]["12-13"][i][j] = 0;
                    this->gps->week[x]["13-14"][i][j] = 0;
                    this->gps->week[x]["14-15"][i][j] = 0;
                    this->gps->week[x]["15-16"][i][j] = 0;
                    this->gps->week[x]["16-17"][i][j] = 0;
                    this->gps->week[x]["17-18"][i][j] = 0;
                    this->gps->week[x]["18-19"][i][j] = 0;
                    this->gps->week[x]["19-20"][i][j] = 0;
                    this->gps->week[x]["20-21"][i][j] = 0;
                    this->gps->week[x]["21-22"][i][j] = 0;
                    this->gps->week[x]["22-23"][i][j] = 0;
                    this->gps->week[x]["23-0"][i][j] = 0;
                }
                else
                {
                    this->gps->week[x]["0-1"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["1-2"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["2-3"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["3-4"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["4-5"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["5-6"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["6-7"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["7-8"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["8-9"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["9-10"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["10-11"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["11-12"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["12-13"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["13-14"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["14-15"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["15-16"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["16-17"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["17-18"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["18-19"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["19-20"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["20-21"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["21-22"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["22-23"][i][j] = this->gps->grafo->INFINITO;
                    this->gps->week[x]["23-0"][i][j] = this->gps->grafo->INFINITO;
                }


            }
        }
    }

    this->A.resize(cant);
    //qDebug()<<this->gps->week[6]["23-0"][16][5]<<"soy el largo";

    for(int i = 0; i<cant; i++)
        this->A[i].resize(cant);
}

void MainWindow::on_pbEditArista_clicked()
{
    if(this->ui->leInicio->text() != "" && this->ui->leFinal->text() !="" && this->ui->lePeso->text() != "")
    {
        this->gps->grafo->addArista(ui->leInicio->text().toInt(),
                           ui->leFinal->text().toInt(),
                           ui->lePeso->text().toFloat());

        this->AreaRender->update();
    }
}

void MainWindow::on_pbDeleteArista_clicked()
{
    if(this->ui->leInicio->text() != "" && this->ui->leFinal->text() !="" && this->ui->lePeso->text() != "")
    {
        this->gps->grafo->addArista(ui->leInicio->text().toInt(),
                           ui->leFinal->text().toInt(),
                           this->gps->grafo->INFINITO);

        this->AreaRender->update();
    }
}

void MainWindow::on_pbFloyd_clicked()
{
    this->Floyd();
}

void MainWindow::on_pbGo_clicked()
{

}
