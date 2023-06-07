#pragma once

#include <string>
#include <list>
#include "cProtesis.h"

using namespace std;

class cOrtopedia {

private: 
	const string Nombre;
	const string Direccion;
	list<cProtesis> Stock_Protesis;
	const string Especializacion;

public:
	cOrtopedia(string Nombre_, string Direccion_, string Especializacion_, list<cProtesis> lista_stock);
	~cOrtopedia();
	bool Buscar_Protesis(float Radio_Amp, string Alergias[] );
	bool Buscar_Por_Alergias(list<cProtesis> lista_filtrada, string Alergias[]);
	bool Buscar_Por_radio(float Radio_Amp);
	list<cProtesis> get_stock();
};