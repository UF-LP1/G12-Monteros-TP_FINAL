#include "cRegistros.h"



cRegistros::cRegistros(string Hospital_, string Medico_, tm* Fecha_sol_, tm* Fecha_Entrega_, unsigned int Estimacion_, Organo_Extremidad_Reemplazada Pieza_, string Paciente_, string Nombre_Fuente_):Hospital(Hospital_), Medico(Medico_), Fecha_Sol(Fecha_sol_), Fecha_Entrega(Fecha_Entrega_), Estimacion(Estimacion_), Pieza(Pieza_), Paciente(Paciente_), Nombre_Fuente(Nombre_Fuente_)
{
}

cRegistros::~cRegistros()
{
}
