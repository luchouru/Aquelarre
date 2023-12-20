#ifndef SUPREMA_H_INCLUDED
#define SUPREMA_H_INCLUDED
#include "Bruja.h"
#include "Fecha.h"

class Suprema : public Bruja{
private:
    Fecha fechaNacimiento;
    int cantidadPoderes;

public:
    Suprema(String,String,Fecha,int);
    Fecha getFechaNacimiento();
    int getCantidadPoderes();
    void setFechaNacimiento(Fecha);
    String tipoBruja();
    int getPoder();
    ~Suprema();
};

#endif // SUPREMA_H_INCLUDED
