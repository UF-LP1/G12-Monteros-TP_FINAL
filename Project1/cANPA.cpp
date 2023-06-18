#include "cANPA.h"

#ifndef __STDC_LIB_EXT1__
#define __STDC_LIB_EXT1__
#endif
#define __STDC_WANT_LIB_EXT1__ 1

cANPA::cANPA(list<cFabricante*> Fabricantes_, list<cHospital*> Hospitales_, list<cOrtopedia*> Ortopedias_)
{
	list<cFabricante*>::iterator it_Fab = this->Fabricantes.begin();
	list<cHospital*>::iterator it_Hos = this->Hospitales.begin();
	list<cOrtopedia*>::iterator it_Ort = this->Ortopedias.begin();

	this->Fabricantes.insert(it_Fab, Fabricantes.begin(), Fabricantes.end());
	this->Hospitales.insert(it_Hos, Hospitales.begin(), Hospitales.end());
	this->Ortopedias.insert(it_Ort, Ortopedias.begin(), Ortopedias.end());
	this->lista_registros.clear();
}

cANPA::~cANPA()
{
}

bool cANPA::Solicitar_Protesis_A_Ortopedia()
{
	return false;
}

bool cANPA::Solicitar_Protesis_A_Fabricante(string Nombre_hospital, cPaciente Paciente_Actual, unsigned int Matricula_med_)
{
	list<cHospital*>::iterator it_hosp = this->Hospitales.begin(); // todas las veces comprobamos que el hospital exista en las
	                                                              //listas del ANPA

	while (it_hosp != this->Hospitales.end())
	{
		if ((*it_hosp)->get_Nombre() == Nombre_hospital)
		{
			break;
		}
		it_hosp++;
	}

	list<cFabricante*>::iterator it_Fab = this->Fabricantes.begin();
	string tipo_fuente = "Fabricante";
	
	while (it_Fab != this->Fabricantes.end())
	{
		srand(time(0));

		if ((rand() % 4 + 1) == 4) //una de cada 4 veces el fabricante acepta hacer una protesis a medida
		{
			time_t fechaactual;
			time(&fechaactual);

			tm Actual;
			localtime_s(&Actual, &fechaactual);

			Registrar_tramite(Paciente_Actual.get_danyada(), it_hosp, Matricula_med_, Paciente_Actual.get_Nombre_Ap(), tipo_fuente += (*it_Fab)->get_Nombre());
			if (Paciente_Actual.get_radio() > 0)
			{
				cProt_No_Quirurgica Fabricada(Paciente_Actual.get_danyada(),Actual , (*it_Fab)->get_Nombre(), Paciente_Actual.get_Prot_NQ().get_Superior_inferior(), Paciente_Actual.get_Prot_NQ().get_largo(), Paciente_Actual.get_Prot_NQ().get_ancho(), Paciente_Actual.get_radio());
				
			}
			return true;
		}
	}

	return false;
}

bool cANPA::Busqueda_Especial(string Nombre_hospital,cPaciente Paciente_Actual, unsigned int Matricula_med_)
{
	list<cHospital*>::iterator it_hosp = this->Hospitales.begin();

	while (it_hosp != this->Hospitales.end())
	{
		if ((*it_hosp)->get_Nombre() == Nombre_hospital)
		{
			break;
		}
		it_hosp++;
	}

	list<cOrtopedia*>::iterator it_No_Convenidas = this->Ortopedias.begin();
	list<cProtesis*>::iterator it_prot;
	string tipo_fuente = "Ortopedia";

	while (it_No_Convenidas != this->Ortopedias.end())
	{
		if (it_No_Convenidas != (*it_hosp)->get_afiliadas())      //operador sobrecargado, si son ortopedias convenidas, 
		{	                                                   //no hace el resto de preguntas 
		
			it_prot = (*it_No_Convenidas)->get_stock().begin();
			if (Paciente_Actual.get_radio() > 0)
			{
				while (it_prot != (*it_No_Convenidas)->get_stock().end())
				{
					//cProtesis* aux = new cProt_No_Quirurgica();    //revisar si esto funciona
					// aux = (cProt_No_Quirurgica*)(&it_prot);

					if (it_prot ==  Paciente_Actual.get_Prot_NQ())
					{
						Registrar_tramite(Paciente_Actual.get_danyada(), it_hosp, Matricula_med_, Paciente_Actual.get_Nombre_Ap(), tipo_fuente += (*it_No_Convenidas)->get_Nombre());

						it_No_Convenidas - &it_prot;
						return true;
					}

					it_prot++;
				}
			}
			else
				while (it_prot != (*it_No_Convenidas)->get_stock().end())
				{
					//cProtesis* aux = new cProt_Quirurgica();    //revisar si esto funciona
					//aux = (cProt_Quirurgica*)(&it_prot);   

					if (it_prot == Paciente_Actual.get_Prot_Q())
					{
						Registrar_tramite(Paciente_Actual.get_danyada(), it_hosp, Matricula_med_, Paciente_Actual.get_Nombre_Ap(), tipo_fuente += (*it_No_Convenidas)->get_Nombre());
						it_No_Convenidas -&it_prot; 
						return true;
					}
					it_prot++;
				}
		}
		it_No_Convenidas++;
	}

	return false;
}

bool cANPA::Buscar_En_Ortopedia_convenida(string Nombre_hospital, cPaciente paciente_actual,unsigned int Matricula_med_)
{
	
	list<cHospital*>::iterator it_hosp = this->Hospitales.begin();

	while (it_hosp != this->Hospitales.end())
	{
		if ((*it_hosp)->get_Nombre() == Nombre_hospital)
		{
			break;
		}
		it_hosp++;
	}
	//Agregar una exception aca en caso de que no se encuentre el nombre del hospital en la lista de hospitales de ANPA

	string 	tipo_fuente = "ortopedia";;
	list<cOrtopedia*>::iterator it_Afiliadas = (*it_hosp)->get_afiliadas().begin();

	list<cProtesis*>::iterator it_prot;

	while (it_Afiliadas != (*it_hosp)->get_afiliadas().end())
	{
		it_prot = (*it_Afiliadas)->get_stock().begin();
		if (paciente_actual.get_radio() > 0)            //si el paciente tiene un radio de amputacion,
		{												//necesita una protesis de un miembro, es decir no quirurgica

			while (it_prot != (*it_Afiliadas)->get_stock().end())
			{

				if (it_prot == paciente_actual.get_Prot_NQ())
				{
					//cProt_No_Quirurgica* aux =dynamic_cast<cProt_No_Quirurgica*>(it_prot) efectivamente esto no funciona a menos que tengas un puntero en todas tus listas
					//revisar si la alternativa de los gets virtuales funciona
	
						Registrar_tramite(paciente_actual.get_danyada(), it_hosp, Matricula_med_, paciente_actual.get_Nombre_Ap(), tipo_fuente += (*it_Afiliadas)->get_Nombre()); 

						//si se encuentra la pieza necesitada se genera un registro de la venta/tramite con los datos de
						//los implicados y como fuente de la protesis se especifica que la fuente fue una ortopedia y se agrega su nombre
						//aprovechando sobrecarga de operadores de la clase string
						
						it_Afiliadas-&it_prot; 

						return true;
					
				}
				it_prot++;
			}
		}
		else
		{
			while (it_prot != (*it_Afiliadas)->get_stock().end())
			{

				if (it_prot == paciente_actual.get_Prot_Q())
				{
					Registrar_tramite(paciente_actual.get_danyada(), it_hosp, Matricula_med_, paciente_actual.get_Nombre_Ap(), tipo_fuente += (*it_Afiliadas)->get_Nombre());
					it_Afiliadas - &it_prot;
					return true;
				}
				it_prot++;
			}
		}
		it_Afiliadas++;
	}

	if (it_Afiliadas == (*it_hosp)->get_afiliadas().end())
		return false;
}

void cANPA::Registrar_tramite(Organo_Extremidad_Reemplazada Pieza_, list<cHospital*>::iterator Hospital_, unsigned int Matricula_Med, string Nombre_pac, string Nombre_fuente)
{
	time_t fecha_actual;
	time(&fecha_actual);
	srand(time(0));

	unsigned int estimacion = rand() % 10 + 1;
	tm Fecha_Actual;
	localtime_s(&Fecha_Actual, &fecha_actual);

	tm fecha_entrega=Fecha_Actual;
	fecha_entrega.tm_mday += estimacion;
	                                             //la protesis se entrega en cualquier momento entre un lapso de 10 dias 
												 //despues de que la solicitud fue aceptada
	cRegistros* aux= new cRegistros((*Hospital_)->get_Nombre(), Buscar_Medico(Hospital_, Matricula_Med), &Fecha_Actual, &fecha_entrega, estimacion, Pieza_, Nombre_pac, Nombre_fuente);
	
	this->lista_registros + aux;  // se crea el registro con los datos recibidos y se agrega a la lista
}

string cANPA::Buscar_Medico(list<cHospital*>::iterator Hospital_, unsigned int Matricula)
{
	list<cMedico*>::iterator it =  (*Hospital_)->get_Medicos().begin();

	while (it != (*Hospital_)->get_Medicos().end())
	{
		if ((*it)->get_Matricula() == Matricula)
			return (*it)->get_Nombre();
	}
	// no se necesita una excepcion para el caso de que no exista el medico, porque la existencia de dicho medico ya fue comprobada anteriormente en el codigo
}

void operator+(list<cRegistros*> lista, cRegistros* agregado)
{
	lista.push_back(agregado); //no es necesario agregar una excepcion porque el metodo pushback es a prueba de excepciones
	                            //fuente:cplusplus
}
void operator-(list<cOrtopedia*>::iterator original, list<cProtesis*>::iterator* eliminado)
{
	(*original)->get_stock().erase(*eliminado);
}

