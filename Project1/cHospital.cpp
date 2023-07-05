#include "cHospital.h"

cHospital::cHospital(string Nombre_, string Direccion_, string Especialidad_, list<cMedico*> Lista_Medicos_, list<cOrtopedia*> Lista_Afiliadas_, queue<cPaciente*> Cola_pac_): Nombre(Nombre_),Direccion(Direccion_), Especialidad(Especialidad_)
{
	this->Lista_Medicos = Lista_Medicos_;
	this->Cola_pacientes = Cola_pac_;
	this->lista_Afiliadas = Lista_Afiliadas_;
}

cHospital::~cHospital()
{
}

void cHospital::set_Pacientes(queue<cPaciente*> cola_actual)
{
	this->Cola_pacientes=cola_actual;
}

bool cHospital::Evaluar_Paciente(cPaciente &Paciente_Actual, unsigned int & Matricula_med )
{
	list<cMedico*>::iterator Med_Aux = this->Lista_Medicos.begin();
	while (Med_Aux != this->Lista_Medicos.end())
	{
		if ((*Med_Aux)->get_Disponibilidad())
			return (*Med_Aux)->Otorgar_Autorizacion(Paciente_Actual, Matricula_med);

		Med_Aux++;
	}
	return false;  // caso de que no haya ningun medico disponible en el hospital
}

string cHospital::get_Nombre()
{
	return this->Nombre;
}

list<cOrtopedia*>::iterator cHospital::get_primera_afiliada()
{
	return this->lista_Afiliadas.begin();
}

list<cOrtopedia*>::iterator cHospital::get_ultima_afiliada()
{
	return this->lista_Afiliadas.end();
}

list<cMedico*>::iterator cHospital::get_Primer_Medico()
{
	return this->Lista_Medicos.begin();
}

list<cMedico*>::iterator cHospital::get_Ultimo_Medico()
{
	return this->Lista_Medicos.end();
}

list<cOrtopedia*> cHospital::get_afiliadas()
{
	return this->lista_Afiliadas;
}

list<cMedico*> cHospital::get_Medicos()
{
	return this->Lista_Medicos;
}

queue<cPaciente*> cHospital::get_Pacientes()
{
	return this->Cola_pacientes;
}

void cHospital::Popear_Paciente()
{
	this->Cola_pacientes.pop();
}

unsigned int cHospital::get_Pacientes_pendientes()
{
	return this->Cola_pacientes.size();
}

void cHospital::Archivar_paciente(cPaciente* agregado)
{
	this->Pacientes_Atendidos.push_back(agregado);
}
/*
const string Nombre;
	list<cMedico*> Lista_Medicos;
	const string Direccion;
	const string Especialidad;
	list<cOrtopedia*> lista_Afiliadas;
	queue<cPaciente*> Cola_pacientes ;
	list<cPaciente*> Pacientes_Atendidos;
	*/

string cHospital::to_string_hosp()
{
	stringstream Salida;
	Salida << "Nombre: " << this->Nombre
		<< ", Direccion: " << this->Direccion
		<< ", Especialidad: " << this->Especialidad<<endl;
	Salida << "ORTOPEDIAS AFILIADAS:" << endl;
	list<cOrtopedia*>::iterator it_afiliadas = this->lista_Afiliadas.begin();
	while (it_afiliadas != this->lista_Afiliadas.end())
	{
		Salida << (*it_afiliadas)->to_string_Ort() << endl;
		it_afiliadas++;
	}
	Salida << "PACIENTES POR ATENDER:" << endl;
	while (this->Cola_pacientes.size() != 0)
	{
		cPaciente* aux(this->Cola_pacientes.front());
		this->Cola_pacientes.pop();
		Salida << aux->to_string()<<endl;
	}
	Salida << "PACIENTES ATENDIDOS:" << endl;
	list<cPaciente*>::iterator it_pac = this->Pacientes_Atendidos.begin();
	while (it_pac != this->Pacientes_Atendidos.end())
	{
		Salida << (*it_pac)->to_string()<<endl;
		it_pac++;
	}
	return Salida.str();
}

void cHospital::imprimir_Hosp()
{
	cout << to_string_hosp() << endl;
}
