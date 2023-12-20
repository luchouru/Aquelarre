#include "Hechizo.h"

Hechizo :: Hechizo(String txt) : texto(txt)
{
    numero=0;
}

int Hechizo :: getNumero()
{
    return numero;
}

String Hechizo :: getTexto()
{
    return texto;
}

void Hechizo :: setNumero(int num)
{
    numero=num;
}

void Hechizo :: setTexto(String txt)
{
    texto=txt;
}

String Hechizo :: tipoHechizo()
{
    return "Comun";
}

Hechizo :: ~Hechizo() {}
