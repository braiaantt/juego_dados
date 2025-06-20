#include <iostream>
#include "operaciones.h"

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

    int ESCALERA = -1;
    int RESETEAR = -2;
    int SUMA = 1;
    int MULTIPLICAR = 2;

    ordenarDados(dados, cantidadDados);

    int contCoincidencias = 1, contEscalera = 1;
    int dadoReferencia = dados[0];

    for(int i = 1; i<cantidadDados; i++){

        if(dados[0] == dados[i]) contCoincidencias++; //Se evalua si todos los numeros son iguales tomando como referencia el primer valor

        if(dadoReferencia+1 == dados[i]){ //Se evalua si hay escalera
            dadoReferencia = dados[i];
            contEscalera++;
        }
    }

    if(contCoincidencias == 6 && dadoReferencia == 6) return RESETEAR;
    if(contCoincidencias == 6) return MULTIPLICAR;
    if(contEscalera == 6) return ESCALERA;

    return SUMA;

}

void ordenarDados(int dados[], int cantidadDados){

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
