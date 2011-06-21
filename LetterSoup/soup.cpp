#include "soup.h"

Soup::Soup()
{
    this->size = 51;
    this->dictionary = new QList<QString>[this->size];
    this->words.clear();
}

void Soup::LoadDictionary(QString path)
{
    this->data = path.toStdString();
    ifstream fs(this->data.data());

    this->dictionary = new QList<QString>[this->size];

    char pal[128];
    int pos, cant;
    cant = 0;
    bool z = true;

    while(z == true)
    {
        fs.getline(pal,128);
        this->data = pal;
        if(data == "/")
        {
            z = false;
            break;
        }

        pos = this->data.length();

        QString word = QString().fromStdString(this->data).toUpper();

        if(!(this->dictionary[pos].contains(word)))
        {
            this->dictionary[pos].push_back(word);
            cant += 1;
        }

    }

    fs.close();
}

void Soup::LoadSoup(QString path, int row, int col)
{
    this->data = path.toStdString();
    ifstream fs(this->data.data());


    this->puzzle = new char*[row];
    for(int i = 0; i<row; i++)
    {
        this->puzzle[i] = new char[col];
    }

    char pal[128];
    int cant;
    cant = 0;
    bool z = true;

    while(z == true)
    {
        fs.getline(pal,128);
        this->data = pal;
        if(data == "/")
        {
            z = false;
            break;
        }

        for(int i = 0; i<this->data.length(); i++)
        {
            this->puzzle[cant][i] = this->data.at(i);
        }
        cant += 1;
    }

    fs.close();

    this->prepareData();
}

void Soup::prepareData()
{
    //METE LAS HORIZONTALES Y VERTICALES
    for(int i = 0; i<(this->size-1); i++)
    {
        this->rows.push_back(QString(this->puzzle[i]));
        this->rows.push_back(this->switchText(this->puzzle[i]));/////

        QString text = "";

        for(int k = 0;k<(this->size-1); k++)
        {
            text.push_back(this->puzzle[k][i]);
        }

        this->rows.push_back(text);
        this->rows.push_back(this->switchText(text));
    }

    //METE LAS PRIMERAS DIAGONALES DE ARRIBA A LA MITAD DE IZQ A DER
    for(int x = 3; x<this->size+1;x++)
    {
        int j = 0;
        QString text = "";
        for(int i = (x-2); i>=0; i--)
        {
            text.push_back(this->puzzle[i][j]);
            j++;
        }

        if(x != 3)
        {                      

            this->rows.push_back(text);
            this->rows.push_back(this->switchText(text));
        }
    }

    //METE LAS DIAGONALES DE LA MITAD HACIA ABAJO DE IZQ A DER
    for(int x = 1; x<(this->size-3); x++)
    {
        int j = x;
        QString text = "";
        for(int i = (this->size-2); i>=x; i--)
        {
            text.push_back(this->puzzle[i][j]);
            j++;
        }

        this->rows.push_back(text);
        this->rows.push_back(this->switchText(text));
    }


    //METE LAS DIAGONALES DE LA MITAD HACIA ABAJO DE DER A IZQ
    for(int x= 0; x<this->size-3 ;x++)
    {
        int j = 0;
        QString text = "";
        for(int i = x ;i<this->size-1; i++)//
        {            
            text.push_back(this->puzzle[i][j]);
            j++;
        }

        if(text.length() > 2)
        {         
            this->rows.push_back(text);
            this->rows.push_back(this->switchText(text));
        }
    }


    //METE LAS DIAGONALES ARRIBA DE LA MITAD DER A IZQ
   for(int x = (this->size-2);x>0 ;x--) //va controlando el aumento del tamaño de la diagonal
    {
        int j = (this->size-1);
        QString text = "";
        for(int i = x; i>=0; i--)
        {                     
            j--;
            text.push_back(this->puzzle[i][j]);                        
        }       

        if(text.length() >2 )
        {
            this->rows.push_back(text);
            this->rows.push_back(this->switchText(text));
        }
    }
}

QString Soup::switchText(QString text)
{
    QString temp;

    for(int i = text.length()-1; i>=0; i--)
    {
        temp.append(text.at(i));
    }
    return temp;
}

QStringList Soup::Solve()
{

    this->time.start();

    for(int i = 0; i<this->rows.length(); i++)
    {
        for(int x = 3; x<16; x++)//(this->size-1)//ESTE ES UN GRAN DETALLE PARA QUE SEA LENTO
        {
            if(!(this->dictionary[x].length() == 0))
            {
                this->testWordHorizontal_or_Vertical(x, this->rows.at(i).toUpper());
            }
        }
    }

    qDebug()<<this->time.elapsed();

    //this->words.removeDuplicates();
    return this->words;
}

void Soup::testWordHorizontal_or_Vertical(int c, QString word)//recibe la cantidad de letras a  y testea la fila
{
    QString section;

    int stop = (this->size-1)/c;

    for(int i = 0; i<word.length(); i++)
    {
        if(i+c >word.length())
            break;        

        section = word.mid(i,c);

        if(this->dictionary[c].contains(section))//
            this->words.push_back(section);
    }

    if(((this->size-1) - stop) != 0)
    {
        section =word.mid((word.length()-1)-c,(word.length()-1));

        if(this->dictionary[c].contains(section))//
            this->words.push_back(section);
    }
}
