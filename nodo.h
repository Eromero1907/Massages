#ifndef NODO_H
#define NODO_H

#include <iostream>
#include "persona.h"
#include <ctime>
#include <string>

class Nodo{
    public:
        Persona persona;
        Nodo(Persona persona):persona(persona){}
};

#endif