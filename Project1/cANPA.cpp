#include "cANPA.h"

cANPA::cANPA(list<cFabricante> Fabricantes_, list<cHospital> Hospitales_, list<cOrtopedia> Ortopedias_)
{
	list<cFabricante>::iterator it_Fab = this->Fabricantes.begin();
	list<cHospital>::iterator it_Hos = this->Hospitales.begin();
	list<cOrtopedia>::iterator it_Ort = this->Ortopedias.begin();

	this->Fabricantes.insert(it_Fab, Fabricantes_.begin(), Fabricantes_.end());
	this->Hospitales.insert(it_Hos, Hospitales_.begin(), Hospitales.end());
	this->Ortopedias.insert(it_Ort, Hospitales.begin(), Hospitales.end());
}

cANPA::~cANPA()
{
}

void cANPA::Crear_Registro()
{
}

bool cANPA::Solicitar_Protesis_A_Ortopedia()
{
	return false;
}

bool cANPA::Solicitar_Protesis_A_Fabricante()
{
	return false;
}

bool cANPA::Buscar_En_Ortopedia_convenida(string Nombre_hospital, cPaciente paciente_actual)
{
	cHospital Hos_aux();
	list<cHospital>::iterator it_hosp = this->Hospitales.begin();

	while (it_hosp != this->Hospitales.end())
	{
		if (it_hosp->get_Nombre() == Nombre_hospital)
		{
			break;
		}
		it_hosp++;
	}
	//Agregar una exception aca en caso de que no se encuentre el nombre del hospital en la lista de hospitales de ANPA

	list<cOrtopedia>::iterator it_Afiliadas = it_hosp->get_afiliadas().begin();
	list<cProtesis>::iterator it_prot;
	while (it_Afiliadas != it_hosp->get_afiliadas().end())
	{
		it_prot = it_Afiliadas->get_stock().begin();
		while (it_prot != it_Afiliadas->get_stock().end())
		{

		}
	}
	

	
}
