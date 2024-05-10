#include "persona.h"
#include <iostream>
#include <sstream>

Persona::Persona(std::string nombre, int habitacion, int docIden,int tipoMasaje)               :nombre(nombre), habitacion(habitacion), docIden(docIden), tipoMasaje(tipoMasaje){}

std::string definirMasaje(int tipoMasaje){
    std::string masaje;
    if(tipoMasaje == 1){
        masaje = "Chocolate";
    } else if (tipoMasaje == 2){
        masaje = "Piedras Volcanicas";
    } else if (tipoMasaje == 3) {
        masaje = "Piedras y Minerales";
    }
    return masaje;
}
std::string  Persona::to_string(){
    std::string masaje = definirMasaje(tipoMasaje);
    std::stringstream ss;
    ss << "Nombre: "<<nombre<<" / Documento de Identidad: "<<docIden<<" / Habitacion: "<<habitacion<<" / Tipo de masaje: "<<masaje<<std::endl;
    return ss.str();
}