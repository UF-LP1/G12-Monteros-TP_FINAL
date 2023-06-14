#pragma once

#include <string>
#include <list>
#include "cMedico.h"
#include "cOrtopedia.h"
#include "cPaciente.h"
#include <queue>
using namespace std;

class cHospital {

private:
	const string Nombre;
	list<cMedico> Lista_Medicos;
	const string Direccion;
	const string Especialidad;
	list<cOrtopedia*> lista_Afiliadas;
	list<cPaciente*> Lista_pacientes ;

public:
	cHospital(string Nombre_,string Direccion_,string Especialidad_, list<cMedico> Lista_Medicos_, string Direccion, string Especialidad, list<cOrtopedia> Lista_Afiliadas_);
	~cHospital();
	void set_Pacientes(list<cPaciente> lista_actual);
	bool Evaluar_Paciente(cPaciente Paciente_Actual);
	string get_Nombre();
	list<cOrtopedia*> get_afiliadas();
	list<cMedico> get_Medicos();
};