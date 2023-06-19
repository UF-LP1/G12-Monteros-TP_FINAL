#include "Funciones_aux.h"

using namespace std;

int main()
{
	//Por Motivos de simulacion haremos que cada hospital registrado en el ANPA atienda a cada uno de sus pacientes
	//mediante las funciones implementadas

	cANPA Prueba(leer_Fabricantes(), leer_Hospitales(), Leer_Ortopedias()); //inicializamos ANPA, que contiene todos los datos

	list<cHospital*>::iterator it_hospital = Prueba.get_Hospitales().begin();

	while (it_hospital != Prueba.get_Hospitales().end())
	{
		cPaciente* Paciente_actual((*it_hospital)->get_Pacientes().front());

	}

}