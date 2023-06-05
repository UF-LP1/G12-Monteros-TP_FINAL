#include "cProt_Quirurgica.h"

cProt_Quirurgica::cProt_Quirurgica(string Articulacion_, string Material_, string Nombre_, time_t Fecha_Fabricacion_, string Fabricante_, bool Superior_Inferior_):cProtesis(Nombre_,Fecha_Fabricacion_,Fabricante_,Superior_Inferior_)
{
	this->Articualcion = Articulacion_;
	this->Material = Material;
}

cProt_Quirurgica::~cProt_Quirurgica()
{
}
