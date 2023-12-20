#ifndef FACHADALOGICA_H_INCLUDED
#define FACHADALOGICA_H_INCLUDED
#include "Brujas.h"
#include "Hechizos.h"
#include "Especial.h"
#include "TipoError.h"

class FachadaLogica
{

private:
    Brujas abbBrujas;

public:
    FachadaLogica();

    //Req 1: Ingresar nueva suprema
    void ingresarBrujaSuprema(String, String, Fecha, int, TipoError&);

    //Req 2: Ingresar bruja comun
    void ingresarBrujaComun(String,String, String, String, bool, TipoError&);

    //Req 3: Listar brujas
    IteradorBrujas listarBrujas(TipoError&);

    //Req 4: Listar detalle de bruja
    IteradorBrujas listarDetalleBruja(String, TipoError&);

    //Req 5: Listar bruja suprema mayor
    Suprema * obtenerBrujaSupremaMayor(TipoError&);

    //Req 6: Registrar nuevo hechizo
    void registrarNuevoHechizo(String, String, TipoError&);
    void registrarNuevoHechizoEspecial(String, String, int, String, TipoError&);

    //Req 7: Listar hechizo de bruja
    Hechizo * listarHechizoBruja(String, int, TipoError&);

    //Req 8: Contar hechizos espciales de bruja en un anio
    int contarHechizosEspecialesEnAnio(String, int, TipoError&);

    ~FachadaLogica();
};


#endif // FACHADALOGICA_H_INCLUDED
