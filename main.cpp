#include <iostream>
#include "juego.h"

using namespace std;

int main()
{

    srand(time(NULL));
    int seleccion, datos = 2;
    int infoMejorPartida[datos] = {1000,1000};
    std::string nombreMejorJugador = "Sin registros";

    while(seleccion != 4){

        std::string nombreJugador;
        int infoPartida[datos];

        cout<<"-----MENU-----"<<endl;
        cout<<"Seleccione una opcion"<<endl;
        cout<<"1. Un jugador"<<endl;
        cout<<"2. Dos jugadores"<<endl;
        cout<<"3. Maxima puntuacion"<<endl;
        cout<<"4. Salir"<<endl;
        cin>>seleccion;

        switch(seleccion){

            case 1: nombreJugador = modoUnJugador(infoPartida);              system("pause"); break;
            case 2: nombreJugador = modoDosJugadores(infoPartida);           system("pause"); break;
            case 3: puntuacionMaxima(nombreMejorJugador, infoMejorPartida);  system("pause"); break;
            case 4: break;

        }

        nombreMejorJugador = analizarInfoPartida(nombreMejorJugador, nombreJugador, infoPartida, infoMejorPartida);

        system("cls");

    }

    cout<<"Gracias por jugar!"<<endl;

    return 0;
}
