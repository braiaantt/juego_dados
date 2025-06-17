#include <iostream>
#include "interfaz.h"

using namespace std;

std::string obtenerNombre(){

    system("cls");
    std::string nombre;
    cout<<"Ingrese su nombre: "; cin>>nombre;
    system("cls");
    return nombre;

}

bool establecerRondas(){

    char respuesta;
    cout<<"Quiere establecer un numero maximo de rondas? s/n "<<endl; cin>>respuesta;

    while(respuesta != 's' && respuesta != 'n'){
        system("cls");
        cout<<"Responda con 's' para SI o 'n' para NO: "; cin>>respuesta;
    }

    system("cls");

    if(respuesta == 's'){
        return true;
    } else {
        return false;
    }

}

int obtenerCantidadRondas(){

    int rondas;
    cout<<"Ingrese numero maximo de rondas: "; cin>>rondas;

    while(rondas <= 0){
        system("cls");
        cout<<"Ingrese un numero mayor que 0"; cin>>rondas;
    }

    system("cls");
    return rondas;

}
