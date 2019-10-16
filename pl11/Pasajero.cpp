#include "Pasajero.hpp"

Pasajero::Pasajero(int id, int prior, int horalleg, int dur)
{
	identificador = id;
	prioridad = prior;
	horaLlegada = horalleg;
	duracion = dur;
}

int Pasajero::getIdentificador()
/*
 * Devuelve el estado de la variable identificador
 */
{
	return identificador;
}

int Pasajero::getPrioridad()
/*
 * Devuelve el estado de la variable prioridad
 */
{
	return prioridad;
}

int Pasajero::getHoraLlegada()
/*
 * Devuelve el estado de la variable HoraLlegada
 */
{
	return horaLlegada;
}

int Pasajero::getDuracion()
/*
 * Devuelve el estado de la variable duracion
 */
{
	return duracion;
}

int Pasajero::getHoraAtendido()
{
	return horaAtendido;
}

void Pasajero::setHoraAtendido(int i) 
{
	horaAtendido = i;
}

int Pasajero::calcularHoraSalida()
{
	return horaLlegada + ( horaAtendido - horaLlegada ) + duracion; 
}

int Pasajero::calcularTiempoQuePasaEnAeropuerto()
{
	return horaAtendido - horaLlegada + duracion;
}


Pasajero::~Pasajero()
{
}

