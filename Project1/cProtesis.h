#pragma once

#ifndef _CPROTESIS_H
#define _CPROTESIS_H

#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include <ctime>

using namespace std;
enum Organo_Extremidad_Reemplazada { Brazo = 1, Pierna, Mano, Dedo, Pie, Hombro, Cadera, Clavicula, Placa_Metalica, Implante_Dental };

class cProtesis {

protected:
	Organo_Extremidad_Reemplazada Nombre;
	tm Fecha_Fabricacion;
	string Fabricante;
     bool Superior_Inferior;

public:
	cProtesis(Organo_Extremidad_Reemplazada Nombre_, tm Fecha_Fabricacion_, string Fabricante_, bool Superior_Inferior_);
	~cProtesis();
	cProtesis();
	Organo_Extremidad_Reemplazada get_nombre();
	tm get_Fabricacion();
	string get_Fabricante();
	bool get_Superior_inferior();		  //
	float virtual get_largo();			  // tuve que sacarles el =0 a estos metodos virtuales e
	float virtual get_ancho() ;           //implementarlos porque de otra forma surgia un error que no me dejaba correr el codigo
	float virtual get_Radio() ;              
	string virtual get_Articulacion() ;
	string virtual get_material() ;
	string virtual to_string();
	void set_Nombre(Organo_Extremidad_Reemplazada set);
	//no son necesarias funciones de impresion porque nunca haremos un objeto de cProtesis
};
//void operator-(list<cProtesis> original, list<cProtesis>::iterator* eliminado);

#endif 