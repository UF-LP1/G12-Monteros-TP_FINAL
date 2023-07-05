#include "cPaciente.h"

cPaciente::cPaciente(string Nombre_Apellido_, tm Feca_Nac_, string Telefono_, list<string*> Alergias_, float Radio_Amp_) : Nombre_Apellido(Nombre_Apellido_), Fecha_Nac(Feca_Nac_), Radio_Amputacion(Radio_Amp_)
{

	this->Telefono = Telefono_;
	this->Hospital = "nn";
	this->Autorizacion = false;
	this->Medico = "nn";
	this->Alergias = Alergias_;
	srand(time(nullptr));

	if (this->Radio_Amputacion > 0)                             //si hay un radio de amputacion se inicializa la parte danyada con algunas de las opciones no quirurgicas
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

void cPaciente::set_ancho(float seter)
{
	this->Necesitada_NQ.set_Dim_ancho(seter);
}

void cPaciente::set_largo(float seter)
{
	this->Necesitada_NQ.set_Dim_largo(seter);
}

void cPaciente::set_radio(float seter)
{
	this->Necesitada_NQ.set_radio(seter);
}

void cPaciente::set_articulacion(string seteada)
{
	this->Necesitada_Q.set_Articulacion(seteada);
}

void cPaciente::Recibir_Protesis_NQ(cProt_No_Quirurgica Seteada)
{
	this->Necesitada_NQ = Seteada;
}

void cPaciente::Recibir_Protesis_Q(cProt_Quirurgica Seteada)
{
	this->Necesitada_Q = Seteada;
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

list<string*> cPaciente::get_alergias()
{
	return this->Alergias;
}


