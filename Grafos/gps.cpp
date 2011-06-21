#include "gps.h"

GPS::GPS()
{ 
    this->grafo = new Grafo(10,false);    
    this->grafo->calcularDistancias();    
}

GPS::GPS(int nodos, int ancho, int alto)
{    
    this->grafo = new Grafo(nodos,false);    
    //Esto calcula las distancias entre todo par de nodos
    this->grafo->calcularDistancias();  
}

