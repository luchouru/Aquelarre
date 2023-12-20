#include "Bruja.h"

Bruja :: Bruja(String id, String nom) : identificador(id), nombre(nom)
{
    hechizos  = new Hechizos();
}

String Bruja :: getIdentificador()
{
    return identificador;
}

String Bruja :: getNombre()
{
    return nombre;
}

Hechizos * Bruja :: getHechizos()
{
    return hechizos;
}


void Bruja :: setNombre(String nom)
{
    nombre = nom;
}

Bruja :: ~Bruja()
{
}

int Bruja :: contarHechizosEspecialesEnAnio(int anio){
    return hechizos->contarHechizosEspecialesEnAnio(anio);
}

void Bruja :: setHechizo(Hechizo * nuevo)
{
    hechizos->insBack(nuevo);
}
