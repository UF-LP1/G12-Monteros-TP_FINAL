#include "cHospital.h"

cHospital::cHospital(string Nombre_, string Direccion_, string Especialidad_, list<cMedico*> Lista_Medicos_, list<cOrtopedia*> Lista_Afiliadas_, queue<cPaciente*> Cola_pac_): Nombre(Nombre_),Direccion(Direccion_), Especialidad(Especialidad_)
{
	this->Lista_Medicos = Lista_Medicos_;
	this->Cola_pacientes = Cola_pac_;
	this->lista_Afiliadas = Lista_Afiliadas_;
}

cHospital::~cHospital()
{
}

void cHospital::set_Pacientes(queue<cPaciente*> cola_actual)
{
	this->Cola_pacientes=cola_actual;
}

bool cHospital::Evaluar_Paciente(cPaciente Paciente_Actual)
{
	list<cMedico*>::iterator Med_Aux = this->Lista_Medicos.begin();
	while (Med_Aux != this->Lista_Medicos.end())
	{
		if ((*Med_Aux)->get_Disponibilidad() == true)
			return (*Med_Aux)->Otorgar_Autorizacion(Paciente_Actual);
	}
	return false;  // caso de que no haya ningun medico disponible en el hospital
}

string cHospital::get_Nombre()
{
	return this->Nombre;
}

list<cOrtopedia*> cHospital::get_afiliadas()
{
	return this->lista_Afiliadas;
}

list<cMedico*> cHospital::get_Medicos()
{
	return this->Lista_Medicos;
}

queue<cPaciente*> cHospital::get_Pacientes()
{
	return this->Cola_pacientes;
}
