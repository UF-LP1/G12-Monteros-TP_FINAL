#include "cFabricante.h"

cFabricante::cFabricante(string Nombre_, string Direccion_, unsigned int Num_Habilitacion_): Nombre(Nombre),Direccion(Direccion_), Num_Habilitacion(Num_Habilitacion_)
{
}

cFabricante::~cFabricante()
{
}

string cFabricante::get_Nombre()
{
	return this->Nombre;
}

string cFabricante::get_Direccion()
{
	return this->Direccion;
}

unsigned int cFabricante::get_Num_Habilitacion()
{
	return this->Num_Habilitacion;
}
