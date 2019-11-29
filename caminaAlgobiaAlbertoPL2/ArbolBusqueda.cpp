#include "ArbolBusqueda.hpp"
#include <cstdio>

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

Pasajero* ArbolBusqueda::satisfaccionMaxima()
{
	if (this) {
		if (!this->der) {
			return this->getRaiz();
		} else {
			return this->getDer()->satisfaccionMaxima();
		}
	}
}

Pasajero* ArbolBusqueda::satisfaccionMinima()
{
	if (this) {
		if (!this->izq) {
			return this->getRaiz();
		} else {
			return this->getIzq()->satisfaccionMinima();
		}
	}
}

float ArbolBusqueda::calcularSatisfaccionMedia() {
	cout << this->sumatorioSatisfaccionesPasajero();
	cout << this->calcularNumeroDePasajeros();
	return this->sumatorioSatisfaccionesPasajero()/this->calcularNumeroDePasajeros();
}

float ArbolBusqueda::sumatorioSatisfaccionesPasajero()
{
	if (this) {
		cout << endl << "Datos: " << this->getRaiz()->getIdentificador() << " | " << this->getRaiz()->getSatisfaccion() << endl;
		return this->getRaiz()->getSatisfaccion() + this->getDer()->sumatorioSatisfaccionesPasajero() + this->getIzq()->sumatorioSatisfaccionesPasajero();
	} else {
		return 0;
	}
}

bool ArbolBusqueda::hoja() {
	return this->izq == NULL && this->der == NULL;
}

int ArbolBusqueda::numeroHojas() {
	if ( this == NULL ) {
		return 0;
	} else {
		if ( this->hoja() ) {
			return 1 + this->izq->numeroHojas() + this->der->numeroHojas();
		} else {
			return this->izq->numeroHojas() + this->der->numeroHojas();
		}
		
	}
}

ArbolBusqueda* ArbolBusqueda::nuevoNodo(Pasajero* psj) {
	ArbolBusqueda* nuevo_arbol = new ArbolBusqueda(psj);
	return nuevo_arbol;
}

void ArbolBusqueda::insertarPorSatisfaccion(Pasajero* psj) {	
	if ( psj->getSatisfaccion() <= this->valor->getSatisfaccion() ) {
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

int ArbolBusqueda::calcularNumeroDePasajeros() {
	return this->numeroNodos() -1;
}

int ArbolBusqueda::numeroNodos() {
	if ( this == NULL ) {
		return 0;
	} else {
		return 1 + izq->numeroNodos() + der->numeroNodos();
	}
}

int ArbolBusqueda::altura() {

	if(this != NULL){
		if(this->izq == NULL){
			if(this->der == NULL){
				return 0;
			}else{
				return 1 + this->der->altura();
			}
		}else{
			if(this->der == NULL){
				return 1 + this->izq->altura();
			}else{
				return 1 + max(this->izq->altura(), this->der->altura());
			}
		}
	}
}

void ArbolBusqueda::preOrden()
{
     if(this!=NULL)
     {
		  if ( this->getRaiz()->getIdentificador() )
			this->getRaiz()->mostrarPasajero();
          this->izq->preOrden();
          this->der->preOrden();
     }
}

void ArbolBusqueda::inOrden()
{
     if(this!=NULL)
     {
          this->izq->inOrden();
		  if ( this->getRaiz()->getIdentificador() )
			this->getRaiz()->mostrarPasajero();
          this->der->inOrden();
     }
}

void ArbolBusqueda::postOrden()
{
     if(this!=NULL)
     {
          this->izq->postOrden();
          this->der->postOrden();
		  if ( !this->getRaiz()->getIdentificador() )
			this->getRaiz()->mostrarPasajero();
     }
}

void ArbolBusqueda::verArbol(int n)
{
     if(this==NULL)
          return;
     this->der->verArbol(n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< this->getRaiz()->getIdentificador() << " | " << this->getRaiz()->getSatisfaccion() <<endl;

     this->izq->verArbol(n+1);
}

ArbolBusqueda::~ArbolBusqueda()
{
}

