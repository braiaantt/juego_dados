#include <iostream>
#include "juego.h"
#include "interfaz.h"
#include "operaciones.h"
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

            mostrarPuntajeDeRonda(i+1, puntosDeRonda);

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

        mostrarNumeroLanzamiento(i+1);

        int puntajeTirada = tirarDados();

        if(puntajeTirada == ESCALERA) return ESCALERA;
        if(puntajeTirada == RESETEAR) return RESETEAR;

        puntos[i] = puntajeTirada;

        mostrarPuntajeTirada(puntajeTirada);

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

    for(int i = 0; i<6; i++){
        dados[i] = (rand()%6)+1;
    }

    combinacion = analizarCombinacion(dados, cantidadDados);

    mostrarDados(dados, cantidadDados);

    switch(combinacion){
        case RESETEAR:      mostrarCombinacion(RESETEAR, dados[0]);         puntaje = ESCALERA; break;
        case SUMA:          mostrarCombinacion(SUMA, dados[0]);         puntaje = calcularCombinacion(dados, cantidadDados, SUMA); break;
        case MULTIPLICAR:   mostrarCombinacion(MULTIPLICAR, dados[0]);  puntaje = RESETEAR; break;
        case ESCALERA:      mostrarCombinacion(ESCALERA, dados[0]);     puntaje = calcularCombinacion(dados, cantidadDados, MULTIPLICAR); break;
    }

    return puntaje;

}

void modoDosJugadores(){

    cout<<"Usted ha seleccionado el modo juego en duelo"<<endl;

}

void puntuacionMaxima(){

    cout<<"Usted quiere ver la puntuacion maxima"<<endl;

}
