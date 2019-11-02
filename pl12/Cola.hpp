#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"

class Cola
{
public:
	Cola();
	~Cola();
	
	void insertar(Pasajero* v);
	void insertarPorPrioridad(Pasajero* p);
	int eliminar();
	void mostrar();
	void mostrarPrimero();
	int longitudCola();
	int buscarPrimerTiempoLlegada();
	void borrarDeCola(Pasajero *pp);
	Pasajero* buscarPersonaLlegada(int t);
	Pasajero* cogerPrimeroPrioridadYTiempoLlegada();
	Pasajero* getPrimero();
	pnodo getPrimeroNodo();
	int calcularTiempoTotalEnAeropuero();

private:
    pnodo primero, ultimo;
};


#endif // COLA_HPP
