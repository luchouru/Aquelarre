#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <string.h>
#include "stdio.h"
#include <iostream>

using namespace std;


const int MAX = 80;

class String{
    private:
        char * cadena;

    public:
        String();
        String(char *);
        String(const String &);
        ~String();

        String operator= (const String &);
        bool operator== (String);
        bool operator!= (String);
        bool operator< (String);
        String operator+ (String);

        void scan();
        void print();
};


#endif // STRING_H_INCLUDED
