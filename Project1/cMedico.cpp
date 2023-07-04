#include "cMedico.h"

cMedico::cMedico(string Nombre_Apellido_, unsigned int Matricula_) :Nombre_Apellido(Nombre_Apellido_), Matricula(Matricula_)
{
	srand(time(0));
	this->Disponible = rand() % 2 == 0;
}

cMedico::cMedico(string Nombre_Apellido_, unsigned int Matricula_, bool Disponible_):Nombre_Apellido(Nombre_Apellido_), Matricula(Matricula_)
{
	this->Disponible = Disponible_;
}

cMedico::~cMedico()
{

}

bool cMedico::Otorgar_Autorizacion(cPaciente &Paciente_actual_, unsigned int & Matricula_med)
{
	srand(time(0));
	Paciente_actual_.set_Medico(this->Nombre_Apellido);
	float auxiliar;
	if ((0 < Paciente_actual_.get_danyada()) && Paciente_actual_.get_danyada() <= 10) //no se va a autorizar al paciente si no tiene una lesion
	{	                                              
		
		
		if ((Organo_Extremidad_Reemplazada)0 < Paciente_actual_.get_danyada() && Paciente_actual_.get_danyada() <= (Organo_Extremidad_Reemplazada)5)  // en el caso de que necesite una protesis no quirurgica se necesitan setear las dimensiones para poder buscarla
		{
			srand(time(0));
			auxiliar = (float)(rand() % 30 + 1);
			Paciente_actual_.set_ancho(auxiliar);

			srand(time(0));
			auxiliar = (float)(rand() % 90 + 1);
			Paciente_actual_.set_largo(auxiliar);
			Paciente_actual_.set_radio(Paciente_actual_.get_radio());
		}
		Paciente_actual_.set_Autorizacion(true);	
		Matricula_med = Matricula;
		return true;
	}
	else {
		return false;
	}


}

string cMedico::get_Nombre()
{
	return this->Nombre_Apellido;
}

bool cMedico::get_Disponibilidad()
{
	return this->Disponible;
}

unsigned int cMedico::get_Matricula()
{
	return this->Matricula;
}

