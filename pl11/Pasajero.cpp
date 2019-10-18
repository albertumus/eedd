#include "Pasajero.hpp"

Pasajero::Pasajero(int id, int prior, int horalleg, int dur)
{
	identificador = id;
	prioridad = prior;
	horaLlegada = horalleg;
	duracion = dur;
}

void Pasajero::cambiarTiempo(int *pt)
/*
 * Funcion de ejemplo de como cambiar el valor para un puntero global
 */
{
	*pt = 31;
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

Pasajero::~Pasajero()
{
}

