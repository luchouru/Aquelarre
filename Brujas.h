#ifndef BRUJAS_H_INCLUDED
#define BRUJAS_H_INCLUDED
#include "IteradorBrujas.h"
#include "Comun.h"
#include "Suprema.h"

class Brujas
{
private:

    struct Nodo
    {
        Bruja * info;
        Nodo * hizq;
        Nodo * hder;
    };
    Nodo * ABB;
    void destruirArbol (Nodo * &); // destruye todo el contenido del árbol
    bool perteneceEnArbol (Nodo *, String);
    void insertEnArbol (Nodo * &, Bruja *);
    Bruja * obtenerEnArbol (Nodo *, String);
    void cargarIterador (Nodo *, IteradorBrujas &);
    Suprema * obtenerEnArbolBrujaMayor (Nodo * a);

public:
    Brujas ();
    bool member(String);
    void insert(Bruja *);
    Bruja * find(String);
    IteradorBrujas listarBrujas();
    bool empty();
    Suprema * obtenerBrujaSupremaMayor();
    ~Brujas();
};

#endif // BRUJAS_H_INCLUDED
