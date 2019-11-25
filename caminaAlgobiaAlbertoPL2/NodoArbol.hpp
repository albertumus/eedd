#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
#include "Pasajero.hpp"

class NodoArbol
{
public:
	NodoArbol(Pasajero* psj, NodoArbol* i = NULL, NodoArbol* d = NULL);
	~NodoArbol();

	Pasajero* valor;
	NodoArbol* izq;
	NodoArbol* der;

friend class ArbolBusqueda;

};

typedef NodoArbol* anodo;

#endif // NODOARBOL_HPP
