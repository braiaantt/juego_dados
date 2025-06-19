#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

std::string obtenerNombre();
bool establecerRondas();
int obtenerCantidadRondas();
void mostrarDados(int dados[], int cantidadDados);
void mostrarRondaActual(std::string nomre, int ronda, int puntaje);
void mostrarPuntajeDeRonda(int numRonda, int puntajeDeRonda);
void mostrarNumeroLanzamiento(int numLanzamiento);
void mostrarPuntajeTirada(int puntajeTirada);
void mostrarCombinacion(int combinacion, int valorDado);
void mostrarGanador(std::string nombre, int puntaje, int rondas);
void mostrarJugadorPierde(std::string nombre, int puntaje);
void mostrarSeReseteanPuntos(std::string nombre);
void mostrarPuntajeParcial(std::string nombre1, int puntaje1, std::string nombre2, int puntaje2);

#endif // INTERFAZ_H_INCLUDED
