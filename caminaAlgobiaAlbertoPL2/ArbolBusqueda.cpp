#include "ArbolBusqueda.hpp"clTabCtrl

ArbolBusqueda::ArbolBusqueda(Pasajero* psj)
{
	NodoArbol* r = new NodoArbol(psj);
	raiz = r;
}

Pasajero* ArbolBusqueda::getValueRaiz() {
	return raiz->valor;
}

anodo ArbolBusqueda::getRaiz() {
	return raiz;
}

int ArbolBusqueda::numeroNodos() {
	return this->numeroNodos_aux(raiz)-1;
}

int ArbolBusqueda::numeroNodos_aux(anodo arbol) {
	if (arbol == NULL) {
		return 0;
	} else {
		return 1 + numeroNodos_aux(arbol->izq) + numeroNodos_aux(arbol->der);
	}
}

ArbolBusqueda::~ArbolBusqueda()
{
}

