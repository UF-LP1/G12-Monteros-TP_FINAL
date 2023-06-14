#include "cPaciente.h"

cPaciente::cPaciente(string Nombre_Apellido_, time_t Feca_Nac_, string Telefono_, string Alergias_[N], string Hospital_, float Radio_Amp_) : Nombre_Apellido(Nombre_Apellido_), Fecha_Nac(Feca_Nac_),Alergias(Alergias_), Radio_Amputacion(Radio_Amp_)
{
	this->Telefono = Telefono_;
	this->Hospital = "nn";
	this->Autorizacion = false;
	this->Medico = "nn";



	srand(time(0));

	if (5>this->Radio_Amputacion > 0)                             //si hay un radio de amputacion se inicializa la parte danyada con algunas de las opciones no quirurgicas
	{                                                             //revisar enum de cPaciente.h
		this->Necesitada_NQ.set_Nombre( (Organo_Extremidad_Reemplazada)(rand() % 5 + 1));
	}
	else {                          // si el radio de amputacion es 0 se inicializa la parte danyada con alguna de las opciones quirurgicas  
		this->Necesitada_Q.set_Nombre( (Organo_Extremidad_Reemplazada)(rand() % 5 + 6));
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

float cPaciente::get_radio()
{
	return this->Radio_Amputacion;
}

float cPaciente::get_largo()
{
	return this->Necesitada_NQ.get_largo();
}

float cPaciente::get_ancho()
{
	return this->Necesitada_NQ.get_ancho();
}


Organo_Extremidad_Reemplazada cPaciente::get_danyada()
{
	if (Radio_Amputacion > 0)
		return Necesitada_NQ.get_nombre();
	else
		return Necesitada_Q.get_nombre();
}

cProt_No_Quirurgica cPaciente::get_Prot_NQ()
{
	return this->Necesitada_NQ;
}

cProt_Quirurgica cPaciente::get_Prot_Q()
{
	return this->Necesitada_Q;
}


