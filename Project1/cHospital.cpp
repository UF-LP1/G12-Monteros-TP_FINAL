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
