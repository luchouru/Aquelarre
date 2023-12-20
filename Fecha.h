#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha {

private:
    int dia, mes, anio;

    Fecha sumaDia();
    Fecha restaDia();
    bool esBisiesto();

public:
    Fecha();
    Fecha(int,int,int);

    int getDia();
    int getMes();
    int getAnio();
    void setDia(int);
    void setMes(int);
    void setAnio(int);

    Fecha (const Fecha &);

    ~Fecha();

    bool operator<(Fecha);
    bool operator==(Fecha);
    Fecha operator++(); //prefijo
    Fecha operator++(int); //postfijo
    Fecha operator+(int);
    int operator-(Fecha);
    bool esValida();

};


#endif // FECHA_H_INCLUDED
