#include "Hechizos.h"

Hechizos :: Hechizos()
{
    tope = 0;
    arre[tope] = NULL;
}

//Precondición: No está lleno.
void Hechizos :: insBack(Hechizo * nuevo)
{
    arre[tope] = nuevo;
    tope++;
    nuevo -> setNumero(tope);
}

bool Hechizos :: esVacia()
{
    return tope == 0;
}

int Hechizos :: largo()
{
    return tope;
}

//Precondición: n es <= tope
Hechizo * Hechizos :: kesimo(int n)
{
    return arre[n];
}

int Hechizos :: contarHechizosEspecialesEnAnio(int anio)
{
    int cont = 0;
    for (int i=0; i < tope; i++)
    {
        Hechizo * hechizoAux = arre[i];
        if(hechizoAux -> tipoHechizo() == "Especial" && ((Especial *) (hechizoAux)) -> getAnioManifiesto() == anio)
            cont++;

    }

    return cont;
}

Hechizos :: ~Hechizos()
{
    destruirHechizos();
}

void Hechizos :: destruirHechizos()
{
    for (int i=0; i < tope; i++)
        delete (arre[i]);
}

int Hechizos :: calcularPuntos(int comun, int especial)
{
    int puntos = 0;

    for(int i = 0; i < tope; i++)
    {
        if(arre[i]->tipoHechizo() == "Especial")
            puntos = puntos + especial;
        else
            puntos = puntos + comun;
    }

    return puntos;
}

bool Hechizos :: estaLlena()
{
    return tope == TAMANIO;
}
