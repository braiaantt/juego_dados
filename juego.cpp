#include <iostream>
#include "juego.h"
#include "interfaz.h"
#include <ctime>
#include <cstdlib>

using namespace std;

void modoUnJugador(){

    std::string nombre = obtenerNombre();
    int puntaje = 0;

    if(establecerRondas()){
        int rondas = obtenerCantidadRondas();

        for(int i = 0; i<rondas; i++){
            mostrarRondaActual(nombre, i+1, puntaje);
            int puntosDeRonda = jugarRonda();
            puntaje += puntosDeRonda;
            cout<<endl<<"Tu puntaje de la ronda "<<i+1<<" fue de: "<<puntosDeRonda<<endl;
            system("pause");
            system("cls");
        }



    } else {

        cout<<"Aca se juega hasta que termine la partida senior "<<nombre<<endl;

    }

}

int jugarRonda(){

    int ESCALERA = 100, RESETEAR = -1;
    int lanzamientos = 3;
    int puntos[lanzamientos];

    for(int i = 0; i<lanzamientos; i++){
        cout<<"-------"<<"Lanzamiento N°"<<i+1<<"-------"<<endl;
        int puntajeTirada = tirarDados();

        if(puntajeTirada == ESCALERA) return ESCALERA;
        if(puntajeTirada == RESETEAR) return RESETEAR;

        puntos[i] = puntajeTirada;
        cout<<"Puntaje de la tirada: "<<puntajeTirada<<endl;
        system("pause");
        cout<<endl;

    }

    return obtenerPuntajeMaximo(puntos, lanzamientos);

}

int tirarDados(){

    const int RESETEAR = -1;
    const int SUMA = 1;
    const int MULTIPLICAR = 2;
    const int ESCALERA = 100;

    int cantidadDados = 6, puntaje, combinacion;
    int dados[cantidadDados];
    std::string tipoCombinacion;

    for(int i = 0; i<6; i++){
        dados[i] = (rand()%6)+1;
    }

    combinacion = analizarCombinacion(dados, cantidadDados);

    mostrarDados(dados, cantidadDados);

    switch(combinacion){
        case ESCALERA:      cout<<"Combinacion: Escalera"<<endl;                  puntaje = ESCALERA; break;
        case SUMA:          cout<<"Combinacion: Suma de dados"<<endl;             puntaje = calcularCombinacion(dados, cantidadDados, SUMA); break;
        case RESETEAR:      cout<<"Combinacion: Sexteto de 6"<<endl;              puntaje = RESETEAR; break;
        case MULTIPLICAR:   cout<<"Combinacion: Sexteto de "<<dados[0]<<endl;     puntaje = calcularCombinacion(dados, cantidadDados, MULTIPLICAR); break;
    }

    return puntaje;

}

int calcularCombinacion(int dados[], int cantidadDados, int combinacion){

    int SUMA = 1, MULTIPLICAR = 2, resultado = 0;

    if(combinacion == SUMA){

        for(int i = 0; i<cantidadDados; i++){
            resultado += dados[i];
        }

    } else if(combinacion == MULTIPLICAR){

        resultado = dados[0] * 10;

    }

    return resultado;

}

int analizarCombinacion(int dados[], int cantidadDados){

    int RESETEAR = -1;
    int SUMA = 1;
    int MULTIPLICAR = 2;
    int ESCALERA = 100;

    //se ordenan los dados
    for(int i = 0; i<cantidadDados-1; i++){

        int posMin = i;
        int aux;

        for(int j = i+1; j<cantidadDados; j++){
            if(dados[j]<dados[posMin]) posMin=j;
        }

        aux = dados[i];
        dados[i] = dados[posMin];
        dados[posMin] = aux;
    }

    int contCoincidencias = 1, contEscalera = 1;
    int dadoReferencia = dados[0];

    for(int i = 1; i<cantidadDados; i++){
        if(dados[0] == dados[i]) contCoincidencias++;
        if(dadoReferencia+1 == dados[i]){
            dadoReferencia = dados[i];
            contEscalera++;
        }
    }

    if(contCoincidencias == 6 && dadoReferencia == 6) return RESETEAR;
    if(contCoincidencias == 6) return MULTIPLICAR;
    if(contEscalera == 6) return ESCALERA;

    return SUMA;

}

int obtenerPuntajeMaximo(int puntos[], int cantidadPuntos){

    int posMax=0;

    for(int i = 1; i<cantidadPuntos ;i++){

        if(puntos[i]>puntos[posMax]) {
                posMax=i;
        }

    }

    return puntos[posMax];

}

void modoDosJugadores(){

    cout<<"Usted ha seleccionado el modo juego en duelo"<<endl;

}

void puntuacionMaxima(){

    cout<<"Usted quiere ver la puntuacion maxima"<<endl;

}
