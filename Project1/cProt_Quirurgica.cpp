#include "cProt_Quirurgica.h"

cProt_Quirurgica::cProt_Quirurgica(string Articulacion_, string Material_, Organo_Extremidad_Reemplazada Nombre_, time_t Fecha_Fabricacion_, string Fabricante_, bool Superior_Inferior_):cProtesis(Nombre_,Fecha_Fabricacion_,Fabricante_,Superior_Inferior_)
{
	this->Articulacion = Articulacion_;
	this->Material = Material;
}

cProt_Quirurgica::~cProt_Quirurgica()
{
}

string cProt_Quirurgica::get_material()
{
	return this->Material;
}

string cProt_Quirurgica::get_Articulacion()
{
	return this->Articulacion;
}

float cProt_Quirurgica::get_ancho()		 //
{												 //estas tres funciones no tienen utilidad en esta clase 
	return 0;									 //
}												 //
												 //
float cProt_Quirurgica::get_largo()		         //son declaradas y definidas para evitar que la clase se considere abstracta
{												 //
	return 0;									 //
}												 //
												 //
float cProt_Quirurgica::get_Radio()		         //
{												 //
	return 0;									 //
}												 //
