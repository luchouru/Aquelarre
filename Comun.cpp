#include "Comun.h"

Comun :: Comun(String id, String nombre, String region, bool escoba, Suprema * reporta) : Bruja(id,nombre), regionOrigen(region)
{
    vuelaEscoba = escoba;
    supremaReporta = reporta;
}

String Comun :: getRegionOrigen()
{
    return regionOrigen;
}

bool Comun :: getVuelaEscoba()
{
    return vuelaEscoba;
}

Suprema * Comun :: getSupremaReporta()
{
    return supremaReporta;
}

void Comun:: setRegionOrigen(String region)
{
    regionOrigen = region;
}

void Comun :: setSupremaReporta(Suprema * reporta)
{
    supremaReporta = reporta;
}

String Comun :: tipoBruja()
{
    return "Comun";
}

int Comun :: getPoder()
{
    Hechizos * aux = Bruja :: getHechizos();
    int puntos = aux->calcularPuntos(1,2);
    if(regionOrigen == "Salem")
        puntos = puntos + 1;

    return puntos;
}


Comun :: ~Comun()
{
}
