#pragma once

#include<string>
#include <list>
#include "cFabricante.h"
#include "cHospital.h"
#include "cOrtopedia.h"
#include "cProtesis.h"
#include "cRegistros.h"
#include "Funciones_aux.h"

class cANPA {
	
private:
	list<cFabricante> Fabricantes;
	list<cHospital> Hospitales;
	list<cOrtopedia> Ortopedias;
	list<cRegistros> lista_registros;

public:

	cANPA(list<cFabricante>Fabricantes_, list<cHospital>Hospitales_, list<cOrtopedia> Ortopedias_);
	~cANPA();
	void Crear_Registro();
	bool Solicitar_Protesis_A_Ortopedia();
	bool Solicitar_Protesis_A_Fabricante();
    bool Buscar_En_Ortopedia_convenida(string Nombre_hospital, cPaciente paciente_actual, unsigned int Matricula_med_);
	void Registrar_tramite(Organo_Extremidad_Reemplazada Pieza_, list<cHospital>::iterator Hospital_, unsigned int Matricula_Med, string Nombre_pac, string Nombre_fuente);
	string Buscar_Medico(list<cHospital>::iterator Hospital_, unsigned int Matricula);

};
list<cRegistros>& operator+(list<cRegistros> lista, cRegistros* agregado);
void operator-(list<cOrtopedia>:: iterator original, list<cProtesis>::iterator* eliminado);