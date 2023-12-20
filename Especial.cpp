#include "Especial.h"

Especial :: Especial(String txt, int anio, String desc) : Hechizo(txt), descripcion(desc)
{
    anioManifiesto = anio;
}

int Especial :: getAnioManifiesto()
{
    return anioManifiesto;
}

String Especial :: getDescripcion()
{
    return descripcion;
}

void Especial :: setAnioManifiesto(int anio)
{
    anioManifiesto = anio;
}

void Especial :: setDescripcion(String desc)
{
    descripcion = desc;
}

String Especial :: tipoHechizo()
{
    return "Especial";
}

Especial :: ~Especial() {}
