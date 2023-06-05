#include "cPaciente.h"

bool cPaciente::Solicitar_Autorizacion()
{
	return false;
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
