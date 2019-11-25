#include "ArbolBusqueda.hpp"clTabCtrl

ArbolBusqueda::ArbolBusqueda(Pasajero* psj)
{
	NodoArbol* r = new NodoArbol(psj);
	raiz = r;
}

Pasajero* ArbolBusqueda::getRaiz(){
	return raiz->valor;
}

ArbolBusqueda::~ArbolBusqueda()
{
}

