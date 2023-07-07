#include "cProt_Quirurgica.h"

cProt_Quirurgica::cProt_Quirurgica(string Articulacion_, string Material_, Organo_Extremidad_Reemplazada Nombre_, tm Fecha_Fabricacion_, string Fabricante_, bool Superior_Inferior_):cProtesis(Nombre_,Fecha_Fabricacion_,Fabricante_,Superior_Inferior_)
{
	this->Articulacion = Articulacion_;
	this->Material = Material_;
}

cProt_Quirurgica::cProt_Quirurgica(list<cProtesis*>::iterator copia):cProtesis((*copia)->get_nombre(), (*copia)->get_Fabricacion(), (*copia)->get_Fabricante(), (*copia)->get_Superior_inferior())
{
	this->Articulacion = (*copia)->get_Articulacion();
	this->Material = (*copia)->get_material();
}

cProt_Quirurgica::~cProt_Quirurgica()
{
}

cProt_Quirurgica::cProt_Quirurgica():cProtesis()
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

float cProt_Quirurgica::get_ancho()		 
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

void cProt_Quirurgica::set_Articulacion(string seteada)
{
	this->Articulacion = seteada;
}

string cProt_Quirurgica::to_string()
{
	string aux;
	if (Superior_Inferior) { aux = "Superior"; }
	else { aux = "Inferior"; }

	stringstream Salida;
	Salida <<", Articulacion:"<<this->Articulacion
		<<"Material: "<<this->Material
		<< ", Miembro reemplazado: " << this->Nombre
		<< ", Fecha de fabricacion: " << this->Fecha_Fabricacion.tm_mday << "/" << Fecha_Fabricacion.tm_mon << "/" << Fecha_Fabricacion.tm_year + 1900
		<< ", Fabricante: " << this->Fabricante
		<< ", Seccion del cuerpo: " << aux << endl;

	return Salida.str();
}

void cProt_Quirurgica::imprimir_Prot_Q()
{
	cout << to_string() << endl;
}
