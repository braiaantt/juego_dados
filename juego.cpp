#include <iostream>
#include "juego.h"
#include "interfaz.h"

using namespace std;

void jugarConRondasLimitadas();
void jugarHastaFinalizar();

void modoUnJugador(){

    std::string nombre = obtenerNombre();

    if(establecerRondas()){
        int rondas = obtenerCantidadRondas();

        for(int i = 0; i<rondas; i++){
            cout<<"Quedan '"<<rondas-i<<"' rondas"<<endl;
        }

        cout<<"Fin de la partida senior "<<nombre<<endl;

    } else {

        cout<<"Aca se juega hasta que termine la partida senior "<<nombre<<endl;

    }

}

void modoDosJugadores(){

    cout<<"Usted ha seleccionado el modo juego en duelo"<<endl;

}

void puntuacionMaxima(){

    cout<<"Usted quiere ver la puntuacion maxima"<<endl;

}
