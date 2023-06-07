#include "cMedico.h"

cMedico::cMedico(string Nombre_Apellido_, unsigned int Matricula_, string Hospitales_) :Nombre_Apellido(Nombre_Apellido_), Matricula(Matricula_)
{
	this->Hospitales = Hospitales_;
	srand(time(0));

	this->Disponible = rand() % 2 + 1;
}

cMedico::~cMedico()
{

}

bool cMedico::Otorgar_Autorizacion(cPaciente Paciente_actual)
{
	srand(time(0));
	Paciente_actual.set_Medico(this->Nombre_Apellido);
	if (rand() % 2 + 1 == 1 && 0<Paciente_actual.Organo_Extremidad_Danyada<=10) // es aleatorio si la solicitud el paciente es autorizada
	{														                    // porque si tiene una lesion o no es aleatorio, po propositos de simulacion
		
		
		if (0 < Paciente_actual.Organo_Extremidad_Danyada <= 5)  // en el cao de que necesite una protesis no quirurgica se necesitan acalsraar als dimensiones para poder buscarla
		{
			srand(time(0));
			Paciente_actual.set_Dim_ancho(rand() % 10 + 1);
			srand(time(0));                                           
			Paciente_actual.set_Dim_largo(rand() % 9 + 1);
		}                                                      //no definimos ningun otro dato en el caso de necesitar prot quirurgica porque ya tenemos 
		Paciente_actual.set_Autorizacion(true);				   //que necesita y los materiales a los que el paciente es alergico
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

