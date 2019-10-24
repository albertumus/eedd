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
	void colaDeLista();
	void cambiarCola(Pasajero *p, Cola& colaOrigen, Cola& colaDestino);
	void serAtendido(Box* box, Pasajero* pp );
	bool boxLibre();
	Box* cogerboxLibre(Box *box1, Box *box2, Box *box3);
	void comprobarBoxFinalizado();
	float calcularTiempoMedioAeropuerto();
	
private:
	int t, prioridad;
	Box box1 = Box(1);
	Box box2 = Box(2);
	Box box3 = Box(3);
	Lista listaBoxes;
	Cola colaFinal;
	Cola colaListos;
	Cola colaInicial;
};

#endif // AIRPORT_HPP
