#include "Fecha.h"
Fecha :: Fecha()
{
    dia=0;
    mes=0;
    anio=0;
}

Fecha :: Fecha(int d,int m,int a)
{
    dia=d;
    mes=m;
    anio=a;
}

int Fecha :: getDia()
{
    return dia;
}

int Fecha :: getMes()
{
    return mes;
}

int Fecha :: getAnio()
{
    return anio;
}

void Fecha :: setDia(int d)
{
    dia=d;

}

void Fecha :: setMes(int m)
{
    mes=m;

}

void Fecha :: setAnio(int a)
{
    anio=a;
}

Fecha :: Fecha (const Fecha &obj)
{
    dia = obj.dia;
    mes = obj.mes;
    anio = obj.anio;
}

Fecha :: ~Fecha() {}

bool Fecha :: operator<(Fecha otra)
{
    int primera = dia + mes * 30 + anio * 365;
    int segunda = otra.getDia() + otra.getMes() * 30 + otra.getAnio() * 365;

    return primera < segunda;

}

bool Fecha :: operator==(Fecha otra)
{

    return dia == otra.getDia() && mes == otra.getMes() && anio == otra.getAnio();
}

Fecha Fecha :: operator++()
{
    sumaDia();
    return (*this);
}


Fecha Fecha :: operator++(int)
{
    Fecha copia= (*this);
    sumaDia();
    return copia;
}

Fecha Fecha :: operator+(int dias)
{
    for (int i=0; i< dias; i++)
    {
        sumaDia();
    }
}

int Fecha :: operator-(Fecha otra)
{

    if ((*this) == otra)
    {
        return 0;
    }

    int diferencia = 0;
    if((*this) < otra)
    {
        while(!((*this) == otra))
        {
            sumaDia();
            diferencia++;
        }

    }
    else
    {
        while(!((*this) == otra))
        {
            otra.sumaDia();
            diferencia--;
        }
    }
    return diferencia;

}

bool Fecha :: esValida()
{
    bool esValida = false;

    switch(mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if(dia>0 && dia<=31)
            esValida = true;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if(dia>0 && dia<=30)
            esValida = true;
        break;
    case 2:
        if(esBisiesto())
        {
            if(dia>0 && dia<=29)
                esValida = true;
        }
        else
        {
            if(dia>0 && dia<=28)
                esValida = true;
        }
        break;
    }
    return esValida;
}


Fecha Fecha :: sumaDia()
{
    int diasMes[] = {0, 31, esBisiesto() ? 29 : 28, 31, 30, 31, 30, 31,31, 30,31,30,31};

    dia++;
    if (dia > diasMes[mes])
    {
        dia = 1;
        mes++;
        if (mes > 12)
        {
            mes = 1;
            anio++;
        }
    }
}

Fecha Fecha :: restaDia()
{
    int diasMes[] = {0, 31, esBisiesto() ? 29 : 28, 31, 30, 31, 30, 31,31, 30,31,30,31};

    dia--;
    if (dia < 1)
    {
        dia = diasMes[mes];
        mes--;
        if (mes < 1)
        {
            mes = 12;
            anio--;
        }
    }
}

bool Fecha :: esBisiesto()
{
    return anio%4==0;
}
