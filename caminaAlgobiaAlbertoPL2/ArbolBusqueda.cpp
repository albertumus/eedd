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

void ArbolBusqueda::insertarPorSatisfaccion(Pasajero* pjs) {
	anodo nuevo_nodo;
	nuevo_nodo = new NodoArbol(pjs);
	
	if ( nuevo_nodo->valor->getSatisfaccion() != 0) {
		insertarPorSatisfaccion_aux(raiz, nuevo_nodo);
	} else {
		cout << "ERROR: El pasajero debe de tener satisfaccion";
	}
	
}

void ArbolBusqueda::insertarPorSatisfaccion_aux(anodo arbol, anodo e) {
	if ( arbol == NULL ) {
		arbol = e;
	} else {
		if ( e->valor->getSatisfaccion() < arbol->valor->getSatisfaccion() ) {
			if ( arbol->izq == NULL ) {
				arbol->izq = e;
			} else {
				insertarPorSatisfaccion_aux(arbol->izq, e);
			}
		} else {
			if ( arbol->der == NULL ) {
				arbol->der = e;
			} else{
				insertarPorSatisfaccion_aux(arbol->der, e);
			}
		}
	}
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

