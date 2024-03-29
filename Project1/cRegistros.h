#pragma once

#ifndef _CREGISTROS_H
#define _CREGISTROS_H

#include "cprotesis.h"


using namespace std;

class cRegistros {

private:
	const string Hospital;
	const string Medico;
	tm Fecha_Sol;
	tm Fecha_Entrega;
	const unsigned int Estimacion;
	const Organo_Extremidad_Reemplazada Pieza;
	const string Paciente;
	const string Nombre_Fuente;
	friend class cANPA;
public:
	cRegistros(string Hospital_, string Medico_, tm Fecha_sol_, tm Fecha_Entrega_, unsigned int Estimacion_, Organo_Extremidad_Reemplazada Pieza_, string Paciente_, string Nombre_Fuente_);
	~cRegistros();
	string to_string_registros() const;
	string to_string_registros_csv() const;
};
ostream& operator<<(ostream& out, const cRegistros& Registro); //esta sobrecarga cumple la misma funcion que un imprimir

#endif