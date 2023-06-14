#pragma once

#include <string>
#include "cProtesis.h"

class cProt_Quirurgica:public cProtesis {
private:
	string Articulacion;
	string Material;

public:
	cProt_Quirurgica(string Articulacion,string Material, Organo_Extremidad_Reemplazada Nombre_, time_t Fecha_Fabricacion_, string Fabricante_, bool Superior_Inferior_);
	~cProt_Quirurgica();
	string  get_material();
	string  get_Articulacion();
	float get_ancho();
	float get_largo();
	float get_Radio();
};