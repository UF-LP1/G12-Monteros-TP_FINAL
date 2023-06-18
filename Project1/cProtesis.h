#pragma once

#ifndef _CPROTESIS_H
#define _CPROTESIS_H

#include <string>
#include <ctime>
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
	cProtesis();
	Organo_Extremidad_Reemplazada get_nombre();
	tm get_Fabricacion();
	string get_Fabricante();
	bool get_Superior_inferior();
	float virtual get_largo()=0;
	float virtual get_ancho() = 0;
	float virtual get_Radio() = 0;
	string virtual get_Articulacion() = 0;
	string virtual get_material() = 0;
	void set_Nombre(Organo_Extremidad_Reemplazada set);
};
void operator-(list<cProtesis> original, list<cProtesis>::iterator* eliminado);

#endif 