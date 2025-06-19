#include <iostream>
#include "juego.h"
#include "interfaz.h"
#include "operaciones.h"
#include <ctime>
#include <cstdlib>

using namespace std;

std::string modoUnJugador(int infoPartida[]){

    int ESCALERA = -1, RESETEAR = -2, posRondas = 0, posPuntos = 1;
    std::string nombre = obtenerNombre();
    std::string ganador = "Sin ganador";
    int puntaje = 0;

    if(establecerRondas()){

        int rondas = obtenerCantidadRondas();

        for(int i = 0; i<rondas; i++){

            mostrarRondaActual(nombre, i+1, puntaje);

            puntaje = jugarTurno(puntaje, i+1);

            if(chequearGanador(puntaje, infoPartida, i+1)){

                mostrarGanador(nombre, puntaje, i+1);
                ganador = nombre;
                break;

            }

        }

        if(puntaje < 100 && puntaje != ESCALERA) mostrarJugadorPierde(nombre, puntaje);

    } else {

        int ronda = 1;

        while(true){

            mostrarRondaActual(nombre, ronda, puntaje);

            puntaje = jugarTurno(puntaje, ronda);

            if(chequearGanador(puntaje, infoPartida, ronda)){

                mostrarGanador(nombre, puntaje, ronda);
                ganador = nombre;
                break;

            }

            ronda++;

        }

    }

    return ganador;

}

std::string modoDosJugadores(int infoPartida[]){

    int ESCALERA = -1, RESETEO = -2, posRondas = 0, posPuntos = 1;
    string jugador1 = obtenerNombre();
    string jugador2 = obtenerNombre();
    string ganador = "Sin ganador";

    int puntaje1 = 0, puntaje2 = 0;
    int ronda = 1;
    bool hayGanador = false;

    if (establecerRondas()){

        int rondas = obtenerCantidadRondas();

        for (int i=0; i<rondas; i++){

            //Turno jugador 1
            mostrarRondaActual(jugador1, ronda, puntaje1);
            int puntos1 = jugarRonda();

            if (puntos1 == ESCALERA){

                infoPartida[posRondas] = ronda;
                infoPartida[posPuntos] = ESCALERA;

                mostrarGanador(jugador1, ESCALERA, ronda);

                ganador = jugador1;
                break;
            }
            else if (puntos1 == RESETEO){
                puntaje1 = 0;
                mostrarSeReseteanPuntos();
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
            if (puntos2 == ESCALERA){

                mostrarGanador(jugador2, ESCALERA, ronda);

                infoPartida[posRondas] = ronda;
                infoPartida[posPuntos] = ESCALERA;

                ganador = jugador2;
                break;
            }
            else if (puntos2 == RESETEO){
                puntaje2 = 0;
                mostrarSeReseteanPuntos();
            }
            else {
                puntaje2 += puntos2;
            }

            mostrarPuntajeParcial(jugador1, puntaje1, jugador2, puntaje2);

            if (puntaje1 >= 100 && (puntaje1 < puntaje2 || puntaje2 < 100)){

                    mostrarGanador(jugador1, puntaje1, ronda);

                    infoPartida[posRondas] = ronda;
                    infoPartida[posPuntos] = puntaje1;

                    ganador = jugador1;
                    break;
            }

            if (puntaje2 >= 100 && (puntaje2 < puntaje1 || puntaje1 < 100)){

                    mostrarGanador(jugador2, puntaje2, ronda);

                    infoPartida[posRondas] = ronda;
                    infoPartida[posPuntos] = puntaje2;

                    ganador = jugador2;
                    break;
                }

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

                mostrarGanador(jugador1, ESCALERA, ronda);

                infoPartida[posRondas] = ronda;
                infoPartida[posPuntos] = ESCALERA;

                ganador = jugador1;
                break;

            } else if (puntos1 == RESETEO){

                puntaje1 = 0;
                mostrarSeReseteanPuntos();

            } else {
                puntaje1 += puntos1;
            }

            mostrarPuntajeParcial(jugador1, puntaje1, jugador2, puntaje2);
            system("pause");
            system("cls");

            //Turno jugador 2
            mostrarRondaActual(jugador2, ronda, puntaje2);
            int puntos2 = jugarRonda();

            if (puntos2 == ESCALERA){

                mostrarGanador(jugador2, ESCALERA, ronda);

                infoPartida[posRondas] = ronda;
                infoPartida[posPuntos] = ESCALERA;

                ganador = jugador2;
                break;

            } else if (puntos2 == RESETEO) {

                puntaje2 = 0;
                mostrarSeReseteanPuntos();

            } else {
                puntaje2 += puntos2;
            }

            mostrarPuntajeParcial(jugador1, puntaje1, jugador2, puntaje2);

            if (puntaje1 >= 100 && (puntaje1 < puntaje2 || puntaje2 < 100)){
                    mostrarGanador(jugador1, puntaje1, ronda);

                    infoPartida[posRondas] = ronda;
                    infoPartida[posPuntos] = puntaje1;

                    ganador = jugador1;
                    break;
                }

            if (puntaje2 >= 100 && (puntaje2 < puntaje1 || puntaje1 < 100)){

                    mostrarGanador(jugador2, puntaje2, ronda);

                    infoPartida[posRondas] = ronda;
                    infoPartida[posPuntos] = puntaje2;

                    ganador = jugador2;
                    break;
                }

            system("pause");
            system("cls");

            ronda++;
        }

    }

    return ganador;

}

int jugarRonda(){

    int ESCALERA = -1, RESETEAR = -2;
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

    const int ESCALERA = -1;
    const int RESETEAR = -2;
    const int SUMA = 1;
    const int MULTIPLICAR = 2;

    int cantidadDados = 6, puntaje, combinacion;
    int dados[cantidadDados];

    for(int i = 0; i<6; i++){

        dados[i] = (rand()%6)+1;
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

void puntuacionMaxima(std::string nombre, int infoMejorJugada[]){

    int posRondas = 0, posPuntos = 1, ESCALERA = -1;

    if(infoMejorJugada[posPuntos] == ESCALERA){

        cout<<endl;
        cout<<"EL JUGADOR "<<nombre<<" GANO CON ESCALERA EN LA RONDA "<<infoMejorJugada[posRondas]<<" ALTA SUERTE TIENE EL LOCO"<<endl;

    } else if(nombre == "Sin ganador"){

        cout<<endl;
        cout<<"Aun no se han registrado victorias."<<endl;

    } else{

        cout<<endl;
        cout<<"El mejor jugador fue: "<<nombre<<endl;
        cout<<"Obtuvo un puntaje de "<<infoMejorJugada[posPuntos]<<" en "<<infoMejorJugada[posRondas]<<" rondas!"<<endl<<endl;

    }

}

std::string analizarInfoPartida(std::string nombreActual, std::string nombreJugador, int infoPartida[], int infoMejorPartida[]){

    int posRondas = 0, posPuntos = 1;

    if(nombreJugador == "Sin ganador") return nombreActual;

    if(infoPartida[posPuntos] <= infoMejorPartida[posPuntos] && infoPartida[posRondas] <= infoMejorPartida[posRondas]){

        infoMejorPartida[posRondas] = infoPartida[posRondas];
        infoMejorPartida[posPuntos] = infoPartida[posPuntos];
        return nombreJugador;
    }

    return nombreActual;

}


bool chequearGanador(int puntaje, int infoPartida[], int rondas){

    const int ESCALERA = -1,  posRondas = 0, posPuntos = 1;;

    if(puntaje >= 100 || puntaje == ESCALERA){
        infoPartida[posRondas] = rondas;
        infoPartida[posPuntos] = puntaje;
        return true;
    }

    return  false;

}

int jugarTurno(int puntosActuales, int ronda){

    const int ESCALERA = -1, RESETEO = -2;

    int puntosDeRonda = jugarRonda();

    switch(puntosDeRonda){

        case ESCALERA:  return ESCALERA;
        case RESETEO:   mostrarSeReseteanPuntos();  return 0;
        default:        mostrarPuntajeDeRonda(ronda, puntosDeRonda);  return puntosDeRonda + puntosActuales;

    }

}
