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
	void crearNuevoBox();
	void cambiarCola(Pasajero *p, Cola& colaOrigen, Cola& colaDestino);
	void finalizarBoxes();
	void vaciarBoxes();
	float calcularTiempoMedioAeropuerto();
	
private:
	int t, numeroBoxes;
	Lista listaBoxes;
	Cola colaFinal;
	Cola colaInicial;
};

#endif // AIRPORT_HPP
