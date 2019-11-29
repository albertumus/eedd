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
	
	Pasajero* satisfaccionMaxima();
	Pasajero* satisfaccionMinima();
	float calcularSatisfaccionMedia();
	
	bool hoja();
	int numeroHojas();
	ArbolBusqueda* nuevoNodo(Pasajero* psj);
	int altura();
	
	void insertarPorSatisfaccion(Pasajero* psj);
	int calcularNumeroDePasajeros();
	int numeroNodos();
	
	void preOrden();
	void inOrden();
	void postOrden();
	
	void verArbol(int n);

private:
	Pasajero* valor;
	ArbolBusqueda* izq;
	ArbolBusqueda* der;
	
	float sumatorioSatisfaccionesPasajero();
};

#endif // ARBOLBUSQUEDA_HPP
