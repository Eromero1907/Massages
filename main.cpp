//g++ main.cpp nodo.cpp persona.cpp -o programa
#include <Windows.h>

#include <iostream>
#include "persona.h"
#include "nodo.h"
#include "menu.cpp"
#include "main.h"

int const MAX_CLIENTES = 16;
int const TARIFA_CHOCOLATE = 60;
int const TARIFA_VOLCANICA = 70;
int const TARIFA_MINERALES = 80;
int reservasDisponibles = 16;
int reservasOcupadas = 0;
int docIdenDos;
Nodo* spam[MAX_CLIENTES];

int horaMomento(int actual){
    int turno = 0;
    int inicio = 800;
    int final = 830;
    for(int i = 0; i < 17; i+=2){
        if(actual >= inicio && actual < final){
            turno = i;
            break;
        }
        inicio += 100;
        final += 100;
    }
    int comienzo = 830;
    int finalizar = 900;
    for(int i = 1; i < 17; i+=2){
        if(actual >= comienzo && actual < finalizar){
            turno = i;
            break;
        }
        comienzo += 100;
        finalizar += 100;
    }

    return turno;
}

void atenderMenu(int opcion, Nodo* (&spam)[16]){
    switch(opcion){
        case 1:{
            std::cout<<"---------------------------------"<<std::endl;
            std::string nombre;
            int habitacion, docIden, horaMasaje, tipoMasaje, horaActual;
            std::cout<<"Ingrese el nombre del cliente: ";
            std::cin >> nombre;
            std::cout<<"Ingrese el numero de habitacion del huesped: ";
            std::cin >> habitacion;
            std::cout<<"Ingrese el documento de identidad: ";
            std::cin >> docIden;
            std::cout<<"Ingrese el tipo de masaje deseado(1 para  Chocolate, 2 para Volcanica y 3 para Mineral): ";
            std::cin >> tipoMasaje;
            std::cout<<"Ingrese la hora actual: ";
            std::cin>> horaActual;
            int turno = horaMomento(horaActual);
            bool libre = false;

            if(!libre && turno < MAX_CLIENTES){
                Nodo* item = spam[turno];
                if(item == nullptr){
                    libre = true;
                } else {
                    std::cout<<"El servicio ya está ocupado para esa hora"<<std::endl;
                }
            } else {
                std::cout<<"El servicio no se encuentra disponible"<<std::endl;
            }

            if(libre){
                spam[turno] = new Nodo(Persona(nombre, habitacion, docIden,tipoMasaje));
                reservasOcupadas++;
                if(tipoMasaje == 1){
                    std::cout<<"Cliente agregado exitosiamente, su turno es el "<<turno<<" y el valor de ese tipo de masaje es de "<<std::to_string(TARIFA_CHOCOLATE)<<" dolares"<<std::endl;
                } else if(tipoMasaje == 2){
                    std::cout<<"Cliente agregado exitosiamente, su turno es el "<<turno<<" y el valor de ese tipo de masaje es de "<<std::to_string(TARIFA_VOLCANICA)<<" dolares"<<std::endl;
                } else if(tipoMasaje == 3){
                    std::cout<<"Cliente agregado exitosiamente, su turno es el "<<turno<<" y el valor de ese tipo de masaje es de "<<std::to_string(TARIFA_MINERALES)<<" dolares"<<std::endl;
                } else {
                    std::cout<<"El tipo de masaje ingresado no existe. Ingrese una tipo de masaje valido."<<std::endl;
                }
                }
        break; 
        }
        case 2:{
            std::cout<<"---------------------------------"<<std::endl;
            std::cout<<"Ingrese el documento de identidad del cliente a remover: ";
            std::cin>>docIdenDos;
            int silla = 0;
            bool encontrado = false;
            for(int i = 0; i < MAX_CLIENTES; i++){
                Nodo* item = spam[i];
                if(item != nullptr){
                    if(item->persona.docIden == docIdenDos){
                        encontrado = true;
                        silla = i;
                        break;
                    }
                }
            }
            if(encontrado){
                spam[silla] = nullptr;
                reservasOcupadas--;
                std::cout<<"El cliente fue removido con exito"<<std::endl;
            } else {
                std::cout<<"La persona con ese ID no se encuentra en las reservas programadas"<<std::endl;
            }
            break;
        }
        case 3:{
            std::cout<<"---------------------------------"<<std::endl;
            std::cout <<"Reservas Totales: "<<std::to_string(MAX_CLIENTES)<<std::endl;
            std::cout <<"Reservas Ocupadas: "<<std::to_string(reservasOcupadas)<<std::endl;
            for(int i = 0; i < MAX_CLIENTES; i++){
                if(spam[i]==nullptr){
                    std::cout<<"["<<std::to_string(i)<<"] LIBRE"<<std::endl;
                } else {
                    std::cout<<"["<<std::to_string(i)<<"] Cliente: "<<spam[i]->persona.to_string()<<" Con el turno: "<<std::to_string(i)<<std::endl;
                }
            }
            break;
        }
        case 4:{
            std::cout<<"---------------------------------"<<std::endl;
            int horaActual;
            std::cout<<"Ingrese la hora actual: ";
            std::cin>>horaActual;
            int numTurno = horaMomento(horaActual);
            if(spam[numTurno]==nullptr){
                std::cout<<"A esta hora no estamos atendiendo ningún turno"<<std::endl;
            } else {
                std::cout<<"A esta hora estamos atendiendo al turno: "<<numTurno<<std::endl;
            }
            break;
        }
        default:{
            std::cout<<"Opcion invalida"<<std::endl;
            break;
        }
    }
}

void NewFunction(){
    Persona* item = nullptr;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int opcion;
    bool terminar = false;

    Nodo* spam[MAX_CLIENTES];
    for(int i = 0; i < MAX_CLIENTES; i++){
        spam[i] = nullptr;
    }

    while(!terminar){
        mostrarMenu();
        opcion = obtenerOpcion();
        if(opcion == 5){
            terminar = true;
        } else {
            atenderMenu(opcion, spam);
        }
    }
    std::cout<<"Gracias por usar nuestro sistema de servicios SPAM!"<<std::endl;
    return 0;
}