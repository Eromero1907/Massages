#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona{
    public:
        Persona(std::string nombre, int habitacion, int docIden, int tipoMasaje);
        void calcularTiempoEnSala();
        std::string to_string();
        std::string nombre;
        int tipoMasaje;
        int docIden;
        int habitacion;
};
#endif