#include <iostream>
#include "juego.h"
#include "interfaz.h"
#include "operaciones.h"

using namespace std;

int main()
{

    srand(time(NULL));
    int seleccion, datos = 2;
    int infoMejorPartida[datos] = {1000,1000};
    bool simularPartida = true;

    std::string nombreMejorJugador = "Sin ganador";

    while(seleccion != 5){

        std::string nombreJugador = "Sin ganador";
        int infoPartida[datos];

        cout<<"-----MENU-----"<<endl;
        cout<<"Seleccione una opcion"<<endl;
        cout<<"1. Un jugador"<<endl;
        cout<<"2. Dos jugadores"<<endl;
        cout<<"3. Maxima puntuacion"<<endl;
        cout<<"4. Simular partida"<<endl;
        cout<<"5. Salir"<<endl;
        cin>>seleccion;

        switch(seleccion){

            case 1: nombreJugador = modoUnJugador(infoPartida, !simularPartida);    system("pause"); break;
            case 2: nombreJugador = modoDosJugadores(infoPartida);                  system("pause"); break;
            case 3: mostrarPuntuacionMaxima(nombreMejorJugador, infoMejorPartida);  system("pause"); break;
            case 4: modoUnJugador(infoPartida, simularPartida);                     system("pause"); break;

        }



        if(nombreJugador != "Sin ganador")nombreMejorJugador = analizarInfoPartida(nombreMejorJugador, nombreJugador, infoPartida, infoMejorPartida);


        system("cls");

    }

    cout<<"Gracias por jugar!"<<endl;

    return 0;
}
