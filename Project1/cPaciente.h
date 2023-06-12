#pragma once
#include <string>
#include <ctime>
#include "cMedico.h"

using namespace std;
#define N 5 //Cantidad maxima de alergias de una persona
enum { Brazo = 1, Pierna, Mano, Dedo, Pie, Hombro, Cadera, Clavicula, Placa_Metalica, Implante_Dental};
class cPaciente {
private:

	friend class cMedico;
	const string Nombre_Apellido;
	const time_t Fecha_Nac;
	string Telefono;
	const string Alergias[N];
	string Hospital;
	const float Radio_Amputacion;
	bool Autorizacion;
	string Medico;
	unsigned int Organo_Extremidad_Danyada;
	unsigned int Largo_amputacion;
	unsigned int ancho_amputacion;

public:

	cPaciente(string Nombre_Apellido_, time_t Feca_Nac_, string Telefono_, string Alergias_[N], string Hospital_, float Radio_Amp_);
	~cPaciente();
	void set_Autorizacion(bool Auto);
	void set_Medico(string Medico_);
	void set_Hospital(string Hospital_);
	string get_Nombre_Ap();
	string get_Hospital();
	bool get_Autorizacion();
	string get_Medico();
	void set_Dim_ancho(unsigned int ancho);
	void set_Dim_largo(unsigned int largo);
	float get_radio();
	float get_largo();
	float get_ancho();
	unsigned int get_danyada();
};