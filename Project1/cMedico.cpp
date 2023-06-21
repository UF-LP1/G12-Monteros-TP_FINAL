#include "cMedico.h"

cMedico::cMedico(string Nombre_Apellido_, unsigned int Matricula_) :Nombre_Apellido(Nombre_Apellido_), Matricula(Matricula_)
{
	srand(time(0));
	this->Disponible = rand() % 2 + 1;
}

cMedico::~cMedico()
{

}

bool cMedico::Otorgar_Autorizacion(cPaciente Paciente_actual_, unsigned int & Matricula_med)
{
	srand(time(0));
	Paciente_actual_.set_Medico(this->Nombre_Apellido);
	if ((rand() % 2 + 1)== 1 && (0 < Paciente_actual_.get_danyada()) && Paciente_actual_.get_danyada() <= 10)
	{	                                              // es aleatorio si la solicitud el paciente es autorizada
												      // y si tiene una lesion o no es aleatorio, por propositos de simulacion
		
		
		if ((Organo_Extremidad_Reemplazada)0 < Paciente_actual_.get_danyada() && Paciente_actual_.get_danyada() <= (Organo_Extremidad_Reemplazada)5)  // en el caso de que necesite una protesis no quirurgica se necesitan acalsraar als dimensiones para poder buscarla
		{
			srand(time(0));
			Paciente_actual_.get_Prot_NQ().set_Dim_ancho((float)(rand() % 10 + 1));

			srand(time(0));                                           
			Paciente_actual_.get_Prot_NQ().set_Dim_largo((float)(rand() % 9 + 1));
		}                                                                //no definimos ningun otro dato en el caso de necesitar prot quirurgica porque ya tenemos 
															             //que necesita (nombre) y los materiales a los que el paciente es alergico

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

