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

string cOrtopedia::to_string_Ort()
{
	stringstream Salida;
	Salida << "Nombre: " << this->Nombre
		<< ", Direccion: " << this->Direccion << endl
		<< "STOCK:" << endl;
	list<cProtesis*>::iterator it = this->Stock_Protesis.begin();
	while (it != this->Stock_Protesis.end())
	{
		Salida<<(*it)->to_string()<<endl;
		it++;
	}
	return Salida.str();
}

void cOrtopedia::Imprimir_Ort()
{
	cout << to_string_Ort() << endl;
}


void operator-(list<cProtesis> original, list<cProtesis>::iterator* eliminado)
{
	original.erase(*eliminado);
}
