#include "cANPA.h"

#ifndef __STDC_LIB_EXT1__
#define __STDC_LIB_EXT1__
#endif
#define __STDC_WANT_LIB_EXT1__ 1

cANPA::cANPA(list<cFabricante*> Fabricantes_, list<cHospital*> Hospitales_, list<cOrtopedia*> Ortopedias_)
{
	this->Fabricantes = Fabricantes_;
	this->Hospitales = Hospitales_;
	this->Ortopedias = Ortopedias_;
}

cANPA::~cANPA()
{

	this->lista_registros.erase(this->lista_registros.begin(),this->lista_registros.end());
	this->Ortopedias.erase(this->Ortopedias.begin(), this->Ortopedias.end());
	this->Hospitales.erase(this->Hospitales.begin(), this->Hospitales.end());
	this->Fabricantes.erase(this->Fabricantes.begin(), this->Fabricantes.end());

}

bool cANPA::Solicitar_Protesis_A_Fabricante(string Nombre_hospital, cPaciente &Paciente_Actual, unsigned int Matricula_med_)
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
	if ((*it_hosp)->get_Nombre() != Nombre_hospital)
		throw new OBJECT_NOT_FOUND;
	

	list<cFabricante*>::iterator it_Fab = this->Fabricantes.begin();
	string tipo_fuente = "Fabricante ";

	srand(time(0));
	while (it_Fab != this->Fabricantes.end())
	{


		if ((rand() % 4 + 1) == 4) //una de cada 4 veces el fabricante acepta hacer una protesis a medida
		{
			time_t fechaactual;
			time(&fechaactual);

			tm Actual;
			localtime_s(&Actual, &fechaactual);

			Registrar_tramite(Paciente_Actual.get_danyada(), it_hosp, Matricula_med_, Paciente_Actual.get_Nombre_Ap(), (tipo_fuente += (*it_Fab)->get_Nombre()));

			if (Paciente_Actual.get_radio() > 0)
			{
				cProt_No_Quirurgica Fabricada(Paciente_Actual.get_danyada(),Actual , (*it_Fab)->get_Nombre(), Paciente_Actual.get_Prot_NQ().get_Superior_inferior(), Paciente_Actual.get_Prot_NQ().get_largo(), Paciente_Actual.get_Prot_NQ().get_ancho(), Paciente_Actual.get_radio());
				Paciente_Actual.Recibir_Protesis_NQ(Fabricada);
			}
			else
			{
				cProt_Quirurgica Fabricada(Elegir_Una_Articulacion(Paciente_Actual.get_danyada()), Elegir_Un_Material(Paciente_Actual.get_alergias()), Paciente_Actual.get_danyada(), Actual, (*it_Fab)->get_Nombre(), Paciente_Actual.get_Prot_Q().get_Superior_inferior());
				Paciente_Actual.Recibir_Protesis_Q(Fabricada);
			}
			return true;
		}
		it_Fab++;
	}
	if (it_Fab == this->Fabricantes.end())
		throw new PACIENTE_PENDIENTE;

	return false;
}

bool cANPA::Busqueda_Especial(string Nombre_hospital,cPaciente &Paciente_Actual, unsigned int Matricula_med_)
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
	if ((*it_hosp)->get_Nombre() != Nombre_hospital)
	throw new OBJECT_NOT_FOUND;

	list<cOrtopedia*>::iterator it_No_Convenidas = this->Ortopedias.begin();
	list<cProtesis*>::iterator it_prot;
	string tipo_fuente = "Ortopedia ";

	while (it_No_Convenidas != this->Ortopedias.end())
	{
		if (it_No_Convenidas != (*it_hosp)->get_afiliadas())      //operador sobrecargado, si son ortopedias convenidas, 
		{	                                                   //no hace el resto de preguntas 
		
			it_prot = (*it_No_Convenidas)->get_Primer_Prot();
			if (Paciente_Actual.get_radio() > 0)
			{
				while (it_prot != (*it_No_Convenidas)->get_ultima_Prot())
				{
					if (it_prot ==  Paciente_Actual.get_Prot_NQ())
					{
						Registrar_tramite(Paciente_Actual.get_danyada(), it_hosp, Matricula_med_, Paciente_Actual.get_Nombre_Ap(), tipo_fuente += (*it_No_Convenidas)->get_Nombre());
						cProt_No_Quirurgica entregada(it_prot);
						Paciente_Actual.Recibir_Protesis_NQ(entregada);
						it_No_Convenidas - &it_prot;
						delete* it_prot;
						return true;
					}

					it_prot++;
				}
			}
			else
				while (it_prot != (*it_No_Convenidas)->get_ultima_Prot())
				{
					if (it_prot == Paciente_Actual.get_Prot_Q())
					{
						Registrar_tramite(Paciente_Actual.get_danyada(), it_hosp, Matricula_med_, Paciente_Actual.get_Nombre_Ap(), tipo_fuente += (*it_No_Convenidas)->get_Nombre());
						cProt_Quirurgica entregada(it_prot);
						Paciente_Actual.Recibir_Protesis_Q(entregada);
						it_No_Convenidas -&it_prot; 
						delete* it_prot;
						return true;
					}
					it_prot++;
				}
		}
		it_No_Convenidas++;
	}

	return false;
}

bool cANPA::Buscar_En_Ortopedia_convenida(string Nombre_hospital, cPaciente &paciente_actual,unsigned int Matricula_med_)
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
	if ((*it_hosp)->get_Nombre() != Nombre_hospital)
		throw new OBJECT_NOT_FOUND;

	string 	tipo_fuente = "ortopedia ";
	list<cOrtopedia*>::iterator it_Afiliadas = (*it_hosp)->get_primera_afiliada();

	list<cProtesis*>::iterator it_prot;

	while (it_Afiliadas != (*it_hosp)->get_ultima_afiliada())
	{
		it_prot = (*it_Afiliadas)->get_Primer_Prot();
		if (paciente_actual.get_radio() > 0)            //si el paciente tiene un radio de amputacion,
		{												//necesita una protesis de un miembro, es decir no quirurgica

			while (it_prot != (*it_Afiliadas)->get_ultima_Prot())
			{

				if (it_prot == paciente_actual.get_Prot_NQ())
				{
						Registrar_tramite(paciente_actual.get_danyada(), it_hosp, Matricula_med_, paciente_actual.get_Nombre_Ap(), tipo_fuente += (*it_Afiliadas)->get_Nombre()); 

						//si se encuentra la pieza necesitada se genera un registro de la venta/tramite con los datos de
						//los implicados y como fuente de la protesis se especifica que la fuente fue una ortopedia y se agrega su nombre
						//aprovechando sobrecarga de operadores de la clase string
						cProt_No_Quirurgica encontrada(it_prot);
						paciente_actual.Recibir_Protesis_NQ(encontrada);
						
						it_Afiliadas-&it_prot; //la Ortopedia pierde esa protesis
						delete *it_prot;
						return true;
				}
				it_prot++;
			}
		}
		else
		{
			while (it_prot != (*it_Afiliadas)->get_ultima_Prot())
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
	                                                 //la protesis se entrega en cualquier momento entre un lapso de 10 dias
	tm fecha_entrega = Fecha_Actual;				 //despues de que la solicitud fue aceptada          
	fecha_entrega.tm_mday += estimacion;
	                                    
												 
	cRegistros* aux = new cRegistros((*Hospital_)->get_Nombre(), Buscar_Medico(Hospital_, Matricula_Med), Fecha_Actual, fecha_entrega, estimacion, Pieza_, Nombre_pac, Nombre_fuente);

	this->lista_registros + aux;  // se crea el registro con los datos recibidos y se agrega a la lista
}

string cANPA::Buscar_Medico(list<cHospital*>::iterator Hospital_, unsigned int Matricula)
{
	list<cMedico*>::iterator it =  (*Hospital_)->get_Primer_Medico();

	while (it != (*Hospital_)->get_Ultimo_Medico())
	{
		if ((*it)->get_Matricula() == Matricula)
			return (*it)->get_Nombre();
		it++;
	}
	throw new OBJECT_NOT_FOUND;
}

list<cHospital*>::iterator cANPA::get_ultimo_hospital()
{
	return this->Hospitales.end();
}

list<cHospital*>::iterator cANPA::get_Primer_Hospital()
{
	return this->Hospitales.begin();
}

string cANPA::Elegir_Un_Material(list<string*> alergias)
{
	list<string>Posibles_Materiales;
	Posibles_Materiales.push_back("Hierro");
	Posibles_Materiales.push_back("Platino");
	Posibles_Materiales.push_back("Thaumio");
	Posibles_Materiales.push_back("Oricalco");
	Posibles_Materiales.push_back("Bronce");
	Posibles_Materiales.push_back("Cobre");
	Posibles_Materiales.push_back("Aluminio");
	Posibles_Materiales.push_back("Plastico");
	Posibles_Materiales.push_back("Madera_De_Abedul");
	Posibles_Materiales.push_back("Madera_De_Roble");
	Posibles_Materiales.push_back("Mithrilo");
	Posibles_Materiales.push_back("Titanio");
	list<string>::iterator it = Posibles_Materiales.begin();

	while (it != Posibles_Materiales.end())
	{
		if (*it != alergias)
			return *it;
		it++;
	}
}

string cANPA::Elegir_Una_Articulacion(Organo_Extremidad_Reemplazada criterio)
{
	srand(time(0));
	unsigned int eleccion = rand() % 2+1;
	//tipos de protessi quirurgicas:
	//Hombro, Cadera, Clavicula, Placa_Metalica, Implante_Dental
	//
	switch (criterio)  // esta fucnion se llama solo para las protesis quirurgicas, del 6 al 10 en el enum
	{
	case 6: // hombro
		switch (eleccion) {
		case 1:return "glenohumeral";
			break;
		case 2: return "subdeltoidea";
			break;
		}
		break;

	case 7:
		switch (eleccion) {
		case 1: return "Cabeza Femoral";
			break;
		case 2: return "Pelvis";
			break;
		}
		break;

	case 8: 
		switch (eleccion) {
		case 1: return "Acromioclavicular";
			break;
		case 2: return "Manubrio";
			break;
		}
		break;

	case 9:
		switch (eleccion) {
		case 1: return "Femur";
			break;
		case 2: return "Radio";
			break;
		}
		break;

	case 10:
		switch (eleccion) {
		case 1: return "Mandibula";
			break;
		case 2: return "Corona";
			break;
		}
		break;

	default:
		return "Ninguna";
	}
}

ostream& operator<<(ostream& out, cANPA print)
{
	{
		list<cRegistros*>::iterator it_reg = print.lista_registros.begin();
		while (it_reg != print.lista_registros.end())
		{
			out << *(*it_reg) << endl;
			it_reg++;
		}
		return out;
	}
}

void operator+(list<cRegistros*>& lista, cRegistros* agregado)
{
	lista.push_back(agregado); //no es necesario agregar una excepcion porque el metodo pushback es a prueba de excepciones
	                            //fuente:cplusplus
}
void operator-(list<cOrtopedia*>::iterator original, list<cProtesis*>::iterator* eliminado)
{
	(*original)->get_stock().erase(*eliminado);
}

bool operator!=(string algo, list<string*> comparado)
{
	list<string*>::iterator it = comparado.begin();
	while (it != comparado.end())
	{
		if (*(*it) == algo)
			return false;
		it++;
	}
	return true;
}



