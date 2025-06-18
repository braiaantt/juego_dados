#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

void modoUnJugador();
void modoDosJugadores();
void puntuacionMaxima();
int jugarRonda();
int tirarDados();
int analizarCombinacion(int dados[], int cantidadDados);
int calcularCombinacion(int dados[], int cantidadDados, int combinacion);
int obtenerPuntajeMaximo(int puntos[], int cantidadPuntos);

#endif // JUEGO_H_INCLUDED
