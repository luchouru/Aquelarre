#ifndef COMUN_H_INCLUDED
#define COMUN_H_INCLUDED
#include "Bruja.h"
#include "Suprema.h"

class Comun : public Bruja{
private:
    String regionOrigen;
    bool vuelaEscoba;
    Suprema * supremaReporta;

public:
    Comun(String,String,String,bool,Suprema *);
    String getRegionOrigen();
    bool getVuelaEscoba();
    Suprema * getSupremaReporta();
    void setRegionOrigen(String);
    void setVuelaEscoba(bool);
    void setSupremaReporta(Suprema *);
    String tipoBruja();
    int getPoder();
    ~Comun();

};

#endif // COMUN_H_INCLUDED
