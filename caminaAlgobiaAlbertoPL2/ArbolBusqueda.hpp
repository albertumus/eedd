#ifndef ARBOLBUSQUEDA_HPP
#define ARBOLBUSQUEDA_HPP
#include "Pasajero.hpp"

class ArbolBusqueda
{
public:
	ArbolBusqueda(Pasajero* psj, ArbolBusqueda* i = NULL, ArbolBusqueda* der = NULL);
	~ArbolBusqueda();
	
	void setDer(ArbolBusqueda* d);
	void setIzq(ArbolBusqueda* i);
	ArbolBusqueda* getDer();
	ArbolBusqueda* getIzq();
	Pasajero* getRaiz();
	
	void insertarPorSatisfaccion(Pasajero* psj);
	int calcularNumeroNodos();
	

private:
	Pasajero* valor;
	ArbolBusqueda* izq;
	ArbolBusqueda* der;
	
	int numeroNodos();
};

#endif // ARBOLBUSQUEDA_HPP
