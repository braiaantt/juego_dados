#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED

#include <iostream>

using namespace std;

int calcularCombinacion(int dados[], int cantidadDados, int combinacion);
int analizarCombinacion(int dados[], int cantidadDados);
int obtenerPuntajeMaximo(int puntos[], int cantidadPuntos);
void ordenarDados(int dados[], int cantidadDados);
std::string analizarInfoPartida(std::string nombreActual, std::string nombreMejorJugador, int infoPartida[], int infoMejorPartida[]);

#endif // OPERACIONES_H_INCLUDED
