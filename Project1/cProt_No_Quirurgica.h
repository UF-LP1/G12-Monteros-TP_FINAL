#pragma once

#ifndef _CPROT_NO_QUIRURGICA_H
#define _CPROT_NO_QUIRURGICA_H

#include "cProtesis.h"

class cProt_No_Quirurgica:public cProtesis {

private:
	float Radio_Conexion;
	float Dim_Largo;
	float Dim_Ancho;


public:
	cProt_No_Quirurgica(Organo_Extremidad_Reemplazada Nombre_, tm Fecha_Fabricacion_, string Fabricante_, bool Superior_Infeior, float Dim_Largo_, float Dim_Ancho_, float Radio_Conexion);
	//cProt_No_Quirurgica(cProt_No_Quirurgica &copia);
	cProt_No_Quirurgica();
	~cProt_No_Quirurgica();

	float get_largo();
	float get_ancho();
	string get_material();
	string get_Articulacion();
	float get_Radio();
	void set_Dim_ancho(float set_);
	void set_Dim_largo(float set_);
};

#endif