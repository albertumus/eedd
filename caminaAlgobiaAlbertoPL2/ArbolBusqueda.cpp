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
          cout << this->getRaiz()->getIdentificador() << " ";
          this->izq->preOrden();
          this->der->preOrden();
     }
}

void ArbolBusqueda::inOrden()
{
     if(this!=NULL)
     {
          this->izq->inOrden();
          cout << this->getRaiz()->getIdentificador() << " ";
          this->der->inOrden();
     }
}

void ArbolBusqueda::postOrden()
{
     if(this!=NULL)
     {
          this->izq->postOrden();
          this->der->postOrden();
          cout << this->getRaiz()->getIdentificador() << " ";
     }
}

void ArbolBusqueda::verArbol(int n)
{
     if(this==NULL)
          return;
     this->der->verArbol(n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< this->getRaiz()->getIdentificador() <<endl;

     this->izq->verArbol(n+1);
}

ArbolBusqueda::~ArbolBusqueda()
{
}

