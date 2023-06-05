#pragma once
#include <string>
#include <ctime>

using namespace std;


class cPaciente {
private:
	const string Nombre_Apellido;
	const time_t Fecha_Nac;
	string telefono;
	const string Alergias;
	string Hospital;
	const float Radio_Amputacion;
	bool Autorizacion;
	string Medico;

public:
	bool Solicitar_Autorizacion();
	void set_Autorizacion(bool Auto);
	void set_Medico(string Medico_);
	void set_Hospital(string Hospital_);
	string get_Nombre_Ap();
	string get_Hospital();
	bool get_Autorizacion();
	string get_Medico();

};