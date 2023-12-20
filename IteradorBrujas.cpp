#include "IteradorBrujas.h"

IteradorBrujas :: IteradorBrujas()
{
    prim = NULL;
    ult = NULL;
    actual = NULL;
}

void IteradorBrujas :: insertar(Bruja * nueva)
{
    Nodo * nuevo = new Nodo;
    nuevo->info = nueva;
    nuevo->sig = NULL;
    if(prim == NULL)
    {
        prim = nuevo;
        ult = nuevo;
        actual = nuevo;
    }
    else
    {
        ult->sig = nuevo;
        ult = ult->sig;
    }
}

bool IteradorBrujas :: hayMasBrujas()
{
    return bool (actual != NULL);
}

Bruja * IteradorBrujas :: proximaBruja()
{
    Bruja * aux = actual->info;
    actual = actual->sig;
    return aux;
}

