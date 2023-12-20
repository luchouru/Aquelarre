#ifndef HECHIZO_H_INCLUDED
#define HECHIZO_H_INCLUDED
#include "String.h"

class Hechizo {

private:
    int numero;
    String texto;

public:
    Hechizo(String);

    int getNumero();
    String getTexto();

    void setNumero(int);
    void setTexto(String);

    virtual String tipoHechizo();

    ~Hechizo();
};


#endif // HECHIZO_H_INCLUDED
