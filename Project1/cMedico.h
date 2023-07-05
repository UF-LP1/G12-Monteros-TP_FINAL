#pragma once

#ifndef _CMEDICO_H
#define _CMEDICO_H

#include "cPaciente.h"

using namespace std;

class cMedico {
private:
	const string Nombre_Apellido;
	const unsigned int Matricula;
	bool Disponible;
public:
	cMedico(string Nombre_Apellido_, unsigned int Matricula_);
	cMedico(string Nombre_Apellido_, unsigned int Matricula_, bool Disponible_);
	~cMedico();

	bool Otorgar_Autorizacion(cPaciente &Paciente_actual_, unsigned int & Matricula_med);
	string get_Nombre();
	bool get_Disponibilidad();
	unsigned int get_Matricula();
	string to_string_med();
	void imprimir();
};

#endif