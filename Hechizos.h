#ifndef HECHIZOS_H_INCLUDED
#define HECHIZOS_H_INCLUDED
#include "Hechizo.h"
#include "Especial.h"

const int TAMANIO = 20;

class Hechizos {

private:
    Hechizo * arre[TAMANIO];
    int tope;

    void destruirHechizos();

public:
    Hechizos();

    void insBack(Hechizo *);
    bool esVacia();
    int largo();
    Hechizo * kesimo(int);
    int contarHechizosEspecialesEnAnio(int);
    int calcularPuntos(int, int);
    bool estaLlena();
    ~Hechizos();
};

#endif // HECHIZOS_H_INCLUDED
