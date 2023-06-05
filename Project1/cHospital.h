#pragma once

#include <string>
#include <list>
#include "cMedico.h"
#include "cOrtopedia.h"
using namespace std;

class cHospital {

private:
	const string Nombre;
	list<cMedico> Lista_Medicos;
	const string Direccion;
	const string Especialidad;
	list<cOrtopedia> lista_Afiliadas;

public:
	cHospital(string Nombre_,string Direccion_,string Especialidad_, list<cMedico> Lista_Medicos_, string Direccion, string Especialidad, list<cOrtopedia> Lista_Afiliadas_);
	~cHospital();
};