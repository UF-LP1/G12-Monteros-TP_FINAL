#pragma once
#include <string>
using namespace std;

class cMedico {
private:
	const string Nombre_Apellido;
	const unsigned int Matricula;
	string Hospitales;

public:
	cMedico(string Nombre_Apellido_, unsigned int Matricula_, string Hospitales_);
	~cMedico();

	bool Otorgar_Autorizacion();
	bool Elevar_sol_Protesis();

};