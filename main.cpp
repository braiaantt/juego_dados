#include <iostream>
#include "juego.h"

using namespace std;

int main()
{
    int seleccion;

    while(seleccion != 4){

        cout<<"-----MENU-----"<<endl;
        cout<<"Seleccione una opcion"<<endl;
        cout<<"1. Un jugador"<<endl;
        cout<<"2. Dos jugadores"<<endl;
        cout<<"3. Maxima puntuacion"<<endl;
        cout<<"4. Salir"<<endl;
        cin>>seleccion;

        switch(seleccion){

            case 1: modoUnJugador(); system("pause"); break;
            case 2: modoDosJugadores(); system("pause"); break;
            case 3: puntuacionMaxima(); system("pause"); break;
            case 4: break;

        }

        system("cls");

    }

    cout<<"Gracias por jugar!"<<endl;

    return 0;
}
