#pragma once

#ifndef _CHOSPITAL_H
#define _CHOSPITAL_H


#include "cMedico.h"
#include "cOrtopedia.h"
#include "cPaciente.h"
#include <queue>
using namespace std;

class cHospital {

private:
	const string Nombre;
	list<cMedico*> Lista_Medicos;
	const string Direccion;
	const string Especialidad;
	list<cOrtopedia*> lista_Afiliadas;
	queue<cPaciente*> Cola_pacientes ;
	list<cPaciente*> Pacientes_Atendidos;

public:
	cHospital(string Nombre_,string Direccion_,string Especialidad_, list<cMedico*> Lista_Medicos_, list<cOrtopedia*> Lista_Afiliadas_, queue<cPaciente*> Cola_pac_);
	~cHospital();
	void set_Pacientes(queue<cPaciente*> lista_actual);
	bool Evaluar_Paciente(cPaciente Paciente_Actual, unsigned int& Matricula_med);
	string get_Nombre();
	list<cOrtopedia*> get_afiliadas();
	list<cMedico*> get_Medicos();
	queue<cPaciente*> get_Pacientes();
	void operator+(cPaciente* agregado);
};

#endif