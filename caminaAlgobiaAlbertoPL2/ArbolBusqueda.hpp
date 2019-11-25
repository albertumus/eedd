#ifndef ARBOLBUSQUEDA_HPP
#define ARBOLBUSQUEDA_HPP
#include "NodoArbol.hpp"


class ArbolBusqueda
{
public:
	ArbolBusqueda(Pasajero* psj);
	~ArbolBusqueda();
	
	Pasajero* getValueRaiz();
	anodo getRaiz();
	int numeroNodos();

private:
    int numeroNodos_aux(anodo arbol);
	anodo raiz;
	

};

#endif // ARBOLBUSQUEDA_HPP
