#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

std::string modoUnJugador(int infoPartida[]);
std::string modoDosJugadores(int infoPartida[]);
void puntuacionMaxima(std::string nombre, int infoMejorPartida[]);
int jugarRonda();
int tirarDados();
int analizarCombinacion(int dados[], int cantidadDados);
int calcularCombinacion(int dados[], int cantidadDados, int combinacion);
int obtenerPuntajeMaximo(int puntos[], int cantidadPuntos);
std::string analizarInfoPartida(std::string nombreActual, std::string nombreMejorJugador, int infoPartida[], int infoMejorPartida[]);
int jugarTurno(int puntosActuales, int ronda);
bool chequearGanador(int puntaje, int infoPartida[], int rondas);

#endif // JUEGO_H_INCLUDED
