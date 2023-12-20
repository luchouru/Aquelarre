#include "String.h"

String :: String()
{
    cadena = new char[1];
    cadena[0] = '\0';
}

String :: String(char * cad)
{
    int largo = strlen(cad);
    cadena = new char[largo + 1];
    strcpy(cadena,cad);
}

String :: ~String()
{
    delete [] cadena;
}

String :: String(const String &otro)
{
    int largo = strlen(otro.cadena);
    cadena = new char[largo + 1];
    strcpy(cadena, otro.cadena);
}

String String :: operator=(const String &otro)
{
    if(this != &otro)
    {
        delete [] cadena;
        int largo = strlen(otro.cadena);
        cadena = new char[largo + 1];
        strcpy(cadena, otro.cadena);
    }

    return (*this);
 }

 bool String :: operator==(String otro)
 {
     return bool (strcmp(cadena,otro.cadena) == 0);
 }

  bool String :: operator!=(String otro)
 {
     return bool (strcmp(cadena,otro.cadena) != 0);
 }


 bool String :: operator<(String otro)
 {
     return bool (strcmp(cadena,otro.cadena) < 0);
 }

String String :: operator+(String otro)
{
    int largo = strlen(cadena) + strlen(otro.cadena);
    String aux;
    aux.cadena = new char[largo + 1];
    strcpy(aux.cadena,cadena);
    strcat(aux.cadena,otro.cadena);
    return aux;
}

void String :: scan()
{
    cin.getline(cadena,MAX,'\n');
}

void String :: print()
{
        cout << cadena;
}
