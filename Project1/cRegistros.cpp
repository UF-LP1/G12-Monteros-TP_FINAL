#include "cRegistros.h"



cRegistros::cRegistros(string Hospital_, string Medico_, tm Fecha_sol_, tm Fecha_Entrega_, unsigned int Estimacion_, Organo_Extremidad_Reemplazada Pieza_, string Paciente_, string Nombre_Fuente_):Hospital(Hospital_), Medico(Medico_), Fecha_Sol(Fecha_sol_), Fecha_Entrega(Fecha_Entrega_), Estimacion(Estimacion_), Pieza(Pieza_), Paciente(Paciente_), Nombre_Fuente(Nombre_Fuente_)
{
}

cRegistros::~cRegistros()
{

}

string cRegistros::to_string_registros() const
{
    stringstream Salida;
    Salida << ", Fecha de entrega: " << Fecha_Entrega.tm_mday << "/" << Fecha_Entrega.tm_mon << "/" << Fecha_Entrega.tm_year+1900
        << ", Estimacion: " << this->Estimacion
        << ", Fecha de Solicitud: " << Fecha_Sol.tm_mday << "/" << Fecha_Sol.tm_mon << "/" << Fecha_Sol.tm_year+1900
        << ", Hospital: " << this->Hospital
        << ", Medico: " << this->Medico
        << ", Pieza Quirurgica: " << this->Pieza
        << ", Nombre del paciente: " << this->Paciente
        << ", Fuente de la pieza: " << this->Nombre_Fuente << endl;
       
    return Salida.str();
}

ostream& operator<<(ostream& out, const cRegistros& Registro)
{
    out << Registro.to_string_registros() << endl;
    return out;
}
