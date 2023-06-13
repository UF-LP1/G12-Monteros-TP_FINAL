#include "cPaciente.h"

cPaciente::cPaciente(string Nombre_Apellido_, time_t Feca_Nac_, string Telefono_, string Alergias_[N], string Hospital_, float Radio_Amp_) : Nombre_Apellido(Nombre_Apellido_), Fecha_Nac(Feca_Nac_),Alergias(Alergias_), Radio_Amputacion(Radio_Amp_)
{
	this->Telefono = Telefono_;
	this->Hospital = "nn";
	this->Autorizacion = false;
	this->Medico = "nn";
	this -> ancho_amputacion = 0;  // las dimensiones de la protesis no quirurgica empiezan en 0 porque 
	this->Largo_amputacion = 0;	   // las decide el medico al hacer el analisis y otorgar el permiso

	srand(time(0));

	if (this->Radio_Amputacion > 0) //si hay un radio de amputacion se inicializa la parte danyada con algunas de las opciones no quirurgicas
	{                               //revisar enum de cPaciente.h
		this->Organo_Extremidad_Danyada = (rand() % 5 + 1);
	}
	else {                          // si el radio de amputacion es 0 se inicializa la parte danyada con alguna de las opciones quirurgicas  
		this->Organo_Extremidad_Danyada = rand() % 5 + 6;
	}
}

cPaciente::~cPaciente()
{
}

void cPaciente::set_Autorizacion(bool Auto)
{
	this->Autorizacion = Auto;
}

void cPaciente::set_Medico(string Medico_)
{
	this->Medico = Medico_;
}

void cPaciente::set_Hospital(string Hospital_)
{
	this->Hospital = Hospital_;
}

string cPaciente::get_Nombre_Ap()
{
	return this->Nombre_Apellido;
}

string cPaciente::get_Hospital()
{
	return this->Hospital;
}

bool cPaciente::get_Autorizacion()
{
	return Autorizacion;
}

string cPaciente::get_Medico()
{
	return this->Medico;
}

void cPaciente::set_Dim_ancho(unsigned int ancho)
{
	this->ancho_amputacion = ancho;
}

void cPaciente::set_Dim_largo(unsigned int largo)
{
	this->Largo_amputacion = largo;
}

float cPaciente::get_radio()
{
	return this->Radio_Amputacion;
}

float cPaciente::get_largo()
{
	return this->Largo_amputacion;
}

float cPaciente::get_ancho()
{
	return this->ancho_amputacion;
}

unsigned int cPaciente::get_danyada()
{
	return this->Organo_Extremidad_Danyada;
}


