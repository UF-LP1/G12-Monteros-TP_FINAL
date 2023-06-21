#pragma once

#ifndef _CORTOPEDIA_H
#define _CORTOPEDIA_H

#include "cProtesis.h"

using namespace std;

class cOrtopedia {

private: 
	const string Nombre;
	const string Direccion;
	list<cProtesis*> Stock_Protesis;

public:
	cOrtopedia(string Nombre_, string Direccion_, list<cProtesis*> lista_stock);
	~cOrtopedia();
	string get_Direccion();
	bool Buscar_Por_Alergias(list<cProtesis> lista_filtrada, string Alergias[]);
	bool Buscar_Por_radio(float Radio_Amp);
	list<cProtesis*> get_stock();
	
	string get_Nombre();
	
};
void operator-(list<cProtesis> original, list<cProtesis>::iterator* eliminado);

#endif 