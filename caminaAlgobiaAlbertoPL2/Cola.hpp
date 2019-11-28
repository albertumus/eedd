#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"
#include "Box.hpp"

class Cola
{
public:
	Cola();
	~Cola();
	
	void insertar(Pasajero* v);
	void insertarPorId(Pasajero* v);
	int eliminar();
	void mostrar();
	void sleepcp(int milliseconds);
	void mostrarPrimero();
	int longitudCola();
	int buscarPrioridad();
	int buscarPrimerTiempoLlegada();
	void borrarDeCola(Pasajero *pp);
	Pasajero* buscarPersonaLlegada(int t);
	Pasajero* cogerPrimeroPrioridad(int prior);
	Pasajero* getPrimero();
	int calcularTiempoTotalEnAeropuero();
	void setearSatisfaccion(double t);

private:
    pnodo primero, ultimo;
};


#endif // COLA_HPP
