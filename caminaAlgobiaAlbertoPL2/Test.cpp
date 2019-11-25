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
	Pasajero* pasajero_test_2 = new Pasajero(1,6,0,20);
	pasajero_test_2->setHoraAtendido(0);
	Pasajero* pasajero_test_3 = new Pasajero(1,6,0,20);
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
	

}

Test::~Test()
{
}

