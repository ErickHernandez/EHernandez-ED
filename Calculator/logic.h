#ifndef LOGIC_H
#define LOGIC_H
#include <QList>
#include <QString>
#include <QDebug>

class Logic
{
public:
    Logic();
    QString evaluate(QList<QString> ecuation);
private:
    bool firtValidations(QList<QString> ecuation);
    void Infijo_ToPosfijo(QList<QString> ecuation);
    QString answer();
    QList<QString> ecuation, operations, numbers;

    int parenthesis;
};

#endif // LOGIC_H
