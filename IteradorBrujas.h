#ifndef ITERADORBRUJAS_H_INCLUDED
#define ITERADORBRUJAS_H_INCLUDED
#include "Bruja.h"

class IteradorBrujas
{
private:
    struct Nodo
    {
        Bruja * info;
        Nodo * sig;
    };
    Nodo * prim;
    Nodo * ult;
    Nodo * actual;

public:
    IteradorBrujas();
    void insertar(Bruja *);
    bool hayMasBrujas();
    Bruja * proximaBruja();
};

#endif // ITERADORBRUJAS_H_INCLUDED
