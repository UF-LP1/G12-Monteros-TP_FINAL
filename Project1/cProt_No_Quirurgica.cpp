#include "cProt_No_Quirurgica.h"

cProt_No_Quirurgica::cProt_No_Quirurgica(string Nombre_, time_t Fecha_Fabricacion_, string Fabricante_, bool Superior_Inferior_, unsigned int Dim_Largo_, unsigned int Dim_Ancho_, unsigned int Radio_Conexion_): cProtesis(Nombre_,Fecha_Fabricacion_, Fabricante_, Superior_Inferior_)
{
	this->Dim_Ancho = Dim_Ancho_;
	this->Dim_Largo = Dim_Largo_;
	this->Radio_Conexion = Radio_Conexion_;
}

cProt_No_Quirurgica::~cProt_No_Quirurgica()
{
}
