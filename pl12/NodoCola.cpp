#include "NodoCola.hpp"

NodoCola::NodoCola(Pasajero* psj, NodoCola* sig)
{
    valor = psj;
    siguiente = sig; 
}

NodoCola::~NodoCola()
{
}

