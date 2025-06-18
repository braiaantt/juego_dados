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

#endif // INTERFAZ_H_INCLUDED
