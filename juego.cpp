#include <iostream>
#include "juego.h"
#include "interfaz.h"
#include "operaciones.h"
#include <ctime>
#include <cstdlib>

using namespace std;

void modoUnJugador(){

    int ESCALERA = 100, RESETEAR = -1;
    std::string nombre = obtenerNombre();
    int puntaje = 0;

    if(establecerRondas()){

        int rondas = obtenerCantidadRondas();

        for(int i = 0; i<rondas; i++){

            mostrarRondaActual(nombre, i+1, puntaje);

            int puntosDeRonda = jugarRonda();

            if (puntosDeRonda == ESCALERA){
                mostrarJugadorGanaPorEscalera(nombre);
                break;
            }

            if (puntosDeRonda == RESETEAR){
                mostrarSeReseteanPuntos(nombre);
                puntaje = 0;
            }

            puntaje += puntosDeRonda;

            mostrarPuntajeDeRonda(i+1, puntosDeRonda);

            if(puntaje >= 100){
                mostrarJugadorGana(nombre, puntaje, i+1);
                break;
            }

        }

        if(puntaje < 100) mostrarJugadorPierde(nombre, puntaje);

    } else {

        int ronda = 1;

        while(true){

            mostrarRondaActual(nombre, ronda, puntaje);

            int puntosDeRonda = jugarRonda();

            if (puntosDeRonda == ESCALERA){
                mostrarJugadorGanaPorEscalera(nombre);
                break;
            }

            if (puntosDeRonda == RESETEAR){
                mostrarSeReseteanPuntos(nombre);
                puntaje = 0;
            }

            puntaje += puntosDeRonda;

            mostrarPuntajeDeRonda(ronda, puntosDeRonda);
            ronda++;

            if(puntaje >= 100){
                mostrarJugadorGana(nombre, puntaje, ronda);
                break;
            }

        }

    }

}

void modoDosJugadores(){


    string jugador1 = obtenerNombre();
    string jugador2 = obtenerNombre();

    int puntaje1 = 0, puntaje2 = 0;
    int ronda = 1;
    bool hayGanador = false;

    if (establecerRondas()){

        int rondas = obtenerCantidadRondas();

        for (int i=0; i<rondas; i++){

            //Turno jugador 1
            mostrarRondaActual(jugador1, ronda, puntaje1);
            int puntos1 = jugarRonda();
            if (puntos1 == 100){
                mostrarJugadorGanaPorEscalera(jugador1);
                return;
            }
            else if (puntos1 == -1){
                puntaje1 = 0;
                mostrarSeReseteanPuntos(jugador1);
            }
            else {
                puntaje1 += puntos1;
            }

            mostrarPuntajeParcial (jugador1, puntaje1, jugador2, puntaje2);
            system("pause");
            system("cls");

            //Turno jugador 2
            mostrarRondaActual(jugador2, ronda, puntaje2);
            int puntos2 = jugarRonda();
            if (puntos2 == 100){
                mostrarJugadorGanaPorEscalera(jugador2);
                return;
            }
            else if (puntos2 == -1){
                puntaje2 = 0;
                mostrarSeReseteanPuntos(jugador2);
            }
            else {
                puntaje2 += puntos2;
            }

            mostrarPuntajeParcial(jugador1, puntaje1, jugador2, puntaje2);
            system("pause");
            system("cls");

            ronda++;
        }

    } else {

        while(!hayGanador){

            //Turno jugador 1
            mostrarRondaActual(jugador1, ronda, puntaje1);
            int puntos1 = jugarRonda();

            if (puntos1 == 100) {
                mostrarJugadorGanaPorEscalera(jugador1);
                return;
            } else if (puntos1 == -1) {
                puntaje1 = 0;
                mostrarSeReseteanPuntos(jugador1);
            } else {
                puntaje1 += puntos1;
                if (puntaje1 >= 100){
                    mostrarJugadorGana(jugador1);
                    return;
                }
            }

            mostrarPuntajeParcial(jugador1, puntaje1, jugador2, puntaje2);
            system("pause");
            system("cls");

            //Turno jugador 2
            mostrarRondaActual(jugador2, ronda, puntaje2);
            int puntos2 = jugarRonda();
            if (puntos2 == 100)
                mostrarJugadorGanaPorEscalera(jugador2);
                return;
            } else if (puntos2 == -1) {
                puntaje2 = 0;
                mostrarSeReseteanPuntos(jugador2);
            } else {
                puntaje2 += puntos2;
                if (puntaje2 >= 100){
                    mostrarJugadorGana(jugador2);
                    return;
                }
            }

            mostrarPuntajeParcial(jugador1, puntaje1, jugador2, puntaje2);
            system("pause");
            system("cls");

            ronda++;
        }

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

void puntuacionMaxima(){

    cout<<"Usted quiere ver la puntuacion maxima"<<endl;

}
