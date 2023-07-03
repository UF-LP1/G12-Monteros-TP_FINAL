#include "cOrtopedia.h"

cOrtopedia::cOrtopedia(string Nombre_, string Direccion_, list<cProtesis*> lista_stock_): Nombre(Nombre_), Direccion(Direccion_)
{
	list<cProtesis*>::iterator it = this->Stock_Protesis.begin();
	this->Stock_Protesis.insert(it, lista_stock_.begin(), lista_stock_.end());
}

cOrtopedia::~cOrtopedia()
{
}

string cOrtopedia::get_Direccion()
{
	return this->Direccion;
}


bool cOrtopedia::Buscar_Por_Alergias(list<cProtesis> lista_filtrada, string Alergias[])
{
	return false;
}

bool cOrtopedia::Buscar_Por_radio(float Radio_Amp)
{
	return false;
}

list<cProtesis*> cOrtopedia::get_stock()
{
	return this->Stock_Protesis;
}

list<cProtesis*>::iterator cOrtopedia::get_Primer_Prot()
{
	return this->Stock_Protesis.begin();
}

list<cProtesis*>::iterator cOrtopedia::get_ultima_Prot()
{
	return this->Stock_Protesis.end();
}

string cOrtopedia::get_Nombre()
{
	return this->Nombre;
}

//void cOrtopedia::Quitar_de_Stock(list<cProtesis>::iterator *quitado)
//{
//	this->Stock_Protesis-quitado;
//}

void operator-(list<cProtesis> original, list<cProtesis>::iterator* eliminado)
{
	original.erase(*eliminado);
}
