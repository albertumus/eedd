#include "Test.hpp"
#include <assert.h> 
#include "Pasajero.hpp"
#include "Cola.hpp"
#include "ArbolBusqueda.hpp"

Test::Test()
{
}

void Test::test_to_pass() {
	
	// Test de 'setSatisfaccion' en Pasajero
	Pasajero* pasajero_test = new Pasajero(1,6,0,20);
	pasajero_test->setSatisfaccion(-10);
	assert (pasajero_test->getSatisfaccion() == -10);
	
	// Test de 'calcularSatisfaccion' en Pasajero
	pasajero_test->setHoraAtendido(0);
	pasajero_test->calcularSatisfaccion(37);
	assert (pasajero_test->getSatisfaccion() == 17);
	pasajero_test->setHoraAtendido(0);
	pasajero_test->calcularSatisfaccion(20);
	assert (pasajero_test->getSatisfaccion() == 0);
	pasajero_test->setHoraAtendido(20);
	pasajero_test->calcularSatisfaccion(20);
	assert (pasajero_test->getSatisfaccion() == -20);
	
	// Test 'setearSatisfaccion' en Cola
	Cola* cola_test =  new Cola();
	Pasajero* pasajero_test_2 = new Pasajero(2,6,0,20);
	pasajero_test_2->setHoraAtendido(0);
	Pasajero* pasajero_test_3 = new Pasajero(3,6,0,20);
	pasajero_test_3->setHoraAtendido(10);
	cola_test->insertar(pasajero_test);
	cola_test->insertar(pasajero_test_2);
	cola_test->insertar(pasajero_test_3);
	assert(cola_test->longitudCola()==3);
	cola_test->setearSatisfaccion(20.5);
	assert (pasajero_test->getSatisfaccion() == -19.5);
	assert (pasajero_test_2->getSatisfaccion() == 0.5);
	assert (pasajero_test_3->getSatisfaccion() == -9.5);
	
	// Test 'crearArbolConPasajero'
	Pasajero* pasajero_nulo_test = new Pasajero(0,0,0,0);
	pasajero_nulo_test->setSatisfaccion(0);
	ArbolBusqueda* arbol_test = new ArbolBusqueda(pasajero_nulo_test);
	assert(arbol_test->getValueRaiz() == pasajero_nulo_test);
	assert(arbol_test->getValueRaiz()->getSatisfaccion() == 0);
	
	// Test 'numeroNodos' 
	assert(arbol_test->numeroNodos() == 0);
	NodoArbol* r1 = new NodoArbol(pasajero_test_2);
	arbol_test->getRaiz()->der = r1;
	assert(arbol_test->numeroNodos() ==1);
	NodoArbol* r2 = new NodoArbol(pasajero_test_3);
	arbol_test->getRaiz()->der = r2;
	assert(arbol_test->numeroNodos() ==1);
	arbol_test->getRaiz()->izq = r1;
	assert(arbol_test->numeroNodos() ==2);
	
	// Test 'insertarPorSatisfaccion'
	ArbolBusqueda* arbol_test_inserccion = new ArbolBusqueda(pasajero_nulo_test);
	assert (pasajero_test->getSatisfaccion() == -19.5);
	arbol_test_inserccion->insertarPorSatisfaccion(pasajero_test);
	assert(arbol_test_inserccion->numeroNodos() ==1);
	assert (pasajero_test_2->getSatisfaccion() == 0.5);
	arbol_test_inserccion->insertarPorSatisfaccion(pasajero_test_2);
	assert(arbol_test_inserccion->numeroNodos() ==2);
	assert(arbol_test_inserccion->getRaiz()->der->valor->getIdentificador() == 2);
	assert (pasajero_test_3->getSatisfaccion() == -9.5);
	arbol_test_inserccion->insertarPorSatisfaccion(pasajero_test_3);
	assert(arbol_test_inserccion->numeroNodos() ==3);
	assert(arbol_test_inserccion->getRaiz()->izq->der->valor->getIdentificador() == 3);

}

Test::~Test()
{
}

