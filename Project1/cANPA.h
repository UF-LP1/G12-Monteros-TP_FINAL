#pragma once

#include<string>
#include <list>
#include "cFabricante.h"
#include "cHospital.h"
#include "cOrtopedia.h"

class cANPA {
	
private:
	list<cFabricante> Fabricantes;
	list<cHospital> Hospitales;
	list<cOrtopedia> Ortopedias;

public:

	cANPA(list<cFabricante>Fabricantes_, list<cHospital>Hospitales_, list<cOrtopedia> Ortopedias_);
	~cANPA();
	void Crear_Registro();
	bool Solicitar_Protesis_A_Ortopedia();
	bool Solicitar_Protesis_A_Fabricante();
    bool Buscar_En_Ortopedia_convenida(string Nombre_hospital, cPaciente paciente_actual);
};