#include "logic.h"

Logic::Logic()
{
    this->operations.push_back("(");
    //this->operations.push_back(")");
    this->operations.push_back("/");
    this->operations.push_back("*");
    this->operations.push_back("+");
    this->operations.push_back("-");

    for(int i = 0; i<10;i++)
        this->numbers.push_back(QString().setNum(i));

    this->parenthesis = 0;
}

QString Logic::evaluate(QList<QString> ecuation)
{
    bool ans;
    this->parenthesis = 0;

    ans = this->firtValidations(ecuation);

    if(!ans)
       return "Sintaxis Error";

    this->ecuation = ecuation;

    this->Infijo_ToPosfijo(ecuation);

    return "Good";
}

bool Logic::firtValidations(QList<QString> ecuation)
{
    QString curr, next;

    for(int i = 0; i<ecuation.count(); i++)
    {
        qDebug()<<ecuation.at(i);

        if(ecuation.at(i) == "(")
            this->parenthesis++;
        else if(ecuation.at(i) == ")")
        {
            if(this->parenthesis == 0)
                return false;

            this->parenthesis--;
        }

        if(i<ecuation.length()-1)
        {
            curr = ecuation.at(i);
            next = ecuation.at(i+1);

            if(curr == "." && curr == next)
                return false;

            if(curr == "(" && curr == ")")
                return false;
        }
    }

    //qDebug()<<this->parenthesis;

    if(this->parenthesis != 0)
        return false;

    return true;
}

void Logic::Infijo_ToPosfijo(QList<QString> ecuation)
{
    ecuation.push_front("(");
    ecuation.push_back(")");
    QList<QString> pile, tail;


    for(int i = 0; i<ecuation.count(); i++)
    {
        if(this->numbers.contains(ecuation.at(i)))
            tail.push_back(ecuation.at(i));
    }

}

QString Logic::answer()
{

}
