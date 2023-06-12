#pragma once

#include <string>
#include<ctime>

using namespace std;

class cRegistros {

private:
	const string Hospital;
	const string Medico;
	const tm* Fecha_Sol;
	const tm* Fecha_Entrega;
	const unsigned int Estimacion;
	const string Pieza;
	const string Paciente;
	const string Nombre_Fuente;

public:
	cRegistros(string Hospital_, string Medico_, tm* Fecha_sol_, tm* Fecha_Entrega_, unsigned int Estimacion_, string Pieza_, string Paciente_, string Nombre_Fuente_);
	~cRegistros();
};