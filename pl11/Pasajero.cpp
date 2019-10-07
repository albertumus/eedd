#include "Pasajero.hpp"

Pasajero::Pasajero(int id, int prior, int horalleg, int dur)
{
	identificador = id;
	prioridad = prior;
	horaLlegada = horalleg;
	duracion = dur;
}

int Pasajero::getIdentificador()
{
	return identificador;
}

int Pasajero::getPrioridad()
{
	return prioridad;
}

int Pasajero::getHoraLlegada()
{
	return horaLlegada;
}

int Pasajero::getDuracion()
{
	return duracion;
}

Pasajero::~Pasajero()
{
}

