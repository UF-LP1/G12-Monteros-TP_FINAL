#pragma once

#ifndef _CPROT_QUIRURGICA_H
#define _CPROT_QUIRURGICA_H

#include "cProtesis.h"

class cProt_Quirurgica:public cProtesis {
private:
	string Articulacion;
	string Material;

public:
	cProt_Quirurgica(string Articulacion,string Material, Organo_Extremidad_Reemplazada Nombre_, tm Fecha_Fabricacion_, string Fabricante_, bool Superior_Inferior_);
	~cProt_Quirurgica();

	cProt_Quirurgica();
	string  get_material();
	string  get_Articulacion();
	float get_ancho();
	float get_largo();
	float get_Radio();
};

#endif