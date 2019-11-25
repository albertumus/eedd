#ifndef ARBOLBUSQUEDA_HPP
#define ARBOLBUSQUEDA_HPP
#include "NodoArbol.hpp"


class ArbolBusqueda
{
public:
	ArbolBusqueda(Pasajero* psj);
	~ArbolBusqueda();
	
	Pasajero* getRaiz();

private:
    anodo raiz;

};

#endif // ARBOLBUSQUEDA_HPP
