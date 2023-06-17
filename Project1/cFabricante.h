#pragma once

#ifndef _CFABRICANTE_H
#define _CFABRICANTE_H

#include <string>

using namespace std;

class cFabricante {

private:
	const string Nombre;
	const string Direccion;
	const unsigned int Num_Habilitacion;

public:
	cFabricante(string Nombre, string Direccion, unsigned int Num_Habilitacion);
	~cFabricante();
	string get_Nombre();
	string get_Direccion();
	unsigned int get_Num_Habilitacion();
};
#endif