#include "Funciones_aux.h"

bool operator==(list<cProtesis>::iterator original, cProt_No_Quirurgica* comparado)
{
	if (original->get_largo() == comparado->get_largo()&& original->get_ancho() == comparado->get_ancho()&& original->get_nombre() == comparado->get_nombre()&& original->get_Radio() == comparado->get_Radio())
		return true;
	else
	return false;
}

bool operator==(list<cProtesis>::iterator original, cProt_Quirurgica* comparado)
{
	if(original->get_Articulacion() == comparado->get_Articulacion() &&original->get_nombre()==comparado->get_nombre() && original->get_material()==comparado->get_material())
	return false;
}

bool operator==(list<cOrtopedia>::iterator izquierda, list<cOrtopedia>::iterator Derecha)
{
	if (izquierda->get_Nombre() == Derecha->get_Nombre()&& izquierda->get_Direccion() == Derecha->get_Direccion())
	return true;
	else
		return false;
}

bool operator!=(list<cOrtopedia>::iterator Total, list<cOrtopedia> Convenida)
{
	list<cOrtopedia>::iterator it = Convenida.begin();

	while (it != Convenida.end())
	{
		if (Total == it)
			return false;
	}
	return true;
}
