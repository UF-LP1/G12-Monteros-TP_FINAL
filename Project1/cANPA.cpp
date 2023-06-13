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
		if (paciente_actual.get_radio() > 0)            //si el paciente tiene un radio de amputacion,
		{												//necesita una protesis de un miembro, es decir no quirurgica

			while (it_prot != it_Afiliadas->get_stock().end())
			{
				cProtesis *aux1();
				cProt_No_Quirurgica* aux{ dynamic_cast<cProt_No_Quirurgica*>(*aux1) };

				if (paciente_actual.get_danyada() == it_prot->get_nombre()) 
				{
					if (paciente_actual.get_ancho() == it_prot.get_ancho() && paciente_actual.get_largo()==it_prot.get_largo())
						Registrar_tramite(it_prot->get_nombre(),)

				}
				it_prot++;
			}
		}
		it_Afiliadas++;
	}
	
}

void cANPA::Registrar_tramite(string Pieza_, cHospital Hospital_, unsigned int Matricula_Med, string Nombre_pac, string Nombre_fuente)
{
	time_t fecha_actual;
	time(&fecha_actual);
	srand(time(0));

	unsigned int estimacion = rand() % 10 + 1;
	tm* Fecha_entrega = localtime(&fecha_actual);
	Fecha_entrega->tm_mday += estimacion;        //la protesis se entrega en cualquier momento entre un lapso de 10 dias 
												 //despues de la solicitud aceptada
	cRegistros* aux= new cRegistros(Hospital_.get_Nombre(), Buscar_Medico(Hospital_, Matricula_Med), localtime(&fecha_actual),Fecha_entrega , estimacion, Pieza_, Nombre_pac, Nombre_fuente);
	
	this->lista_registros + aux;
}

string cANPA::Buscar_Medico(cHospital Hospital_, unsigned int Matricula)
{
	list<cMedico>::iterator it = Hospital_.get_Medicos().begin();
	while (it != Hospital_.get_Medicos().end())
	{
		if (it->get_Matricula() == Matricula)
			return it->get_Nombre();
	}
	// no se necesita una excepcion para el caso de que no exista el medico, porque la existencia de dicho medico ya fue comprobada anteriormente en el codigo
}

list<cRegistros>& operator+(list<cRegistros> lista, cRegistros* agregado)
{
	lista.push_back(*agregado); //no es necesario agregar una excepcion porque el metodo pushback es a prueba de excepciones
	                            //fuente:cplusplus
}
