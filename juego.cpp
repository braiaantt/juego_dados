#include <iostream>
#include "juego.h"
#include "interfaz.h"
#include "operaciones.h"
#include <ctime>
#include <cstdlib>

using namespace std;

std::string modoUnJugador(int infoPartida[], bool partidaSimulada){

    int ESCALERA = -1;
    std::string nombre = obtenerNombre();
    std::string ganador = "Sin ganador";
    int puntaje = 0, ronda = 1, rondasEstablecidas = -1;

    if(establecerRondas()) rondasEstablecidas = obtenerCantidadRondas();

    while(rondasEstablecidas != 0){

        mostrarRondaActual(nombre, ronda, puntaje);

        puntaje = jugarTurno(puntaje, ronda, partidaSimulada);

        if(chequearGanador(puntaje)){

            guardarInfoPartida(infoPartida, puntaje, ronda);
            mostrarGanador(nombre, puntaje, ronda);
            ganador = nombre;
            break;

        }

        ronda++;
        rondasEstablecidas--;

    }

    if(puntaje < 100 && puntaje != ESCALERA) mostrarJugadorPierde(nombre, puntaje);

    return ganador;

}

std::string modoDosJugadores(int infoPartida[]){

    int ESCALERA = -1;
    string jugador1 = obtenerNombre();
    string jugador2 = obtenerNombre();
    string ganador = "Sin ganador";

    int puntaje1 = 0, puntaje2 = 0;
    int ronda = 1, rondasEstablecidas = -1;

    if(establecerRondas()) rondasEstablecidas = obtenerCantidadRondas();

    while(rondasEstablecidas != 0){

        //Turno jugador 1
        mostrarRondaActual(jugador1, ronda, puntaje1);

        puntaje1 = jugarTurno(puntaje1, ronda, false);

        if(puntaje1 == ESCALERA){

            guardarInfoPartida(infoPartida, ESCALERA, ronda);
            mostrarGanador(jugador1, puntaje1, ronda);
            ganador = jugador1;
            break;

        }

        mostrarPuntajeParcial(jugador1, puntaje1, jugador2, puntaje2);

        //Turno jugador 2
        mostrarRondaActual(jugador2, ronda, puntaje2);

        puntaje2 = jugarTurno(puntaje2, ronda, false);

        if(puntaje2 == ESCALERA){

            guardarInfoPartida(infoPartida, ESCALERA, ronda);
            mostrarGanador(jugador2, puntaje2, ronda);
            ganador = jugador2;
            break;

        }

        mostrarPuntajeParcial(jugador1, puntaje1, jugador2, puntaje2);

        int idGanador = obtenerGanador(puntaje1, puntaje2);

        if(idGanador == 1){

            guardarInfoPartida(infoPartida, puntaje1, ronda);
            mostrarGanador(jugador1, puntaje1, ronda);
            ganador = jugador1;
            break;

        } else if(idGanador == 2){

            guardarInfoPartida(infoPartida, puntaje2, ronda);
            mostrarGanador(jugador2, puntaje2, ronda);
            ganador = jugador2;
            break;

        } else if(idGanador == 3){
            //jugar empate
        }

        ronda++;
        rondasEstablecidas--;
    }

    return ganador;

}

int jugarTurno(int puntosActuales, int ronda, bool partidaSimulada){

    const int ESCALERA = -1, RESETEO = -2;

    int puntosDeRonda = jugarRonda(partidaSimulada);

    switch(puntosDeRonda){

        case ESCALERA:  return ESCALERA;
        case RESETEO:   mostrarSeReseteanPuntos();  return 0;
        default:        mostrarPuntajeDeRonda(ronda, puntosDeRonda);  return puntosDeRonda + puntosActuales;

    }

}

int jugarRonda(bool partidaSimulada){

    int ESCALERA = -1, RESETEAR = -2;
    int lanzamientos = 3;
    int puntos[lanzamientos];

    for(int i = 0; i<lanzamientos; i++){

        mostrarNumeroLanzamiento(i+1);

        int puntajeTirada = tirarDados(partidaSimulada);

        if(puntajeTirada == ESCALERA) return ESCALERA;
        if(puntajeTirada == RESETEAR) return RESETEAR;

        puntos[i] = puntajeTirada;

        mostrarPuntajeTirada(puntajeTirada);

    }

    return obtenerPuntajeMaximo(puntos, lanzamientos);

}

int tirarDados(bool partidaSimulada){

    const int ESCALERA = -1;
    const int RESETEAR = -2;
    const int SUMA = 1;
    const int MULTIPLICAR = 2;

    int cantidadDados = 6, puntaje, combinacion;
    int dados[cantidadDados];

    for(int i = 0; i<6; i++){

        if(partidaSimulada) dados[i] = pedirValorDado(i+1);
        if(!partidaSimulada) dados[i] = (rand()%6)+1;

    }

    combinacion = analizarCombinacion(dados, cantidadDados);

    mostrarDados(dados, cantidadDados);

    switch(combinacion){
        case RESETEAR:      mostrarCombinacion(RESETEAR, dados[0]);     puntaje = RESETEAR; break;
        case SUMA:          mostrarCombinacion(SUMA, dados[0]);         puntaje = calcularCombinacion(dados, cantidadDados, SUMA); break;
        case MULTIPLICAR:   mostrarCombinacion(MULTIPLICAR, dados[0]);  puntaje = calcularCombinacion(dados, cantidadDados, MULTIPLICAR); break;
        case ESCALERA:      mostrarCombinacion(ESCALERA, dados[0]);     puntaje = ESCALERA; break;
    }

    return puntaje;

}


bool chequearGanador(int puntaje){

    const int ESCALERA = -1;

    if(puntaje >= 100 || puntaje == ESCALERA) return true;

    return  false;

}

void guardarInfoPartida(int infoPartida[], int puntaje, int rondas){

    int posRondas = 0, posPuntos = 1;
    infoPartida[posRondas] = rondas;
    infoPartida[posPuntos] = puntaje;

}

int obtenerGanador(int puntaje1, int puntaje2){

    if(puntaje1 >= 100 && puntaje2 >= 100){ //Caso ambos superan el objetivo de puntos en la misma cantidad de rondas
            if(puntaje1 < puntaje2) return 1;
            if(puntaje1 > puntaje2) return 2;
            return 3;
    }

    //Si los jugadores no ganan al mismo tiempo, alguno ganó o no gano ninguno

    if(puntaje1 >= 100) return 1; //Caso jugador 1 gana
    if(puntaje2 >= 100) return 2; //Caso jugador 2 gana

    return 0; //No hay ganador
}
