#include "cOrtopedia.h"

cOrtopedia::cOrtopedia(string Nombre_, string Direccion_, string Especializacion_, list<cProtesis> lista_stock_): Nombre(Nombre_), Direccion(Direccion_), Especializacion(Especializacion_)
{
	list<cProtesis>::iterator it = this->Stock_Protesis.begin();
	this->Stock_Protesis.insert(it, lista_stock_.begin(), lista_stock_.end());
}

cOrtopedia::~cOrtopedia()
{
}

bool cOrtopedia::Buscar_Protesis(float Radio_Amp, string Alergias[])
{
	return false;
}

bool cOrtopedia::Buscar_Por_Alergias(list<cProtesis> lista_filtrada, string Alergias[])
{
	return false;
}

bool cOrtopedia::Buscar_Por_radio(float Radio_Amp)
{
	return false;
}

list<cProtesis> cOrtopedia::get_stock()
{
	return this->Stock_Protesis;
}
void cOrtopedia:: operator-(cProtesis* eliminado) {

}


