#include "cMedico.h"

cMedico::cMedico(string Nombre_Apellido_, unsigned int Matricula_, string Hospitales_) :Nombre_Apellido(Nombre_Apellido_), Matricula(Matricula_)
{
	this->Hospitales = Hospitales_;
}

cMedico::~cMedico()
{
}

bool cMedico::Otorgar_Autorizacion()
{
	return false;
}

bool cMedico::Elevar_sol_Protesis()
{
	return false;
}
