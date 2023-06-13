#pragma once

#include<string>
#include <list>
#include "cFabricante.h"
#include "cHospital.h"
#include "cOrtopedia.h"
#include "cProtesis.h"
#include "cRegistros.h"


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
    bool Buscar_En_Ortopedia_convenida(string Nombre_hospital, cPaciente paciente_actual);
	void Registrar_tramite(string Pieza_, cHospital Hospital_, unsigned int Matricula_Med, string Nombre_pac, string Nombre_fuente);
	string Buscar_Medico(cHospital Hospital_, unsigned int Matricula);

};
list<cRegistros>& operator+(list<cRegistros> lista, cRegistros* agregado);