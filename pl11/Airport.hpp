#ifndef AIRPORT_HPP
#define AIRPORT_HPP
#include "Cola.hpp"
#include "Box.hpp"
#include "Lista.hpp"

class Airport
{
public:
	Airport();
	~Airport();
	
	void gestionarAeropuerto();
	void cambiarCola(Pasajero *p, Cola& colaOrigen, Cola& colaDestino);
	bool boxLibre();
	void comprobarBoxFinalizado();
	float calcularTiempoMedioAeropuerto();
	
private:
	int t;
	Lista listaBoxes;
	Cola colaFinal;
	Cola colaInicial;
};

#endif // AIRPORT_HPP
