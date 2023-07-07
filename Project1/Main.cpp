#include "Funciones_aux.h"

using namespace std;

int main()
{
	//Por Motivos de simulacion haremos que cada hospital registrado en el ANPA atienda a cada uno de sus pacientes
	//mediante las funciones implementadas

	//cANPA Prueba(leer_Fabricantes(), leer_Hospitales(), Leer_Ortopedias()); //inicializamos ANPA, que contiene todos los datos de forma random
	//o
	cANPA Prueba(Fabricantes_Predeterminados(), Hospitales_Predeterminados(), Ortopedias_Predeterminadas()); //inicializamos ANPA con datos predeterminados (excepto las alergias de pacientes)

	list<cHospital*>::iterator it_hospital = Prueba.get_Primer_Hospital();

	unsigned int Matricula_auxiliar = 0;
	bool comprobacion=true;

	while (it_hospital != Prueba.get_ultimo_hospital())
	{
		while ((*it_hospital)->get_Pacientes_pendientes() != 0)
		{
			cPaciente* Paciente_actual((*it_hospital)->get_Pacientes().front()); // variable auxiliar para cada paciente
			(*it_hospital)->Popear_Paciente();

			if ((*it_hospital)->Evaluar_Paciente(*Paciente_actual, Matricula_auxiliar)) //si es true, el medico atendio al paciente y el paciente tiene la autorizacion y los datos de protesis
			{
				comprobacion = Prueba.Buscar_En_Ortopedia_convenida((*it_hospital)->get_Nombre(), *Paciente_actual, Matricula_auxiliar);  //se busca en ortopedias convenidas
				if (comprobacion == false) {
					comprobacion = Prueba.Busqueda_Especial((*it_hospital)->get_Nombre(), *Paciente_actual, Matricula_auxiliar);//si no se encuentra se busca en no convenidas
				}
				if (comprobacion == false) {
					try {
						Prueba.Solicitar_Protesis_A_Fabricante((*it_hospital)->get_Nombre(), *Paciente_actual, Matricula_auxiliar);//si nadie las tiene se pude fabricar una
					}
					catch (exception* e) {
						cout << e->what() << endl;
						delete e;
					}
				}
			}// si el medico no autoriza al paciente, se pasa al siguiente paciente
			(*it_hospital)->Archivar_paciente(Paciente_actual);
		}
		it_hospital++;
	}
	cout << Prueba << endl;

	Escribir_Archivo(Prueba);
	return 1;
}