#ifndef PASAJERO_HPP
#define PASAJERO_HPP

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
	int calcularHoraSalida();
		
private:
	int identificador, prioridad, horaLlegada, horaAtendido, duracion;
};

#endif // PASAJERO_HPP
