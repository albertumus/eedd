#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"

class Cola
{
public:
	Cola();
	~Cola();
	
	void insertar(Pasajero* v);
    int eliminar();
    void mostrar();
	int longitudCola();

private:
    pnodo primero, ultimo;
};


#endif // COLA_HPP
