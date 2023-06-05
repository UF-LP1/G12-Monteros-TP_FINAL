#pragma once

#include <string>
#include "cProtesis.h"

class cProt_Quirurgica:public cProtesis {
private:
	string Articualcion;
	string Material;

public:
	cProt_Quirurgica(string Articulacion,string Material,string Nombre_, time_t Fecha_Fabricacion_, string Fabricante_, bool Superior_Inferior_);
	~cProt_Quirurgica();
};