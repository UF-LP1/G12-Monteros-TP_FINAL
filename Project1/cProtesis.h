#pragma once

#include <string>
#include <ctime>
#include "cProt_No_Quirurgica.h"
#include "cProt_Quirurgica.h"
#include <list>

using namespace std;

class cProtesis {

private:
	const unsigned int Nombre;
	const time_t Fecha_Fabricacion;
	const string Fabricante;
	const bool Superior_Inferior;

public:
	cProtesis(unsigned int Nombre_, time_t Fecha_Fabricacion_, string Fabricante_, bool Superior_Inferior_);
	~cProtesis();
	cProtesis(list<cProtesis>::iterator copia);
	unsigned int get_nombre();
	time_t get_Fabricacion();
	string get_Fabricante();
	bool get_Superior_inferior();
};