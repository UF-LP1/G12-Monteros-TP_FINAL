#include "cFabricante.h"

cFabricante::cFabricante(string Nombre_, string Direccion_, unsigned int Num_Habilitacion_): Nombre(Nombre_),Direccion(Direccion_), Num_Habilitacion(Num_Habilitacion_)
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
/*
const string Nombre;
const string Direccion;
const unsigned int Num_Habilitacion;
*/
string cFabricante::to_string_fab()
{
	stringstream Salida;
	Salida << "Nombre: " << this->Nombre 
		<< ", Direccion: " << this->Direccion 
		<< ", Numero de Habilitacion" << this->Num_Habilitacion << endl;
	return Salida.str();
}

void cFabricante::Imprimir_fab()
{
	cout << to_string_fab() << endl;
}



