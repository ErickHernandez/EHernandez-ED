#include "grafo.h"
//Aun no hace nada, aplicar los algoritmos de recorrido (pendiente), consultar el bool del nodo;
//No olvidar que valla tornando false los nodos recorridos.


Grafo::Grafo(int cantidad_nodos, bool dirigido){
    int fila;
    _tamano = cantidad_nodos;
    _dirigido = dirigido;
    matriz = new float*[cantidad_nodos]; // Esto crea todas las filas
    for (fila=0; fila<cantidad_nodos; fila++)
    {
        matriz[fila] = new float[cantidad_nodos]; // Esto crea todas las columnas
    }
    for(int i=0; i<cantidad_nodos; i++) // Inicializar el la matriz con ceros en diagonal e infinito el resto
      for(int j=0; j<cantidad_nodos; j++)
        if(i==j)
          matriz[i][j]=0.0;
        else
            matriz[i][j]=Grafo::INFINITO;

    // Inicializar el indice de nodos
    nodos = new nodo[cantidad_nodos];
    for(int i=0; i<cantidad_nodos; i++)
        nodos[i].etiqueta.setNum(i);

    this->visitados = new bool[cantidad_nodos];

    // Semilla de numeros aleatorios
    srand(time(0));

}
Grafo::~Grafo(){

    for (int i=0; i<_tamano; i++)
    {
        delete [] matriz[i] ;
    }    
    delete [] matriz;
    delete [] nodos;
    delete []visitados;
}

void Grafo::addArista(int nodo1, int nodo2, float peso)
{
    // Si la arista ya existe, entonces no hacer nada
    if(nodo1!=nodo2)
    {        
            this->matriz[nodo1][nodo2] = peso;
            if(!this->_dirigido)
               this->matriz[nodo2][nodo1] = peso;
    }
}

void Grafo::removeArista(int nodo1, int nodo2)
{
    if(nodo1!=nodo2 )
    {
        this->matriz[nodo1][nodo2] = Grafo::INFINITO;
        if(!this->_dirigido)
            this->matriz[nodo2][nodo1] = Grafo::INFINITO;
    }
}

nodo Grafo::getNodo(int i)
{
   nodo n;
   n=this->nodos[i];
   return n;
}

float Grafo::getPesoArista(int nodo1, int nodo2)
{
   return this->matriz[nodo1][nodo2];
}

void Grafo::setPesoArista(int nodo1, int nodo2,float peso)
{
    if(nodo1!=nodo2 && this->matriz[nodo1][nodo2]!=Grafo::INFINITO)
    {
       this->matriz[nodo1][nodo2] = peso;
       if(!this->_dirigido)
           this->matriz[nodo2][nodo1] = peso;

    }
}

void Grafo::setEtiquetaNodo(int nodo1,string etiqueta)
{
    this->nodos[nodo1].etiqueta = QString().fromStdString(etiqueta);
}

void Grafo::setXYNodo(int nodo1, int x, int y)
{
    this->nodos[nodo1].x = x; this->nodos[nodo1].x = y;
}

bool Grafo::checkColision(int limite,int candidato_x,int candidato_y)
{
    float dist;
    for(int i=0; i<limite; i++)
    {
        dist = Grafo::distancia(nodos[i].x,nodos[i].y,
                                candidato_x,candidato_y);
        qDebug() << "nodo:" << i <<"<->" << limite << "candidatos:" << candidato_x << ":"
                 << candidato_y << " Distancia:" << dist ;
        if(dist<=Grafo::DELTACOLISION)
        {   qDebug() << "Colision Detected: " << dist;
            return true;
        }
    }
    return false;
}

/*void Grafo::generarPosicionesRandom(int ancho,int alto)
{
     for (int i=0;i<this->_tamano;i++)
     {
       bool colision=true;
       int cont=0;
       int candidato_x, candidato_y;
       while(colision&&cont<=Grafo::INTENTOS_COLISION) // intentos
       {
           candidato_x = rand() % ancho;
           candidato_y = rand() % alto;
           // Este metodo chequea contra el resto sino colisiona
           // Hasta el nodo i
           if (!checkColision(i,candidato_x,candidato_y))
                colision=false;
           else
               cont++;
       }
       this->nodos[i].x = candidato_x  ;
       this->nodos[i].y = candidato_y;

     }

}*/
// PRE-CONDICION : ya se tuve que haber generado Posiciones Random del grafo
void Grafo::calcularDistancias()
{
    for (int i = 0 ; i< this->_tamano; i++)
    {
        for (int j=0; j< this->_tamano; j++ )
        {
          if (i!=j) // Si no es el mismo
             this->addArista(i,j,Grafo::distancia( this->getNodo(i),this->getNodo(j)));
        }
    }

}


void Grafo::setearFalse()
{
    for(int i = 0; i<this->_tamano; i++)
        this->visitados[i] = false;
}

QStringList Grafo::Recorrer_Profundida(int N)
{
    this->setearFalse();    
    this->visitas.clear();
    this->RP(N);
    for(int i =0; i<this->_tamano; i++)
    {
        if(this->visitados[i] == false)
            this->RP(i);
    }
    return this->visitas;

}

void Grafo::RP(int N)
{
    this->visitados[N] = true;
    QString num(QString().setNum(N));
    this->visitas.push_back(num);
     qDebug()<<N;

        for(int i = 0; i<this->_tamano; i++)
        {
           if(this->matriz[N][i] != this->INFINITO)
            {
               if(N != i)
               {
                   if(this->visitados[i] == false)
                   {

                       this->RP(i);
                   }
               }
            }
        }
}

int Grafo::NodoIndex(QString etiqueta)
{
    for(int i = 0; i<this->_tamano; i++)
    {
        if(this->nodos[i].etiqueta == etiqueta)
            return i;
    }
}


void Grafo::setData(QVector<QVector<float> > data)
{
    for(int i = 0; i<data.size(); i++)
        for(int j = 0; j<data.size(); j++)
            this->matriz[i][j] = data[i][j];
}
