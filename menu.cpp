#include <iostream>
void mostrarMenu(){
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"SPAM"<<std::endl;
    std::cout<<"1. Agregar reserva"<<std::endl;
    std::cout<<"2. Cancelar reserva"<<std::endl;
    std::cout<<"3. Mostrar lista de reservas"<<std::endl;
    std::cout<<"4. Mostrar turno actual"<<std::endl;
    std::cout<<"5. Finalizar programa"<<std::endl;
}

int obtenerOpcion(){
    int opcion;
    std::cout << "Ingrese una opcion: ";
    std::cin >> opcion;
    return opcion;
}