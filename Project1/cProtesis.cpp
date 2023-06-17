#include "cProtesis.h"

cProtesis::cProtesis(Organo_Extremidad_Reemplazada Nombre_, tm Fecha_Fabricacion_, string Fabricante_, bool Superior_Inferior_): Nombre(Nombre_), Fecha_Fabricacion(Fecha_Fabricacion_), Fabricante(Fabricante_), Superior_Inferior(Superior_Inferior_)
{
}

cProtesis::~cProtesis()
{
}

cProtesis::cProtesis(list<cProtesis>::iterator copia): Nombre(copia->get_nombre()), Fecha_Fabricacion(copia->get_Fabricacion()), Fabricante(copia->get_Fabricante()), Superior_Inferior(copia->get_Superior_inferior())
{

}


Organo_Extremidad_Reemplazada cProtesis::get_nombre()
{
    return this->Nombre;
}

cProtesis::cProtesis():Nombre(Brazo), Fecha_Fabricacion(), Fabricante(), Superior_Inferior()
{
}


tm cProtesis::get_Fabricacion()
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

void cProtesis::set_Nombre(Organo_Extremidad_Reemplazada set)
{
    this->Nombre = set;
}
void operator-(list<cProtesis> original, list<cProtesis>::iterator* eliminado)
{
    original.erase(*eliminado);
}

