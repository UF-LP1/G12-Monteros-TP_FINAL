#pragma once

#ifndef _CPACIENTE_H
#define _CPACIENTE_H

#include "cProt_No_Quirurgica.h"
#include "cProt_Quirurgica.h"


class cPaciente {
private:

	friend class cMedico;
	const string Nombre_Apellido;
	const tm Fecha_Nac;
	string Telefono;
	list<string*> Alergias;
	string Hospital;
	const float Radio_Amputacion;
	bool Autorizacion;
	string Medico;
	cProt_Quirurgica Necesitada_Q;
	cProt_No_Quirurgica Necesitada_NQ;


public:

	cPaciente(string Nombre_Apellido_, tm Feca_Nac_, string Telefono_, list<string*> Alergias_, float Radio_Amp_);
	~cPaciente();
	void set_Autorizacion(bool Auto);
	void set_Medico(string Medico_);
	void set_Hospital(string Hospital_);
	string get_Nombre_Ap();
	string get_Hospital();
	bool get_Autorizacion();
	string get_Medico();
	float get_radio();
	float get_largo();
	float get_ancho();
	Organo_Extremidad_Reemplazada get_danyada();
	cProt_No_Quirurgica get_Prot_NQ();
	cProt_Quirurgica get_Prot_Q();
};
#endif