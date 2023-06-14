#pragma once

#include <string>
#include <ctime>
#include "cProt_No_Quirurgica.h"
#include "cProt_Quirurgica.h"
#include <list>

using namespace std;
enum Organo_Extremidad_Reemplazada { Brazo = 1, Pierna, Mano, Dedo, Pie, Hombro, Cadera, Clavicula, Placa_Metalica, Implante_Dental };

class cProtesis {

private:
	Organo_Extremidad_Reemplazada Nombre;
	const tm Fecha_Fabricacion;
	const string Fabricante;
	const bool Superior_Inferior;

public:
	cProtesis(Organo_Extremidad_Reemplazada Nombre_, tm Fecha_Fabricacion_, string Fabricante_, bool Superior_Inferior_);
	~cProtesis();
	cProtesis(list<cProtesis>::iterator copia);
	Organo_Extremidad_Reemplazada get_nombre();
	tm get_Fabricacion();
	string get_Fabricante();
	bool get_Superior_inferior();
	float virtual get_ancho() = 0;	         //por razones de comparacion de datos que se necesitan en diversos metodos
	float virtual get_largo() = 0; 	         //defino metodos virtuales para poder acceder a los miembros de objetos de clases hijas
	float virtual get_Radio() = 0;			 //desde un iterador de una lista de cProtesis
	string virtual get_material() = 0;       
	string virtual get_Articulacion() = 0;
	void set_Nombre(Organo_Extremidad_Reemplazada set);
};
void operator-(list<cProtesis> original, list<cProtesis>::iterator* eliminado);
