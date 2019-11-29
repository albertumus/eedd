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
	assert(arbol_test->getRaiz() == pasajero_nulo_test);
	assert(arbol_test->getRaiz()->getSatisfaccion() == 0);
	
	// Test 'numeroNodos' 
	assert(arbol_test->calcularNumeroDePasajeros() == 0);
	ArbolBusqueda* r1 = new ArbolBusqueda(pasajero_test_2);
	arbol_test->setDer(r1);
	assert(arbol_test->calcularNumeroDePasajeros() ==1);
	ArbolBusqueda* r2 = new ArbolBusqueda(pasajero_test_3);
	arbol_test->setDer(r2);
	assert(arbol_test->calcularNumeroDePasajeros() ==1);
	arbol_test->setIzq(r1);
	assert(arbol_test->calcularNumeroDePasajeros() ==2);
	
	// Test 'insertarPorSatisfaccion'
	ArbolBusqueda* arbol_test_inserccion = new ArbolBusqueda(pasajero_nulo_test);
	assert (pasajero_test->getSatisfaccion() == -19.5);
	arbol_test_inserccion->insertarPorSatisfaccion(pasajero_test);
	assert(arbol_test_inserccion->calcularNumeroDePasajeros() == 1);
	assert(arbol_test_inserccion->getIzq()->getRaiz()->getSatisfaccion() == -19.5);
	assert (pasajero_test_2->getSatisfaccion() == 0.5);
	arbol_test_inserccion->insertarPorSatisfaccion(pasajero_test_2);
	assert(arbol_test_inserccion->calcularNumeroDePasajeros() ==2);
	assert(arbol_test_inserccion->getDer()->getRaiz()->getIdentificador() == 2);
	assert (pasajero_test_3->getSatisfaccion() == -9.5);
	arbol_test_inserccion->insertarPorSatisfaccion(pasajero_test_3);
	assert(arbol_test_inserccion->calcularNumeroDePasajeros() ==3);
	assert(arbol_test_inserccion->getIzq()->getDer()->getRaiz()->getIdentificador() == 3);
	
	// Test 'hojas'
	ArbolBusqueda* arbol_test_hoja = new ArbolBusqueda(pasajero_nulo_test);
	assert(arbol_test_hoja->hoja() == true);
	arbol_test_hoja->insertarPorSatisfaccion(pasajero_test);
	assert(arbol_test_hoja->hoja() == false);
	
	// Test 'numeroHojas'
	arbol_test_hoja->insertarPorSatisfaccion(pasajero_test_2);
	assert(arbol_test_hoja->calcularNumeroDePasajeros() == 2);
	assert(arbol_test_hoja->numeroHojas() == 2);
	arbol_test_hoja->insertarPorSatisfaccion(pasajero_test_3);
	assert(arbol_test_hoja->numeroHojas() == 2);
	
	// Test 'altura'
	ArbolBusqueda* arbol_test_altura = new ArbolBusqueda(pasajero_nulo_test);
	arbol_test_altura->insertarPorSatisfaccion(pasajero_test);
	arbol_test_altura->insertarPorSatisfaccion(pasajero_test_2);
	arbol_test_altura->insertarPorSatisfaccion(pasajero_test_3);
	assert (pasajero_test_3->getSatisfaccion() == -9.5);
	assert(arbol_test_altura->altura() == 2);
	
	//Insertar por ID
	Cola* cola_test_insertar = new Cola();
	cola_test_insertar->insertarPorId(pasajero_test_3);
	cola_test_insertar->insertarPorId(pasajero_test);
	cola_test_insertar->insertarPorId(pasajero_test_2);
	assert(cola_test_insertar->longitudCola() == 3);
	assert(cola_test_insertar->getPrimero()->getIdentificador() == 1);
	assert(cola_test_insertar->getUltimo()->getIdentificador() == 3);
	cola_test_insertar->insertarPorId(pasajero_test_3);
	assert(cola_test_insertar->longitudCola() == 4);
	assert(cola_test_insertar->getUltimo()->getIdentificador() == 3);
	
	// Maximo Pasajero
	ArbolBusqueda* arbol_max_min_test = new ArbolBusqueda(pasajero_nulo_test);
	arbol_max_min_test->insertarPorSatisfaccion(pasajero_test);
	arbol_max_min_test->insertarPorSatisfaccion(pasajero_test_2);
	arbol_max_min_test->insertarPorSatisfaccion(pasajero_test_3);
	arbol_max_min_test->insertarPorSatisfaccion(pasajero_test_3);
	assert(arbol_max_min_test->calcularNumeroDePasajeros() == 4);
	assert(arbol_max_min_test->satisfaccionMaxima() == pasajero_test_2);
	Pasajero* pasajero_test_4 = new Pasajero(4,6,0,20);
	Pasajero* pasajero_test_5 = new Pasajero(5,6,0,20);
	Pasajero* pasajero_test_6 = new Pasajero(6,6,0,20);
	Pasajero* pasajero_test_7 = new Pasajero(7,6,0,20);
	pasajero_test_4->setSatisfaccion(0.4);
	pasajero_test_5->setSatisfaccion(0.7);
	pasajero_test_6->setSatisfaccion(0.6);
	pasajero_test_7->setSatisfaccion(0.8); 
	arbol_max_min_test->insertarPorSatisfaccion(pasajero_test_4);
	arbol_max_min_test->insertarPorSatisfaccion(pasajero_test_5);
	arbol_max_min_test->insertarPorSatisfaccion(pasajero_test_6);
	arbol_max_min_test->insertarPorSatisfaccion(pasajero_test_7);
	assert(arbol_max_min_test->satisfaccionMaxima() == pasajero_test_7);
	
	// Minimo Pasajero
	assert(arbol_max_min_test->satisfaccionMinima() == pasajero_test);
	Pasajero* pasajero_test_8 = new Pasajero(8,6,0,20);
	Pasajero* pasajero_test_9 = new Pasajero(9,6,0,20);
	pasajero_test_8->setSatisfaccion(-20);
	pasajero_test_9->setSatisfaccion(-19.7); 
	arbol_max_min_test->insertarPorSatisfaccion(pasajero_test_8);
	arbol_max_min_test->insertarPorSatisfaccion(pasajero_test_9);
	assert(arbol_max_min_test->satisfaccionMinima() == pasajero_test_8);
	
	// Media
	//cout << arbol_max_min_test->calcularSatisfaccionMedia();
	//assert(arbol_max_min_test->calcularSatisfaccionMedia() == -7.52);
	
}

Test::~Test()
{
}

