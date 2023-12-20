#ifndef BRUJA_H_INCLUDED
#define BRUJA_H_INCLUDED
#include "String.h"
#include "Hechizos.h"


class Bruja
{
private:
    String identificador;
    String nombre;
    Hechizos * hechizos;
public:
    Bruja(String, String);
    String getIdentificador();
    String getNombre();
    Hechizos * getHechizos();
    int contarHechizosEspecialesEnAnio(int);
    void setNombre(String);
    void setHechizo(Hechizo *);
    virtual String tipoBruja() = 0;
    virtual int getPoder() = 0;
    virtual ~Bruja ();
};

#endif // BRUJA_H_INCLUDED
