#ifndef SOUP_H
#define SOUP_H
#include <QString>
#include <QList>
#include <QStringList>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <QDebug>
#include <QTime>
using namespace std;


class Soup
{
public:
    Soup();
    void LoadSoup(QString path, int row, int col);
    void LoadDictionary(QString path);    
    QStringList Solve();
    char** puzzle;    

private:   
    void testWordHorizontal_or_Vertical(int c, QString word);
    void prepareData();
    QString switchText(QString text);
    QList<QString> *dictionary;    
    QList<QString> rows;
    QTime time;

    QStringList words;
    string data;
    int size;

};

#endif // SOUP_H
