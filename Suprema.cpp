#include "Suprema.h"

Suprema :: Suprema(String id, String nombre, Fecha nacimiento, int poderes) : Bruja(id,nombre), fechaNacimiento(nacimiento)
{
    cantidadPoderes = poderes;
}

Fecha Suprema :: getFechaNacimiento()
{
    return fechaNacimiento;
}

int Suprema :: getCantidadPoderes()
{
    return cantidadPoderes;
}

void Suprema :: setFechaNacimiento(Fecha nacimiento)
{
    fechaNacimiento = nacimiento;
}

String Suprema :: tipoBruja()
{
    return "Suprema";
}

int Suprema :: getPoder()
{
    Hechizos * aux = Bruja::getHechizos();
    int puntos = aux->calcularPuntos(2,4) + aux->largo();
    if(fechaNacimiento.getAnio() < 1900)
        puntos = puntos + 5;

    return puntos;
}


Suprema :: ~Suprema()
{

}
