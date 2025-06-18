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

void mostrarDados(int dados[], int cantidadDados){

    for(int i = 0; i<cantidadDados; i++){
        cout<<dados[i]<<"   ";
    }

}

void mostrarRondaActual(std::string nombre, int ronda, int puntaje){

    cout<<"Jugador: "<<nombre<<" | Ronda N°"<<ronda<<" | Puntaje: "<<puntaje<<endl;

}

void mostrarPuntajeDeRonda(int numRonda, int puntajeDeRonda){

    cout<<endl;
    cout<<"Tu puntaje de la ronda "<<numRonda<<" fue de: "<<puntajeDeRonda;
    cout<<endl;

    system("pause");
    system("cls");

}

void mostrarNumeroLanzamiento(int numLanzamiento){

    cout<<"-------"<<"Lanzamiento N°"<<numLanzamiento<<"-------"<<endl;

}

void mostrarPuntajeTirada(int puntajeTirada){

    cout<<"Puntaje de la tirada: "<<puntajeTirada;

    cout<<endl;
    system("pause");
    cout<<endl;

}

void mostrarCombinacion(int combinacion, int valorDado){

    const int RESETEAR = -1;
    const int SUMA = 1;
    const int MULTIPLICAR = 2;
    const int ESCALERA = 100;

    switch(combinacion){
        case ESCALERA:      cout<<"COMBINACION: Escalera"<<endl;                break;
        case SUMA:          cout<<"COMBINACION: Suma de dados"<<endl;           break;
        case RESETEAR:      cout<<"COMBINACION: Sexteto de 6"<<endl;            break;
        case MULTIPLICAR:   cout<<"COMBINACION: Sexteto de "<<valorDado<<endl;  break;
    }

}
