#pragma once

#include <string>
#include "cProtesis.h"

class cProt_No_Quirurgica:public cProtesis {

private:
	unsigned int Dim_Largo;
	unsigned int Dim_Ancho;
	unsigned int Radio_Conexion;

public:
	cProt_No_Quirurgica(Organo_Extremidad_Reemplazada Nombre_, time_t Fecha_Fabricacion_, string Fabricante_, bool Superior_Infeior, unsigned int Dim_Largo_, unsigned int Dim_Ancho_, unsigned int Radio_Conexion);
	cProt_No_Quirurgica(cProt_No_Quirurgica &copia);
	~cProt_No_Quirurgica();

	unsigned int get_Largo();
	unsigned int get_Ancho();
	unsigned int get_Radio();
};