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
    int eliminar();
    void mostrar();
	void mostrarPrimero();
	int longitudCola();
	int buscarPrioridad();
	Pasajero* cogerPrimeroPrioridad(int *t, int *prior);
	void borrarDeCola(Pasajero *pp, Cola *pc);
    Pasajero* buscarPersonaLlegada( int *t );

private:
    pnodo primero, ultimo;
};


#endif // COLA_HPP