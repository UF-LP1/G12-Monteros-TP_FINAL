#include "cProt_No_Quirurgica.h"

cProt_No_Quirurgica::cProt_No_Quirurgica(Organo_Extremidad_Reemplazada Nombre_, time_t Fecha_Fabricacion_, string Fabricante_, bool Superior_Inferior_, unsigned int Dim_Largo_, unsigned int Dim_Ancho_, unsigned int Radio_Conexion_): cProtesis(Nombre_,Fecha_Fabricacion_, Fabricante_, Superior_Inferior_)
{
	this->Dim_Ancho = Dim_Ancho_;
	this->Dim_Largo = Dim_Largo_;
	this->Radio_Conexion = Radio_Conexion_;
}

cProt_No_Quirurgica::cProt_No_Quirurgica(cProt_No_Quirurgica& copia):cProtesis(copia)
{
	this->Dim_Ancho = copia.get_ancho();
	this->Dim_Largo = copia.get_largo();
	this->Radio_Conexion = copia.get_Radio();
}

cProt_No_Quirurgica::~cProt_No_Quirurgica()
{
}

float cProt_No_Quirurgica::get_largo()
{
	return this->Dim_Largo;
}

float cProt_No_Quirurgica::get_ancho()
{
	return this->Dim_Ancho;
}
													  //
string cProt_No_Quirurgica::get_material()			  //
{													  //
	return "Acero";									  //estas dos funciones no tienen utilidad en las protesis no quirurgicas
}													  //se declaran y definen para evitar que la clase sea abstracta 
													  //
string cProt_No_Quirurgica::get_Articulacion()		  //
{
	return "Miembro";
}

float cProt_No_Quirurgica::get_Radio()
{
	return this->Radio_Conexion;
}
