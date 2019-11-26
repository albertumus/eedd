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
	void insertarPorSatisfaccion(Pasajero* psj);
	int numeroNodos();

private:
    int numeroNodos_aux(anodo arbol);
	void insertarPorSatisfaccion_aux(anodo arbol, anodo e);
	anodo raiz;
	

};

#endif // ARBOLBUSQUEDA_HPP
