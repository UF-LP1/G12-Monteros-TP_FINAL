#pragma once

#include <string>
#include <ctime>

using namespace std;

class cProtesis {

private:
	const string Nombre;
	const time_t Fecha_Fabricacion;
	const string Fabricante;
	const bool Superior_Inferior;

public:
	cProtesis(string Nombre_, time_t Fecha_Fabricacion_, string Fabricante_, bool Superior_Inferior_);
	~cProtesis();
};