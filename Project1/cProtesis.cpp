#include "cProtesis.h"

cProtesis::cProtesis(Organo_Extremidad_Reemplazada Nombre_, tm Fecha_Fabricacion_, string Fabricante_, bool Superior_Inferior_): Nombre(Nombre_), Fecha_Fabricacion(Fecha_Fabricacion_), Fabricante(Fabricante_), Superior_Inferior(Superior_Inferior_)
{
}

cProtesis::~cProtesis()
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

float cProtesis::get_largo()
{
    return 0.0f;
}

float cProtesis::get_ancho()
{
    return 0.0f;
}

float cProtesis::get_Radio()
{
    return 0.0f;
}

string cProtesis::get_Articulacion()
{
    return string();
}

string cProtesis::get_material()
{
    return string();
}

void cProtesis::set_Nombre(Organo_Extremidad_Reemplazada set)
{
    this->Nombre = set;
}

//void operator-(list<cProtesis> original, list<cProtesis>::iterator* eliminado)
//{
//    original.erase(*eliminado);
//}

