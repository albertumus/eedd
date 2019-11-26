#include "ArbolBusqueda.hpp"clTabCtrl

ArbolBusqueda::ArbolBusqueda(Pasajero* psj, ArbolBusqueda* i, ArbolBusqueda* d)
{
	valor = psj;
	der = d;
	izq = i;
}

void ArbolBusqueda::setDer(ArbolBusqueda* d) {
	der = d;
}
void ArbolBusqueda::setIzq(ArbolBusqueda* i) {
	izq = i;
}
ArbolBusqueda* ArbolBusqueda::getDer(){
	return der;
}
ArbolBusqueda* ArbolBusqueda::getIzq() {
	return izq;
}

Pasajero* ArbolBusqueda::getRaiz() {
	return valor;
}

ArbolBusqueda* ArbolBusqueda::nuevoNodo(Pasajero* psj) {
	ArbolBusqueda* nuevo_arbol = new ArbolBusqueda(psj);
	return nuevo_arbol;
}

void ArbolBusqueda::insertarPorSatisfaccion(Pasajero* psj) {	
	if ( psj->getSatisfaccion() < this->valor->getSatisfaccion() ) {
		if ( this->izq == NULL ) {
			this->izq = this->nuevoNodo(psj);
		} else {
			this->izq->insertarPorSatisfaccion(psj);
		}
	} else {
		if ( this->der == NULL ) {
			this->der = this->nuevoNodo(psj);
		} else {
			this->der->insertarPorSatisfaccion(psj);
		}
	}
}
/*
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
*/

int ArbolBusqueda::calcularNumeroNodos() {
	return this->numeroNodos() -1;
}

int ArbolBusqueda::numeroNodos() {
	if ( this == NULL ) {
		return 0;
	} else {
		return 1 + izq->numeroNodos() + der->numeroNodos();
	}
}

ArbolBusqueda::~ArbolBusqueda()
{
}

