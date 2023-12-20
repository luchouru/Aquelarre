#include "FachadaLogica.h"

FachadaLogica :: FachadaLogica(): abbBrujas() {}

FachadaLogica :: ~FachadaLogica() {}


//Req 1: Ingresar nueva suprema
void FachadaLogica :: ingresarBrujaSuprema(String id, String nombre, Fecha fechaNac, int cantPoderes, TipoError &error)
{
    error = SIN_ERROR;
    if(abbBrujas.member(id))
    {
        error = BRUJA_YA_EXISTE;
    }
    else
    {
        Suprema * nuevaBruja = new Suprema(id, nombre, fechaNac, cantPoderes);
        abbBrujas.insert(nuevaBruja);
    }
}

//Req 2: Ingresar bruja comun
void FachadaLogica :: ingresarBrujaComun(String idSuprema, String id, String nombre, String regionOrigen, bool vuelaEscoba, TipoError &error)
{
    error = SIN_ERROR;
    if(abbBrujas.member(id))
    {
        error = BRUJA_YA_EXISTE;
    }
    else
    {
        if(!abbBrujas.member(idSuprema))
        {
            error = BRUJA_NO_EXISTE;
        }
        else
        {
            Bruja * brujaEncontrada = abbBrujas.find(idSuprema);
            if(brujaEncontrada->tipoBruja()!="Suprema")
            {
                error = NO_ES_BRUJA_SUPREMA;
            }
            else
            {
                Suprema * brujaSuprema = (Suprema *)brujaEncontrada;
                Comun * nuevaBruja = new Comun(id, nombre, regionOrigen,vuelaEscoba, brujaSuprema);
                abbBrujas.insert(nuevaBruja);
            }
        }
    }
}

//Req 3: Listar brujas
IteradorBrujas FachadaLogica :: listarBrujas(TipoError &error)
{
    error = SIN_ERROR;
    if(abbBrujas.empty())
    {
        error = NO_HAY_BRUJAS;
    }
    else
    {
        return abbBrujas.listarBrujas();

    }
}

//Req 4: Listar detalle de bruja
IteradorBrujas FachadaLogica :: listarDetalleBruja(String id, TipoError &error)
{
    IteradorBrujas iter = IteradorBrujas();
    error = SIN_ERROR;

    if(!abbBrujas.member(id))
        error = BRUJA_NO_EXISTE;
    else
    {
        Bruja * brujaEncontrada = abbBrujas.find(id);
        iter.insertar(brujaEncontrada);
        if(brujaEncontrada->tipoBruja() == "Comun")
        {
            Comun * brujaComun = (Comun *) brujaEncontrada;
            Suprema * reporta = brujaComun->getSupremaReporta();
            iter.insertar(abbBrujas.find(reporta->getIdentificador()));
        }
    }
    return iter;
}

//Req 5: Listar bruja suprema mayor
Suprema * FachadaLogica :: obtenerBrujaSupremaMayor(TipoError &error)
{
    error = SIN_ERROR;
    if(abbBrujas.empty())
    {
        error = NO_HAY_BRUJAS;
    }
    else
    {
        return abbBrujas.obtenerBrujaSupremaMayor();
    }
}

//Req 6: Registrar nuevo hechizo
void FachadaLogica :: registrarNuevoHechizo(String idBruja, String txt, TipoError &error)
{
    error = SIN_ERROR;
    Hechizo * nuevo = NULL;
    Hechizos * secuencia;
    //Control existencia bruja

    if(!abbBrujas.member(idBruja))
    {
        error = BRUJA_NO_EXISTE;
    }
    else
    {
        Bruja * actual = abbBrujas.find(idBruja);
        secuencia = actual->getHechizos();

        if(secuencia->estaLlena())
        {
            error = MAXIMO_HECHIZOS;
        }
        else
        {
            nuevo = new Hechizo(txt);
            actual->setHechizo(nuevo);
        }

    }
}

//Req 6: Registrar nuevo hechizo Especial
void FachadaLogica :: registrarNuevoHechizoEspecial(String idBruja, String txt, int anio, String desc, TipoError &error)
{
    error = SIN_ERROR;
    Hechizo * nuevo = NULL;
    Hechizos * secuencia = NULL;
    //Control existencia bruja y otros errores
    if(!abbBrujas.member(idBruja))
    {
        error = BRUJA_NO_EXISTE;
    }
    else
    {
        Bruja * actual = abbBrujas.find(idBruja);
        secuencia = actual->getHechizos();
        if(secuencia->estaLlena())
        {
            error = MAXIMO_HECHIZOS;
        }
        else
        {
            nuevo = new Especial(txt,anio,desc);
            secuencia->insBack(nuevo);
        }

    }
}

//Req 7: listar Hechizo
Hechizo * FachadaLogica :: listarHechizoBruja(String idBruja, int numHc, TipoError &error)
{
    error = SIN_ERROR;
    if(!abbBrujas.member(idBruja))
    {
        error = BRUJA_NO_EXISTE;
    }
    else
    {
        Hechizos *phc = abbBrujas.find(idBruja)->getHechizos();
        if(numHc <= 0 || phc->largo() < numHc)
            error = HECHIZO_NO_EXISTE;
        else
            return phc->kesimo(numHc - 1);
    }
}


//Req 8: Contar hechizos espciales de bruja en un anio
int FachadaLogica :: contarHechizosEspecialesEnAnio(String idBruja, int anio, TipoError &error)
{
    int cantidadHechizos =0;
    error = SIN_ERROR;

    if(!abbBrujas.member(idBruja))
    {
        error = BRUJA_NO_EXISTE;
    }
    else
    {
        cantidadHechizos = abbBrujas.find(idBruja) -> contarHechizosEspecialesEnAnio(anio);
    }

    return cantidadHechizos;
}

