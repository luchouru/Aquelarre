#ifndef ESPECIAL_H_INCLUDED
#define ESPECIAL_H_INCLUDED
#include "Hechizo.h"

class Especial : public Hechizo
{
private:
    int anioManifiesto;
    String descripcion;

public:
    Especial (String, int, String);
    int getAnioManifiesto();
    String getDescripcion();
    void setAnioManifiesto(int);
    void setDescripcion(String);

    String tipoHechizo();

    ~Especial();
};


#endif // ESPECIAL_H_INCLUDED
