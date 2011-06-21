#ifndef GPS_H
#define GPS_H
#include "grafo.h"
#include <Qmap>
#include <QVector>

using namespace std;

class GPS
{
public:
    GPS();// por default 10 nodos, y alcance de 5.0
    GPS(int nodos, int ancho, int alto);
    Grafo *grafo;
    QMap<int, QMap<QString,QVector<QVector<float> > > >week;
    QMap<int, QMap<QString,QVector<QVector<float> > > >::const_iterator it;
    ~GPS() { delete grafo;}   // Corre el destructor de grafo


private:

    void removeAristasMayoresAlcance();    
};

#endif // GPS_H
