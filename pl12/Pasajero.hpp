#ifndef PASAJERO_HPP
#define PASAJERO_HPP
#include <iostream>
using namespace std;

class Pasajero
{
public:
	Pasajero(int id, int prior, int horalleg, int dur);
	~Pasajero();
	
	int getIdentificador();
	int getPrioridad();
	int getHoraLlegada();
	int getDuracion();
	int getHoraAtendido();
	void setHoraAtendido(int i);
	void setIdentificadorBox(int iden);
	int getIdentificadorBox();
	int calcularHoraSalida();
	int calcularTiempoQuePasaEnAeropuerto();
	void mostrarPasajero();
		
private:
	int identificador, prioridad, horaLlegada, horaAtendido, duracion, identificadorBox;
};

#endif // PASAJERO_HPP
