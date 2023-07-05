#pragma once

#ifndef _CANPA_H
#define _CANPA_H
#include "cFabricante.h"
#include "cHospital.h"
#include "cRegistros.h"
#include "Funciones_aux.h"

class cANPA {
	
private:
	list<cFabricante*> Fabricantes;
	list<cHospital*> Hospitales;
	list<cOrtopedia*> Ortopedias;
	list<cRegistros*> lista_registros;

public:

	cANPA(list<cFabricante*>Fabricantes_, list<cHospital*>Hospitales_, list<cOrtopedia*> Ortopedias_);
	~cANPA();
	bool Solicitar_Protesis_A_Fabricante(string Nombre_hospital, cPaciente &Paciente_Actual, unsigned int Matricula_med_);
	bool Busqueda_Especial(string Nombre_hospital, cPaciente &Paciente_Actual, unsigned int Matricula_med_);
    bool Buscar_En_Ortopedia_convenida(string Nombre_hospital, cPaciente &paciente_actual, unsigned int Matricula_med_);
	void Registrar_tramite(Organo_Extremidad_Reemplazada Pieza_, list<cHospital*>::iterator Hospital_, unsigned int Matricula_Med, string Nombre_pac, string Nombre_fuente);
	string Buscar_Medico(list<cHospital*>::iterator Hospital_, unsigned int Matricula);
	list<cHospital*>::iterator get_ultimo_hospital();
	list<cHospital*>::iterator get_Primer_Hospital();
	string Elegir_Un_Material(list<string*> alergias); // elije el primer material disponible al que el paciente no sea alergico
	string Elegir_Una_Articulacion(Organo_Extremidad_Reemplazada criterio); // le asigna una articulacion posible a la protesis a partir del tipo de protesis quirugica que necesite el paciente, se usan dos posibles articulaciones por protesis a modo de ejemplo, en la realidad son mas
	friend ostream& operator<<(ostream& out, cANPA print);


};
ostream& operator<<(ostream& out, cANPA print);
void operator+(list<cRegistros*>& lista, cRegistros* agregado);
void operator-(list<cOrtopedia*>:: iterator original, list<cProtesis*>::iterator* eliminado);
bool operator!=(string algo, list<string*> comparado);



#endif