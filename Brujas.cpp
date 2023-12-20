#include "Brujas.h"

void Brujas :: destruirArbol (Nodo * &a)
{
    if (a != NULL)
    {
        destruirArbol(a->hizq);
        destruirArbol(a->hder);
        delete (a->info);
        delete (a);
        a = NULL;
    }
}
bool Brujas :: perteneceEnArbol (Nodo * a, String id)
{
    bool encontre = false;
    while (!encontre && a != NULL)
        if (id == a->info->getIdentificador())
            encontre = true;
        else if (id < a->info->getIdentificador())
            a = a->hizq;
        else
            a = a->hder;
    return encontre;
}
void Brujas :: insertEnArbol (Nodo * &a, Bruja * bruja)
{
    if (a == NULL)
    {
        a = new Nodo;
        a -> info = bruja;
        a -> hizq = NULL;
        a -> hder = NULL;
    }
    else if (bruja->getIdentificador() < a->info->getIdentificador())
        insertEnArbol(a->hizq,bruja);
    else
        insertEnArbol(a->hder,bruja);

}
Bruja * Brujas :: obtenerEnArbol (Nodo * a, String id)
{
    while (id != a->info->getIdentificador())
        if (id < a->info->getIdentificador())
            a = a->hizq;
        else
            a = a->hder;
    return (a->info);
}
void Brujas :: cargarIterador (Nodo * a, IteradorBrujas &iter)
{
    if (a != NULL)
    {
        cargarIterador (a->hizq, iter);
        iter.insertar (a->info);
        cargarIterador (a->hder, iter);
    }
}


Suprema * Brujas :: obtenerEnArbolBrujaMayor (Nodo * a)
{
    Bruja * aux = a->info; // La primera bruja siempre es suprema
    Suprema * brujaMayor = NULL;
    Suprema * temp;

    if(aux->tipoBruja() == "Suprema")
    {
        temp = (Suprema *) aux;

        if(brujaMayor == NULL ||
                temp->getFechaNacimiento() < brujaMayor->getFechaNacimiento())
        {
            brujaMayor = temp;
        }

    }

    if(a->hizq != NULL)
    {
        temp = obtenerEnArbolBrujaMayor(a->hizq);
        if(temp)
        {
            if(brujaMayor == NULL || temp->getFechaNacimiento() < brujaMayor->getFechaNacimiento())
            {
                brujaMayor = temp;
            }
        }
    }

    if(a->hder != NULL)
    {
        temp = obtenerEnArbolBrujaMayor(a->hder);
        if(temp)
        {
            if(brujaMayor == NULL || temp->getFechaNacimiento() < brujaMayor->getFechaNacimiento())
            {
                brujaMayor = temp;
            }
        }

    }

    return brujaMayor;
}


/*Metodos publicos*/
Brujas :: Brujas ()
{
    ABB = NULL;
}
Brujas :: ~Brujas ()
{
    destruirArbol(ABB);
}
bool Brujas :: member (String id)
{
    return perteneceEnArbol (ABB, id);
}
void Brujas :: insert (Bruja * bruja)
{
    insertEnArbol (ABB, bruja);
}
Bruja * Brujas :: find (String id)
{
    return obtenerEnArbol (ABB, id);
}
IteradorBrujas Brujas :: listarBrujas ()
{
    IteradorBrujas iter = IteradorBrujas();
    cargarIterador (ABB, iter);
    return iter;
}
bool Brujas :: empty()
{
    return ABB == NULL;
}

// Precondicion: coleccion no vacia
Suprema * Brujas :: obtenerBrujaSupremaMayor ()
{
    return obtenerEnArbolBrujaMayor(ABB);
}
