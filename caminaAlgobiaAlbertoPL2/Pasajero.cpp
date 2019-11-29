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

void Pasajero::setIdentificadorBox(int iden)
{
	identificadorBox = iden;
}
int Pasajero::getIdentificadorBox()
{
	return identificadorBox;
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
	return horaAtendido + duracion; 
}

int Pasajero::calcularTiempoQuePasaEnAeropuerto()
{
	return horaAtendido - horaLlegada + duracion;
}

void Pasajero::mostrarPasajero() 
{
	cout << "El pasajero con id: " << this->getIdentificador() << ", prioridad: " << this->getPrioridad() << ", hora llegada: " << this->getHoraLlegada() << " y duracion: " << this->getDuracion() 
	<< ". Hora atendido " << this->getHoraAtendido() << ". Tiempo pasado en aeropuerto " << this->calcularTiempoQuePasaEnAeropuerto() << ".Su satisfacion es: " << this->getSatisfaccion() << endl;
}

void Pasajero::setSatisfaccion(double satis) {
	satisfaccion = satis;
}

double Pasajero::getSatisfaccion() {
	return satisfaccion;
}

void Pasajero::calcularSatisfaccion(double t) {
	satisfaccion = t - this->calcularTiempoQuePasaEnAeropuerto();
}


Pasajero::~Pasajero()
{
}

