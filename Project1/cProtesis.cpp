#include "cProtesis.h"

cProtesis::cProtesis(unsigned int Nombre_, time_t Fecha_Fabricacion_, string Fabricante_, bool Superior_Inferior_): Nombre(Nombre_), Fecha_Fabricacion(Fecha_Fabricacion_), Fabricante(Fabricante_), Superior_Inferior(Superior_Inferior_)
{
}

cProtesis::~cProtesis()
{
}

cProtesis::cProtesis(list<cProtesis>::iterator copia): Nombre(copia->get_nombre()), Fecha_Fabricacion(copia->get_Fabricacion()), Fabricante(copia->get_Fabricante()), Superior_Inferior(copia->get_Superior_inferior())
{

}


unsigned int cProtesis::get_nombre()
{
    return this->Nombre;
}

time_t cProtesis::get_Fabricacion()
{
    return this->Fecha_Fabricacion;
}

string cProtesis::get_Fabricante()
{
    return this->Fabricante;
}

bool cProtesis::get_Superior_inferior()
{
    return this->Superior_Inferior;
}
