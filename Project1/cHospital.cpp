#include "cHospital.h"

cHospital::cHospital(string Nombre_, string Direccion_, string Especialidad_, list<cMedico> Lista_Medicos_, string Direccion, string Especialidad, list<cOrtopedia> Lista_Afiliadas_): Nombre(Nombre_),Direccion(Direccion_), Especialidad(Especialidad_)
{
	list<cMedico>::iterator it_med = this->Lista_Medicos.begin();
	this->Lista_Medicos.insert(it_med, Lista_Medicos_.begin(), Lista_Medicos_.end());

	list<cOrtopedia>::iterator it_ort = this->lista_Afiliadas.begin();
	this->lista_Afiliadas.insert(it_ort, Lista_Afiliadas_.begin(), Lista_Afiliadas_.end());
}

cHospital::~cHospital()
{
}

void cHospital::set_Pacientes(list<cPaciente> lista_actual)
{
	list<cPaciente>::iterator it = this->Lista_pacientes.begin();
	this->Lista_pacientes.insert(it, lista_actual.begin(), lista_actual.end());
}

bool cHospital::Evaluar_Paciente(cPaciente Paciente_Actual)
{
	list<cMedico>::iterator Med_Aux = this->Lista_Medicos.begin();
	while (Med_Aux != this->Lista_Medicos.end())
	{
		if (Med_Aux->get_Disponibilidad() == true)
			return Med_Aux->Otorgar_Autorizacion(Paciente_Actual);
	}
	return false;  // caso de que no haya ningun medico disponible en el hospital
}

string cHospital::get_Nombre()
{
	return this->Nombre;
}
